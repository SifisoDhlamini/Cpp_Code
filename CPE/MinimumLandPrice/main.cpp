#include <iostream>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;

int main()
{
    vector<int> lands;
    int cases, land;

    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        cin >> land;
        while (land != 0)
        {
            lands.push_back(land);
            cin >> land;
        }
        sort(lands.begin(), lands.end(), greater<int>());
        int total = 0;
        int counter = 1;
        for (auto land : lands)
        {
            total += (2 * pow(land, counter));
            counter++;
        }
        lands.clear();
        (total <= 5000000) ? cout << total << endl : cout << "Too expensive" << endl;
    }
    return 0;
}