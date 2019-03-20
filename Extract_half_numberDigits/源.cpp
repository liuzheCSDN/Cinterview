/*在遍历数组的时候保存两个值：一个是数组中的一个数字，一个是次数。

当我们遍历到下一个数字的时候，

如果下一个数字和当前我们保存的数字相同，则次数加 1；

如果和当前我们保存的数字不同，则次数减 1；

当次数减到 0 的时候，我们将保存的数字改为当前遍历所处的位置，并将次数更改为 1。*/

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
	vector<int> arr;         //声明变长数组
	for (int i = 0; i < length; i++)
		arr.push_back(arr_str[i] - '0');
	//for (int i = 0; i < length; i++)
	//	cout << arr[i] << endl;
	int halfNum=MoreThanHalfNum(arr,length);
	cout << halfNum;
	system("pause");
	return 0;
}