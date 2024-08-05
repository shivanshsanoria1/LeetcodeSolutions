class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    string kthDistinct(vector<string>& arr, int k) {
        int n=arr.size();
        for(int i=0; i<n; i++)
        {
            bool isDistinct = true;
            for(int j=0; j<n; j++)
                if(i != j && arr[i] == arr[j])
                {
                    isDistinct = false;
                    break;
                }

            if(isDistinct && --k == 0)
                return arr[i];
        }

        return "";
    }
};