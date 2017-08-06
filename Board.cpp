#include <iostream>
#include <vector>

#include "Board.h"


Board::Board(int orientation) : _orientation(orientation){
	//inititalize the board vector, sadly this requires a bit of hard coded setting
	ChessPiece * temp = nullptr;
	int i = 10; //this doesn't really matter right now, but if the board arrangement changes it will be helpful
	int colour = orientation;

	temp = new Rook(i, colour);
	_pieces.push_back(temp);
	i++;

	temp = new Horse(i, colour);
	_pieces.push_back(temp);
	i++;

	temp = new Bishop(i, colour);
	_pieces.push_back(temp);
	i++;

	temp = new Queen(i, colour);
	_pieces.push_back(temp);
	i++;

	temp = new King(i, colour);
	_pieces.push_back(temp);
	i++;

	temp = new Bishop(i, colour);
	_pieces.push_back(temp);
	i++;

	temp = new Horse(i, colour);
	_pieces.push_back(temp);
	i++;

	temp = new Rook(i, colour);
	_pieces.push_back(temp);
	i++;

	for(i = 19; i <= 26; i++){
		temp = new Pawn(i, colour);
		_pieces.push_back(temp);
	}

	for(int i = 28; i <= 62; i++){
		//make sure its not a marker spot (left column of board)
		if(i % 9 != 0){
			temp = new EmptySpace(i);
			_pieces.push_back(temp);
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
		_pieces.push_back(temp);
	}

	i = 73;

	temp = new Rook(i, colour);
	_pieces.push_back(temp);
	i++;

	temp = new Horse(i, colour);
	_pieces.push_back(temp);
	i++;

	temp = new Bishop(i,colour);
	_pieces.push_back(temp);
	i++;

	temp = new Queen(i, colour);
	_pieces.push_back(temp);
	i++;

	temp = new King(i, colour);
	_pieces.push_back(temp);
	i++;

	temp = new Bishop(i, colour);
	_pieces.push_back(temp);
	i++;

	temp = new Horse(i, colour);
	_pieces.push_back(temp);
	i++;

	temp = new Rook(i, colour);
	_pieces.push_back(temp);

}

Board::~Board(){
	for(int i = 0; i < _pieces.size(); i++){
		delete _pieces[i];
	}
}

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

void Board::update_board(move new_move){
	int current = move.get_current_position();
	int dest = move.get_new_position();

	ChessPiece * new_marker = new Marker(current, "-");

	//clean up whatever is in the destination spot of the move
	if(_pieces[dest] != nullptr){
		delete _pieces[dest];
		_pieces[dest] = nullptr;
	}

	_pieces[dest] = _pieces[current];
	_pieces[current] = new_marker;
}