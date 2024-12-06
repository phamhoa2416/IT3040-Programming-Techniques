#include <iostream>
#include <stack>

using namespace std;

struct state {
    int i, j; // i for index of the current element, j for the sign (-1 or 1)
    state(int _i = 0, int _j = 0): i(_i), j(_j) {}
};

int main() {
    int n, M;
    cin >> n >> M;
    
    int m[n + 1];
    for (int i = 1; i <= n; ++i) 
        cin >> m[i];

    int x[n + 1]; // array to store the sign of the element
    stack<state> s;

    int sum = 0; // current sum of the expression
    s.push(state(1, -1)); // start DFS with the first element, trying a negative sign first
    while (!s.empty()) {
        state &top = s.top();
        if (top.i > n) {
            if (sum == M) {
                for (int i = 1; i <= n; ++i) {
                    if (x[i] == -1) cout << '-' << m[i];
                    if (x[i] == 1) cout << '+' << m[i];
                }
                cout << "=" << M;
                exit(0);
            }
            s.pop();
            continue;
        }
        // if the current element had a sign assigned, undo the operation
        if (top.j > -1)  
            sum -= m[top.i] * x[top.i];
        // if we've tried all options for the current element, backtrack further
        if (top.j > 1) {
            s.pop(); // remove the current element
            continue;
        }
        // assign the current sign to the element and update the sum
        x[top.i] = top.j;
        sum += m[top.i] * x[top.i];
        // move to next element, starting with a negative sign
        s.push(state(top.i + 1, -1));
        // increment the sign for the current element to try the next option
        ++top.j; 
    }
    cout << -1;

    return 0;
}