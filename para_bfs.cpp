#include <iostream>
#include <vector>
#include <queue>
#include <omp.h>

using namespace std;

const int MAX = 100000;
vector<int> graph[MAX];
bool visited[MAX];

void bfs(int start_node) {
    queue<int> q;
    q.push(start_node);
    visited[start_node] = true;
    
    while (!q.empty()) {
        int curr_node = q.front();
        q.pop();
        cout << curr_node << " ";
        
        #pragma omp parallel for
        for (int i = 0; i < graph[curr_node].size(); i++) {
            int adj_node = graph[curr_node][i];
            if (!visited[adj_node]) {
                visited[adj_node] = true;
                q.push(adj_node);
            }
        }
    }
}

int main() {
    int n, m, start_node;
    // n: nodes, m: edges
    cout << "Enter number of Nodes: ";
    cin >> n;
    cout << "Enter number of Edges: ";
    cin >> m;

    cout << "Enter pairs of edges: ";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        // u and v: Pair of edges
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    
    cout << "Enter the starting node: ";
    cin >> start_node;
    
    bfs(start_node);

    /*for (int i = 0; i < n; i++) {
        if (visited[i]) {
            cout << i << " ";
        }
    }*/

    return 0;
}

/*
OUTPUT
unix@unix-HP-280-G1-MT:~/codes$ g++ -fopenmp para_bfs.cpp -o para_bfs
unix@unix-HP-280-G1-MT:~/codes$ ./para_bfs
Enter number of Nodes: 5
Enter number of Edges: 6
Enter pairs of edges: 5 1
5 3
5 2
3 4
1 4
2 3
Enter the starting node: 5
5 1 2 3 4 unix@unix-HP-280-G1-MT:~/codes$ 

*/

