#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#define TRUE_OR_FALSE 0

//#define SIX_FUNCTIONS




int learningForCharStringCaseMain() {

	








#ifdef ONE
#undef ONE

	//�ַ�������������ֵ
	char c;
	c = 'a';
	//c="abcd";���Ǵ���ġ���Ϊ�������Ͳ�һ����
	//c����char�ͣ�"abcd"��һ���ַ�����
	

#endif // ONE


#ifdef TWO
#undef TWO
	//�ַ��������ַ����ǲ�ͬ�ĸ��
	//�ַ�����ÿ����Ա��һ���ַ�����β����Ҫ��'\0'������
	//�ַ���һ������'\0'Ϊ������
	
	char cStr[5] = { 'a','b','c','d','e' };
	cout << cStr << endl;//���ĩβ�����룬��Ϊû��'\0'�ַ�����cout���ʱ�Ǹ���'\0'�ַ���ֹͣ�ġ�
	char cStr2[5] = { 'a','b','c','d','\0' };
	cout << cStr2 << endl;//�˴�����������ˡ�
	
	//���ַ�����ĳ��ȱ��ַ������ٶ�һ��ʱ���ַ������Ը�ֵ���ַ����顣�����У����뱨��
	//cStr = "1234";�˱��ʽ������cStrһ�����岻�ɸı䡣
	char c_Str[5] = "1234";//char c_Str[5] = "12345";�ǲ��еġ�
	cout << c_Str << endl;

	char cc_Str[7] = "1234";//�ַ�������ַ������Ȳ�ֹ��1���ǿ��Ը�ֵ�ġ�
	cout << cc_Str << endl;

	//�������������ַ�����ֵ���ַ�����
	const char myStr[] = "Hello,Joe!";//�����ǳ������������ǰҪ����const;
	//ָ��ҲҪ��const
	const char *pmyStr = "Hello,Joe!";
	//�۲����������ָ�������ָ�Ķ����ַ�Ƿ�һ��
	cout << "myStr��ָ��ַ��:" << &myStr << endl;
	cout << "pmyStr��ָ��ַ��:" << (void*)pmyStr << endl;
	cout << "Hello,Joe!�ĵ�ַ�ǣ�" << &"Hello,Joe!" << endl;
	//�������֤����������ָ�ַ�������ĵ�ַ ��ͬ�� �ַ���"Hello,Joe!"����ĵ�ַ��
	//ԭ���ǣ��ַ��������������ڴ�ġ��ѡ��ϣ��������Ӧ���ַ��������ڡ�ջ���ϡ�



	



	
#endif


#ifdef THREE
#undef THREE
	//�ַ��������ַ�ָ��
	char cstr[5] = { 'a','b','c','d','\0' };//�ַ�����
	cout<< cstr << endl;//cstr�����ַ������׵�ַ����cout���ȴ�������ַ����������ַ���
	cout << &cstr << endl;//��������ַ������׵�ַ��
	//�������ַ�ָ��������
	char *pcstr;
	//pcstr = &cstr;���ָ�ֵͨ������
	pcstr = cstr;//������ԡ�pcstr��ָ���ַ������ˡ�
	cout << pcstr << endl;
	//��������Ĳ���ָ���ֵ����ָ����ĵ�ַ������Ϊcout��Ϊ�����ַ��������������ָ�ַ�����������ַ�����
	cout << (void*)pcstr << "----" << &cstr << endl;
	//��void*)����ָ��Ϳ��Եõ�ָ���ֵ������ָ����ĵ�ֵַ�����ַ�������׵�ַ��

	


#endif // THREE




#ifdef FOUR
#undef FOUR
	//�ַ�ָ���������ַ�ָ���ָ��
	//���涨������ַ�ָ������
	const char *pstr[] = { "abcde","12345","ab34" };//�ַ���������ֵ��ָ��ʱ����Ҫ��const�ؼ��֡�
	//pstr�����ַ�ָ�������׵�ַ��
	const char **ppstr = pstr;//ָ���ַ������׵�ַ��ָ��
	//(void *)ppstr����ָ��������׵�ַ
	cout << (void *)ppstr << "-------" << &pstr << endl;//ָ��ָ��ĵ�ַ���ַ�ָ��������׵�ַ��ͬ
	//ͨ���ַ�ָ�����飬��������ַ���
	for (auto i : pstr) {
		cout << i << "\t";
	}
	cout << endl;
	//ͨ��ָ���ַ�ָ�������ָ����������ַ���
	for (int i = 0;i < 3;i++) {
		cout << *(ppstr + i) << "\t";
	}
	cout << endl;





#endif // FOUR


#ifdef FIVE
#undef FIVE

//�ַ����ĺ�������
	char str1[15] = "fddhello";
	char str2[] = "fdd";

	//�ַ�������
	cout << strlen(str1) << "-----" << strlen(str2) << endl;//strlen()���س�����������ַ�������
	//�����ַ���
	strcat_s(str1, str2);//str1�ĳ���Ҫ�ܹ�װ����str2,���򱨴�
	cout <<str1 << endl;
	//һ���ַ�������һ���ַ����г��ֵ�λ��
	cout << strstr(str1, str2) << endl;
	//ָ���ַ�����һ���ַ����г��ֵ�λ��
	cout <<strchr(str1,'h')<< endl;
	//�Ƚ������ַ��Ƿ���ͬ����ͬ����0��ǰ���С�����ش���0��ǰС��󣬷��ش���0
	cout << strcmp(str1, str2) << endl;
	//�����ַ���
	strcpy_s(str1, str2);
	cout << str1 << "---" << str2 << endl;
	cout << strcmp(str1, str2) << endl;
	cout << endl;



#endif // FIVE


#ifdef SIX_STRING
#undef SIX_STRING

	/*string���ѧϰ
	string�Ǳ�ʾ�ַ������ַ�����
		string��Ľӿ��볣�������Ľӿڻ�����ͬ�������һЩר����������string�ĳ���ӿ�
		string���ڵײ�ʵ������basic_stringģ����ı�����typedef basic_string<char, char_traits, allocator> string��
		string�಻�ܲ������ֽڻ��߱䳤�ַ�����
		ʹ��string���ʱ�򣬱������ͷ�ļ�string�Լ�using namespace std��*/
		

	//���캯��
	string s;//1,���ַ���

	//2,�ӵ���char�ַ�����
	string strfromchar(1, 'a');
	string strfromnchar(8, 'a');
	cout << "strfromchar:"<<strfromchar<< endl;
	cout << "strfromnchar:" << strfromnchar << endl;

	//3,��C�ַ������ַ����飩���ַ�ָ�빹��
	char chararray[] = "abcdefghijkmn";
	const char *pcharstr = "1234567890";
	string strfromchararray(chararray);
	cout << "strfromchararray:"<<strfromchararray<< endl;
	string strfromcharpointer(pcharstr);
	cout << "strfromcharpointer:"<<strfromcharpointer << endl;

	//4,����һ��string�ַ��������µ��ַ���
	string strfromstr(strfromchararray);
	cout << "strfromstr:" << strfromstr << endl;


	//5����c�ַ�����ǰn���ַ������ַ���
	string strfromchararraylenfromhead(chararray, 2);
	cout << "strfromchararraylenfromhead:"<< strfromchararraylenfromhead << endl;

	//6����string�ַ����е�n���ַ���ʼ���ַ����������ַ�����n��0��ʼ�ģ�
	string strfromstrfrombegintoend(strfromchararray, 2);
	cout << "strfromstrfrombegintoend:" << strfromstrfrombegintoend << endl;


	
	//7,��C�ַ�����n���ַ���ʼ������Ϊm���ַ����������ַ���
	string strfromchararraylenfrombegin(chararray, 2, 5);
	cout<<"strfromchararraylenfrombegin:" << strfromchararraylenfrombegin << endl;

	//8,��string�ַ�����n���ַ���ʼ������Ϊm���ַ����������ַ���
	string strfromstrlenfrombegin(strfromchararray, 2, 5);
	cout << "strfromstrlenfrombegin:" << strfromstrlenfrombegin << endl;

	//������������û�и㶮�Ĺ��캯��



#endif // SIX_STRING


#ifdef SIX_FUNCTIONS
#undef SIX_FUCTIONS

//1.������Ϣ
#ifdef SIX_FUNCTIONS_INFORMATION
#undef SIX_FUNCTIONS_INFORMATION

	//string::capacity();
	if (TRUE_OR_FALSE) {
		/*����������
		size_t capacity() const;
		*/
	}
	//string::length();
	if (TRUE_OR_FALSE) {
		/*����������
		size_t length() const;
		*/
	}
	//string::max_size();
	if (TRUE_OR_FALSE) {
		/*����������
		size_t max_size() const;
		*/
	}
	//string::size();
	if (TRUE_OR_FALSE) {
		/*����������
		size_t size() const;
		*/
	}
	
	

#endif // SIX_FUNCTIONS_INFORMATION


//2.��λ
#ifdef SIX_FUNCTIONS_POSITION
#undef SIX_FUNCTIONS_POSITION


	//string::at()
	if (TRUE_OR_FALSE) {
		/*����������
		char& at (size_t pos);
		const char& at (size_t pos) const;
		*/
	}
	//string::begin();
	if (TRUE_OR_FALSE) {
		/*����������
		iterator begin();
		const_iterator begin() const;
		*/
	}
	//string::cbegin();
	if (TRUE_OR_FALSE) {
		/*����������
		const_iterator cbegin() const noexcept;
		
		*/
	}
	//string::rbegin();
	if (TRUE_OR_FALSE) {
		/*����������
		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;
		*/
	}
	//string::crbegin();
	if (TRUE_OR_FALSE) {
		/*����������
		const_reverse_iterator crbegin() const noexcept;
		*/
	}
	//string::end();
	if (TRUE_OR_FALSE) {
		/*����������
		iterator end();
		const_iterator end() const;
		*/
	}
	//string::cend();
	if (TRUE_OR_FALSE) {
		/*����������
		const_iterator cend() const noexcept;
		*/
	}
	//string::rend();
	if (TRUE_OR_FALSE) {
		/*����������
		reverse_iterator rend();
		const_reverse_iterator rend() const;
		*/
	}
	//string::crend();
	if (TRUE_OR_FALSE) {
		/*����������
		const_reverse_iterator crend() const noexcept;
		*/
	}


	//string::front()
	if (TRUE_OR_FALSE) {
		/*����������
		char& front();
		const char& front() const;
		*/
	}
	//string::back();
	if (TRUE_OR_FALSE) {
		/*����������
		char& back();
		const char& back() const;
		*/
	}

	//string::find();
	if (TRUE_OR_FALSE) {
		/*����������
		size_t find (const string& str, size_t pos = 0) const;
		size_t find (const char* s, size_t pos = 0) const;
		size_t find (const char* s, size_t pos, size_t n) const;
		size_t find (char c, size_t pos = 0) const;
		*/
	}
	//string::rfind();
	if (TRUE_OR_FALSE) {
		/*����������
		size_t rfind (const string& str, size_t pos = npos) const;
		size_t rfind (const char* s, size_t pos = npos) const;
		size_t rfind (const char* s, size_t pos, size_t n) const;
		size_t rfind (char c, size_t pos = npos) const;
		*/
	}
	//string::find_first_of();
	if (TRUE_OR_FALSE) {
		/*����������
		size_t find_first_of (const string& str, size_t pos = 0) const;
		size_t find_first_of (const char* s, size_t pos = 0) const;
		size_t find_first_of (const char* s, size_t pos, size_t n) const;
		size_t find_first_of (char c, size_t pos = 0) const;
		*/
	}
	//string::find_last_of();
	if (TRUE_OR_FALSE) {
		/*����������
		size_t find_last_of (const string& str, size_t pos = npos) const;
		size_t find_last_of (const char* s, size_t pos = npos) const;
		size_t find_last_of (const char* s, size_t pos, size_t n) const;
		size_t find_last_of (char c, size_t pos = npos) const;
		*/
	}
	//string::find_first_not_of();
	if (TRUE_OR_FALSE) {
		/*����������
		size_t find_first_not_of (const string& str, size_t pos = 0) const;
		size_t find_first_not_of (const char* s, size_t pos = 0) const;
		size_t find_first_not_of (const char* s, size_t pos, size_t n) const;
		size_t find_first_not_of (char c, size_t pos = 0) const;

		*/
	}
	//string::find_last_not_of();
	if (TRUE_OR_FALSE) {
		/*����������
		size_t find_last_not_of (const string& str, size_t pos = npos) const;
		size_t find_last_not_of (const char* s, size_t pos = npos) const;
		size_t find_last_not_of (const char* s, size_t pos, size_t n) const;
		size_t find_last_not_of (char c, size_t pos = npos) const;

		*/
	}
	//string::operator[]
	if (TRUE_OR_FALSE) {
		/*����������
		char& operator[] (size_t pos);
		const char& operator[] (size_t pos) const;
		*/
	}
	//
	



	
#endif // SIX_FUNCTIONS_POSITION

//3.�޸�
#ifdef SIX_FUNCTIONS_MODIFIERS
#undef	SIX_FUNCTIONS_MODIFIERS
	//
	//string::operator+=;
if (TRUE_OR_FALSE) {
	/*
	����������
	string& operator+= (const string& str);
	string& operator+= (const char* s);
	string& operator+= (char c);
	*/
	cout << "string::operator+=()���н����"<<endl;	
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
	����������
	string& operator= (const string& str);
	string& operator= (const char* s);
	string& operator= (char c);
	*/
	cout << "string::operator=()���н����" << endl;
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
	/*����������
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
	cout << "string:append()���н����" << endl;
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
	cout << "string:assign()���н����" << endl;
	cout << all << endl;

}
	//string::clear();
if (TRUE_OR_FALSE) {
	/*����������
	void clear() noexcept;
	*/
}
	//string::push_back();
	//string::pop_back();
if (TRUE_OR_FALSE) {
	/*����������
	void push_back (char c);
	void pop_back();
	*/
	cout << "string::push_back()��string::pop_back()���н����" << endl;
	string s = "12345";
	cout << s << endl;
	s.push_back('6');
	cout << s << endl;
	s.pop_back();
	cout << s << endl;


}
	
	//string::erase();
if (TRUE_OR_FALSE) {
	/*����������
 string& erase (size_t pos = 0, size_t len = npos);
iterator erase (const_iterator p);
iterator erase (const_iterator first, const_iterator last);
	*/
	cout << "string::erase()���н����" << endl;
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
	/*����������
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
	cout << "string::insert()���н��Ϊ��" << endl;
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
	/*����������
	void resize (size_t n);
	void resize (size_t n, char c);
	*/
	cout << "string::resize()���н����" << endl;
	string s = "0123456789101112131415";
	s.resize(10);
	cout << s << endl;
	s.resize(13, '.');
	cout << s << endl;


}

	//string::reserve();
if (TRUE_OR_FALSE) {
	/*����������
	void reserve (size_t n = 0);
	*/
	string s;
	//����ǰ����һ��test.txt�ļ������У���
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
	/*����������
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
	cout << "string::replace()���н����" << endl;
	string s = "my name is fdd.her name is dcw.";
	string ss = "My daughter is fqy.";
	s.replace(0, 1, 1,'M');
	s.replace(s.begin()+s.find("her"), s.begin() + s.find("her")+1, 1, 'H');//ָ��λ��֮�䣺[����)(��ѧ��ʾ������
	s.replace(s.find("dcw"), 3, ss, ss.find("fqy"), 3);
	s.replace(s.size() - 1, 1, ",do you know????", 13);
	cout << s << endl;
	



	

	
}
	//string::shrink_to_fit();
if (TRUE_OR_FALSE) {
	/*����������
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
	/*����������
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
		//����������const char* data() const;
		string s = "hello";
		const char *pcs=s.data();
		cout << "string::data()���н����"<<endl;
		cout << pcs << endl;
		
		
}
	//string::c_str();
if (TRUE_OR_FALSE) {
	//����������const char* c_str() const;
	string s = "hello";
	const char *pcs = s.c_str();
	cout << "string::c_str()���н����" << endl;
	cout << pcs << endl;

}
	//string::at();
if (TRUE_OR_FALSE) {
	/*
	���������� char& at (size_t pos);
	const char& at(size_t pos) const;
	*/
	string s = "string::at()";
	const string const_s = "const string:at()";
	char& cs = s.at(0);
	const char& ccs = const_s.at(0);
	cout << "string::at()���н����" << endl;
	cout << cs << endl;
	cout << ccs << endl;
	cs = '*';//����ֵΪ���ã������޸�ֵ����ԭ�ַ������޸ġ�
	//ccs='*';�����޸�const������
	cout << s << endl;
	

}
	//string:front();
if (TRUE_OR_FALSE) {
	/*
	����������  
	char& front();
	const char& front() const;
	*/
	string s = "do";
	char& cs = s.front();
	cs = 'h';//����Ϊ���ã������޸�ֵ��ԭ�ַ������޸ġ�
	cout << "string::front()���н����" << endl;
	cout << s << endl;



}
	//string::back();
if (TRUE_OR_FALSE) {


	/*
	����������     
	char& back();
	const char& back() const;
	*/
}
	//string::operator[];
if (TRUE_OR_FALSE) {
	/*
	����������
	char& operator[] (size_t pos);
	const char& operator[] (size_t pos) const;
	*/
	string s = "abcdefg";
	auto pos = s.find('d');
	s[pos] = '*';
	cout << "string::operator[]���н����" << endl;
	cout << s << endl;
	
}
	//string::substr();
if(TRUE_OR_FALSE){
	//����������string substr (size_t pos = 0, size_t len = npos) const;
	string s = "Copies a substring of the current value of the string object into the array pointed by s.";
	s = s.substr(9, 9);
	cout << "string::substr()���н����"<<endl;
	cout << s << endl;//output:substr
	s += " function.";
	s = s.substr();//Ĭ��pos=0,len=string::npos��C++11����涨stringһ������'\0'��β��
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
	cs[len] = '\0';//����˷�����ַ���ʱ��������롣
	cout << cs<< endl;
	break;//��ֻ֤����һ�Ρ�
	//�Ѵ���Ž�ѭ���壬��Ϊ����ѭ���������ʧЧ��
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
	/*����������
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
	/*����������
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
	/*����������
	ostream& operator<< (ostream& os, const string& str);
	*/
}
	//>>
if (TRUE_OR_FALSE) {
	/*����������
	istream& operator>> (istream& is, string& str);
	*/
}
	//+
if (TRUE_OR_FALSE) {
	/*����������
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
	/*����������
	std::swap (string) void swap (string& x, string& y);
	*/
}
	//




#endif // SIX_FUNCTIONS_NONMEMBER












#endif // SIX_FUCTIONS









	return 0;
}