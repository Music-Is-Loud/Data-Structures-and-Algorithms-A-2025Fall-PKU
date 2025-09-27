#include<iostream>
#include<map>
using namespace std;
int main()
{
    int n;int x,exp;bool have;
    cin>>n;
    while(n--)
    {
        have=false;
        map<int,int,greater<int>>poly;//系数 幂次
        while(cin>>x>>exp)
        {
            if(exp<0) break;
            poly[exp]+=x;
        }
        while(cin>>x>>exp)
        {
            if(exp<0) break;
            poly[exp]+=x;
        }
        for(auto it=poly.begin();it!=poly.end();it++)
        {
            if(it->second!=0)
            {
                if(!have)
                {
                    cout<<"[ "<<it->second<<" "<<it->first<<" ]";
                    have=true;
                }
                else
                {
                    cout<<" [ "<<it->second<<" "<<it->first<<" ]";
                }
            }

        }
        cout<<endl;

    }
}