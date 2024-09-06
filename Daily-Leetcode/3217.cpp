/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <unordered_set>
#include <stack>

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> set(nums.begin(), nums.end());
        stack<ListNode*> stk;
        ListNode* current = head;

        while (current != nullptr) {
            if (set.find(current->val) == set.end()) {
                stk.push(current);
            }
            current = current->next;
        }

        ListNode* newHead = nullptr;
        while (!stk.empty()) {
            ListNode* node = stk.top();
            stk.pop();
            node->next = newHead;
            newHead = node;
        }

        return newHead;
    }
};