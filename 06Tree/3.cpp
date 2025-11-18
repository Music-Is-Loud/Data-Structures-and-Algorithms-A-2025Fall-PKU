#include<iostream>
using namespace std;
int father[50005];
int find(int x)
{
    if(father[x]==x) return x;
    return father[x]=find(father[x]);
}
void Union(int x,int y)
{
    int fx=find(x);
    int fy=find(y);
    if(fx==fy) return;
    father[fx]=fy;
}
int main()
{
   int N,M;int T=0;
    while(cin>>N>>M)
    {
        if(N==0&&M==0) break;
        T++;
        for(int i=1;i<=N;i++) father[i]=i;
        for(int i=1;i<=M;i++)
        {
            int x,y;
            cin>>x>>y;
            Union(x,y);
        }
        int cnt=0;
        for(int i=1;i<=N;i++)
        {
            if(father[i]==i) cnt++;
        }
        cout<<"Case "<<T<<": "<<cnt<<endl;
    }
}