class Solution {
public:
    // T.C.=O(n1 + n2 + m1), S.C.=O(m1)
    // m1: max-element in arr1[] (limited to 1000 here)
    // Counting-sort
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // Step-1: find the max-element in arr1[]
        int m1 = *max_element(arr1.begin(), arr1.end());

        // Step-2: find the freq of each element in arr1[]
        vector<int> freq1(m1 + 1, 0);
        for(int num1: arr1)
            freq1[num1]++;
        
        // Step-3: find all elements in arr1[] in the order they appear in arr2[]
        vector<int> ans;
        for(int num2: arr2)
            while(freq1[num2] > 0)
            {
                ans.push_back(num2);
                freq1[num2]--;
            }
        
        // Step-4: find all elements in arr1[] which are not found in arr2[]
        for(int i=0; i<=m1; i++)
            while(freq1[i] > 0)
            {
                ans.push_back(i);
                freq1[i]--;
            }
        
        return ans;
    }
};