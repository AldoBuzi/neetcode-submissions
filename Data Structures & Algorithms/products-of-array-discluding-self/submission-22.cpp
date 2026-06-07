class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // First solution:
        // Scan array and save product
        // Then scan again and divide by a[i] value
        /*vector<int> result;
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
        */
        //let's use prefix and suffix arrays
        vector<int> prefix, suffix;
        int tot = 1;
        for(auto& num: nums){
            tot *= num;
            prefix.push_back(tot);
        }
        tot = 1;
        for(auto num = nums.rbegin(); num != nums.rend(); num++){
            tot *= *num;
            suffix.push_back(tot);
        }
        vector<int> result;
        
        for(int i = 0; i < nums.size(); i++){
            if(i==0){
                result.push_back(suffix[nums.size() - i - 2]);
                continue;
            }
            if(i == nums.size()-1){
                result.push_back(prefix[i-1]);
                continue;
            }
            result.push_back(prefix[i-1] * suffix[nums.size() - i - 2]);
        }
        return result;
    }
    
};
