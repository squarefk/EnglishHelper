#ifndef USER_H
#define USER_H

#include <QString>


class User{
public:
    User();
    ~User();
    enum Type{newWord,grayWord,knownWord};

    QString word;
    int type;
    int time;
    int totVisit;
    int totWrong;
    int cotinueCorrect;
    int id;
    static int userTot;
    static int testWordTot;
    static int* recordTestList;
};

extern User user[100000];
#endif // USER_H

