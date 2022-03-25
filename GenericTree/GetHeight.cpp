#include <iostream>
#include<algorithm>
using namespace std;
template <typename T>
    class TreeNode {
     public:
        T data;
        vector<TreeNode<T>*> children;
    
        TreeNode(T data) {
            this->data = data;
        }
    
        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }
    };

int getHeight(TreeNode<int> *root)
{
    // Write your code here
    if(root==NULL){
        return 0;
    }
    int height=0;
    for(int i=0; i<root->children.size(); i++){
        height=max(height, getHeight(root->children[i]));
    }
    height++;
    return height;
}
int main()
{

    return 0;
}