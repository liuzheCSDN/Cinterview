#include<string>
#include<iostream>
#include<string.h>

using namespace std;

int main() {
	string str1;                  // �����ַ�������, �����ַ�����
	string str2 = "abcdef1234567cvfdvwew43";
	cout << "please input a string" << endl;
	cin >> str1;                 //�Ӽ�������һ���ַ������ַ�������string1
	cout << str2 << endl;
	str2[2] = 'C';               //������һ���ַ������޸�
	cout << str2 << endl;
	str2 = str1;                 //ֱ���á�=�����и�ֵ��str1��str2���ȿ��Բ���ͬ�����ơ�strcpy(string1,string2);
	cout << str2 << endl;
	str2 = str1 + "abcd";           //���ӣ�����strcat(����)
	str2 = str2 + '4';              //�����ű�ʾһ���ַ�����char����˫���ű�ʾһ���ַ�����char[]
	cout << str2 << endl;

	system("pause");
	return 0;
}