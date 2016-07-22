/**
 * Plus one linked list
 * Given a non-negative number represented as a singly linked list of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.

Example:
Input:
1->2->3

Output:
1->2->4
Show Company Tags
Show Tags
Show Similar Problems

solution: 添加一个dummy node作为链表头结点。找出最后一个val不为9的节点i，最后一个节点为j。如果节点j值+1后不超过
10， 则不作额外处理。如果节点j值+1后超过10，则节点i值+1并且把节点i之后的所有节点置为0.
time complexity: O(n)
space complexity: O(1)
 *
 */

#include <iostream>
using namespace std;

namespace plus_one_linked_list {
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* i = dummy;
        ListNode* j = dummy;
        while (j->next) {
            j = j->next;
            if (j->val != 9)
                i = j;
        }
        if (j->val != 9)
            j->val++;
        else {
            i->val++;
            for (j = i->next; j; j = j->next)
                j->val = 0;
        }
        if (dummy->val == 0)
            return dummy->next;
        else
            return dummy;
    }
};
}
