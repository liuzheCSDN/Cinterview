#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	int len;                            //输入字节数组长度
	cin >> len;
	vector<long long> lens(len);
	for (int i = 0; i < len; ++i) {
		cin >> hex >> lens[i];         //字节数组中的元素，输入的是16进制数
	}

	int num; 
	cin >> num;                       //解析数值的个数ElementNum
	vector<int> nums(num);            //定义一个包含num个int元素的STL向量
	for (int i = 0; i < num; ++i) {
		cin >> dec >> nums[i];        //每个数值所占的bit数
	}

	vector<bool> bits;
	//len的值分别是98，128,0（0x62 0x80 0x00）
	for (int len : lens) {            //遍历lens中的值,for(元素类型t 元素变量x : 遍历对象obj)
		for (int i = 0x80; i; i >>= 1) {    //i是判断条件，为0时退出；i>>=1将i的二进制值右移1
			bits.push_back(len&i);          //使用1000 0000对0x62（0110 0010）做"与"运算，将"1""0"提取出来分别存入bits向量
		}
	}

	int start = 0;
	long long result = 0;
	for (int num : nums) {   //nums中存 4,5
		for (int i = 0; i<num; ++i) {
			result = 2 * result + bits[i + start];  //取出4个bit位，将其转换为十进制
		}
		cout << result << endl;

		result = 0;
		start += num;                     //设置第二次循环的起始bit位
	}
	system("pause");
	return 0;
}