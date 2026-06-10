class Solution {
private:
    // returns the Kth bit in the string Sn
    int solve(int n, int k){
        if(n == 1)
            return 0;

        int len = (1 << n) - 1;
        int mid = len/2;    
        
        if(k < mid)
            return solve(n-1, k);
        
        if(k > mid)
            return !solve(n-1, len-k-1);
        
        // k == mid
        return 1;
    }

public:
    // T.C.=O(n), S.C.=O(n)
    char findKthBit(int n, int k) {
        // (k-1) is done to convert it from 
        // 1-based to 0-based indexing
        return solve(n, k-1) == 0 ? '0' : '1';
    }
};

/*
# len of string Sn = 2^n - 1 = (1 << n) - 1
# all strings are of odd length with the middle bit being 1 
  except for S1 whose middle bit is 0
*/