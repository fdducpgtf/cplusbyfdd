#include<iostream>
#include<string>
#include<fstream>
#include <iterator>
#include<list>

using namespace std;
//宽字符与窄字符的转换
wstring stringToWstring(const string&);
string wstringToString(const wstring&);
//
int isHasEnter(char*);
int getStrLen(char*);


//获取指定数的二进制字符串形式
extern void giveBinaryStringToStringFromInt(int, string&);

//自定义类：A
class A {
public:
	
	int getvalue();
	/*定义自定义类的流操作符（ << ）
	*/
	friend ostream &operator<<(ostream &output, A a) {
		output << a.getvalue();
		return output;
	
	}
#ifdef AOS

	//定义自定义类的指针流操作符（<<）
	friend ostream &operator<<(ostream &output, A *a) {
		output << a->getvalue();
		return output;

	}
#endif // AOS

	
private:
	int value = 22;
};


//******************************************程序***************************************
int coutFormatControlCaseMain() {


	

	//cout重定向到文件：输出到屏幕-->输出到文件
//#define ONE
#ifdef ONE
	if(1){
		
		//保存原输出流
		streambuf* old_cout_streambuf = cout.rdbuf();
		//建立文件输出流
		ofstream outfile("1.txt");
		//把文件输出流绑定到cout的输出流
		cout.rdbuf(outfile.rdbuf());
		//输出内容到cout，实则是输出到文件中
		cout << "这是cout重定向到文件测试！" << endl;
		//关闭文件
		outfile.close();
		//还原为默认的输出流
		cout.rdbuf(old_cout_streambuf); 

		
	}


#undef ONE
#endif // ONE


	//cin重定向到文件:从键盘输入-->从文件输入
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

	
	//从键盘输入，直接输出到文件
//#define	THREE
#ifdef THREE
	//事实已经证明：get()是否能够处理汉字与字母数字混排，取决于
	//setlocale的设置。当设置为"chs"时，它就能处理，否则不行。
	//本程序中没看见setlocale()语句，却能够处理中文字母等混排，
	//没搞懂为什么。留解！！！！！
	streambuf* old_cout_streambuf = cout.rdbuf();
	ofstream outputfile("1.txt");
	cout.rdbuf(outputfile.rdbuf());

	const char enter = '\n';
	char before;
	while (cin.good()) {
		before = cin.get();
		cout << before;
		if (before == enter) {//如果出现第一个换行
			
			char current = cin.get();//如果是第二个换行，就退出
			if (current != enter) {
				cout << current;  //否则显示    
			}
			else {
				break;//退出
			}
		}
		
	}

	outputfile.close();
	cout.rdbuf(old_cout_streambuf);

#undef THREE
#endif // THREE


	//从键盘获取指定类型的数据
//#define FOUR
#ifdef FOUR
	//获取整形数字
	if (0) {
		int input = 0;
		int sum = 0;
		while (cin >> input) {//会自动跳过空白字符（空格，换行，制表符等）
			sum += input;
		}//直到遇到不是指定类型的数据（这里是整数数字）非空白字符就会 退出
		cout << "最后一个输入的数字是：" << input << endl;//遇到非空白字符，返回0
		cout << "数字之和为：" << sum << endl;
		//遇到输入结束符（ctrl+z+endter)正常结束，input保留最后一个有效整数数字。

		

	}

	//获取float或double类型数字,过程与上述整数数字获取完全一致
	if (0) {
		double input = 0;
		double sum = 0;

		while (cin >> input) {
			sum += input;
		}
		cout << "最后一个double数字是：" << input << endl;
		cout << "数字之和为：" << sum << endl;

	}

	//获取字符型数据，如：char等
	//怎么处理宽字符和窄字符混排是关键。	
	if (0) {
		//注意两个方法：一是：setlocale()它从根本上决定是否能够区别宽字符窄字符
		//二是get()，它接受所有输入的字符，不跳过空白。这方便处理输入的某些特殊字符。
		string s = setlocale(LC_ALL, NULL);//保存区域设置
		setlocale(LC_ALL, "chs");//设置为简体中文区域
		const char enter = '\n';
		char before;
		while (cin.good()) {
			before = cin.get();//惊奇发现：get()可以处理汉字与字母数字混排的情况
			cout << before;
			if (before == enter) {//如果出现第一个换行

				char current = cin.get();//如果是第二个换行，就退出
				if (current != enter) {
					cout << current;  //否则显示    
				}
				else {
					break;//退出
				}
			}

		}
		//恢复区域设置，与前面设置要成对出现。
		setlocale(LC_ALL, s.c_str());

	}

	//检查I/O异常
	if (0) {
		int input = 0;
		int sum = 0;
		//设置引发异常的原因
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
				cout << "没有办法了，退出！" << endl;
				exit(1);
			}

		}
		
		cout << "请再输入数字：" << endl;
		cin >> input;
		sum += input;
	
		cout << "最后一个输入的数字是：" << input << endl;//遇到非空白字符，返回0
		cout << "数字之和为：" << sum << endl;
	}
	/*
		1、ios_base::iostate保存了I / O错误状态。I / O流都继承这一属性。
		2、错误状态有三种：eofbit, badbit, failbit(bitmask类型)。三种都正常，状态为
		goodbit。
		3、正常时，位值为：0，错误时为1。
		4、错误含义：eofbit：文件结尾；failbit：存取错误，如：存取非需要的类型数据。
		badbit：无法诊断的失败流。
		5、设置哪些错误状态引发错误：函数exceptions(iostate)可以使用。
			exceptions()不带参数时，返回错误掩码。然后可以对它操作识别错误状态。
			cin.rdstate()也可以返回流状态。二者有区别尚。
			前面exceptions()是设置可以抛出错误的类型，
			或者返回当前设置的哪些错误可以抛出。目的是捕捉错误。
			而后者是返回当前流的实际运行状态。目的是识别当前的错误类型 。

		6、设置引发错误的类型后，可以捕捉错误。在可能引发错误的代码块，使用
			try {}catch(){}捕捉错误。catch()里面要传入引用的错误变量。如上。错误
			发生时能捕捉，可以使程序不会出现莫名其妙的结果或返回值。
		7、设置错误状态值：设置的方法如下：
			clear(iostate)：先清除所有错误标志，然后设置iostate指定的错误标志。
			setstate(iostate)：只设置指定错误标志，不影响已设置的其它错误标志。
*/
	//测试流的状态
	if (0) {
		//可以抛出哪些错误的设置
	
		for (int bit = 0;bit<8 ;bit++) {

			cin.exceptions(std::_Iosb<char>::_Iostate(bit));
			int state = cin.exceptions();
			cout << hex <<showbase<< "[state]:" << state << endl<<endl;
			cout.unsetf(ios_base::hex);
			cout << noshowbase;
			if (state&ios_base::eofbit) {
				cout << "eofbit------>被设置了。" << endl;
			}
			else {
				cout << "eofbit------>没有被设置。" << endl;
			}
			if (state&ios_base::failbit) {
				cout << "failbit------>被设置了。" << endl;
			}
			else {
				cout << "failbit------>没有被设置。" << endl;
			}
			
			if (state&ios_base::badbit) {
				cout << "badbit------>被设置了。" << endl << endl;
			}
			else {
				cout << "badbit------>没有被设置。" << endl<<endl;
			}
			
		}



	}
	if (0) {
		//流状态的重新设置
		/*clear(iostate)：先清除所有错误标志，然后设置iostate指定的错误标志。
			setstate(iostate)：只设置指定错误标志，不影响已设置的其它错误标志。*/
	}
