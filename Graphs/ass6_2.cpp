#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;
void add_connection(vector<vector<int>> &vec, int x, int y) {
	vec[x].push_back(y);
	vec[y].push_back(x);
}
int bfs(vector<vector<int>> vec, int source, int end_node) {
	queue<int> q;		
	vector<bool> visited(vec.size(), false);
	vector<int> dist(vec.size(), -1);
	
	visited[source] = true;
	dist[source] = 1;
	q.push(source);
	
	while (!q.empty()) {
		int node_index = q.front();
		q.pop();
		for(unsigned long connected_node = 0; connected_node < vec[node_index].size(); connected_node++) {			
			int v = vec[node_index][connected_node];						
			if (v == end_node) { return dist[node_index] ;}
			if (!visited[v]) {
				visited[v] = true;						
				q.push(v);
				dist[v] = dist[node_index] + 1;
			}					
		}
	}
	return -1;
}

int main(){
    int t,n,m;
    
    cin >> t ;
    for(int i=0; i<t; i++)
    {
		cin >> n >> m;
		vector<vector<int>> connections(n+1);
		for (int i=0; i<m; i++) { 
			int x, y;
			cin >> x >> y;
			add_connection(connections, x, y);
		}
		cout << bfs(connections, 1, n) << endl;	
    }
    return 0;
}
