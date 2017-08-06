

struct move{
	public:
		move();
		move(int start, int dest, int validity_code);
		~move();
	private:
		int _start;
		int _dest;
		int _validity_code; //0 is same colour, 1 is empty, 2 is other team
};
typedef struct move move;

move::move(): _start(0), _dest(0), _validity_code(0){};
move::move(int start, int dest, int validity_code): _start(start), _dest(dest), _validity_code(validity_code) {};
move::~move(){};
int move::get_move_validity(){ return _validity_code; }
int move::get_current_position(){ return _start; }
int move::get_new_position(){ return _dest; }