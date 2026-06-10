class Solution {
public:
    typedef pair<int, pair<int, int>> PI;

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        priority_queue<PI, vector<PI>, greater<PI>> pq; // min-heap
        set<pair<int, int>> visited; // to keep track of visited index pairs (i,j)
        int n1 = nums1.size(), n2 = nums2.size();
        pq.push({nums1[0] + nums2[0], {0, 0}});
        visited.insert({0, 0});
        // pop out min(k, min-heap size) pairs from min-heap
        while(!pq.empty() && k--)
        {
            auto curr = pq.top();
            pq.pop();
            int i = curr.second.first;
            int j = curr.second.second;
            // (i+1, j) exists and not found in set
            if(i+1 < n1 && visited.find({i+1, j}) == visited.end()) 
            {
                pq.push({nums1[i+1] + nums2[j], {i+1, j}});
                visited.insert({i+1, j});
            }
            // (i, j+1) exists and not found in set
            if(j+1 < n2 && visited.find({i, j+1}) == visited.end())
            {   
                pq.push({nums1[i] + nums2[j+1], {i, j+1}});
                visited.insert({i, j+1});
            }
            ans.push_back({nums1[i], nums2[j]});
        }
        return ans;
    }
};
/*
# for index pairs (i,j)-
# (0,0) forms the pair with the smallest sum as nums1, nums2 are sorted
# for each pair popped from min-heap, the next pair with the smallest sum can be (i+1,j) or (i,j+1)
# a visited set is used to prevent pushing repeated pairs in the heap
# unordered_set does not work with pairs so set is used instead
*/