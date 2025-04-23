#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

#define a  'a'
#define z  'z'
#define A  'A'
#define Z  'Z'
#define space ' '
#define zero   '0'
#define nine    '9'

using namespace std;

void count_char_type(string s)
{
    vector<int> type(4);

    fill(type.begin(), type.end(), 0);
    for(int i = 0; i < s.size(); i ++)
    {
        if((s[i] >= a) && (s[i] <= z))
        {
            type[0] ++;
        }
        else if((s[i] >= A) && (s[i] <= Z))
        {
            type[1] ++;
        }
        else if((s[i] >= zero) && (s[i] <= nine))
        {
            type[2] ++;
        }
        else if(s[i] == space)
        {
            type[3] ++;
        }
        else
        {
            cout << "invalid char" << endl;
        }
    }
    
    cout << type[0] << " " << type[1] << " " << type[2] << " " << type[3] << endl;
}

int main(void)
{
    queue<string> lines;
    string line;

    while(getline(cin, line))
    {
        count_char_type(line);
    }
    return 0;
}