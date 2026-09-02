class Solution {

    long long check(int mid,int h,vector<int>&piles){
        long long hours=0;
        for(int i=0;i<piles.size();i++){
            if(piles[i]<=mid){
                hours++;
                //mid is the hours 
                //our hours per banana is more than that pile so we will finish that in o ne hour 
                
            }else{
                //our hours(mid) is less than the piles

                //hours+=(ceil(piles[i]/mid));
                hours+=(piles[i]+mid-1)/mid;
            }
            

        }

        return hours;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {

       
        
    

        int start=1;
        
        int end=*max_element(piles.begin(),piles.end());

        int ans=end;

        while(start<=end){
            int mid=start+(end-start)/2;

            long long  totalhours=check(mid,h,piles);

            if(totalhours<=h){

                ans=mid;
                end=mid-1;

            }

            else {
                start=mid+1;
            }

           
        }

        return ans;
        
    }
};