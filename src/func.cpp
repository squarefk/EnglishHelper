#include "func.h"
#include "word.h"
#include "user.h"
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
    loadDictionary();
    loadUser();
    //startTest(5);
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
void makeIndex_Dict()
{
    for (int i=1;i<=Word::total;i++){
        dict.insert(std::pair<QString,int>(word[i].word,i));
    }

}

namespace loadDictionarySpace{
    void loadAnsTransDictionary(){
        //There is some bug
        //Like CERN is only recognise C
    }
}

void Func::loadDictionary(){
    //1.
    QFile *file = new QFile("dictionary.txt");

    if (file->open(QFile::ReadOnly | QFile::Text))
    {
        QString line,ll;int tot=0;
        file->deleteLater();
        QByteArray buff = file->readAll();
        QTextStream stream( &buff );
        stream.setCodec("UTF-8");
        //int count=0;
        //int ttt=0;
        while ( !stream.atEnd() ) {
            word[tot].word=stream.readLine();
            line=stream.readLine();
            while (line!="###"){
                word[tot].info+=line;
                word[tot].info+='\n';

                line=stream.readLine();
            }

            word[tot].info.remove(word[tot].info.size()-1,1);
            tot++;
        }
        Word::total=tot;
        file->close();
    }else
    {
        qDebug()<<"no file";
    }

    makeIndex_Dict();
}

void Func::saveDictionary(){
    QFile *file = new QFile("dictionary_save.txt");

    if (file->open(QFile::WriteOnly | QFile::Text))
    {
        qDebug()<<"open dictionary_save.txt success";
        QTextStream stream(file);
        QByteArray buff;
        stream.setCodec("UTF-8");
        for (int i=0;i<Word::total;i++){
            stream<<word[i].word<<endl;
            stream<<word[i].info<<endl;
            stream<<"###"<<endl;
        }
        file->close();
    }else{
        qDebug()<<"open dictionary_save.txt fail";
    }

}

void makeIndex_userDict(){
    for (int i=0;i<User::total;i++)
    {
        userDict.insert(std::pair<QString,int>(user[i].word,i));
    }
}

void Func::loadUser()
{
    QFile *file = new QFile("user.txt");

    if (file->open(QFile::ReadOnly | QFile::Text))
    {
        int tot=0;QString line;
        qDebug()<<"open user.txt success";
        QByteArray buff = file->readAll();
        QTextStream stream( &buff );
        stream.setCodec("UTF-8");
        //stream.setCodec(QTextCodec::codecForUtfText(buff, QTextCodec::codecForName("utf-8")));
        while(!stream.atEnd())
        {
            user[tot].word=stream.readLine();
            while (user[tot].word.size()&&
                   (user[tot].word[user[tot].word.size()-1]=='\n'||user[tot].word[user[tot].word.size()-1]==' '))
            {
                user[tot].word.remove(user[tot].word.size()-1,1);
            }
            if (user[tot].word.size()){
                   stream>>user[tot].type;
                stream>>user[tot].time;
                stream>>user[tot].totVisit;
                stream>>user[tot].totWrong;
                stream>>user[tot].cotinueCorrect;
                stream>>user[tot].id;
                stream.readLine();
                //qDebug()<<user[tot].word;
                tot++;
            }
        }
        User::total=tot;
        file->close();
    }else{
        qDebug()<<"open user.txt fail";
    }

    makeIndex_userDict();
}

void Func::saveUser()
{
    QFile *file = new QFile("user.txt");

    if (file->open(QFile::WriteOnly | QFile::Text))
    {
        qDebug()<<"open user_save.txt success";
        QTextStream stream(file);
        stream.setCodec("UTF-8");
        for (int i=0;i<User::total;i++){
            stream<<user[i].word<<endl;
            stream<<user[i].type<<endl;
            stream<<user[i].time<<endl;
            stream<<user[i].totVisit<<endl;
            stream<<user[i].totWrong<<endl;
            stream<<user[i].cotinueCorrect<<endl;
            stream<<user[i].id<<endl;
        }


        file->close();
    }else{
        qDebug()<<"open user_save.txt fail";
    }

}

//-----------------------------------------------Query-------------------------------------------------------------


