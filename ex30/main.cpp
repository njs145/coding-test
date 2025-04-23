#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
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

	return 0;
}
