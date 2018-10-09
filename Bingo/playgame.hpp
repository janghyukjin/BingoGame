#ifndef playgame_hpp
#define playgame_hpp
#include <stdio.h>

class playgame
{
private:
public:
    void PlayerTurn(int map[5][5], int map2[5][5], int num[25]);
    void ComputerTurn(int map[5][5], int map2[5][5], int num[25]);
};
#endif /* playgame_hpp */
