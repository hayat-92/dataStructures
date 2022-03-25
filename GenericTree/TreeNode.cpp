#include <iostream>
using namespace std;
#include <vector>;

template <typename T>
class TreeNode
{
    public:
    T data;
    vector<TreeNode<T> *> *children;

// public:
    TreeNode(T data)
    {
        this->data = data;
        this->children = new vector<TreeNode<T> *>();
    }
};
int main()
{
    TreeNode<int> *root=new TreeNode<int>(4);
    TreeNode<int> *root1=new TreeNode<int>(2);
    TreeNode<int> *root2=new TreeNode<int>(3);
    TreeNode<int> *root3=new TreeNode<int>(5);
    TreeNode<int> *root4=new TreeNode<int>(6);

    root->children->push_back(root1);
    root->children->push_back(root2);
    root->children->push_back(root3);
    root->children->push_back(root4);

    cout<<root<<endl;

    return 0;
}