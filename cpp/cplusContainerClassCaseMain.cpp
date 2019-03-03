#include <iostream>
#include<vector>
#include<time.h>
#include<iomanip>
#include<list>
#include<string>


using namespace std;

//����define�������1-x��Χ�ڵ��������������
#define random(x) rand()%x

#define THREE


//��������
class MyIterator : public std::iterator<std::input_iterator_tag, int>
{
	int* p;
public:
	MyIterator(int* x) :p(x) {}
	MyIterator(const MyIterator& mit) : p(mit.p) {}
	MyIterator& operator++() { ++p;return *this; }
	MyIterator operator++(int) { MyIterator tmp(*this); operator++(); return tmp; }
	bool operator==(const MyIterator& rhs) const { return p == rhs.p; }
	bool operator!=(const MyIterator& rhs) const { return p != rhs.p; }
	int& operator*() { return *p; }
};










 
template<typename TVector>
void coutVector(vector<TVector>&);




template<typename TList>
void coutList(list<TList>&);


//list::remove_if��غ���
template<typename TRemoveIf>
bool boolByRemoveIf(const TRemoveIf);
//list::merge��صĺ���
bool mycomparison(double, double);

//list::unique()��صĺ���
bool same_integral_part(double, double);
bool maxof(int, int);
bool oddnumber(int, int);

// a binary predicate implemented as a class:
struct is_near {
	bool operator() (double first, double second)
	{
		return (fabs(first - second) < 5.0);
	}
};



//list::sort()��غ���
bool compare_nocase(const std::string&, const std::string&);








