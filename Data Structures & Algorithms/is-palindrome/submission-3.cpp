class Solution {
public:
    /*bool isPalindrome(string s) {
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
    }*/
     bool isPalindrome(string s) {
        int l = 0, r = s.length() - 1;

        while (l < r) {
            while (l < r && !alphaNum(s[l])) {
                l++;
            }
            while (r > l && !alphaNum(s[r])) {
                r--;
            }
            if (tolower(s[l]) != tolower(s[r])) {
                return false;
            }
            l++; r--;
        }
        return true;
    }

    bool alphaNum(char c) {
        return (c >= 'A' && c <= 'Z' ||
                c >= 'a' && c <= 'z' ||
                c >= '0' && c <= '9');
    }
};
