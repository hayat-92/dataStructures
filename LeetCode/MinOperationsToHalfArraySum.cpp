#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// class Solution
// {
// public:
    int halveArray(vector<int> &nums)
    {
        double *arr=new double[nums.size()];
        int n=nums.size();
        sort(arr, arr+n);
        
        double sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }
        double temp = sum;
        double halfSum = sum / 2.0;
        int count = 0;
        for (int i = n - 1; i >= 0;)
        {
            double val = arr[i];
            double x = temp;
            x -= val;
            val = val / 2.0;
            x = x + val;
            if (sum - x < halfSum)
            {
                temp = x;
                arr[i] = val;
                sort(arr, arr+n);
                for(int i=0; i<n; i++){
                    cout<<arr[i]<<" ";
                }
                cout<<endl;
                count++;
            }
            else
            {
                i--;
                continue;
            }
        }
        return count;
    }
// };
int main()
{

    vector<int> v={5,19,8,1};
    cout<<halveArray(v);


    return 0;
}