class Solution {
public:
    // T.C.=O(n), S.C.=O(n), Counting-sort
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp; // num -> freq
        for(int num: arr)
            mp[num]++;

        int n=arr.size();
        // i: freq, vec[i]: num of elements with that freq
        vector<int> vec(n+1, 0);
        for(auto [num, freq]: mp)
            vec[freq]++;

        for(int i=1; i<=n; i++)
        {
            if(vec[i] == 0)
                continue;
            while(k >= i && vec[i] > 0)
            {
                k -= i;
                vec[i]--;
            }
            if(k < i)
                k = 0;
        }

        return accumulate(vec.begin(), vec.end(), 0);
    }
};