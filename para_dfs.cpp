#include <iostream>
#include <vector>
#include <stack>
#include <omp.h>

using namespace std;

const int MAX = 100000;
vector<int> graph[MAX];
bool visited[MAX];

void dfs(int node) {
	stack<int> s;
	s.push(node);

	while (!s.empty()) {
    	int curr_node = s.top();
    	s.pop();

    	if (!visited[curr_node]) {
        	visited[curr_node] = true;
        	
        	if (visited[curr_node]) {
        	cout << curr_node << " ";
    	}

        	#pragma omp parallel for
        	for (int i = 0; i < graph[curr_node].size(); i++) {
            	int adj_node = graph[curr_node][i];
            	if (!visited[adj_node]) {
                	s.push(adj_node);
            	}
        	}
    	}
	}
}

int main() {
	int n, m, start_node;
         //n: node,m:edges
         cout<<" Enter Number of Nodes:";
		cin>>n;
	    cout<<"Enter number of Edges:";
		cin>>m;

cout << "Enter Pair of edges:" ;
	for (int i = 0; i < m; i++) {
    	int u, v;
    		
    	cin >> u >> v;
//u and v: Pair of edges
    	graph[u].push_back(v);
    	graph[v].push_back(u);
	}


	#pragma omp parallel for
	for (int i = 0; i < n; i++) {
    	visited[i] = false;
	}
 	cout<<"Enter the starting node:";
   cin>>start_node;
	dfs(start_node);

/*	for (int i = 0; i < n; i++) {
    	if (visited[i]) {
        	cout << i << " ";
    	}
	}*/

	return 0;
}


/*
OUTPUT
unix@unix-HP-280-G1-MT:~/codes$ g++ para_dfs.cpp
unix@unix-HP-280-G1-MT:~/codes$ ./a.out
 Enter Number of Nodes:5
Enter number of Edges:6
Enter Pair of edges:0 1 
0 2
0 3
1 4
3 4
2 3
Enter the starting node:3
3 2 0 1 4 
*/



