#include<iostream>
#include<vector>
//#include<bits/stdc++.h>
//next数组模版题
//思路：寻找最大相同前缀和后缀（不包括全串）例如ababab->abab 
//那么未被前缀覆盖的剩下来部分就是循环节（因为必然是后缀的一部分）或者根本就无法循环abab cdef abab
using namespace std;
int main()
{
    char s[1000005];
    int fix,cycle;
    while(scanf("%s",s))
    {
        if(s[0]=='.') break;
        fix=0;
        int len=strlen(s);
        vector<int> next(len+1);
        next[0]=-1;
        int k=-1,i=0;
        while(i<len)
        {   
            while(k>=0 and s[k]!=s[i])
                k=next[k];
            i++;k++;
            next[i]=k;
        }
       /*for(int i=0;i<=len;i++)
        {
            printf("%d ",next[i]);
        }
        printf("\n");*/
        cycle=len-next[len];//printf("%d\n",next[len]);
        if(len%cycle==0) printf("%d\n",len/cycle);
        else printf("%d\n",1);
    }
}