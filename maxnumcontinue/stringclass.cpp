#include<string>
#include<iostream>
#include<string.h>

using namespace std;

//int main() {
//	string str1;                  // �����ַ�������, �����ַ�����
//	string str2 = "abcdef1234567cvfdvwew43";
//	cout << "please input a string" << endl;
//	cin >> str1;                 //�Ӽ�������һ���ַ������ַ�������string1
//	cout << str2 << endl;
//	str2[2] = 'C';               //������һ���ַ������޸�
//	cout << str2 << endl;
//	str2 = str1;                 //ֱ���á�=�����и�ֵ��str1��str2���ȿ��Բ���ͬ�����ơ�strcpy(string1,string2);
//	cout << str2 << endl;
//	str2 = str1 + "abcd";           //���ӣ�����strcat(����)
//	str2 = str2 + '4';              //�����ű�ʾһ���ַ�����char����˫���ű�ʾһ���ַ�����char[]
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