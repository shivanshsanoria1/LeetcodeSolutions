class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) { //T.C.=O(n) , S.C.=O(1)
        vector<int> ans;
        int n1=nums1.size(), n2=nums2.size(), n3=nums3.size();
        vector<bool> vec1(101,false); //keeps track of num present in nums1
        vector<bool> vec2(101,false); //keeps track of num present in nums2
        vector<bool> vec3(101,false); //keeps track of num present in nums3
        for(int i=0; i<n1; i++)
            vec1[nums1[i]]=true;
        for(int i=0; i<n2; i++)
            vec2[nums2[i]]=true;
        for(int i=0; i<n3; i++)
            vec3[nums3[i]]=true;
        for(int i=1; i<101; i++)
            if((vec1[i] && vec2[i]) || (vec2[i] && vec3[i]) || (vec3[i] && vec1[i]))
                ans.push_back(i);
        return ans;
    }
};