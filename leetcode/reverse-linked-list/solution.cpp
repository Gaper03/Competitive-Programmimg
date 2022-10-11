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
private:
    ListNode* newHead = NULL;
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return head;
        
        ListNode* node = head;
        updateNode(node->next, node);
        node->next = NULL;
        return newHead;
    }
    
    void updateNode(ListNode* node, ListNode* prev) {
        if (node != NULL) {
            updateNode(node->next, node);
            node->next = prev;
        } else {
            newHead = prev;
        }
    }
};
