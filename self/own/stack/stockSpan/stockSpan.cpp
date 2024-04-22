#include <bits/stdc++.h>
using namespace std;
/*
Write a class StockSpanner which collects daily price quotes for some stock, and returns the span of that stock's price for the current day.

The span of the stock's price today is defined as the maximum number of consecutive days (starting from today and going backwards) for which the price of the stock was less than or equal to today's price.

For example, if the price of a stock over the next 7 days were [100, 80, 60, 70, 60, 75, 85], then the stock spans would be [1, 1, 1, 2, 1, 4, 6].
*/
void stockSpan(int *price, int n, int *span) {
    stack<int> st;//indices of the days
    st.push(0);
    span[0] = 1;
    for (int i = 1; i <= n - 1; i ++) {
        int currentPrice = price[i];
        while (!st.empty() && price[st.top()] <= currentPrice) {
            st.pop();
        }
        if (!st.empty()) {
            int prev_highest = st.top();
            span[i] = i - prev_highest;
        } else {
            span[i] = i + 1;
        }
        //push this element into the stack
        st.push(i);

    }
}
int main() {
    // Write your code here
    int n;
    cin >> n;
    int price[n];
    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }
    int span[10000] = {0};
    stockSpan(price, n, span);
    for (int i = 0; i < n; i++) {
        cout << span[i] << " ";
    }
    cout << endl;
    return 0;
}
