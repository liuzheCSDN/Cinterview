#include<iostream>
#include<string>
#include<vector>
using namespace std;


void BubbleSort(int arr[],int len)
{
	for (int i = 1; i < len; i++)//循环len-1次
		for (int j = 0; j < len-i; j++)
			if (arr[j] > arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
}

void BubbleSort2(int arr[], int len)
{
	for (int i = 1; i < len; i++)//循环len-1次
	{
		bool flag = true;
		for (int j = 0; j < len - i; j++)
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flag = false;
			}
		if (flag)
			break;
	}		
}

void BubbleSort3(int arr[], int len)
{
	int pos = 0; 
	int k = len - 1;
	for (int i = 1; i < len; i++)//循环len-1次
	{
		bool flag = true;
		for (int j = 0; j < k; j++)
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flag = false;
				pos = j;
			}
		k = pos;
		if (flag)
			break;
	}
}

void QuickSort(int arr[], int first, int end) {
	if (first < end) {
		int i = first; int j = end;
		//从右边区开始，保证i<j并且arr[i]小于或者等于arr[j]的时候就向左遍历
		while (i < j) {
			while (i<j && arr[i] <= arr[j]) 
				j--;
			if (i < j) {
				int temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
			//对另一边执行同样的操作
			while (i < j && arr[i] <= arr[j]) 
				i++;
			if (i < j) {
				int temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
		int pivot = i;//将i设为新的轴值
		//再对轴值左右进行递归
		QuickSort(arr, first, pivot - 1);
		QuickSort(arr, pivot + 1, end);
	}
}

void InsertSort(int arr[], int len) {
	for (int i = 1; i < len; i++)
		for (int j = i; j > 0; j--) 
			if (arr[j] < arr[j - 1]) {
				int temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}
}

void ShellSort(int arr[], int len) {
	int gap = len;
	while (gap > 1) {
		gap = gap / 3 + 1;
		for (int i = gap; i < len; i += gap)
			for (int j = i; j > 0;j-=gap)
				if (arr[j] < arr[j - gap]) {
					int temp = arr[j];
					arr[j] = arr[j - gap];
					arr[j - gap] = temp;
				}
		for (int m = 0; m < len; m++)
			cout << arr[m]<<" ";
		cout << endl;

	}
}

void SelectSort(int arr[], int len) {
	for (int i = 0; i < len; i++) {
		int mindex = i;
		for (int j = i + 1; j < len; j++) {
			if (arr[j] < arr[mindex])
				mindex = j;
		}
		int temp = arr[mindex];
		arr[mindex] = arr[i];
		arr[i] = temp;
		for (int m = 0; m < len; m++)
			cout << arr[m] << " ";
		cout << endl;
	}
}


int main() {
	int array[6] = { 65,7,23,98,34,65 };
	int length = (int)sizeof(array)/sizeof(array[0]);
	//BubbleSort(array,length);
	//BubbleSort2(array, length);
	//BubbleSort3(array, length);
	//QuickSort(array, 0, length - 1);
	//InsertSort(array,length);
	//ShellSort(array, length);
	SelectSort(array, length);
	for (int i = 0; i < length; ++i)
		cout << array[i] << endl;
	system("pause");
}