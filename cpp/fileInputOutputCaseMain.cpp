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

//�����в���+-----------------------------------------------------------
#ifdef ONE

	if (argc == 1) {
		cout << "�ź���ֻ��һ��������" << argv[0] << endl;
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
		cout << argv[file] << "�ļ����ַ�����Ϊ��" << anyone << endl;
		total += anyone;
		anyone = 0;
		
	}

	cout << argc - 1 << "���ļ��ַ�����Ϊ��" << total << endl;


	setlocale(LC_ALL,currentlocale.c_str());

#undef ONE
#endif // ONE

//�����ƶ�д�ļ�
#ifdef TWO
//������д���ļ�
	string outputfilename = "11";
	ofstream outfile(outputfilename, ios_base::out | ios_base::binary);
	if (!outfile.is_open()) {
		cout << "�ļ����ܴ򿪣�" << outputfilename << endl;
		exit(1);
	}
	const char infor[] = "abcdefg\n�л����񹲺͹�\n1234";
	outfile.write(infor, sizeof infor);
	outfile.close();
//�����ƶ�ȡ�ļ�
	const streamsize size = sizeof infor;
	char getinfor[size];
	string inputfilename = outputfilename;
	ifstream infile(inputfilename, ios_base::in | ios_base::binary);
	if (infile.is_open()) {
		cout << "�ļ�����������У�"<<endl;
		while (infile.read(getinfor, size)) {
			cout << getinfor;
		}
		cout << endl;
	}
	else {
		cout << "�ļ����ܴ򿪣�" << inputfilename << endl;
	}
	infile.close();

	//����һ����������������ȡ������д����ļ�
	infile.open(inputfilename, ios_base::in);
	//�������Ļ�����ʹ�ܴ����ֵȿ��ַ�
	string currentlocale = setlocale(LC_ALL, NULL);
	setlocale(LC_ALL, "chs");
	//��ȡ�ļ�
	char c;
	cout << "��һ��ķ�ʽ��ȡ���ļ��������£�" << endl;
	while(infile.get(c)) {
		cout << c;
	}
	cout << endl;
	infile.close();
	//��ȡ����

	//�ָ���������
	setlocale(LC_ALL, currentlocale.c_str());
	


#undef TWO
#endif // TWO


//�̶����ݽṹ���ļ��洢�Ĺ�����ʵ������洢�������д��
#ifdef THREE

	//���ȶ���һ�����ݽṹ���洢�̶���Ϣ
	const int sizeName = 255;
	const int sizeSex = 9;
	struct Person {
		char name[sizeName];
		int age;
		char sex[sizeSex];

	};
	Person person;
	//д����PersonΪ��λ����Ϣ���ļ�
	char inforPersonFile[] = "person.txt";
	//�Զ�д��������ģʽ�����ļ�
	//ͬʱ�Ը���ԭ�ļ�����ʽ��
	fstream finout(inforPersonFile, ios_base::in | ios_base::out | ios_base::binary);
	if (!finout.is_open()) {
		cout << "�ļ�����ʧ�ܣ�" << inforPersonFile << endl;
		exit(1);
	}


	/*
	//����д����Ϣ
	int i = 0;
	 int MaxRecords = 6;
	 cout << "������׼���洢�ļ�¼�����ֵ��";
	 cin >> MaxRecords;

	while(cin.good()){
		if (i > MaxRecords-1)
			break;
		cout <<"��"<<++i<< "���˵���Ϣ��������Person��������";
		cin>>person.name;
		check();
		cout << "��" << i << "���˵���Ϣ��������Person�����䣺";
		cin>>person.age ;
		check();
		cout << "��" << i << "���˵���Ϣ��������Person���Ա�";
		cin>>person.sex;
		check();
		
		finout.write((char*)&person, sizeof person);

	}
	
	finout.clear();
	д����Ϣ����
	*/



	//��ʾ������Ϣ����¼��
	cout << "�������ļ��������еļ�¼��Ϣ��" << endl;
	cout <<left
		<<setw(12)<<"���"
		<< setw(12) << "����" 
		<< setw(12) << "����" 
		<< setw(12) << "�Ա�" 
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
		//��������Ҫ�ı�ļ�¼���
		cout << "����������ı�ļ�¼���(��ʼ���Ϊ1����";
		recordnum = 0;
		cin >> recordnum;
		if (recordnum > allRecords) {
			break;
		}
		
		cout << "��ѡ��ı���ǣ�" << recordnum << endl;

		//��ȡѡ�����Ϣ
		finout.seekg((recordnum - 1)*(sizeof person));

		finout.read((char*)&person, sizeof person);
		cout << left
			<< setw(12) << "���"
			<< setw(12) << "����"
			<< setw(12) << "����"
			<< setw(12) << "�Ա�"
			<< endl;

		cout << left
			<< setw(12) << recordnum
			<< setw(12) << person.name
			<< setw(12) << person.age
			<< setw(12) << person.sex
			<< endl << endl;

		finout.clear();

		//��������ı���Ϣ
		cout << "����������ı����Ϣ��" << endl;
		cout << "������Person��������";
		cin >> person.name;

		cout << "������Person�����䣺";
		cin >> person.age;

		cout << "������Person���Ա�";
		cin >> person.sex;

		//д��ı���Ϣ
		finout.seekp((recordnum - 1)*(sizeof person));
		finout.write((char*)&person, sizeof person);
		finout.clear();

		//������ʾ���º�ļ�¼

		cout << "�ļ����º�ļ�¼��Ϣ��" << endl;
		cout << left
			<< setw(12) << "���"
			<< setw(12) << "����"
			<< setw(12) << "����"
			<< setw(12) << "�Ա�"
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

