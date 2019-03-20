#include<iostream>
#include<string>
#include<vector>
using namespace std;


void BubbleSort(int arr[],int len)
{
	for (int i = 1; i < len; i++)//ѭ��len-1��
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
	for (int i = 1; i < len; i++)//ѭ��len-1��
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
	for (int i = 1; i < len; i++)//ѭ��len-1��
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
		//���ұ�����ʼ����֤i<j����arr[i]С�ڻ��ߵ���arr[j]��ʱ����������
		while (i < j) {
			while (i<j && arr[i] <= arr[j]) 
				j--;
			if (i < j) {
				int temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
			//����һ��ִ��ͬ���Ĳ���
			while (i < j && arr[i] <= arr[j]) 
				i++;
			if (i < j) {
				int temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
		int pivot = i;//��i��Ϊ�µ���ֵ
		//�ٶ���ֵ���ҽ��еݹ�
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