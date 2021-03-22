#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int countTriplets(int *arr, int arrSize)
{
    int xor_1 = 0;
    int xor_2 = 0;
    int cnt = 0;
    for (int k = 0; k < arrSize; k++)
    {
        for (int i = k; i < arrSize; i++)
        {
            xor_1 ^= arr[i];
            xor_2 = 0;
            for (int j = i + 1; j < arrSize; j++)
            {
                xor_2 ^= arr[j];
                if (!(xor_1 ^ xor_2))
                {
                    ++cnt;
                }
            }
        }
        xor_1 = 0;
    }

    return cnt;
}
int main()
{
    int arr[9] = {7, 11, 12, 9, 5, 2, 7, 17, 22};
    printf("ans : %d \n", countTriplets(arr, 9));
}