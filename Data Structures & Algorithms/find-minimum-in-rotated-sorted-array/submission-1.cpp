class Solution {
public:
    int findMin(vector<int> &nums) {
        // easy solution: sort and take minimum
        // Other solution: scan array to understand how many times the array was rotated
        // Then take (rotated + 1) % array_len as min
        /*int times = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            if (nums[i] <= nums[i+1]){
                times += 1;
                continue;
            }
            break; // if we got there, then nums[i] > nums[i+1]
        }
        return nums[(times + 1) % nums.size()];*/

        // Let's exploit binary search
        int res = nums[0];
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            if (nums[l] < nums[r]) {
                res = min(res, nums[l]);
                break;
            }
            int m = l + (r - l) / 2;
            res = min(res, nums[m]);

            if (nums[m] >= nums[l]) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return res;
    }
};
