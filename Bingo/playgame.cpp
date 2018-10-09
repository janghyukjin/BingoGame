#include "playgame.hpp"
#include "rule.hpp"
#include <iostream>
#include <unistd.h>
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
    int rowcheck = 0;
    int colcheck = 0;
    int row=5;
    int col=5;
    int reset=0,reset2=0;
    if(map[2][2]!=0){
        SelectNum2 = map[2][2];
    }
    else{
        SelectNum2=rand()%25+1;
        for(int i=0;i<100;i++){
            for(int k=0;k<25;k++){
                if(num[k]==SelectNum2){
                    SelectNum2=rand()%25+1;
                    k=0;
                }
            }
            for(int j=0;j<5;j++){
                for(int s=0;s<5;s++){
                    if(map[j][s]==SelectNum2){
                        row=j;
                        col=s;
                    }
                }
            }
            for(int s=0;s<5;s++){
                if(map[row][s]==0){
                    colcheck++;
                }
            }
            for(int j=0;j<5;j++){
                if(map[j][col]==0){
                    rowcheck++;
                }
            }
            if(reset2<20){
                reset2++;
                if(colcheck==4||rowcheck==4){
                    rowcheck=0;
                    colcheck=0;
                    continue;
                }
                else{
                    if(colcheck==3||rowcheck==3){
                        rowcheck=0;
                        colcheck=0;
                        continue;
                    }
                    else{
                        if(colcheck==2||rowcheck==2){
                            rowcheck=0;
                            colcheck=0;
                            continue;
                        }
                        else{
                            if(colcheck==1||rowcheck==1){
                                rowcheck=0;
                                colcheck=0;
                                break;
                            }
                            else{
                                SelectNum2=rand()%25+1;
                                i=0;
                            }
                        }
                    }
                }
            }
        }
        reset=0;
        reset2=0;
    }
    for(int i=0;i<25;i++){
        if(num[i]==0){
            num[i]=SelectNum2;
            break;
        }
    }
    cout<<"Computer가 선택한 숫자 : "<<SelectNum2<<endl;
    usleep(1000000);
    rule gamerule2;
    gamerule2.ChangeMap(map,SelectNum2);
    gamerule2.ChangeMap(map2,SelectNum2);
}
