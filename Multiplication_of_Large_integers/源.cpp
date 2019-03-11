#include <iostream>  
#include <string>
#include <vector>
using namespace std;


int multiply(const string strMultiplierA, const string strMultiplierB, string &strRst)
{
	//测试是否有乘数（字符串）为空  
	if (strMultiplierA.empty() || strMultiplierB.empty())
		return -1;

	string strA = strMultiplierA;
	string strB = strMultiplierB;
	int lenA = strA.length();
	int lenB = strB.length();
	int strRst_length = 0;
	int lenC = (lenA + 1)*(lenB + 1);
	// 创建了一个 int 类型lenC个元素，且值均为0的vecotr容器pC
	vector<int> pC(lenC, 0); //逆序存放的结果  
	vector<int> pA(lenA, 0); //逆序存放的乘数A
	vector<int> pB(lenB, 0); //逆序存放的乘数B

	//把乘数逆序放到数组pA中，若A是12345，则pA是54321  
	for (int index = 0; index != strA.size(); index++)
		pA[lenA - 1 - index] = strA[index] - '0';     //   减'0'会把字符串转化为数字整型

	for (int index = 0; index != strB.length(); index++)
		pB[lenB - 1 - index] = strB[index] - '0';

	//每个位循环相乘
	for (int iB = 0; iB < lenB; iB++) {
		for (int iA = 0; iA < lenA; iA++) { //pA的每个位循环与pB[iB]相乘
											//pC[iA+iB]利用iB起到移位的作用，如iB是十位数，则在乘法计算中要向后移动移位。  
			int temp = pC[iA + iB] + pA[iA] * pB[iB];
			pC[iA + iB] = temp % 10;//余数
			int carry = temp / 10; //进位  

			int x = iA + iB + 1;
			//lenC足够大;大数相加与数相乘同时计算,进位有可能是多位数  
			while (carry != 0) {
				//进位不等于0
				pC[x] = pC[x] + carry % 10;//若前面有进位，则提前把进位加到求和结果p[x]上  
				carry = carry / 10;
				x++;
			}
		}
	}

	//判断结果有几位 
	while (lenC--) {
		if (pC[lenC] != 0) {
			strRst_length = lenC + 1;
			break;
		}
	}
	char ch;
	for (int i = strRst_length - 1; i >= 0; i--)  //把结果放入字符串中 （注意倒序） 
	{
		ch = pC[i] + '0';                        //数字转字符
		strRst.push_back(ch);
	}
	if (strRst.empty())//如果结果为0，则输出字符串为“0”  
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
			
	string C = "\0";//保存结果
	multiply(A, B, C);
	if(neg_count==1)
		cout << "-";
	cout << C << endl;

	system("pause");
	return 0;

}