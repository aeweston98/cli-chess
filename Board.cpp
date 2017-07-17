#include <iostream>
#include <vector>

#include "Board.h"

Board::Board(int orientation) : _orientation(orientation){
	//inititalize the board vector, sadly this requires a bit of hard coded setting
	ChessPiece * temp = nullptr;
	int i = 10; //this doesn't really matter right now, but if the board arrangement changes it will be helpful
	int colour = orientation;

	temp = new Rook(i, colour);
	_pieces[i] = temp;
	i++;

	temp = new Horse(i, colour);
	_pieces[i] = temp;
	i++;

	temp = new Bishop(i, colour);
	_pieces[i] = temp;
	i++;

	temp = new Queen(i, colour);
	_pieces[i] = temp;
	i++;

	temp = new King(i, colour);
	_pieces[i] = temp;
	i++;

	temp = new Bishop(i, colour);
	_pieces[i] = temp;
	i++;

	temp = new Horse(i, colour);
	_pieces[i] = temp;
	i++;

	temp = new Rook(i, colour);
	_pieces[i] = temp;
	i++;

	for(i = 19; i <= 26; i++){
		temp = new Pawn(i, colour);
		_pieces[i] = temp;
	}

	for(int i = 28; i <= 62; i++){
		//make sure its not a marker spot (left column of board)
		if(i % 9 != 0){
			temp = new EmptySpace(i);
			_pieces[i] = temp;
		}
	}

	//forgot how to use ternary operator
	if(colour == 1){
		colour = 0;
	}
	else{
		colour = 1;
	}

	for(i = 64; i <= 71; i++){
		temp = new Pawn(i, colour);
		_pieces[i] = temp;
	}

	i = 73;

	temp = new Rook(i, colour);
	_pieces[i] = temp;
	i++;

	temp = new Horse(i, colour);
	_pieces[i] = temp;
	i++;

	temp = new Bishop(i,colour);
	_pieces[i] = temp;
	i++;

	temp = new Queen(i, colour);
	_pieces[i] = temp;
	i++;

	temp = new King(i, colour);
	_pieces[i] = temp;
	i++;

	temp = new Bishop(i, colour);
	_pieces[i] = temp;
	i++;

	temp = new Horse(i, colour);
	_pieces[i] = temp;
	i++;

	temp = new Rook(i, colour);
	_pieces[i] = temp;

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