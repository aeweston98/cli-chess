#include <string>
#include <vector>



class ChessPiece{
	public:
		ChessPiece();
		virtual ~ChessPiece();
		virtual  display() const = 0; 
		virtual void possible_moves(std::vector<int> &);

	private:
		std::string _name;
		int _current_position;
};

class Pawn: public ChessPiece{
	public:
		Pawn();
		~Pawn();
		void display() const override;
		void possible_moves(std::vector<int> &) override;
};

class Rook: public ChessPiece{
	public:
		Rook();
		~Rook();
		void display() const override;
		void possible_moves(std::vector<int> &) override;
};

class Horse: public ChessPiece{
	public:
		Horse();
		~Horse();
		void display() const override;
		void possible_moves(std::vector<int> &) override;
};

class Bishop: public ChessPiece{
	public:
		Bishop();
		~Bishop();
		void display() const override;
		void possible_moves(std::vector<int> &) override;
};

class Queen: public ChessPiece{
	public:
		Queen();
		~Queen();
		void display() const override;
		void possible_moves(std::vector<int> &) override;
};

class King: public ChessPiece{
	public:
		King();
		~King();
		void display() const override;
		void possible_moves(std::vector<int> &) override;
};

class EmptySpace: public ChessPiece{
	public:
		EmptySpace();
		~EmptySpace();
		void display() const override;
		void possible_moves(std::vector<int> &) override;
};

class Marker: public ChessPiece{
	public:
		Marker();
		~Marker();
		void display() const override;
		void possible_moves(std::vector<int> &) override;
};