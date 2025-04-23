#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M;

	cin >> N >> M;
	vector<vector<int>> map(N + 1, vector<int>(N + 1, 0));
	vector<vector<long long>> S(N + 1, vector<long long>(N + 1, 0));	

	for(int i = 1; i <= N; i ++)
	{
		for(int j = 1; j <= N; j ++)
		{
			cin >> map[i][j];

			S[i][j] = map[i][j] + S[i - 1][j] + S[i][j - 1] - S[i - 1][j -1];
		}
	}

	for(int i = 0; i < M; i ++)
	{
		int x1, y1, x2, y2;
		long long temp;

		cin >> x1 >> y1 >> x2 >> y2;

		temp = S[x2][y2] - S[x1 - 1][y2] - S[x2][y1 -1] + S[x1 -1][y1 -1];

		cout << temp << '\n'; 
	}

	return 0;
}
