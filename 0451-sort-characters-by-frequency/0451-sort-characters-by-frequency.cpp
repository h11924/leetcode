class Solution {
public:
    string frequencySort(string s) {

        string ans="";
        map<char,int> mp;

        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }

        vector<pair<char, int>> v;

        for(auto c : mp) {
            v.push_back(c);
        }
        //we made a vector where we are storing the character and freq

        //sorting the vector based on the desecing order of the second element of it 
        sort(v.begin(), v.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });

        
        for(auto c:v){
            while(c.second--){
                ans+=c.first;
            }
        }

       

        return ans;



       
        
    }
};