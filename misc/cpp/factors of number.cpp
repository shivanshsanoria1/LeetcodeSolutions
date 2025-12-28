#include <iostream>
using namespace std;

void factorPairs(int n) // T.C.=O(sqrt(n)) ; A.S.=O(1)
{
	for(int i=1; i*i<=n; i++) // i<=sqrt(n)
	{
		if(n%i==0)
		{
			if(i==n/i) // equal factors
				cout << i << " ";
			else
				cout << i << " " << n/i << " "; 
		}
	}
}

int main()
{
	int n=36;
	factorPairs(n);
	return 0;
}