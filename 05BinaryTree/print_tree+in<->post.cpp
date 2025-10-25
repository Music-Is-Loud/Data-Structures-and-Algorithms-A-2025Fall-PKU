#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<map>
#include <functional>
using namespace std;
struct Node {
    char val;Node* left;Node* right;
    Node(char x):val(x),left(NULL),right(NULL){}
};
int word_to_num[27]={0};//存储每个小写字母代表的变量值
int op_priority(char op)
{
    if(op=='+' or op=='-') return 1;
    if(op=='*' or op=='/')return 2;
    else return 0;//"("优先级最低
}
int cal(int a,int b,char op)
{
    if(op=='+') return a+b;
    if(op=='-') return a-b;
    if(op=='*') return a*b;
    else return a/b;
}
string in_to_post(string str)//中缀表达式转后缀表达式
{
    //cout<<"In to Post!"<<endl;
    stack<char> ops;
    string post="";
    int i=0;
    while(i<str.length())
    {
        //cout<<"Processing "<<str[i]<<endl;
        if(str[i]>='a' and str[i]<='z')
        {
            post+=str[i];
            post+=" ";
        }
        else if(str[i]=='(')
        {
            ops.push('(');
        }
        else if(str[i]==')')
        {
            while(!ops.empty()&&ops.top()!='(')
            {
                post+=ops.top();post+=" ";
                ops.pop();
            }
            ops.pop();
        }
        else
        {
            while(!ops.empty()&&op_priority(ops.top())>=op_priority(str[i]))//必须保证当前操作符优先级<最终栈顶优先级才能继续操作
            {
                post+=ops.top();post+=" ";
                ops.pop();
            }
            ops.push(str[i]);
        }
        i++;
    }
    while(!ops.empty())
    {
        post+=ops.top();ops.pop();post+=" ";
    }
    if(post.back()==' ') post.pop_back();
    return post;
}
int ans(string post)//计算后缀表达式的值
{
    stack<int> number;
    int i=0;
    int res=0;int val1,val2;
    while(i<post.length())
    {
        if(post[i]>='a' and post[i]<='z')
        {
            number.push(word_to_num[post[i]-'a']);
            i++;
        }
        else if(post[i]!=' ')
        {
            val1=number.top();number.pop();
            val2=number.top();number.pop();
            res=cal(val2,val1,post[i]);
            number.push(res);
            i++;
        }
        else
        {
            i++;
        }
    }
    res=number.top();
    return res;
}
Node* build_tree(string post)//根据后缀表达式建立表达式树
{
    stack<Node*> nodes;
    int i=0;
    Node* node;Node* left;Node* right;
    while(i<post.length())
    {
        if(post[i]>='a' and post[i]<='z')
        {
            node=new Node(post[i]);
            nodes.push(node);
            i++;
        }
        else if(post[i]!=' ')
        {
            node=new Node(post[i]);
            right=nodes.top();nodes.pop();
            left=nodes.top();nodes.pop();
            node->left=left;
            node->right=right;
            nodes.push(node);
            i++;
        }
        else
        {
            i++;
        }
    }
    return nodes.top();
}
int get_height(Node* root)//获取表达式树高度,叶子节点高度为1
{
    if(root==NULL) return 0;
    return max(get_height(root->left),get_height(root->right))+1;
}
void printTree(Node* root)//打印表达式树
{
    if(root==NULL) return;
    int height=get_height(root);
    int max_width=(1<<height);//底层最大宽度
    vector<string> line_output(2*height-1,string(max_width,' '));//每行输出
    function<void(Node*,int,int,int)> fill=[&](Node* node,int level,int left,int right)
    {
        if(node==NULL) return;
        int mid=(left+right)/2;
        line_output[2*level][mid]=node->val;
        fill(node->left,level+1,left,mid-1);
        fill(node->right,level+1,mid+1,right);
        if(node->left)
        {
            line_output[2*level+1][mid-1]='/';
        }
        if(node->right)
        {
            line_output[2*level+1][mid+1]='\\';
        }
    };
    fill(root,0,0,max_width-1);
    for(auto& line:line_output)
    {
       int last_char_index=line.find_last_not_of(' ');
        if (last_char_index!=string::npos) {
            cout<<line.substr(0,last_char_index+1);
            //cout<<"End!";
            cout<<endl;
        }
    }

}
int main()
{
    string str;int n;
    char word;int x;
    cin>>str;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>word>>x;
        word_to_num[word-'a']=x;    
    }
    string post=in_to_post(str);
    for(int i=0;i<post.length();i++)
    {
        if(post[i]!=' ')cout<<post[i];
    }
    cout<<endl;
    int result=ans(post);
    Node* root=build_tree(post);
    printTree(root);
    cout<<result<<endl;
    return 0;
}