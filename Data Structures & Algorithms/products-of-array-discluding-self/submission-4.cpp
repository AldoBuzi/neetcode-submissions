class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // First solution:
        // Scan array and save product
        // Then scan again and divide by a[i] value
        vector<int> result;
        int tot = 1;
        int how_many = 0;
        for(auto& num: nums){
            if (num == 0) {
                how_many ++;
                continue;
            }
            tot *= num;
        }
        if(how_many > 1) tot = 0;
        for(auto& num: nums){
            if (num == 0){
                result.push_back(tot);
                continue;
            }
            result.push_back(how_many == 1 ? 0 : tot/num);
        }
        return result;
    }
};
