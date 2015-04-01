#include "func.h"
#include "word.h"
using namespace std;

Func::Func()
{

}

Func::~Func()
{
	
}

//**********************************************
//  This is function of loaddictionary from ../lib/dict/dict.txt
//  Function will do two things
//  1.read from dict and make message into word[]
//  2.and pair<sting,int> into map , the 'int' is the position number of this word in word[]
//**********************************************
void Func::loadDictionary(Word* word)
{
	freopen("../lib/dict/dict.txt","r",stdin);
	
	string cut="------------------------------";
	string str,a,myword;
	char b[500];
	
	//1.
	while (gets(b)){
		a=b;
		if (a==cut){
			if (str.size()!=0){
				while (a[a.size()-1]==' '||a[a.size()-1]=='\n') a.erase(a.size()-1);
				for (int i=0;i<int(a.size());i++){
					if (a[i]=='('||a[i]=='/') break;
					myword+=a[i];
				}
				Word::total++;
				word[Word::total].word=myword;
				word[Word::total].info=a;
			}
		}else{
			if (str.size()!=0) str=str+'\n';
			str=str+a;
		}
	}
	
	//2.
	for (int i=1;i<=word[0].total;i++){
		dict.insert(pair<string,int>(word[i].word,i));
	}
}

void Func::loadUser()
{

}

void Func::saveUser()
{

}

string *Func::similar(string word)
{
}

string Func::randomWord()
{

}

void Func::article(char *file)
{

}
