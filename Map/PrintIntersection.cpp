#include <iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;
void intersection(int *arr1, int *arr2, int n, int m)
{
    // Write your code here
    unordered_map<int, int> mp;
    for(int i=0; i<m; i++){
        int val=arr2[i];
        mp[val]++;
    }

    sort(arr1, arr1+n);
    for(int i=0; i<n; i++){
        if(mp.find(arr1[i])!=mp.end()){
            if(mp[arr1[i]]>0){
                cout<<arr1[i]<<" ";
                mp[arr1[i]]--;
            }
        }
    }

}
int main()
{

    return 0;
}