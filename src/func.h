#ifndef FUNC_H
#define FUNC_H

#include <QString>
#include <map>

class Word;

// The map named 'dict' is the index of words
// 1.string is the name of word
// 2.int is position number this word in word[]
extern std::map<QString,int> dict;

class Func
{
public:
	Func();
	~Func();
	void loadDictionary(Word *word); //导入字典
	void loadUser(); //导入记忆信息
	void saveUser(); //导出记忆信息
    QString *similar(QString word); //生成相似单词(增加前缀和后缀，修改相邻字母的位置，然后查询这个词是否在字典中出现)
    QString randomWord(); //随机生成单词
	void article(char *file); //助手
    QString query(QString a);
    QString* findSame(QString a);
};


#endif
