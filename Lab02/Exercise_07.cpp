#include <iostream>

using namespace std;

template <typename T>
T arr_sum(T *firstArray, int firstSize, T *secondArray, int secondSize)
{
    T sumArray = 0;
    for (int i = 0; i < firstSize; ++i)
        sumArray += *(firstArray + i);

    for (int i = 0; i < secondSize; ++i)
        sumArray += *(secondArray + i);

    return sumArray;
}

int main()
{
    int val;
    cin >> val;

    {
        int firstArray[] = {3, 2, 0, val};
        int secondArray[] = {5, 6, 1, 2, 7};
        cout << arr_sum(firstArray, 4, secondArray, 5) << endl;
    }

    {
        double firstArray[] = {3.0, 2, 0, val * 1.0};
        double secondArray[] = {5, 6.1, 1, 2.3, 7};
        cout << arr_sum(firstArray, 4, secondArray, 5) << endl;
    }

    return 0;
}