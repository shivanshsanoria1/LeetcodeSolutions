#include <iostream>
using namespace std;

void dec_to_bin(int n)
{
	int binarr[32]; // array storing binary
	int i=0;
	while(n>0)
	{
		binarr[i]=n%2;
		n=n/2;
		i++;
	}
	for(int j=i-1;j>=0;j--)
		cout << binarr[j];
}

int main()
{
	int n=17;
	dec_to_bin(n);
	return 0;
}