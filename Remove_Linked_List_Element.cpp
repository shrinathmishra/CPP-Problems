/*
https://leetcode.com/problems/remove-linked-list-elements/description/

Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.
*/

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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)
            return head;
        
        while(head && head -> val == val)
            head = head -> next;
        
        ListNode* curr = head, *prev = nullptr;

        while(curr) {
            if(curr -> val == val)
                prev -> next = curr -> next;
            else
                prev = curr;
            curr = curr -> next;
        }
        return head;
    }
};