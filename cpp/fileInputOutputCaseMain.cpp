#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<sstream>


using namespace std;

void check();

#define SEVEN



//705
int fileInputOutputCaseMain(int argc, char* argv[]) {

//命令行参数+-----------------------------------------------------------
#ifdef ONE

	if (argc == 1) {
		cout << "遗憾：只有一个参数：" << argv[0] << endl;
		exit(1);
	}
	
	string currentlocale = setlocale(LC_ALL, NULL);
	setlocale(LC_ALL,"chs");

	ifstream inputFStream;
	int total = 0;
	int anyone = 0;
	for (int file = 1;file < argc;file++) {
		inputFStream.open(argv[file]);
		if (!inputFStream.is_open())
			continue;
		char c;
		while (inputFStream.get(c)) {
			anyone++;
		}
		inputFStream.clear();
		inputFStream.close();
		cout << argv[file] << "文件里字符总数为：" << anyone << endl;
		total += anyone;
		anyone = 0;
		
	}

	cout << argc - 1 << "个文件字符总数为：" << total << endl;


	setlocale(LC_ALL,currentlocale.c_str());

#undef ONE
#endif // ONE

//二进制读写文件
#ifdef TWO
//二进制写入文件
	string outputfilename = "11";
	ofstream outfile(outputfilename, ios_base::out | ios_base::binary);
	if (!outfile.is_open()) {
		cout << "文件不能打开：" << outputfilename << endl;
		exit(1);
	}
	const char infor[] = "abcdefg\n中华人民共和国\n1234";
	outfile.write(infor, sizeof infor);
	outfile.close();
//二进制读取文件
	const streamsize size = sizeof infor;
	char getinfor[size];
	string inputfilename = outputfilename;
	ifstream infile(inputfilename, ios_base::in | ios_base::binary);
	if (infile.is_open()) {
		cout << "文件里面的内容有："<<endl;
		while (infile.read(getinfor, size)) {
			cout << getinfor;
		}
		cout << endl;
	}
	else {
		cout << "文件不能打开：" << inputfilename << endl;
	}
	infile.close();

	//测试一下用其它函数来读取二进制写入的文件
	infile.open(inputfilename, ios_base::in);
	//设置中文环境，使能处理汉字等宽字符
	string currentlocale = setlocale(LC_ALL, NULL);
	setlocale(LC_ALL, "chs");
	//读取文件
	char c;
	cout << "用一般的方式读取的文件内容如下：" << endl;
	while(infile.get(c)) {
		cout << c;
	}
	cout << endl;
	infile.close();
	//读取结束

	//恢复区域设置
	setlocale(LC_ALL, currentlocale.c_str());
	


#undef TWO
#endif // TWO


//固定数据结构与文件存储的关联，实现随机存储（随机读写）
#ifdef THREE

	//首先定义一个数据结构，存储固定信息
	const int sizeName = 255;
	const int sizeSex = 9;
	struct Person {
		char name[sizeName];
		int age;
		char sex[sizeSex];

	};
	Person person;
	//写入以Person为单位的信息给文件
	char inforPersonFile[] = "person.txt";
	//以读写、二进制模式创建文件
	//同时以覆盖原文件的形式打开
	fstream finout(inforPersonFile, ios_base::in | ios_base::out | ios_base::binary);
	if (!finout.is_open()) {
		cout << "文件创建失败：" << inforPersonFile << endl;
		exit(1);
	}


	/*
	//下面写入信息
	int i = 0;
	 int MaxRecords = 6;
	 cout << "请输入准备存储的记录的最大值：";
	 cin >> MaxRecords;

	while(cin.good()){
		if (i > MaxRecords-1)
			break;
		cout <<"第"<<++i<< "个人的信息：请输入Person的姓名：";
		cin>>person.name;
		check();
		cout << "第" << i << "个人的信息：请输入Person的年龄：";
		cin>>person.age ;
		check();
		cout << "第" << i << "个人的信息：请输入Person的性别：";
		cin>>person.sex;
		check();
		
		finout.write((char*)&person, sizeof person);

	}
	
	finout.clear();
	写入信息结束
	*/



	//显示已有信息（记录）
	cout << "下面是文件里面已有的记录信息：" << endl;
	cout <<left
		<<setw(12)<<"编号"
		<< setw(12) << "姓名" 
		<< setw(12) << "年龄" 
		<< setw(12) << "性别" 
		<< endl;
	finout.seekg(0);
	int recordnum = 0;
	while (finout.read((char*)&person, sizeof person)) {
		cout << left
			<<setw(12) << ++recordnum 
			<< setw(12)<<person.name 
			<<setw(12) << person.age 
			<<setw(12) << person.sex 
			<< endl;

	}
	cout << endl;
	finout.clear();
	int allRecords = recordnum;
	while (1) {
		//请求输入要改变的记录编号
		cout << "请输入你想改变的记录编号(起始编号为1）：";
		recordnum = 0;
		cin >> recordnum;
		if (recordnum > allRecords) {
			break;
		}
		
		cout << "你选择的编号是：" << recordnum << endl;

		//读取选择的信息
		finout.seekg((recordnum - 1)*(sizeof person));

		finout.read((char*)&person, sizeof person);
		cout << left
			<< setw(12) << "编号"
			<< setw(12) << "姓名"
			<< setw(12) << "年龄"
			<< setw(12) << "性别"
			<< endl;

		cout << left
			<< setw(12) << recordnum
			<< setw(12) << person.name
			<< setw(12) << person.age
			<< setw(12) << person.sex
			<< endl << endl;

		finout.clear();

		//请求输入改变信息
		cout << "请输入你想改变的信息：" << endl;
		cout << "请输入Person的姓名：";
		cin >> person.name;

		cout << "请输入Person的年龄：";
		cin >> person.age;

		cout << "请输入Person的性别：";
		cin >> person.sex;

		//写入改变信息
		finout.seekp((recordnum - 1)*(sizeof person));
		finout.write((char*)&person, sizeof person);
		finout.clear();

		//重新显示更新后的记录

		cout << "文件更新后的记录信息：" << endl;
		cout << left
			<< setw(12) << "编号"
			<< setw(12) << "姓名"
			<< setw(12) << "年龄"
			<< setw(12) << "性别"
			<< endl;
		finout.seekg(0);
		recordnum = 0;
		while (finout.read((char*)&person, sizeof person)) {


			cout << left << setw(12) << ++recordnum
				<< setw(12) << person.name
				<< setw(12) << person.age
				<< setw(12) << person.sex
				<< endl;
		}

	}
	finout.close();







#undef THREE
#endif // THREE

//内核格式化：sstream---ostringstream----istringstream
#ifdef FOUR
	//写入string
	ostringstream ostrStream;
	ostrStream <<123<<"123"<<"abcd 中华人 123 民共和国";
	string str = ostrStream.str();
	cout << str << endl;
	
	//读出内容到不同类型的变量
	//读取方式仍然与其它流一样，注意后面的读取只能在前面
	//读取剩下的缓冲内容来读取，最后一个什么也没读到。
	istringstream istrStream(str);
	int n;
	cout << "n:" << "-";
	while (istrStream >> n) {
		cout<< n << "-";
	}
	cout << endl;

	istrStream.clear();
	string s;
	cout << "s:" << "-";
	while (istrStream >> s) {
		cout << s<<"-";
	}
	cout << endl;

	istrStream.clear();
	char c;

	cout << "c:" << "-";
	while (istrStream >> c) {
		cout << c << "-";
	}
	cout << endl;

	
	//总结：可以拿来与string对象进行合作。
	//可以拿来进行字符串与数字之间的转换。


	


#undef FOUR
#endif // FOUR
//练习作业：拼接输出。724页，c++

#ifdef FIVE
	

	string infilea = "1.txt";//要读取的文件 ，必须已经存在
	string infileb = "2.txt";//要读取的文件 ，必须已经存在
	string outfile = "personsss.txt";//要输出的文件，不存在就新建文件。存在就覆盖原文件。
	//输出文件，默认打开模式是：ios_base::out|ios_base::trun

	//打开文件
	ifstream instream_a(infilea);
	ifstream instream_b(infileb);

	ofstream outstream(outfile);
	//如果以上有一个文件没有能打开，就跳到最后：关闭文件，退出程序。
	if (!(instream_a.is_open() && instream_b.is_open() && outstream.is_open()))
		goto LAST;//目的跳到最后，有机会关闭其中可能有成功打开的文件。
	
	char c;
	
	while (1) {//循环读取两个文件,while(1)恒为真，目的让两个文件互不干扰，都能全部输出所有内容。
		string stra, strb;//把两个储存字符的string放在这儿，目的是始终能让它们保持为空的状态。
	
		while (!instream_a.eof()) {//文件读完才退出
			c = instream_a.get();	//文件读完前，会出现EOF标志字符
			if(c!=EOF)//必须丢弃这个字符，否则，把它存储进string时会出现错误。
			stra.append(1, c);//始终存储所有字符（包括Enter)，除EOF外。
			if (c == '\n')
				break;

		}
		//以下与上完全相同的思路。
		while (!instream_b.eof()) {
			c = instream_b.get();
			if (c != EOF)
			strb.append(1, c);
			if (c == '\n')
				break;
		}
		//开始写进文件：第一个文件的内容
		if (stra.size()) {//有内容才写
			
			if (strb.size()) {//如果第二个文件有内容，
				stra.back()= ' ';//就需要替换掉第一个文件的内容的最后一个字符（始终为Enter），即替换掉Enter为空格，防止换行。
			}
			outstream << stra;//有内容就写进文件
		}
		//第二个文件的内容。
		if (strb.size()) {//有内容就写进文件
			outstream << strb;
		}
	
		//两个文件都读完，就退出主循环不再读取文件了。
		if (instream_a.eof() && instream_b.eof())
			break;
	 }
LAST:
	instream_a.close();
	instream_b.close();
	outstream.close();



#undef FIVE
#endif // FIVE

//练习作业：从两个朋友名单文件中找出朋友名单，并去掉重复的，写入文件中保存。
#ifdef SIX

	ifstream mdstream("md.txt");
	ifstream pdstream("pd.txt");
	ofstream mpdstream("mpd.txt");

	const char Enter = '\n';
	string names;//用于储存所有不重复的姓名
	string currentname;//当前从文件读取的某个姓名
	while (!mdstream.eof()) {
		//从文件 读取，用<<操作符读取。它会遇到空白符（包括空格换行等字符）就停止读取。
		mdstream >> currentname;
		if(mdstream.peek()!=Enter)//如果没有正常读到换行符，
			mdstream.ignore(255, '\n');//就丢弃剩下指定数量的字符或者到第一个换行符为止。
		
		if (names.find(currentname)==string::npos) {//如果当前读取的姓名与已有的姓名没有重复
			names.append(currentname);//就存储
			names.append(1, ',');
			mpdstream << currentname << endl;//就写进文件。
			
		}
	}
	//以下与上完全相同。读取的文件不同而已。
	while (!pdstream.eof()) {
		
		pdstream >> currentname;
		if (pdstream.peek() != Enter)
			pdstream.ignore(255, '\n');

		if (names.find(currentname) == string::npos) {
			names.append(currentname);
			names.append(1, ',');
			mpdstream << currentname << endl;
		}
	}
	cout << names << endl;//测试：把结果显示到屏幕
	mdstream.close();
	pdstream.close();
	mpdstream.clear();




#undef SIX
#endif // SIX

#ifdef SEVEN

	




#undef SEVEN
#endif // SEVEN

	return 0;
}


void check() {
	if (!cin.good()) {
		cin.clear();
		while (1) {
			char c;
			if (!cin.get(c))
				break;

		}

	}
}
