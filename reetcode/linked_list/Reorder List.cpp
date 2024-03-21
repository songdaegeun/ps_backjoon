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
        ListNode *rev_head;
        ListNode *cur = head;
        int ls_size = 0;
        while(cur) {
            ls_size++;
            cur = cur->next;
        }
        if(ls_size==1)
            return;
    
        int rev_size = ls_size/2;
        ListNode *tmp;
        cur = head;
        int i = 0;
        while(i < rev_size) {
            i++;
            if(i==rev_size) {
                tmp = cur;
                if(ls_size%2)
                    tmp = tmp->next;
            }
            cur = cur->next;
        }
        if(ls_size%2) {
            rev_head = cur->next;
        }
        else {
            rev_head = cur;
        }
        tmp->next = NULL;

        cur = rev_head;
        ListNode *pre = NULL;
        while(cur) {
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        rev_head = pre;

        ListNode *ls_cur = head;
        ListNode *rev_cur = rev_head;
        ListNode *ls_tmp;
        ListNode *rev_tmp;
        i = 0;
        while(i < rev_size) {
            i++;
            ls_tmp = ls_cur->next;
            rev_tmp = rev_cur->next;
            ls_cur->next = rev_cur;
            rev_cur->next = ls_tmp;
            ls_cur = ls_tmp;
            rev_cur = rev_tmp;
        }
    }
};