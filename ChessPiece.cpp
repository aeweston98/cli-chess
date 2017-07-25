#include <string>
#include <vector>
#include <iostream>

#include "ChessPiece.h"


move::move(){};
move::move(int start, int dest, int validity_code): _start(start), _dest(dest), _validity_code(validity_code) {};
move::~move(){};

//Class constructors
ChessPiece::ChessPiece(std::string name1, std::string name2, int current_position, int colour): _name1(name1),_name2(name2), _current_position(current_position), _colour(colour) {};
Pawn::Pawn(int current_position, int colour): ChessPiece("P","p", current_position, colour){};
Rook::Rook(int current_position, int colour): ChessPiece("R", "r", current_position, colour){};
Horse::Horse(int current_position, int colour): ChessPiece("H", "h", current_position, colour){};
Bishop::Bishop(int current_position, int colour): ChessPiece("B", "b", current_position, colour){};
Queen::Queen(int current_position, int colour): ChessPiece("Q", "q", current_position, colour){};
King::King(int current_position, int colour): ChessPiece("K", "k", current_position, colour){};
EmptySpace::EmptySpace(int current_position): ChessPiece("-", "-", current_position, 0){};
Marker::Marker(int current_position, std::string mark): ChessPiece(mark, mark,current_position, 0){};

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

std::string ChessPiece::get_name() const{
	return _name1;
}

int ChessPiece::get_colour() const{
	return _colour;
}

void ChessPiece::display() const {
	if(_colour == 0){
		std::cout << _name1 << " ";
	}
	else{
		std::cout << _name2 << " "; 
	}
}

/* 
	Direction Definition (does not apply to horses)
	From the reference of the white player
	 1 2 3
	  \|/
	8 - - 4
	  /|\
	 7 6 5
*/

move ChessPiece::check_move_validity(const std::vector<ChessPiece*> &pieces, int direction, int distance) const{
	int check_pos = _current_position;
	int expl_position = _current_position;
	int validity_code = 0;

	// decide on direction
	switch(direction){
		case 1:
			check_pos += (_colour * distance * -10);
			expl_position += (_colour * (distance - 1) * -10);
			break;
		case 2:
			check_pos += (_colour * distance * -9);
			expl_position = 1; //don't want to check edges if we are moving straight
			break;
		case 3:
			check_pos += (_colour * distance * -8);
			expl_position += (_colour * (distance - 1) * -8);
			break;

		case 4:
			check_pos += (_colour * distance * 1);
			expl_position += (_colour * (distance - 1) * 1);
			break;
		case 5:
			check_pos += (_colour * distance * 10);
			expl_position += (_colour * (distance - 1) * 10);
			break;
		case 6:
			check_pos += (_colour * distance * 9);
			expl_position = 1; //don't want to check edges if we are moving straight
			break;
		case 7:
			check_pos += (_colour * distance * 8);
			expl_position += (_colour * (distance - 1) * 8);
			break;
		case 8:
			check_pos += (_colour * distance * -1);
			expl_position += (_colour * (distance - 1) * -1);
			break;
	}

	//check that we are not wrapping around the board
	if((expl_position % 9 - 1) == 0 || (expl_position + 1) % 9 == 0 || check_pos > 80 || check_pos < 10){
		validity_code = 0;
	}
	//if we have made a valid move in terms of board position, check what occupies the potential dest
	else{
		if(pieces[check_pos] -> get_name() == "-"){
			validity_code = 1;
		}
		else if(pieces[check_pos] -> _colour == _colour){
			validity_code = 0;
		}
		else{ //it is an opposing teams piece
			validity_code = 2;
		}
	}
	move return_move(_current_position, check_pos,validity_code);
	return return_move;
}


//Direction for horse moves go in clockwise direction starting from two forward, one left

