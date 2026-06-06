class Solution {
public:
    bool isPalindrome(string s) {
        string new_string = "";
        for(int i= 0; i < s.size(); i++){
            if(s[i] == ' ') continue;
            if(std::isalnum(s[i])){
                new_string += std::tolower(s[i]);
            }
        }
        string copy = new_string;
        std::reverse(new_string.begin(), new_string.end());
        return copy == new_string;
    }
};
