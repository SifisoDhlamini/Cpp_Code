// check matrix symetricy
// METHOD:
// 1.Change rows to columns in copy matrix
// 2. Check if all elements are the same while traversing through the both matrices

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    int cases, size;

    cin >> cases;
    for (int testCase = 0; testCase < cases; testCase++)
    {
        cout << "N = ";
        cin >> size;

        vector<vector<int>> originalMatrix(size, vector<int>(size));
        vector<vector<int>> compareMatrix(size, vector<int>(size));
        // int originalArr[size][size];
        // int compareArr[size][size];

        // populate original array
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                int num;
                cin >> num;
                originalMatrix[i][j] = num;
            }
        }

        // save transposed version
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                // need to change this
                compareMatrix[i][j] = originalMatrix[size - i - 1][size - j - 1];
            }
        }

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << compareMatrix[i][j] << " ";
            }
            cout << endl;
        }
        // compare vector equality
        bool is_equal = equal(originalMatrix.begin(), originalMatrix.end(), compareMatrix.begin());

        (is_equal) ? cout << "Symetric" << endl : cout << "Non-symetric" << endl;
    }

    return 0;
}
