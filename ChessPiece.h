#include <string>
#include <vector>

struct move{
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
		virtual void possible_moves(std::vector<move> &, const Board &) const = 0;
		void update_captured(bool new_captured);
		void update_position(int new_position);
		std::string get_name();
		int get_colour();
		virtual int check_move_validity(const Board &current_board, int direction, int distance) const;
	private:
		std::string _name;
		int _current_position;
		bool _captured = false;
		int _colour; //-1 for white, 1 for black
};

class Pawn:  public ChessPiece{
	public:
		Pawn(int current_position, int colour);
		~Pawn();
		void possible_moves(std::vector<move> &, const Board &) const override;
		void set_convert(bool convert){_convert_pawn = convert};
	private:
		bool _convert_pawn = false;
};

class Rook: public ChessPiece{
	public:
		Rook(int current_position, int colour);
		~Rook();
		void possible_moves(std::vector<move> &, const Board &) const override;
};

class Horse: public ChessPiece{
	public:
		Horse(int current_position, int colour);
		~Horse();
		void possible_moves(std::vector<move> &, const Board &) const override;
		int check_move_validity() const override;
};

class Bishop: public ChessPiece{
	public:
		Bishop(int current_position, int colour);
		~Bishop();
		void possible_moves(std::vector<move> &, const Board &) const override;
};

class Queen: public ChessPiece{
	public:
		Queen(int current_position, int colour);
		~Queen();
		void possible_moves(std::vector<move> &, const Board &) const override;
};

class King: public ChessPiece{
	public:
		King(int current_position, int colour);
		~King();
		void possible_moves(std::vector<move> &, const Board &) const override;
};

class EmptySpace: public ChessPiece{
	public:
		EmptySpace(int current_position);
		~EmptySpace();
		void possible_moves(std::vector<move> &, const Board &) const override;
	private:
		int _colour = 0;
};

class Marker: public ChessPiece{
	public:
		Marker(int current_position, std::string mark);
		~Marker();
		void possible_moves(std::vector<move> &, const Board &) const override;
	private:
		int _colour = 0;
};