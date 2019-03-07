#include<string>
#include<iostream>
#include<string.h>

using namespace std;

int main() {
	string str1;                  // 定义字符串变量, 不是字符数组
	string str2 = "abcdef1234567cvfdvwew43";
	cout << "please input a string" << endl;
	cin >> str1;                 //从键盘输入一个字符串给字符串变量string1
	cout << str2 << endl;
	str2[2] = 'C';               //对其中一个字符进行修改
	cout << str2 << endl;
	str2 = str1;                 //直接用“=”进行赋值，str1和str2长度可以不相同；类似“strcpy(string1,string2);
	cout << str2 << endl;
	str2 = str1 + "abcd";           //连接；类似strcat(连接)
	str2 = str2 + '4';              //单引号表示一个字符变量char，用双引号表示一个字符数组char[]
	cout << str2 << endl;

	system("pause");
	return 0;
}