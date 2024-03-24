#include <iostream>
// #include <vector>
//  #include <queue>
//  #include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int people;
    cin >> people;
    while (people != 0)
    {
        // vector<int> ages(101, 0);
        int ages[101]{};
        for (int i = 0; i < people; i++)
        {
            int age;
            cin >> age;
            ages[age]++;
        }

        bool first = true;
        for (int i = 1; i <= 100; i++)
        {
            for (int j = 0; j < ages[i]; j++)
            {
                if (!first)
                    cout << " ";
                cout << i;
                first = false;
            }
        }
        cout << "\n";
        cin >> people;
    }
    return 0;

    // int people;
    // // vector<int> ages;
    // priority_queue<int, vector<int>, greater<int>> agesOther;

    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    // cin >> people;
    // while (people > 0)
    // {
    //     for (int i = 0; i < people; i++)
    //     {
    //         int age;
    //         cin >> age;
    //         // ages.push_back(age);
    //         agesOther.push(age);
    //     }

    //     // sort(ages.begin(), ages.end(), less<int>());
    //     // int n = ages.size();
    //     int n = agesOther.size();
    //     bool first = true;
    //     for (int i = 0; i < n; i++)
    //     {
    //         if (!first)
    //             cout << " ";
    //         // cout << ages[i];
    //         cout << agesOther.top();
    //         agesOther.pop();
    //         first = false;
    //     }
    //     cout << "\n";
    //     // ages.clear();
    //     cin >> people;
    // }
    // return 0;
}