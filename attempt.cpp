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
    while (a != 0 || b != 0)
    {
        // populate vectors
        insertToVector(a, first);
        insertToVector(b, second);

        while (first.size() > 0 && second.size() > 0)
        {
            int sum = *first.end() + *second.end() + rem;

            if (sum >= 10)
            {
                rem = sum - 10;
                carries++;
            }
            else
            {
                rem = 0;
            }
        }

        if (rem)
        {
            if (first.size() && (rem + *first.end() >= 10))
                carries++;
            if (second.size() && (rem + *second.end() >= 10))
                carries++;
        }

        if (!carries)
        {
            cout << "No carry operation.";
        }
        if (carries == 1)
        {
            cout << "1 carry operation.";
        }
        if (carries > 1)
        {
            cout << carries << " carry operations.";
        }

        // request input again
        cin >> a >> b;
    }

    return 0;
}