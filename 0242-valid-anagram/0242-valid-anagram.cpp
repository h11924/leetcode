class Solution {
public:
    bool isAnagram(string s, string t) {

        int smap[256]={0};
        int tmap[256]={0};

        if(s.size()!=t.size()) return false;

        for(int i=0;i<s.size();i++){
            smap[s[i]]++;
            tmap[t[i]]++;
        }

        for(int i=0;i<256;i++){
            //f(smap[s[i]]!=tmap[t[i]]) return false;
             if(smap[i]!=tmap[i]) return false;
        }

        return true;
        
    }
};