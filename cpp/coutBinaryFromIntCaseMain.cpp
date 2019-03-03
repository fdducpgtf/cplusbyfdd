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
		cout << i << "的二进制为:----->"<< s<<endl;
	
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
//连续使用下面的函数时，必须在进入下次前传入负数（负int)清空字符串。
//否则，得到的结果会被累计添加。
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