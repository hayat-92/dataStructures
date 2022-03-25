#include <iostream>
#include<string>
#include<queue>
using namespace std;

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

TreeNode<int>* takeInputLevelWise(){
    cout<<"Enter root data"<<endl;
    int rootData;
    cin>>rootData;
    queue<TreeNode<int>*> *pendingNodes=new queue<TreeNode<int>*>();
    TreeNode<int> *root=new TreeNode<int>(rootData);
    pendingNodes->push(root);
    while(!pendingNodes->empty()){
        TreeNode<int> *frontNode=pendingNodes->front();
        pendingNodes->pop();
        cout<<"Enter num of children of "<<frontNode->data<<endl;
        int numChildren;
        cin>>numChildren;
        for(int i=0; i<numChildren; i++){
            cout<<"Enter "<<(i+1)<<" child of "<<frontNode->data<<endl;
            int child;
            cin>>child;
            TreeNode<int> *childNode=new TreeNode<int>(child);
            frontNode->children->push_back(childNode);
            pendingNodes->push(childNode);
        }
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

    TreeNode<int> *root=takeInputLevelWise();
    print(root);


    return 0;
}