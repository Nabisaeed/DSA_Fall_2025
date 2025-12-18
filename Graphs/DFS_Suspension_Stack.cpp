#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>> graph, vector<bool> visited) { 
    visited[node] = true;
    cout << node << " ";
    for (int neighbor : graph[node]) {
        if (visited[neighbor]==false) {
            dfs(neighbor, graph, visited);
        }
    }
}
int main() {
    int n = 5; 
    vector<vector<int>> graph(n);

    graph[0] = {1, 2};
    graph[1] = {0, 3};
    graph[2] = {0, 4};
    graph[3] = {1};
    graph[4] = {2};
    vector<bool> visited(n, false); 
    cout << "DFS starting from node 0: ";
    dfs(0, graph, visited);
    return 0;
}
