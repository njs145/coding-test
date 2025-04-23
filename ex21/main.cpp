#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

static int N;
static vector<int> number;
static string result;

int main(void)
{
	cin >> N;
	
	for(int i = 1; i <= N; i ++)
	{
		number.push_back(i);
	}

	do
	{
		for(int j = 0; j < N; j++)
		{
			result += to_string(number[j]) + " ";
		}

		result += "\n";
	}while(next_permutation(number.begin(), number.end()));	
	
	cout << result;
}
