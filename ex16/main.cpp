#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> moums = {'a', 'e', 'i', 'o', 'u'};
vector<bool> mask;
vector<char> alphabat;
string word;
int C, L;

static int is_valid(string word)
{
    int mo_count = 0; 

    for(int i = 0; i < word.size(); i ++)
    {
        for(int m = 0; m < moums.size(); m ++)
        {
            if(word[i] == moums[m])
            {
                mo_count ++;
            }
        }
    }


    return ((mo_count >= 1) && (mo_count <= (L - 2)));
}

int main(void)
{
    cin >> L >> C;
    char ch;
    int ret;

    mask.resize(C);
    fill(mask.begin(), mask.begin() + L, true);  // 앞에서 L개 선택

    for(int q = 0; q < C; q ++)
    {
        cin >> ch;
        
        alphabat.push_back(ch);
    }

    sort(alphabat.begin(), alphabat.end());

    do
    {
        word = "";
        for(int j = 0; j < mask.size(); j ++)
        {
            if(mask[j] == true)
            {
                word.push_back(alphabat[j]); 
            }
        }

        ret = is_valid(word);
        if(ret)
        {
            cout << word << '\n';
        }

    } while (prev_permutation(mask.begin(), mask.end()));
    

    return 0;
}
