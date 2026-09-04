class Solution {
public:
    string removeOuterParentheses(string s) {
        int count = 0;
        string ans = "";

        for(char c : s) {
            if(c == ')') count--;
            if(count != 0) ans += c;
            if(c == '(') count++;
        }

        return ans;
    }
};