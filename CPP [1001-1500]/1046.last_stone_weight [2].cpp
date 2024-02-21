class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n=stones.size();
        if(n==1) //cannot break only 1 stone
            return stones[0];
        int max1, max2; //largest and 2nd largest num in array in each step
        int max1_index, max2_index; //index of max1 and max2
        for(int k=0; k<n-1; k++) //atmost (n-1) steps are required for n stones (breaking 2 stones at a time)
        {
            max1=INT_MIN;
            max2=INT_MIN;
            for(int i=0; i<n; i++) //find max1 and max2 in each step
            {
                if(stones[i] >= max1) //new max1 found
                {
                    max2_index=max1_index; //store max1 index in max2
                    max1_index=i; //update index of max1
                    max2=max1; //store max1 in max2
                    max1=stones[i]; //update max1
                }
                else if(stones[i] > max2) //new max2 found
                {
                    max2_index=i; //update index of max2
                    max2=stones[i]; //update max2
                }
            }
            stones[max1_index]=max1-max2; //replace max1 with (max1-max2) in the array
            stones[max2_index]=0; //replace max2 with 0 in the array
        }
        return stones[max1_index];
    }
};