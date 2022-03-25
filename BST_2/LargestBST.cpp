#include <iostream>
#include <algorithm>
using namespace std;
template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
struct BSTNode
{
    int max;
    int min;
    int maxHeight;
    bool isBST;
};

BSTNode helper(BinaryTreeNode<int> *root)
{
    if(root==NULL){
        BSTNode ans;
        ans.max=INT_MIN;
        ans.min=INT_MAX;
        ans.isBST=true;
        ans.maxHeight=0;
        return ans;
    }

    BSTNode left=helper(root->left);
    BSTNode right=helper(root->right);

    if(!(right.isBST && right.min>root->data)){
        right.isBST=false;
    }

    if(!(left.isBST && left.max< root->data)){
        left.isBST=false;
    }

    BSTNode ans;

    if(!left.isBST || !right.isBST || root->data<left.max || root->data>right.min){
        if(left.maxHeight>right.maxHeight){
            left.isBST=false;
            return left;
        }else{
            right.isBST=false;
            return right;
        }
    }

    ans.isBST=true;
    ans.min=min(left.min, min(right.min, root->data));
    ans.max=max(left.max, max(right.max, root->data));
    ans.maxHeight=max(left.maxHeight, right.maxHeight)+1;

    return ans;
    
}
int largestBSTSubtree(BinaryTreeNode<int> *root)
{
    // Write your code here
    return helper(root).maxHeight;
}
int main()
{

    return 0;
}