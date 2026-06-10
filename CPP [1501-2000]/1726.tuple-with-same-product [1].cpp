class Solution {
public:
    // T.C.=O(n^2), S.C.=O(n^2)
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();
        // product -> freq
        unordered_map<int, int> mp;
        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)
                mp[nums[i]*nums[j]]++;
        
        int count = 0;
        for(auto [pro, freq]: mp)
            count += 8*freq*(freq-1)/2;
        
        return count;
    }
};
/*
# tuple (a,b,c,d) is valid if a*b = c*d and (a != b != c != d)
# each tuple (a,b,c,d) is counted 8 times 
  as it has 8 valid permutations:
  (a,b,c,d) (b,a,c,d) (a,b,d,c) (b,a,d,c) 
  (c,d,a,b) (c,d,b,a) (d,c,a,b) (d,c,b,a) 
# for every pair of distinct nums x,y 
  find their product x*y along with its freq
# for a product p with freq f, the num of 
  distinct tuples (without permutations) generated is
  fC2 = (f*(f-1))/2
*/