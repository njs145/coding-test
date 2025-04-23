#include<iostream>
#include<vector>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M, Q;

	cin >> N >> M;

	vector<vector<int>> map(N + 1, vector<int>(M + 1,0));
	vector<vector<long long>> pre_sum(N+1, vector<long long>(M + 1, 0));

	for(int i = 1; i <= N; i ++)
	{
		for(int j = 1; j <= M; j ++)
		{
			cin >> map[i][j];
			
			pre_sum[i][j] = pre_sum[i - 1][j] + pre_sum[i][j - 1] - pre_sum[i - 1][j - 1] + map[i][j];		
		}
	}
	
	cin >> Q;

	for(int i = 0; i < Q; i ++)
	{
		int x1, y1, x2, y2;
		long long total_sum;

		cin >> x1 >> y1 >> x2 >> y2;

		total_sum = pre_sum[x2][y2] - pre_sum[x1 -1][y2] - pre_sum[x2][y1 -1] + pre_sum[x1 -1][y1 - 1];

		cout << total_sum << '\n';
	}
}
