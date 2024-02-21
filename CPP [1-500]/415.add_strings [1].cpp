class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1=num1.length(), n2=num2.length(), sum, carry=0, i, j;
        string ans="";
        for(i=n1-1,j=n2-1; i>=0 && j>=0; i--,j--)
        {
            sum=int(num1[i]-'0')+int(num2[j]-'0')+carry;
            if(sum>9) // carry is generated
            {
                sum=sum-10;
                carry=1;
            }
            else
                carry=0;
            ans+=to_string(sum);
        }
        while(i>=0) // num1 has more digits remaining
        {
            sum=int(num1[i]-'0')+carry;
            if(sum>9)
            {
                sum=sum-10;
                carry=1;
            }
            else
                carry=0;
            ans+=to_string(sum);
            i--;
        }
        while(j>=0) // num2 has more digits remaining
        {
            sum=int(num2[j]-'0')+carry;
            if(sum>9)
            {
                sum=sum-10;
                carry=1;
            }
            else
                carry=0;
            ans+=to_string(sum);
            j--;
        }
        if(carry==1) // final carry is generated from MSB
            ans+='1';
        reverse(ans.begin(),ans.end());
        return ans;
    }
};