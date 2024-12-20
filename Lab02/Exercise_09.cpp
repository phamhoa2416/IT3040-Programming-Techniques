#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <cstdio>

using namespace std;

const int LIMIT = 100;
const int NUM_ITER = 100000;
const int NUM_INPUTS = NUM_ITER * 100;

double sigmoid_slow(double x) {
    return 1.0 / (1.0 + exp(-x));
}

double x[NUM_INPUTS];

void prepare_input() {
    const int PRECISION = 1000000;
    const double RANGE = LIMIT / 20.0;
    for (int i = 0; i < NUM_INPUTS; ++i) {
        x[i] = RANGE * (rand() % PRECISION - rand() % PRECISION) / PRECISION;
    }
}

const int N = 100000;
double x[N + 1];

void precalc() {
    double delta = (LIMIT * 2.0) / N;
    for (int i = 0; i <= N; ++i) {
        x[i] = sigmoid_slow(-LIMIT + delta * i);
    }
}

inline double sigmoid_fast(double x) {
    if (x < -LIMIT) return 0;
    if (x >= +LIMIT) return 1;
    static double delta = (LIMIT * 2.0) / N;
    int i = (x + LIMIT) / delta;
    return (x - (-LIMIT + (delta * i))) / delta * (x[i + 1] - x[i]) + x[i];
}    

double benchmark(double (*calc)(double), vector<double> &result) {
    const int NUM_TEST = 20;
    double taken = 0;
    result = vector<double>();
    result.reserve(NUM_ITER);

    int input_id = 0;
    clock_t start = clock();
    for (int t = 0; t < NUM_TEST; ++t) {
        double sum = 0;
        for (int i = 0; i < NUM_ITER; ++i) {
            double v = fabs(calc(x[input_id]));
            sum += v;
            if (t == 0) result.push_back(v);
            if ((++input_id) == NUM_INPUTS) input_id = 0;
        }
    }        

    clock_t finish = clock();
    taken = (double) (finish - start);
    // printf("Time: %.9f\n", taken / CLOCKS_PER_SEC);
    return taken;
}    

bool is_correct(const vector<double> &a_5128, const vector<double> &b_5128) {
    const double EPS = 1e-6;

    if (a_5128.size() != b_5128.size()) return false;
    for (unsigned i = 0; i < a_5128.size(); ++i) {
        if (fabs(a_5128[i] - b_5128[i]) > EPS) {
            return false;
        }
    }        

    return true;
}    

int main() {
    prepare_input();
    precalc();

    vector<double> a_5128, b_5128;
    double slow = benchmark(sigmoid_slow, a_5128);
    double fast = benchmark(sigmoid_fast, b_5128);

    double xval;
    scanf("%lf", &xval);
    printf("%.2f \n", sigmoid_fast(xval));

    if (is_correct(a_5128, b_5128) && (slow/fast > 1/3)) {
        printf("Correct answer! Your code is faster at least 30%%!\n");
    } else {
        printf("Wrong answer or your code is not fast enough!\n");
    }

    return 0;
}    
