class Solution {
public:
    bool isValid(string s) {
        std::stack<char> _stack;
        std::unordered_map<char, char> _map = {{')','('},{']','['},{'}','{'}};
        for(int i=0; i < s.length(); i++){
            if(_map.contains(s[i])){
                if (_stack.empty() or _map[s[i]] != _stack.top()){
                    return false;
                }
                _stack.pop();
                continue;
            }
            _stack.push(s[i]);

        }
        return _stack.empty();
    }
};
