/**
 * insertion sort list
 * Sort a linked list using insertion sort.

Subscribe to see which companies asked this question
 */

#include <iostream>
using namespace std;

class Solution {
public:
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* tail = head;
        ListNode* index = head->next;
        while (index) {
            ListNode* cur = head;
            ListNode* pre = NULL;
            while (cur->val < index->val) {
                pre = cur;
                cur = cur->next;
            }
            if (cur == index) {
                tail = tail->next;
            } else {
                tail->next = index->next;
                if (pre == NULL) {
                    index->next = head;
                    head = index;
                } else {
                    pre->next = index;
                    index->next = cur;
                }
            }
            index = tail->next;
        }
        return head;
    }
};
