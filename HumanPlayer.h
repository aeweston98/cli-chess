
#include "Player.h"
#include "move.h"

class HumanPlayer : public Player{
	public:
		HumanPlayer();
		~HumanPlayer();

		bool check_user_move(move user_attempt_move);
	private:
		
};
