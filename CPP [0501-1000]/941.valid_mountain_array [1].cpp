class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n=arr.size();
        if(n<3) //min size of array must be 3
            return false;
        int peak=0;
        for(int i=1; i<n-1; i++)
        {
            int diff1=arr[i]-arr[i-1], diff2=arr[i+1]-arr[i];
            if(diff1== 0 || diff2==0 || (diff1<0 && diff2>0)) //diff==0 means flat, diff= -ve to +ive means valley
                return false;
            if(diff1>0 && diff2<0) //diff= +ive to -ive means peak
                peak++;
            if(peak>1) //mountain cannot have more than 1 peak
                return false;
        }
        return peak==0 ? false : true; //peak==0 means array is strictly increasing or decreasing
    }
};