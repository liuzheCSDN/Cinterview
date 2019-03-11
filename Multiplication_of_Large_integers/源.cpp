#include <iostream>  
#include <string>
#include <vector>
using namespace std;


int multiply(const string strMultiplierA, const string strMultiplierB, string &strRst)
{
	//�����Ƿ��г������ַ�����Ϊ��  
	if (strMultiplierA.empty() || strMultiplierB.empty())
		return -1;

	string strA = strMultiplierA;
	string strB = strMultiplierB;
	int lenA = strA.length();
	int lenB = strB.length();
	int strRst_length = 0;
	int lenC = (lenA + 1)*(lenB + 1);
	// ������һ�� int ����lenC��Ԫ�أ���ֵ��Ϊ0��vecotr����pC
	vector<int> pC(lenC, 0); //�����ŵĽ��  
	vector<int> pA(lenA, 0); //�����ŵĳ���A
	vector<int> pB(lenB, 0); //�����ŵĳ���B

	//�ѳ�������ŵ�����pA�У���A��12345����pA��54321  
	for (int index = 0; index != strA.size(); index++)
		pA[lenA - 1 - index] = strA[index] - '0';     //   ��'0'����ַ���ת��Ϊ��������

	for (int index = 0; index != strB.length(); index++)
		pB[lenB - 1 - index] = strB[index] - '0';

	//ÿ��λѭ�����
	for (int iB = 0; iB < lenB; iB++) {
		for (int iA = 0; iA < lenA; iA++) { //pA��ÿ��λѭ����pB[iB]���
											//pC[iA+iB]����iB����λ�����ã���iB��ʮλ�������ڳ˷�������Ҫ����ƶ���λ��  
			int temp = pC[iA + iB] + pA[iA] * pB[iB];
			pC[iA + iB] = temp % 10;//����
			int carry = temp / 10; //��λ  

			int x = iA + iB + 1;
			//lenC�㹻��;��������������ͬʱ����,��λ�п����Ƕ�λ��  
			while (carry != 0) {
				//��λ������0
				pC[x] = pC[x] + carry % 10;//��ǰ���н�λ������ǰ�ѽ�λ�ӵ���ͽ��p[x]��  
				carry = carry / 10;
				x++;
			}
		}
	}

	//�жϽ���м�λ 
	while (lenC--) {
		if (pC[lenC] != 0) {
			strRst_length = lenC + 1;
			break;
		}
	}
	char ch;
	for (int i = strRst_length - 1; i >= 0; i--)  //�ѽ�������ַ����� ��ע�⵹�� 
	{
		ch = pC[i] + '0';                        //����ת�ַ�
		strRst.push_back(ch);
	}
	if (strRst.empty())//������Ϊ0��������ַ���Ϊ��0��  
		strRst = "0";
	return 0;
}


int main() {
	string A;
	string B;
	cin >> A; cin >> B;
	int neg_count = 0;
	if (A[0] == '-') {
		A = A.substr(1, A.size() - 1);
		neg_count++;
	}
		
	if (B[0] == '-') {
		B = B.substr(1, B.size() - 1);
		neg_count++;
	}
			
	string C = "\0";//������
	multiply(A, B, C);
	if(neg_count==1)
		cout << "-";
	cout << C << endl;

	system("pause");
	return 0;

}