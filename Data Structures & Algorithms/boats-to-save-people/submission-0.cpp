#include <vector>
#include <algorithm>

class Solution {
public:
    int numRescueBoats(std::vector<int>& people, int limit) {
        std::sort(people.begin(), people.end());
        
        int light = 0;
        int heavy = people.size() - 1;
        int boats = 0;
        
        while (light <= heavy) {
            // If the lightest and heaviest can share a boat, pair them
            if (people[light] + people[heavy] <= limit) {
                light++;
            }
            // In all cases, the heaviest person gets a boat (either shared or alone)
            heavy--;
            boats++;
        }
        
        return boats;
    }
};