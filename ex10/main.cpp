#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited(false);

void dfs(int start)
{
    visited[start] = true;

    cout << start << " ";
    
    for(int i : graph[start])
    {
        if(visited[i] != true)
        {
            dfs(i);
        }
    }
}

void bfs(int start)
{
    queue<int> q;
    visited[start] = true;
    int i;

    q.push(start);

    cout << start << " ";
    while(!q.empty())
    {
        i = q.front();
        q.pop();
        for(int j : graph[i])
        {
            if(visited[j] != true)
            {
                q.push(j);
                cout << j << " ";
                visited[j] = true;
            }
        }
    }
}

int main(void)
{
    int M, N, V;
    int a, b;

    cin >> M >> N >> V;
    
    graph.resize(M + 1);
    visited.resize(M + 1);

    for(int i = 0; i < N; i ++)
    {
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int j = 1; j < (M + 1); j ++)
    {
        sort(graph[j].begin(), graph[j].end());
    }

    dfs(V);

    cout << endl;

    fill(visited.begin(), visited.end(), false);

    bfs(V);
    return 0;
}