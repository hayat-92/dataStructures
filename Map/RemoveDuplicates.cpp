#include <iostream>
#include<map>
#include<vector>
using namespace std;

vector<int>* removeDuplicates(int *arr, int n){
    vector<int> *output=new vector<int>();
    map<int, bool> m;
    for(int i=0; i<n; i++){
        if(m.find(arr[i])!=m.end()){
            continue;
        }

        output->push_back(arr[i]);
        m.insert({arr[i], true});
    }
    return output;
}

int main()
{

    int arr[]={1, 3, 2, 2, 3, 1, 6, 2, 5};
    vector<int>* output=removeDuplicates(arr, 9);
    for(int i=0; i<output->size(); i++){
        cout<<output->at(i)<<" ";
    }

    return 0;
}