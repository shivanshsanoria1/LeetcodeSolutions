class Solution {
public:
    // T.C.=O(n1 + n2 + n1*logn1), S.C.=O(n1)
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // Step-1: find the freq of each element in arr1[]
        // num1 -> freq
        unordered_map<int, int> mp1;
        for(int num1: arr1)
            mp1[num1]++;
        
        // Step-2: find all elements in arr1[] in the order they appear in arr2[]
        vector<int> ans;
        for(int num2: arr2)
            while(mp1[num2] > 0)
            {
                ans.push_back(num2);
                mp1[num2]--;
            }
        
        // Step-3: find all elements in arr1[] which are not found in arr2[]
        int idx = ans.size();
        for(auto& [num, freq]: mp1)
            while(freq > 0)
            {
                ans.push_back(num);
                freq--;
            }
        
        // Step-4: sort the elements found only in arr1[]
        sort(ans.begin() + idx, ans.end());
        
        return ans;
    }
};