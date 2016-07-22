/**
 * Palindrome linked list
 * Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?

Subscribe to see which companies asked this question
 */

#include <iostream>
using namespace std;

namespace palindrome_linked_list {
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
  bool isPalindrome(ListNode* head) {
          if (!head || !head->next)
              return true;
          ListNode* slow = head;
          ListNode* fast = head;
          while (fast->next != NULL && fast->next->next != NULL) {
              slow = slow->next;
              fast = fast->next->next;
          }
          fast = slow->next;
          slow->next = NULL;
          ListNode* head2 = reverseList(fast);
          while (head && head2 && head->val == head2->val) {
              head = head->next;
              head2 = head2->next;
          }
          return head2 == NULL;
      }
      ListNode* reverseList(ListNode* head) {
          if (!head->next)
              return head;
          ListNode* newhead = NULL;
          while (head->next) {
              ListNode* record = head->next;
              head->next = record->next;
              if (newhead == NULL) {
                  newhead = record;
                  record->next = head;
              } else {
                  record->next = newhead;
                  newhead = record;
              }
          }
          return newhead;
      }
};
}

int main_palindrome_linked_list() {
  using namespace palindrome_linked_list;
  ListNode* head = new ListNode(-1);
  head->next = new ListNode(4);
  head->next->next = new ListNode(1);
  head->next->next->next = new ListNode(1);
  head->next->next->next->next = new ListNode(4);
  head->next->next->next->next->next = new ListNode(-1);
  if ((new Solution())->isPalindrome(head))
    cout << "true";
  else
    cout << "false";
}
