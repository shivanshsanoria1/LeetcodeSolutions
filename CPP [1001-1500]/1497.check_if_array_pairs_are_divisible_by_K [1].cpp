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

            int mod = num % k;
            int pairMod = (k - mod) % k;

            // no matching pair found
            if(freq[pairMod] == 0)
                freq[mod]++;
            // matching pair found
            else // freq[pairMod] > 0
                freq[pairMod]--;
        }

        for(int i=0; i<k; i++)
            if(freq[i] > 0)
                return false;
        
        return true;
    }
};

/*
# after reducing each num with mod k:
  # a num with mod 0 can only be paired with another num with mod 0
  # a num with non-zero mod m can only be paired with another num with mod (k-m)
# both of these cases can be combined as:
  a num with mod m can only be paired with another num with mod ((k-m) % k)
# if no matching pair is found then increment the freq of curr mod val
# if a matching pair is found then decrement the freq of the paired mod val
# array can be split into n/2 pairs if at the end 
  the freq of each num reduced with mod k is 0
*/