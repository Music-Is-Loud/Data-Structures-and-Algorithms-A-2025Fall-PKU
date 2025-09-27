#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;
//stack<int>s;
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
string in_to_post(string str)
{
    stack<char> ops;
    string post="";
    int i=0;
    while(i<str.length())
    {
        if(str[i]>='0' and str[i]<='9')
        {
            string num="";
            while(str[i]>='0' and str[i]<='9')
            {
                num+=str[i];i++;
            }
            post+=num+" ";continue;
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
            while(!ops.empty()&&op_priority(ops.top())>=op_priority(str[i]))//必须保证当前操作符优先级<=栈顶优先级
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
    return post;
}
int ans(string post)
{
    stack<int> number;
    int i=0;
    int res=0;int val1,val2;
    while(i<post.length())
    {
        if(post[i]>='0' and post[i]<='9')
        {
            int num=0;
            while(post[i]>='0' and post[i]<='9')
            {
                num=num*10+post[i]-'0';i++;
            }
            number.push(num);
            continue;
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
int main()
{
    int n;string str;
    cin>>n;getchar();
    while(n--)
    {
        getline(cin,str);
        int result=ans(in_to_post(str));
        cout<<result<<endl;
    }
}