#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct Node 
{
    char val;Node* left;Node* right;
    int level;
    Node(char v,int l):val(v),left(NULL),right(NULL),level(l){}
};
void printTree(Node* root,bool if_pre,bool if_in,bool if_post)
{
    if(!root) return;
    if(if_pre&&root->val!='*') cout<<root->val;;
    printTree(root->left,if_pre,if_in,if_post);
    if(if_in&&root->val!='*') cout<<root->val;
    printTree(root->right,if_pre,if_in,if_post);
    if(if_post&&root->val!='*') cout<<root->val;
}
int main()
{
    int N;cin>>N;
    string input;
    Node* root=NULL;
    while(N--)
    {
        vector<Node*> nodes;//值，
        root=NULL;//getchar();

        while(cin>>input)
        {
            if(input=="0") break;
            //getchar();
            int level=0;
            for(int i=0;i<input.length();i++)
            {
                if(input[i]=='-') level++;
                else
                {
                    nodes.push_back(new Node(input[i],level));
                    for(int j=nodes.size()-2;j>=0;j--)
                    {
                        if(nodes[j]->level==level-1)
                        {
                            if(!nodes[j]->left) nodes[j]->left=nodes.back();
                            else nodes[j]->right=nodes.back();
                            break;
                        }
                    }
                }
            }
            
        }
        root=nodes[0];
        printTree(root,1,0,0);
        cout<<endl;
        printTree(root,0,0,1);
        cout<<endl;
        printTree(root,0,1,0);
        cout<<endl;
        cout<<endl;
    }
}
