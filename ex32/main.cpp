#include <iostream>
#include <vector>

using namespace std;

#define T_MIN(A,B)	(A >= B) ? B : A

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, S;
	int start = 0, end = 0, sum = 0, length = 0, anwser;

	cin >> N >> S;

	anwser = N + 1;

	vector<int> nums(N, 0);

	for(int i = 0; i < N; i ++)
	{
		cin >> nums[i];
	}

	while(start < N)
	{
		if(sum < S && end < N)
		{
			sum += nums[end];
			end ++;
		}
		else
		{
			if(sum >= S)
			{
				length = end - start; // 사이즈 계산: 인덱스가 0부터라서 end - start
				anwser = T_MIN(anwser, length);
			}
			sum -= nums[start];
			start ++;
		}
	}

	if(anwser == (N + 1))
	{
		cout << 0 << endl;
	}
	else
	{
		cout << anwser << endl;
	}
}
