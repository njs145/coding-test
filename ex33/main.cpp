#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool binary_search(const vector<int>& arr, int target)
{
	int left, right, mid;

	left = 0;
	right = arr.size() - 1;

	while(left <= right)
	{
		mid = (left + right) / 2;
		if(target == arr[mid])
		{
			return true;
		}
		else if(target > arr[mid])
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	return false;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M;

	cin >> N;

	vector<int> a(N, 0);

	for(int i = 0; i < N; i ++)
	{
		cin >> a[i];
	}
	
	cin >> M;
	vector<int> b(M, 0);

	for(int i = 0; i < M; i ++)
	{
		cin >> b[i];
	}

	sort(a.begin(), a.end());
	// sort(b.begin(), b.end());

	for(int i = 0; i < M; i ++)
	{
		if(binary_search(a, b[i]) == true)
		{
			cout << 1 << '\n';
		}
		else
		{
			cout << 0 << '\n';
		}
	}	

}
