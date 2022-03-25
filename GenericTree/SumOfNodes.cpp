#include <iostream>
using namespace std;
template <typename T>
class TreeNode
{
    TreeNode<T> **children;
    int childCount;
    int maxChildCount;

public:
    T data;

    TreeNode(T data)
    {
        this->data = data;
        childCount = 0;
        children = new TreeNode<T> *[10];
        maxChildCount = 10;
    }

    int numChildren()
    {
        return childCount;
    }

    void addChild(TreeNode<T> *child)
    {
        children[childCount] = child;
        childCount++;
        if (childCount == maxChildCount)
        {
            TreeNode<T> **childrenNew = new TreeNode<T> *[2 * maxChildCount];
            for (int i = 0; i < maxChildCount; i++)
            {
                childrenNew[i] = children[i];
            }
            maxChildCount *= 2;
            children = childrenNew;
        }
    }

    TreeNode<T> *getChild(int index)
    {
        return children[index];
    }

    void setChild(int index, TreeNode<T> *child)
    {
        children[index] = child;
    }
};
int sumOfNodes(TreeNode<int> *root)
{
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    if(root==NULL){
        return 0;
    }
    int sum=root->data;
    for(int i=0; i<root->numChildren(); i++){
        sum+=sumOfNodes(root->getChild(i));
    }
    return sum;
}
int main()
{

    return 0;
}