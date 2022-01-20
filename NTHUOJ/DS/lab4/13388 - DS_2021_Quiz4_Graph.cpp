#include <iomanip>
#include <iostream>
#include <list>
#include <queue>
#include <utility>
#define MAXN 505
using namespace std;

typedef pair<int, double> pairID;
typedef pair<double, int> pairDI;

class Graph {
   private:
    list<pairID> *edge;

   public:
    Graph();
    ~Graph();
    void addEdge(int u, int v, double p);
    double maxPossibility(int src, int dst);
};
int main() {
    int N, M, R, a, b, S, E;
    double p;
    Graph myGraph;
    cin >> N >> M >> R;
    while (M--) {
        cin >> a >> b >> p;
        myGraph.addEdge(a, b, p);
    }
    while (R--) {
        cin >> S >> E;
        cout << fixed << setprecision(5) << myGraph.maxPossibility(S, E) << "\n";
    }
    return 0;
}

Graph::Graph() {
    edge = new list<pairID>[MAXN];
}
Graph::~Graph() {
    delete[] edge;
}
void Graph::addEdge(int u, int v, double p) {
    this->edge[u].push_back(make_pair(v, p));
    this->edge[v].push_back(make_pair(u, p));
}
double Graph::maxPossibility(int src, int dst) {
    priority_queue<pairDI, vector<pairDI>, greater<pairDI>> pq;
    vector<double> possibility(MAXN, double(0));
    pq.push(make_pair(double(0), src));
    possibility[src] = 1;
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for (list<pairID>::iterator it = edge[u].begin(); it != edge[u].end(); ++it) {
            int v = (*it).first;
            double weight = (*it).second;
            if (possibility[v] < possibility[u] * weight) {
                possibility[v] = possibility[u] * weight;
                pq.push(make_pair(possibility[v], v));
            }
        }
    }
    return possibility[dst];
}