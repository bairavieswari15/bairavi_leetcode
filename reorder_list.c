/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reorderList(struct ListNode* head) {
    if (!head || !head->next || !head->next->next)
     {
        return;
    }
    struct ListNode *slow = head, *fast = head;
    while (fast->next && fast->next->next)
     {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode *curr = slow->next;
    slow->next = NULL;
    struct ListNode *prev = NULL, *next = NULL;
    while (curr)
     {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    struct ListNode *first = head, *second = prev;
    while (second)
     {
        struct ListNode *tmp1 = first->next;
        struct ListNode *tmp2 = second->next;
        
        first->next = second;
        second->next = tmp1;
        
        first = tmp1;
        second = tmp2;
    }
}