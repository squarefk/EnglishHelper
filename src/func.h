#ifndef FUNC_H
#define FUNC_H

#include <QString>
#include <map>

class Word;

// The map named 'dict' is the index of words
// 1.string is the name of word
// 2.int is position number this word in word[]
extern std::map<QString,int> dict;
extern std::map<QString,int> userDict;


enum Answer{Yes,No};

class Func
{
private:
    QString similarList[10000];
    int numberList[10000];
    int similarTot;

public:
    class QueryPair{
    public:
        QString first;
        QString* second;
    };
    class TestPair{
    public:
        QString first;
        QString* second;
        int third;
    };
    Func();
	~Func();
    void loadExcel(QString dir);//导入Excel格式文件
    void loadXML(QString dir);//导入xml格式文件
    void loadDictionary(); //导入字典
    void saveDictionary();//导出字典
    void loadUser(); //导入记忆信息
	void saveUser(); //导出记忆信息
    QueryPair* query(QString a);//查单词
    TestPair* startTest(int tot);//测试准备
    void answerForTest(int id,Answer answer);//每道题的回答
    void endTest();//测试结束
    QString analysisArticle(QString article);//分析文章
};

extern std::map<QString,int> dict;
extern std::map<QString,int> userDict;


#endif
