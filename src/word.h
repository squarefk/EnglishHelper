#ifndef WORD_H
#define WORD_H

#include <string>
#include "func.h"


class Word
{
	static int total;// total if the total number  of words        #####!!!  need to be initialize!
	std::string word;
	std::string info; 
	//string phoneticSymbols; //音标
	//string partOfSpeech; //词性
	//string interpretation; //释义
	//string example; //例句
	//记忆参数

public:
	Word();
	~Word();
	friend void Func::loadDictionary(Word* word);
};

#endif
