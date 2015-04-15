#ifndef WORD_H
#define WORD_H

#include <string>
#include "func.h"


class Word
{
    //QString phoneticSymbols; //音标
    //QString partOfSpeech; //词性
    //QString interpretation; //释义
    //QString example; //例句
	//记忆参数

public:
    QString word;
    QString info;
    Word();
	~Word();
	static int total;// total if the total number  of words        #####!!!  need to be initialize!
	friend void Func::loadDictionary(Word* word);
    friend QString Func::query(QString a);
    friend QString *Func::similar(QString primaryWord);
};

extern Word word[100000];

class userWord:public Word{

};

#endif
