#include<iostream>
#include<vector>
using namespace std;

void dfs(vector<vector<char>>& maze, vector<vector<bool>>& visited, int i, int j, int n, int m)
{
    if (i < 0 || i >= n || j < 0 || j >= m || maze[i][j] != '#' || visited[i][j])
        return;
    visited[i][j] = true;
    dfs(maze, visited, i + 1, j, n, m);
    dfs(maze, visited, i - 1, j, n, m);
    dfs(maze, visited, i, j + 1, n, m);
    dfs(maze, visited, i, j - 1, n, m);
}

int countObstacles(vector<vector<char>>& maze, int n, int m)
{
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (maze[i][j] == '#' && !visited[i][j])
            {
                count++;
                dfs(maze, visited, i, j, n, m);
            }  
        }
    }
    return count;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> maze(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> maze[i][j];
        }
    }
    cout << countObstacles(maze, n, m);

}