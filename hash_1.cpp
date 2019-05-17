#include <bits/stdc++.h>
using namespace std;
int main()
{
	//declaring an array
	int a[] = { 9, 4, 3, 2, 5, 2, 1, 0, 4, 3, 5, 10, 15, 12, 18, 20, 19 }; 
	//Calculating the size
    int n = sizeof(a) / sizeof(a[0]);
    int max = *max_element(a,a+n);
    int hash[max+1] = {0};
    //keying done by a
    for(int i = 0;i<n;i++)
    hash[a[i]] += 1;
	for(int i=0;i<max;i++)
	{
		if(hash[i])
		{
			//printing the result
			for(int j = 0;j<hash[i];j++)
			cout<<i<<" ";
		}
	} 
}
