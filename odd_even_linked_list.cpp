/**
 * Odd Even Linked List
 * Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example:
Given 1->2->3->4->5->NULL,
return 1->3->5->2->4->NULL.

Note:
The relative order inside both the even and odd groups should remain as it was in the input.
The first node is considered odd, the second node even and so on ...

Credits:
Special thanks to @DjangoUnchained for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

solution: 把一条链分成odd链和even链，然后再用oddTail->next = evenHead, evenTail->next = NULL
time complexity: O(n)
space complexity: O(1)
 */
#include <iostream>
#include <vector>
using namespace std;

namespace odd_even_linked_list {
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* oddHead = head;
        ListNode* oddTail = head;
        ListNode* evenHead = head->next;
        ListNode* evenTail = evenHead;
        ListNode* cur = head->next->next;
        while (cur) {
            oddTail->next = cur;
            oddTail = oddTail->next;
            cur = cur->next;
            if (cur) {
                evenTail->next = cur;
                evenTail = evenTail->next;
                cur = cur->next;
            }
        }
        evenTail->next = NULL;
        oddTail->next = evenHead;
        return head;
    }
    ListNode* vectorToList(vector<int>& nums) {
      ListNode* head = NULL;
      ListNode* tail = NULL;
      for (int num : nums) {
        if (!head) {
          head = new ListNode(num);
          tail = head;
        } else {
          tail->next = new ListNode(num);
          tail = tail->next;
        }
      }
      tail->next = NULL;
      return head;
    }
    void printList(ListNode* head) {
      while (head) {
        cout << head->val << " ";
        head = head->next;
      }
    }
};



}

int main_odd_even_linked_list() {
  using namespace odd_even_linked_list;
  int data[] = {1,2,3,4,5,6};
  vector<int> nums(data, data+6);
  Solution solution;
  ListNode* head = solution.vectorToList(nums);
  solution.printList(solution.oddEvenList(head));
}
