#include <bits/stdc++.h>
#define MIN -0x7FFFFFFF
#define MAX 0x7FFFFFFF
const int SIZE = 8;
using State = std::array<std::array<int, SIZE>, SIZE>;
struct Point {
   public:
    // Operators
    bool operator==(const Point& rhs) const {
        return x == rhs.x && y == rhs.y;
    }
    bool operator!=(const Point& rhs) const {
        return !operator==(rhs);
    }
    bool operator<(const Point& rhs) const {
        return x < rhs.x || (x == rhs.x && y < rhs.y);
    }
    bool operator>(const Point& rhs) const {
        return operator!=(rhs) && !operator<(rhs);
    }
    Point operator+(const Point& rhs) const {
        return Point(x + rhs.x, y + rhs.y);
    }
    Point operator-(const Point& rhs) const {
        return Point(x - rhs.x, y - rhs.y);
    }
    Point& operator=(const Point& rhs) {
        x = rhs.x, y = rhs.y;
        return (*this);
    }
    friend std::ostream& operator<<(std::ostream&, const Point&);

    int x, y;
    Point() : Point(0, 0) {}
    Point(int x, int y) : x(x), y(y) {}
    Point(const Point& pt) : x(pt.x), y(pt.y) {}
};

/**
 * @brief Board class. Stores: board, curPlayer, value
 */
class Board {
   public:
    // Operators
    friend class Engine;
    friend std::ostream& operator<<(std::ostream&, const Board&);
    bool operator==(const Board& rhs) const {
        return this->board == rhs.board;
    }
    bool operator!=(const Board& rhs) const {
        return !operator==(rhs);
    }
    bool operator<(const Board& rhs) const {
        return 64 - this->get_cnt_discs(0) < 64 - rhs.get_cnt_discs(0);
    }
    bool operator>(const Board& rhs) const {
        return 64 - this->get_cnt_discs(0) > 64 - rhs.get_cnt_discs(0);
    }
    Board& operator=(const Board& rhs) {  // REMEMBER change when add new variables
        this->board = rhs.board;
        this->discsCnt = rhs.discsCnt;
        return *this;
    }
    const constexpr std::array<int, SIZE> operator[](int idx) const {
        return this->board[idx];
    }
    const std::array<Point, 8> directions{{Point(-1, -1), Point(-1, 0), Point(-1, 1),
                                           Point(0, -1), /*{0, 0}, */ Point(0, 1),
                                           Point(1, -1), Point(1, 0), Point(1, 1)}};
    enum SPOT_STATE {
        EMPTY = 0,
        BLACK = 1,
        WHITE = 2
    };

    State board;

   private:
    std::array<int, 3> discsCnt;

   public:
    Board() {
        discsCnt = {0, 0, 0};
    }
    Board(const Board& other) {
        Board();
        operator=(other);
    }
    ~Board() = default;
    void initialize() {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                discsCnt[board[i][j]]++;
            }
        }
    }

    int get_next_player(int player) const {
        return 3 - player;
    }
    bool is_spot_on_board(Point p) const {
        return 0 <= p.x && p.x < SIZE && 0 <= p.y && p.y < SIZE;
    }
    int get_disc(Point p) const {
        return board[p.x][p.y];
    }
    void set_disc(Point p, int disc) {
        discsCnt[get_disc(p)]--;
        discsCnt[disc]++;
        board[p.x][p.y] = disc;
    }
    void flip_discs(Point center) {
        int player = get_disc(center);
        for (Point dir : directions) {
            Point p = center + dir;
            if (!is_disc_at(p, get_next_player(player)))
                continue;
            std::vector<Point> discs({p});
            p = p + dir;
            while (is_spot_on_board(p) && get_disc(p) != EMPTY) {
                if (is_disc_at(p, player)) {
                    for (Point s : discs) {
                        set_disc(s, player);
                    }
                    break;
                }
                discs.push_back(p);
                p = p + dir;
            }
        }
    }
    void set_move(Point p, int player) {
        set_disc(p, player);
        flip_discs(p);
    }
    bool is_disc_at(Point p, int disc) const {
        if (!is_spot_on_board(p))
            return false;
        if (get_disc(p) != disc)
            return false;
        return true;
    }
    bool is_spot_valid(Point center, int player) const {
        if (get_disc(center) != EMPTY)
            return false;
        for (Point dir : directions) {
            // Move along the direction while testing.
            Point p = center + dir;
            if (!is_disc_at(p, get_next_player(player)))
                continue;
            p = p + dir;
            while (is_spot_on_board(p) && get_disc(p) != EMPTY) {
                if (is_disc_at(p, player))
                    return true;
                p = p + dir;
            }
        }
        return false;
    }
    std::set<Point> get_valid_spots(int player) const {
        std::set<Point> valid_spots;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                Point p = Point(i, j);
                if (board[i][j] != EMPTY)
                    continue;
                if (is_spot_valid(p, player))
                    valid_spots.insert(p);
            }
        }
        return valid_spots;
    }
    bool is_terminal() const {
        if (this->discsCnt[0] == 0) return true;
        int toCheck = discsCnt[0];
        for (int i = 0; i < SIZE && toCheck; i++) {
            for (int j = 0; j < SIZE && toCheck; j++) {
                if (board[i][j] != EMPTY)
                    continue;
                toCheck--;
                Point curPt = Point(i, j);
                for (auto dir : directions) {
                    Point p = curPt + dir;
                    int firstPly = get_disc(p);
                    while (is_spot_on_board(p) && get_disc(p) != EMPTY) {
                        if (get_disc(p) != firstPly) return false;
                        p = p + dir;
                    }
                }
            }
        }
        return true;
    }
    int get_cnt_discs(int i) const {
        return discsCnt[i];
    }
};

