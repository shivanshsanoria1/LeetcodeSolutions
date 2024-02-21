class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> ans;
        vector<int> vec(10,0); //count of digits present in the array digits
        for(int i=0; i<digits.size(); i++)
            vec[digits[i]]++;
        for(int num=100; num<1000; num=num+2) //generate all 3 digit even numbers, num is of the form ABC
        {
            int c=num%10, b=(num/10)%10, a=num/100; //find the digits c,b,a of the num ABC
            vec[c]--; //decrement the count of c, b, a
            vec[b]--;
            vec[a]--;
            if(vec[c]>=0 && vec[b]>=0 && vec[a]>=0) //all freq remain non -ive after decrements
                ans.push_back(num); //valid num found
            vec[c]++; //restore the freq of c, b, a
            vec[b]++;
            vec[a]++;
        }
        return ans;
    }
};