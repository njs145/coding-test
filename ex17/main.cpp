#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

static string password;
static vector<int> alphabat;
static int L, C;
static vector<char> mo = {'a', 'e', 'i', 'o', 'u'};

static int is_valid(string password)
{
	int mo_count = 0;

	for(int i = 0; i < L; i ++)
	{
		auto ret = find(mo.begin(), mo.end(), password[i]);
		if(ret != mo.end())
		{
			mo_count ++;
		}	
	}

	return ((mo_count > 0) && (mo_count <= (L - 2)));
}

static void make_password(int start, int depth)
{
	if(depth == L)
	{
		if(is_valid(password))
		{
			cout << password << endl;
			return;
		}
	}

	for(int i = start; i < C; i ++)
	{
		password.push_back(alphabat[i]);
		make_password(i + 1, depth + 1);
		password.pop_back();
	}
}


int main(void)
{
	char ch;
	cin >> L >> C;
	
	/* save input data */
	for(int i = 0; i < C; i ++)
	{
		cin >> ch;
		alphabat.push_back(ch);
	}

	/* sort alphabat */
	sort(alphabat.begin(), alphabat.end());
	
	make_password(0, 0);

	return 0;
}

