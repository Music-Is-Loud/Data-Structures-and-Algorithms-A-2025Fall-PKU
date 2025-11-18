//带权的并查集（食物链简化版）
//https://zhuanlan.zhihu.com/p/540422718
#include <iostream>
using namespace std;
int father[100005],relation[100005];
//father[i]表示i的父亲，relation[i]表示i与father[i]的关系，0表示同类，1表示异类
int find(int x)//采用路径压缩找祖先，修改relation数组
{
    if(father[x]==x) return x;
    int temp=father[x];
    father[x]=find(father[x]);//更新父节点
    relation[x]=(relation[x]+relation[temp])%2;
    return father[x];
}
void Union(int x,int y)//r表示x与y的关系，0表示同类，1表示异类
{
    int fx=find(x);
    int fy=find(y);
    if(fx==fy) return;
    father[fx]=fy;
    relation[fx]=(1+relation[x]+relation[y])%2;//x与y异类
}   
int main()
{
    int T;
    cin>>T;int N,M;char op;int x,y;
    while(T--)
    {
        cin>>N>>M;
        for(int i=1;i<=N;i++)
        {
            father[i]=i;
            relation[i]=0;
        }
        for(int i=1;i<=M;i++)
        {
           //getchar();
           cin>>op>>x>>y;
           if(op=='D') Union(x,y);
           else
           {
               int fx=find(x);
               int fy=find(y);
               if(fx!=fy) cout<<"Not sure yet."<<endl;
               else
               {
                   if(relation[x]==relation[y]) cout<<"In the same gang."<<endl;
                   else cout<<"In different gangs."<<endl;
               }
           }
        }
    }
}