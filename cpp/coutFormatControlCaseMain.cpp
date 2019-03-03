#include<iostream>
#include<string>
#include<fstream>
#include <iterator>
#include<list>

using namespace std;
//���ַ���խ�ַ���ת��
wstring stringToWstring(const string&);
string wstringToString(const wstring&);
//
int isHasEnter(char*);
int getStrLen(char*);


//��ȡָ�����Ķ������ַ�����ʽ
extern void giveBinaryStringToStringFromInt(int, string&);

//�Զ����ࣺA
class A {
public:
	
	int getvalue();
	/*�����Զ���������������� << ��
	*/
	friend ostream &operator<<(ostream &output, A a) {
		output << a.getvalue();
		return output;
	
	}
#ifdef AOS

	//�����Զ������ָ������������<<��
	friend ostream &operator<<(ostream &output, A *a) {
		output << a->getvalue();
		return output;

	}
#endif // AOS

	
private:
	int value = 22;
};


//******************************************����***************************************
int coutFormatControlCaseMain() {


	

	//cout�ض����ļ����������Ļ-->������ļ�
//#define ONE
#ifdef ONE
	if(1){
		
		//����ԭ�����
		streambuf* old_cout_streambuf = cout.rdbuf();
		//�����ļ������
		ofstream outfile("1.txt");
		//���ļ�������󶨵�cout�������
		cout.rdbuf(outfile.rdbuf());
		//������ݵ�cout��ʵ����������ļ���
		cout << "����cout�ض����ļ����ԣ�" << endl;
		//�ر��ļ�
		outfile.close();
		//��ԭΪĬ�ϵ������
		cout.rdbuf(old_cout_streambuf); 

		
	}


#undef ONE
#endif // ONE


	//cin�ض����ļ�:�Ӽ�������-->���ļ�����
//#define TWO
#ifdef TWO
	if (1) {
		streambuf* old_cin_streambuf = cin.rdbuf();
		ifstream inputfile("1.txt");
		cin.rdbuf(inputfile.rdbuf());
		
		while (!cin.eof()) {
			string s;
			cin >> s;
			cout << s << endl;
		}
		
		inputfile.close();
		cin.rdbuf(old_cin_streambuf);
	}


#undef TWO
#endif // TWO

	
	//�Ӽ������룬ֱ��������ļ�
//#define	THREE
#ifdef THREE
	//��ʵ�Ѿ�֤����get()�Ƿ��ܹ�����������ĸ���ֻ��ţ�ȡ����
	//setlocale�����á�������Ϊ"chs"ʱ�������ܴ��������С�
	//��������û����setlocale()��䣬ȴ�ܹ�����������ĸ�Ȼ��ţ�
	//û�㶮Ϊʲô�����⣡��������
	streambuf* old_cout_streambuf = cout.rdbuf();
	ofstream outputfile("1.txt");
	cout.rdbuf(outputfile.rdbuf());

	const char enter = '\n';
	char before;
	while (cin.good()) {
		before = cin.get();
		cout << before;
		if (before == enter) {//������ֵ�һ������
			
			char current = cin.get();//����ǵڶ������У����˳�
			if (current != enter) {
				cout << current;  //������ʾ    
			}
			else {
				break;//�˳�
			}
		}
		
	}

	outputfile.close();
	cout.rdbuf(old_cout_streambuf);

#undef THREE
#endif // THREE


	//�Ӽ��̻�ȡָ�����͵�����
//#define FOUR
#ifdef FOUR
	//��ȡ��������
	if (0) {
		int input = 0;
		int sum = 0;
		while (cin >> input) {//���Զ������հ��ַ����ո񣬻��У��Ʊ���ȣ�
			sum += input;
		}//ֱ����������ָ�����͵����ݣ��������������֣��ǿհ��ַ��ͻ� �˳�
		cout << "���һ������������ǣ�" << input << endl;//�����ǿհ��ַ�������0
		cout << "����֮��Ϊ��" << sum << endl;
		//���������������ctrl+z+endter)����������input�������һ����Ч�������֡�

		

	}

	//��ȡfloat��double��������,�����������������ֻ�ȡ��ȫһ��
	if (0) {
		double input = 0;
		double sum = 0;

		while (cin >> input) {
			sum += input;
		}
		cout << "���һ��double�����ǣ�" << input << endl;
		cout << "����֮��Ϊ��" << sum << endl;

	}

	//��ȡ�ַ������ݣ��磺char��
	//��ô������ַ���խ�ַ������ǹؼ���	
	if (0) {
		//ע������������һ�ǣ�setlocale()���Ӹ����Ͼ����Ƿ��ܹ�������ַ�խ�ַ�
		//����get()������������������ַ����������հס��ⷽ�㴦�������ĳЩ�����ַ���
		string s = setlocale(LC_ALL, NULL);//������������
		setlocale(LC_ALL, "chs");//����Ϊ������������
		const char enter = '\n';
		char before;
		while (cin.good()) {
			before = cin.get();//���淢�֣�get()���Դ���������ĸ���ֻ��ŵ����
			cout << before;
			if (before == enter) {//������ֵ�һ������

				char current = cin.get();//����ǵڶ������У����˳�
				if (current != enter) {
					cout << current;  //������ʾ    
				}
				else {
					break;//�˳�
				}
			}

		}
		//�ָ��������ã���ǰ������Ҫ�ɶԳ��֡�
		setlocale(LC_ALL, s.c_str());

	}

	//���I/O�쳣
	if (0) {
		int input = 0;
		int sum = 0;
		//���������쳣��ԭ��
		cin.exceptions(ios_base::failbit);
		try {
			while (cin >> input) {
				sum += input;
			}
		}
		catch (ios_base::failure& state) {
			cout << sum << endl;
			if (cin.fail() && (!cin.eof())) {
				cin.clear();
				
				while (!isspace(input=cin.get())) {
					continue;
				}
				

			}
			else {
				cout << "û�а취�ˣ��˳���" << endl;
				exit(1);
			}

		}
		
		cout << "�����������֣�" << endl;
		cin >> input;
		sum += input;
	
		cout << "���һ������������ǣ�" << input << endl;//�����ǿհ��ַ�������0
		cout << "����֮��Ϊ��" << sum << endl;
	}
	/*
		1��ios_base::iostate������I / O����״̬��I / O�����̳���һ���ԡ�
		2������״̬�����֣�eofbit, badbit, failbit(bitmask����)�����ֶ�������״̬Ϊ
		goodbit��
		3������ʱ��λֵΪ��0������ʱΪ1��
		4�������壺eofbit���ļ���β��failbit����ȡ�����磺��ȡ����Ҫ���������ݡ�
		badbit���޷���ϵ�ʧ������
		5��������Щ����״̬�������󣺺���exceptions(iostate)����ʹ�á�
			exceptions()��������ʱ�����ش������롣Ȼ����Զ�������ʶ�����״̬��
			cin.rdstate()Ҳ���Է�����״̬�������������С�
			ǰ��exceptions()�����ÿ����׳���������ͣ�
			���߷��ص�ǰ���õ���Щ��������׳���Ŀ���ǲ�׽����
			�������Ƿ��ص�ǰ����ʵ������״̬��Ŀ����ʶ��ǰ�Ĵ������� ��

		6������������������ͺ󣬿��Բ�׽�����ڿ�����������Ĵ���飬ʹ��
			try {}catch(){}��׽����catch()����Ҫ�������õĴ�����������ϡ�����
			����ʱ�ܲ�׽������ʹ���򲻻����Ī������Ľ���򷵻�ֵ��
		7�����ô���״ֵ̬�����õķ������£�
			clear(iostate)����������д����־��Ȼ������iostateָ���Ĵ����־��
			setstate(iostate)��ֻ����ָ�������־����Ӱ�������õ����������־��
*/
	//��������״̬
	if (0) {
		//�����׳���Щ���������
	
		for (int bit = 0;bit<8 ;bit++) {

			cin.exceptions(std::_Iosb<char>::_Iostate(bit));
			int state = cin.exceptions();
			cout << hex <<showbase<< "[state]:" << state << endl<<endl;
			cout.unsetf(ios_base::hex);
			cout << noshowbase;
			if (state&ios_base::eofbit) {
				cout << "eofbit------>�������ˡ�" << endl;
			}
			else {
				cout << "eofbit------>û�б����á�" << endl;
			}
			if (state&ios_base::failbit) {
				cout << "failbit------>�������ˡ�" << endl;
			}
			else {
				cout << "failbit------>û�б����á�" << endl;
			}
			
			if (state&ios_base::badbit) {
				cout << "badbit------>�������ˡ�" << endl << endl;
			}
			else {
				cout << "badbit------>û�б����á�" << endl<<endl;
			}
			
		}



	}
	if (0) {
		//��״̬����������
		/*clear(iostate)����������д����־��Ȼ������iostateָ���Ĵ����־��
			setstate(iostate)��ֻ����ָ�������־����Ӱ�������õ����������־��*/
	}
#undef FOUR
#endif // FOUR

//#define FIVE
#ifdef FIVE
//��ȡ������ѧϰ
	//get(char&) get()���ص㣺��ȡ�����ַ���
	//��ʹ��setlocale�����޷���ȷ��⺺�ֵȿ��ַ�
	if (0) {
		char c;
		cout << "cin.get(char&)"<< endl;
		while (cin.get(c)) {
			cout << c;
			if (c == '\n') {
				if (cin.get(c)) {
					if (c == '\n') {
						break;
					}
					else {
						cout << c;
					}
				}
				else {
					break;
				}

			}
			

		}

	}
	if (0) {
		char cc;
		cout << "cin.get()" << endl;
		while (cin.good()) {
			cc = cin.get();
			cout << cc;
			if (cc == '\n') {
				cc = cin.get();
				if (cc == '\n') {
					break;
				}
				else {
					cout << cc;
				}
			}
		}



	}

	//cin>>�����������ص㣺�����հס�
	if (0) {
		char c;
		while (cin >> c) {
			cout << c;//���Կհ׷�
			if (c == '`')//���ֻ�����÷ǿհ׵������ַ���Ϊ�˳���־
			{//û�������˳��ַ�������ctrl+z+enter�˳���
				cout << endl;
				break;
			}
		}
	}
	 //����������cin>>��ȡ��ֵ����ȡ������ַ����������֣�
	//�����������б�������ȡ���ִ���ֹͣ
	//����������һ���������ֵ��ַ�Ϊֹ���հ׷����⣩
	if (0) {
		int val=-1;
		//0-9intֵΪ��48-57 .
		while (1) {
			cin >> val;
			//������ֶ�ȡ����valֵ����
			//�����cin����״̬����ȡ�������ַ����ã�ʹcin����
			//����������ȡ���룬�������������˳���
			cout << "state:"<<cin.rdstate() << endl;
			if (cin.rdstate()) {
				
				cin.clear();//�������״̬
				while (1) {
					if (cin.peek() == -1)//������������β
							exit(1);//���˳�
					//�����������һ���ַ����������0-9������
					//�Ͷ�����������
					if ((cin.peek() < 48) || (cin.peek() > 57)) {
						
						cout << "lastint:"<<cin.get() << endl;
					}
						
					else
						break;//������һ���ַ������־��˳��������ȡ���á�ѭ��
				}
			}
			else {
				cout << val << endl;//��ȡʱû�д��������Ҫ��ֵ
			}
		}
		

	}

	//get(char*,int,char) ,get(char*,int)
	//ͨ�����벻ͬ������ͬ�ַ�����ָ��������з����ļ���β���ȣ�
	//�˽�cin.get(char*,int,char)�Ķ�ȡ����
	if (0) {
		const int size = 7;
		char str[size];
		char demarcation = ' ';

		cin.get(str, size, demarcation);
		cout << "str:" << str << "--Len:" << getStrLen(str) << "--Enter:" << isHasEnter(str) << endl;
		cout << "state:" << cin.rdstate() << endl;
		cout << "��һ���ַ���intֵ�ǣ�" << cin.peek() << endl;

		cin.get(str, size, demarcation);
		cout << "str:" << str << "--Len:" << getStrLen(str) << "--Enter:" << isHasEnter(str) << endl;
		cout << "state:" << cin.rdstate() << endl;
		cout << "��һ���ַ���intֵ�ǣ�" << cin.peek() << endl;

		cin.get(str, size, demarcation);
		cout << "str:" << str << "--Len:" << getStrLen(str) << "--Enter:" << isHasEnter(str) << endl;
		cout << "state:" << cin.rdstate() << endl;
		cout << "��һ���ַ���intֵ�ǣ�" << cin.peek() << endl;

		//1.��ȡֹͣ��ԭ���ǣ���һ���ǲ���ָ���ķָ���demarcation
			//�����Ƿ�Ϊ��β����EOF����cinΪctrl+z)������ôζ�ȡ����ֹͣ��
			//���ǣ����������������ʱ������һ���ַ�ʼ��Ϊ����β������ֵΪ-1��
			//�ڶ����Ƿ�ﵽ����ַ�����ָ���Ĵ�СҪ��һ��������������ôζ�ȡ����ֹͣ��
			//�������Ƿ�Ϊ��β����EOF����cinΪctrl+z)������ôζ�ȡ����ֹͣ��
					//���һ����ͬ�����ȡ�
					//�ر�ע�⣺�ڻ����������Ѿ������ǰ���£�ǰһ���ַ�Ϊenter֮���ctrl+z��
					//�ű���Ϊ��β
					//����ctrl+z�ᱻ��һ���ַ����롣
			//���ģ����з���������ֹͣ��ȡ�����Ǽ��ϻ��з��պö�����ֹͣ��
					//���з��ǿ��Զ���ȥ�ģ�������ԡ�
					//�������ǻ���Ե�ǰ�����һ�����з����������������У�
					//����һ�ζ�ȡʱ���ᱻ����һ���ַ���ȡ��
			//���壬��������ˢ�£�����һ���ǰ��»��з���enter)֮���ˢ�£�
					//����һ�ζ�ȡ���ַ��ڵ�ǰ�Ļ�������ȫ�ܹ���������������ȡ��ʱ��
					//���ᱻ�Զ�ˢ�¶�ȡ��������ֹһ�Σ�ֻҪ�������ڵ��ַ��㹻������Ҫ��
	}
	

	//��get()��ɶ��������ݸ��ݻ��з��ͷָ����������ַ������ӷ��㡣
	//get(char*,int,char)��̫�鷳��
	if (0) {
		char demarcation = ' ';//�ָ�����
		string str;
		char lastchar[2]="-";
		

		string currentlocale = setlocale(LC_ALL, NULL);
		setlocale(LC_ALL, "chs");
		const char enter = '\n';
		char before;
		
		
		

		while (cin.good()) {
			before = cin.get();
			if ((before == enter) || (before == demarcation)) {

				if ((lastchar[0]== enter) && (before == enter)) {
					break;
				}
				else if ((lastchar[0] == demarcation)||(lastchar[0] == enter) ){
					lastchar[0]=before;
					continue;
				}
				else {
					lastchar[0] = before;
					cout << "str:" << str << endl;
					str.erase();
				}
				

			}
			else {
				lastchar[0] = before;
				str.append(1, before);
			}
			

		}
		
		
	

		setlocale(LC_ALL,currentlocale.c_str());
	}


	//read
	if (0) {
		const int len = 5;
		char s[len];
		s[len - 1] = '\0';
		cin.read(s, len-1);
		cout <<"-"<< s << "-"<<endl;
		cin.read(s, len-1);
		cout << "-" << s << "-" << endl;
		cin.read(s, len-1);
		cout << "-" << s << "-" << endl;
	}
	//����ĩβ���Զ��ӿ��ַ����⣬��get(char*,int)����


	//ignore(int=1,int=EOF)��ȡ������ָ���������ַ���ֱ��ָ�����ַ�Ϊֹ
	//�磺ignore(255,'\n')�������µ�255���ַ���ֱ����һ�����з�Ϊֹ��
#undef FIVE
#endif // FIVE


			
			


			

	return 0;
}


