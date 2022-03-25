#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    bool divideArray(vector<int> &nums)
    {
        if (nums.size() % 2 != 0)
        {
            return false;
        }
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i += 2)
        {
            if (nums.at(i - 1) != nums.at(i))
            {
                return false;
            }
        }
        return true;
    }
};
int main()
{
    vector<int> nums = {1,2,3,4};
    // cout<<divideArray(nums);

        return 0;
}