// Reverse_Linked_List

#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
		ListNode* cur = head;
		ListNode* prev = NULL;
		ListNode* tmp;
		while(cur) {
			tmp = cur->next;
			cur->next = prev;
			prev = cur;
			cur = tmp;
		}
		return (prev);
	}
};

int main() {

}