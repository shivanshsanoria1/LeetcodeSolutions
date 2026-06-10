class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        // calculate the sum without flipping any node
        long long int finalSum = 0;
        for(int num: nums)
            finalSum += num;

        // count the +ive and 0 diff nodes
        int posDiffCount = 0;
        int zeroDiffCount = 0;
        for(int num: nums)
        {
            int diff = (num ^ k) - num;

            if(diff > 0)
            {
                posDiffCount++;
                finalSum += diff;
            }
            else if (diff == 0)
                zeroDiffCount++;
        }
        
        // each +ive diff node can be flipped by 
        // pairing it with another +ive or zero diff node
        if(posDiffCount % 2 == 0 || zeroDiffCount > 0)
            return finalSum;
        
        // at this point, 1 +ive diff node is left unpaired :(

        int leastPosDiff = INT_MAX;
        int leastNegDiff = INT_MIN;
        for(int num: nums)
        {
            int diff = (num ^ k) - num;

            if(diff > 0)
                leastPosDiff = min(leastPosDiff, diff);
            else if(diff < 0)
                leastNegDiff = max(leastNegDiff, diff);
        }

        // pair up the least +ive diff and least -ive diff nodes
        if(leastPosDiff + leastNegDiff > 0)
            finalSum += leastNegDiff;
        // leave the least +ive diff node unpaired
        else
            finalSum -= leastPosDiff;

        return finalSum;
    }
};
/*
# this is a very weird ques

# if we modify the edge A--B, then A becomes A^k and B becomes B^k
  now if this edge is modified again, then A^k becomes A^k^k and B becmoes B^k^k
  since, we know that x^y^y = x^(y^y) = x^0 = x
  so, doing 2 operations on an edge returns its nodes to their original value
# Therefore each node can be in 2 states: 
  1. x (original value)
  2. x^k (flipped value)

# in a tree, any 2 nodes are connected with a unique path
# if we take starting node as A and ending node as B, 
  then the path from A to B looks like: 
  A -- (I1 -- I2 -- ... -- In) -- B
  where (I1, I2, ..., In) are intermediate nodes
  if we modify each edge in this path while moving from A to B,
  then all the intermediate nodes are flipped 2 times while
  the starting and ending nodes are flipped only once
# Therefore we can take any 2 random nodes in the graph and
  modify them in the same way as if they were directly connected with an edge

# at this point we can realize that we don't need the edges at all

# now we calculate the difference (x^k - x) for each node with value x.
  if this diff is +ive then its optimal to flip this node, while 
  if this diff is -ive then its optimal to leave this node 

# if there are even num of +ive diff nodes, 
  then each of them can be flipped by making pairs among them

# if there are odd num of +ive diff nodes, then 1 node is left unpaired.
  so we check if there is some 0 diff node to pair up with this remaining node.

# if there is no 0 diff node, then we have to check for a -ive diff node with 
  the least absolute value, ie, least -ive diff node.
# its optimal to include this least -ive diff node, 
  if the its absolute value is smaller than the least +ive diff node, ie,
  least +ive diff + least -ive diff > 0
# otherwise its better to leave the least +ive diff unpaired, 
  ie, unflipped, ie, in its original value
*/