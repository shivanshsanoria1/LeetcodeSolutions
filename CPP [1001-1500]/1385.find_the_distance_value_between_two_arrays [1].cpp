class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) { // T.C.=O(n1*n2), S.C.=O(1)
        int count = 0;
        for(int i=0; i<arr1.size(); i++)
        {
            bool include = true;
            for(int j=0; j<arr2.size(); j++)
                if(abs(arr1[i] - arr2[j]) <= d)
                {
                    include = false;
                    break;
                }
            if(include)
                count++;
        }
        return count;
    }
};