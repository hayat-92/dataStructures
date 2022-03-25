#include <iostream>
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

int helper(BinaryTreeNode<int>*root, int sum){
    if(root==NULL){
        return sum;
    }

    int Rsum=helper(root->right, sum);
    Rsum+=root->data;
    root->data=Rsum;
    int Lsum=helper(root->left, Rsum);
    return Lsum;
}

void replaceWithLargerNodesSum(BinaryTreeNode<int> *root)
{
    // Write your code here
    helper(root, 0);
}
int main()
{

    return 0;
}