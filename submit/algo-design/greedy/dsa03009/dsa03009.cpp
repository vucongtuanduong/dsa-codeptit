#include <bits/stdc++.h>
using namespace std;
struct Job{
    int id;
    int deadline;
    int profit;
};
void testCase();
bool cmp(Job a, Job b);
pair<int, int> findMaxProfit(vector<Job> a, int n);
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
pair<int, int> findMaxProfit(vector<Job> a, int n) {
    vector<int> result(n);
    vector<bool> slot(n, false);
    int countJobs = 0, maxProfit = 0;
    for (int i = 0; i < n; i++) {
        for (int j = min(n, a[i].deadline) - 1; j >= 0; j--) {
            if (slot[j] == false) {
                result[j] = i;
                slot[j] = true;
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
    return a.profit > b.profit;
}
void testCase() {
    int n;
    cin >> n;
    vector<Job> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].id >> a[i].deadline >> a[i].profit;
    }
    sort(a.begin(), a.end(), cmp);
    pair<int, int> res = findMaxProfit(a, n);
    cout << res.first << " " << res.second;
}