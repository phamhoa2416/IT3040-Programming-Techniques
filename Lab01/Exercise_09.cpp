#include<iostream>

using namespace std;

int main() {
    int size, value;
    cin >> size;

    int sequence[size];

    for (int i = 0; i < size; ++i) {
        cin >> value;
        sequence[i] = value;
    }

    for (int i = 0; i < size; ++i) {
        for (int j = i; j < size; ++j) {
            for (int k = i; k <= j; ++k) {
                cout << sequence[k] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}