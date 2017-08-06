#include <string>

#include "Board.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "MachinePlayer.h"

class GameManager{
	public:
		GameManager(char computer_mode, int orientation);
		~GameManager();

		std::string get_winner();

	private:
		//the board
		Board _game_board;

		//the players
		HumanPlayer _human;
		MachinePlayer _machine;

		//other variables
		int _game_state;
		char _computer_mode;
		int _orientation;
		int _active_player;

		std::string _winner;
};