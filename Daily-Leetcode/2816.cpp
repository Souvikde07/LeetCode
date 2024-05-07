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
class Solution {
public:

    int multiply(ListNode* head){
        //base condition
        if(head == NULL){
            return 0;
        }
        int value = head -> val * 2 + multiply(head-> next);
        head->val = value % 10;
        return value / 10;
    }

    ListNode* doubleIt(ListNode* head) {
        int carry = multiply(head);
        if (carry)
            head = new ListNode(carry, head);
        return head;
    }
};