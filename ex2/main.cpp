#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void input_to_queue(vector<int> *v, int count)
{
    int data;
    for(int i = 0; i < count; i ++)
    {
        cin >> data;
        v->push_back(data);
    }
}

int main(void)
{
    int count;
    int cur_num;
    size_t size;
    vector<int> data;

    cin >> count;
    input_to_queue(&data, count);

    sort(data.begin(), data.end());


    cur_num = 0;
    for(int i = 0; i < data.size(); i ++)
    {
        if(cur_num != data[i])
        {
            cur_num = data[i];
            cout << cur_num << " ";
        }
    }
    return 0;
}