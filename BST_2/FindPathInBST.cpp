#include <iostream>
#include <vector>
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

vector<int> *getPath(BinaryTreeNode<int> *root, int data)
{
    // Write your code here
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == data)
    {
        vector<int> *v=new vector<int>();
        v->push_back(data);
        return v;
    }

    if (root->data < data)
    {
        vector<int> *output = getPath(root->right, data);
        if (output != NULL)
        {
            output->push_back(root->data);
        }
        return output;
    }
    else
    {
        vector<int> *output = getPath(root->left, data);
        if (output != NULL)
        {
            output->push_back(root->data);
        }
        return output;
    }
}
int main()
{

    return 0;
}