void reverseArray(int arr[], int size)
{
    int left = 0, right = size - 1;
    while (left < right)
    {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        ++left;
        --right;
    }
}

void ptr_reverseArray(int *arr, int size)
{
    int left = 0, right = size - 1;
    while (left < right)
    {
        int temp = *(arr + left);
        *(arr + left) = *(arr + right);
        *(arr + right) = temp;
        ++left;
        --right;
    }
}