inline int A::getvalue() {
	return A::value;
}




wstring stringToWstring(const string& s) {
	string currentLocale = setlocale(LC_ALL, NULL);//����ΪNULL
	setlocale(LC_ALL, "chs");//�������ĵ���


	//�������������ò��ܽ���������ַ�ת��
	const char* sourceString = s.c_str();
	size_t destWstrinSize = s.size() + 1;
	wchar_t* destWstring = new wchar_t[destWstrinSize];
	size_t num;
	mbstowcs_s(&num, destWstring, destWstrinSize, sourceString, s.size());
	wstring result = destWstring;

	delete[] destWstring;
	setlocale(LC_ALL, currentLocale.c_str());
	return result;




}

string wstringToString(const wstring& ws) {

	string currentLocale = setlocale(LC_ALL, NULL);
	setlocale(LC_ALL, "chs");

	const wchar_t* sourceWstring = ws.c_str();
	size_t destStringSize = ws.size() + 1;

	char* destString = new char[destStringSize];

	size_t num;

	wcstombs_s(&num, destString, destStringSize, sourceWstring, ws.size());

	string result = destString;
	delete[] destString;
	setlocale(LC_ALL, currentLocale.c_str());
	return result;


}

int isHasEnter(char* str) {
	int j = 0;
	for (int i = 0;str[i]!='\0';i++) {
		if(str[i]=='\n')
			j++;
	}
	return j;
}

int getStrLen(char* str) {
	int i;
	for (i = 0;str[i] != '\0';i++) {
		
	}
	return i;
}