#include "func.h"
#include "word.h"
//#include "user.h"
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
#include <ctime>
#include <algorithm>


std::map<QString,int> dict;
std::map<QString,int> userDict;

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

//导入单词库
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

void Func::saveDictionary(){
    QFile *file = new QFile("user_save.txt");

    if (file->open(QFile::WriteOnly | QFile::Text))
    {
        qDebug()<<"open user.txt success";
        QTextStream stream(file);
        for (int i=0;i<Word::total;i++){
            stream<<word[i].word<<endl;
            stream<<word[i].info<<endl;
            stream<<"###";
        }

        file->close();
    }else{
        qDebug()<<"open user.txt fail";
    }

}

/*void Func::loadUser()
{
    QFile *file = new QFile("user.txt");

    if (file->open(QFile::ReadOnly | QFile::Text))
    {
        int tot;QString line;
        qDebug()<<"open user.txt success";
        QByteArray buff = file->readAll();
        QTextStream stream( &buff );
        stream.setCodec(QTextCodec::codecForUtfText(buff, QTextCodec::codecForName("utf-8")));
        while(!stream.atEnd())
        {
            tot++;
            user[tot].word="";
            line=stream.readLine();
            while (line!="###")
            {
                user[tot].word+=line;
            }
            stream>>user[tot].type;
            stream>>user[tot].time;
            stream>>user[tot].totVisit;
            stream>>user[tot].totWrong;
            stream>>user[tot].cotinueCorrect;
            stream>>user[tot].id;
        }
        User::userTot=tot;
        file->close();
    }else{
        qDebug()<<"open user.txt fail";
    }

}*/

/*void Func::saveUser()
{
    QFile *file = new QFile("user_save.txt");

    if (file->open(QFile::WriteOnly | QFile::Text))
    {
        qDebug()<<"open user.txt success";
        QTextStream stream(file);
        for (int i=0;i<User::userTot;i++){
            stream<<user[i].word<<endl;
            stream<<"###"<<endl;
            stream<<user[i].type<<endl;
            stream<<user[i].time<<endl;
            stream<<user[i].totVisit<<endl;
            stream<<user[i].totWrong<<endl;
            stream<<user[i].cotinueCorrect<<endl;
            stream<<user[i].id<<endl;
        }


        file->close();
    }else{
        qDebug()<<"open user.txt fail";
    }

}*/

namespace Query
{
    //返回最多5个相似单词数组,为-1表示没有
    QString* relative(QString myWord)
    {
        QString answer[5];int tot=0;
        for (int i=0;i<5;i++) answer[i]=-1;
        QString smallWord;
        for (int i=0;i<myWord.size()-1;i++)
        {
            smallWord="";
            for (int j=i;j<myWord.size();j++) smallWord+=myWord[j];
            for (int j=0;j<Word::total;j++)
                if (word[j].word.contains(smallWord)&&tot<5)
                {
                    for (int k=0;k<tot;k++) if (answer[k]==word[j].word) break;
                    answer[tot++]=word[j].word;
                }
        }
        for (int i=1;i<myWord.size();i++)
        {
            smallWord="";
            for (int j=0;j<=i;j++) smallWord+=myWord[j];
            for (int j=0;j<Word::total;j++)
                if (word[j].word.contains(smallWord)&&tot<5)
                {
                    for (int k=0;k<tot;k++) if (answer[k]==word[j].word) break;
                    answer[tot++]=word[j].word;
                }
        }
        return answer;
    }
}
//查询单词
Func::QueryPair Func::query(QString a){
    QueryPair answer;
    if (dict.find(a) != dict.end()){
        int b=dict[a];
        answer.first=word[b].info;
        answer.second=Query::relative(word[b].word);
        return answer;
    }
    answer.first="No this word!";
    answer.second=NULL;
    return answer;
}

namespace StartTest
{
    void addNewWordToUser(int tot)
    {
        //for (int i=0;i<tot;i++) if ()
    }

