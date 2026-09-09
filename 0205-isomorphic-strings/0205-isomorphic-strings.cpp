/*class Solution {
public:
    bool isIsomorphic(string s, string t) {

        int smap[26]={0};
        int tmap[26]={0};

        for(int i=0;i<s.size();i++){
            if(smap[s[i]-'a']!=tmap[t[i]-'a']) return false;

            /*smap[s[i]-'a']++;
            tmap[t[i]-'a']++;

            smap[s[i]-'a']=i+1;
            tmap[t[i]-'a']=i+1;


        }

        return true;
        
    }
};*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {

        int smap[256]={0};
        int tmap[256]={0};

        for(int i=0;i<s.size();i++){
            if(smap[s[i]]!=tmap[t[i]]) return false;

            smap[s[i]]=i+1;
            tmap[t[i]]=i+1;
        }

        return true;
    }
};