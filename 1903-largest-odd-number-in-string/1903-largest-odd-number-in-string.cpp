class Solution {
public:
    string largestOddNumber(string num) {

        int i=num.size()-1;
        while(i>=0){
            /*if(num[i]%2!=0){
                num.pop_back();
                i--;
            }else{
                break;
            }*/
            if((num[i]-'0')%2!=0){
                break;
            }else{
                num.pop_back();
                i--;
            }
        }

        return num;
        
    }
};