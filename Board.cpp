#include <iostream>
#include <vector>

#include "Board.h"

Board::Board(int orientation) : _orientation(orientation){
	//inititalize the board vector, sadly this requires a bit of hard coded setting
	
}

Board::~Board(){}


void Board::print_board(){
	//print board for user as white orientation
	if(_orientation == 0){
		for(int i = 0; i < _pieces.size(); i++){
			_pieces[i] -> display();
			if(i-1 % 9 == 0){
				std::cout << "\n \n";
			}
		}
	}
	//print board for user as black orientation
	else{
		for(int i = 80; i >= 0; i--){
			_pieces[i] -> display();
			if(i-1 % 9 == 0){
				std::cout << "\n \n";
			}
		}
	}
}

void Board::get_board(std::vector<ChessPiece*> &pieces){
	pieces = _pieces;
	return;
}