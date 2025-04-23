#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(void)
{
    string line;
    vector<vector<string>> str_template(51);
    int line_count;
    int count;
    int max_size;

    cin >> count;
    max_size = 0;

    cin.ignore();

    for(int i = 0; i < count; i ++)
    {
        getline(cin, line);
        line_count = line.size();

        str_template[line_count].push_back(line);

        if(line_count > max_size)
        {
            max_size = line_count;
        }
    }

    for(int j = 1; j < 50 + 1; j ++)
    {
        if(!str_template[j].empty())
        {
            sort(str_template[j].begin(), str_template[j].end());

            str_template[j].erase(unique(str_template[j].begin(), str_template[j].end()), str_template[j].end());
            
            for(int k = 0; k < str_template[j].size(); k ++)
            {
                cout << str_template[j][k] << endl;
            }
        }
    }
}