#include <algorithm>
#include <string>        
#include <vector>        
#include <unordered_map> 

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        if (s.empty()) return 0; // Quick edge-case guard

        std::vector<int> solutions = {0};
        std::unordered_map<char, int> seen;

        for (int i = 0; i < s.length(); i++) {
            // Find where it last appeared (or -1 if new)
            int previous_app = seen.count(s[i]) ? seen[s[i]] : -1;
            
            // Get the length of the valid substring from the previous step
            int prev_length = solutions.back();
            
            // The bottleneck calculation
            int new_length = std::min(prev_length + 1, i - previous_app);
            
            // Save the state
            solutions.push_back(new_length);
            seen[s[i]] = i;
        }

        // Return the highest length we recorded
        return *std::max_element(solutions.begin(), solutions.end());
    }
};