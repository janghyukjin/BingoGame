#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "startgame.hpp"

using namespace std;

void startgame::MapSetting(int map[5][5]){
    int number=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            map[i][j]=++number;
        }
    }
}
void startgame::MapShuffle(int map[5][5]){
    int col1,col2;
    int row1,row2;
    int temp;
    for(int i=0;i<25;i++){
        col1=rand()%5;
        col2=rand()%5;
        row1=rand()%5;
        row2=rand()%5;
        temp=map[row1][col1];
        map[row1][col1]=map[row2][col2];
        map[row2][col2]=temp;
    }
}
void startgame::MapPrinting(int map[5][5], int map2[5][5]){
    cout<<"******************* BINGO GAME *******************"<<endl;
    cout<<"Computer와 번갈아 가며 Play 진행, 5빙고를 먼저 완성시키면 승리!"<<endl;
    cout<<"**************************************************"<<endl;
    cout<<" -----------------------------------------------"<<endl;
    for(int i=0;i<5;i++){
        cout<<" ";
        cout<<"|";
        for(int j=0;j<5;j++){
            cout.width(4);
            cout<<map[i][j];
        }
        cout<<"\t"<<"|";
        for(int j=0;j<5;j++){
            if(map2[i][j]==0){
                cout.width(4);
                cout<<"0";
            }
            else{
                cout.width(4);
                cout<<"@";
            }
        }
        cout<<"  |"<<endl;
    }
    cout<<" -----------------------------------------------"<<endl;
}
