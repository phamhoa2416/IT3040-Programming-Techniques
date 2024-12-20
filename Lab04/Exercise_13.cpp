#include <iostream>
#include <unordered_map>

using namespace std;

int countSubStringsWithEqual01(const string& line) {
    unordered_map<int, int> prefixCount;
    int balance = 0;
    int result = 0;

    prefixCount[0] = 1;

    for (char c : line) {
        if (c == '1') 
            balance++;
        else 
            balance--;
    }

    if (prefixCount.find(balance) != prefixCount.end()) {
        result += prefixCount[balance];
    }

    return result;
}

int main() {
    string line;
    cin >> line;

    cout << countSubStringsWithEqual01(line) << endl;
    return 0;
}