
#include "Player.h"
#include "move.h"

class HumanPlayer : public Player{
	public:
		HumanPlayer();
		~HumanPlayer();

		bool check_user_move();
	private:
};
