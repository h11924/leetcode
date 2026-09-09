class Solution {
public:
    bool rotateString(string s, string goal) {

        if(s.size()!=goal.size()) return false;

        string n=s+s;
        if(n.find(goal)!=string::npos) return true;
        
        return false;
        
    }
};