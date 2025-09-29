#include<iostream>
#include<string>
using namespace std;
int main()
{
    string pattern,seq;
    int pl,sl;bool flag;
    while(cin>>pattern>>seq)
    {
        flag=false;
        pl=pattern.length();sl=seq.length();
        int j=0;
        for(int i=0;i<sl;i++)
        {
            if(pattern[j]==seq[i])
            {
                j++;
                if(j==pl) 
                {
                    cout<<"Yes"<<endl;flag=true;break;
                }
            }
        }
        if(!flag) cout<<"No"<<endl;
    }
}