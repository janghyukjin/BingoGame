#ifndef startgame_hpp
#define startgame_hpp
#include <stdio.h>

class startgame
{
private:
public:
    void MapSetting(int map[5][5]);
    void MapShuffle(int map[5][5]);
    void MapPrinting(int map[5][5], int map2[5][5]);
};
#endif /* startgame_hpp */
