#pragma once

#include <iostream>
#include <vector>

#include "ChessPiece.h"
#include "move.h"

class Board{
	public:
		Board(int orientation);
		~Board();

		void print_board();
		void get_board(std::vector<ChessPiece*> &pieces);

		void update_board(move);

	private:
		int _orientation;
		std::vector<ChessPiece*> _pieces;
};