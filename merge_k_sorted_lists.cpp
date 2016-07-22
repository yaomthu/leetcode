/**
 * Merge k sorted lists
 * Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 solution: use heap as data structure, use stl function make_heap, pop_heap and push_heap to minipulate
 a heap.

 time complexity: O(nklogk)
 space complexity: O(n)

 */

#include <iostream>
#include <vector>
using namespace std;

namespace merge_k_sorted_lists {
class Solution {
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
public:
    struct Cmp {
        bool operator() (const ListNode* a, const ListNode* b) {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return NULL;
        ListNode* head = NULL;
        ListNode* tail = NULL;
        Cmp cmp;
        vector<ListNode*> heap;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i])
                heap.push_back(lists[i]);
        }
        make_heap(heap.begin(), heap.end(), cmp);
        while (heap.size()) {
            ListNode* top = heap[0];
            if (!head) {
                head = top;
                tail = head;
            } else {
                tail->next = top;
                tail = tail->next;
            }
            pop_heap(heap.begin(), heap.end(), cmp);
            heap.pop_back();
            if (top->next) {
                heap.push_back(top->next);
                push_heap(heap.begin(), heap.end(), cmp);
            }
        }
        return head;
    }
};
}
