/*�ڱ��������ʱ�򱣴�����ֵ��һ���������е�һ�����֣�һ���Ǵ�����

�����Ǳ�������һ�����ֵ�ʱ��

�����һ�����ֺ͵�ǰ���Ǳ����������ͬ��������� 1��

����͵�ǰ���Ǳ�������ֲ�ͬ��������� 1��

���������� 0 ��ʱ�����ǽ���������ָ�Ϊ��ǰ����������λ�ã�������������Ϊ 1��*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int MoreThanHalfNum(vector<int> array,int len)
{
	int count = 1; int result = array[0];
	for (int i = 1; i < len; i++)
	{
		if (array[i] == result)
			count++;
		else if (count == 0)
			result = array[i];
		else
			count--;
	}
	return result;
}
int main()
{
	string  arr_str;
	cin >> arr_str;
	int length = arr_str.length();
	vector<int> arr;         //�����䳤����
	for (int i = 0; i < length; i++)
		arr.push_back(arr_str[i] - '0');
	//for (int i = 0; i < length; i++)
	//	cout << arr[i] << endl;
	int halfNum=MoreThanHalfNum(arr,length);
	cout << halfNum;
	system("pause");
	return 0;
}