class Solution {
public:
    int digitSum(int n)
    {
        int sum=0;
        while(n>0)
        {
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
        
    int countLargestGroup(int n) {
        unordered_map<int,int> mp; //digit sum -> freq
        int max_freq=0, c=0;
        for(int i=1; i<=n; i++)
            mp[digitSum(i)]++;
        for(auto it: mp)
        {
            if(it.second > max_freq) //new max freq is found
            {
                max_freq= it.second; //update the max freq
                c=1; //reset the count to 1
            }
            else if(it.second == max_freq) //same max freq is found
                c++; //increment the count
        }
        return c;
    }
};