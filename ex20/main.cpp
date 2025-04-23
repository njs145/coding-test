#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static int M, N;
static vector<int> numbers;
static vector<bool> mask;
static string result;

void make_number(void)
{
	do
	{
		for(int i = 0; i < M; i ++)
		{
			if(mask[i])
			{
				result += to_string(numbers[i]) + " ";
			}
		}
		result += "\n";
	}while(prev_permutation(mask.begin(), mask.end()));
}

int main(void)
{
	cin >> M >> N;

	mask.resize(M);

	for(int i = 1; i <= M; i ++)
	{
		numbers.push_back(i);
	}

	fill(mask.begin(), mask.begin() + N, true);

	make_number();

	cout << result;
}
