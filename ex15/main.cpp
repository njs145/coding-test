#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> moums = {'a', 'e', 'i', 'o', 'u'};
vector<char> alphabat;
int L, C;
string password;

int check_valid_password(string pw)
{
    int moum_count = 0;

    for(int i = 0; i < pw.size(); i ++)
    {
        for(int j = 0; j < moums.size(); j ++)
        {
            if(pw[i] == moums[j])
            {
                moum_count ++;
            }
        }
    }

    return ((moum_count > 0) && (moum_count <= (L - 2)));
}

void make_password(int start, int depth)
{
    int ret;
    if(depth == L)
    {
        ret = check_valid_password(password);
        if(ret == 1)
        {
            cout << password << endl;
        }
        return;
    }

    for(int i = start; i < alphabat.size(); i ++)
    {
        password.push_back(alphabat[i]);
        make_password((i + 1), (depth + 1));
        password.pop_back();
    }
}

int main(void)
{
    char ch;
    cin >> L >> C;

    for(int i = 0; i < C; i ++)
    {
        cin >> ch;
        alphabat.push_back(ch);
    }

    sort(alphabat.begin(), alphabat.end());

    make_password(0, 0);

    return 0;
}