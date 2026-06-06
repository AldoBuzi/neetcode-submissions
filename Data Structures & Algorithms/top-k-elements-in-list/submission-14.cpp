#include <queue>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //First solution:
        // Build unordered_map with values and times it appears
        // Build min_heap where we index by how many times an element appears
        // Scan the min_heap to build a list of the k most frequent elements

        std::unordered_map<int, int> my_map;
        std::priority_queue<std::pair<int, int>> min_heap;
        for (auto& num : nums){
            my_map[num] += 1;
        }
        for (auto& [key,value] : my_map){
            min_heap.push({-value, key});
            if (min_heap.size() > k){
                min_heap.pop();
            }
        }
        std::vector<int> result; 
        while(!min_heap.empty()){
            std::pair<int,int> _pair = min_heap.top();
            min_heap.pop();
            result.push_back(_pair.second);
        }
        return result;
    }
};
