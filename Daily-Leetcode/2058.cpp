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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head || !head->next || !head->next->next)
            return {-1,-1};

        ListNode* prev = head;
        ListNode* curr = prev->next;
        ListNode* nxt = curr->next;
        vector<int> v;
        int count = 1;
        while(nxt){
            if((curr->val > prev->val && curr->val > nxt->val)||(curr->val < prev->val && curr->val < nxt->val))
                v.push_back(count);
            count++;
            prev = curr;
            curr = nxt;
            nxt = nxt->next;
        }
        if(v.size() < 2)
            return {-1,-1};
        int mini = INT_MAX;
        for(int i = 1; i < v.size(); i++)
            mini = min(mini, v[i] - v[i-1]);
        return {mini, v.back() - v[0]};
    }
};