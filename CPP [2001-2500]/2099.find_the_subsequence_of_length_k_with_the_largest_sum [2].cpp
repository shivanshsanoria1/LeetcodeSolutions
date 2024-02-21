class Cmp {
public:
    typedef pair<int, int> PI;

    // sort in descending order of 'first' and 'second' for each pair
    bool operator()(PI &a, PI &b){
        return a.first == b.first ? a.second < b.second : a.first < b.first;
    }
};

class Solution {
public:
    typedef pair<int, int> PI;

    vector<int> maxSubsequence(vector<int>& nums, int k) { // T.C.=O(n*logn + k*logk), S.C.=O(n+k)
        vector<int> ans;
        int n = nums.size();
        priority_queue<PI, vector<PI>, Cmp> pq; // max-heap
        // sort in decreasing order of num (and decreasing index if num are equal)
        for(int i=0; i<n; i++)
            pq.push({nums[i], i}); // num -> index
        vector<PI> temp;
        // pop k elements from heap and push them in the temp vector
        while(k--)
        {
            auto curr = pq.top();
            temp.push_back({curr.second, curr.first}); // index -> num
            pq.pop();
        }
        // sort the first k elements in increasing order of index
        sort(temp.begin(), temp.end());
        // push the num corresponding to the indexes of the correct subsequence
        for(auto it: temp)
            ans.push_back(it.second);
        return ans;
    }
};
/*
# the comparator function for priority_queue-
# requires its own class,
# works opposite to a regular comparator function (for some reason ??)
# for a regular comparator function: a < b sorts in increasing order
# for a priority_queue comparator function: a < b sorts in decreasing order
*/