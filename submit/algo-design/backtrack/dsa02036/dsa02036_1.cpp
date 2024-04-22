#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, a[101], b[101];
bool ok;

void khoitao()
{
    for(int i = 1; i <= n; i++) a[i] = 0;
}

void sinh()
{
    int i = n;
    while(i >= 1 && a[i])
    {
        a[i] = 0;
        i--;
    }
    if(i == 0) ok = 0;
    else a[i] = 1;
}

bool check()
{
    int sum = 0;
    for(int i = 1; i <= n; i++)
    {
        if(a[i])
        {
            sum += b[i];
        }
    }
    return sum % 2 == 1;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        khoitao();
        for(int i = 1; i <= n; i++) cin >> b[i];
        sort(b + 1, b + n + 1, greater<int>());
        ok = 1;
        vector<string> v;
        while(ok)
        {
            if(check())
            {
                // string tmp = "";
                // for(int i = 1; i <= n; i++)
                // {
                //     if(a[i]) tmp += (to_string(b[i]) + " ");
                // }
                // v.push_back(tmp);
                for (int i = 1; i <= n; i++) {
                    if (a[i]) {
                        cout << b[i] << " ";
                    }
                }
                cout << endl;
            }
            sinh();
        }
        sort(v.begin(), v.end());
        for(auto it: v) cout << it << endl;
    }
    return 0;
}
