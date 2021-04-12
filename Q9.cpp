#include <iostream>
#include <vector>
using namespace std;
vector<int> singleNumber(vector<int> &nums)
{
    vector<int> rst;
    int a = 0;
    int b = 0;
    uint32_t axorb = 0;

    for (int i : nums)
        axorb ^= i;
    printf("a & b = %d\n", axorb);
    //找出兩個不一樣的bit的第一個位置
    uint32_t mask = axorb & ~(axorb - 1);

    for (int i : nums)
    {
        if (i & mask)
            a ^= i;

        else
            b ^= i;
    }
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    rst.push_back(a);
    rst.push_back(b);
    return rst;
}
int main()
{
    vector<int> nums = {1, 2, 1, 3, 2, 5};

    singleNumber(nums);
}