move Horse::check_horse_move_validity(const std::vector<ChessPiece*> &pieces, int direction) const{
	int check_pos = _current_position;
	int expl_pos = _current_position;
	int validity_code = 0;

	// decide on direction
	//check inside the switch whether the move will cause us to wrap around the board
	switch(direction){
		case 1:
			if((_current_position - 1) % 9 != 0){
				check_pos += (_colour * -19);
				validity_code = 1;
			}
			break;
		case 2:
			if((_current_position + 1) % 9 != 0){
				check_pos += (_colour * -17);
				validity_code = 1;
			}
			break;
		case 3:
			if((_current_position + 1) % 9 != 0 && (_current_position + 2) % 9 != 0){
				check_pos += (_colour * -7);
				validity_code = 1;
			}
			break;
		case 4:
			if((_current_position + 1) % 9 != 0 && (_current_position + 2) % 9 != 0){
				check_pos += (_colour * 11);
				validity_code = 1;
			}
			break;
		case 5:
			if((_current_position + 1) % 9 != 0){
				check_pos += (_colour * 19);
				validity_code = 1;
			}
			break;
		case 6:
			if((_current_position - 1) % 9 != 0){
				check_pos += (_colour * 17);
				validity_code = 1;
			}
			break;
		case 7:
			if((_current_position - 2) % 9 != 0 && (_current_position - 1) % 9 != 0){
				check_pos += (_colour * 7);
				validity_code = 1;
			}
			break;
		case 8:
			if((_current_position - 2) % 9 != 0 && (_current_position - 1) % 9 != 0){
				check_pos += (_colour * -11);
				validity_code = 1;
			}
			break;
	}

	//if we have made a valid move in terms of board position, check what occupies the potential dest
	if(validity_code != 0 && check_pos <= 80 && check_pos >= 10){
		if(pieces[check_pos] -> get_name() == "-"){
			validity_code = 1;
		}
		else if(pieces[check_pos] -> get_colour() == _colour){
			validity_code = 0;
		}
		else{ //it is an opposing teams piece
			validity_code = 2;
		}
	}

	move return_move(_current_position, check_pos, validity_code);
	return return_move;	
}


void Pawn::possible_moves(std::vector<move> &moves, const std::vector<ChessPiece*> &pieces) const{
	move temp_move;

	for(int i = 1; i < 4; i++){
		temp_move = check_move_validity(pieces, i, 1);
		
		//empty space directly in front of the pawn
		if(i % 2 == 0 && temp_move._validity_code == 1){
			moves.push_back(temp_move);
		}
		//opposing piece one forward, diagonal step away
		else if(i % 2 == 1 && temp_move._validity_code == 2){
			moves.push_back(temp_move);
		}
	}
}

void Rook::possible_moves(std::vector<move> &moves, const std::vector<ChessPiece*> &pieces) const{
	int j = 1;
	move temp_move;

	for(int i = 2; i < 9; i += 2){
		while(true){
			//check the move
			temp_move = check_move_validity(pieces, i, j);
			
			//if the move is valid, check the next step forward in that direction
			if(temp_move._validity_code != 0){
				j++;
				moves.push_back(temp_move);
			}
			else{//reset and go to the next direction
				j = 1;
				break;
			}
		}
	}
}

void Horse::possible_moves(std::vector<move> &moves, const std::vector<ChessPiece*> &pieces) const{
	move temp_move;

	for(int i = 1; i < 9; i++){
		//check the move
		temp_move = check_horse_move_validity(pieces, i);

		if(temp_move._validity_code != 0){
			moves.push_back(temp_move);
		}
	}
}

void Bishop::possible_moves(std::vector<move> &moves, const std::vector<ChessPiece*> &pieces) const{
	int j = 1;
	move temp_move;

	for(int i = 1; i < 9; i += 2){
		while(true){
			//check the move
			temp_move = check_move_validity(pieces, i, j);
			
			//if the move is valid, check the next step forward in that direction
			if(temp_move._validity_code != 0){
				j++;
				moves.push_back(temp_move);
			}
			else{ //reset and go to the next direction
				j = 1;
				break;
			}
		}
	}
}

void Queen::possible_moves(std::vector<move> &moves, const std::vector<ChessPiece*> &pieces) const{
	int j = 1;
	move temp_move;

	for(int i = 1; i < 9; i ++){
		while(true){
			temp_move = check_move_validity(pieces, i, j);
			if(temp_move._validity_code != 0){
				j++;
				moves.push_back(temp_move);
			}
			else{
				j = 1;
				break;
			}
		}
	}
}

//need to give the king some more thought, since you have to check
//that you are not putting your king into check by moving it
void King::possible_moves(std::vector<move> &moves, const std::vector<ChessPiece*> &pieces) const{
	for(int i = 1; i < 9; i++){
		move temp_move = check_move_validity(pieces, i, 1);

		if(temp_move._validity_code != 0){
			moves.push_back(temp_move);
		}
	}

	//implement check to see if King can move here
	for(int i = 0; i < moves.size(); i++){

	}
}


