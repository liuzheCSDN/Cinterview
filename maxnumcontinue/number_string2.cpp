//使用字符数组进行操作

#include<string>
#include<iostream>
#include<string.h>

using namespace std;

unsigned int MaxContinue(char* outputnum,char* inputstr) {

	int i = 0;
	int len = 0;              //记录当前数字串的长度
	int Maxlen = 0;           //保存最长数字串的长度
	int end = 0;              //记录最大数字串的结束位置
	while (inputstr[i] != '\0')
	{
		len = 0;//每一趟先把size置0
				//若是数字，则累加size
		while (inputstr[i] >= '0' && inputstr[i] <= '9')
		{
			len++;
			i++;
		}
		if (len > Maxlen) //比较判断最大数字串的长度和结束位置
		{
			Maxlen = len;
			end = i - 1;  //保存结束的位置
		}
		i++;
	}
	for (int j = 0; j < Maxlen; j++)

		outputnum[j] = inputstr[end-Maxlen+1+j];
	return Maxlen;
}

int main() {
	char input[20];                                
	char b[20]="";
	gets_s(input);      //输入
	puts(input);  // 输出
	int i = MaxContinue(b,input);            
	cout << i << endl;
	cout << b;
	system("pause");
	return 0;
}