namespace QuerySpace
{
    //返回最多5个相似单词数组,为###表示没有
    QString* relative(QString myWord)
    {
        QString *answer = new QString[6];
        int tot=0;
        for (int i=0;i<6;i++) answer[i]="###";
        QString smallWord;
        for (int i=1;i<myWord.size()-1;i++)
        {
            smallWord="";
            for (int j=i;j<myWord.size();j++) smallWord+=myWord[j];
            for (int j=0;j<Word::total;j++) if (tot<5)
                if (word[j].word.contains(smallWord)&&word[j].word!=myWord)
                {
                    for (int k=0;k<tot;k++) if (answer[k]==word[j].word) break;
                    answer[tot++]=word[j].word;

                //    qDebug()<<"find similar1: "<<answer[tot-1];
                }
        }
        for (int i=1;i<myWord.size();i++)
        {
            smallWord="";
            for (int j=0;j<=i;j++) smallWord+=myWord[j];
            for (int j=0;j<Word::total;j++) if (tot<5)
                if (word[j].word.contains(smallWord)&&word[j].word!=myWord)
                {
                    for (int k=0;k<tot;k++) if (answer[k]==word[j].word) break;
                    answer[tot++]=word[j].word;
                //    qDebug()<<"find similar2: "<<answer[tot-1];
                }
        }
        return answer;
    }
}
//查询单词
Func::QueryPair* Func::query(QString a){
    QueryPair *answer=new QueryPair;
    if (dict.find(a) != dict.end()){
        int b=dict[a];
        answer->first=word[b].info;
        answer->second=QuerySpace::relative(word[b].word);
        return answer;
    }
    answer->first="No this word!";
    answer->second=new QString[1];
    answer->second[0]="###";
    return answer;
}



//-----------------------------------------------Test-------------------------------------------------------


namespace StartTest
{
    QString getChinese(const QString &myWord){
        QString ans="";int first=0,found=0;
        for (int i=0;i<myWord.size();i++){
            QString str=myWord[i];
            if (str.contains(QRegExp("[\\x4e00-\\x9fa5]+"))||ans!=""){
                if (ans=="") first=i;
                if (ans==""&&i&&myWord[i-1]!=' '&&!myWord[i-1].isLetter())
                {
                    ans+=myWord[i-1];
                }
                if (first&&(str=="["||str=="(")) found=1;
                if (first&&(str=="]"||str==")"&&!found)){
                    //qDebug()<<"found!";
                    //qDebug()<<ans;
                    int j=first-1;
                    while (j){
                        ans=myWord[j]+ans;
                        if (myWord[j]=='['||myWord[j]=='(') break;
                        j--;
                    }
                }
                ans+=str;
            }
            if (str=="\n"&&ans!="") break;
        }
       // qDebug()<<"add: "<<ans;
        if (ans=="") ans=myWord;
        return ans;
    }

    int getSystemTime()
    {
        return std::time(NULL);
    }

    void addNewWordToUser(int tot)
    {
        srand(time(NULL));
        int newID;
        for (int i=1;i<=tot;i++)
        {
            do{
                newID=((rand()*rand())%Word::total+Word::total)%Word::total;
            }
            while(userDict.find(word[newID].word)!=userDict.end());

            user[User::total].word=word[newID].word;
            user[User::total].type=User::newWord;
            user[User::total].time=getSystemTime();
            user[User::total].totVisit=0;
            user[User::total].totWrong=0;
            user[User::total].cotinueCorrect=0;
            user[User::total].id=newID;
            User::total++;
        }
    }

