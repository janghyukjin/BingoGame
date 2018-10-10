#ifndef rule_hpp
#define rule_hpp
#include <stdio.h>

class rule
{
private:
public:
    void ChangeMap(int map[5][5],int num);
    int BingoCheck(int map[5][5]);
};
#endif /* rule_hpp */
