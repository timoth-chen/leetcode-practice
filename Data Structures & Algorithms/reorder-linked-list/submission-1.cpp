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
    void reorderList(ListNode* head) {
        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* second = slow->next;
        slow->next = nullptr;
        ListNode* prev = nullptr;
        while(second){
            ListNode* next_node = second->next;
            second->next = prev;
            prev = second;
            second = next_node;
        }

        second = prev;
        ListNode* first = head;
        while(second){
            ListNode* next_node1 = first->next;
            ListNode* next_node2 = second->next;

            first->next = second;
            second->next = next_node1;

            first= next_node1;
            second= next_node2;
        }
    }
};
