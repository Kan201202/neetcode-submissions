#include <vector>
#include <list>
#include <algorithm>

class MyHashSet {
private:
    int numBuckets;
    std::vector<std::list<int>> buckets;

    // A simple hash function
    int hash(int key) {
        return key % numBuckets;
    }

public:
    MyHashSet() {
        numBuckets = 10007; 
        buckets.resize(numBuckets);
    }
    
    void add(int key) {
        int index = hash(key);
        // Check if the key is already in the bucket's linked list
        if (!contains(key)) {
            buckets[index].push_back(key);
        }
    }
    
    void remove(int key) {
        int index = hash(key);
        // std::list has a built-in remove function that removes the specific value
        buckets[index].remove(key); 
    }
    
    bool contains(int key) {
        int index = hash(key);
        // Search for the key in the specific bucket
        auto it = std::find(buckets[index].begin(), buckets[index].end(), key);
        return it != buckets[index].end();
    }
};