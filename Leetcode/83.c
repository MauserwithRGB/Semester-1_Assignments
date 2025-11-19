/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* current = head;

    while (current != NULL && current->next != NULL) {
        if (current->val == current->next->val) {
            // Duplicate found: bypass the next node
            struct ListNode* temp = current->next;
            current->next = current->next->next;
            free(temp); // Free memory of the removed node
        } else {
            // No duplicate: move to next node
            current = current->next;
        }
    }
    return head;
}
