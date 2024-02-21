class Solution {
public:
    int candy(vector<int>& ratings) { // T.C.=O(n), S.C.=O(n)
        int n=ratings.size();
        // stores number of candies received by each child 
        // while only considering the left or right neighbour rating  
        vector<int> left(n, 1), right(n, 1);

        for(int i=1; i<n; i++)
            // curr rating > left neighbour rating 
            if(ratings[i-1] < ratings[i])
                // curr child gets 1 more candy than its left neighbour
                left[i] = 1 + left[i-1]; 
        for(int i=n-2; i>=0; i--)
            // curr rating > right neighbour rating 
            if(ratings[i] > ratings[i+1])
                // curr child gets 1 more candy than its left neighbour
                right[i] = 1 + right[i+1];

        int ans = 0;
        // for each child take the max of candies 
        // while only considering the left or right neighbour rating  
        for(int i=0; i<n; i++)
            ans += max(left[i], right[i]);
        return ans;
    }
};