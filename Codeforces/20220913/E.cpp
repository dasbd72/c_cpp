// #include <bits/stdc++.h>
// using namespace std;

// struct Node{
//     int label;
//     std::vector<Node*> parent;
//     std::vector<Node*> children;
// };
// int cur_label = 1;
// void dfs(Node* node){
//     if(node->label)
//         return;
//     node->label = cur_label++;
//     for(auto n : node->children) {
//         dfs(n);
//     }
// }
// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);

//     int n, m;
//     Node* nodes[100005];

//     std::cin >> n >> m;
    
//     for(int i = 1; i <= n; i++) {
//         nodes[i] = new Node;
//         nodes[i]->label = 0;
//     }
//     for(int i = 0; i < m; i++) {
//         int v, u;
//         std::cin >> v >> u;
//         nodes[v]->children.push_back(nodes[u]);
//         nodes[u]->parent.push_back(nodes[v]);
//     }

//     for(int i = 1; i <= n; i++) {
//         if(nodes[i]->label) continue;
//         if(nodes[i]->parent.size() == 0)
//             dfs(nodes[i]);
//     }

//     for(int i = 1; i <= n; i++) {
//         std::cout << nodes[i]->label << " ";
//     }

//     return 0;
// }
// // g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -O2 E.cpp ; ./a.out <c.in
// // g++ -std=c++17 -Wall -Wextra -g -O2 E.cpp ; ./a.exe