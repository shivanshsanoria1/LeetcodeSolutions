#include <iostream>
#include <vector>
#include <string>
#include <random>

using namespace std;

class Sorting{
private:
    // T.C.=O(n^2), S.C.=O(1) | Stable | In-place
    static void bubbleSort(vector<int>& nums){
        int n = nums.size();
        
        for(int i=0; i<n-1; i++){
            bool isSwapped = false;
    
            for(int j=0; j<n-i-1; j++)
                if(nums[j] > nums[j+1]){
                    swap(nums[j], nums[j+1]);
                    isSwapped = true;
                }
    
            if(!isSwapped)
                break;
        }
    }
    
    // T.C.=O(n^2), S.C.=O(1) | Unstable | In-place
    static void selectionSort(vector<int>& nums){
        int n = nums.size();
        
        for(int i=0; i<n-1; i++){
            int minVal = nums[i];
            int idx = i;
    
            for(int j=i+1; j<n; j++)
                if(nums[j] < minVal){
                    minVal = nums[j];
                    idx = j;
                }
                
            if(idx != i)
                swap(nums[i], nums[idx]);
        }
    }
    
    // T.C.=O(n^2), S.C.=O(1) | Stable | In-place
    static void insertionSort(vector<int>& nums){
        int n = nums.size();
        
        for(int i=1; i<n; i++){
            for(int j=i; j>0; j--){
                if(nums[j-1] > nums[j])
                    swap(nums[j-1], nums[j]);
                else
                    break;
            }
        }
    }
    
    static void merge(vector<int>& nums, int left, int mid, int right){
        vector<int> temp1;
        for(int i = left; i <= mid; i++)
            temp1.push_back(nums[i]);
    
        vector<int> temp2;
        for(int i = mid + 1; i <= right; i++)
            temp2.push_back(nums[i]);
    
        int i=0, j=0;
        int k = left;
    
        for(; i < temp1.size() && j < temp2.size(); k++){
            if(temp1[i] <= temp2[j]){
                nums[k] = temp1[i];
                i++;
            }else{
                nums[k] = temp2[j];
                j++;
            }
        }
    
        for(;i < temp1.size(); i++, k++)
            nums[k] = temp1[i];
    
        for(;j < temp2.size(); j++, k++)
            nums[k] = temp2[j];
        
    }
    
    // T.C.=O(n*log(n)), S.C.=O(n) | Stable | Not In-place
    static void mergeSort(vector<int>& nums, int left, int right){
        if(left >= right)
            return;
    
        int mid = left + (right - left)/2;
    
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
    
        merge(nums, left, mid, right);
    }

public:
    bool enableLog;
    
    Sorting(){
        this->enableLog = true;
    }
    
    static void print(const vector<int>& nums){
        for(int num: nums)
            cout<<num<<" ";
        cout<<endl;
    }
    
    void runAlgo(vector<int>& nums, string algo){
        if(enableLog){
            cout<<"Before Sorting: ";
            print(nums);   
        }
        
        if(algo == "bubble"){
            if(enableLog)
                cout<<"Running Bubble-sort..."<<endl;
            bubbleSort(nums);
        }else if(algo == "selection"){
            if(enableLog)
                cout<<"Running Selection-sort..."<<endl;
            selectionSort(nums);
        }else if(algo == "insertion"){
            if(enableLog)
                cout<<"Running Insertion-sort..."<<endl;
            insertionSort(nums);
        }else if(algo == "merge"){
            if(enableLog)
                cout<<"Running Merge-sort..."<<endl;
            mergeSort(nums, 0, nums.size() - 1);
        }else{
            if(enableLog)
                cout<<"Invalid algo. name"<<endl;
            return;
        }
        
        if(enableLog){
            cout<<"After Sorting: ";
            print(nums);
            cout<<string(30, '-')<<endl<<endl;
        }
    }
    
    static vector<int> generateRandomVector(int n, int minVal, int maxVal){
        if(minVal > maxVal){
            cout<<"Min-value must be <= Max-value"<<endl;
            return {};
        }
        
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(minVal, maxVal);
        
        vector<int> nums;
        for(int i=0; i<n; i++)
            nums.push_back(distrib(gen));
            
        return nums;
    }
};

int main() {
    Sorting st;
    vector<int> nums = st.generateRandomVector(10, 1, 50);
    
    // st.runAlgo(nums, "bubble");
    // st.runAlgo(nums, "selection");
    // st.runAlgo(nums, "insertion");
    st.runAlgo(nums, "merge");
    
    return 0;
}