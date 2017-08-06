

#include "GameManager.h"
#include "move.h"

GameManager::GameManager(char computer_mode, int orientation): _computer_mode(computer_mode), _orientation(orientation), _game_board(orientation), _human(), _machine(_computer_mode) {
}

GameManager::~GameManager(){}

/*
	1. get active player
	2. if regular user, ask for their move. If computer, compute all moves.
	3. if regular user, check if their move is valid. If computer , decide what move to take
	4. update the positions
	5. check if the game has ended or change a pawn.
	6. draw the new board 
	7. return
*/

std::string get_winner(){
	return _winner;
}

void GameManager::go(){
	
	move new_move();

	if(_active_player == 0){
		_human.get_user_move(new_move);
		_human.check_move_validity();
	}
	else if(_active_player == 1){
		_machine.get_all_moves();
		_machine.decide_move();
	}
	else{
		return;
	}

	if(new_move.get_move_validity() > 0){
		_game_board.update_board(new_move);
		_game_board.print_board();
	}
}


