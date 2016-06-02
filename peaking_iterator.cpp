/**
 * Peaking iterator
 * Given an Iterator class interface with methods: next() and hasNext(), design and implement a PeekingIterator that support the peek() operation -- it essentially peek() at the element that will be returned by the next call to next().

Here is an example. Assume that the iterator is initialized to the beginning of the list: [1, 2, 3].

Call next() gets you 1, the first element in the list.

Now you call peek() and it returns 2, the next element. Calling next() after that still return 2.

You call next() the final time and it returns 3, the last element. Calling hasNext() after that should return false.

solution: 使用一个额外空间cache来记录peek的结果。
Show Hint
Follow up: How would you extend your design to be generic and work with all types, not just integer?
solution: 使用模板类来实现。
 */

#include <iostream>
#include <vector>
using namespace std;

namespace peaking_iterator {
class Iterator {
public:
  Iterator(const vector<int>& nums) {
    this->nums = nums;
    index = 0;
  }
  Iterator(const Iterator& iter) {
    nums = iter.nums;
    index = iter.index;
  }
  virtual ~Iterator() {
  }
  // Returns the next element in the iteration.
  int next() {
    return nums[index++];
  }
  // Returns true if the iteration has more elements.
  bool hasNext() const {
    return index < nums.size();
  }
private:
  vector<int> nums;
  int index;
};


class PeekingIterator : public Iterator {
public:
  PeekingIterator(const vector<int>& nums) : Iterator(nums) {
      // Initialize any member here.
      // **DO NOT** save a copy of nums and manipulate it directly.
      // You should only use the Iterator interface methods.
      cached = false;
  }

    // Returns the next element in the iteration without advancing the iterator.
  int peek() {
        if (!cached) {
            cached = true;
            cache = Iterator::next();
        }
        return cache;
  }

  // hasNext() and next() should behave the same as in the Iterator interface.
  // Override them if needed.
  int next() {
      if (cached) {
          cached = false;
          return cache;
      } else {
          return Iterator::next();
      }
  }

  bool hasNext() const {
      return cached || Iterator::hasNext();
  }
private:
    bool cached;
    int cache;
};
}

namespace peaking_iterator_template {
template <class T>
class Iterator {
 public:
   Iterator(const vector<T>& nums) {
     //for (int i=0; i<nums.size(); i++)
       //this->nums.push_back(nums[i]);
     this->nums = nums;
     index = 0;
   }
   virtual ~Iterator() {
   }
   // Returns the next element in the iteration.
   T next() {
     return nums[index++];
   }
   // Returns true if the iteration has more elements.
   bool hasNext() const {
     return index < nums.size();
   }
 private:
   vector<T> nums;
   int index;
};

template <class T>
class PeekingIterator : public Iterator<T> {
public:
  PeekingIterator(const vector<T>& nums) : Iterator<T>(nums) {
      // Initialize any member here.
      // **DO NOT** save a copy of nums and manipulate it directly.
      // You should only use the Iterator interface methods.
      cached = false;
  }

    // Returns the next element in the iteration without advancing the iterator.
  T peek() {
        if (!cached) {
            cached = true;
            cache = Iterator<T>::next();
        }
        return cache;
  }

  // hasNext() and next() should behave the same as in the Iterator interface.
  // Override them if needed.
  T next() {
      if (cached) {
          cached = false;
          return cache;
      } else {
          return Iterator<T>::next();
      }
  }

  bool hasNext() const {
      return cached || Iterator<T>::hasNext();
  }
private:
    bool cached;
    T cache;
};

class Node {
public:
  Node() {}
  Node(int x_, int y_) : x(x_), y(y_) {}
  void operator = (const Node& node) {
    x = node.x;
    y = node.y;
  }
  int x, y;
};

}

int main_peaking_iterator() {
  vector<peaking_iterator_template::Node> nums;
  nums.push_back(peaking_iterator_template::Node(2,2));
  peaking_iterator_template::PeekingIterator<peaking_iterator_template::Node> peeking(nums);
  peaking_iterator_template::Node node = peeking.peek();
  cout << node.x << node.y << endl;
  node = peeking.next();
  cout << node.x << node.y << endl;
}
