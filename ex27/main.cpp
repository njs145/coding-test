#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int N, M;

	cin >> N >> M;

	vector<vector<int>> t_map(N + 1, vector<int>(N + 1, 0));
	vector<vector<long long>> pre_sum(N + 1, vector<long long>(N + 1, 0));
	vector<long long> vector_sum(M, 0);

	for(int i = 1; i <= N; i ++)
	{
		for(int j = 1; j <= N; j ++)
		{
			cin >> t_map[i][j];

			pre_sum[i][j] = t_map[i][j] + pre_sum[i - 1][j] + pre_sum[i][j - 1] - pre_sum[i - 1][j - 1];
		}
	}

	for(int i = 0; i < M; i ++)
	{
		int x1, y1, x2, y2;
		long long temp;

		cin >> x1 >> y1 >> x2>> y2;
		
		temp = pre_sum[y2][x2] - pre_sum[y1 -1][x2] - pre_sum[y2][x1 -1] + pre_sum[y1 - 1][x1 - 1];  
		
		cout << temp << "\n";
	}

	return 0;

}
