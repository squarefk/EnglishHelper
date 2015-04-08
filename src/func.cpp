#include "func.h"
#include "word.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>
#include <QDir>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

std::map<QString,int> dict;


Func::Func()
{
    loadDictionary(word);

}

Func::~Func()
{
	
}

//**********************************************
//  This is function of loaddictionary from ../lib/dict/dict.txt
//  Function will do two things
//  1.read from dict and make message into word[]
//  2.and pair<sting,i1nt> into map , the 'int' is the position number of this word in word[]
//**********************************************

QString* findSimilar(QString a){
    return NULL;
}

QString Func::query(QString a){
	if (dict.find(a) != dict.end()){
		int b=dict[a];
		return word[b].info;
	}
	return "No this word!";
}
 

void Func::loadDictionary(Word* word)
{

    qDebug()<<"vcc";
    QString cut="------------------------------";
    QString str,line,myword;


    //1.

    QFile *file = new QFile(":dictionary/dictionary/dictionary.txt");

    if (file->open(QFile::ReadOnly))
    {
        qDebug()<<"open file";
        //return;//
        file->deleteLater();
        QTextStream stream( file );
        int count=0;
        while ( !stream.atEnd() ) {
            line = stream.readLine(); // 不包括“/n”的一行文本
            count++;
            if (line==cut){

                if (str.size()!=0)
                {
                    while (str.size()&&str[str.size()-1]<=32) str.remove(str.size()-1,1);

                    for (int i=0;i<int(str.size());i++){
                        if (str[i]=='('||str[i]=='/') break;

                        myword+=str[i];
                    }
                    while (myword.size()&&myword[myword.size()-1]<=32) myword.remove(myword.size()-1,1);

                    Word::total++;
                    word[Word::total].word=myword;
                    word[Word::total].info=str;

                    str="";
                    myword="";
                }
            }else
            {
                if (str.size()!=0) str=str+'\n';
                str=str+line;
            }

        }
        file->close();
    }else
    {
        qDebug()<<"no file";
    }

    qDebug()<<Word::total;

	//2.
	for (int i=1;i<=word[0].total;i++){
        dict.insert(std::pair<QString,int>(word[i].word,i));
    }

    qDebug()<<query("apple");
}

void Func::loadUser()
{

}

void Func::saveUser()
{

}

QString *Func::similar(QString word)
{
    return NULL;
}

QString Func::randomWord()
{
    return QString("");
}

void Func::article(char *file)
{

}