std::ostream& operator<<(std::ostream& os, const Point& rhs) {
    os << "(" << rhs.x << "," << rhs.y << ")";
    return os;
}
std::ostream& operator<<(std::ostream& os, const Board& rhs) {
    os << "+---------------+\n";
    for (int i = 0; i < SIZE; i++) {
        os << "|";
        for (int j = 0; j < SIZE; j++) {
            switch (rhs[i][j]) {
                case 1:
                    os << "1";
                    break;
                case 2:
                    os << "2";
                    break;
                default:
                    os << " ";
                    break;
            }
            if (j != SIZE - 1) os << " ";
        }
        os << "|\n";
    }
    os << "+---------------+\n";
    return os;
}

class AIMethod {
   protected:
    int curPlayer;
    Board curBoard;
    std::set<Point> nxtSpots;

   public:
    AIMethod() {
        this->curPlayer = 2;
        this->curBoard.board = {{{0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 2, 1, 0, 0, 0, 0},
                                 {0, 0, 0, 2, 1, 0, 0, 0},
                                 {0, 0, 0, 1, 1, 0, 0, 0},
                                 {0, 0, 0, 0, 1, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0}}};
        this->curBoard.initialize();
        std::cout << curBoard;
    }
    virtual ~AIMethod() {}
    virtual void solve() = 0;

   private:
    enum TYPE_ID {
        ID_CORNER,
        ID_CENTER,
        ID_EDGE_A,
        ID_EDGE_B,
        ID_CORN_X,
        ID_CORN_C,
        ID_EDGE_0,
        ID_EDGE_1
    };
    const State BOARD_ID = {{
        {ID_CORNER, ID_CORN_C, ID_EDGE_B, ID_EDGE_A, ID_EDGE_A, ID_EDGE_B, ID_CORN_C, ID_CORNER},
        {ID_CORN_C, ID_CORN_X, ID_EDGE_1, ID_EDGE_0, ID_EDGE_0, ID_EDGE_1, ID_CORN_X, ID_CORN_C},
        {ID_EDGE_B, ID_EDGE_1, ID_CENTER, ID_CENTER, ID_CENTER, ID_CENTER, ID_EDGE_1, ID_EDGE_B},
        {ID_EDGE_A, ID_EDGE_0, ID_CENTER, ID_CENTER, ID_CENTER, ID_CENTER, ID_EDGE_0, ID_EDGE_A},
        {ID_EDGE_A, ID_EDGE_0, ID_CENTER, ID_CENTER, ID_CENTER, ID_CENTER, ID_EDGE_0, ID_EDGE_A},
        {ID_EDGE_B, ID_EDGE_1, ID_CENTER, ID_CENTER, ID_CENTER, ID_CENTER, ID_EDGE_1, ID_EDGE_B},
        {ID_CORN_C, ID_CORN_X, ID_EDGE_1, ID_EDGE_0, ID_EDGE_0, ID_EDGE_1, ID_CORN_X, ID_CORN_C},
        {ID_CORNER, ID_CORN_C, ID_EDGE_B, ID_EDGE_A, ID_EDGE_A, ID_EDGE_B, ID_CORN_C, ID_CORNER},
    }};
    const State WEIGHT_MID = {{
        {1000, -300, 500, 100, 100, 500, -300, 1000},
        {-300, -500, 0, 0, 0, 0, -500, -300},
        {500, 0, 0, 0, 0, 0, 0, 500},
        {100, 0, 0, 100, 100, 0, 0, 100},
        {100, 0, 0, 100, 100, 0, 0, 100},
        {500, 0, 0, 0, 0, 0, 0, 500},
        {-300, -500, 0, 0, 0, 0, -500, -300},
        {1000, -300, 500, 100, 100, 500, -300, 1000},
    }};
    int get_id(Point p) const {
        return BOARD_ID[p.x][p.y];
    }

