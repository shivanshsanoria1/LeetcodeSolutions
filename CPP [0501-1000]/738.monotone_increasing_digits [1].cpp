class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        if(n>=0 && n<=9) //1 digit numbers always have monotone increasing digits
            return n;
        vector<int> digs;
        int ans=0, index=-1;
        while(n > 0) //fill the digits of n in array (LSB to MSB)
        {
            digs.push_back(n%10);
            n/=10;
        }
        for(int i=0; i<digs.size()-1; i++)
        {
            if(digs[i] < digs[i+1])
            {
                digs[i+1]--;
                index=i; //mark the index where change happens
            }
        }
        for(int i=0; i<=index; i++) //change the digits from index '0' to 'index' to 9
            digs[i]=9;
        for(int i=digs.size()-1; i>=0; i--) //iterate the array in reverse and form the ans
            ans=ans*10+digs[i];
        return ans;
    }
};