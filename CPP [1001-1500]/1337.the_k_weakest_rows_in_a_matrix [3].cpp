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
        priority_queue<pair<int, int>> pq; // max-heap
        for(int i=0; i<mat.size(); i++)
        {
            pq.push({calculateOnes(mat[i]), i});
            if(pq.size() > k)
                pq.pop();
        }
        while(k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};