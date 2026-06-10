class Solution {
public:
    int maxArea(vector<int>& heights) {
        //Two pointers:
        // Computer max and if it's greater, then we update last max
        // we move the pointer that has the smallest value
        int l = 0,r = heights.size() - 1 ;
        int max = 0;
        while (l < r){
            int local = std::min(heights[l],heights[r]) * (std::abs(r - l));
            if (max < local){
                max = local;
            }
            if (heights[l] < heights[r]){
                l++;
            }
            else{
                r--;
            }

        }
        return max;
        
    }
};
