#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;

vector<int> numbers;

int main(void)
{
    string line;
    int temp;
    int K;

    while(getline(cin, line))
    {
        istringstream iss(line);

        iss >> K;

        while(iss >> temp)
        {
            numbers.push_back(temp);

        }

        for(int i = 0; i < K; i ++)
        {
            cout << numbers[i] << " ";
        }

        cout << endl;
    }
}