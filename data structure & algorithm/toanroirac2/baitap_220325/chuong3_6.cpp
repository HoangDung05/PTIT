#include <bits/stdc++.h> 
using namespace std;
vector<int> adj[105];
bool visited[105];
int in[105], low[105];
set<int> dinhtru;
int timer, n;
void dfs(int u, int parent){
	visited[u] = 1;
	in[u] = low[u] = ++timer;
	int children = 0;
	for(int v : adj[u]){
		if(v == parent) continue;
		if(visited[v]){
			low[u] = min(low[u], in[v]);
		}
		else{
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if(low[v] >= in[u] && parent != -1){
				dinhtru.insert(u);
			}
			++children;
		}
	}
	if(parent == - 1 && children > 1){
		dinhtru.insert(u);
	}
}
int main () {
	cin >> n;
	for(int i = 1; i <= n; i++){
		int k, v;
		cin >> k;
		while(k--){
			cin >> v;
			adj[i].push_back(v);
			adj[v].push_back(i);
		}
	}
	memset(visited, 0, sizeof(visited));
	timer = 0;
	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			dfs(i, - 1);
		}
	}
	cout << dinhtru.size() << endl;
	for(int v : dinhtru){
		cout << v << ' ';
	}
}
