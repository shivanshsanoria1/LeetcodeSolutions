class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    int numTeams(vector<int>& rating) {
        int n=rating.size();
        int count = 0;

        for(int j=1; j<n-1; j++)
        {
            int leftSmaller = 0, leftLarger = 0;
            for(int i=0; i<j; i++)
            {
                if(rating[i] < rating[j])
                    leftSmaller++;
                else
                    leftLarger++;
            }

            int rightSmaller = 0, rightLarger = 0;
            for(int k=j+1; k<n; k++)
            {
                if(rating[j] > rating[k])
                    rightSmaller++;
                else
                    rightLarger++;
            }

            count += (leftSmaller * rightLarger) + (leftLarger * rightSmaller);
        }

        return count;
    }
};