#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void spilt(char *s, int *s_size, int i, char **res, int *r_size)
{
    if (i == *s_size)
    {
        char *temp = (char *)malloc(sizeof(char) * (*s_size));
        memset(temp, 0, (*s_size));
        printf("Size \t %d \t", *s_size);
        printf("tmep ptr is \t %p \n", temp);
        for (int i = 0; i < *s_size; i++)
        {
            temp[i] = s[i];
        }
        // temp = s;
        res[*r_size] = temp;
        printf("value of b_static: %s\t", res[*r_size]);

        *r_size = *r_size + 1;
        printf("r_size : %d \n", *r_size);
        return;
    }
    spilt(s, s_size, i + 1, res, r_size);
    if (isalpha(s[i]))
    {
        // toggle case
        s[i] ^= (1 << 5);
        spilt(s, s_size, i + 1, res, r_size);
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **letterCasePermutation(char *S, int *returnSize)
{
    int size;
    for (size = 0; S[size] != '\0'; ++size)
        ;

    printf("size : %d \n", size);
    *returnSize = 0;
    for (int i = 0; i < size; i++)
    {
        printf("S[%d] = %c \t", i, S[i]);
        *returnSize = isalpha(S[i]) ? *returnSize + 1 : *returnSize;
        printf("returnSize : %d\n", *returnSize);
    }
    *returnSize = *returnSize * 2;
    printf("returnSize : %d\n", *returnSize);
    char **output = (char **)malloc(sizeof(char *) * (*returnSize));
    memset(output, 0, (*returnSize));

    int r_s = 0;
    spilt(S, &size, 0, output, &r_s);
    for (int i = 0; i < *returnSize; i++)
    {
        printf("i = %i \t ans : %s \n", i, output[i]);
    }
    printf("Done\n");
    return output;
}

int main()
{
    char S[] = "a1b2";
    int size = 0;
    char **ans = letterCasePermutation(S, &size);
    for (int i = 0; i < size; i++)
    {
        printf("i = %i \t ans : %s \n", i, ans[i]);
    }
    free(ans);
}