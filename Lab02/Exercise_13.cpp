#include <iostream>
#include <vector>
#include <complex>

using namespace std;

using complex_double = complex<double>;
const double PI = acos(-1);

void fast_fourier(vector<complex_double> &p, bool invert) {
    int size = p.size();
    if (size == 1) 
        return;
    
    vector<complex_double> p_0(size / 2), p_1(size / 2); 
    for (int i = 0; i < size / 2; ++i) {
        p_0[i] = p[2 * i];
        p_1[i] = p[2 * i + 1];
    }
    fast_fourier(p_0, invert);
    fast_fourier(p_1, invert);

    double angle = 2 * PI / size * (invert ? -1 : 1);
    complex_double matrix_element(1), matrix_element_n(cos(angle), sin(angle));
    for (int i = 0; i < size / 2; ++i) {
        p[i] = p_0[i] + matrix_element * p_1[i];
        p[i + size / 2] = p_0[i] - matrix_element * p_1[i];
        if (invert) {
            p[i] /= 2;
            p[i + size / 2] /= 2;
        }
        matrix_element = matrix_element * matrix_element_n;
    }
}

vector<int> polynomial_multiply(vector<int>& first, vector<int>& second) {
    vector<complex_double> fa(first.begin(), first.end()), fb(second.begin(), second.end());
    int n = 1;
    while (n < first.size() + second.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);
    fast_fourier(fa, false);
    fast_fourier(fb, false);

    for (int i = 0; i < n; ++i) {
        fa[i] *= fb[i];
    }

    fast_fourier(fa, true);
    vector<int> result(n);
    for (int i = 0; i < n; ++i) {
        result[i] = round(fa[i].real());
    }

    return result;
}

int main() {
    int m, n;
    vector<int> firstPolynomial, secondPolynomial;
    cin >> n;
    for (int i = 0; i < n + 1; ++i) {
        int value;
        cin >> value;
        firstPolynomial.push_back(value);
    }

    cin >> m;
    for (int i = 0; i < m + 1; ++i) {
        int value;
        cin >> value;
        secondPolynomial.push_back(value);
    }

    vector<int> result = polynomial_multiply(firstPolynomial, secondPolynomial);

    int h = m + n + 1;
    int xor_res = result[0] ^ result[1];
    for (int i = 2; i < h; ++i) 
        xor_res = xor_res ^ result[i];
    cout << endl << xor_res;

    return 0;
}
