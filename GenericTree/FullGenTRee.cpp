#include <iostream>
#include<string>
using namespace std;
#include <vector>

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

TreeNode<int>* takeInput(){
    int n;
    cout<<"Enter next node data"<<endl;
    cin>>n;
    TreeNode<int>* root=new TreeNode<int>(n);
    cout<<"Enter number of children for "<<n<<endl;
    int childCount;
    cin>>childCount;
    for(int i=0; i<childCount; i++){
        TreeNode<int> *child=takeInput();
        root->children->push_back(child);
    }

    return root;
}

void print(TreeNode<int> *root){
    string s="";
    s+=to_string(root->data);
    s+=":";
    for(int i=0;i<(root->children->size()); i++){
        s=s+to_string(root->children->at(i)->data)+",";
    }

    cout<<s<<endl;
    for(int i=0; i<(root->children->size()); i++){
        print(root->children->at(i));
    }
}
int main()
{
    TreeNode<int> *N=takeInput();
    print(N);

    return 0;
}