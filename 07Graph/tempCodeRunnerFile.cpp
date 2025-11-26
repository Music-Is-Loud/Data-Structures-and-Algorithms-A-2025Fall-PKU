//拓扑排序
#include<iostream>
#include<vector>   
using namespace std; 

int main()
{
    int v,a;int from,to;
    cin>>v>>a;
    vector<int> indegree(v); //入度数组
    vector<vector<int>> graph(v+2); //邻接表
    for(int i=0;i<a;i++)
    {
        cin>>from>>to;
        graph[from].push_back(to);
        indegree[to]++;
    }
    vector<int> result; //存储拓扑排序结果
    int left=v; //记录剩余节点数
    while(left)
    {
        bool found=false; //标记是否找到入度为0的节点
        for(int i=1;i<=v;i++)
        {
            if(indegree[i]==0) //找到入度为0的节点
            {
                result.push_back(i); //加入结果
                indegree[i]=-1; //标记为已处理
                for(int neighbor:graph[i]) //更新邻接节点的入度
                {
                    indegree[neighbor]--;
                }
                left--; //剩余节点数减1
                found=true;
                break; //重新开始寻找入度为0的节点
            }
        }
        if(!found) //如果没有找到入度为0的节点，说明有环
        {
            //cout<<"Circle."<<endl;
            return 0;
        }
    }
    for(int i=0;i<result.size();i++)
    {
        if(i) cout<<" ";
        cout<<"v"<<result[i];
    }
    return 0;
}