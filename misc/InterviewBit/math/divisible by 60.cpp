int Solution::divisibleBy60(vector<int> &arr) {
    int n=arr.size();
    if(n==1) //1 digit number
        return arr[0]==0 ? true : false; //0 is divisible by 60
    int digs[10]={0}; //counts freq of digits
    int sum=0;
    for(int i=0; i<n; i++)
    {
        digs[arr[i]]++;
        sum+= arr[i];
    }
    if(digs[0]>0 && sum%3==0)
    {
        digs[0]--;
        if(digs[0]>0 || digs[2]>0 || digs[4]>0 || digs[6]>0 || digs[8]>0) //atleast 1 even digit must be present besides a zero used above
            return true;
    }
    return false;
}
