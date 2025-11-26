//用kruskal算法求最小生成树
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <pair<int, pair<int, int>>> edges; //存储边及其权
int parent[100]; //并查集数组
int find(int x) { //查找根节点
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}
void unionSet(int x, int y) { //合并两个集合
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        parent[rootY] = rootX;
    }
}
bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
    return a.first < b.first; //按权值升序排序
}
int n;
int main()
{
    cin>>n;
    char c;int k;char d;int w;
    for(int i=0;i<n-1;i++)
    {
        cin>>c>>k;
        for(int j=0;j<k;j++)
        {
            cin>>d>>w;
            edges.push_back({w,{c-'A',d-'A'}});
        }
    }
    //初始化并查集
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
    }
    //按权值排序边
    sort(edges.begin(),edges.end(),cmp);
    int mst_weight=0; //最小生成树的总权值
    for(auto edge:edges)
    {
        int weight=edge.first;
        int u=edge.second.first;
        int v=edge.second.second;
        //判断是否形成环
        if(find(u)!=find(v))
        {
            unionSet(u,v);
            mst_weight+=weight;
        }
    }
    cout << mst_weight << endl;
}