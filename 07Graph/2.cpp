//floyd算法求两点间最短距离
#include <iostream>
#include <vector>
using namespace std;
const int INF = 1e9; 
string place[35]; //存放地点名称
int dist[35][35]; //存放两点间距离
int path[35][35]; //存放路径
int main()
{
    int p,q,r;
    cin>>p;
    for(int i=0;i<p;i++)
        cin>>place[i];
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<p;j++)
        {
            if(i==j)
            {
                dist[i][j]=0;
                path[i][j]=i;
            }   
            else
            {
                dist[i][j]=INF;
                path[i][j]=-1;
            }
        }
    }    
    cin>>q;
    string begin,end;int distance;
    for(int i=0;i<q;i++)
    {
        cin>>begin>>end>>distance;
        int u,v;
        for(u=0;u<p;u++)
            if(place[u]==begin)
                break;
        for(v=0;v<p;v++)
            if(place[v]==end)
                break;
        dist[u][v]=distance;
        path[u][v]=u;
        dist[v][u]=distance;
        path[v][u]=v;
    }

    for(int k=0;k<p;k++)
    {
        for(int i=0;i<p;i++)
        {
            for(int j=0;j<p;j++)
            {
                if(dist[i][j]>dist[i][k]+dist[k][j])
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                    path[i][j]=path[k][j];
                }
            }     
        }
    }
    cin>>r;
    
    for(int i=0;i<r;i++)
    {
        cin>>begin>>end;
        int u,v;
        for(u=0;u<p;u++)
            if(place[u]==begin)
                break;
        for(v=0;v<p;v++)
            if(place[v]==end)
                break;
        
        vector<int> route;
        if(dist[u][v]==INF) continue;
        else
        if(u==v)
        {
            cout<<place[u]<<endl;
            continue;
        }
        for(int k=v;k!=u;k=path[u][k])
        {
            route.push_back(k);
        }
        route.push_back(u);
        for(int j=route.size()-1;j>0;j--)
        {
            cout<<place[route[j]];
            cout<<"->";
            cout<<"("<<dist[route[j]][route[j-1]]<<")->";
        }
        cout<<place[v];
        cout<<endl;
    }
        
}
