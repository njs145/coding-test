#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

#define alphabat_num    ('z' - 'a' + 1)

int main(void)
{
    string line;
    int count;
    vector<pair<int, bool>> word;
    int before_count = 0;
    int flag;
    int group_count = 0;

    cin >> count;
    
    while(count --)
    {
        string line;
        cin >> line;

        word.clear();
        word.resize(alphabat_num, {0, false});

        flag = 1;
        for(int i = 0; i < line.size(); i ++)
        {
            if(((i - word[line[i] - 'a'].first) > 1) && (word[line[i] - 'a'].second != false))
            {
                flag = 0;
            }        
            word[line[i] - 'a'].first = i;
            word[line[i] - 'a'].second = true;
        }

        group_count += flag;
    }

    cout << group_count << endl;
}