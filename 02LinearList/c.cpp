#include<iostream>
using namespace std;
int a[40][40]={};
int main()
{
    int n;cin>>n;
    a[0][n-1]=1;
    int last_x=0,last_y=n-1;int now_x,now_y,now_num=2;
    int count=(2*n-1)*(2*n-1)-1;
    while(count--)
    {
        if(last_x==0&&last_y==2*n-2) 
        {
            now_x=1;now_y=last_y;
        }
        else
        {
            if(last_x==0) now_x=2*n-2;
            else now_x=last_x-1;
            if(last_y==2*n-2) now_y=0;
            else now_y=last_y+1;
            if(a[now_x][now_y]!=0)
            {
                now_x=last_x+1;now_y=last_y;
            }
        }
        
        a[now_x][now_y]=now_num;
        last_x=now_x;last_y=now_y;now_num++;
        //cout<<"*"<<last_x<<last_y<<now_num<<endl;
    }
    for(int i=0;i<2*n-1;i++)
    {
        for(int j=0;j<2*n-1;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}