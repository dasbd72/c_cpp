#include <iostream>
#include <vector>
using namespace std;
int Rows, Cols;
int Targets;
enum MatrixCode : char {
    EMPTY = ' ',
    WALL = '#',
    TARGET = '.',
    FRAGILE = '@',
    BOX = 'x',
    BOXT = 'X',
    PLY = 'o',
    PLYT = 'O',
    PLYF = '!',
    NONE = '\0'
};
enum Direction : char {
    UP = 'W',
    DOWN = 'S',
    LEFT = 'A',
    RIGHT = 'D',
    NONEDIR = '\0'
};
Direction& operator++(Direction& d);
struct Position {
    int row;
    int col;
    Position() : row(0), col(0) {}
    Position(int r, int c) : row(r), col(c) {}
    ~Position() {}
    Position operator+(Direction& rhs) {
        if (rhs == UP)
            return Position(row - 1, col);
        else if (rhs == DOWN)
            return Position(row + 1, col);
        else if (rhs == LEFT)
            return Position(row, col - 1);
        else if (rhs == RIGHT)
            return Position(row, col + 1);
        else
            return *this;
    }
    Position go(Direction dir) {
        return *this + dir;
    }
    Position up() {
        return Position(row - 1, col);
    }
    Position down() {
        return Position(row + 1, col);
    }
    Position left() {
        return Position(row, col - 1);
    }
    Position right() {
        return Position(row, col + 1);
    }
};
ostream& operator<<(ostream& os, const Position& rhs);

class Sokoban {
   private:
    bool static isBox(char c);
    bool static isPly(char c);
    char static addBox(char c);
    char static rmBox(char c);
    char static addPly(char c);
    char static rmPly(char c);

    struct State {
       private:
        char** matrix;
        Position ply;
        string moveSequence;

        bool moveBox(Position pos, Direction dir);

       public:
        State();
        State(const vector<string>& obj);
        State(const State& obj);
        ~State();
        void initialize();
        bool movePly(Direction dir);
        bool isdead() const;
        int getFilled() const;
        void setBlk(Position pos, char code);
        char getBlk(Position pos) const;
        char getBlk(int r, int c) const;
        bool solved() const;
        void print() const;
        string getMoveSequence() const;
        State& operator=(State const& rhs);
    };
    // friend Sokoban::State& Sokoban::State::operator=(Sokoban::State const& rhs);
    vector<string> input;
    State initState;

   public:
    Sokoban();
    ~Sokoban();
    void getInput(char* file_path);
    void test();
    void manual();
    void bfs();
};
