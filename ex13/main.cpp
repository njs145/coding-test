#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int num, max, card, sum, max_sum;
    vector<int> cards;
    cin >> num >> max;

    for(int i = 0; i < num; i ++)
    {
        cin >> card;
        cards.push_back(card);
    }

    max_sum = 0;
    for(int a = 0; a < num; a ++)
    {
        for(int b = 0; b < num; b ++)
        {
            for(int c = 0; c < num; c ++)
            {
                if((a == b) || (b == c) || (c == a))
                {
                    continue;
                }

                sum = cards[a] + cards[b] + cards[c];

                if(sum > max)
                {
                    continue;
                }

                if((sum > max_sum))
                {
                    max_sum = sum;
                }
            }
        }
    }

    cout << max_sum << endl;

}