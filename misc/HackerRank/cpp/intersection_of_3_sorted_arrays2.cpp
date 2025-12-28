#include<bits/stdc++.h>
using namespace std;

vector<int> array_intersection (int n1, int n2, int n3, vector<int> arr1, vector<int> arr2, vector<int> arr3) {
   // Write your code here
    vector<int> ans;
    int i=0, j=0, k=0;
    while(i < n1 && j < n2 && k < n3)
    {
        if(arr1[i] == arr2[j] && arr2[j] == arr3[k]) // x == y and y == z
        {
            ans.push_back(arr1[i]);
            i++;
            j++;
            k++;
        }
        else if(arr1[i] < arr2[j]) // x < y
            i++;
        else if(arr2[j] < arr3[k]) // y < z
            j++;
        else // x > y and y > z 
            k++;
    }
    return ans;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int n1;
    cin >> n1;
    int n2;
    cin >> n2;
    int n3;
    cin >> n3;
    vector<int> arr1(n1);
    for(int i_arr1 = 0; i_arr1 < n1; i_arr1++)
    {
    	cin >> arr1[i_arr1];
    }
    vector<int> arr2(n2);
    for(int i_arr2 = 0; i_arr2 < n2; i_arr2++)
    {
    	cin >> arr2[i_arr2];
    }
    vector<int> arr3(n3);
    for(int i_arr3 = 0; i_arr3 < n3; i_arr3++)
    {
    	cin >> arr3[i_arr3];
    }

    vector<int> out_;
    out_ = array_intersection(n1, n2, n3, arr1, arr2, arr3);
    cout << out_[0];
    for(int i_out_ = 1; i_out_ < out_.size(); i_out_++)
    {
    	cout << " " << out_[i_out_];
    }
}