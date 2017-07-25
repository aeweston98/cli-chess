

#include "GameManager.h"

GameManager::GameManager(char computer_mode, int orientation): _computer_mode(computer_mode), _orientation(orientation), _game_board(orientation), _human(), _machine(_computer_mode) {
	//HumanPlayer's constructor is not defined yet
	//MachinePlayer's constructor is also undefined but it will require this value
}

GameManager::~GameManager(){}

