#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

#define SELECT_COUNT		6
#define DEBUG				0

static int K;
static vector<int> S;
static string result;

int main(void)
{
	string line;
	int temp;

	while(getline(cin, line))
	{
		if(line == "0")
		{
			break;
		}
		vector<bool> mask;

		istringstream iss(line);

		iss >> K;

		mask.resize(K);

		while(iss >> temp)
		{
			S.push_back(temp);
			#if(DEBUG)
			cout << temp << " ";
			#endif
		}

		#if(DEBUG)
		cout << endl;
		#endif

		fill(mask.begin(), mask.begin() + SELECT_COUNT, true);

		do
		{
			for(int j = 0; j < K; j++)
			{
				if(mask[j])
				{
					#if(DEBUG)
					cout << S[j] << " ";
					#endif
					result += to_string(S[j]) + " ";		
				}
			}

			#if(DEBUG)
			cout << endl;
			#endif
			result += "\n";

		}while(prev_permutation(mask.begin(), mask.end()));
		result += "\n";
		S.erase(S.begin(), S.end());
	}

	cout << result;
}