int cplusContainerClassCaseMain() {

	cout << "This is cplusContainerClassCaseMain()!" << endl;

	//������������
//vector
	//�����洢�ṹ��ÿ��Ԫ�����ڴ����������ģ�
	//	֧�ָ�Ч��������ʺ���β�˲��� / ɾ��������������λ�õĲ��� / ɾ������Ч�ʵ��£�
#ifdef ONE
	//���塢��ֵ����ȡ----------------------------------------------------------------------------------------------
	const int Max = 15;
	vector<int> vint;
	for (int i = 0;i < Max;i++) {
		vint.push_back(i);

	}
	//vector�����ȫ��ֵ
	cout << "vector��ǰȫ��ֵΪ��" << endl;
	for (int i = 0;i < Max;i++) {
		cout << vint[i] << " ";
	}
	cout << endl;

	//�˽�vector��ǰ�洢����������-------------------------------------------------------------------------
	cout << "��ǰ���洢������" << vint.capacity() << endl;
	cout << "��ǰ�洢�Ķ���������" << vint.size() << endl;
	int oldsize = vint.size();
	vint.resize(oldsize - 1);
	cout << "vector::resize(" << oldsize - 1 << ")���ú��size()�ǣ�" << vint.size() << endl;
	oldsize = vint.size();
	cout << "vector::reserve(" << oldsize * 2 << ")���ú��size()�ǣ�" << vint.size() << endl;
	cout << "vector::swap()";
	cout << "������ʾ����vector::size(),vector::resize(),vector::reserve()֮��Ĺ�ϵ��" << endl;

	//[]��������ʹ��----�����ȡvector<int>�����ֵ-----------------------------------------------------
	if (0) {
		//����������ӣ���Ȼÿ�����ж�һ��������ʱ��Ϊ���ӣ�
		srand(int(time(0)));
		//����ע�⣺ʹ����ʱ��vector�����ڸ�λ���Ѿ���ֵ�ˣ�������ִ���
		int n = random(vint.size() + 1) - 1;
		cout << "���λ�� " << n << " ��ȡ��ֵΪ:" << vint[n] << endl;
	}



	//c.assign(beg,end)��[beg; end)�����е����ݸ�ֵ��c��---------------------------------------------------------
	//c.assign(n, elem)��n��elem�Ŀ�����ֵ��c��
	if (0) {
		oldsize = vint.size();
		cout << "vint�Ĵ�СΪ��" << oldsize << endl;
		cout << "vint��ֵΪ��" << endl;
		for (int i = 0;i < vint.size();i++) {
			cout << vint[i] << " ";
		}
		cout << endl;
		vector<int> vint2;
		//c.assign(beg,end)--------------------
		vint2.assign(vint.begin(), vint.end() - 2);
		cout << "vint2����vint2.assign(vint.begin(), vint.end() - 2)���ֵΪ��" << endl;
		for (int i = 0;i < vint2.size();i++) {
			cout << vint2[i] << " ";
		}
		cout << endl;
		//c.assign(n, elem)-------------------
		vint2.assign(3, 9);
		cout << "vint2����vint2.assign(3, 9)���ֵΪ��" << endl;
		for (int i = 0;i < vint2.size();i++) {
			cout << vint2[i] << " ";
		}
		cout << endl;



	}
	//vector::clear(),vector::at(size_t),vector::front(),vector::back()
	if (0) {

		vint.clear();
		cout << "vint.clear()֮���ֵΪ��" << endl;
		for (int i = 0;i < vint.size();i++) {
			cout << vint[i] << " ";
		}
		cout << endl;

		vint.assign(5, 9);
		cout << "vint.assign(5, 9)֮���ֵΪ��" << endl;
		for (int i = 0;i < vint.size();i++) {
			cout << vint[i] << " ";
		}
		cout << endl;

		cout << "vint.at(vint.size() - 1)��ֵΪ��" << vint.at(vint.size() - 1) << endl;

		cout << "vint.front()��ֵΪ��" << vint.front() << endl;

		cout << "vint.back()��ֵΪ��" << vint.back() << endl;

	}


	//vint.data(),vint.data()const-------------------------------------------------------------------
	if (0) {
		cout << "vint��ǰȫ��ֵΪ��---" << endl;
		for (int i = 0;i < vint.size();i++) {
			cout << vint[i] << " ";
		}
		cout << endl;
		cout << "vint.data():" << endl;
		for (int i = 0;i < vint.size();i++) {
			cout << *(vint.data() + i) << " ";
		}
		cout << endl;




	}

	//vint.pop_back��vint.putback()-------------------------------
	if (0) {
		cout << "vint��ֵΪ��" << endl;
		for (int i = 0;i < vint.size();i++) {
			cout << vint[i] << " ";
		}
		cout << endl;

		vint.pop_back();
		cout << "vint.pop_back֮���ֵΪ:" << endl;
		for (int i = 0;i < vint.size();i++) {
			cout << vint[i] << " ";
		}
		cout << endl;

		vint.push_back(100);

		cout << "vint.push_back(100)֮���ֵΪ:" << endl;
		for (int i = 0;i < vint.size();i++) {
			cout << vint[i] << " ";
		}
		cout << endl;
	}
	//vint.emplace()
	if (0) {
		cout << "vint��ֵΪ��" << endl;
		for (int i = 0;i < vint.size();i++) {
			cout << vint[i] << " ";
		}
		cout << endl;


		vint.emplace(vint.cbegin() + 2, 55);
		cout << "vint.emplace(vint.begin()+2, 55)֮���ֵΪ��" << endl;
		for (int i = 0;i < vint.size();i++) {
			cout << vint[i] << " ";
		}
		cout << endl;




	}

	//vint.insert()
//https://en.cppreference.com/w/cpp/container/vector/insert
	if (0) {
		//����vector�ķ�ʽ
		std::vector<int> myvector(3, 100);


		coutVector(myvector);
		std::vector<int>::iterator it;

		it = myvector.begin();
		it = myvector.insert(it, 200);
		coutVector(myvector);
		myvector.insert(it, 2, 300);
		coutVector(myvector);
		// "it" no longer valid, get a new one:
		it = myvector.begin();

		std::vector<int> anothervector(2, 400);
		coutVector(anothervector);
		myvector.insert(it + 2, anothervector.begin(), anothervector.end());
		coutVector(myvector);
		int myarray[] = { 501,502,503 };
		myvector.insert(myvector.begin(), myarray, myarray + 3);
		coutVector(myvector);
		//����vector�ķ�ʽ
		vector<int> v{ 1,2,3,4,5 };
		vector<int> v1{ 6,7,8,9,10 };
		v.insert(v.end(), v1.begin(), v1.begin() + 5);
		coutVector(v);
		v.insert(v.begin(), v.begin(), v.end());
		coutVector(v);


		//����vector�ķ�ʽ
		// initialising the vector 
		vector<int> vec = { 10, 20, 30, 40 };
		coutVector(vec);

		std::vector<int> nums1{ 3, 1, 4, 6, 5, 9 };
		std::vector<int> nums2;
		std::vector<int> nums3;

		std::cout << "Initially:\n";
		coutVector(nums1);
		coutVector(nums2);

		coutVector(nums3);


		// copy assignment copies data from nums1 to nums2
		nums2 = nums1;

		std::cout << "After assigment:\n";
		coutVector(nums1);
		coutVector(nums2);

		coutVector(nums3);

		// move assignment moves data from nums1 to nums3,
		// modifying both nums1 and nums3
		nums3 = std::move(nums1);

		std::cout << "After move assigment:\n";

		coutVector(nums1);
		coutVector(nums2);

		coutVector(nums3);
	}


	////
	//vint.operator=;
	//vint.shrink_to_fit;
	//vint.swap();
	if (1) {
		cout << "1:";
		coutVector(vint);
		vector<int> vintx;
		vint.swap(vintx);//��vint���е�vintx.vint��Ϊ�գ�vintx���ԭ��vint��ֵ
		cout << "2:";
		coutVector(vintx);
		cout << "3:";
		coutVector(vint);
		cout << "vint.size():" << vint.size() << endl;

		cout << "data:" << *(vintx.data() + 2) << endl;





	}



#undef ONE
#endif // ONE

	

	//list
		//�������洢�ṹ������˫����ṹ��ÿ��Ԫ��ά��һ��ǰ��ͺ���ָ�룬���֧��ǰ�� / ���������
		//	֧�ָ�Ч��������� / ɾ�����������������Ч�ʵ��£���������Ҫ����ά��ָ�룬����Ҳ�Ƚϴ�

#ifdef TWO
 // һ�����캯�����ʼ����---------------------------------------------------------------------
	if (0) {
		//�������ֳ�ʼ���ķ����ȽϷ�����
		//���캯��֮�㣺����һ���յ�list,Ҳ����������ʼ����
		list<int> intList = { 13,24,75,92,10,84 };//list<int> intList();
		coutList<int>(intList);

		//���캯��֮һ��ָ���洢Ԫ�ظ���
		list<int> firstList(4);
		cout << "list<int> firstList(4) �����" << endl;
		cout << firstList.size() << endl;

		//���캯��֮����ָ���洢��ͬ��Ԫ�ؼ�����
		list<int> secondList(4, 9);
		cout << "list<int> secondList(4, 9) �����" << endl;
		coutList(secondList);

		//���캯��֮�����ñ��list�ĵ��������ݹ����µ�list
		list<int> three(intList.rbegin(), intList.rend());
		cout << "list<int> three(intList.rbegin(), intList.rend()) �����" << endl;
		coutList(three);

		//���캯��֮�ģ�ֱ������һ����ͬ���͵�list������list
		list<int> four(intList);
		cout << "list<int> four(intList) �����" << endl;
		coutList(four);
	}



	//����list��Ա������list��������-----------------------------------------------------------------

	//1.list�������Ի���Ϣ 
	if (0) {
		list<int> intList = { 3,4,9,22,98,47,25 };
		cout << "list<int>::size():" << endl;
		cout << intList.size() << endl;

		cout << "list<int>::max_size():" << endl;
		cout << intList.max_size() << endl;

		cout << "list<int>::empty():" << endl;
		cout << intList.empty() << endl;




	}


	//2.list�Ĳ�����ɾ��
	list<int> intList = { 2,4,6,8,10,12 };
	list<int> otherList;
	if (0) {//list::assign()



		otherList.assign(intList.rbegin(), intList.rend());//���list��iterator
		cout << "otherList.assign(intList.rbegin(),intList.rend()) :" << endl;
		coutList(otherList);

		otherList.assign(3, 8);//ָ��������ֵ
		cout << "otherList.assign(3, 8)��" << endl;
		coutList(otherList);

		int myints[] = { 1776,7,4 };
		otherList.assign(myints, myints + 3);//����
		cout << "otherList.assign(myints,myints+3)��" << endl;
		coutList(otherList);

	}

	if (0) {//list::insert()
		if (0) {
			intList.insert(intList.begin(), 99);
			cout << "intList.insert(intList.begin(), 99)��" << endl;
			coutList(intList);

			//��һ�ַ�������Ȼ������list::begin()+2֮��ķ�����
			//��������++,--�Ĳ�����
			list<int>::iterator it = ++intList.begin();
			intList.insert(it, 88);
			cout << "intList.insert(it, 99)��" << endl;
			coutList(intList);

			//�������ñ����ķ���Ѱ�Ҳ����λ��
			for (list<int>::iterator iter = intList.begin();iter != intList.end();iter++) {
				if (*iter == 8) {
					intList.insert(iter, 100);
				}
			}
			cout << "��������Ѱ�Ҳ���λ�ã�ֵΪ8�Ĳ���100��" << endl;
			coutList(intList);
		}
		if (0) {
			otherList.insert(otherList.begin(), intList.rbegin(), intList.rend());
			cout << "������һ��list�ĵ��������������ݣ�" << endl;
			coutList(otherList);
			cout << "���Լ��ĵ������ݲ��룺" << endl;
			otherList.insert(otherList.begin(), otherList.rbegin(), otherList.rend());
			coutList(otherList);

		}

		if (0) {
			intList.insert(intList.begin(), 2, 150);//����һ�ַ���
			coutList(intList);
		}
	}

	if (0) {//��ӻ����޸ģ���ʼ���β�ģ�һ��Ԫ�ء�
		//list::push_front() push_back() front() back()
		intList.push_front(33);
		intList.push_back(44);
		coutList(intList);
		intList.front() = 55;
		intList.back() = 67;
		coutList(intList);
		//list::pop_front();list::pop_back()ɾ��һ��Ԫ��
		intList.pop_front();
		intList.pop_back();
		coutList(intList);
	}


	if (0) {
		otherList.clear();//ɾ��ȫ��Ԫ�ء�
		coutList(otherList);

		otherList.assign(intList.rbegin(),intList.rend());
		coutList(otherList);
		//����ֵɾ��
		otherList.remove(8);
		coutList(otherList);
		//��������ɾ���������棡
		cout << "remove_if:" << endl;
		otherList.remove_if(boolByRemoveIf<int>);//boolByRemoveIf����������
		coutList(otherList);
		//�ı�������С���ܻ�ɾ��ĳЩԪ�ء�
		otherList.resize(otherList.size() - 2);
		coutList(otherList);
		//list::reverse()�ߵ�˳��
		otherList.assign(intList.rbegin(), intList.rend());
		coutList(otherList);
		otherList.reverse();
		coutList(otherList);
		//list:;emplace(),emplace_front(),emplace_back()

		otherList.emplace(otherList.begin(), 10);
		otherList.emplace_front(73);
		otherList.emplace_back(19);
		coutList(otherList);

		//ע��std::pair�ṹ�Ķ��塣
		if (0) {
			std::list< std::pair<int, char> > mylist;
			//������Ĳ����������Ե�֪��emplace()��ֵ�Ĳ����������Բ�����
			mylist.emplace(mylist.begin(), 100, 'x');
			mylist.emplace(mylist.begin(), 200, 'y');

			std::cout << "mylist contains:";
			for (auto& x : mylist)
				std::cout << " (" << x.first << "," << x.second << ")";

			std::cout << '\n';
		}

	}

	//��������Ӻ������
	//erase()ɾ��ָ��λ�û�ָ�������ڵ�Ԫ�ء�
	if (0) {//list::erase();
		std::list<int> mylist;
		std::list<int>::iterator it1, it2;

		// set some values:
		for (int i = 1; i < 10; ++i) mylist.push_back(i * 10);

									// 10 20 30 40 50 60 70 80 90
		it1 = it2 = mylist.begin(); // ^^
		advance(it2, 6);            // ^                 ^
		++it1;                      //    ^              ^

		it1 = mylist.erase(it1);   // 10 30 40 50 60 70 80 90
									//    ^           ^

		it2 = mylist.erase(it2);   // 10 30 40 50 60 80 90
									//    ^           ^

		++it1;                      //       ^        ^
		--it2;                      //       ^     ^
		//֮�����˼��[)ǰһ���㣬��һ�����㡣
		mylist.erase(it1, it2);     // 10 30 60 80 90
									//        ^

		std::cout << "mylist contains:";
		for (it1 = mylist.begin(); it1 != mylist.end(); ++it1)
			std::cout << ' ' << *it1;
		std::cout << '\n';
	}

	if (0) {
		//�ܽ᣺list::merge()ʹ��ǰ�������򡣵���Ҫ�Զ�����������ʱ��ע�������������Զ�������֮��Ҫһ�¡�
		//��Ҫ��������Ҫ���򣬶����򡣽���ʹ��merge(,greater<>())��
		std::list<double> first, second;

		first.push_back(3.1);
		first.push_back(2.2);
		first.push_back(2.9);

		second.push_back(3.7);
		second.push_back(7.1);
		second.push_back(1.4);
		//merge()֮ǰ��������
		first.sort();
		second.sort();
		


		first.merge(second);
		
		second.push_back(2.1);
		
		
		first.merge(second, mycomparison);
		
 		std::cout << "first contains:";
		for (std::list<double>::iterator it = first.begin(); it != first.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

	}


	if (0) {
		//list::splice ƴ��������򲿷����ݡ�
	/*	������Ҫ���������list���

		void splice(const_iterator position, list& x);
		void splice(const_iterator position, list&& x);


		���涼����գ�ֻ��ָ��������������ߡ�
		void splice(const_iterator position, list& x, const_iterator i);
		void splice(const_iterator position, list&& x, const_iterator i);
	
		void splice(const_iterator position, 
					list& x,
					const_iterator first, 
					const_iterator last);
		void splice(const_iterator position, 
					list&& x,
					const_iterator first, 
					const_iterator last);
			*/

		std::list<int> mylist1, mylist2;
		std::list<int>::iterator it;

		// set some initial values:
		for (int i = 1; i <= 4; ++i)
			mylist1.push_back(i);      // mylist1: 1 2 3 4

		for (int i = 1; i <= 3; ++i)
			mylist2.push_back(i * 10);   // mylist2: 10 20 30

		it = mylist1.begin();
		//ָ���ƶ���������������
		++it;                         // points to 2
		//Ҫ������һ������յķ���
		mylist1.splice(it, mylist2); // mylist1: 1 10 20 30 2 3 4
									  // mylist2 (empty)
									  // "it" still points to 2 (the 5th element)
		//����յķ���
		mylist2.splice(mylist2.begin(), mylist1, it);
		// mylist1: 1 10 20 30 3 4
		// mylist2: 2
		// "it" is now invalid.
		it = mylist1.begin();
		//ָ���ƶ�����һ��Ч����������list�ĳ�Ա����ס������������
		std::advance(it, 3);           // "it" points now to 30
		//����ķ�Χ����[ )���֡�
		mylist1.splice(mylist1.begin(), mylist1, it, mylist1.end());
		// mylist1: 30 3 4 1 10 20

		std::cout << "mylist1 contains:";
		for (it = mylist1.begin(); it != mylist1.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		std::cout << "mylist2 contains:";
		for (it = mylist2.begin(); it != mylist2.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}



	if (0) {
		//void swap(list& x);�����������ݱ˴˽�����
		std::list<int> first(3, 100);   // three ints with a value of 100
		std::list<int> second(5, 200);  // five ints with a value of 200

		first.swap(second);

		std::cout << "first contains:";
		for (std::list<int>::iterator it = first.begin(); it != first.end(); it++)
			std::cout << ' ' << *it;
		std::cout << '\n';

		std::cout << "second contains:";
		for (std::list<int>::iterator it = second.begin(); it != second.end(); it++)
			std::cout << ' ' << *it;
		std::cout << '\n';

	}


	if (0) {
		//�������ݵ�Ψһ�ԡ�ʹ��ǰҪ������
		//��һ��û�в����ģ�������ֵͬ�еĵ�һ����
		//�ڶ��ָ�������������һ����
		//���������֣��������ࡣ����ֻ�����ֳ��֣���Ҫʵ��һ��operator()����������������г������š�
		//void unique();
		/*template <class BinaryPredicate>
		void unique(BinaryPredicate binary_pred);*/
		//-----------------------------------------------------------------------------
		

		
			double mydoubles[] = { 12.15,  2.72, 73.0,  12.77,  3.14,
								 12.77, 73.35, 72.25, 15.3,  72.25 };
			std::list<double> mylist(mydoubles, mydoubles + 10);

			mylist.sort();             //  2.72,  3.14, 12.15, 12.77, 12.77,
									   // 15.3,  72.25, 72.25, 73.0,  73.35

			mylist.unique();           //  2.72,  3.14, 12.15, 12.77
									   // 15.3,  72.25, 73.0,  73.35

			mylist.unique(same_integral_part);  //  2.72,  3.14, 12.15
												 // 15.3,  72.25, 73.0

			mylist.unique(is_near());           //  2.72, 12.15, 72.25

			std::cout << "mylist contains:";
			for (std::list<double>::iterator it = mylist.begin(); it != mylist.end(); ++it)
				std::cout << ' ' << *it;
			std::cout << '\n';


	}

	if (0) {//��ϰ��ѧϰ���档void unique()

		list<int> intList = { 99,2,47,99,26,51,2,46 };
		//--------------������ʹ����ʲô����----------------------------
		intList.unique();//�������ʹ��ûЧ����������������ȵ�ֵ��
		//coutList(intList);
		intList.push_front(99);
		//coutList(intList);//99��ɾ��һ����֤����unique()ֻ�������Ѿ�����ֻ�Ƚ�����Ԫ��֮���ֵ��С��
		intList.unique();//����ȣ���ɾ������ģ�������һ����
		//coutList(intList);
		//--------------������ʹ����ʲô����----------------------------

		//--------------������ʹ����ʲô����----------------------------
		intList.sort();
		//coutList(intList);
		intList.unique();
		//coutList(intList);
		//���ֵֻ������һ����Ч���ﵽ��
		//--------------������ʹ����ʲô����----------------------------



		//--------------������������ʹ����ʲô����----------------------------
		intList.unique(maxof);//ֻ�������ֵ�����Ľ����ֻʣһ����С�ġ�������������
		cout << "----" << endl;
		coutList(intList);

		//ȡ������ӵ����ģ�ֻ����һ��
		intList = { 12,13,17,26,31,33,38,49 };
		coutList(intList);
		intList.unique(oddnumber);
		coutList(intList);//����������Ԥ�ڣ��ɹ���

		//--------------������������ʹ����ʲô����----------------------------


	}


	//3.����list::sort()
	//(1)void sort();Ĭ������
	//(2)template <class Compare>
	//	void sort(Compare comp);//����������������
	if (0) {
		std::list<std::string> mylist;
		std::list<std::string>::iterator it;
		mylist.push_back("one");
		mylist.push_back("two");
		mylist.push_back("Three");
		mylist.push_back("Thread");//���������Ԫ��
		mylist.push_back("Threads");
		mylist.sort();

		std::cout << "mylist contains:";
		for (it = mylist.begin(); it != mylist.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		mylist.sort(compare_nocase);

		std::cout << "mylist contains:";
		for (it = mylist.begin(); it != mylist.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';


	}


	//4.list.get_allocator()   ������
	if (0) {//http://www.cplusplus.com/reference/memory/allocator/?kw=allocator(�й�allocator�ࣩ

		std::list<int> mylist;
		int * p;
		
		// allocate an array of 5 elements using mylist's allocator:
		p = mylist.get_allocator().allocate(5);

		// assign some values to array
		for (int i = 0; i < 5; ++i) p[i] = i;

		std::cout << "The allocated array contains:";
		for (int i = 0; i < 5; ++i) std::cout << ' ' << p[i];
		std::cout << '\n';

		//mylist.get_allocator().deallocate(p, 5);
		coutList(mylist);

	}



#undef	TWO
#endif // TWO

	
#ifdef THREE
	//������
	int numbers[] = { 10,20,30,40,50 };
	MyIterator from(numbers);
	MyIterator until(numbers + 5);
	for (MyIterator it = from; it != until; it++)
		std::cout << *it << ' ';
	std::cout << '\n';


#undef THREE
#endif // 

		
	
	




	return 0;
}

/*-----------------------------����------------------------------------------------------------------
*/

//����һ��ģ�庯�����������vector�����ڵ�����Ԫ��
//vector�洢Ԫ�ص��ڴ��ַ�������ģ��������������
//[]�������洢Ԫ�أ�Ҳ������begin()+2֮��ġ���
template<typename TVector>
void coutVector(vector<TVector>& myvector) {

	for (int i = 0;i < myvector.size();i++) {
		cout << myvector[i] << " ";
	}
	cout << endl;
}


//����һ��ģ�庯�����������list�����ڵ�����Ԫ��

template<typename TList>
void coutList(list<TList>& myList) {
	//�ر�ע�⣺����ģ����ඨ��һ������ʱ����ǰ��һ��Ҫ��һ��typename,���򣬱�������֪����
	//��һ���Զ�����ࡣ��������ȷ�ģ�typename list<TList>::iterator it��
	for (typename list<TList>::iterator it = myList.begin();it != myList.end();it++) {
		//����list�洢Ԫ�ص��ڴ��ַ�������������Բ���ʹ��[]����begin()+2֮��ġ���
		cout << *it << " ";
	}
	cout << endl;
}


//list::remove_if��صĺ���
template<typename TRemoveIf>
bool boolByRemoveIf(const TRemoveIf value) {
	return value < 5;
}

//list::merge
// compare only integral part:
bool mycomparison(double firsta, double secondb)
{
	int tmp = int(firsta)< int(secondb);
	return tmp;
}


//list::unique()��صĺ���

// a binary predicate implemented as a function:
bool same_integral_part(double first, double second)
{
	return (int(first) == int(second));
}

bool maxof(int first, int second)
{
	return ((first) < (second));
}

bool oddnumber(int first, int second)
{
	return (int(first)+int(second))%2;
}

//list::sort()��غ���

// comparison, not case sensitive.
bool compare_nocase(const std::string& first, const std::string& second)
{
	unsigned int i = 0;
	while ((i < first.length()) && (i < second.length()))
	{
		if (tolower(first[i]) < tolower(second[i])) return true;
		else if (tolower(first[i]) > tolower(second[i])) return false;
		++i;
	}
	return (first.length() < second.length());
}