//�ں˸�ʽ����sstream---ostringstream----istringstream
#ifdef FOUR
	//д��string
	ostringstream ostrStream;
	ostrStream <<123<<"123"<<"abcd �л��� 123 �񹲺͹�";
	string str = ostrStream.str();
	cout << str << endl;
	
	//�������ݵ���ͬ���͵ı���
	//��ȡ��ʽ��Ȼ��������һ����ע�����Ķ�ȡֻ����ǰ��
	//��ȡʣ�µĻ�����������ȡ�����һ��ʲôҲû������
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

	
	//�ܽ᣺����������string������к�����
	//�������������ַ���������֮���ת����


	


#undef FOUR
#endif // FOUR
//��ϰ��ҵ��ƴ�������724ҳ��c++

#ifdef FIVE
	

	string infilea = "1.txt";//Ҫ��ȡ���ļ� �������Ѿ�����
	string infileb = "2.txt";//Ҫ��ȡ���ļ� �������Ѿ�����
	string outfile = "personsss.txt";//Ҫ������ļ��������ھ��½��ļ������ھ͸���ԭ�ļ���
	//����ļ���Ĭ�ϴ�ģʽ�ǣ�ios_base::out|ios_base::trun

	//���ļ�
	ifstream instream_a(infilea);
	ifstream instream_b(infileb);

	ofstream outstream(outfile);
	//���������һ���ļ�û���ܴ򿪣���������󣺹ر��ļ����˳�����
	if (!(instream_a.is_open() && instream_b.is_open() && outstream.is_open()))
		goto LAST;//Ŀ����������л���ر����п����гɹ��򿪵��ļ���
	
	char c;
	
	while (1) {//ѭ����ȡ�����ļ�,while(1)��Ϊ�棬Ŀ���������ļ��������ţ�����ȫ������������ݡ�
		string stra, strb;//�����������ַ���string���������Ŀ����ʼ���������Ǳ���Ϊ�յ�״̬��
	
		while (!instream_a.eof()) {//�ļ�������˳�
			c = instream_a.get();	//�ļ�����ǰ�������EOF��־�ַ�
			if(c!=EOF)//���붪������ַ������򣬰����洢��stringʱ����ִ���
			stra.append(1, c);//ʼ�մ洢�����ַ�������Enter)����EOF�⡣
			if (c == '\n')
				break;

		}
		//����������ȫ��ͬ��˼·��
		while (!instream_b.eof()) {
			c = instream_b.get();
			if (c != EOF)
			strb.append(1, c);
			if (c == '\n')
				break;
		}
		//��ʼд���ļ�����һ���ļ�������
		if (stra.size()) {//�����ݲ�д
			
			if (strb.size()) {//����ڶ����ļ������ݣ�
				stra.back()= ' ';//����Ҫ�滻����һ���ļ������ݵ����һ���ַ���ʼ��ΪEnter�������滻��EnterΪ�ո񣬷�ֹ���С�
			}
			outstream << stra;//�����ݾ�д���ļ�
		}
		//�ڶ����ļ������ݡ�
		if (strb.size()) {//�����ݾ�д���ļ�
			outstream << strb;
		}
	
		//�����ļ������꣬���˳���ѭ�����ٶ�ȡ�ļ��ˡ�
		if (instream_a.eof() && instream_b.eof())
			break;
	 }
LAST:
	instream_a.close();
	instream_b.close();
	outstream.close();



#undef FIVE
#endif // FIVE

//��ϰ��ҵ�����������������ļ����ҳ�������������ȥ���ظ��ģ�д���ļ��б��档
#ifdef SIX

	ifstream mdstream("md.txt");
	ifstream pdstream("pd.txt");
	ofstream mpdstream("mpd.txt");

	const char Enter = '\n';
	string names;//���ڴ������в��ظ�������
	string currentname;//��ǰ���ļ���ȡ��ĳ������
	while (!mdstream.eof()) {
		//���ļ� ��ȡ����<<��������ȡ�����������հ׷��������ո��е��ַ�����ֹͣ��ȡ��
		mdstream >> currentname;
		if(mdstream.peek()!=Enter)//���û�������������з���
			mdstream.ignore(255, '\n');//�Ͷ���ʣ��ָ���������ַ����ߵ���һ�����з�Ϊֹ��
		
		if (names.find(currentname)==string::npos) {//�����ǰ��ȡ�����������е�����û���ظ�
			names.append(currentname);//�ʹ洢
			names.append(1, ',');
			mpdstream << currentname << endl;//��д���ļ���
			
		}
	}
	//����������ȫ��ͬ����ȡ���ļ���ͬ���ѡ�
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
	cout << names << endl;//���ԣ��ѽ����ʾ����Ļ
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
