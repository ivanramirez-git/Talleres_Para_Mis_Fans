#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

typedef vector<string> r;
typedef vector<r> matrix;

void get_board(matrix& board){
    //Pre: matrix filled with " ", conformed by 7 columns & 6 rows.
    //Post: board filled with the corresponding tokens.
    cout<<" -----------------------------";
    cout<<endl; 
    for(unsigned int j = 0;j< board.size();j++){
        cout<<j;
        for(unsigned int i = 0;i< board[j].size();i++){
            cout<<" | "<<board[j][i];
        }
        cout<<" |"<<endl;
        cout<<" -----------------------------";
        cout<<endl;
    }
    cout<<"  | 0 | 1 | 2 | 3 | 4 | 5 | 6 |"<<endl;
}

bool slot_checker (matrix&board, int column, int& row){
    //Pre: The board and two int that are the coordenates (column/row) where the token will go.
    //Post: Returns true if the coordenates are suitable to contain a token.
    bool empty=false;
    row=5; 
    while((row>=0) and (not empty)){
        //Inv: The latest examinated row is not empty.
        if (board[row][column]==" ") empty=true;
        else row--;
    }
    return empty;
}

void set_slot(matrix& board, int column, int row, string token){
    //Pre: Receives the coordinates of the empty last item in the column.
    //Post: Fills the location acordding to the coordinates.
    board[row][column] = token;
}

int CPU_turn (){
    //Pre: after users turn.
    //Post: Returns a number between 0-6 that will be the column where the computer plays its token.
    int column=rand()%7;
    return column;
}

bool win_v (matrix& board, string token, int column){
    //Pre: receives last token position.
    //Post: returns true if there are 4 equal tokens vertically aligned.
    bool vertical = false;
    bool match = false;
    int count = 0;
    for(int i = 0; i <= 5; i++){
        if(match){
            if(board[i][column] == token) count++;
            else{
                match = false;
                count = 0;
            }
        }
        if(board[i][column] == token and not match){
            match = true;
            count++;
        }
        if(count == 4) vertical = true;
    }
    return vertical;
}

bool win_h(matrix& board, string token, int row){
    //Pre: receives last token position.
    //Post: returns true if there are 4 equal tokens horizontally aligned.
    bool horizontal = false;
    bool match = false;
    int count = 0;
    for(int j = 0; j<= 6; j++){
        if(match){
            if(board[row][j] == token) count++;
            else{
                match = false;
                count = 0;
            }
        }
        if(board[row][j] == token and not match){
            match = true;
            count++;
        }
        if(count == 4) horizontal = true;
    }
    return horizontal;     
}

bool win_d_right (matrix& board, string token, int row, int column){
    //Pre: receives last token position.
    //Post: returns true if there are 4 equal tokens / aligned.
    bool diagonal = false;
    bool match = false;
    int count = 0;
    bool end = false;
    while(!end){
        //Inv: the actual position is not at the upper or right tip of the board
        if(column == 6 or row == 0) end = true;
        else{
            row--;
            column++;
        }
    }
    end = false;
    int row_aux = row;
    int column_aux = column;
    while(!end){
        //Inv: the actual position is not at the lower or left tip of the board
        if(column_aux == 0 or row_aux == 5) end = true;
        else{
            row_aux++;
            column_aux--;
        }
    }
    while(row <= row_aux and column >= column_aux){
        //Inv: Last examined element was not the last on the / diagonal.
        if(match){
            if(board[row][column] == token) count++; 
            else{
                match = false;
                count = 0;
            }
        }
        if(board[row][column] == token and not match){
            match = true;
            count++;
        }
        if(count == 4) diagonal = true;
        row++;
        column--;
    }

    return diagonal;

}

bool win_d_left (matrix& board, string token, int row, int column){
    //Pre: receives last token position.
    //Post: returns true if there are 4 equal tokens \ aligned.
    bool diagonal = false;
    bool match = false;
    int count = 0;
    bool end = false;
    while(!end){
        //Inv: the actual position is not at the upper or left tip of the board.
        if(column == 0 or row == 0) end = true;
        else{
            row--;
            column--;
        }
    }
    end = false;
    int row_aux = row;
    int column_aux = column;
    while(!end){
        //Inv: the actual position is not at the lower or left tip of the board.
        if(column_aux == 6 or row_aux == 5) end = true;
        else{
            row_aux++;
            column_aux++;
        }
    }

    while(row <= row_aux and column <= column_aux){
        //Inv: Last examined element was not the last on the \ diagonal
        if(match){
        
            if(board[row][column] == token){
                count++;
            } 
            else{
                match = false;
                count = 0;
            }
        }
        
        if(board[row][column] == token and not match){
            match = true;
            count++;
        }

        if(count == 4) diagonal = true;
        
        row++;
        column++;
    }

    return diagonal;
}

string win_check(matrix& board, string token, int column, int row){
    //Pre: recives the user identity and the coordenates of the token.
    //Post: returns the direction if there is a winner combination or a "none" if there is no winner.
    string way = "none";
    if(win_h(board,token,row)) way = "horizontal";
    if(win_v(board,token,column)) way = "vertical";
    if(win_d_right(board,token, row, column)) way = "diagonal dreta";
    if(win_d_left(board,token, row, column)) way = "diagonal esquerra";
    return way;
}  

int main(){

    bool gameOn = true,turn = true;
    int column, row, turnCounter = 0;
    string playerName,token,way;
    matrix board(6,r(7," "));
    srand(5);

    cout<<"Nom del jugador: ";cin>>playerName;cout<<endl;
    
    get_board(board);

    while(gameOn){
        //Inv: The game has not ended.
        while(turn){  
            //Inv: Next turn.
            cout<<endl;
            cout<<"================================"<<endl;
            if(turnCounter%2 == 0) cout<<"Torn de "<<playerName<<endl;
            else cout<<"Torn de la CPU"<<endl;
            
            cout<<"================================"<<endl;
            cout<<endl;

            if(turnCounter%2 == 0){
                cout<<"A quina columna vols col·locar la teva fitxa ? (0-6): "; cin>>column;
            } 
            else{
                column = CPU_turn();
                cout<<"La màquina ha decidit la columna "; cout<<column<<endl;
            }

            if(column<= 6 and slot_checker(board,column,row)){
                turn = false;
                if(turnCounter%2 == 0) set_slot(board,column,row,"X");
                else                    set_slot(board,column,row,"O");
                get_board(board);
            }
            else cout<<"Error, columna incorrecta !!"<<endl;
        }

        if(turnCounter%2 == 0) way = win_check(board, "X",column,row);
        else                   way = win_check(board, "O",column,row);

        if(way != "none"){
            cout<<endl;
            if(turnCounter%2 == 0) cout<<"Hi ha quatre en ratlla en "<<way<<" de "<<playerName<<"!!"<<endl;
            else                   cout<<"Hi ha quatre en ratlla en "<<way<<" de l'ordinador!!"<<endl;
            
            gameOn = false;
        }
        else turn = true;

        turnCounter++;

        if(turnCounter == 42){
            cout<<endl;
            cout<<"El taulell està Ple.  EMPAT!!"<<endl;
            gameOn = false;

        }
    }
}