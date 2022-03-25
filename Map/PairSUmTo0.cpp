#include <iostream>
#include <unordered_map>
using namespace std;
int pairSum(int *arr, int n)
{
    // Write your code here
    unordered_map<int, int> m;
    // for (int i = 0; i < n; i++)
    // {
    //     m[arr[i]]++;
    // }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (m.find(-arr[i]) != m.end())
        {
            // if (m[-arr[i]] > 0)
            // {
                // m[arr[i]]--;
                count += (m[-arr[i]]);
                
            // }
        }
        m[arr[i]]++;
    }

    return count;
}
int main()
{

    return 0;
}