#undef FOUR
#endif // FOUR

//#define FIVE
#ifdef FIVE
//读取函数的学习
	//get(char&) get()。特点：读取所有字符。
	//不使用setlocale，就无法正确误解汉字等宽字符
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

	//cin>>流操作符：特点：跳过空白。
	if (0) {
		char c;
		while (cin >> c) {
			cout << c;//忽略空白符
			if (c == '`')//因此只有设置非空白的特殊字符作为退出标志
			{//没有设置退出字符，就用ctrl+z+enter退出。
				cout << endl;
				break;
			}
		}
	}
	 //用流操作符cin>>读取数值（读取输入的字符中任意数字）
	//与正常操作有别：正常读取出现错误即停止
	//（即遇到第一个不是数字的字符为止，空白符除外）
	if (0) {
		int val=-1;
		//0-9int值为：48-57 .
		while (1) {
			cin >> val;
			//如果出现读取错误，val值不用
			//并清除cin错误状态，读取非数字字符弃用，使cin可以
			//重新正常读取输入，遇到结束符，退出。
			cout << "state:"<<cin.rdstate() << endl;
			if (cin.rdstate()) {
				
				cin.clear();//清除错误状态
				while (1) {
					if (cin.peek() == -1)//如果处于输入结尾
							exit(1);//就退出
					//下面语句检查下一个字符，如果不是0-9的数字
					//就读到它并丢弃
					if ((cin.peek() < 48) || (cin.peek() > 57)) {
						
						cout << "lastint:"<<cin.get() << endl;
					}
						
					else
						break;//遇到下一个字符是数字就退出这个“读取弃用”循环
				}
			}
			else {
				cout << val << endl;//读取时没有错误就是想要的值
			}
		}
		

	}

	//get(char*,int,char) ,get(char*,int)
	//通过输入不同数量或不同字符（如分隔符，换行符，文件结尾符等）
	//了解cin.get(char*,int,char)的读取规则。
	if (0) {
		const int size = 7;
		char str[size];
		char demarcation = ' ';

		cin.get(str, size, demarcation);
		cout << "str:" << str << "--Len:" << getStrLen(str) << "--Enter:" << isHasEnter(str) << endl;
		cout << "state:" << cin.rdstate() << endl;
		cout << "下一个字符的int值是：" << cin.peek() << endl;

		cin.get(str, size, demarcation);
		cout << "str:" << str << "--Len:" << getStrLen(str) << "--Enter:" << isHasEnter(str) << endl;
		cout << "state:" << cin.rdstate() << endl;
		cout << "下一个字符的int值是：" << cin.peek() << endl;

		cin.get(str, size, demarcation);
		cout << "str:" << str << "--Len:" << getStrLen(str) << "--Enter:" << isHasEnter(str) << endl;
		cout << "state:" << cin.rdstate() << endl;
		cout << "下一个字符的int值是：" << cin.peek() << endl;

		//1.读取停止的原则是：第一，是不是指定的分隔符demarcation
			//或者是否为结尾符（EOF）（cin为ctrl+z)，是则该次读取即行停止；
			//但是：上述两种情况，此时流中下一个字符始终为“结尾符”，值为-1。
			//第二，是否达到最大字符（比指定的大小要少一个即满），是则该次读取即行停止；
			//第三，是否为结尾符（EOF）（cin为ctrl+z)，是则该次读取即行停止。
					//与第一条件同样优先。
					//特别注意：在缓冲区数据已经读完的前提下，前一个字符为enter之后的ctrl+z，
					//才被视为结尾
					//否则，ctrl+z会被当一个字符读入。
			//第四，换行符并不导致停止读取，除非加上换行符刚好读满才停止。
					//换行符是可以读进去的，不会忽略。
					//但它总是会忽略当前最后下一个换行符，并保持它在流中，
					//但下一次读取时它会被当作一个字符读取。
			//第五，缓冲区的刷新，并不一定是按下换行符（enter)之后才刷新，
					//当下一次读取的字符在当前的缓冲区完全能够读到（满足最大读取数时）
					//它会被自动刷新读取，甚至不止一次，只要缓冲区内的字符足够满足需要。
	}
	

	//用get()完成对输入内容根据换行符和分隔符来划分字符，更加方便。
	//get(char*,int,char)等太麻烦。
	if (0) {
		char demarcation = ' ';//分隔符。
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
	//除了末尾不自动加空字符以外，与get(char*,int)无异


	//ignore(int=1,int=EOF)读取并丢弃指定数量的字符或直到指定的字符为止
	//如：ignore(255,'\n')丢弃余下的255个字符或直到第一个换行符为止。
#undef FIVE
#endif // FIVE


			
			


			

	return 0;
}


inline int A::getvalue() {
	return A::value;
}




wstring stringToWstring(const string& s) {
	string currentLocale = setlocale(LC_ALL, NULL);//必须为NULL
	setlocale(LC_ALL, "chs");//简体中文地区


	//进行了上述设置才能进行下面的字符转换
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