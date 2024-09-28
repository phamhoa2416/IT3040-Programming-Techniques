#include <iostream>

using namespace std;

void addTwoMatrix(int **firstMatrix, int **secondMatrix, int size)
{
    int **resultMatrix = new int *[size];
    for (int i = 0; i < size; ++i)
    {
        resultMatrix[i] = new int[size];
        for (int j = 0; j < size; ++j)
        {
            resultMatrix[i][j] = firstMatrix[i][j] + secondMatrix[i][j];
            cout << resultMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

void multiplyTwoMatrix(int **firstMatrix, int **secondMatrix, int size)
{
    int **resultMatrix = new int *[size];
    for (int i = 0; i < size; ++i)
    {
        resultMatrix[i] = new int[size];
        for (int j = 0; j < size; ++j)
        {
            resultMatrix[i][j] = 0;
            for (int k = 0; k < size; ++k)
                resultMatrix[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
            cout << resultMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int size;
    printf("Enter the size of two matrices: ");
    scanf("%d", &size);
    printf("Enter the first matrix: \n");
    int **firstMatrix = new int *[size];
    for (int i = 0; i < size; ++i)
    {
        firstMatrix[i] = new int[size];
        for (int j = 0; j < size; ++j)
        {
            scanf("%d", &firstMatrix[i][j]);
        }
    }

    printf("Enter the second matrix: \n");
    int **secondMatrix = new int *[size];
    for (int i = 0; i < size; ++i)
    {
        secondMatrix[i] = new int[size];
        for (int j = 0; j < size; ++j)
        {
            scanf("%d", &secondMatrix[i][j]);
        }
    }

    printf("The sum of the two matrices is: \n");
    addTwoMatrix(firstMatrix, secondMatrix, size);

    printf("The product of the two matrices is: \n");
    multiplyTwoMatrix(firstMatrix, secondMatrix, size);

    free(firstMatrix);
    free(secondMatrix);

    return 0;
}