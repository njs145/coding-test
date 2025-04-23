#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static long long N, H;

bool is_enough(const vector<int>& array, int height)
{
	long long total = 0;

	for(long long i = 0; i < N; i ++)
	{
		if(array[i] > height)
		{
			total += (array[i] - height);
		}
	}

	return total >= H;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> H;

	vector<int> size(N, 0);
	
	for(long long i = 0; i < N; i ++)
	{
		cin >> size[i];
	}

	int low = 0, high = *max_element(size.begin(), size.end()), anwser = 0;
	int mid;

	while(low <= high)
	{
		mid = (low + high) / 2;
		if(is_enough(size, mid))
		{
			anwser = mid;
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}

	cout << anwser << endl;
}
