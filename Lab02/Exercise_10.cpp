#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

const int N = 128;

struct Matrix
{
    unsigned int matrix[N][N];

    Matrix()
    {
        memset(matrix, 0, sizeof(matrix));
    }
};

bool operator==(const Matrix &a, const Matrix &b)
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (a.matrix[i][j] != b.matrix[i][j])
                return false;
        }
    }
    return true;
}

Matrix multiply_naive(const Matrix &a, const Matrix &b)
{
    Matrix result;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            for (int k = 0; k < N; ++k)
                result.matrix[i][j] += a.matrix[i][k] * b.matrix[k][j];
        }
    }
    return result;
}

Matrix multiply_fast(const Matrix &a, const Matrix &b)
{
    Matrix result;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            int sum = 0;
            for (int k = 0; k < N; ++k)
            {
                sum += a.matrix[i][k] * b.matrix[k][j];
            }
            result.matrix[i][j] = sum;
        }
    }
    return result;
}

Matrix gen_random_matrix()
{
    Matrix a;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            a.matrix[i][j] = rand();
        }
    }
    return a;
}

Matrix base;

double benchmark(Matrix (*multiply)(const Matrix &, const Matrix &), Matrix &result)
{
    const int NUM_TEST = 10;
    const int NUM_ITER = 64;

    Matrix a = base;
    result = a;

    double taken = 0;
    for (int t = 0; t < NUM_TEST; ++t)
    {
        clock_t start = clock();
        for (int i = 0; i < NUM_ITER; ++i)
        {
            a = multiply(a, result);
            result = multiply(result, a);
        }
        clock_t finish = clock();
        taken += (double)(finish - start);
    }
    taken /= NUM_TEST;

    printf("Time: %.9f\n", taken / CLOCKS_PER_SEC);
    return taken;
}

int main()
{
    base = gen_random_matrix();

    Matrix a, b;
    printf("Slow version\n");
    double slow = benchmark(multiply_naive, a);
    printf("Fast version\n");
    double fast = benchmark(multiply_fast, b);

    if (a == b)
    {
        printf("Correct answer! Your code is %.2f%% faster\n", slow / fast * 100.0);
    }
    else
    {
        printf("Wrong answer!\n");
    }

    return 0;
}
