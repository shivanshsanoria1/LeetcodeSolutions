class Solution {
private:
    // returns true if the array bits[] has 
    // a group of 1's exactly of size m
    bool hasGroupOf1sOfSizeM(vector<bool>& bits, int m){
        int n=bits.size()-1;
        int left = 1, right = 1;

        while(right <= n)
        {
            if(!bits[right])
            {
                if(right - left == m)
                    return true;
                left = right + 1;
            }

            right++;
        }

        // check for the last group
        if(right - left == m)
            return true;

        return false;
    }

public:
    // T.C.=O(n^2), S.C.=O(n)
    int findLatestStep(vector<int>& arr, int m) {
        int n=arr.size();
        // initially assume all bits are 1
        vector<bool> bits(n+1, true);

        for(int i=n; i>=1; i--)
        {
            if(hasGroupOf1sOfSizeM(bits, m))
                return i;
            // set the (arr[i-1])th bit to 0
            bits[arr[i-1]] = false;
        }

        return -1;
    }
};