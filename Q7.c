#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
void caldiff(int *arr, char *c, int *size)
{
    // printf("ans : %d \n", arr[*c - 'a']);
    *size = ++arr[*c - 'a'] == 1 ? *size + 1 : *size;
}

int numSplits(char *s)
{
    int arr1[26];
    memset(arr1, 0, sizeof(int) * 26);
    int arr2[26];
    memset(arr2, 0, sizeof(int) * 26);
    int size_1 = 0;
    int size_2 = 0;

    int len;
    for (len = 0; s[len] != '\0'; ++len)
        ;

    int prefix[len];
    int suffix[len];
    memset(prefix, 0, len);
    memset(suffix, 0, len);

    for (int i = 0; i < len; i++)
    {
        caldiff(arr1, &s[i], &size_1);
        caldiff(arr2, &s[len - i - 1], &size_2);
        // printf("s is %c \t int is %d \t", s[i], (int)(s[i] - 'a'));
        // printf("size_1 : %d \n", size_1);
        // printf("s is %c \t int is %d \t", s[len - i - 1], (int)(s[len - i - 1] - 'a'));
        // printf("size_2 : %d \n", size_2);
        prefix[i] = size_1;
        suffix[len - i - 1] = size_2;
    }
    // printf("prefix \n");
    // for (int j = 0; j < len; j++)
    // {
    //     printf("i = %d \t value : %d \n", j, prefix[j]);
    // }
    // printf("suffix \n");
    // for (int j = 0; j < len; j++)
    // {
    //     printf("i = %d \t value : %d \n", j, suffix[j]);
    // }
    // printf("res \n");

    int res = 0;
    for (int i = 0; i < len - 1; i++)
    {
        // printf("pre value : %d \n", prefix[i]);
        // printf("suf value : %d \n", suffix[i]);

        res = prefix[i] == suffix[i + 1] ? res + 1 : res;
        printf("i = %d \t value : %d \n", i, res);
    }
    return res;
}

int main()
{
    char *s = "cacbacfhadcfecfbhgcahhcfcffehbgeagagfbhhacdfcadfgcghafcddcbcgbfhefaaadgchcdggdhehhbhfgehgaaehbabfddfebdbbdhfdefhdfebhacadbacbhafabefhdddbheacdggeeechdhffcedbgghadgbebhhgheggehddfhahchhfcdcfecbcccfbdbafahacdccgbfggfdcabchfabdbafacehedaafdgcceabghehhbabbhdacfdedbghbehgecheehcffacfeffdhdggcbfacbebdbahegfbbbfbefgbdbhgechagddgbaabaffcchedbccadbefhgbdddfcabhdgedbafadchcdfcgaeggbaccebghcafgcggdchgdgccdbaehehgfbdhgegacdgdbgedddaaehbfdcfdhdceaggabfbhdgbeaaefdaagffcfgeeeehgbcdghhbcagbfgehabdgefeeaffffacafecdbfcfafbgfggcbghcdcahbcbfdehbdfcgbbaafdbegbcecebdeeccddbgcddaacdgfcgdffefbfhcceeaeffacheabebccffaadfhecdhfbdcbgbaaahdhcfbaeghccdfeachfhehacaaefecdbbhadhgdcafhfdhcaggcdbhaffgabhcbdaabgfhchfdahcdbacehebgahdafbeghdacgeegafdabgcgfbaffaaaaeddebghbhfhedagaffgfehegahcbffhhehhghbcgfbbeedhcagdfffabecacgffgddbebdccbbafhahdbgbfgebfhbdfchaecehccaghahdcfechchbedghbghhabecadaddfffahcfhaaafdffhcccffddacgdehddehbfagfaccbfggcaeacg";
    numSplits(s);
    // while (*s)
    // {
    //     printf("s is %c \t int is %d \n", *s, (int)(*s - 'a'));
    //     s++;
    // }
}