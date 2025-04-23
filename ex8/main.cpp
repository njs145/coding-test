#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int row, col;
    int num;

    cin >> row >> col;

    vector<vector<int>> a(row, vector<int>(col,0));
    vector<vector<int>> b(row, vector<int>(col,0));
    vector<vector<int>> sum(row, vector<int>(col,0));

    for(int i = 0; i < row; i ++)
    {
        for(int j = 0; j < col; j ++)
        {
           cin >> num;
           a[i][j] = num;
            
        }
    }

    for(int k = 0; k < row; k ++)
    {
        for(int q = 0; q < col; q ++)
        {
           cin >> num;
           b[k][q] = num;
        }
    }

    for(int o = 0; o < row; o ++)
    {
        for(int p = 0; p < col; p ++)
        {
            sum[o][p] = a[o][p] + b[o][p];
        }
    }

    for(int c = 0; c < row; c ++)
    {
        for(int d = 0; d < col; d ++)
        {
            cout << sum[c][d] << " ";
        }
        cout << endl;
    }
}