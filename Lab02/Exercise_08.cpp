#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
    int firstValue, secondValue;
    cin >> firstValue >> secondValue;

    vector<vector<int>> arr = {
        {1, 3, 7},
        {2, 3, 4, firstValue},
        {9, 8, 15},
        {10, secondValue},
    };

    sort(arr.begin(), arr.end(), [](const vector<int> &a, const vector<int> &b)
         { return accumulate(a.begin(), a.end(), 0) > accumulate(b.begin(), b.end(), 0); });

    for (const auto &v : arr)
    {
        for (int it : v)
        {
            cout << it << " ";
        }
        cout << endl;
    }

    return 0;
}