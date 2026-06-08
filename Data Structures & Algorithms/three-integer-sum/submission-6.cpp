#include <algorithm>

struct Triplet {
    int a, b, c;

    // Required for unordered_set to handle collisions
    bool operator==(const Triplet& other) const {
        return a == other.a && b == other.b && c == other.c;
    }
};
namespace std {
    template <>
    struct hash<Triplet> {
        std::size_t operator()(const Triplet& t) const {
            // A simple, fast bit-shifting hash combination
            return hash<int>()(t.a) ^ (hash<int>()(t.b) << 1) ^ (hash<int>()(t.c) << 2);
        }
    };
}
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //Brute Force solution: O(n^3)
        // I can exploit that we have to reach 0, and to do so, I cannot sum two positive or negative numbers
        std::sort(nums.begin(), nums.end());
        if (nums.size() && nums[0] > 0) {
            return {};
        }
        //std::set<Triplet> seen;
        vector<vector<int>> result;
        for(int i= 0; i < nums.size(); i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int l= i + 1, r = nums.size() -1;
            while(l < r){
                if(nums[i] + nums[l] + nums[r] == 0){
                    result.push_back({nums[i],nums[l],nums[r]});
                    // Skip duplicate values for the left pointer
                    while (l < r && nums[l] == nums[l + 1]) l++;
                    // Skip duplicate values for the right pointer
                    while (l < r && nums[r] == nums[r - 1]) r--;
                    l ++;
                    r --;
                }
                else if (nums[i] + nums[l] + nums[r] > 0){
                    r --;
                }
                else {
                    l++;
                }
            }
        }
        return result;
    }
};
