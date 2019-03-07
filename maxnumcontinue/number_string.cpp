//使用字符指针进行操作
#include<string>
#include<iostream>
#include<string.h>

using namespace std;

//unsigned int 为 "无符号整型"，可以理解为 unsigned int =-20和 int=20 输出结果是一样的为 "20”
unsigned int MaxContinue(char** outputnum,char* inputstr);
int main() {
	char* input;
	char* b;                                   //我要修改的是指针b的地址值
	input = (char*)malloc(sizeof(char) * 20);  // 申请20个char长度的空间
	scanf_s("%s", input);      //输入
	printf("%s\n", input);  // 输出
	int i = MaxContinue(&b, input);            //input:我操作的是input指向的字符值，&b我操作的是指针b本身的地址值
	cout << i << endl;
	for (int j = 0; j<i; j++)   // 控制需要输出字符串的起始位置（下标从0开始）
	{
		printf("%c", *(b+j));  // 以字符的形式输出"%c"
	}
	system("pause");
	return 0;
}
unsigned int MaxContinue(char** outputnum, char* inputstr) {

	int i = 0;            
	int len = 0;              //记录当前数字串的长度
	int Maxlen = 0;           //保存最长数字串的长度
	int end = 0;              //记录最大数字串的结束位置
	while (inputstr[i] != '\0') 
	{
		len = 0;//每一趟先把size置0
         //若是数字，则累加size
		while (inputstr[i] >= '0'&&inputstr[i] <= '9') 
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
	*outputnum= (char*)malloc(sizeof(char) * (Maxlen));//定义了一个指针类型的变量p，并给该指针动态分配了maxsize个字符的空间，可以通过该指针进行访问该空间
	*outputnum = inputstr + end - Maxlen + 1;
	return Maxlen;
}