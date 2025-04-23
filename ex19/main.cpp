#include <iostream>
#include <vector>
#include <string>

using namespace std;

static int M, N;
static vector<int> numbers;
static vector<bool> visited;
static vector<int> select_num;
static string result;

void dfs(int depth)
{
	if(depth == N)
	{
		for(int i = 0; i < N; i ++)
		{
			result += to_string(select_num[i]) + " ";
		}
		result += "\n";

		return;
	}

	for(int j = 0; j < M; j ++)
	{
		//if(!visited[j])
		//{
			visited[j] = true;
			select_num.push_back(numbers[j]);
			dfs(depth + 1);
			select_num.pop_back();
			visited[j] = false;
		//}
	}
}

int main(void)
{
	cin >> M >> N;

	visited.resize(M);

	for(int i = 1; i <= M; i ++)
	{
		numbers.push_back(i);
	}

	dfs(0);

	cout << result;
}
