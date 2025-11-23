class Solution {
public:
    int numTrees(int n) { // Tabulation, T.C.=O(n^2), S.C.=O(n)
        vector<int> dp(n+1, 0);
        dp[0] = 1; // 1 BST possible using 0 nodes (empty tree)
        dp[1] = 1; // 1 BST possible using 1 node (with value 1)
        // tree has i nodes
        for(int i=2; i<=n; i++)
            // root node has value j
            for(int j=1; j<=i; j++)
            {
                int left = dp[j-1]; // num of possible left-subtrees
                int right = dp[i-j]; // num of possible right-subtrees
                dp[i] += left * right;
            }
        return dp[n];
    }
};
// dp[i]: num of BSTs possible using i nodes (with values 1 to i)


/* PYTHON 

class Solution:
    def numTrees(self, n: int) -> int:
        return int(math.factorial(2*n) / (math.factorial(n) * math.factorial(n+1)))

# Math soln.
# num of BSTs with n nodes = nth Catalan number
# nth Catalan number = (2n)! / (n!*(n+1)!)

*/