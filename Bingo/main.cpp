#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "startgame.hpp"
#include "playgame.hpp"
#include "rule.hpp"
#define true 1

using namespace std;

int PlayerMap[5][5];
int ComputerMap[5][5];
int PlayerBingo=0;
int ComputerBingo=0;
int win=1;
int SelectNum[25]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
void result(){
    if(PlayerBingo>=5&&ComputerBingo>=5){
        cout<<"무승부입니다."<<endl;
        win++;
    }
    else if(PlayerBingo>=5){
        cout<<PlayerBingo<<" Bingo로 Player 승리!!"<<endl;
        win++;
    }
    else if(ComputerBingo>=5){
        cout<<ComputerBingo<<" Bingo로 Computer에게 패배ㅠ"<<endl;
        win--;
    }
}
int main(){
    srand((unsigned int)time(NULL));
    startgame game;
    game.MapSetting(PlayerMap);
    game.MapShuffle(PlayerMap);
    game.MapSetting(ComputerMap);
    game.MapShuffle(ComputerMap);
    game.MapPrinting(PlayerMap,ComputerMap);
    playgame play;
    rule bingorule;
    while(true){
        play.PlayerTurn(PlayerMap,ComputerMap,SelectNum);
        PlayerBingo=bingorule.BingoCheck(PlayerMap);
        ComputerBingo=bingorule.BingoCheck(ComputerMap);
        result();
        if(win!=1){
            game.MapPrinting(PlayerMap,ComputerMap);
            cout<<"   Player's Bingo : "<<PlayerBingo;
            cout<<"   |   Computer's Bingo : "<<ComputerBingo<<endl<<endl;
            break;
        }
        play.ComputerTurn(ComputerMap,PlayerMap,SelectNum);
        PlayerBingo=bingorule.BingoCheck(PlayerMap);
        ComputerBingo=bingorule.BingoCheck(ComputerMap);
        result();
        if(win!=1){
            game.MapPrinting(PlayerMap,ComputerMap);
            cout<<"   Player's Bingo : "<<PlayerBingo;
            cout<<"   |   Computer's Bingo : "<<ComputerBingo<<endl<<endl;
            break;
        }
        game.MapPrinting(PlayerMap,ComputerMap);
        cout<<"   Player's Bingo : "<<PlayerBingo;
        cout<<"   |   Computer's Bingo : "<<ComputerBingo<<endl<<endl;
    }
}
