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
bool isIdentical(TreeNode<int> *root1, TreeNode<int> *root2)
{
    // Write your code here
    if (root1 == NULL || root2 == NULL)
    {
        return true;
    }
    if ((root1 == NULL && root2 != NULL) || (root1 != NULL && root2 == NULL))
    {
        return false;
    }

    if ((root1->data) != (root2->data) || root1->numChildren() != root2->numChildren())
    {
        return false;
    }

    int i = 0;
    while (i < root1->numChildren())
    {
        if (isIdentical(root1->getChild(i), root2->getChild(i)))
        {
            i++;
        }else{
            return false;
        }
    }

    return true;
}
int main()
{

    return 0;
}