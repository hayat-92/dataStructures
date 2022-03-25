#include <iostream>
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

TreeNode<int> *nextLargerElement(TreeNode<int> *root, int n)
{
    // Write your code here
    if(root==NULL){
        return NULL;
    }

    TreeNode<int> *max=NULL;
    if(root->data>n){
        max=root;
    }
    for(int i=0; i<root->numChildren(); i++){
        TreeNode<int> *val=nextLargerElement(root->getChild(i), n);
        if(val!=NULL){
            if(max!=NULL){
                if(val->data<max->data){
                    max=val;
                }
            }else{
                max=val; 
            }
        }
    }

    return max;
}
int main()
{

    return 0;
}