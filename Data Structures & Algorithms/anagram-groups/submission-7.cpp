class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::map<std::multiset<char>, std::vector<std::string>> myMap;
        for (auto& str : strs){
            std::multiset<char> string_set(str.begin(),str.end());
            if (!myMap.count(string_set)){
                myMap[string_set] = {str};
            }
            else {
                myMap[string_set].push_back(str);
            }
        }
        std::vector<std::vector<string>> result = {};
        for (auto& [key,value_list] : myMap){
            result.push_back(value_list);
        }
        return result;
    }
};
