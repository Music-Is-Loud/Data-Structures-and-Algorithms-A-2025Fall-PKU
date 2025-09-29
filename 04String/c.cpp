#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    int n;string s;vector<string>stu;
    string pattern;
    cin>>n;
    for(int ii=0;ii<n;ii++)
    {
        cin>>s;
        stu.push_back(s);
    }
    cin>>pattern;int i,j;string now;
    //cout<<1;
    for(int ii=0;ii<n;ii++)
    {
        i=0,j=0;
        now=stu[ii];
        int now_len=now.length();int p_len=pattern.length();bool flag=true;
        while(i<now_len&&j<p_len)
        {
            if(j>=p_len){flag=false;break;}
            if(pattern[j]!='[')
            {
                if(pattern[j]==now[i] or pattern[j]+32==now[i] or pattern[j]-32==now[i])
                {
                    i++;j++;
                } 
                else
                {
                    flag=false;break;   
                }
            }
            else
            {
                j++;
                while(pattern[j]!=']' and (!(pattern[j]==now[i] or pattern[j]+32==now[i] or pattern[j]-32==now[i])))
                {
                    j++;
                }
                if(pattern[j]==']')
                {
                    flag=false;break;
                }
                else
                {
                    while(pattern[j]!=']')j++;
                    i++;j++;
                }
            }
        }
        //cout<<i;
        if(flag&&i==now_len&&j==p_len)
        {
            cout<<ii+1<<" "<<now<<endl;

        }
    }

}