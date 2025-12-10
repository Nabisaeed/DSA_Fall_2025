#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 4;

    // adjacency list representation
    vector<vector<int>> graph(n);

    // Adding edges (same edges as adjacency matrix)
    graph[0] = {1, 2};       // 0 connected to 1 and 2
    graph[1] = {0, 3};       // 1 connected to 0 and 3
    graph[2] = {0, 3};       // 2 connected to 0 and 3
    graph[3] = {1, 2};       // 3 connected to 1 and 2

    // Print adjacency list
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << ": ";
        for (int neighbor : graph[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }

    return 0;
}
