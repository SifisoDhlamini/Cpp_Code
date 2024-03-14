#include <vector>
#include <iostream>

using namespace std;

void insertToVector(int number, vector<int> &container)
{
    std::vector<int>::iterator it;
    while (number)
    {
        it = container.begin();
        container.insert(it, number % 10);
        number /= 10;
    }
}

int main()
{
    int a, b, rem = 0, carries{};
    vector<int> first{};
    vector<int> second{};

    cin >> a >> b;
    while (a != 0 && b != 0)
    {

        // populate vectors
        insertToVector(a, first);
        insertToVector(b, second);

        while (first.size() > 0 && second.size() > 0)
        {
            int sum = first.back() + second.back() + rem;
            // cout << "sum: " << sum << endl;

            if (sum >= 10)
            {
                // cout << "in" << endl;
                rem = 1;
                carries++;
            }
            else
            {
                rem = 0;
            }
            first.pop_back();
            second.pop_back();
        }

        // check if there is still a remainder
        // if rem added to remain digit does it cause a carry
        // cout << "rem: " << rem << endl;
        if (rem)
        {
            if (first.size() && (rem + *first.end() >= 10))
                carries++;
            if (second.size() && (rem + *second.end() >= 10))
                carries++;
        }

        if (!carries)
        {
            cout << "No carry operation." << endl;
        }
        if (carries == 1)
        {
            cout << "1 carry operation." << endl;
        }
        if (carries > 1)
        {
            cout << carries << " carry operations." << endl;
        }

        rem = 0;
        carries = 0;

        // request input again
        cin >> a >> b;
    }

    return 0;
}