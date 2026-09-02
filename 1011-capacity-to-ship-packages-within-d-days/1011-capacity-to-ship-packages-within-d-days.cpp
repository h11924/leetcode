/*class Solution {

    int check(int mid,vector<int>& weights, int days){
        int ourdays=0;
        int sum=0;
        for(int i=0;i<weights.size();i++){
            sum+=weights[i];
            if(sum>mid){
                sum-=weights[i];
                ourdays++;
            }
        }

        return ourdays;

    }
public:
    int shipWithinDays(vector<int>& weights, int days) {

        int start=INT_MAX;
        int end=INT_MIN;

        for(int i=0;i<weights[i];i++){
            start=min(start,weights[i]);
            end=max(end,weights[i]);
        }

        int ans=start;

        while(start<=end){
            int mid=start+(end-start)/2;

            int d=check(mid,weights,days);

            if(d<=days){
                ans=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return ans;
        
    }
};*/

class Solution {

    int check(int mid,vector<int>& weights,int days){
        int ourdays=1; // CORRECTION: start with 1 day because we need at least one day
        int sum=0;

        for(int i=0;i<weights.size();i++){ // CORRECTION: weights[i] was used in the loop condition

            if(sum+weights[i]>mid){ // CORRECTION: check whether current weight fits in current day
                ourdays++;
                sum=weights[i]; // CORRECTION: current package starts the next day
            }
            else{
                sum+=weights[i];
            }
        }

        return ourdays;
    }

public:
    int shipWithinDays(vector<int>& weights,int days){

        int start=INT_MIN;
        int end=0;

        for(int i=0;i<weights.size();i++){ // CORRECTION: weights.size() instead of weights[i]
            start=max(start,weights[i]); // CORRECTION: minimum capacity must be at least the largest package
            end+=weights[i]; // CORRECTION: maximum capacity can be the sum of all packages
        }

        int ans=end;

        while(start<=end){
            int mid=start+(end-start)/2;

            int d=check(mid,weights,days);

            if(d<=days){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }

        return ans;
    }
};