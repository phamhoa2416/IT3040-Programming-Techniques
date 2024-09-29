#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
    int key, value;
    vector<pair<int, int>> map;
    while (cin >> key && cin >> value)
        map.push_back(make_pair(key, value));

    sort(map.begin(), map.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         {
        if (a.second > b.second) return true;
        else if (a.second < b.second) return false;
        else return a.first >= b.first; });

    for (auto &p : map)
        cout << p.first << " " << p.second << endl;
}