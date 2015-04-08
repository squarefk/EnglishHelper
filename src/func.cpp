#include "func.h"
#include "word.h"

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

std::map<QString,int> dict;


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
//  2.and pair<sting,i1nt> into map , the 'int' is the position number of this word in word[]
//**********************************************

QString* findSimilar(QString a){
}

QString Func::query(QString a){
	if (dict.find(a) != dict.end()){
		int b=dict[a];
		return word[b].info;
	}
	return "No this word!";
}
 

void Func::loadDictionary(Word* word)
{
	freopen("../lib/dict/dict.txt","r",stdin);
	
    QString cut="------------------------------";
    QString str,a,myword;
	char b[5000];
	
	//1.
	int count=0;
	while (gets(b)){
		count++;
		a=b;
	//	if (count>1000000) break; 
		
		if (a==cut){
			if (str.size()!=0){
                while (str.size()&&str[str.size()-1]<=32) str.remove(str.size()-2,1);
				for (int i=0;i<int(str.size());i++){
					if (str[i]=='('||str[i]=='/') break;
					myword+=str[i];
				}
                while (myword.size()&&myword[myword.size()-1]<=32) myword.remove(myword.size()-2,1);
				
				Word::total++;
				word[Word::total].word=myword;
				word[Word::total].info=str;
				/*if (Word::total==286){
					//cout<<str<<endl;
					cout<<word[286].word<<endl;
					cout<<"abashed"<<endl;
                    QString aaa="abashed";
					for (int i=0;i<7;i++) printf("%d %d\n",word[286].word[i],aaa[i]);
					printf("#%d\n",word[286].word[7]);
					cout<<"$"<<word[286].word[7]<<"$"<<endl;
					printf("!!%d %d\n",aaa.size(),word[286].word.size());
					//cout<<word[286].info<<endl;
					cout<<(word[286].word=="abashed")<<endl;
				}*/
				str="";
				myword="";
			}
		}else{
			if (str.size()!=0) str=str+'\n';
			str=str+a;
		}
	}
	//2.
	for (int i=1;i<=word[0].total;i++){
        dict.insert(std::pair<QString,int>(word[i].word,i));
	}
}

void Func::loadUser()
{

}

void Func::saveUser()
{

}

QString *Func::similar(QString word)
{
}

QString Func::randomWord()
{

}

void Func::article(char *file)
{

}
