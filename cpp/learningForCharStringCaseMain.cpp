#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#define TRUE_OR_FALSE 0

//#define SIX_FUNCTIONS




int learningForCharStringCaseMain() {

	








#ifdef ONE
#undef ONE

	//字符变量声明及赋值
	char c;
	c = 'a';
	//c="abcd";这是错误的。因为它们类型不一样。
	//c属于char型；"abcd"是一个字符串。
	

#endif // ONE


#ifdef TWO
#undef TWO
	//字符数组与字符串是不同的概念。
	//字符数组每个成员是一个字符，结尾不需要以'\0'结束；
	//字符串一定是以'\0'为结束。
	
	char cStr[5] = { 'a','b','c','d','e' };
	cout << cStr << endl;//输出末尾有乱码，因为没有'\0'字符。而cout输出时是根据'\0'字符而停止的。
	char cStr2[5] = { 'a','b','c','d','\0' };
	cout << cStr2 << endl;//此次输出就正常了。
	
	//当字符数组的长度比字符串至少多一个时，字符串可以赋值给字符数组。否则不行，编译报错。
	//cStr = "1234";此表达式将报错。cStr一旦定义不可改变。
	char c_Str[5] = "1234";//char c_Str[5] = "12345";是不行的。
	cout << c_Str << endl;

	char cc_Str[7] = "1234";//字符数组比字符串长度不止大1，是可以赋值的。
	cout << cc_Str << endl;

	//还可以这样把字符串赋值给字符数组
	const char myStr[] = "Hello,Joe!";//由于是常量，数组变量前要加上const;
	//指针也要加const
	const char *pmyStr = "Hello,Joe!";
	//观察数组变量与指针变量所指的对象地址是否一致
	cout << "myStr所指地址是:" << &myStr << endl;
	cout << "pmyStr所指地址是:" << (void*)pmyStr << endl;
	cout << "Hello,Joe!的地址是：" << &"Hello,Joe!" << endl;
	//上述语句证明：数组所指字符串分配的地址 不同于 字符串"Hello,Joe!"分配的地址。
	//原因是：字符串常量分配于内存的”堆”上，而数组对应的字符串分配于“栈”上。



	



	
#endif


#ifdef THREE
#undef THREE
	//字符数组与字符指针
	char cstr[5] = { 'a','b','c','d','\0' };//字符数组
	cout<< cstr << endl;//cstr代表字符数组首地址，但cout输出却是整个字符数组所有字符。
	cout << &cstr << endl;//输出的是字符数组首地址。
	//可以用字符指针来检验
	char *pcstr;
	//pcstr = &cstr;这种赋值通不过；
	pcstr = cstr;//这个可以。pcstr就指向字符数组了。
	cout << pcstr << endl;
	//上面输出的不是指针的值（所指对象的地址），因为cout认为它是字符串，所以输出所指字符数组的整个字符串。
	cout << (void*)pcstr << "----" << &cstr << endl;
	//（void*)修饰指针就可以得到指针的值——所指对象的地址值。即字符数组的首地址。

	


#endif // THREE




#ifdef FOUR
#undef FOUR
	//字符指针数组与字符指针的指针
	//下面定义的是字符指针数组
	const char *pstr[] = { "abcde","12345","ab34" };//字符串常量赋值给指针时，都要加const关键字。
	//pstr代表字符指针数组首地址。
	const char **ppstr = pstr;//指向字符数组首地址的指针
	//(void *)ppstr代表指向的数组首地址
	cout << (void *)ppstr << "-------" << &pstr << endl;//指针指向的地址与字符指针数组的首地址相同
	//通过字符指针数组，输出所有字符串
	for (auto i : pstr) {
		cout << i << "\t";
	}
	cout << endl;
	//通过指向字符指针数组的指针输出所有字符串
	for (int i = 0;i < 3;i++) {
		cout << *(ppstr + i) << "\t";
	}
	cout << endl;





#endif // FOUR


#ifdef FIVE
#undef FIVE

//字符串的函数操作
	char str1[15] = "fddhello";
	char str2[] = "fdd";

	//字符串长度
	cout << strlen(str1) << "-----" << strlen(str2) << endl;//strlen()返回除结束符外的字符个数。
	//连接字符串
	strcat_s(str1, str2);//str1的长度要能够装得下str2,否则报错。
	cout <<str1 << endl;
	//一个字符串在另一个字符串中出现的位置
	cout << strstr(str1, str2) << endl;
	//指定字符在另一个字符串中出现的位置
	cout <<strchr(str1,'h')<< endl;
	//比较两个字符是否相同，相同返回0，前大后小，返回大于0，前小后大，返回大于0
	cout << strcmp(str1, str2) << endl;
	//复制字符串
	strcpy_s(str1, str2);
	cout << str1 << "---" << str2 << endl;
	cout << strcmp(str1, str2) << endl;
	cout << endl;



#endif // FIVE


#ifdef SIX_STRING
#undef SIX_STRING

	/*string类的学习
	string是表示字符串的字符串类
		string类的接口与常规容器的接口基本相同，在添加一些专门用来操作string的常规接口
		string类在底层实际上是basic_string模板类的别名。typedef basic_string<char, char_traits, allocator> string。
		string类不能操作多字节或者变长字符序列
		使用string类的时候，必须包含头文件string以及using namespace std。*/
		

	//构造函数
	string s;//1,空字符串

	//2,从单个char字符构造
	string strfromchar(1, 'a');
	string strfromnchar(8, 'a');
	cout << "strfromchar:"<<strfromchar<< endl;
	cout << "strfromnchar:" << strfromnchar << endl;

	//3,从C字符串（字符数组）或字符指针构造
	char chararray[] = "abcdefghijkmn";
	const char *pcharstr = "1234567890";
	string strfromchararray(chararray);
	cout << "strfromchararray:"<<strfromchararray<< endl;
	string strfromcharpointer(pcharstr);
	cout << "strfromcharpointer:"<<strfromcharpointer << endl;

	//4,从另一个string字符串构造新的字符串
	string strfromstr(strfromchararray);
	cout << "strfromstr:" << strfromstr << endl;


	//5，从c字符串中前n个字符构造字符串
	string strfromchararraylenfromhead(chararray, 2);
	cout << "strfromchararraylenfromhead:"<< strfromchararraylenfromhead << endl;

	//6，从string字符串中第n个字符开始的字符串构造新字符串（n从0开始的）
	string strfromstrfrombegintoend(strfromchararray, 2);
	cout << "strfromstrfrombegintoend:" << strfromstrfrombegintoend << endl;


	
	//7,从C字符串第n个字符开始，长度为m的字符串构造新字符串
	string strfromchararraylenfrombegin(chararray, 2, 5);
	cout<<"strfromchararraylenfrombegin:" << strfromchararraylenfrombegin << endl;

	//8,从string字符串第n个字符开始，长度为m的字符串构造新字符串
	string strfromstrlenfrombegin(strfromchararray, 2, 5);
	cout << "strfromstrlenfrombegin:" << strfromstrlenfrombegin << endl;

	//……还有其它没有搞懂的构造函数



#endif // SIX_STRING


#ifdef SIX_FUNCTIONS
#undef SIX_FUCTIONS

//1.自身信息
#ifdef SIX_FUNCTIONS_INFORMATION
#undef SIX_FUNCTIONS_INFORMATION

	//string::capacity();
	if (TRUE_OR_FALSE) {
		/*函数声明：
		size_t capacity() const;
		*/
	}
	//string::length();
	if (TRUE_OR_FALSE) {
		/*函数声明：
		size_t length() const;
		*/
	}
	//string::max_size();
	if (TRUE_OR_FALSE) {
		/*函数声明：
		size_t max_size() const;
		*/
	}
	//string::size();
	if (TRUE_OR_FALSE) {
		/*函数声明：
		size_t size() const;
		*/
	}
	
	

#endif // SIX_FUNCTIONS_INFORMATION


//2.定位
#ifdef SIX_FUNCTIONS_POSITION
#undef SIX_FUNCTIONS_POSITION


	//string::at()
	if (TRUE_OR_FALSE) {
		/*函数声明：
		char& at (size_t pos);
		const char& at (size_t pos) const;
		*/
	}
	//string::begin();
	if (TRUE_OR_FALSE) {
		/*函数声明：
		iterator begin();
		const_iterator begin() const;
		*/
	}
	//string::cbegin();
	if (TRUE_OR_FALSE) {
		/*函数声明：
		const_iterator cbegin() const noexcept;
		
		*/
	}
	//string::rbegin();
	if (TRUE_OR_FALSE) {
		/*函数声明：
		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;
		*/
	}
	//string::crbegin();
	if (TRUE_OR_FALSE) {
		/*函数声明：
		const_reverse_iterator crbegin() const noexcept;
		*/
	}
	//string::end();
	if (TRUE_OR_FALSE) {
		/*函数声明：
		iterator end();
		const_iterator end() const;
		*/
	}
	//string::cend();
	if (TRUE_OR_FALSE) {
		/*函数声明：
		const_iterator cend() const noexcept;
		*/
	}
	//string::rend();
	if (TRUE_OR_FALSE) {
		/*函数声明：
		reverse_iterator rend();
		const_reverse_iterator rend() const;
		*/
	}
	//string::crend();
	if (TRUE_OR_FALSE) {
		/*函数声明：
		const_reverse_iterator crend() const noexcept;
		*/
	}


	//string::front()
	if (TRUE_OR_FALSE) {
		/*函数声明：
		char& front();
		const char& front() const;
		*/
	}
	//string::back();
	if (TRUE_OR_FALSE) {
		/*函数声明：
		char& back();
		const char& back() const;
		*/
	}

	//string::find();
	if (TRUE_OR_FALSE) {
		/*函数声明：
		size_t find (const string& str, size_t pos = 0) const;
		size_t find (const char* s, size_t pos = 0) const;
		size_t find (const char* s, size_t pos, size_t n) const;
		size_t find (char c, size_t pos = 0) const;
		*/
	}
	//string::rfind();
	if (TRUE_OR_FALSE) {
		/*函数声明：
		size_t rfind (const string& str, size_t pos = npos) const;
		size_t rfind (const char* s, size_t pos = npos) const;
		size_t rfind (const char* s, size_t pos, size_t n) const;
		size_t rfind (char c, size_t pos = npos) const;
		*/
	}
	//string::find_first_of();
	if (TRUE_OR_FALSE) {
		/*函数声明：
		size_t find_first_of (const string& str, size_t pos = 0) const;
		size_t find_first_of (const char* s, size_t pos = 0) const;
		size_t find_first_of (const char* s, size_t pos, size_t n) const;
		size_t find_first_of (char c, size_t pos = 0) const;
		*/
	}
	//string::find_last_of();
	if (TRUE_OR_FALSE) {
		/*函数声明：
		size_t find_last_of (const string& str, size_t pos = npos) const;
		size_t find_last_of (const char* s, size_t pos = npos) const;
		size_t find_last_of (const char* s, size_t pos, size_t n) const;
		size_t find_last_of (char c, size_t pos = npos) const;
		*/
	}
	//string::find_first_not_of();
	if (TRUE_OR_FALSE) {
		/*函数声明：
		size_t find_first_not_of (const string& str, size_t pos = 0) const;
		size_t find_first_not_of (const char* s, size_t pos = 0) const;
		size_t find_first_not_of (const char* s, size_t pos, size_t n) const;
		size_t find_first_not_of (char c, size_t pos = 0) const;

		*/
	}
	//string::find_last_not_of();
	if (TRUE_OR_FALSE) {
		/*函数声明：
		size_t find_last_not_of (const string& str, size_t pos = npos) const;
		size_t find_last_not_of (const char* s, size_t pos = npos) const;
		size_t find_last_not_of (const char* s, size_t pos, size_t n) const;
		size_t find_last_not_of (char c, size_t pos = npos) const;

		*/
	}
	//string::operator[]
	if (TRUE_OR_FALSE) {
		/*函数声明：
		char& operator[] (size_t pos);
		const char& operator[] (size_t pos) const;
		*/
	}
	//
	



	
#endif // SIX_FUNCTIONS_POSITION

//3.修改
#ifdef SIX_FUNCTIONS_MODIFIERS
#undef	SIX_FUNCTIONS_MODIFIERS
	//
	//string::operator+=;
if (TRUE_OR_FALSE) {
	/*
	函数声明：
	string& operator+= (const string& str);
	string& operator+= (const char* s);
	string& operator+= (char c);
	*/
	cout << "string::operator+=()运行结果："<<endl;	
	string s = "abcd";
	char cs[] = "efgh";
	char c = 'i';
	string ss;
	ss+= s;
	ss += cs;
	ss += c;

	cout << ss << endl;

}

	//string::operator=;
if (TRUE_OR_FALSE) {
	/*
	函数声明：
	string& operator= (const string& str);
	string& operator= (const char* s);
	string& operator= (char c);
	*/
	cout << "string::operator=()运行结果：" << endl;
	string s = "fdd";
	char cs[] = "fqy";
	char c = '-';
	s = cs;
	cout << s << endl;
	s = c;
	cout << s << endl;


}
	//string::append();
if (TRUE_OR_FALSE) {
	/*函数声明：
string& append (const string& str);
string& append (const string& str, size_t subpos, size_t sublen);
string& append (const char* s);
string& append (const char* s, size_t n);
string& append (size_t n, char c);
template <class InputIterator>
   string& append (InputIterator first, InputIterator last);
string& append (initializer_list<char> il);
	*/
	string s = "abcdefg";
	string ss = "hijklmn1234";
	char cs[] = "opqrstuvwxyz";
	char c = '.';
	s.append(ss,0,7);
	s.append(cs);
	s.append(3, c);
	cout << "string:append()运行结果：" << endl;
	cout << s << endl;



}
	//string::assign();
if (TRUE_OR_FALSE) {
	/*
string& assign (const string& str);
string& assign (const string& str, size_t subpos, size_t sublen);
string& assign (const char* s);
string& assign (const char* s, size_t n);
string& assign (size_t n, char c);
template <class InputIterator>
   string& assign (InputIterator first, InputIterator last);
string& assign (initializer_list<char> il);
string& assign (string&& str) noexcept;
	*/
	string all;
	string s = "abcdefg";
	string ss = "hijklmn1234";
	char cs[] = "opqrstuvwxyz";
	char c = '.';
	s.assign(ss, 0, 7);
	all += s;
	s.assign(cs);
	all += s;
	s.assign(3, c);
	all += s;
	cout << "string:assign()运行结果：" << endl;
	cout << all << endl;

}
	//string::clear();
if (TRUE_OR_FALSE) {
	/*函数声明：
	void clear() noexcept;
	*/
}
	//string::push_back();
	//string::pop_back();
if (TRUE_OR_FALSE) {
	/*函数声明：
	void push_back (char c);
	void pop_back();
	*/
	cout << "string::push_back()和string::pop_back()运行结果：" << endl;
	string s = "12345";
	cout << s << endl;
	s.push_back('6');
	cout << s << endl;
	s.pop_back();
	cout << s << endl;


}
	
	//string::erase();
if (TRUE_OR_FALSE) {
	/*函数声明：
 string& erase (size_t pos = 0, size_t len = npos);
iterator erase (const_iterator p);
iterator erase (const_iterator first, const_iterator last);
	*/
	cout << "string::erase()运行结果：" << endl;
	string s = "abcd1234efg56hijkmnopqrstuvwxyz";
	s.erase(4, 4);
	s.erase(7, 2);
	cout << s << endl;
	s.erase(s.end() - 5);
	cout << s << endl;
	s.erase(s.begin() + 4, s.begin() + 8);
	cout << s << endl;
}
	//string::insert();
if (TRUE_OR_FALSE) {
	/*函数声明：
 string& insert (size_t pos, const string& str);
 string& insert (size_t pos, const string& str, size_t subpos, size_t sublen);
 string& insert (size_t pos, const char* s);
 string& insert (size_t pos, const char* s, size_t n);
 string& insert (size_t pos,   size_t n, char c);
iterator insert (const_iterator p, size_t n, char c);
iterator insert (const_iterator p, char c);
template <class InputIterator>
iterator insert (iterator p, InputIterator first, InputIterator last);
 string& insert (const_iterator p, initializer_list<char> il);
	*/
	cout << "string::insert()运行结果为：" << endl;
	string s = "13389642690";
	string ss = "-";
	s.insert(3, ss);
	s.insert(8, ss);
	
	s.insert(0, "My telephone");
	s.insert(12, " number is 123.", 7);
	ss = "This is a book.";
	s.insert(19, ss, 4, 4);
	s.insert(s.size(), 1, '.');
	cout << s << endl;
	s.pop_back();
	ss = ",ok?";
	s.insert(s.end(), ss.begin(), ss.end());
	cout << s << endl;
	

}
	//string::resize();
if (TRUE_OR_FALSE) {
	/*函数声明：
	void resize (size_t n);
	void resize (size_t n, char c);
	*/
	cout << "string::resize()运行结果：" << endl;
	string s = "0123456789101112131415";
	s.resize(10);
	cout << s << endl;
	s.resize(13, '.');
	cout << s << endl;


}

	//string::reserve();
if (TRUE_OR_FALSE) {
	/*函数声明：
	void reserve (size_t n = 0);
	*/
	string s;
	//需提前建立一个test.txt文件（已有）。
	ifstream file("test.txt", ios::in | ios::ate);
	if (file) {
		ifstream::streampos filesize = file.tellg();
		s.reserve(filesize);

		file.seekg(0);
		while (!file.eof())
		{
			s += file.get();
		}
		cout << s;
	}
}
	//string::replace();
if (TRUE_OR_FALSE) {
	/*函数声明：
	string& replace (size_t pos,  size_t len,  const string& str);
	string& replace (iterator i1, iterator i2, const string& str);
	string& replace (size_t pos,  size_t len,  const string& str,
                 size_t subpos, size_t sublen);
	string& replace (size_t pos,  size_t len,  const char* s);
	string& replace (iterator i1, iterator i2, const char* s);
	string& replace (size_t pos,  size_t len,  const char* s, size_t n);
	string& replace (iterator i1, iterator i2, const char* s, size_t n);
	string& replace (size_t pos,  size_t len,  size_t n, char c);
	string& replace (iterator i1, iterator i2, size_t n, char c);
	template <class InputIterator>
	string& replace (iterator i1, iterator i2,
                   InputIterator first, InputIterator last);
	*/
	cout << "string::replace()运行结果：" << endl;
	string s = "my name is fdd.her name is dcw.";
	string ss = "My daughter is fqy.";
	s.replace(0, 1, 1,'M');
	s.replace(s.begin()+s.find("her"), s.begin() + s.find("her")+1, 1, 'H');//指定位置之间：[……)(数学表示法）。
	s.replace(s.find("dcw"), 3, ss, ss.find("fqy"), 3);
	s.replace(s.size() - 1, 1, ",do you know????", 13);
	cout << s << endl;
	



	

	
}
	//string::shrink_to_fit();
if (TRUE_OR_FALSE) {
	/*函数声明：
	void shrink_to_fit();
	*/
	string s(100, 'x');
	cout << "1. capacity of s: " << s.capacity() << '\n';

	s.resize(10);
	cout << "2. capacity of s: " << s.capacity() << '\n';

	s.shrink_to_fit();
	cout << "3. capacity of s: " << s.capacity() << '\n';

}
	//string::swap();
if (TRUE_OR_FALSE) {
	/*函数声明：
	void swap (string& str);
	*/
	string buyer("money");
	string seller("goods");

	cout << "Before the swap, buyer has " << buyer;
	cout << " and seller has " << seller << endl;

	seller.swap(buyer);

	cout << " After the swap, buyer has " << buyer;
	cout << " and seller has " << seller << endl;
}
	//string::_Replace_range();
	//string::_Swap_all();
	//string::_Swap_bx_large_with_small();
	//string::_Swap_data();
	


#endif // SIX_FUNCTIONS_MODIFIERS



#ifdef SIX_FUNCTIONS_GETSTRING
#undef SIX_FUNCTIONS_GETSTRING
	//
	//string::data();
if(TRUE_OR_FALSE) {
		//函数声明：const char* data() const;
		string s = "hello";
		const char *pcs=s.data();
		cout << "string::data()运行结果："<<endl;
		cout << pcs << endl;
		
		
}
	//string::c_str();
if (TRUE_OR_FALSE) {
	//函数声明：const char* c_str() const;
	string s = "hello";
	const char *pcs = s.c_str();
	cout << "string::c_str()运行结果：" << endl;
	cout << pcs << endl;

}
	//string::at();
if (TRUE_OR_FALSE) {
	/*
	函数声明： char& at (size_t pos);
	const char& at(size_t pos) const;
	*/
	string s = "string::at()";
	const string const_s = "const string:at()";
	char& cs = s.at(0);
	const char& ccs = const_s.at(0);
	cout << "string::at()运行结果：" << endl;
	cout << cs << endl;
	cout << ccs << endl;
	cs = '*';//返回值为引用，可以修改值，即原字符串被修改。
	//ccs='*';不能修改const变量。
	cout << s << endl;
	

}
	//string:front();
if (TRUE_OR_FALSE) {
	/*
	函数声明：  
	char& front();
	const char& front() const;
	*/
	string s = "do";
	char& cs = s.front();
	cs = 'h';//返回为引用，可以修改值。原字符串被修改。
	cout << "string::front()运行结果：" << endl;
	cout << s << endl;



}
	//string::back();
if (TRUE_OR_FALSE) {


	/*
	函数声明：     
	char& back();
	const char& back() const;
	*/
}
	//string::operator[];
if (TRUE_OR_FALSE) {
	/*
	函数声明：
	char& operator[] (size_t pos);
	const char& operator[] (size_t pos) const;
	*/
	string s = "abcdefg";
	auto pos = s.find('d');
	s[pos] = '*';
	cout << "string::operator[]运行结果：" << endl;
	cout << s << endl;
	
}
	//string::substr();
if(TRUE_OR_FALSE){
	//函数声明：string substr (size_t pos = 0, size_t len = npos) const;
	string s = "Copies a substring of the current value of the string object into the array pointed by s.";
	s = s.substr(9, 9);
	cout << "string::substr()运行结果："<<endl;
	cout << s << endl;//output:substr
	s += " function.";
	s = s.substr();//默认pos=0,len=string::npos。C++11里面规定string一定是以'\0'结尾。
	cout << s << endl;//output:substr function.



	
}

	//string::_Get_data();
	//string::_Getal();
	//string::_Getpfirst();
	

	

#endif // SIX_FUNCTIONS_GETSTRING

#ifdef SIX_FUNCTIONS_COPYSTRING
#undef SIX_FUNCTIONS_COPYSTRING
	//
	//string::copy();
//size_t copy (char* s, size_t len, size_t pos = 0) const;
for (;;) {
	string s = "My name is dcw.";
	char cs[20]="My name is fdd.";
	auto len = s.copy(cs, s.size(),0);
	cs[len] = '\0';//不设此符输出字符串时会出现乱码。
	cout << cs<< endl;
	break;//保证只运行一次。
	//把代码放进循环体，因为出了循环体变量即失效。
}


	//string::_Copy_s();
	//string::_Copy_alloc();
	//





	



#endif // SIX_FUNCTIONS_COPYSTRING

#ifdef SIX_FUNCTIONS_COMPARE
#undef SIX_FUNCTIONS_COMPARE
	//
	//string::compare();
if (TRUE_OR_FALSE) {
	/*函数声明：
	int compare (const string& str) const;
	int compare (size_t pos, size_t len, const string& str) const;
	int compare (size_t pos, size_t len, const string& str,
				 size_t subpos, size_t sublen) const;
	int compare (const char* s) const;
	int compare (size_t pos, size_t len, const char* s) const;
	int compare (size_t pos, size_t len, const char* s, size_t n) const;
	*/
}
	



#endif // SIX_FUNCTIONS_COMPARE

#ifdef SIX_FUNCTIONS_NONMEMBER
#undef SIX_FUNCTIONS_NONMEMBER
	//getline();
if (TRUE_OR_FALSE) {
	/*函数声明：
	istream& getline (istream&  is, string& str, char delim);
	istream& getline (istream&& is, string& str, char delim);
	istream& getline (istream&  is, string& str);
	istream& getline (istream&& is, string& str);	*/


	std::string name;

	cout << "Please, enter your full name: ";
	getline(cin, name);
	cout << "Hello, " << name << "!\n";
}
	//<<
if (TRUE_OR_FALSE) {
	/*函数声明：
	ostream& operator<< (ostream& os, const string& str);
	*/
}
	//>>
if (TRUE_OR_FALSE) {
	/*函数声明：
	istream& operator>> (istream& is, string& str);
	*/
}
	//+
if (TRUE_OR_FALSE) {
	/*函数声明：
	string operator+ (const string& lhs, const string& rhs);
	string operator+ (string&&      lhs, string&&      rhs);
	string operator+ (string&&      lhs, const string& rhs);
	string operator+ (const string& lhs, string&&      rhs);
	string operator+ (const string& lhs, const char*   rhs);
	string operator+ (string&&      lhs, const char*   rhs);
	string operator+ (const char*   lhs, const string& rhs);
	string operator+ (const char*   lhs, string&&      rhs);
	string operator+ (const string& lhs, char          rhs);
	string operator+ (string&&      lhs, char          rhs);
	string operator+ (char          lhs, const string& rhs);
	string operator+ (char          lhs, string&&      rhs);
	*/
}
	//swap
if (TRUE_OR_FALSE) {
	/*函数声明：
	std::swap (string) void swap (string& x, string& y);
	*/
}
	//




#endif // SIX_FUNCTIONS_NONMEMBER












#endif // SIX_FUCTIONS









	return 0;
}