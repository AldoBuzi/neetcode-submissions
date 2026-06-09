#include <limits>
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = std::numeric_limits<int>::max();
        int max = std::numeric_limits<int>::min();
        int gain = 0;
        for (auto& price: prices){
            if (price < min){
                min = price;
                max = std::numeric_limits<int>::min();
            }
            else if(price > max){
                max = price;
                if (gain < max - min)
                gain = max - min;
            }
        }
        return gain;
    }
};
