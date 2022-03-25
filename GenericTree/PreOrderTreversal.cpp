#include <iostream>
#include<vector>
using namespace std;
template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;

    TreeNode(T data)
    {
        this->data = data;
    }

    ~TreeNode()
    {
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }
};

void preOrder(TreeNode<int> *root){
    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    for(int i=0; i<root->children.size(); i++){
        preOrder(root->children.at(i));
    }
}
int main()
{

    return 0;
}