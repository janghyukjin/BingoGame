#include "rule.hpp"
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

void rule::ChangeMap(int map[5][5], int num){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(map[i][j]==num){
                map[i][j]=0;
            }
        }
    }
}
int rule::BingoCheck(int map[5][5]){
    int bingo=0;
    int check=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(map[i][j]!=0){
                check++;
            }
        }
        if(check==0){
            bingo++;
        }
        else{
            check=0;
        }
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(map[j][i]!=0){
                check++;
            }
        }
        if(check==0){
            bingo++;
        }
        else{
            check=0;
        }
    }
    if(map[0][0]==0&&map[1][1]==0&&map[2][2]==0&&map[3][3]==0&&map[4][4]==0){
        bingo++;
    }
    if(map[0][4]==0&&map[1][3]==0&&map[2][2]==0&&map[3][1]==0&&map[4][0]==0){
        bingo++;
    }
    return bingo;
}

