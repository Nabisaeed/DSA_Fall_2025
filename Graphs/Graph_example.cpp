#include <iostream>
#include <vector>
#include <string>
using namespace std;


struct City {
    string name;
    int population; 
};

int main() {
    int n = 5; 

    
    vector<City> cities(n);

    
    cities[0] = {"Karachi", 15000000};
    cities[1] = {"Lahore", 11000000};
    cities[2] = {"Islamabad", 2000000};
    cities[3] = {"Multan", 2000000};
    cities[4] = {"Peshawar", 1800000};

    
    vector<vector<int>> graph(n);

  
    graph[0] = {1, 2};      
    graph[1] = {0, 3};      
    graph[2] = {0, 4};      
    graph[3] = {1, 4};      
    graph[4] = {2, 3};      

    
    for (int i = 0; i < n; i++) {
        cout << cities[i].name << " (" << cities[i].population << ") connected to: ";
        for (int neighbor : graph[i]) {
            cout << cities[neighbor].name << ", ";
        }
        cout << endl;
    }

    return 0;
}
