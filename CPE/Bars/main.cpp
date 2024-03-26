#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int tests;
    cin >> tests;
    while (tests--)
    {
        int length, bars;
        cin >> length >> bars;
        vector<int> bar_lengths(bars);
        for (int i = 0; i < bars; i++)
        {
            cin >> bar_lengths[i];
        }

        vector<bool> dp(length + 1, false);
        dp[0] = true;
        for (int i = 0; i < bars; i++)
        {
            for (int j = length; j >= bar_lengths[i]; j--)
            {
                if (dp[j - bar_lengths[i]])
                {
                    dp[j] = true;
                }
            }
        }

        if (dp[length])
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}