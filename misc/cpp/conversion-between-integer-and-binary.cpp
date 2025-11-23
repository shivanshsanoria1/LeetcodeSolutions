#include <bits/stdc++.h>
using namespace std;

// converts a non-negative int to a binary-string
string convertIntToBinaryString(int num){
    if(num < 0)
        return "Invalid";
    
    if(num == 0)
        return "0";
        
    string binStr = "";
    
    while(num > 0)
    {
        // (num % 2) can also be used instead of (num & 1)
        binStr += num & 1 ? "1" : "0";
        // (num /= 2) can also be used instead of (num >>= 1)
        num >>= 1;
    }
    
    reverse(binStr.begin(), binStr.end());
    
    return binStr;
}

// converts a binary-string back to its non-negative int
int convertBinaryStringToInt(string binStr){
    int num = 0;
    
    for(char ch: binStr)
    {
        // (num *= 2) can also be used instead of (num <<= 1)
        num <<= 1;
        num += ch == '1' ? 1 : 0;
    }
    
    return num;
}

int main(){
    vector<int> nums = { 0, 12, 5, 128, 49, 31 };
    
    for(int num: nums)
    {
        string binStr = convertIntToBinaryString(num);
        cout<<num<<" (Decimal) = "<<binStr<<" (Binary)"<<endl;
        
        int originalNum = convertBinaryStringToInt(binStr);
        cout<<binStr<<" (Binary) = "<<originalNum<<" (Decimal)"<<endl;
        
        cout<<endl;
    }
    
    cout<<endl<<string(25, '-')<<endl;
    
    return 0;
}