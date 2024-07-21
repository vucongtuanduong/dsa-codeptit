#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
    string s;
    cin>>s;
    int n;
    n=s.size();
    s='+'+s;
    int q;
    cin>>q;
    map<int,int> mp;
    while(q--)
    {
        int a;
        cin>>a;
        int la=n+1-a;


        mp[a]++;
        mp[la+1]--;
    }
    for(int i=1;i<=n;i++)
    {

        if(i==1)
        {
            if(mp[1]%2==0)
            {
                cout<<s[1];
            }
            else
            {
                cout<<s.back();
            }
        }
        else
        {
            mp[i]+=mp[i-1];
            if(mp[i]%2==0)
            {
                cout<<s[i];
            }
            else
            {
                cout<<s[n+1-i];
            }
        }
    }


    return 0;
}