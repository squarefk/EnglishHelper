#ifndef FUNC_H
#define FUNC_H

#include <string>
using namespace std;

class Func
{
public:
	Func();
	~Func();
	void loadDictionary(); //导入字典
	void loadUser(); //导入记忆信息
	void saveUser(); //导出记忆信息
	string *similar(string word); //生成相似单词(增加前缀和后缀，修改相邻字母的位置，然后查询这个词是否在字典中出现)
	string randomWord(); //随机生成单词
	void article(char *file); //助手
};

#endif
