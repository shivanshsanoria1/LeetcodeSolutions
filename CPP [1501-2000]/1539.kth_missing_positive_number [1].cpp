class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size(), i=0, x=0;
        while(k > 0)
        {
            x++;
            if(i<n && x==arr[i]) //x present in array
                i++;
            else //x not present in array
                k--;
        }
        return x;
    }
};