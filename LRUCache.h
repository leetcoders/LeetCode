/*
 Author:     Matthew Jin, marthew777@gmail.com
 Date:       March 12, 2014
 Problem:    LRU Cache
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/lru-cache/
 Notes:
 Design and implement a data structure for Least Recently Used (LRU) cache. 
 It should support the following operations: get and set. 
 get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
 set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
 
 Solution: Hash + list.
*/
struct CacheNode{
    int key;
    int value;
    CacheNode(int k, int v) : key(k), value(v) {}
};

class LRUCache{
public:
    LRUCache(int capacity) : size(capacity) {
    }
    
    int get(int key){
        if (cachemap.find(key) != cachemap.end()) {
            cachelist.splice(cachelist.begin(), cachelist, cachemap[key]);
            return cachemap[key]->value;
        }
        else {
            return -1;
        }
    }
    
    void set(int key, int value) {
        if (cachemap.find(key) != cachemap.end()) {
            cachelist.splice(cachelist.begin(), cachelist, cachemap[key]);
            cachemap[key]->value = value;
        }
        else {
            if (size == cachelist.size()) {
                cachemap.erase(cachelist.back().key);
                cachelist.pop_back();
            }
            cachelist.push_front(CacheNode(key, value));
            cachemap[key] = cachelist.begin();
        }
    }
private:
    list<CacheNode> cachelist;
    unordered_map<int, list<CacheNode>::iterator> cachemap;
    int size;
};
