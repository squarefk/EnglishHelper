#ifndef TRIE_H
#define TRIE_H

#include "word.h"

class Trie
{
	Word *word;
	Trie *next[26];

public:
	Trie();
	~Trie();
};

#endif
