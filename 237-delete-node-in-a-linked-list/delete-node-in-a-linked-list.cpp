/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val=node->next->val;
        ListNode* temp=node->next;
        node->next=node->next->next;
        delete temp;
        // // Copy value from next node
        // node->val = node->next->val;

        // // Save pointer to next node
        // ListNode* temp = node->next;

        // // Skip the next node
        // node->next = node->next->next;

        // // Delete the next node
        // delete temp;
    
    }
};