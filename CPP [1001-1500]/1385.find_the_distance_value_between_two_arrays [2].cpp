class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int count = 0;
        for(int i=0; i<arr1.size(); i++)
        {
            bool include = true;
            int left = 0, right = arr2.size()-1;
            while(left <= right)
            {
                int mid = left + (right-left)/2;
                if(arr1[i] - arr2[mid] > d)
                    left = mid + 1;
                else if(arr1[i] - arr2[mid] < -d)
                    right = mid - 1;   
                else // -d <= arr1[i] - arr2[mid] <= d
                {
                    include = false;
                    break;
                }
            }
            if(include)
                count++;
        }
        return count;
    }
};
// Binary-search
// T.C.=O(n2*logn2 + n1*logn2), S.C.=O(1)