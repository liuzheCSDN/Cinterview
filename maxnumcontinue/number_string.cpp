//ʹ���ַ�ָ����в���
#include<string>
#include<iostream>
#include<string.h>

using namespace std;

//unsigned int Ϊ "�޷�������"���������Ϊ unsigned int =-20�� int=20 ��������һ����Ϊ "20��
unsigned int MaxContinue(char** outputnum,char* inputstr);
int main() {
	char* input;
	char* b;                                   //��Ҫ�޸ĵ���ָ��b�ĵ�ֵַ
	input = (char*)malloc(sizeof(char) * 20);  // ����20��char���ȵĿռ�
	scanf_s("%s", input);      //����
	printf("%s\n", input);  // ���
	int i = MaxContinue(&b, input);            //input:�Ҳ�������inputָ����ַ�ֵ��&b�Ҳ�������ָ��b����ĵ�ֵַ
	cout << i << endl;
	for (int j = 0; j<i; j++)   // ������Ҫ����ַ�������ʼλ�ã��±��0��ʼ��
	{
		printf("%c", *(b+j));  // ���ַ�����ʽ���"%c"
	}
	system("pause");
	return 0;
}
unsigned int MaxContinue(char** outputnum, char* inputstr) {

	int i = 0;            
	int len = 0;              //��¼��ǰ���ִ��ĳ���
	int Maxlen = 0;           //��������ִ��ĳ���
	int end = 0;              //��¼������ִ��Ľ���λ��
	while (inputstr[i] != '\0') 
	{
		len = 0;//ÿһ���Ȱ�size��0
         //�������֣����ۼ�size
		while (inputstr[i] >= '0'&&inputstr[i] <= '9') 
		{
			len++;
			i++;	
		}
		if (len > Maxlen) //�Ƚ��ж�������ִ��ĳ��Ⱥͽ���λ��
		{
			Maxlen = len;
			end = i - 1;  //���������λ��
		}

		i++;
	}
	*outputnum= (char*)malloc(sizeof(char) * (Maxlen));//������һ��ָ�����͵ı���p��������ָ�붯̬������maxsize���ַ��Ŀռ䣬����ͨ����ָ����з��ʸÿռ�
	*outputnum = inputstr + end - Maxlen + 1;
	return Maxlen;
}