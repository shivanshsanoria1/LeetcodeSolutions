#include <iostream>
#include <vector>
using namespace std;

void factorPairs(int n) // T.C.=O(sqrt(n)) ; A.S.=O(sqrt(n))
{
	vector<int> v;
	for(int i=1; i*i<=n; i++) // i<=sqrt(n)
	{
		if(n%i==0)
		{
			cout << i << " "; // print the smaller factor
			if(i!=n/i) // unequal factors
				v.push_back(n/i); // push the larger factor in vector
		}
	}
	for(int i=v.size()-1; i>=0; i--)
	{
		cout << v[i] << " ";
		v.pop_back();
	}
}

int main()
{
	int n=28;
	factorPairs(n);
	return 0;
}