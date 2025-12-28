// link: "https://www.geeksforgeeks.org/problems/aggressive-cows/1"

class Solution {
private:
    // returns true if 'cows' cows can be placed in stalls with
    // a min-dist of 'dist' between them
    // 2-pointer
    bool check(vector<int>& stalls, int cows, int dist){
        int left = 0, right = 1;
        cows--; // 1st cow can always be placed in the 1st stall
        
        while(cows > 0 && right < stalls.size())
        {
            if(stalls[right] - stalls[left] >= dist)
            {
                left = right;
                cows--;
            }
            
            right++;
        }
        
        return cows == 0;
    }

public:
    // T.C.=O(n*log(n) + n*log(m)), S.C.=O(1)
    // m: max-val in stalls[]
    // Sorting + Binary-search
    int solve(int n, int k, vector<int> &stalls) {
        // Write your code here
        
        sort(stalls.begin(), stalls.end());
        
        // min-dist possible
        int left = 1; 
        // max-dist possible
        int right = stalls[n-1] - stalls[0];
        
        int ans = -1;
        
        while(left <= right)
        {
            int mid = left + (right - left)/2;
            
            if(check(stalls, k, mid))
            {
                ans = mid;
                left = mid + 1;
            }
            else
                right = mid - 1;
        }
        
        return ans;
    }
};