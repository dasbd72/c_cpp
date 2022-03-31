#include "hw1.hh"

#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <utility>
#include <vector>
using namespace std;
// g++ -std=c++17 -O3 -pthread -fopenmp -Wall -Wextra -fsanitize=address -g hw1.cc -o hw1; ./hw1 test.txt
// g++ -std=c++17 -O3 -pthread -fopenmp -Wall -Wextra -g hw1.cc -o hw1; ./hw1 test.txt

Direction& operator++(Direction& d) {
    switch (d) {
        case UP:
            d = RIGHT;
            break;
        case RIGHT:
            d = DOWN;
            break;
        case DOWN:
            d = LEFT;
            break;
        case LEFT:
            d = NONEDIR;
            break;
        default:
            d = NONEDIR;
            break;
    }
    return d;
}
// Sokoban, Private
bool Sokoban::isBox(char c) {
    return c == BOX || c == BOXT;
}
bool Sokoban::isPly(char c) {
    return c == PLY || c == PLYT || c == PLYF;
}
char Sokoban::addBox(char c) {
    if (c == EMPTY)
        return BOX;
    else if (c == TARGET)
        return BOXT;
    else
        return NONE;
}
char Sokoban::rmBox(char c) {
    if (c == BOX)
        return EMPTY;
    else if (c == BOXT)
        return TARGET;
    else
        return NONE;
}
char Sokoban::addPly(char c) {
    if (c == EMPTY)
        return PLY;
    else if (c == TARGET)
        return PLYT;
    else if (c == FRAGILE)
        return PLYF;
    else
        return NONE;
}
char Sokoban::rmPly(char c) {
    if (c == PLY)
        return EMPTY;
    else if (c == PLYT)
        return TARGET;
    else if (c == PLYF)
        return FRAGILE;
    else
        return NONE;
}

// Sokoban::State, Private
bool Sokoban::State::moveBox(Position pos, Direction dir) {
    if (addBox(getBlk(pos + dir))) {
        setBlk(pos, rmBox(getBlk(pos)));
        setBlk(pos + dir, addBox(getBlk(pos + dir)));
        return true;
    }
    return false;
}
// Sokoban::State, Public
Sokoban::State::State() {
    this->matrix = NULL;
}
Sokoban::State::State(const vector<string>& obj) {
    State();
    this->matrix = new char*[Rows];
    for (int r = 0; r < Rows; r++) {
        this->matrix[r] = new char[Cols];
        for (int c = 0; c < Cols; c++) {
            this->matrix[r][c] = obj[r][c];
        }
    }

    this->initialize();
}
Sokoban::State::State(const State& obj) {
    State();
    this->matrix = new char*[Rows];
    for (int r = 0; r < Rows; r++) {
        this->matrix[r] = new char[Cols];
        for (int c = 0; c < Cols; c++) {
            this->matrix[r][c] = obj.matrix[r][c];
        }
    }
    this->ply = obj.ply;
    this->moveSequence = obj.moveSequence;
}
Sokoban::State::~State() {
    if (this->matrix) {
        for (int r = 0; r < Rows; r++)
            delete[] this->matrix[r];
        delete[] this->matrix;
    }
}
void Sokoban::State::initialize() {
    for (int r = 0; r < Rows; r++) {
        for (int c = 0; c < Cols; c++) {
            if (this->getBlk(r, c) == PLY || this->getBlk(r, c) == PLYT || this->getBlk(r, c) == PLYF)
                ply = Position(r, c);
        }
    }
    return;
}
bool Sokoban::State::movePly(Direction dir) {
    bool res = false;
    // cout << "movePly, curPly pos : " << ply << "\n";
    switch (getBlk(ply + dir)) {
        case EMPTY:
        case TARGET:
        case FRAGILE:
            setBlk(ply, rmPly(getBlk(ply)));
            setBlk(ply + dir, addPly(getBlk(ply + dir)));
            res = true;
            break;
        case BOX:
        case BOXT:
            res = moveBox(ply + dir, dir);
            if (res) {
                setBlk(ply, rmPly(getBlk(ply)));
                setBlk(ply + dir, addPly(getBlk(ply + dir)));
            }
            break;
        case WALL:
        default:
            break;
    }
    if (res) {
        ply = ply + dir;
        moveSequence.push_back(dir);
    }
    return res;
}
bool Sokoban::State::isdead() const {
    Position pos;
    for (pos.row = 0; pos.row < Rows; pos.row++) {
        for (pos.col = 0; pos.col < Cols; pos.col++) {
            if (this->getBlk(pos) == BOX) {
                if (this->getBlk(pos.up()) == WALL || this->getBlk(pos.down()) == WALL) {
                    if (this->getBlk(pos.left()) == WALL || this->getBlk(pos.right()) == WALL)
                        return true;
                }
            }
        }
    }
    return false;
}
int Sokoban::State::getFilled() const {
    int res = 0;
    for (int r = 0; r < Rows; r++) {
        for (int c = 0; c < Cols; c++) {
            if (getBlk(r, c) == BOXT)
                res++;
        }
    }
    return res;
}
void Sokoban::State::setBlk(Position pos, char code) {
    // cout << "setBlk : [" << this->matrix[pos.row][pos.col] << "] to [" << code << "]\n";
    this->matrix[pos.row][pos.col] = code;
}
char Sokoban::State::getBlk(Position pos) const {
    // cout << "getBlk : [" << this->matrix[pos.row][pos.col] << "]\n";
    return this->matrix[pos.row][pos.col];
}
char Sokoban::State::getBlk(int r, int c) const {
    return this->matrix[r][c];
}
bool Sokoban::State::solved() const {
    return this->getFilled() == Targets;
}
void Sokoban::State::print() const {
    cout << "ply : " << ply << "\n";
    cout << moveSequence << "\n";
    cout << "solved : " << (this->solved() ? "true" : "false") << "\n";
    for (int r = 0; r < Rows; r++) {
        for (int c = 0; c < Cols; c++)
            cout << this->matrix[r][c];
        cout << "\n";
    }
}
string Sokoban::State::getMoveSequence() const {
    return moveSequence;
}
Sokoban::State& Sokoban::State::operator=(State const& rhs) {
    if (this->matrix != NULL) {
        for (int r = 0; r < Rows; r++)
            delete[] this->matrix[r];
        delete[] this->matrix;
    }
    this->matrix = new char*[Rows];
    for (int r = 0; r < Rows; r++) {
        this->matrix[r] = new char[Cols];
        for (int c = 0; c < Cols; c++) {
            this->matrix[r][c] = rhs.matrix[r][c];
        }
    }
    this->ply = rhs.ply;
    this->moveSequence = rhs.moveSequence;
    return *this;
}

