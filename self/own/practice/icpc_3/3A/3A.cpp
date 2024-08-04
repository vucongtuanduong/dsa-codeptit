#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dis(pair<ll, ll> a, pair<ll, ll> b) {
    ll tmp1 = a.first - b.first;
    ll tmp2 = a.second - b.second;
    return tmp1 * tmp1 + tmp2 * tmp2;
}

struct Da {
    int x;
    char c;
    int vsA;
    int vsB;
    ll cost;
    Da(int m, char n, int o, int p, ll q) {
        this->x = m;
        this->c = n;
        this->vsA = o;
        this->vsB = p;
        this->cost = q;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> a(n), b(m);
    for (auto &x : a) {
        cin >> x.first >> x.second;
    }
    for (auto &x : b) {
        cin >> x.first >> x.second;
    }

    ll res = LLONG_MAX;
    queue<Da> q;
    q.push(Da(0, 'A', 0, -1, 0));

    while (!q.empty()) {
        Da top = q.front();
        q.pop();

        int cur = top.x;
        char curc = top.c;
        int curA = top.vsA;
        int curB = top.vsB;
        ll cnt = top.cost;

        if (cur == n - 1 && curc == 'A' && curB == m - 1) {
            res = min(res, cnt);
        }

        if (curc == 'A') {
            if (curA < n - 1) {
                ll dist = dis(a[cur + 1], a[cur]);
                if (dist + cnt < res)
                    q.push(Da(cur + 1, 'A', cur + 1, curB, cnt + dist));
            }
            if (curB < m - 1) {
                ll dist = dis(a[cur], b[curB + 1]);
                if (dist + cnt < res)
                    q.push(Da(curB + 1, 'B', cur, curB + 1, cnt + dist));
            }
        } else {
            if (curB < m - 1) {
                ll dist = dis(b[cur], b[cur + 1]);
                if (dist + cnt < res)
                    q.push(Da(cur + 1, 'B', curA, cur + 1, cnt + dist));
            }
            if (curA < n - 1) {
                ll dist = dis(a[curA + 1], b[cur]);
                if (dist + cnt < res)
                    q.push(Da(curA + 1, 'A', curA + 1, cur, cnt + dist));
            }
        }
    }

    cout << res << endl;
    return 0;
}