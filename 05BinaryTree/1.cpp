#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
unordered_map<int,int> inMap;//能够在中序访问时根据数据定义位置
vector<int> inorder,postorder;
struct Node{
    int data;Node* left;Node* right;
    Node(int val){
        data=val;left=NULL;right=NULL;
    }
};
Node* buildTree(int inStart,int inEnd,int postStart,int postEnd){
    if(inStart>inEnd || postStart>postEnd|| postStart<0 || postEnd<0) return NULL;
    int rootVal=postorder[postEnd];//后序遍历的最后一个节点是根节点
    Node* root=new Node(rootVal);//创建根节点
    int inIndex=inMap[rootVal];//在中序遍历中找到根节点的位置
    //递归构建右子树和左子树
    int leftTreeSize=inIndex-inStart;
    int rightTreeSize=inEnd-inIndex;
    root->right=buildTree(inIndex+1,inEnd,postStart+leftTreeSize,postEnd-1);
    root->left=buildTree(inStart,inIndex-1,postStart,postStart+leftTreeSize-1);
    return root;
}
void coutPreorder(Node* root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    coutPreorder(root->left);
    coutPreorder(root->right);
}
int main()
{
    int x;int treeSize=0;
    while(cin.peek()!='\n'&&cin>>x){
        inorder.push_back(x);
        treeSize++;
    }
    cin.clear();
    cin.ignore(); 
    for(int i=0;i<treeSize;i++){
        cin>>x;
        postorder.push_back(x);
    }
    for(int i=0;i<inorder.size();i++){
        inMap[inorder[i]]=i;
    }
    Node* root=buildTree(0,inorder.size()-1,0,postorder.size()-1);
    coutPreorder(root);
    return 0;
}
    