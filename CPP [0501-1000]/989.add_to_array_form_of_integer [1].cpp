class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int index=num.size()-1, carry=0;
        vector<int> ans;
        while(k>0)
        {
            int rem=k%10;
            k=k/10;
            int curr_dig;
            if(index>=0) //when length of nums array >= legnth of k
                curr_dig=rem+num[index]+carry;
            else //when length of nums array < legnth of k
                curr_dig=rem+carry;
            if(curr_dig <= 9)
                carry=0;
            else
            {
                curr_dig-=10;
                carry=1;
            }
            ans.push_back(curr_dig);
            index--;
        }
        while(index>=0) //there are still elements left in nums array 
        {
            int curr_dig=num[index]+carry;
            if(curr_dig <= 9)
                carry=0;
            else
            {
                curr_dig-=10;
                carry=1;
            }
            ans.push_back(curr_dig);
            index--;
        }
        if(carry==1) //final carry is generated from MSB
            ans.push_back(1);
        reverse(ans.begin(),ans.end()); //reverse the ans array to get the answer
        return ans;
    }
};