    void reloadTypeByTime()
    {
        int time=getSystemTime();
        for (int i=0;i<User::total;i++)
        {
            int day=abs(time-user[i].time)/86400;
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
        int *use=new int[User::total],*line=new int[User::total],* ans=new int[tot];
        for (int i=0;i<User::total;i++) use[i]=0;
        int totNow=0,ansTot=0;
        for (int i=0;i<User::total;i++) if (user[i].type==User::grayWord)
        {
            line[totNow++]=i;
        }
        std::random_shuffle(line,line+totNow);
        for (int i=0;i<std::min(totNow,grayWordTot);i++) {use[line[i]]=1;ans[ansTot++]=line[i];}
        totNow=0;
        for (int i=0;i<User::total;i++) if (user[i].type==User::newWord)
        {
            line[totNow++]=i;
        }
        std::random_shuffle(line,line+totNow);
        for (int i=1;i<=std::min(totNow,newWordTot);i++) {ans[ansTot++]=line[i];use[line[i]]=1;}

        totNow=0;
        for (int i=0;i<User::total;i++) if (user[i].type==User::knownWord)
        {
            line[totNow++]=i;
        }
        std::random_shuffle(line,line+totNow);
        for (int i=1;i<=std::min(knownWordTot,totNow);i++) {use[line[i]]=1;ans[ansTot++]=line[i];}

        if (ansTot<tot)
        {
            for (int i=0;i<User::total;i++) if (ansTot<tot&&user[i].type==User::grayWord&&!use[i])
            {
                use[i]=1;
                ans[ansTot++]=i;
            }
            for (int i=0;i<User::total;i++) if (ansTot<tot&&user[i].type==User::newWord&&!use[i])
            {
                use[i]=1;
                ans[ansTot++]=i;
            }

        }
        //return ans;

        if (ansTot<tot)
        {
            int oldTot=ansTot;
            qDebug()<<"need to addNewWord:"<<tot-ansTot;
            addNewWordToUser(tot-ansTot);
            for (int i=oldTot;i<tot;i++) ans[ansTot++]=i;
        }
        delete[] use;
        delete[] line;
        return ans;//
    }

    void changeOneLetter(QString* ans,int &tot,const QString &primaryWord){
        QString newWord=primaryWord;
        for (int i=0;i<primaryWord.size();i++){
            for (char a='a';a<='z';a++) if (a!=primaryWord[i])
            {
                newWord[i]=a;
                if (tot<4&&dict.find(newWord)!=dict.end())
                {
                    ans[tot++]=newWord;
                }
            }
            newWord[i]=primaryWord[i];
        }
    }
    void changeTwoLetter(QString* ans,int &tot,const QString &primaryWord){
        QString newWord=primaryWord;
        for (int i=0;i<primaryWord.size();i++)
               for (int j=primaryWord.size()-1;j>i;j--)
               {
                   for (char a='a';a<='z';a++)
                       for (char b='a';b<='z';b++) if (a!=primaryWord[i]&&b!=primaryWord[j])
                       {
                           newWord[i]=a;newWord[j]=b;

                           if (tot<4&&dict.find(newWord)!=dict.end())
                           {
                           //    qDebug()<<"changeTwoLetter: "<<newWord<<" "<<i<<j;
                               ans[tot++]=newWord;
                           }
                       }
                    newWord[i]=primaryWord[i];
                    newWord[j]=primaryWord[j];
               }
    }
    void changeThreeLetter(QString* ans,int &tot,const QString &primaryWord){
        QString newWord=primaryWord;
        for (int i=primaryWord.size()-1;i>=0;i--)
               for (int j=i+1;j<primaryWord.size();j++)
                    for (int k=primaryWord.size()-1;k>j;k--)
                    {
                        for (char a='a';a<='z';a++)
                            for (char b='a';b<='z';b++)
                                for (char c='a';c<='z';c++) if (!(a==primaryWord[i]&&b==primaryWord[j]&&c==primaryWord[k]))
                                {
                                    newWord[i]=a;newWord[j]=b;newWord[k]=c;

                                    if (tot<4&&dict.find(newWord)!=dict.end())
                                    {
                                        ans[tot++]=newWord;
                                    }
                                }
                        newWord[i]=primaryWord[i];
                        newWord[j]=primaryWord[j];
                        newWord[k]=primaryWord[k];
                    }
    }

    QString* findSimilar(QString primaryWord)
    {
        QString *ans=new QString[5];int tot=1;
        ans[0]=primaryWord;

        if (primaryWord.size()==1)
        {
            ans[0]=primaryWord;ans[1]="b";ans[2]="c";ans[3]="d";
            std::random_shuffle(ans,ans+4);
            return ans;
        }
        changeOneLetter(ans,tot,primaryWord);
        if (primaryWord.size()>1&&tot<4) changeTwoLetter(ans,tot,primaryWord);
        //if (primaryWord.size()>2&&tot<4) changeThreeLetter(ans,tot,primaryWord);


        for (int i=tot+1;i<=4;i++){
            int ID=((rand()*rand())%Word::total+Word::total)%Word::total;
            ans[tot++]=word[ID].word;
        }
        std::random_shuffle(ans,ans+4);
        //for (int i=0;i<4;i++) qDebug()<<ans[i];
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
        //qDebug()<<"number of testList:"<<myList[i];

        ans[i].first=StartTest::getChinese(word[user[myList[i]].id].info);
       // qDebug()<<"word of testList:"<<ans[i].first;
        ans[i].second=StartTest::findSimilar(user[myList[i]].word);
        ans[i].third=-1;
        for (int j=0;j<4;j++){
            if (user[myList[i]].word == ans[i].second[j]) ans[i].third=j;
        }
    }

    User::recordTestList=myList;
    //qDebug()<<"!!"<<ans;//
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
        qDebug()<<"User:total :"<<User::total;
        for (int i=0;i<User::testWordTot;i++)
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
    qDebug()<<"try: endTest";
    EndTest::reloadTypeByUser();
    qDebug()<<"reloadTypeByUser() finish";
    saveUser();
    qDebug()<<"saveUser() finish";
}


//------------------------------------------------Article---------------------------------------------------------

namespace analysisArticleSpace{
    void makeStringList(const QString &paper,QStringList &article){
        article = paper.split(" ");
        for (int i=0;i<article.size();i++){
        //    qDebug()<<"article[i]: "<<article[i];
            if (!(('a'<=article[i][0]&&article[i][0]<='z')
                ||('A'<=article[i][0]&&article[i][0]<='Z'))){
                article[i]="###";
            }
        }
    }
}

QString Func::analysisArticle(QString paper)
{
    if ('A'<=paper[0]&&paper[0]<='Z') paper[0]=paper[0].toLower();
    //qDebug()<<"in analysisArticle";
    int *ans= new int[100];
    QString ans2="";
    QStringList article;int tot;
    analysisArticleSpace::makeStringList(paper,article);
    int myTot=0;
    for (int i=0;i<article.size();i++) if (article[i]!="###")
    {
        if (userDict.find(article[i])==userDict.end() && dict.find(article[i]) != dict.end())
        {
            ans[myTot++]=dict[article[i]];
            if (ans2!="") ans2=ans2+"\n";
            ans2=ans2+article[i];
        }
    }
    //qDebug()<<"myTot: "<<myTot;

    ans[myTot]=-1;
    return ans2;
}
