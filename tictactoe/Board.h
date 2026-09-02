#pragma once
#include <bits/stdc++.h>
#include "Symbol.h"
using namespace std;

class Board{
    vector<vector<Symbol>> board;
    int numLeft;

    bool checkWinnerHorizontal(int i, int j, Symbol s, int k){
        int leftSyms = 0, rightSims = 0;
        int x = i, y = j;
        while(x > 0){
            x--;
            if(board[x][y] == s) leftSyms++;
            else break;
        }
        x = i;
        while(x < board.size()-1){
            x++;
            if(board[x][y] == s) rightSims++;
            else break;
        }
        if(leftSyms + rightSims + 1 >= k) return true;
        return false;
    }

    bool checkWinnerVertical(int i, int j, Symbol s, int k){
        int leftSyms = 0, rightSims = 0;
        int x = i, y = j;
        while(y > 0){
            y--;
            if(board[x][y] == s) leftSyms++;
            else break;
        }
        y = j;
        while(y < board.size()-1){
            y++;
            if(board[x][y] == s) rightSims++;
            else break;
        }
        if(leftSyms + rightSims + 1 >= k) return true;
        return false;
    }

    bool checkWinnerDiag1(int i, int j, Symbol s, int k){
        int leftSyms = 0, rightSims = 0;
        int x = i, y = j;
        while(y > 0 && x > 0){
            y--;
            x--;
            if(board[x][y] == s) leftSyms++;
            else break;
        }
        x = i;
        y = j;
        while(y < board.size()-1 && x < board.size() - 1){
            x++;
            y++;
            if(board[x][y] == s) rightSims++;
            else break;
        }
        if(leftSyms + rightSims + 1 >= k) return true;
        return false;
    }

    bool checkWinnerDiag2(int i, int j, Symbol s, int k){
        int leftSyms = 0, rightSims = 0;
        int x = i, y = j;
        while(y < board.size()-1 && x > 0){
            y++;
            x--;
            if(board[x][y] == s) leftSyms++;
            else break;
        }
        x = i;
        y = j;
        while(y > 0 && x < board.size() - 1){
            x++;
            y--;
            if(board[x][y] == s) rightSims++;
            else break;
        }
        if(leftSyms + rightSims + 1 >= k) return true;
        return false;
    }


public:
    Board(int n){
        for(int i = 0; i < n; i++){
            vector<Symbol> row(n, Symbol::EMPTY);
            board.push_back(row);
        }
        this->numLeft = n*n;
    }

    bool checkValidMove(int i, int j){
        if(i < 1 || i > board.size()) return false;
        if(j < 1 || j > board.size()) return false;
        if(board[i-1][j-1] != Symbol::EMPTY) return false;
        return true;
    }

    bool makeMove(int i, int j, Symbol s){
        if(checkValidMove(i,j) == false){
            return false;
        }
        board[i-1][j-1] = s;
        numLeft--;
        return true;
    }

    bool checkWinner(int i, int j, Symbol s){
        i--;
        j--;
        bool horizontal = checkWinnerHorizontal(i,j,s,3);
        bool vertical = checkWinnerVertical(i,j,s,3);
        bool diag1 = checkWinnerDiag1(i,j,s,3);
        bool diag2 = checkWinnerDiag2(i,j,s,3);

        return ((horizontal||vertical)||(diag1||diag2));
    }

    bool checkDraw(){
        if(this->numLeft == 0) return true;
        return false;
    }

    void displayBoard(){
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board.size(); j++){
                if(board[i][j] == Symbol::X) cout<<"X"<<" ";
                else if(board[i][j] == Symbol::O) cout<<"O"<<" ";
                else cout<<"  ";
            }
            cout<<endl;
        }
    }
    
};