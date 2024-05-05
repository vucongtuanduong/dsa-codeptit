#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
int main() {
    // Write your code here
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        ListNode *node_list  = new ListNode;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            insertTail(node_list);
        }
        Solution h;
        h.deleteNode(x);
        printNode()
    }
    return 0;
}
