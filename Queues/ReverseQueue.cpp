#include<iostream>
#include<queue>
using namespace std;

void reverseQueue(queue<int> &input) {
	// Write your code here
    if(input.empty()){
        return;
    }
    int val=input.front();
    input.pop();
    reverseQueue(input);
    input.push(val);
}