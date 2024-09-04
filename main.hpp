#include<iostream>
using namespace std;

class Board{
    private:
        char arr[3][3];
        char winner;
    public:
        Board();
        void printarr();
        void setWinner(char nameIn);
        char getWinner();
        bool enterThePosition(int row,int column,char currentPlayer);
        char checkplayer(char playerX , char playerO ,char currentPlayer);
        void checkWinner(int row,int column);

};
Board::Board(){
    winner=' ';
    for (int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            arr[i][j]=' ';
        }
    }
}
void Board::printarr(){
    cout << "   |   |   " << endl;
    cout << " " << arr[0][0] << " | " << arr[0][1] << " | " << arr[0][2] << endl;
    cout << "___|___|___" << endl;
    cout << "   |   |   " << endl;
    cout << " " << arr[1][0] << " | " << arr[1][1] << " | " << arr[1][2] << endl;
    cout << "___|___|___" << endl;
    cout << "   |   |   " << endl;
    cout << " " << arr[2][0] << " | " << arr[2][1] << " | " << arr[2][2] << endl;
    cout << "   |   |   " << endl;
}
void Board::setWinner(char winnerIn){
    winner=winnerIn;
}
char Board::getWinner(){
    return winner;
}
bool Board::enterThePosition(int row,int column,char currentPlayer){
    if(row<0||row>2||column<0||column>2){
        cout<<"You have enterd invalid input try again.";
        return false;
    }
    if(arr[row][column]==' '){
        arr[row][column]=currentPlayer;
        return true;
    }
    else{
        cout<<"This position is filled try again.";
        return false;
    } 
}
char Board::checkplayer(char playerX , char playerO ,char currentPlayer){
    if(currentPlayer == playerX){
        return playerO;
    }
    else{
        return playerX;
    }
}
void Board::checkWinner(int row,int column){
    for(int i=0;i<3;i++){
        if(arr[row][0]!=' '&&arr[row][0]==arr[row][1]&&arr[row][2]==arr[row][1]){
            winner=arr[row][0];
        }
    }
    for(int i=0;i<3;i++){
        if(arr[0][column]!=' '&&arr[0][column]==arr[1][column]&&arr[1][column]==arr[2][column]){
            winner=arr[0][column];
        }
    }
    if(arr[0][0]==arr[1][1]&&arr[1][1]==arr[2][2]){
        winner=arr[0][0];
    }
    else if(arr[0][2]==arr[1][1]&&arr[1][1]==arr[2][0]){
        winner=arr[0][2];
    }
}