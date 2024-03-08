#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

double maxPieSize(int radii[], int n, int f)
{
    double pi = 3.14159265358979323846;
    // double pi = acos(-1);
    double low = 0, high = 0;
    for (int i = 0; i < n; i++)
    {
        high += pi * radii[i] * radii[i];
    }
    high /= (f + 1);
    double eps = 1e-6;
    while ((high - low) > eps)
    {
        double mid = (low + high) / 2;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            count += (int)(pi * radii[i] * radii[i] / mid);
        }
        if (count >= f + 1)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }
    return low;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, f;
        cin >> n >> f;
        int radii[n];
        for (int i = 0; i < n; i++)
        {
            cin >> radii[i];
        }
        double answer = maxPieSize(radii, n, f);
        // printf("%.4f\n", answer);
        cout << fixed;
        cout.precision(4);
        cout << answer << endl;
    }

    return 0;
}