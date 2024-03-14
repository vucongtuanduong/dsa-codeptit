## dsa01015
![alt text](image.png)
## Approach
**Problem Analysis:**

Given an integer N, your task is to find the smallest integer X that is a multiple of N, and X contains only the digits 0 and 9.

**Solution Analysis:**

This problem can be solved using a breadth-first search (BFS) approach. The idea is to consider each number as a node in a graph, where the two children of a node X are the numbers formed by appending a 0 or a 9 to X. We start from the node 9 and perform a BFS until we find a node that is a multiple of N.

The algorithm to solve this problem can be described as follows:

1. Initialize a queue and push the number 9 into it.

2. While the queue is not empty, pop the front number X from the queue. If X is a multiple of N, return X as the answer. Otherwise, push the numbers formed by appending a 0 and a 9 to X into the queue.

**Implementation in C++:**

```cpp
#include <bits/stdc++.h>
using namespace std;

string bfs(int n) {
    queue<string> q;
    set<int> visit;

    string t = "9";
    q.push(t);

    while (!q.empty()) {
        t = q.front(); q.pop();

        int rem = stoi(t) % n;
        if (rem == 0)
            return t;

        if(visit.find(rem) == visit.end()) {
            visit.insert(rem);
            q.push(t + "0");
            q.push(t + "9");
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        cout << bfs(N) << endl;
    }
    return 0;
}
```

**Time Complexity Analysis:**

The time complexity of the algorithm is O(N), as in the worst case we may have to visit all numbers from 1 to N. The space complexity of the algorithm is also O(N), as we are using a queue and a set to keep track of the visited numbers. This is efficient enough for the given problem constraints (1 ≤ N ≤ 500).

## RTE
The runtime error might be due to the use of `stoi(t)`. If the string `t` becomes too large, it might not fit into an integer and `stoi(t)` will throw an out_of_range exception. To fix this, we can calculate the remainder of a number represented as a string with respect to `n` using a function.

Here is the corrected code:

```cpp
#include <bits/stdc++.h>
using namespace std;

int remainder(string t, int n) {
    int rem = 0;
    for (int i = 0; i < t.size(); i++)
        rem = (rem*10 + (t[i]-'0')) % n;
    return rem;
}

string bfs(int n) {
    queue<string> q;
    set<int> visit;

    string t = "9";
    q.push(t);

    while (!q.empty()) {
        t = q.front(); q.pop();

        int rem = remainder(t, n);
        if (rem == 0)
            return t;

        if(visit.find(rem) == visit.end()) {
            visit.insert(rem);
            q.push(t + "0");
            q.push(t + "9");
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        cout << bfs(N) << endl;
    }
    return 0;
}
```

This code should now work correctly without any runtime errors.