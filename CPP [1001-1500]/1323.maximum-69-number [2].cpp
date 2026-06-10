class Solution {
public:
    int maximum69Number (int num) {
        string s= to_string(num); //convert int to string
        for(int i=0; i<s.length(); i++) //change the 1st 6 to 9 starting from MSB to LSB
        {
            if(s[i]=='6')
            {
                s[i]='9';
                break;
            }
        }
        return stoi(s); //convert the modified string to int
    }
};