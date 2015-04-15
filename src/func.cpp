#include "func.h"
#include "word.h"
#include <QFile>
#include <QTextStream>
#include <QTextCodec>
#include <QMessageBox>
#include <QDir>
#include <QDebug>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>


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

QString Func::getWord()
{
    int number=rand()%Word::total;
    return word[number].word;
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

    QString cut="------------------------------";
    QString str,line,myword;


    //1.

    QFile *file = new QFile("dictionary.txt");

    if (file->open(QFile::ReadOnly | QFile::Text))
    {
        file->deleteLater();
        QByteArray buff = file->readAll();
        QTextStream stream( &buff );
        stream.setCodec(QTextCodec::codecForUtfText(buff, QTextCodec::codecForName("utf-8")));
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

	//2.
	for (int i=1;i<=word[0].total;i++){
        dict.insert(std::pair<QString,int>(word[i].word,i));
    }
}

void Func::loadUser()
{

}

void Func::saveUser()
{

}

void addStringList(const QString &newWord,int &similarTot,QString *stringList)
{
    if (dict.find(newWord)!=dict.end())
    {
        if (newWord.size()!=0) stringList[similarTot++]=newWord;
        //qDebug()<<"The "<<similarTot<<"similar word: "<<newWord;//
    }

}

void findSimilar(QString primaryWord,int &similarTot,QString* similarList)
{
    int recordTot=similarTot;
    double digit=0.5;
    for (int k=0;k<Word::total;k++)
    {
        if (digit>20) digit=0.7;
        if (digit>50) digit=0.8;
        if (digit>100) digit=0.9;
        int flag=0,len=0;QString recordWord;
        for (int i=0;i<primaryWord.size();i++)
        {
            for (int j=i+1;j<primaryWord.size();j++)
            {
                QString smallWord=primaryWord.mid(i,j-i+1);
                if (word[k].word.contains(smallWord))
                {
                   flag=1;
                   if (smallWord.size()>len)
                   {
                       len=smallWord.size();
                       recordWord=smallWord;
                   }
                }

            }
        }
        if (double(len)/word[k].word.size()>digit)
        {
            if (word[k].word.size()!=0) similarList[++similarTot]=word[k].word;
        }
    }
    qDebug()<<"findSimilar: "<<similarTot-recordTot;
}

void changeOneChar(QString primaryWord,int &similarTot,QString* similarList)
{
    QString newWord=primaryWord;
    int recordTot=similarTot;

    //Change one character
    for (int i=0;i<primaryWord.size();i++)
    {
        for (int j='a';j<='z';j++) if (j!=primaryWord[i])
        {
            newWord[i]=j;
            addStringList(newWord,similarTot,similarList);
        }

        for (int j='A';j<='Z';j++) if (j!=primaryWord[i])
        {
            newWord[i]=j;
            addStringList(newWord,similarTot,similarList);
        }

        newWord[i]=primaryWord[i];
    }
    qDebug()<<"changeOneChar: "<<similarTot-recordTot;
}
void addSuffix(QString primaryWord,int &similarTot,QString *similarList)
{
    int recordTot=similarTot;
    QString newWord;
    for (int i=0;i<Word::total;i++)
    {
        if (word[i].word[0]=='-')
        {
            newWord=primaryWord;
            for (int j=1;j<word[i].word.size();j++) newWord+=word[i].word[j];
            addStringList(newWord,similarTot,similarList);
        }
    }
    qDebug()<<"addSuffix: "<<similarTot-recordTot;

}
void addToFourString(QString primartWord,int &similarTot,QString *similarList)
{
    for (int i=similarTot;i<4;i++) similarList[i]=similarList[similarTot-1];
    similarTot=std::max(similarTot,4);

}

QString *Func::similar(QString primaryWord)
{
    similarList[0]=primaryWord;
    similarTot=1;

    changeOneChar(primaryWord,similarTot,similarList);

    //addSuffix(primaryWord,similarTot,similarList);
    findSimilar(primaryWord,similarTot,similarList);

    addToFourString(primaryWord,similarTot,similarList);


    qDebug()<<"totfind: "<<similarTot;
    std::random_shuffle(similarList,similarList+similarTot);
    return similarList;
}

QString Func::randomWord()
{
    return QString("");
}

void Func::article(char *file)
{

}
