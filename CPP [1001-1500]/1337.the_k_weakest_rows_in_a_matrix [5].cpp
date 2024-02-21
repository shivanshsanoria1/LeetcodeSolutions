class Solution {
public:
    int calculateOnes(vector<int>& arr){ // using binary search
        int left = 0, right = arr.size()-1;
        while(left <= right)
        {
            int mid = left + (right - left)/2;
            if(arr[mid] == 0) // move to left-subarray
                right = mid - 1;
            else // move to right-subarray
                left = mid + 1;
        }
        return left;
    }

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> ans;
        vector<pair<int, int>> vec;
        for(int i=0; i<mat.size(); i++)
            vec.push_back({calculateOnes(mat[i]), i});
        stable_sort(vec.begin(), vec.end());
        for(int i=0; i<k; i++)
            ans.push_back(vec[i].second);
        return ans;
    }
};
/*
# stable_sort() keeps the relative order of duplicate values
# here there is no need to use cmp() with stable_sort() as it sorts by the 'first' key in pair
# and we are pushihg the 'second' key of the pair in increasing order in the initial vector
*/