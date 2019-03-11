#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	int len;                            //�����ֽ����鳤��
	cin >> len;
	vector<long long> lens(len);
	for (int i = 0; i < len; ++i) {
		cin >> hex >> lens[i];         //�ֽ������е�Ԫ�أ��������16������
	}

	int num; 
	cin >> num;                       //������ֵ�ĸ���ElementNum
	vector<int> nums(num);            //����һ������num��intԪ�ص�STL����
	for (int i = 0; i < num; ++i) {
		cin >> dec >> nums[i];        //ÿ����ֵ��ռ��bit��
	}

	vector<bool> bits;
	//len��ֵ�ֱ���98��128,0��0x62 0x80 0x00��
	for (int len : lens) {            //����lens�е�ֵ,for(Ԫ������t Ԫ�ر���x : ��������obj)
		for (int i = 0x80; i; i >>= 1) {    //i���ж�������Ϊ0ʱ�˳���i>>=1��i�Ķ�����ֵ����1
			bits.push_back(len&i);          //ʹ��1000 0000��0x62��0110 0010����"��"���㣬��"1""0"��ȡ�����ֱ����bits����
		}
	}

	int start = 0;
	long long result = 0;
	for (int num : nums) {   //nums�д� 4,5
		for (int i = 0; i<num; ++i) {
			result = 2 * result + bits[i + start];  //ȡ��4��bitλ������ת��Ϊʮ����
		}
		cout << result << endl;

		result = 0;
		start += num;                     //���õڶ���ѭ������ʼbitλ
	}
	system("pause");
	return 0;
}