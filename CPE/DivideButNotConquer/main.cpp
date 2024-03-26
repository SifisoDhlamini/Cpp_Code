#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;

    cin >> n >> m;
    vector<int> multiples;
    while (n >= m)
    {
        if (n % m == 0)
        {
            multiples.push_back(n);
            n /= m;
            if (n == 1)
                multiples.push_back(n);
        }
        else
        {
            break;
        }
    }

    if (n == 1)
    {
        for (int multiple = 0; multiple < multiples.size(); multiple++)
        {
            if (multiple == 0)
                cout << multiples[multiple];
            else
                cout << " " << multiples[multiple];
        }
    }
    else
    {
        cout << "Boring!";
    }
    cout << endl;

    return 0;
}