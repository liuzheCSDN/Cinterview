//ʹ���ַ�������в���

#include<string>
#include<iostream>
#include<string.h>

using namespace std;

unsigned int MaxContinue(char* outputnum,char* inputstr) {

	int i = 0;
	int len = 0;              //��¼��ǰ���ִ��ĳ���
	int Maxlen = 0;           //��������ִ��ĳ���
	int end = 0;              //��¼������ִ��Ľ���λ��
	while (inputstr[i] != '\0')
	{
		len = 0;//ÿһ���Ȱ�size��0
				//�������֣����ۼ�size
		while (inputstr[i] >= '0' && inputstr[i] <= '9')
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
	for (int j = 0; j < Maxlen; j++)

		outputnum[j] = inputstr[end-Maxlen+1+j];
	return Maxlen;
}

int main() {
	char input[20];                                
	char b[20]="";
	gets_s(input);      //����
	puts(input);  // ���
	int i = MaxContinue(b,input);            
	cout << i << endl;
	cout << b;
	system("pause");
	return 0;
}
