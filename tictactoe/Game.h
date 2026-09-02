#pragma once
#include <bits/stdc++.h>
#include "Symbol.h"
#include "Board.h"
#include "MoveResult.h"
using namespace std;

class Game {
    Board board;
    Symbol currentPlayer = Symbol::X;

    MoveResult makeMove(int i, int j){

        bool move = board.makeMove(i, j, currentPlayer);
        if(!move) return MoveResult::INVALID;

        if(board.checkWinner(i, j, currentPlayer)) return MoveResult::WIN;
        if(board.checkDraw()) return MoveResult::DRAW;

        if(currentPlayer == Symbol::X) currentPlayer = Symbol::O;
        else currentPlayer = Symbol::X;
        return MoveResult::LEGAL;
   }

public:
    Game(int n) : board(n) {}

    pair<int,int> getMove() {
        int i, j;
        cin >> i >> j;
        return {i, j};
    }

   void playGame(){
        while(true){
            if(currentPlayer == Symbol::X) cout<<"X's turn"<<endl;
            else cout<<"O's turn"<<endl;

            cout<<"Enter coordinates of your move"<<endl;
            pair<int,int> currMove = getMove();

            MoveResult currMoveResult = makeMove(currMove.first, currMove.second);

            if(currMoveResult == MoveResult::INVALID){
                cout<<"Invalid Move, try again"<<endl;
                continue;
            }
            
            board.displayBoard();
            if(currMoveResult == MoveResult::WIN){
                if(currentPlayer == Symbol::X) cout<<"X wins"<<endl;
                else cout<<"O wins"<<endl;
                return;
            }

            if(currMoveResult == MoveResult::DRAW){
                cout<<"DRAW"<<endl;
                return;
            }
        }
   }
};