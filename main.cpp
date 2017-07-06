//stdlib includes
#include <iostream>


//local includes
#include "Board.h"

char select_game_mode(){
	char user_input;

	do{
		std::cout << "Welcome to Anthony's Chess Game!" << std::endl;
		std::cout << "Your options for an oppontent are: \n Random Engine (enter r) \n Please select your opponent by inputting a character or input q to quit" << std::endl;
		std::cin >> user_input;
	} while(user_input != 'q' && user_input != 'r');
	return q;
}

void state_machine(){
	char game_mode = select_game_mode();
	if(game_mode == 'q'){return;}
	GameManager cur_game (game_mode);

	int active_player;
	
	while(cur_game.get_state != 0){
		//this loop gets passed over once per turn

	}

}



int main(){
	state_machine();

	return 0;	
}