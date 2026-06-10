class Cmp{
private:
    typedef pair<int, int> PI;

public:
    bool operator()(PI &a, PI &b){
        return a.first == b.first ? a.second > b.second : a.first > b.first;
    }
};

class Solution {
private:
    typedef pair<int, int> PI;

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
        priority_queue<PI, vector<PI>, Cmp> pq; // min-heap
        for(int i=0; i<mat.size(); i++)
            pq.push({calculateOnes(mat[i]), i});
        while(k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};