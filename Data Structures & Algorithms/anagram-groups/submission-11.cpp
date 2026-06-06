class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> myMap;
        for (auto& str : strs){
            std::string sorted_str = str;
            std::sort(sorted_str.begin(), sorted_str.end());
            myMap[sorted_str].push_back(str);
        }
        
        std::vector<std::vector<string>> result = {};
        for (auto& [key, value_list] : myMap){
            result.push_back(std::move(value_list));
        }
        return result;
    }
};