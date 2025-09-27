#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    string str,substr;char m;int n;
    while(cin>>str>>substr)
    {
        n=0;m=str[0];
        for(int i=1;i<str.length();i++)
        {
            if(str[i]>m) {m=str[i];n=i;}
        }
        str.insert(n+1,substr);
        cout<<str<<endl;
    }
}
