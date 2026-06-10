class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //Easy solution is sorting and then count
        if(nums.size() < 2){
            return nums.size() ? 1 : 0;
        }
        sort(nums.begin(), nums.end());
        int max_length = 1;
        int old_max = 1;
        for (int i =0; i < nums.size() - 1; i++){
            if (nums[i] == nums[i+1])
                continue;
            if(nums[i] == nums[i+1] - 1){
                max_length += 1;
            }
            else{
                old_max = std::max(max_length, old_max);
                max_length = 1;
            }
        }
        return std::max(max_length, old_max);
    }
};