   protected:
    int sum(int a, int b) const {
        if (a < 0 && b < 0 && a + b > 0) return MIN;
        if (a > 0 && b > 0 && a + b < 0) return MAX;
        return a + b;
    }
    int get_stage(Board& board, int player) const {
        std::vector<int> row = {0, 1, 6, 7};
        int stage = 1;
        for (auto i : row) {
            for (int j = 0; j < SIZE && stage == 1; j++) {
                if (board[i][j] == player && (BOARD_ID[i][j] != ID_CENTER || BOARD_ID[i][j] != ID_EDGE_1)) stage = 2;
            }
            if (stage != 1) break;
        }
        return stage;
    }
    int evaluate(Board& board, int player) const {  //-1000 ~ 1000
        int val = 0;
        int stage = get_stage(board, player);
        if (stage == 1) {
            val += get_mobility(board, player);
        } else {
            val += get_value(board, player);
        }
        return val;
    }
    int get_mobility(Board& board, int player) const {  // -100 ~ 100
        int cnt = board.get_valid_spots(player).size() - 3;
        return cnt < 0 ? cnt * 120 : cnt * 100;
    }
    int get_value(Board& board, int player) const {  // -100 ~ 100
        int val = 0;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] == player)
                    val += WEIGHT_MID[i][j];
                else if (board[i][j] == 3 - player)
                    val -= WEIGHT_MID[i][j];
            }
        }
        return val;
    }
};
class AIAlphaBetaPruning : public AIMethod {
   public:
    AIAlphaBetaPruning() {
    }
    void solve() override {
        MAXDEPTH = 1;
        // if (this->curBoard.get_cnt_discs(0) <= 11)
        //     MAXDEPTH = 11;
        // else
        //     MAXDEPTH = 9;
        this->getAlphaBetaVal(this->curBoard, 0, MIN, MAX, this->curPlayer);
    }

   private:
    int MAXDEPTH;

    int getAlphaBetaVal(Board curBoard, int depth, int alpha, int beta, int player) const {
        int retVal = 0;
        if (curBoard.is_terminal()) {
            int a = curBoard.get_cnt_discs(player);
            int b = curBoard.get_cnt_discs(3 - player);
            if (a > b)
                retVal = MAX;
            else if (a < b)
                retVal = MIN;
            else if (a == b)
                retVal = 0;
        } else if (depth >= MAXDEPTH) {
            retVal = evaluate(curBoard, player);
        } else {
            std::set<Point> nxtSpots;
            Board nxtBoard;
            int maxVal, nxtVal;

            maxVal = MIN;
            nxtSpots = (curBoard.get_valid_spots(player));

            for (auto spot : nxtSpots) {
                nxtBoard = curBoard;
                nxtBoard.set_move(spot, player);
                nxtVal = -this->getAlphaBetaVal(nxtBoard, depth + 1, -beta, -alpha, 3 - player);
                if (nxtVal > maxVal) {
                    if (depth == 0) {
                        std::cout << spot << "\n";
                        std::cout << "Value of " << player << "-" << 3 - player << " " << spot << " is " << nxtVal << "\n";
                    }
                    maxVal = nxtVal;
                }
                alpha = std::max(alpha, maxVal);
                if (beta <= alpha) break;
            }
            retVal = maxVal;
        }
        return retVal;
    }
};

int main() {
    Board bd, nxtbd;
    State test = {{{0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 2, 1, 0, 0, 0, 0},
                   {0, 0, 0, 2, 1, 0, 0, 0},
                   {0, 0, 0, 1, 1, 0, 0, 0},
                   {0, 0, 0, 0, 1, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0}}};
    AIMethod* aiMethod = new AIAlphaBetaPruning();
    try {
        aiMethod->solve();
    } catch (const std::exception& e) {
        std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!" << e.what() << '\n';
    }
    delete aiMethod;
    std::cout << "end\n";
}
/*
{1, 1, 1, 1, 1, 1, 1, 1},
{0 , 1, 1, 1, 1, 2, 2, 1},
{1, 2, 1, 2, 1, 2, 2, 1},
{1, 2, 2, 1, 1, 2, 1, 1},
{1, 2, 1, 2, 1, 2, 1, 1},
{1, 2, 2, 2, 2, 1, 1, 1},
{1, 2, 2, 2, 2, 2, 2, 1},
{1, 2, 1, 1, 1, 1, 1, 1},
*/
/*
Current Player: X
Current Board:
+---------------+
|               |
|               |
|    X O        |
|      X O      |
|      O O      |
|        O      |
|               |
|               |
+---------------+
*/