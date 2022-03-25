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

void printAtK(TreeNode<int> *root, int k){
    if(k<0){
        return;
    }

    if(k==0){
        cout<<root->data<<endl;
        return;
    }

    for(int i=0; i<root->children.size(); i++){
        printAtK(root->children.at(i), k-1);
    }
}
int main()
{

    return 0;
}