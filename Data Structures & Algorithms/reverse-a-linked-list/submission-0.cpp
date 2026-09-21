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
    ListNode* reverseList(ListNode* head) {
        ListNode* reverse_list = nullptr;
        while (head){
            ListNode* temp = head;
            head = head->next;
            temp->next = reverse_list;
            reverse_list = temp;
        }
        return reverse_list;
    }
};
