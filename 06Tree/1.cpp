#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> children;//chidren[i]是节点i的孩子节点列表
vector<int> parent;//parent[i]是节点i的父节点
vector<int> Lchildren,Rsib;//Lchildren[i]是节点i的左孩子，Rson[i]是节点i的右兄弟
int n;//节点总数
int tree_height(int root)
{
    if(children[root].empty()) return 0;//叶子节点高度为1
    int max_height = 0;
    for(int child : children[root])
    {
        max_height = max(max_height, tree_height(child));
    }
    return max_height+1;
}
//将普通树转换为左孩子右兄弟表示法
void build_LRTree(int root)
{
    //每次处理一个节点的孩子节点：连上自己的左孩子，连上孩子的右兄弟
    if(children[root].empty()) return;//叶子节点没有孩子
    Lchildren[root] = children[root][0];//第一个孩子是左孩子
    for(int i=0;i<children[root].size()-1;i++)
    {
        int child = children[root][i];
        Rsib[child] = children[root][i+1];//连上右兄弟
    }
    for(int child : children[root])
    {
        build_LRTree(child);//递归处理每个孩子节点
    }
}

int height_LRTree(int root)
{
    if(root==-1) return -1;//空节点高度为-1
    return 1+(max(height_LRTree(Lchildren[root]), height_LRTree(Rsib[root])));
}
int main()
{
    string s;int cur_root;
    int nxt;int T=0;
    while(cin>>s)
    {
        if(s=="#")  break;
        T++;
        children.clear();
        parent.clear();
        children.resize(10005);
        parent.resize(10005,-1);
        cur_root=0;
        n=1;
        for(char c : s)
        {
            if(c=='d')
            {
                n++;
                nxt=n;
                children[cur_root].push_back(nxt);
                parent[nxt]=cur_root;
                cur_root=nxt;
            }
            else if(c=='u')
            {
                cur_root=parent[cur_root];
            }
        }
        int h1=tree_height(0);
        Lchildren.clear();
        Rsib.clear();
        Lchildren.resize(n+1,-1);
        Rsib.resize(n+1,-1);
        build_LRTree(0);
        int h2=height_LRTree(0);
        cout<<"Tree "<<T<<": "<<h1<<" => "<<h2<<endl;
    }
}