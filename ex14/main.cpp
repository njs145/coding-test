#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
static vector<char> alphabets;
static vector<char> moum = {'a', 'e', 'i', 'o', 'u'};
static int choose, input_count;
static int depth;
static string line;

static int is_valid(string word)
{
    int mo_count = 0; 
    int ja_count = 0;

    for(int i = 0; i < word.size(); i ++)
    {
        for(int m = 0; m < moum.size(); m ++)
        {
            if(word[i] == moum[m])
            {
                mo_count ++;
            }
        }
    }


    return ((mo_count >= 1) && (mo_count <= (choose - 2)));
}

static void dfs(int start, int depth)
{
    if(depth == choose)
    {
        if(is_valid(line))
        {
            cout << line << endl;
        }
    }

    for(int i = start; i < alphabets.size(); i ++)
    {
        line.push_back(alphabets[i]);
        dfs((i + 1), depth + 1);
        line.pop_back();
    }
}

int main(void)
{
    string word;
    char alphabet;

    cin >> choose >> input_count;

    for(int i = 0; i < input_count; i ++)
    {
        cin >> alphabet;
        alphabets.push_back(alphabet);
    }

    sort(alphabets.begin(), alphabets.end()); /* DFS 중간에 sort 하면 조짐. */
    dfs(0 ,0);

    return 0;
}