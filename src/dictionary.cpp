#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "word.h"
#include "trie.h"

class Dictionary
{
	Trie *trie;
public:
	Dictionary();
	~Dictionary();
	void insert(string); //插入一个单词
	Word Query(string word); //返回一个单词的所有信息
};

#endif