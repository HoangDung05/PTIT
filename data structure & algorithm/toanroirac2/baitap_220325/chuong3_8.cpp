#include <bits/stdc++.h> 
using namespace std;
const int maxn = 105;
vector<int> adj[maxn];
bool visited[maxn];
void dfs(int u, int ignore){
	if(u == ignore) return;
	visited[u] = true;
	for(int v : adj[u]){
		if(!visited[v]){
			dfs(v, ignore);
		}
	}
}
int main () {
	int n, m, u, v;
	cin >> n >> m >> u >> v;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	vector<int> dinhthat;
	for(int i = 1; i <= n; i++){
		if(i == u || i == v){
			continue;
		}
		memset(visited, 0, sizeof(visited));
		dfs(u, i);
		if(!visited[v]){
			dinhthat.push_back(i);
		}
	}
	cout << dinhthat.size() << endl;
	for(int x : dinhthat){
		cout << x << " ";
	}
	return 0;
}
