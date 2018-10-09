#include "playgame.hpp"
#include "rule.hpp"
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

void playgame::PlayerTurn(int map[5][5], int map2[5][5], int num[25]){
    int SelectNum = 0;
    cout<<"숫자를 입력하세요 : ";
    cin >> SelectNum;
    cout<<""<<endl;
    for(int i=0;i<25;i++){
        if(num[i]==SelectNum){
            cout<<"중복된 숫자입니다, 다시 입력하세요 : ";
            cin>>SelectNum;
            i=0;
        }
    }
    for(int i=0;i<25;i++){
        if(num[i]==0){
            num[i]=SelectNum;
            break;
        }
    }
    rule gamerule;
    gamerule.ChangeMap(map,SelectNum);
    gamerule.ChangeMap(map2,SelectNum);
}

void playgame::ComputerTurn(int map[5][5], int map2[5][5], int num[25]){
    int SelectNum2 = 0;
    SelectNum2=rand()%25+1;
    for(int i=0;i<25;i++){
        if(num[i]==SelectNum2){
            SelectNum2=rand()%25+1;
            i=0;
        }
    }
    for(int i=0;i<25;i++){
        if(num[i]==0){
            num[i]=SelectNum2;
            break;
        }
    }
    rule gamerule2;
    gamerule2.ChangeMap(map,SelectNum2);
    gamerule2.ChangeMap(map2,SelectNum2);
}
