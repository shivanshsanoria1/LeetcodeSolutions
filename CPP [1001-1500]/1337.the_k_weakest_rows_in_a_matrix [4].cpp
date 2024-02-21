class Solution {
private:
    typedef pair<int, int> PI;

    static bool cmp(PI &a, PI &b){
        return a.first == b.first ? a.second < b.second : a.first < b.first;
    }

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
        vector<PI> vec;
        for(int i=0; i<mat.size(); i++)
            vec.push_back({calculateOnes(mat[i]), i});
        sort(vec.begin(), vec.end(), cmp);
        for(int i=0; i<k; i++)
            ans.push_back(vec[i].second);
        return ans;
    }
};