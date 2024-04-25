#include <bits/stdc++.h>
using namespace std;

struct Job{
    int id;
    int deadline;
    int profit;
};
vector<Job> a;
int n;
void testCase();
bool cmp(Job a, Job b);
pair<int,int> solve();
int main() {
    // Write your code here
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
pair<int,int> solve() {
    vector<bool> isSchedule(n, false);
    int countJobs = 0, maxProfit = 0;
    for (int i = 0; i < n; i++) {
        for (int j = min(n, a[i].deadline) - 1; j >= 0; j--) {
            if (!isSchedule[j]) {
                isSchedule[j] = true;
                countJobs++;
                maxProfit += a[i].profit;
                break;
            }
        }
    }
    return make_pair(countJobs, maxProfit);
}
bool cmp(Job a, Job b) {
    if (a.profit == b.profit) {
        return a.deadline > b.deadline;
    }
    return a.profit  > b.profit;
}
void testCase() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].id >> a[i].deadline >> a[i].profit;
    }
    sort(a.begin(), a.end(), cmp);
    pair<int, int> ans = solve();
    cout << ans.first << " " << ans.second;
}