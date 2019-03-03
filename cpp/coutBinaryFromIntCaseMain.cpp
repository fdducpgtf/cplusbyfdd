#include<iostream>
#include<string>

using namespace std;


void coutBinaryFromInt(int);
string getBinaryStringFromInt(int);
void giveBinaryStringToStringFromInt(int, string&);

int coutBinaryFromIntCaseMain() {

	for (int i = 0;i <= 256;i++) {
		string s="\0";
		
		giveBinaryStringToStringFromInt(i,s);
		cout << i << "�Ķ�����Ϊ:----->"<< s<<endl;
	
	}
	return 0;
}

void coutBinaryFromInt(int val) {
	if (val >= 2) {
		coutBinaryFromInt(val / 2);
		cout << val % 2;
	}
	else {
		cout << val % 2;
	}
}
//����ʹ������ĺ���ʱ�������ڽ����´�ǰ���븺������int)����ַ�����
//���򣬵õ��Ľ���ᱻ�ۼ���ӡ�
string getBinaryStringFromInt(int val) {
	static string binaryString="\0";
	if (val < 0) {
		binaryString.erase();
	}else {
		if (val >= 2) {
			getBinaryStringFromInt(val / 2);
		}
		binaryString.append(to_string(int(val % 2)));
	
	 }
		
	return binaryString;
}


void giveBinaryStringToStringFromInt(int val, string& binaryString) {
	if (val >= 2) {
		giveBinaryStringToStringFromInt(val / 2, binaryString);
	}
	binaryString.append(to_string(int(val % 2)));
}