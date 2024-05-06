#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        if (head == NULL) {
            return head;
        }
        head->next = removeNodes(head->next);
        if (head->next != NULL && head->val < head->next->val) {
            head = head->next;
        }
        return head;
    }
};
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
int main() {
    // Write your code here
    return 0;
}
