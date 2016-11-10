/**
 * Linked list random node
 * Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.

Follow up:
What if the linked list is extremely large and its length is unknown to you? Could you solve this efficiently without using extra space?

Example:

// Init a singly linked list [1,2,3].
ListNode head = new ListNode(1);
head.next = new ListNode(2);
head.next.next = new ListNode(3);
Solution solution = new Solution(head);

// getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.
solution.getRandom();
Subscribe to see which companies asked this question

solution: for i-th node, select it as candidate with probability 1/i.
time complexity: O(n)
space complexity: O(1)
related link: https://en.wikipedia.org/wiki/Reservoir_sampling
 */

#include <iostream>
using namespace std;

namespace linked_list_random_node {
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head = head;
    }

    /** Returns a random node's value. */
    int getRandom() {
        ListNode* record = head;
        ListNode* cur = head->next;
        int len = 1;
        while (cur) {
            len++;
            if (rand()%len == 0) {
                record = cur;
            }
            cur = cur->next;
        }
        return record->val;
    }
private:
    ListNode* head;
};
}
