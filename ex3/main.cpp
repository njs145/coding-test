#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define  a  'a'
#define  z  'z'
#define  A  'A'
#define  Z  'Z'


int main(void)
{
    vector<char> ch;
    vector<int> count(26);
    string line;
    int max, max_index;
    int res;
    int max_count = 0;

    cin >> line;

    for(int i = 0; i < line.size(); i ++)
    {
        if((line[i] >= a) && (line[i] <= z))
        {
            count[line[i] - a] ++;
        }
        else if((line[i] >= A) && (line[i] <= Z))
        {
            count[line[i] - A] ++;
        }
        else
        {
            break;
        }
    }

    max_index = 0;
    for(int i = 0; i < count.size(); i ++)
    {
        if(count[max_index] < count[i])
        {
            max_index = i;
        }
    }

    for(int j = 0; j < count.size(); j ++)
    {
        if(count[max_index] == count[j])
        {
            max_count ++;
        }
    }

    if(max_count == 1)
    {
        cout << (char)(max_index + A) << endl;
    }
    else
    {
        cout << "?" << endl;
    }

    return 0;
}