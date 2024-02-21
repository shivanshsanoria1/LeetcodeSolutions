class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> ans;
        vector<int> vec(10,0); //count of digits present in the array digits
        for(int i=0; i<digits.size(); i++)
            vec[digits[i]]++;
        for(int num=100; num<1000; num=num+2) //generate all 3 digit even numbers, num is of the form ABC
        {
            int n=num;
            vector<int> temp=vec;
            int c=n%10;
            temp[c]--;
            if(temp[c] < 0)
                continue;
            n/=10;
            int b=n%10;
            temp[b]--;
            if(temp[b] < 0)
                continue;
            n/=10;
            int a=n%10;
            temp[a]--;
            if(temp[a] < 0)
                continue;
            ans.push_back(num);
        }
        return ans;
    }
};