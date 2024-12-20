#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_vector(const vector<int> &a)
{
    for (int v : a)
        cout << v << " ";
    cout << endl;
}

void delete_even(vector<int> &a)
{
    a.erase(remove_if(a.begin(), a.end(), [](int x)
                      { return x % 2 == 0; }),
            a.end());
}

void sort_decrease(vector<int> &a)
{
    sort(a.begin(), a.end(), greater<int>());
}

vector<int> merge_vectors(const vector<int> &a, const vector<int> &b)
{
    vector<int> result;
    merge(a.begin(), a.end(), b.begin(), b.end(), back_inserter(result), greater<int>());
    return result;
}

int main()
{
    int m, n, u;
    std::vector<int> a, b;

    std::cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        std::cin >> u;
        a.push_back(u);
    }
    for (int i = 0; i < n; i++)
    {
        std::cin >> u;
        b.push_back(u);
    }

    delete_even(a);
    std::cout << "Odd elements of a: ";
    print_vector(a);

    delete_even(b);
    std::cout << "Odd elements of b: ";
    print_vector(b);

    sort_decrease(a);
    std::cout << "Decreasingly sorted a: ";
    print_vector(a);

    sort_decrease(b);
    std::cout << "Decreasingly sorted b: ";
    print_vector(b);

    vector<int> c = merge_vectors(a, b);
    std::cout << "Decreasingly sorted c: ";
    print_vector(c);

    return 0;
}