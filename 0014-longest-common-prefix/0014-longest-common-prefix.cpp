class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());

        string start=strs[0];
        int n=strs.size();
        string end=strs[n-1];

        string ans="";

        int i=0;
        while(i<start.size() && i<end.size() && start[i]==end[i]){
            ans+=start[i];
            i++;
        }

        return ans;
        
    }
};