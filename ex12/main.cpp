#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

static vector<vector<int>> map;
static vector<vector<bool>> check;
static vector<int> dx = {-1, 1, 0, 0};
static vector<int> dy = {0, 0, -1, 1};
static vector<int> APT_count_array;
static int town_num;
static int side;
static int APT_count;

static void count_town(int start_x, int start_y)
{
    int curr_x, curr_y;
    int new_x, new_y;

    curr_x = start_x;
    curr_y = start_y;

    check[start_x][start_y] = true; /* 초기 방문 x */
    APT_count ++;

    for(int i = 0; i < 4; i ++)
    {
        new_x = curr_x + dx[i];
        new_y = curr_y + dy[i];

        if((new_x < 0) || (new_x >= side) || (new_y < 0) || (new_y >= side))
        {
            continue;
        }
        if((check[new_x][new_y] == true) || map[new_x][new_y] == 0)
        {
            continue;
        }

        check[new_x][new_y] = true;
        count_town(new_x, new_y);
    }
}

int main(void)
{
    string line;

    town_num = 0;

    cin >> side;
    cin.ignore();

    map.resize(side);
    check.resize(side);

    for(int i = 0; i < side; i ++)
    {
        getline(cin, line);

        for(int j = 0; j < side; j ++)
        {
            if(line[j] == '1')
            {
                map[i].push_back(1); 
            }
            else
            {
                map[i].push_back(0);
            }
            check[i].push_back(false);
        }
    }

    for(int k = 0; k < side; k ++)
    {
        for(int q = 0; q < side; q ++)
        {
            if((check[k][q] != true) && (map[k][q] != 0))
            {
                APT_count = 0;
                count_town(k, q);
                APT_count_array.push_back(APT_count);
                town_num ++;
            }
        }
    }

    cout << town_num << endl;
    sort(APT_count_array.begin(),APT_count_array.end());
    for(int p = 0; p < APT_count_array.size(); p ++)
    {
        cout << APT_count_array[p] << endl;
    }


    return 0;
}