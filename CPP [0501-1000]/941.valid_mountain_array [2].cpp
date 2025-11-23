class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n=arr.size(), i=0;
        while(i<n-1 && arr[i]<arr[i+1]) //walk uphill
            i++;
        if(i==0 || i==n-1) //peak cannot be at start or at end
            return false;
        while(i<n-1 && arr[i]>arr[i+1]) //walk downhill
            i++;
        return i==n-1 ? true : false;
    }
};