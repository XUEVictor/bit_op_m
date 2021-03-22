
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int *Prefix_sum_xor(int *arr, int arrSize)
{
    int *output = (int *)malloc(sizeof(int) * arrSize);
    memset(output, 0, arrSize);
    output[0] = arr[0];
    // printf("i = %d , value = %d\n", 0, output[0]);

    for (int i = 1; i < arrSize; i++)
    {
        output[i] = arr[i] ^ output[i - 1];
        // printf("i = %d , value = %d\n",   i, output[i]);
    }
    return output;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *xorQueries(int *arr, int arrSize, int **queries, int queriesSize, int *queriesColSize, int *returnSize)
{
    int *output = (int *)malloc(sizeof(int) * queriesSize);
    memset(output, 0, queriesSize);

    int *perfix_sum_arr = Prefix_sum_xor(arr, arrSize);
    for (int i = 0; i < queriesSize; i++)
    {
        output[i] = queries[i][0] ? perfix_sum_arr[queries[i][1]] ^ perfix_sum_arr[queries[i][0] - 1] : perfix_sum_arr[queries[i][1]];
    }

    *returnSize = queriesSize;

    return output;
}
int main()
{
    int query_num = 3;
    int input[1] = {16};
    int query_1[3] = {0, 0, 0};
    int query_2[3] = {0, 0, 0};
    int return_size;
    int **query = (int **)malloc(sizeof(int *) * query_num);
    memset(query, 0, query_num);

    for (int i = 0; i < 3; i++)
    {
        query[i] = (int *)malloc(sizeof(int) * 2);
        memset(query[i], 0, 2);

        query[i][0] = query_1[i];
        query[i][1] = query_2[i];
    }
    int *output = xorQueries(input, 1, query, 3, &query_num, &return_size);

    for (int i = 0; i < return_size; i++)
    {
        printf("i = %d result %d \n", i, output[i]);
    }
    free(output);
    for (int i = 0; i < 3; i++)
    {
        free(query[i]);
    }
    free(query);
}