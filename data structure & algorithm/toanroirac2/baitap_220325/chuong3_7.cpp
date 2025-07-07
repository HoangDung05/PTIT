#include <bits/stdc++.h> 
using namespace std;
vector<int> adj[105];
int in[105], low[105];
bool visited[105];
vector<pair<int, int>> canhcau;
int timer, n, m;
void dfs(int u, int parent){
	visited[u] = 1;
	in[u] = low[u] = ++timer;
	for(int v : adj[u]){
		if(v == parent) continue;
		if(visited[v]){
			low[u] = min(low[u], in[v]);	
		}
		else{
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if(low[v] > in[u]){
				canhcau.push_back(make_pair(min(u, v), max(u, v)));
			}
		}
	}
}
int main () {
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	memset(visited, 0, sizeof(visited));
	timer = 0;
	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			dfs(i, - 1);
		}
	}
	sort(canhcau.begin(), canhcau.end());
	cout << canhcau.size() << endl;
	for(size_t i = 0; i < canhcau.size(); i++){
		cout << canhcau[i].first << " " << canhcau[i].second << endl;
	}
}
