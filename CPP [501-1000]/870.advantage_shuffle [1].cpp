class Solution {
public:
    // T.C.=O(n*logn), S.C.=O(n)
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> s;
        for(int num: nums1)
            s.insert(num);

        vector<int> ans;
        for(int num: nums2)
        {
            // iterator to the elment just greater than num
            auto itr = s.upper_bound(num);

            if(itr != s.end())
            {
                ans.push_back(*itr);
                s.erase(itr);
            }
            else
            {
                // iterator to the smallest element
                auto startItr = s.begin();
                ans.push_back(*startItr);
                s.erase(startItr);
            }
        }

        return ans;
    }
};