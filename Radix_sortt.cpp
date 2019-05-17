#include <bits/stdc++.h>
using namespace std;
int main()
{
	/*
	Basic idea
	Let original, unsorted list:
	170, 45, 75, 90, 802, 24, 2, 66
	Sorting by least significant digit (1s place) gives: [*Notice that we keep 802 before 2, because 802 occurred before 2 in the original list, and similarly for pairs 170 & 90 and 45 & 75.]
	170, 90, 802, 2, 24, 45, 75, 66
	Sorting by next digit (10s place) gives: [*Notice that 802 again comes before 2 as 802 comes before 2 in the previous list.]
	802, 2, 24, 45, 66, 170, 75, 90
	Sorting by most significant digit (100s place) gives:
	2, 24, 45, 66, 75, 90, 170, 802
	*/
	
	//creating arr array
	int arr[] = {233, 488, 7 ,89,1};
	int n = sizeof(arr)/sizeof(arr[0]);
	//getting largest element
	int max = *max_element(arr,arr+n);
	for(int i=1;max/i>0;i = i*10)
	{
		//Same from here, counting sort
		int a[10] = {0};
		int output[n];
		for(int j=0;j<n;j++)
		a[(arr[j]/i)%10]++;
		for(int j=1;j<10;j++)
		a[j] += a[j-1];
		for(int j=n-1;j>=0;j--)
		{
			output[a[(arr[j]/i)%10]-1] = arr[j];
			a[(arr[j]/i)%10]--;
		}
		for(int j=0;j<n;j++)
		arr[j] = output[j];
	}
	for(int i=0;i<n;i++)
	cout<<arr[i]<<" ";
}
