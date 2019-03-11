#include<string>
#include<iostream>
#include<string.h>

using namespace std;

//int main() {
//	string str1;                  // 定义字符串变量, 不是字符数组
//	string str2 = "abcdef1234567cvfdvwew43";
//	cout << "please input a string" << endl;
//	cin >> str1;                 //从键盘输入一个字符串给字符串变量string1
//	cout << str2 << endl;
//	str2[2] = 'C';               //对其中一个字符进行修改
//	cout << str2 << endl;
//	str2 = str1;                 //直接用“=”进行赋值，str1和str2长度可以不相同；类似“strcpy(string1,string2);
//	cout << str2 << endl;
//	str2 = str1 + "abcd";           //连接；类似strcat(连接)
//	str2 = str2 + '4';              //单引号表示一个字符变量char，用双引号表示一个字符数组char[]
//	cout << str2 << endl;
//
//	system("pause");
//	return 0;
//}
int main() {

	string str;
	string out;
	cin >> str;
	int i = 0; int Maxlen = 0; int end = 0; int ed;
	while (str[i] != '\0') {
		int count = 0;
		while(str[i] >= '0'&& str[i] <= '9'){
				count++;
				ed = i;
				if (i != str.length() - 1)
					i++;
				else if(i == str.length() - 1) {
					break;
				}
					

		}
		i++;
		if (count > Maxlen) {
			Maxlen = count;
			end = ed;
		}
	}
	cout << Maxlen<<endl<<end<<endl;
	int start = end - Maxlen + 1;
	for (int i = start; i <= end; i++) {
		out = out+str[i];

	}
	cout << out;
	system("pause");
	return 1;
}