    void reloadTypeByTime()
    {
        int time=std::time(NULL);
        for (int i=0;i<User::userTot;i++)
        {
            int day=(user[i].time-time)/86400;
            if (user[i].type=User::knownWord)
            {
                if ((day>=5&&user[i].cotinueCorrect<=1)
                   ||(day>=10&&user[i].cotinueCorrect<=3)   )
                {
                    user[i].type=User::grayWord;
                }
            }
            if (user[i].type=User::grayWord)
            {
                if ((day>=5&&user[i].cotinueCorrect<=1)
                     ||day>=10)
                {
                    user[i].type=User::newWord;
                }
            }
        }
    }
    int* getTest(int tot)
    {
        srand(time(NULL));
        int grayWordTot=int(tot*0.6),newWordTot=int(tot*0.3),knownWordTot=tot-grayWordTot-newWordTot;
        int *use=new int[User::userTot],*line=new int[User::userTot],* ans=new int[User::userTot];
        for (int i=0;i<User::userTot;i++) use[i]=0;
        int totNow=0,ansTot=0;
        for (int i=0;i<User::userTot;i++) if (user[i].type==User::grayWord)
        {
            line[totNow++]=i;
        }
        std::random_shuffle(line,line+totNow);
        for (int i=1;i<=std::min(totNow,grayWordTot);i++) {use[i]=1;ans[ansTot++]=line[i];}

        totNow=0;
        for (int i=0;i<User::userTot;i++) if (user[i].type==User::newWord)
        {
            line[totNow++]=i;
        }
        std::random_shuffle(line,line+totNow);
        for (int i=1;i<=std::min(totNow,newWordTot);i++) {ans[ansTot++]=line[i];use[i]=1;}

        totNow=0;
        for (int i=0;i<User::userTot;i++) if (user[i].type==User::knownWord)
        {
            line[totNow++]=i;
        }
        std::random_shuffle(line,line+totNow);
        for (int i=1;i<=std::min(knownWordTot,totNow);i++) {use[i]=1;ans[ansTot++]=line[i];}

        if (ansTot<tot)
        {
            for (int i=0;i<User::userTot;i++) if (ansTot<tot&&user[i].type==User::grayWord&&!use[i])
            {
                use[i]=1;
                ans[ansTot++]=i;
            }
            for (int i=0;i<User::userTot;i++) if (ansTot<tot&&user[i].type==User::grayWord&&!use[i])
            {
                use[i]=1;
                ans[ansTot++]=i;
            }

        }

        if (ansTot<tot)
        {
            addNewWordToUser(tot-ansTot);
            for (int i=User::userTot-1;i>=0&&ansTot<tot;i--) ans[ansTot++]=i;
        }

        return ans;
    }
    /*void addStringList(const QString &newWord,int &similarTot,QString *stringList)
    {
        if (dict.find(newWord)!=dict.end())
        {
            if (newWord.size()!=0) stringList[similarTot++]=newWord;
            //qDebug()<<"The "<<similarTot<<"similar word: "<<newWord;//
        }

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

    }*/

    QString* findSimilar(QString primaryWord)
    {
        QString ans[4];int tot=0;
        ans[0]=primaryWord;
        /*similarList[0]=primaryWord;
        similarTot=1;

        changeOneChar(primaryWord,similarTot,similarList);

        //addSuffix(primaryWord,similarTot,similarList);
        findSimilar(primaryWord,similarTot,similarList);

        addToFourString(primaryWord,similarTot,similarList);


        qDebug()<<"totfind: "<<similarTot;
        std::random_shuffle(similarList,similarList+similarTot);
        return similarList;*/
        if (primaryWord.size()==1)
        {
            ans[0]=primaryWord;ans[1]="b";ans[2]="c";ans[4]="d";
            std::random_shuffle(ans,ans+4);
            return ans;
        }
        QString newWord=primaryWord;
        for (int i=0;i<primaryWord.size();i++)
               for (int j=0;j<primaryWord.size();j++) if (i!=j)
               {
                   for (int a='a';a<='z';a++)
                       for (int b='a';b<='z';b++)
                       {
                           newWord[i]=a;newWord[j]=b;
                           if (tot<4&&dict.find(newWord)!=dict.end())
                           {
                               ans[tot++]=newWord;
                           }
                       }
                    newWord[i]=primaryWord[i];
                    newWord[j]=primaryWord[j];
               }
        for (int i=tot;i<=4;i++) ans[tot++]="none";
        std::random_shuffle(ans,ans+4);
        return ans;
    }
}
//生成Test
Func::TestPair* Func::startTest(int _tot)
{
    User::testWordTot=_tot;
    Func::TestPair *ans=new Func::TestPair[User::testWordTot];
    StartTest::reloadTypeByTime();
    int* myList=StartTest::getTest(User::testWordTot);
    for (int i=0;i<User::testWordTot;i++)
    {
        ans[i].first=user[myList[i]].word;
        ans[i].second=StartTest::findSimilar(ans[i].first);
    }
    User::recordTestList=myList;
    return ans;
}
void Func::answerForTest(int id,Answer answer)
{
    user[id].totVisit++;
    user[id].time=time(NULL);
    if (answer==Yes)
    {
        user[id].cotinueCorrect++;
    }
    if (answer==No)
    {
        user[id].cotinueCorrect=0;
        user[id].totWrong++;
    }
}
namespace EndTest
{
    void reloadTypeByUser()
    {
        for (int i=0;i<User::userTot;i++)
        {
            User my=user[User::recordTestList[i]];
            if (my.type==User::knownWord)
            {
                if (my.cotinueCorrect==0)
                    my.type=User::grayWord;
            }
            if (my.type==User::grayWord)
            {
                if (my.cotinueCorrect>=3)
                    my.type=User::knownWord;
                else{
                   if (double(my.totWrong)/my.totVisit>0.7)
                      my.type=User::newWord;
                }
            }
            if (my.type==User::newWord)
            {
                if (my.cotinueCorrect!=0 && double(my.totWrong)/my.totVisit>0.5)
                      my.type=User::grayWord;
            }
        }
    }
}
void Func::endTest()
{
    EndTest::reloadTypeByUser();
    saveUser();
}
int* Func::analysisArticle(QString* article,int tot)
{
    int ans[100];int myTot=0;
    for (int i=0;i<tot;i++)
    {
        if (userDict.find(article[i])==userDict.end())
        {
            int userID=userDict[article[i]];
            int wordID=user[userID].id;
            ans[myTot++]=wordID;
        }
    }
    return ans;
}

/*void findSimilar(QString primaryWord,int &similarTot,QString* similarList)
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
}*/

