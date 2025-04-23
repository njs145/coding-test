#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

static vector<vector<int>> map;
static vector<vector<int>> visited;
static vector<vector<int>> movement;
static queue<pair<int, int>> point;

static int dx[4] = {-1, 1, 0, 0};
static int dy[4] = {0, 0, -1, 1};

static void search_mirro(int row, int col)
{
    int curr_x = 0, curr_y = 0;
    int new_x, new_y;
    int count;

    point.push({curr_x, curr_y});
    visited[curr_x][curr_y] = true;
    movement[curr_x][curr_y] = 1;

    while(!point.empty())
    {
        curr_x = point.front().first;
        curr_y = point.front().second;
        point.pop();

        for(int dir = 0; dir < 4; dir ++)
        {
            new_x = dx[dir] + curr_x;
            new_y = dy[dir] + curr_y;

            if((new_x >= row) || (new_x < 0) || (new_y >= col) || (new_y < 0))
            {
                continue;
            }

            if(visited[new_x][new_y] == true)
            {
                continue;
            }

            if(map[new_x][new_y] == 1)
            {
                point.push({new_x, new_y});
                visited[new_x][new_y] = true;
                movement[new_x][new_y] = movement[curr_x][curr_y] + 1; /* 이전 값에서 더하면 됨. */

                if((new_x == (row -1) && new_y == (col - 1)))
                {
                    return; /* 걍 리턴해서 빠져 나와 */
                }
            }
        }
    }


}

int main(void)
{
    int row, col;
    string line;
    int num;
    char ch;

    cin >> row >> col;
    cin.ignore();

    map.resize(row);
    visited.resize(row);
    movement.resize(row);

    for(int i = 0; i < row; i ++)
    {
        getline(cin, line);
        for(int j = 0; j < col; j ++)
        {
            if(line[j] == '1')
            {
                map[i].push_back(1);
            }
            else
            {
                map[i].push_back(0);
            }

            visited[i].push_back(false);
            movement[i].push_back(0);
        }
    }

    search_mirro(row, col);

    cout << movement[row - 1][col - 1] << endl;


    return 0;
}