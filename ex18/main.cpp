#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static int N, M;
vector<int> number;
vector<bool> visited;
vector<int> select_num;
string result;

void dfs(int depth)
{
	if(depth == M)
	{
		for(int i = 0; i < M; i++)
		{
			result += to_string(select_num[i]) + " ";
		}
		result += "\n";
		return;
	}

	for(int j = 0; j < N; j ++)
	{
		if(!visited[j])
		{
			select_num.push_back(number[j]);
			visited[j] = true;
			dfs(depth + 1);
			visited[j] = false;
			select_num.pop_back();
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	visited.resize(N);

	fill(visited.begin(), visited.end(), false);

	for(int i = 1; i <= N; i ++)
	{
		number.push_back(i);
	}

	dfs(0);

	cout << result;
}