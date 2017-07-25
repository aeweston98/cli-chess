#pragma once

#include <string>
#include <vector>


struct move{
	move();
	move(int start, int dest, int validity_code);
	~move();
	int _start;
	int _dest;
	int _validity_code; //for use in check_move_validity method
};
typedef struct move move;

class ChessPiece{
	public:
		ChessPiece(std::string name1, std::string name2, int current_position, int colour);
		virtual ~ChessPiece();
		void display() const; 
		virtual void possible_moves(std::vector<move> &, const std::vector<ChessPiece*> &pieces) const = 0;
		void update_captured(bool new_captured);
		void update_position(int new_position);
		std::string get_name() const;
		int get_colour() const;
		move check_move_validity(const std::vector<ChessPiece*> &pieces, int direction, int distance) const;

	protected:
		int _current_position;
		int _colour; //0 for white, 1 for black

	private:
		std::string _name1;
		std::string _name2;
		bool _captured = false;
};

class Pawn:  public ChessPiece{
	public:
		Pawn(int current_position, int colour);
		~Pawn();
		void possible_moves(std::vector<move> &, const std::vector<ChessPiece*> &pieces) const override;
		void set_convert(bool convert){_convert_pawn = convert;}
	private:
		bool _convert_pawn = false;
};

class Rook: public ChessPiece{
	public:
		Rook(int current_position, int colour);
		~Rook();
		void possible_moves(std::vector<move> &, const std::vector<ChessPiece*> &pieces) const override;
};

class Horse: public ChessPiece{
	public:
		Horse(int current_position, int colour);
		~Horse();
		void possible_moves(std::vector<move> &, const std::vector<ChessPiece*> &pieces) const override;
		move check_horse_move_validity(const std::vector<ChessPiece*> &pieces, int direction) const;
};

class Bishop: public ChessPiece{
	public:
		Bishop(int current_position, int colour);
		~Bishop();
		void possible_moves(std::vector<move> &, const std::vector<ChessPiece*> &pieces) const override;
};

class Queen: public ChessPiece{
	public:
		Queen(int current_position, int colour);
		~Queen();
		void possible_moves(std::vector<move> &, const std::vector<ChessPiece*> &pieces) const override;
};

class King: public ChessPiece{
	public:
		King(int current_position, int colour);
		~King();
		void possible_moves(std::vector<move> &, const std::vector<ChessPiece*> &pieces) const override;
};

class EmptySpace: public ChessPiece{
	public:
		EmptySpace(int current_position);
		~EmptySpace();
		void possible_moves(std::vector<move> &, const std::vector<ChessPiece*> &pieces) const override;
	private:
		int _colour = 0;
};

class Marker: public ChessPiece{
	public:
		Marker(int current_position, std::string mark);
		~Marker();
		void possible_moves(std::vector<move> &, const std::vector<ChessPiece*> &pieces) const override;
	private:
		int _colour = 0;
};