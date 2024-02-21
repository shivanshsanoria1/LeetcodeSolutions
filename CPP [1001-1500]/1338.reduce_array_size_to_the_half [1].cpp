class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n=arr.size(),n2=n/2,sum=0,c=0;
        map<int,int> freq;
        vector<int> vec;
        for(int i=0; i<n; i++)
            freq[arr[i]]++;
        for(auto it=freq.rbegin(); it!=freq.rend(); it++) // push frequencies in vector
        {
            vec.push_back(it->second);
        }
        sort(vec.begin(),vec.end(),greater<int>()); // sort vector in descending order
        for(int i=0; i<vec.size(); i++)
        {
            sum=sum+vec[i];
            c++;
            if(sum>=n2)
                return c;
        }
        return -1;
    }
};