// Sokoban, Private
Sokoban::Sokoban() {}
Sokoban::~Sokoban() {}
void Sokoban::getInput(char* file_path) {
    ifstream input_file;
    string input_line;

    input_file.open(file_path);
    if (!input_file)
        cerr << "No file found.\n";

    while (getline(input_file, input_line))
        input.emplace_back(input_line);

    Rows = input.size();
    Cols = input[0].size();

    Targets = 0;
    for (int r = 0; r < Rows; r++)
        for (int c = 0; c < Cols; c++)
            if (input[r][c] == TARGET || input[r][c] == BOXT || input[r][c] == PLYT)
                Targets++;

    initState = State(input);
    return;
}
void Sokoban::test() {
    initState.print();
    State s(initState);
    s = initState;
    s.print();
    s.movePly(UP);
    s.print();
}
void Sokoban::manual() {
    initState.print();
    string inp;
    while (cin >> inp) {
        initState.movePly(Direction(inp[0]));
        initState.print();
    }
}
void Sokoban::bfs() {
    queue<State> states;
    states.emplace(initState);

    while (!states.empty()) {
        State curState = states.front();
        states.pop();
        cout << curState.getMoveSequence() << "\n";
        for (Direction dir = UP; dir != NONEDIR; ++dir) {
            cout << dir << "\n";
            State nxtState = curState;
            if (nxtState.movePly(dir)) {
                if (nxtState.solved()) {
                    cout << nxtState.getMoveSequence() << "\n";
                    return;
                } else {
                    states.emplace(nxtState);
                }
            }
        }
    }
    cout << "DONE\n";
}

ostream& operator<<(ostream& os, const Position& rhs) {
    os << "(" << rhs.row << " , " << rhs.col << ")";
    return os;
}

int main(int argc, char* argv[]) {
    Sokoban sokoban;
    sokoban.getInput(argv[1]);
    sokoban.bfs();
    return 0;
}