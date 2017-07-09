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

int ChessPiece::get_colour(){
	return _colour;
}

void ChessPiece::display() const {
	if(_colour == 0){
		std::cout << _name1 << " ";
	}
	else{
		std::cout << _name2<< " "; 
	}
}

int ChessPiece::check_move_validity(const Board &current_board, int direction, int distance) const{
	int check_pos = _colour;

	// decide on direction
	switch(direction){

	}

	//check within board boundaries

	if(current_board.get_board()[check_pos] -> get_name() == "-"){
		return 0;
	}
	else if(current_board.get_board()[check_pos] -> get_colour == _colour){
		return 1;
	}
	else{ //it is an opposing teams piece
		return 2;
	}
}


//implement check empty and check same team



void Pawn::possible_moves(std::vector<move> &moves, const Board &current_board){
	if(_current_position <= 71 && _current_position >= 9){
		if(current_board.get_board()[_current_position+(9*_colour)] -> get_name == "-"){
			move temp1 (_current_position, _current_position+(9*_colour));
			moves.push_back(temp1);
		}
		if(current_board.get_board()[_current_position+(8*_colour)] -> get_name() != "-" && current_board.get_board()[_current_position+(8*_colour)] -> get_colour() != _colour ){
			move temp2 (_current_position, _current_position+(8*_colour));
			moves.push_back(temp2);
		}
		if(current_board.get_board()[_current_position+(10*_colour)] -> get_name() != "-" && current_board.get_board()[_current_position+(10*_colour)] -> get_colour() != _colour){
			move temp3 (_current_position, _current_position+(10*_colour));
			moves.push_back(temp3);
		}
	}
	else{
		//this should never occur since the pawn will be converted at this point
		//but in case it does, there are no possible moves
		return;
	}

	if((_current_position <= 17 && _current_position >= 9) || (_current_position >= 63 && _current_position <= 71)){
		current_board.get_board()[_current_position] -> set_convert(true);
	}
}

void Rook::possible_moves(std::vector<move> &moves, const Board &current_board){
	int i = 1;
	//check left
	while(_current_position - (i*_colour) >= 0 && _current_position - (i*_colour) <= 80){
		move temp (_current_position, _current_position - (i*_colour));
		moves.push_back(temp);
		
		if(current_board.get_board()[_current_position - (i*_colour)] -> get_name == "-"){
			i++;
		}
		else{
			i=1;
			break;
		}
	}

	//check right
	while(_current_position + (i*_colour) >= 0 && _current_position + (i*_colour) <= 80){
		move temp (_current_position, _current_position + (i*_colour));
		moves.push_back(temp);

		if(current_board.get_board()[_current_position + (i*_colour)] -> get_name == "-"){
			i++;
		}
		else{
			i=1;
			break;
		}
	}
	//check down
	while(_current_position - (i*9*_colour) >= 0 && _current_position - (i*9*_colour) <= 80){
		move temp (_current_position, _current_position - (i*9*_colour));
		moves.push_back(temp);
		
		if(current_board.get_board()[_current_position - (i*9*_colour)] -> get_name == "-"){
			i++;
		}
		else{
			i=1;
			break;
		}
	}

	//check up
	while(_current_position + (i*9*_colour) >= 0 && _current_position + (i*9*_colour) <= 80){
		move temp (_current_position, _current_position + (i*9*_colour));
		moves.push_back(temp);
		
		if(current_board.get_board()[_current_position + (i*9*_colour)] -> get_name == "-"){
			i++;
		}
		else{
			i=1;
			break;
		}
	}
}

void Bishop::possible_moves(std::vector<move> &moves, const Board &current_board){

}

void Queen::possible_moves(std::vector<move> &moves, const Board &current_board){

}


void King::possible_moves(std::vector<move> &moves, const Board &current_board){
	bool safe_move = false;
	while(safe_move == false){
		//decide all possible moves
		if(_current_position - (i*9*_colour) >= 0 && _current_position - (i*9*_colour) <= 80){
			move temp1 (_current_position, _current_position+(9*_colour));
			moves.push_back(temp1);
		}
		if(_current_position - (i*9*_colour) >= 0 && _current_position - (i*9*_colour) <= 80){
			move temp2 (_current_position, _current_position+(8*_colour));
			moves.push_back(temp2);
		}
		if(_current_position - (i*9*_colour) >= 0 && _current_position - (i*9*_colour) <= 80){
			move temp3 (_current_position, _current_position+(10*_colour));
			moves.push_back(temp3);
		}


		//check if the move is valid
	}
}


