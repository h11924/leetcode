class Solution {

    bool check(int mid,vector<int>& bloomDay, int m, int k){
        int reqflowers=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid){
                reqflowers++;
                if(reqflowers==k){
                    m--;
                    reqflowers=0;
                    if(m==0) return true;
                }
            }else{
                reqflowers=0;
            }
        }
        return false;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {

        if(bloomDay.size() < (long long)m*k) return -1;

        int start=INT_MAX;
        int end=INT_MIN;

        for(int i=0;i<bloomDay.size();i++){
            start=min(bloomDay[i],start);
            end=max(bloomDay[i],end);
        }

        

        int ans=start;

        while(start<=end){
            int mid=start+(end-start)/2;

            if(check(mid,bloomDay,m,k)){
                ans=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }

        return ans;
        
    }
};