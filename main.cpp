#include "main.hpp"
int main(){
    Board game;
    char playerX='X';
    char playerO='O';
    char currentPlayer=playerX;
    int r=-1;
    int c=-1;
    //print the empty board
    game.printarr();
    for(int i=0;i<9;i++)
    {
        cout<<"Current player is = "<<currentPlayer<<endl;
        cout<<"Please enter from 0-2 for the row and column that you want."<<endl;
        cin>>r>>c;
        while(game.enterThePosition(r,c,currentPlayer)!=1)
        {
            //Reset the values
            cout<<"Please retry the entery."<<endl;
            cin>>r>>c;
        }
        //print the board so the player can see the game
        game.printarr();
        //To change the current player
        currentPlayer = game.checkplayer(playerX , playerO , currentPlayer);
        game.checkWinner(r,c);
        if(game.getWinner()!=' '){
            break;
        }
    }
    if(game.getWinner()==' '){
        cout<<"It's a tie.";
    }
    else {
        cout<<"The winner is player "<<game.getWinner()<<endl;
    }

    return 0;
}