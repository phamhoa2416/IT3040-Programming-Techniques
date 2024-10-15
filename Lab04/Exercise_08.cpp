#include <iostream>
#include <map>

using namespace std;

template <class T>
map<T, double> fuzzy_set_union(const map<T, double> &a, const map<T, double> &b)
{
    map<T, double> result = a;
    for (const pair<T, double> &element : b)
    {
        if (result.find(element.first) == result.end())
            result[element.first] = element.second;
        else
            result[element.first] = max(result[element.first], element.second);
    }
    return result;
}

template <class T>
map<T, double> fuzzy_set_intersection(const map<T, double> &a, const map<T, double> &b)
{
    map<T, double> result = a;
    for (const pair<T, double> &element : b)
    {
        if (result.find(element.first) != result.end())
            result[element.first] = min(result[element.first], element.second);
    }
    return result;
}

template <class T>
void print_fuzzy_set(const std::map<T, double> &fuzzy_set)
{
    cout << "{";
    for (const auto &x : fuzzy_set)
        cout << "(" << x.first << "," << x.second << ") ";
    cout << "}";
    cout << std::endl;
}

// int main() {
//     std::map<int, double> a = {{1, 0.2}, {2, 0.5}, {3, 1}, {4, 0.6}, {5, 0.7}};
//     std::map<int, double> b = {{1, 0.5}, {2, 0.4}, {4, 0.9}, {5, 0.4}, {6, 1}};
//     std::cout << "A = "; print_fuzzy_set(a);
//     std::cout << "B = "; print_fuzzy_set(b);
//     std::map<int, double> c = fuzzy_set_union(a, b);
//     std::map<int, double> d = fuzzy_set_intersection(a, b);
//     std::cout << "Union: "; print_fuzzy_set(c);
//     std::cout << "Intersection: "; print_fuzzy_set(d);

//     return 0;

// }