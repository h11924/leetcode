class Solution {
private:
    string print(int start, int end, string s, string &ans) {
        for(int i = start; i <= end; i++) {
            ans += s[i];
        }
        return ans;
    }

public:
    string reverseWords(string s) {
        string ans = "";
        int n = s.size();

        int i = n - 1;

        while(i >= 0) {
            while(i >= 0 && s[i] == ' ')
                i--;

            if(i < 0)
                break;

            int end = i;

            while(i >= 0 && s[i] != ' ')
                i--;

            int start = i + 1;

            print(start, end, s, ans);
            ans += ' ';
        }

        if(!ans.empty())
            ans.pop_back();

        return ans;
    }
};