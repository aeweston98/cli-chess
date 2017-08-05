
#include "Player.h"

class MachinePlayer: public Player{
	public:
		MachinePlayer();
		MachinePlayer(char);
		~MachinePlayer();
	private:
		char _player_type;
};