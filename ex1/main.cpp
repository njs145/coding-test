#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#include <sstream>

using namespace std;

class my_queue
{
    public:
    my_queue(void)
    {

    }

    ~my_queue(void)
    {

    }

    void my_queue_push(int data)
    {
        my_queue_.push_back(data);
        my_queue_index ++;
    }

    void my_queue_pop(void)
    {
        if(my_queue_index == 0)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << my_queue_.front() << endl;
            my_queue_.erase(my_queue_.begin());
            my_queue_index --;
        }
    }

    void my_queue_size(void)
    {
        cout << my_queue_index << endl;
    }

    void my_queue_empty(void)
    {
        if(my_queue_index == 0)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }

    void my_queue_front(void)
    {
        if(my_queue_index == 0)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << my_queue_.front() << endl;
        }
    }

    void my_queue_back(void)
    {
        if(my_queue_index == 0)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << my_queue_.back() << endl;
        }
    }

    private:

    vector<int> my_queue_;
    int my_queue_index = 0;
    
};

void input_to_queue(queue<pair<string, string>> *q, int max_cmd)
{
    for(int count = 0; count < max_cmd; count ++)
    {
        string line, cmd, data;
        getline(cin, line);
        stringstream ss(line);

        ss >> cmd >> data;

        q->push({cmd, data});
    }
}

int main(void)
{
    int max_cmd;
    int num;
    queue<pair<string, string>> q;
    string cmd, s_data;
    my_queue my_queue_;

    cout << "start" << endl;

    cin >> max_cmd;
    cin.ignore();

    input_to_queue(&q, max_cmd);

    for(int i = 0; i < max_cmd; i ++)
    {
        cmd = q.front().first;
        s_data = q.front().second;

        num = s_data.empty() ? 0 : stoi(s_data);
        q.pop();


        if(cmd.compare("push") == 0)
        {
            my_queue_.my_queue_push(num);
        }
        else if(cmd.compare("pop") == 0)
        {
            my_queue_.my_queue_pop();
        }
        else if(cmd.compare("size") == 0)
        {   
            my_queue_.my_queue_size();
        }
        else if(cmd.compare("empty") == 0)
        {
            my_queue_.my_queue_empty();
        }
        else if(cmd.compare("front") == 0)
        {
            my_queue_.my_queue_front();
        }
        else if(cmd.compare("back") == 0)
        {
            my_queue_.my_queue_back();
        }
        else
        {
            cout << "Disable Command" << cmd << endl; 
        }
    }

    return 0;
}