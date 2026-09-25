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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp_ptr = new ListNode(0, head);
        ListNode* left = temp_ptr;
        ListNode* right = head;

        for (int i = 0; i < n; i++){
            right=right->next;
        }

        while(right){
            right=right->next;
            left=left->next;
        }
        left->next = left->next->next;
        return temp_ptr->next;
    }
};
