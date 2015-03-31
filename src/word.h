#ifndef WORD_H
#define WORD_H

#include <string>
using namespace std;

class Word
{
	string phoneticSymbols; //音标
	string partOfSpeech; //词性
	string interpretation; //释义
	string example; //例句
	//记忆参数

public:
	Word();
	~Word();
};

#endif
