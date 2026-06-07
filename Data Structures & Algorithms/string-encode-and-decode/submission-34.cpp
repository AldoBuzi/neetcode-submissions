#include <iostream>
#include <string>
#include <sstream>
#include <vector>
class Solution {
public:

    string encode(vector<string>& strs) {
        /*if (!strs.size()){
            return "";
        }*/
        string result = "";
        for(auto& mystr: strs){
            result +=  mystr + '\0';
        }
        if (result.size()) result.pop_back();
        result = to_string(strs.size()) + " " + result;
        return result;
    }

    vector<string> decode(string s) {
        /*if (s == ""){
            return {};
        }*/
        vector<string> result;
        std::stringstream sstream(s);
        string token;
        std::getline(sstream,token, ' ');
        int size = std::stoi(token);
        cout << s;
        for(int i = 0; i < size; i++) {
            std::getline(sstream,token, '\0');
            result.push_back(token);
        }
        if (result.size() < size){
            result.insert(result.begin(), "");
        }
        return result;
    }
};
