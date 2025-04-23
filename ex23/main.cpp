#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#define DEBUG		0

using namespace std;

static int N, S;
static int plus_count;
static vector<int> numbers;
static vector<int> select_num;
static int gole_count;

int is_valid(void)
{
	int sum = 0;
	int ret = 0;
	for(int i = 0; i < plus_count; i ++)
	{
#if(DEBUG)
		cout << select_num[i];
#endif
		sum += select_num[i];
	}
	
	if(sum == S)
	{
#if(DEBUG)
		cout << "sum: " << sum << " target: " << S << endl;
#endif
		ret = 1;
	}
	
	return ret;
}

void dfs(int start, int depth)
{
#if(DEBUG)
	// cout << plus_count << endl;
#endif		
	if(depth == plus_count)
	{
		if(is_valid())
		{
			gole_count ++;	
		}
	}

	for(int i = start; i < N; i ++)
	{
		select_num.push_back(numbers[i]);
		dfs(i + 1, depth + 1);
		select_num.pop_back();
	}
}

int main(void)
{
	string line;
	int temp;

	gole_count = 0;

	cin >> N >> S;
	cin.ignore();

	getline(cin, line);

	istringstream iss(line);

	while(iss >> temp)
	{
		numbers.push_back(temp);
	}

	for(plus_count = 1; plus_count <= N; plus_count++)
	{
		dfs(0,0);
	}

	cout << gole_count << endl;

}
