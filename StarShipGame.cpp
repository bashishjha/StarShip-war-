#include <bits/stdc++.h>
using namespace std;

int main(){
    cout<<"Welcome to 1-D Battleship!\n";
    //user setup
    string name;
    cout<<"Select your name: ";
    cin>>name;
    int lengthBattlefeild;
    int numberShips;
    int shipSize;
    cout<<"Now choose size of the battlefield: ";
    cin>>lengthBattlefeild;
    cout<<"Number of ships: ";
    cin>>numberShips;
    cout<<"Size of the ships: ";
    cin>>shipSize;
    string board;
    for(int i=1;i<=lengthBattlefeild;++i)
        board+='_';
    cout<<"User: "<<name<<endl;
    cout<<"Board status\n";
    cout<<board<<endl;
    cout<<name<<", place your ships on the board!\n";
    for(int i=0;i<numberShips;){
        cout<<"Add ship index: ";
        int idx;
        cin>>idx;
        string temp=board;
        int flag=0;
        if(idx!=1&&temp[idx-2]=='#'){
                flag=1;
            }
        if(flag==0){
                for(int j=idx-1;j<shipSize+idx-1;++j){
                if(temp[j]=='#'||j>=lengthBattlefeild){
                    flag=1;
                    break;
                }
                else{
                    temp[j]='#';
                }
            }
        }
        if(flag==1){
            cout<<"You could not place the ship because of the overlaps. Change the position.\n";
        }
        else{
            board=temp;
             cout<<"User: "<<name<<endl;
            cout<<"Board status\n";
            cout<<board<<endl;
            ++i;
        }
    }
// Computer setup
    string comBoard;
    for(int i=1;i<=lengthBattlefeild;++i)
        comBoard+='_';
    for(int i=0;i<numberShips;){
        int idx=rand()%lengthBattlefeild;
        if(idx==0)
            idx=lengthBattlefeild;
        string temp=comBoard;
        int flag=0;
        if(idx!=1&&temp[idx-2]=='#'){
                flag=1;
            }
        if(flag==0){
                for(int j=idx-1;j<shipSize+idx-1;++j){
                if(temp[j]=='#'||j>=lengthBattlefeild){
                    flag=1;
                    break;
                }
                else{
                    temp[j]='#';
                }
            }
        }
        if(flag==0){
            comBoard=temp;
            ++i;
        }
    }
    cout<<"computer board: "<<comBoard<<endl;
    //Game start
    cout<<"We are ready to start!\n";
    string temp;
    for(int i=0;i<lengthBattlefeild;++i){
        temp+='_';
    }
    while(1){
        cout<<"Select position of the shot: ";
        int idx;
        cin>>idx;
        if(comBoard[idx-1]=='_'){
            cout<<"You missed\n";
            temp[idx-1]='o';
        }
        else{
            cout<<"You got a hit"<<endl;
            temp[idx-1]='x';
            comBoard[idx-1]='x';
        }
        cout<<"This is how computer's field looks like now:\n";
        cout<<temp<<endl;
        cout<<"Computer's turn\n";
        idx=rand()%lengthBattlefeild;
        if(idx==0)
            idx=lengthBattlefeild;
        if(board[idx-1]=='#'){
            cout<<"You got hit at position: "<<idx<<endl;
            board[idx-1]='x';
        }
        else{
            cout<<"Computer missed"<<endl;
        }
        int computerWinner=1;
        int userWinner=1;
        for(int i=0;i<lengthBattlefeild;++i){
            if(comBoard[i]=='#'){
                userWinner=0;
            }
            if(board[i]=='#'){
                computerWinner=0;
            }
        }
        if(computerWinner==1){
            cout<<"COMPUTER WINS\n";
            break;
        }
        else if(userWinner==1)
        {
             cout<<"YOU WINS\n";
            break;
        }
        
    }

    return 0;
}