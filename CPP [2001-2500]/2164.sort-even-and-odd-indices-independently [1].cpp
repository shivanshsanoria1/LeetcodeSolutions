class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        int n=nums.size();
        if(n<=2)
            return nums;
        vector<int> even; //stores the even index nums
        vector<int> odd; //stores the odd index nums
        for(int i=0; i<n; i=i+2)
            even.push_back(nums[i]);
        for(int i=1; i<n; i=i+2)
            odd.push_back(nums[i]);
        sort(even.begin(),even.end()); //sort even index nums in ascending order
        sort(odd.begin(),odd.end()); //sort odd index nums in ascending order
        int index=0;
        for(int i=0; i<n; i=i+2)
        {
            nums[i]=even[index];
            index++;
        }
        index=odd.size()-1;
        for(int i=1; i<n; i=i+2) //add odd array in reverse order
        {
            nums[i]=odd[index];
            index--;
        }
        return nums;
    }
};