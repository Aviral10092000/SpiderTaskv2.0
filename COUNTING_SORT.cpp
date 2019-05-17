#include <bits/stdc++.h>
#include <vector>
using namespace std;
int main()
{
	/*
	For simplicity, consider the data in the range 0 to 9. 
	Input data: 1, 4, 1, 2, 7, 5, 2
  1) Take a count array to store the count of each unique object.
  Index:     0  1  2  3  4  5  6  7  8  9
  Count:     0  2  2  0   1  1  0  1  0  0

  2) Modify the count array such that each element at each index 
  stores the sum of previous counts. 
  Index:     0  1  2  3  4  5  6  7  8  9
  Count:     0  2  4  4  5  6  6  7  7  7

	The modified count array indicates the position of each object in 
	the output sequence.
 
  3) Output each object from the input sequence followed by 
  decreasing its count by 1.
  Process the input data: 1, 4, 1, 2, 7, 5, 2. Position of 1 is 2.
  Put data 1 at index 2 in output. Decrease count by 1 to place 
  next data 1 at an index 1 smaller than this index.
  */
	// generating vector <int> a;
	vector<int> a = {23,20,29,21,28,30,21,21};
	// calculating largest and smallest element. Doing so because two handle with negative numbers.
	int max = *max_element(a.begin(),a.end());
	int min = *min_element(a.begin(),a.end());
	int range = max - min + 1;
	//creating two more vectors. keying is done by vector a;
	vector<int> count(range), output(a.size());
	//counting the occurance
	for(int i=0;i<a.size();i++)
	count[a[i]-min]++;
	// the following step is done so that to get the position of the array elements
	for(int i=1;i<range;i++)
	count[i] += count[i-1];
	//output vector will get the positions of the array element
	for(int i=0;i<a.size();i++)
	{
		output[count[a[i]-min]-1] = a[i];//-1 is done because in c, things begin from zero
		count[a[i]-min]--;// done to get a position before it
	}
	//printing the output
	for(int i=0;i<a.size();i++)
	cout<<output[i]<<" ";
}
