#include <vector>
#include <list>
#include <utility>

class MyHashMap {
private:
    int numBuckets;
    // An array of linked lists, where each list holds a pair of {key, value}
    std::vector<std::list<std::pair<int, int>>> buckets;

    // Simple modulo hash function
    int hash(int key) {
        return key % numBuckets;
    }

public:
    MyHashMap() {
        numBuckets = 10007; // A prime number helps distribute keys evenly
        buckets.resize(numBuckets);
    }
    
    void put(int key, int value) {
        int index = hash(key);
        
        // Search for the key in the bucket
        for (auto& pair : buckets[index]) {
            if (pair.first == key) {
                pair.second = value; // Key exists, update the value
                return;
            }
        }
        
        // Key does not exist, add it to the bucket
        buckets[index].push_back({key, value});
    }
    
    int get(int key) {
        int index = hash(key);
        
        // Search for the key
        for (const auto& pair : buckets[index]) {
            if (pair.first == key) {
                return pair.second;
            }
        }
        
        return -1; // Key not found
    }
    
    void remove(int key) {
        int index = hash(key);
        
        // Search for the key to remove it
        for (auto it = buckets[index].begin(); it != buckets[index].end(); ++it) {
            if (it->first == key) {
                buckets[index].erase(it);
                return;
            }
        }
    }
};