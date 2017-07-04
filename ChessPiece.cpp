#include <string>
#include <vector>

#include "ChessPiece.h"


move::move(int start, int dest): _start(start), _dest(dest) {};
move::~move(){};

//Class constructors
ChessPiece::ChessPiece(std::string name1, std::string name2, int current_position, int colour): _name1(name1),_name2(name2), _current_position(current_position), _colour(colour) {};
Pawn::Pawn(int current_position, int colour): ChessPiece("P","p", current_position, colour){};
Rook::Rook(int current_position, int colour): ChessPiece("R", "r", current_position, colour){};
Horse::Horse(int current_position, int colour): ChessPiece("H", "h", current_position, colour){};
Bishop::Bishop(int current_position, int colour): ChessPiece("B", "b", current_position, colour){};
Queen::Queen(int current_position, int colour): ChessPiece("Q", "q", current_position, colour){};
King::King(int current_position, int colour): ChessPiece("K", "k", current_position, colour){};
EmptySpace::EmptySpace(int current_position): ChessPiece("-", "-" current_position){};
Marker::Marker(int current_position, std::string mark): ChessPiece(mark, mark,current_position){};

//Class Destructors
ChessPiece::~ChessPiece(){};
Pawn::~Pawn(){};
Rook::~Rook(){};
Horse::~Horse(){};
Bishop::~Bishop(){};
Queen::~Queen(){};
King::~King(){};
EmptySpace::~EmptySpace(){};
Marker::~Marker(){};

//Member functions
void ChessPiece::update_captured(bool new_captured){
	_captured = new_captured;
}

void ChessPiece::update_position(int new_position){
	_current_position = new_position;
}

std::string ChessPiece::get_name(){
	return _name1;
}

//should replace these inidivual display functions using templates
void ChessPiece::display() const {
	if(_colour == 0){
		std::cout << _name1 << " ";
	}
	else{
		std::cout << _name2<< " "; 
	}
}

void Pawn::possible_moves(std::vector<move> &moves, const Board &current_board){
	if(_current_position < 63){
		if(current_board[_current_position+(9*_colour)] -> get_name == "-"){
			move temp1 (_current_position, _current_position+(9*_colour));
			moves.push_back(temp1);
		}
		if(current_board[_current_position+(8*_colour)] -> get_name() != "-"){
			move temp2 (_current_position, _current_position+(8*_colour));
			moves.push_back(temp2);
		}
		if(current_board[_current_position+(10*_colour)] -> get_name() != "-"){
			move temp3 (_current_position, _current_position+(10*_colour));
			moves.push_back(temp3);
		}
		return;
	}
	else if(){
		move temp1 (_current_position, _current_position+(9*_colour));
		moves.push_back(temp1);
		move temp2 (_current_position, _current_position+(8*_colour));
		moves.push_back(temp2);
		move temp3 (_current_position, _current_position+(10*_colour));
		moves.push_back(temp3);

		//do something to convert the pawn

		return;
	}
	else{
		//this should never occur since the pawn will be converted at this point
		//but in case it does, there are no possible moves
		return;
	}
}


