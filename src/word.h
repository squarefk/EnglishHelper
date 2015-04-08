#ifndef WORD_H
#define WORD_H

#include <string>
#include "func.h"


class Word
{
    QString word;
    QString info;
    //QString phoneticSymbols; //音标
    //QString partOfSpeech; //词性
    //QString interpretation; //释义
    //QString example; //例句
	//记忆参数

public:
	Word();
	~Word();
	static int total;// total if the total number  of words        #####!!!  need to be initialize!
	friend void Func::loadDictionary(Word* word);
    friend QString Func::query(QString a);
};

extern Word word[100000];

#endif
