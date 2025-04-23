#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(void)
{
    string line;
    int a, b, sum;
    while(getline(cin, line))
    {
        stringstream ss(line);
        ss >> a >> b;

        sum = (a + b);

        if(sum != 0)
        {
            cout << sum << endl;
        }
    }
}