class Solution {
public:
    // T.C.=O(n + k), S.C.=O(k)
    bool canArrange(vector<int>& arr, int k) {
        // freq of num reduced with mod k
        vector<int> freq(k, 0);
        for(int num: arr)
        {
            // convert -ive num to +ive before taking mod with k
            if(num < 0)
                num += ((-num/k) * k) + k;

            freq[num % k]++;
        }
        
        if(freq[0] % 2 == 1)
            return false;

        int left = 1, right = k-1;
        while(left < right)
        {
            if(freq[left] != freq[right])
                return false;
            
            left++;
            right--;
        }
        
        return true;
    }
};

/*
# after reducing each num with mod k:
  # a num with mod 0 can only be paired with another num with mod 0
  # a num with non-zero mod m can only be paired with another num with mod (k-m)
# array can be split into n/2 pairs if at the end
  # freq of nums with mod 0 is even
  # each mod m and its pair (k-m) have the same freq of nums
*/