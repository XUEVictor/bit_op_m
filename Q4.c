#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *countBits_way1(int num, int *returnSize)
{
    printf("Size of int : %lu \n", sizeof(int));
    int *ans = (int *)malloc(sizeof(int) * num);
    for (int i = 0; i <= num; i++)
    {
        int cnt = 0;
        int temp = i;
        while (temp)
        {
            if (temp & 1)
                cnt++;
            temp >>= 1;
        }
        ans[i] = cnt;
        printf("i = %i , value = %d \n", i, cnt);
    }
    *returnSize = num + 1;
    return ans;
}

int *countBits(int num, int *returnSize)
{
    int *ans = (int *)malloc(sizeof(int) * (num + 1));
    memset(ans, 0, sizeof(num + 1));

    for (int i = 0; i <= num; i++)
    {
        ans[i] = i % 2 ? 1 + ans[i >> 1] : ans[i >> 1];
    }
    *returnSize = num + 1;
    return ans;
}
int main()
{
    int size;
    int *ans = countBits(5, &size);

    free(ans);

    for (int i = 0; i < size; i++)
    {
        printf("i = %i , value = %d \n", i, ans[i]);
    }
}