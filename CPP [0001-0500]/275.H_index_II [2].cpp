class Solution {
private:
    // returns true if there are atleast 'h' elements 
    // greater than or equal to 'h' in nums[]
    bool binarySearch(vector<int>& nums, int h){
        int n=nums.size();
        int left = 0, right = n-1;

        while(left <= right)
        {
            int mid = left + (right - left)/2;

            if(nums[mid] >= h)
            {
                if(n-mid >= h)
                    return true;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }

        return false;
    }

public:
    // T.C.=O((log(n))^2), S.C.=O(1)
    // Binary + Binary search
    int hIndex(vector<int>& citations) {
        int left = 1, right = citations.size();
        int h = 0;

        while(left <= right)
        {
            int mid = left + (right - left)/2;

            if(binarySearch(citations, mid))
            {
                h = mid;
                left = mid + 1;
            }
            else
                right = mid - 1;
        }

        return h;
    }
};
/*
# basically we have the find the max value of a num 'h' such that 
  there are atleast 'h' elements greater than or equal to 'h' in citations[]
# range of 'h' is [0, n]
*/