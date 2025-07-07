#include <bits/stdc++.h> 
using namespace std;
vector<int> adj[105];
int in[105], low[105];
bool visited[105];
vector<pair<int, int>> edges, directed_edges;
int timer, n, m;
void dfs(int u, int parent, bool &taocau){
	visited[u] = true;
	in[u] = low[u] = ++timer;
	for(int v : adj[u]){
		if(v == parent) continue;
		if(visited[v]){
			low[u] = min(low[u], in[v]);
		}
		else{
			dfs(v, u, taocau);
			low[u] = min(low[u], low[v]);
			if(low[v] > in[u]){
				taocau = 1;
			}
		}
	}
}
bool ketnoi(){
	memset(visited, 0, sizeof(visited));
	queue<int> q;
	q.push(1);
	visited[1] = 1;
	int count = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		count++;
		for(int v : adj[u]){
			if(!visited[v]){
				visited[v] = 1;
				q.push(v);
			}
		}
	}
	return count == n;
}
void dinhchieu(int u){
	visited[u] = 1;
	for(int v : adj[u]){
		if(!visited[v]){
			directed_edges.push_back({u, v});
			dinhchieu(v);
		}
		else if(find(directed_edges.begin(), directed_edges.end(), make_pair(v, u)) == directed_edges.end()){
			directed_edges.push_back({u, v});
		}
	}
}
int main () {
	int t;
	cin >> t >> n >> m;
	for(int i = 0; i< m; i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		edges.push_back({u, v});
	}
	if(!ketnoi()){
		cout << 0 << endl;
		return 0;
	}
	timer = 0;
	memset(visited, 0, sizeof(visited));
	bool taocau = 0;
	dfs(1, -1, taocau);
	if(taocau){
		cout << 0 << endl;
		return 0;
	}
	else if(t == 1){
		cout << 1 << endl;
	}
	else{
		memset(visited, 0,sizeof(visited));
		dinhchieu(1);
		cout << n << " " << m << endl;
		sort(directed_edges.begin(), directed_edges.end());
		for(auto &e : directed_edges){
			cout << e.first << " " << e.second << endl;
		}
	}
	return 0;
}
