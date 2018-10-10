#ifndef Playgame_hpp
#define Playgame_hpp
#include <stdio.h>

class Playgame
{
private:
public:
    void PlayerTurn(int map[5][5], int map2[5][5], int num[25]);
    void ComputerTurn(int map[5][5], int map2[5][5], int num[25]);
};
#endif /* Playgame_hpp */
