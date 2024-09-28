#include <stdio.h>
#include <cstdlib>

int *arr;
int size, temp;

int main()
{
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    // Allocate memory
    arr = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; ++i)
        scanf("%d", arr + i);

    printf("The input array is: \n");
    for (int i = 0; i < size; ++i)
        printf("%d ", *(arr + i));
    printf("\n");

    for (int i = 0; i < size; ++i)
    {
        for (int j = i; j < size; ++j)
        {
            if (*(arr + i) > *(arr + j))
            {
                temp = *(arr + i);
                *(arr + i) = *(arr + j);
                *(arr + j) = temp;
            }
        }
    }

    printf("The sorted array is: \n");
    for (int i = 0; i < size; ++i)
        printf("%d ", *(arr + i));
    printf("\n");

    delete[] arr;
    return 0;
}