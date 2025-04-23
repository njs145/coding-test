#include <iostream>
#include <vector>

using namespace std;

vector<int> number;
vector<long long> pre_sum;
vector<long long> moduler_array; 

int main(void)
{
	int N, M;
	int t_num;
	int t_temp = 0;
	int moduler_count = 0;

	cin >> N >> M;

	moduler_array.resize(M);
	fill(moduler_array.begin(), moduler_array.end(), 0);
	
	number.push_back(0);
	pre_sum.push_back(0);
	
	for(int i = 1; i <= N; i ++)
	{
		cin >> t_num;
		number.push_back(t_num);
		
		pre_sum.push_back(pre_sum[i - 1] + number[i]);
	}

	for(size_t i = 0; i < pre_sum.size(); i ++)
	{
		moduler_array[pre_sum[i] % M] ++;
	}

	for(int i = 0; i < M; i ++)
	{
		t_temp = ((moduler_array[i]) * (moduler_array[i] - 1)) / 2;
		moduler_count += t_temp;
	}

	moduler_count += moduler_array[0];
	
	cout << moduler_count << endl;

	return 0;
}
