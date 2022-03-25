#include <iostream>
#include<utility>
using namespace std;
template <typename T>
class TreeNode
{
    TreeNode<T> **children;
    int childCount;

public:
    T data;

    TreeNode(T data); // Constructor
    int numChildren();
    void addChild(TreeNode<T> *child);
    TreeNode<T> *getChild(int index);
    void setChild(int index, TreeNode<T> *child);
};

pair<TreeNode<int>*, int> helper(TreeNode<int>* root){
    int sum=0;
    sum+=root->data;
    for(int i=0; i<root->numChildren(); i++){
        sum+=root->getChild(i)->data;
    }
    int maxSum=sum;
    TreeNode<int>* maxNode=root;
    pair<TreeNode<int>*, int> fnl;
    for(int i=0; i<root->numChildren(); i++){
        pair<TreeNode<int>*, int> p=helper(root->getChild(i));
        if(p.second>maxSum){
            maxSum=p.second;
            maxNode=p.first;
        }
    }

    fnl.first=maxNode;
    fnl.second=maxSum;
    return fnl;

}

TreeNode<int>* maxSumNode(TreeNode<int> *root){
    // Write your code here
    pair<TreeNode<int>*, int> p=helper(root);
    return p.first;

}
int main()
{

    return 0;
}