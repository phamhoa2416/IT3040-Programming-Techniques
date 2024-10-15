#include <iostream>

using namespace std;

void generateHamming(int N, int H, int pos, int ones, int sequence[])
{
    if (pos == N)
    {
        if (ones == H)
        {
            for (int i = 0; i < N; ++i)
                cout << sequence[i];
            cout << endl;
        }
        return;
    }

    sequence[pos] = 0;
    generateHamming(N, H, pos + 1, ones, sequence);

    if (ones < H)
    {
        sequence[pos] = 1;
        generateHamming(N, H, pos + 1, ones + 1, sequence);
    }
}

int main()
{
    int test_case;
    cin >> test_case;

    int t[200][2];
    int sequence[200];

    for (int i = 1; i <= test_case; ++i)
        cin >> t[i][0] >> t[i][1];

    for (int i = 1; i <= test_case; ++i)
    {
        int N = t[i][0];
        int H = t[i][1];
        cout << endl;
        generateHamming(N, H, 0, 0, sequence);
    }
}