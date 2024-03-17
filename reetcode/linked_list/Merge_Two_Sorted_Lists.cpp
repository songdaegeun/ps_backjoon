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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ret = new(ListNode);
        ListNode* head = ret;

        while(1) {
            ListNode* tmp;
            if(list1 && (!list2 || list1->val <= list2->val)) {
                tmp = new ListNode(list1->val);
                list1 = list1->next;
            }
            else if(list2 && (!list1 || list2->val <= list1->val)) {
                tmp = new ListNode(list2->val);
                list2 = list2->next;
            }
            else {
                break;
            }
            ret->next = tmp;
            ret = ret->next;
        }
        return (head->next);
    }
};