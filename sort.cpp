#include <iostream>
using namespace std;
int static count =0;
void BubbleSort(int arr[], int n)
{
	for(int i=0; i<n; i++)
	{
	
		
		for(int j=0; j< n-1; j++)
		{
			if(arr[j]> arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				
				count++;
			}
		}
		
	}
}

void CombSort(int arr[], int n)
{
	int gap = n;
	bool swapped = true;
	while (gap>1 || swapped)
	{
		gap = gap/1.3;
		if(gap<1) gap = 1;
		swapped = false;
		for( int i = 0; i + gap < n; i++)
		{
			if(arr[i]> arr[gap + i])
			{
				int temp = arr[gap + i];
				arr[gap+i]= arr[i];
				arr[i]=temp;
				
				swapped = true;
			}
		}
	}
	
}

void InsertionSort(int arr[], int n)
{
	for(int i = 1; i<n; i++)
	{
		int key = arr[i];
		int j = i-1;
		while(j>=0 && arr[j]>key)
		{
			arr[j+1]= arr[j];
			j--;
		}
			arr[j+1] = key;
	}
}

void SelectionSort(int arr[], int n)
{
	for(int i =0; i<n-1; i++)
	{
		int min_index = i;
		
		for(int j = i + 1; j<n; j++)
		{
		
			if(arr[j] < arr[min_index])
			{
				min_index = j;
				
			}
		}
			if(min_index!=i)
			{
				int temp = arr[i];
				arr[i]=arr[min_index];
				arr[min_index] = temp;
			}
		
	}
}
int main()
{
	int arr[5] = {11,17,8,9,21};
	SelectionSort(arr, 5);
	for(int i = 0; i<5; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
//	cout<< "The no. of swapping in the program is "<<count;
}
