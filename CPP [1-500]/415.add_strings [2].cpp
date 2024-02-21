class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1=num1.length(), n2=num2.length(), i=n1-1, j=n2-1;
        int sum, carry=0, a, b;
        string ans;
        while(i>=0 || j>=0) // atleast one of the numbers is present
        {
            if(i>=0) // num1 exists
                a=num1[i]-'0';
            else // num1 is finished
                a=0;
            if(j>=0) // num2 exists
                b=num2[j]-'0';
            else // num2 is finished
                b=0;
            sum=a+b+carry;
            carry=sum/10;
            sum=sum%10;
            ans.push_back(sum+'0');
            i--;
            j--;
        }
        if(carry==1) // final carry is generated from MSB
            ans+='1';
        reverse(ans.begin(),ans.end());
        return ans;
    }
};