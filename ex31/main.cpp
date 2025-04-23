#include <iostream>

using namespace std;

int main(void)
{
	ios:: sync_with_stdio(false);
	cin.tie(0);

	int N;
	int start = 1, end = 1, sum = 1;
	int count = 0;

	cin >> N;

	while(start <= N)
	{
		if(sum < N)
		{
			end ++;
			sum += end;
		}
		else if(sum > N)
		{
			sum -= start;
			start ++;
		}
		else
		{
			count ++;
			sum -= start;
			start ++;
		}
	}

	cout << count << endl;

	
}
