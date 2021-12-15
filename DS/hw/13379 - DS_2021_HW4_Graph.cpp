#include <bits/stdc++.h>
using namespace std;
#define MAXN 20005
typedef pair<int, int> pairII;

class Graph {
   private:
    list<pairII> *tunnel;
    list<pairII> *bridge;

   public:
    Graph();
    ~Graph();
    void addTunnel(int u, int v, int w);
    void addBridge(int u, int v, int w);
    int shortestPath(int src, int dst);
};

int main() {
    int N, S, E, T, B;
    Graph myGraph;
    cin >> N >> S >> E;
    cin >> T;
    for (int t = 0, u, v, w; t < T; t++) {
        cin >> u >> v >> w;
        myGraph.addTunnel(u, v, w);
    }
    cin >> B;
    for (int b = 0, u, v, w; b < B; b++) {
        cin >> u >> v >> w;
        myGraph.addBridge(u, v, w);
    }
    cout << myGraph.shortestPath(S, E) << '\n';
    return 0;
}

Graph::Graph() {
    this->tunnel = new list<pairII>[MAXN];
    this->bridge = new list<pairII>[MAXN];
}
Graph::~Graph() {
    delete[] this->tunnel;
    delete[] this->bridge;
}
void Graph::addTunnel(int u, int v, int w) {
    this->tunnel[u].push_back(make_pair(v, w));
    this->tunnel[v].push_back(make_pair(u, w));
}
void Graph::addBridge(int u, int v, int w) {
    this->bridge[u].push_back(make_pair(v, w));
    this->bridge[v].push_back(make_pair(u, w));
}
int Graph::shortestPath(int src, int dst) {
    priority_queue<pairII, vector<pairII>, greater<pairII>> pq;
    vector<int> dist(MAXN, INT_MAX);
    vector<int> dist_b(MAXN, INT_MAX);
    vector<bool> usedBridge(MAXN, false);
    pq.push(make_pair(0, src));
    dist[src] = 0;
    dist_b[src] = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for (list<pairII>::iterator it = tunnel[u].begin(); it != tunnel[u].end(); ++it) {
            int v = (*it).first;
            int weight = (*it).second;
            if (dist[u] != INT_MAX && dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
            if (dist_b[u] != INT_MAX && dist_b[v] > dist_b[u] + weight) {
                dist_b[v] = dist_b[u] + weight;
                pq.push(make_pair(dist_b[v], v));
            }
        }
        for (list<pairII>::iterator it = bridge[u].begin(); it != bridge[u].end(); ++it) {
            int v = (*it).first;
            int weight = (*it).second;
            if (dist[u] != INT_MAX && dist_b[v] > dist[u] + weight) {
                dist_b[v] = dist[u] + weight;
                pq.push(make_pair(dist_b[v], v));
            }
        }
    }
    return min(dist[dst], dist_b[dst]);
}