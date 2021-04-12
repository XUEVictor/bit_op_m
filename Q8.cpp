#include <iostream>
#include <vector>
using namespace std;
void printResult(vector<vector<int> > &nums)
{
    cout << "-------------------\n";

    for (vector<int> vec : nums)
    {
        for (int i : vec)
        {
            cout << i << "  ";
        }
        cout << "\n";
    }
}
vector<vector<int> > subsets(vector<int> &nums)
{
    vector<vector<int> > result = {{}};

    for (int num : nums)
    {
        int len = result.size();
        printf("Len : %d \n", len);
        for (int i = 0; i < len; i++)
        {

            result.push_back(result[i]);
            // 把目前數字放進最後一個矩陣內
            result.back().push_back(num);
            printResult(result);
        }
    }
    return result;
}

int main()
{
    vector<int> vect;
    vect.push_back(1);
    vect.push_back(2);
    vect.push_back(3);
    subsets(vect);
}