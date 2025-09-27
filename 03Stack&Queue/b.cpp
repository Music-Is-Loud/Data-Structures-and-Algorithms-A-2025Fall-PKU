#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
int main()
{
    int n;cin>>n;
    vector<int> seq;
    vector<string> ans;
    stack<int> s;int temp;
    for(int i=0;i<n;i++)
    {
        cin>>temp;seq.push_back(temp);
    }
    int cur=1;//目前入栈的数
    for(int i=0;i<n;i++)
    {
        if(seq[i]<1 or seq[i]>n)//出栈的数
        {
            cout<<"NO"<<endl;
            return 0;
        }
        while(cur<=seq[i])//入栈到此数
        {
            s.push(cur);
            ans.push_back("PUSH "+to_string(cur));
            cur++;
        }
        if(s.empty()||s.top()!=seq[i])
        {cout<<"NO"<<endl;return 0;}
        s.pop();
        ans.push_back("POP "+to_string(seq[i]));
    }
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<endl;
    }
}