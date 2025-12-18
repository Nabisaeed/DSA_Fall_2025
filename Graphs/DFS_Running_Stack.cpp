#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void DFS(vector<vector<int>>& graph, int startVertex) {
    int n = graph.size();  

    vector<bool> visited(n, false);  
    stack<int> s;

    s.push(startVertex);

    while (!s.empty()) {
      
        int currentVertex = s.top();
        s.pop();


        if (!visited[currentVertex]) {
            visited[currentVertex] = true;
            cout << "Visited: " << currentVertex << endl; 

            
            for (int neighbor : graph[currentVertex]) {
                if (!visited[neighbor]) {
                    s.push(neighbor);
                }
            }
        }
    }
}

int main() {
   
    vector<vector<int>> graph = {
        {1, 2},        
        {0, 3, 4},     
        {0, 5},        
        {1},           
        {1},           
        {2}            
    };
    int startVertex = 0;

    cout << "DFS Traversal starting from vertex " << startVertex << ":\n";
    DFS(graph, startVertex);

    return 0;
}
