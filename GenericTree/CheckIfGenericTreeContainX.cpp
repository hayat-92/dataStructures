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
bool containsX(TreeNode<int> *root, int x)
{
    // Write your code here
    if(root==NULL){
        return false;
    }

    if(root->data==x){
        return true;
    }

    for(int i=0; i<root->numChildren(); i++){
        bool val=containsX(root->getChild(i), x);
        if(val){
            return val;
        }
    }

    return false;
}
int main()
{

    return 0;
}