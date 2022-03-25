#include <iostream>
#include<map>
using namespace std;
int highestFrequency(int arr[], int n) {
    // Write your code here
    map<int, int> m;
    for(int i=0; i<n; i++){
        m[arr[i]]++;
    }

    int maxVal=0;
    int maxFreq=0;
    for(auto val:m){
        if(val.second>maxFreq){
            maxVal=val.first;
        }
    }

    return maxVal;
}
int main()
{

    return 0;
}