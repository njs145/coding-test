#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int main(void)
{
    vector<vector<bool>> paper(100, vector<bool>(100 , 0));
    int count;
    string line;
    int size = 0;

    cin >> count;
    cin.ignore();

    for(int i = 0; i < count; i ++)
    {
        string srow, scol;
        int row, col;

        getline(cin, line);

        stringstream ss(line);
        ss >> srow >> scol;

        row = stoi(srow);
        col = stoi(scol);

        for(int j = row; j < (row + 10); j ++)
        {
            for(int k = col; k < (col + 10); k ++)
            {
                paper[j][k] = true;
            }
        }
    }

    for(int a = 0; a < 100; a ++)
    {
        for(int b = 0; b < 100; b ++)
        {
            if(paper[a][b] == true)
            {
                size ++;
            }
        }
    }

    cout << size << endl;

    
    return 0;
}