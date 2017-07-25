#pragma once

#include <iostream>
#include <vector>

#include "ChessPiece.h"

class Board{
	public:
		Board(int orientation);
		~Board();

		void print_board();
		void get_board(std::vector<ChessPiece*> &pieces);

	private:
		int _orientation;
		std::vector<ChessPiece*> _pieces;
};