

#include "GameManager.h"
#include "move.h"

GameManager::GameManager(char computer_mode, int orientation): _computer_mode(computer_mode), _orientation(orientation), _game_board(orientation), _human(), _machine(_computer_mode) {
}

GameManager::~GameManager(){}

