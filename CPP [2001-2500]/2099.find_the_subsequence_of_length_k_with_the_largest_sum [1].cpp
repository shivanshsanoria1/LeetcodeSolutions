class Solution {
public:
    typedef pair<int, int> PI;

    // sort in descending order of 'first' and 'second' for each pair
    static bool cmp1(PI &a, PI &b){
        return a.first == b.first ? a.second > b.second : a.first > b.first;
    }

    // sort in increasing order of 'second' for each pair
    static bool cmp2(PI &a, PI &b){
        return a.second < b.second;
    }

    vector<int> maxSubsequence(vector<int>& nums, int k) { // T.C.=O(n*logn + k*logk), S.C.=O(n)
        vector<int> ans;
        int n = nums.size();
        vector<PI> vec;
        for(int i=0; i<n; i++)
            vec.push_back({nums[i], i});
        // sort in decreasing order of num (and decreasing index if num are equal)
        sort(vec.begin(), vec.end(), cmp1);
        // sort the first k elements in increasing order of index
        sort(vec.begin(), vec.begin() + k, cmp2);
        for(int i=0; i<k; i++)
            ans.push_back(vec[i].first);
        return ans;
    }
};