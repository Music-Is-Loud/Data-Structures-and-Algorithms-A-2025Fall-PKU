//模版题！滑动窗口：给定区间长度算最值
//核心思想：老而劣的元素不可能成为最值
//算法（以求最大值为例）
//从队尾踢掉之前比他小的元素（这些元素又老又劣）再入队，队头移除已经离开的数，队头即最大值
//用双端队列，vector erase时间复杂度O(n)
#include<iostream>
#include<queue>
#include<deque>
#include<vector>
using namespace std;
int main()
{
    int n,k,num;cin>>n>>k;
    deque<int> qmin;deque<int> qmax;
    vector<int>a;
    vector<int> ansmin;vector<int> ansmax;
    for(int i=0;i<n;i++)
    {
        cin>>num;a.push_back(num);
    }
    qmin.push_back(0);qmax.push_back(0);
    
    for(int i=0;i<n;i++)
    {
        if(qmin.front()==i-k) qmin.pop_front();//移出窗口的数
        if(qmax.front()==i-k) qmax.pop_front();//移出窗口的数
        while(!qmin.empty()&&a[qmin.back()]>=a[i])
        {
            qmin.pop_back();
        }
        qmin.push_back(i);
        while(!qmax.empty()&&a[qmax.back()]<=a[i])
        {
            qmax.pop_back();
        }
        qmax.push_back(i);
        if(i>=k-1)
        {
            ansmax.push_back(a[qmax.front()]);
            ansmin.push_back(a[qmin.front()]);
        }
    }
    
    for(int i=0;i<ansmin.size();i++)
    {
        cout<<ansmin[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<ansmax.size();i++)
    {
        cout<<ansmax[i]<<" ";
    }
    cout<<endl;
}