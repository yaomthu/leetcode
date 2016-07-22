/**
 * LRU cache
 * Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

solution: 注意使用stl::list, list.splice(list.begin(), list, list::iterator)，将iterator指向的节点连接
到list的开头位置。
 */

#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

namespace lru_cache {
class LRUCache{
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (cacheMap.find(key) != cacheMap.end()) {
            int ans = cacheMap[key]->second;
            cache.splice(cache.begin(), cache, cacheMap[key]);
            cacheMap[key] = cache.begin();
            return ans;
        } else
            return -1;
    }

    void set(int key, int value) {
        if (cacheMap.find(key) != cacheMap.end()) {
            cacheMap[key]->second = value;
            cache.splice(cache.begin(), cache, cacheMap[key]);
            cacheMap[key] = cache.begin();
        } else {
            if (capacity > 0) {
                capacity--;
                cache.push_front(make_pair(key, value));
                cacheMap[key] = cache.begin();
            } else {
                cacheMap.erase(cache.back().first);
                cache.pop_back();
                cache.push_front(make_pair(key, value));
                cacheMap[key] = cache.begin();
            }
        }
    }
private:
    int capacity;
    list<pair<int,int> > cache;
    unordered_map<int, list<pair<int,int> >::iterator> cacheMap;
};
}
