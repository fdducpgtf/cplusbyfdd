#include <iostream>
#include<vector>
#include<time.h>
#include<iomanip>
#include<list>
#include<string>


using namespace std;

//利用define定义输出1-x范围内的随机数（整数）
#define random(x) rand()%x

#define THREE


//迭代器类
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


//list::remove_if相关函数
template<typename TRemoveIf>
bool boolByRemoveIf(const TRemoveIf);
//list::merge相关的函数
bool mycomparison(double, double);

//list::unique()相关的函数
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



//list::sort()相关函数
bool compare_nocase(const std::string&, const std::string&);








int cplusContainerClassCaseMain() {

	cout << "This is cplusContainerClassCaseMain()!" << endl;

	//代码其它内容
//vector
	//连续存储结构，每个元素在内存上是连续的；
	//	支持高效的随机访问和在尾端插入 / 删除操作，但其他位置的插入 / 删除操作效率低下；
#ifdef ONE
	//定义、赋值、读取----------------------------------------------------------------------------------------------
	const int Max = 15;
	vector<int> vint;
	for (int i = 0;i < Max;i++) {
		vint.push_back(i);

	}
	//vector里面的全部值
	cout << "vector当前全部值为：" << endl;
	for (int i = 0;i < Max;i++) {
		cout << vint[i] << " ";
	}
	cout << endl;

	//了解vector当前存储方面的情况：-------------------------------------------------------------------------
	cout << "当前最大存储数量：" << vint.capacity() << endl;
	cout << "当前存储的对象数量：" << vint.size() << endl;
	int oldsize = vint.size();
	vint.resize(oldsize - 1);
	cout << "vector::resize(" << oldsize - 1 << ")作用后的size()是：" << vint.size() << endl;
	oldsize = vint.size();
	cout << "vector::reserve(" << oldsize * 2 << ")作用后的size()是：" << vint.size() << endl;
	cout << "vector::swap()";
	cout << "以上演示的是vector::size(),vector::resize(),vector::reserve()之间的关系！" << endl;

	//[]操作符的使用----随机读取vector<int>里面的值-----------------------------------------------------
	if (0) {
		//设置随机种子，不然每次运行都一样。（以时间为种子）
		srand(int(time(0)));
		//必须注意：使用它时，vector本身在该位置已经有值了，否则出现错误。
		int n = random(vint.size() + 1) - 1;
		cout << "随机位置 " << n << " 读取的值为:" << vint[n] << endl;
	}



	//c.assign(beg,end)将[beg; end)区间中的数据赋值给c。---------------------------------------------------------
	//c.assign(n, elem)将n个elem的拷贝赋值给c。
	if (0) {
		oldsize = vint.size();
		cout << "vint的大小为：" << oldsize << endl;
		cout << "vint的值为：" << endl;
		for (int i = 0;i < vint.size();i++) {
			cout << vint[i] << " ";
		}
		cout << endl;
		vector<int> vint2;
		//c.assign(beg,end)--------------------
		vint2.assign(vint.begin(), vint.end() - 2);
		cout << "vint2经过vint2.assign(vint.begin(), vint.end() - 2)后的值为：" << endl;
		for (int i = 0;i < vint2.size();i++) {
			cout << vint2[i] << " ";
		}
		cout << endl;
		//c.assign(n, elem)-------------------
		vint2.assign(3, 9);
		cout << "vint2经过vint2.assign(3, 9)后的值为：" << endl;
		for (int i = 0;i < vint2.size();i++) {
			cout << vint2[i] << " ";
		}
		cout << endl;



	}
	//vector::clear(),vector::at(size_t),vector::front(),vector::back()
	if (0) {

		vint.clear();
		cout << "vint.clear()之后的值为：" << endl;
		for (int i = 0;i < vint.size();i++) {
			cout << vint[i] << " ";
		}
		cout << endl;

		vint.assign(5, 9);
		cout << "vint.assign(5, 9)之后的值为：" << endl;
		for (int i = 0;i < vint.size();i++) {
			cout << vint[i] << " ";
		}
		cout << endl;

		cout << "vint.at(vint.size() - 1)的值为：" << vint.at(vint.size() - 1) << endl;

		cout << "vint.front()的值为：" << vint.front() << endl;

		cout << "vint.back()的值为：" << vint.back() << endl;

	}


	//vint.data(),vint.data()const-------------------------------------------------------------------
	if (0) {
		cout << "vint当前全部值为：---" << endl;
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

	//vint.pop_back与vint.putback()-------------------------------
	if (0) {
		cout << "vint的值为：" << endl;
		for (int i = 0;i < vint.size();i++) {
			cout << vint[i] << " ";
		}
		cout << endl;

		vint.pop_back();
		cout << "vint.pop_back之后的值为:" << endl;
		for (int i = 0;i < vint.size();i++) {
			cout << vint[i] << " ";
		}
		cout << endl;

		vint.push_back(100);

		cout << "vint.push_back(100)之后的值为:" << endl;
		for (int i = 0;i < vint.size();i++) {
			cout << vint[i] << " ";
		}
		cout << endl;
	}
	//vint.emplace()
	if (0) {
		cout << "vint的值为：" << endl;
		for (int i = 0;i < vint.size();i++) {
			cout << vint[i] << " ";
		}
		cout << endl;


		vint.emplace(vint.cbegin() + 2, 55);
		cout << "vint.emplace(vint.begin()+2, 55)之后的值为：" << endl;
		for (int i = 0;i < vint.size();i++) {
			cout << vint[i] << " ";
		}
		cout << endl;




	}

	//vint.insert()
//https://en.cppreference.com/w/cpp/container/vector/insert
	if (0) {
		//定义vector的方式
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
		//定义vector的方式
		vector<int> v{ 1,2,3,4,5 };
		vector<int> v1{ 6,7,8,9,10 };
		v.insert(v.end(), v1.begin(), v1.begin() + 5);
		coutVector(v);
		v.insert(v.begin(), v.begin(), v.end());
		coutVector(v);


		//定义vector的方式
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
		vint.swap(vintx);//把vint剪切到vintx.vint变为空，vintx变成原来vint的值
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
		//非连续存储结构，具有双链表结构，每个元素维护一对前向和后向指针，因此支持前向 / 后向遍历。
		//	支持高效的随机插入 / 删除操作，但随机访问效率低下，且由于需要额外维护指针，开销也比较大。

#ifdef TWO
 // 一、构造函数或初始化：---------------------------------------------------------------------
	if (0) {
		//下面这种初始化的方法比较方便快捷
		//构造函数之零：构造一个空的list,也可以立即初始化。
		list<int> intList = { 13,24,75,92,10,84 };//list<int> intList();
		coutList<int>(intList);

		//构造函数之一：指定存储元素个数
		list<int> firstList(4);
		cout << "list<int> firstList(4) 结果：" << endl;
		cout << firstList.size() << endl;

		//构造函数之二：指定存储相同的元素及数量
		list<int> secondList(4, 9);
		cout << "list<int> secondList(4, 9) 结果：" << endl;
		coutList(secondList);

		//构造函数之三：用别的list的迭代器数据构造新的list
		list<int> three(intList.rbegin(), intList.rend());
		cout << "list<int> three(intList.rbegin(), intList.rend()) 结果：" << endl;
		coutList(three);

		//构造函数之四：直接用另一个相同类型的list构造新list
		list<int> four(intList);
		cout << "list<int> four(intList) 结果：" << endl;
		coutList(four);
	}



	//二、list成员函数及list基本操作-----------------------------------------------------------------

	//1.list基本属性或信息 
	if (0) {
		list<int> intList = { 3,4,9,22,98,47,25 };
		cout << "list<int>::size():" << endl;
		cout << intList.size() << endl;

		cout << "list<int>::max_size():" << endl;
		cout << intList.max_size() << endl;

		cout << "list<int>::empty():" << endl;
		cout << intList.empty() << endl;




	}


	//2.list的插入与删除
	list<int> intList = { 2,4,6,8,10,12 };
	list<int> otherList;
	if (0) {//list::assign()



		otherList.assign(intList.rbegin(), intList.rend());//别的list的iterator
		cout << "otherList.assign(intList.rbegin(),intList.rend()) :" << endl;
		coutList(otherList);

		otherList.assign(3, 8);//指定数量的值
		cout << "otherList.assign(3, 8)：" << endl;
		coutList(otherList);

		int myints[] = { 1776,7,4 };
		otherList.assign(myints, myints + 3);//数组
		cout << "otherList.assign(myints,myints+3)：" << endl;
		coutList(otherList);

	}

	if (0) {//list::insert()
		if (0) {
			intList.insert(intList.begin(), 99);
			cout << "intList.insert(intList.begin(), 99)：" << endl;
			coutList(intList);

			//换一种方法：虽然不能用list::begin()+2之类的方法，
			//但可以用++,--的操作符
			list<int>::iterator it = ++intList.begin();
			intList.insert(it, 88);
			cout << "intList.insert(it, 99)：" << endl;
			coutList(intList);

			//还可以用遍历的方法寻找插入的位置
			for (list<int>::iterator iter = intList.begin();iter != intList.end();iter++) {
				if (*iter == 8) {
					intList.insert(iter, 100);
				}
			}
			cout << "遍历方法寻找插入位置，值为8的插入100：" << endl;
			coutList(intList);
		}
		if (0) {
			otherList.insert(otherList.begin(), intList.rbegin(), intList.rend());
			cout << "利用另一个list的迭代器来插入内容：" << endl;
			coutList(otherList);
			cout << "用自己的倒序内容插入：" << endl;
			otherList.insert(otherList.begin(), otherList.rbegin(), otherList.rend());
			coutList(otherList);

		}

		if (0) {
			intList.insert(intList.begin(), 2, 150);//又是一种方法
			coutList(intList);
		}
	}

	if (0) {//添加或者修改（开始或结尾的）一个元素。
		//list::push_front() push_back() front() back()
		intList.push_front(33);
		intList.push_back(44);
		coutList(intList);
		intList.front() = 55;
		intList.back() = 67;
		coutList(intList);
		//list::pop_front();list::pop_back()删除一个元素
		intList.pop_front();
		intList.pop_back();
		coutList(intList);
	}


	if (0) {
		otherList.clear();//删除全部元素。
		coutList(otherList);

		otherList.assign(intList.rbegin(),intList.rend());
		coutList(otherList);
		//根据值删除
		otherList.remove(8);
		coutList(otherList);
		//根据条件删除！很神奇！
		cout << "remove_if:" << endl;
		otherList.remove_if(boolByRemoveIf<int>);//boolByRemoveIf见函数定义
		coutList(otherList);
		//改变容器大小可能会删除某些元素。
		otherList.resize(otherList.size() - 2);
		coutList(otherList);
		//list::reverse()颠倒顺序。
		otherList.assign(intList.rbegin(), intList.rend());
		coutList(otherList);
		otherList.reverse();
		coutList(otherList);
		//list:;emplace(),emplace_front(),emplace_back()

		otherList.emplace(otherList.begin(), 10);
		otherList.emplace_front(73);
		otherList.emplace_back(19);
		coutList(otherList);

		//注意std::pair结构的定义。
		if (0) {
			std::list< std::pair<int, char> > mylist;
			//由下面的参数个数可以得知：emplace()中值的参数个数可以不定。
			mylist.emplace(mylist.begin(), 100, 'x');
			mylist.emplace(mylist.begin(), 200, 'y');

			std::cout << "mylist contains:";
			for (auto& x : mylist)
				std::cout << " (" << x.first << "," << x.second << ")";

			std::cout << '\n';
		}

	}

	//下面的例子很妙！！！
	//erase()删除指定位置或指定区间内的元素。
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
		//之间的意思是[)前一个算，后一个不算。
		mylist.erase(it1, it2);     // 10 30 60 80 90
									//        ^

		std::cout << "mylist contains:";
		for (it1 = mylist.begin(); it1 != mylist.end(); ++it1)
			std::cout << ' ' << *it1;
		std::cout << '\n';
	}

	if (0) {
		//总结：list::merge()使用前必须排序。当需要自定义排序条件时，注意数据排序与自定义条件之间要一致。
		//即要升序都升序，要降序，都降序。降序使用merge(,greater<>())。
		std::list<double> first, second;

		first.push_back(3.1);
		first.push_back(2.2);
		first.push_back(2.9);

		second.push_back(3.7);
		second.push_back(7.1);
		second.push_back(1.4);
		//merge()之前必须排序
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
		//list::splice 拼接两个表或部分内容。
	/*	这两种要把括号里的list清空

		void splice(const_iterator position, list& x);
		void splice(const_iterator position, list&& x);


		后面都不清空，只把指定插入的内容移走。
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
		//指针移动方法（迭代器）
		++it;                         // points to 2
		//要把其中一个表清空的方法
		mylist1.splice(it, mylist2); // mylist1: 1 10 20 30 2 3 4
									  // mylist2 (empty)
									  // "it" still points to 2 (the 5th element)
		//不清空的方法
		mylist2.splice(mylist2.begin(), mylist1, it);
		// mylist1: 1 10 20 30 3 4
		// mylist2: 2
		// "it" is now invalid.
		it = mylist1.begin();
		//指针移动的另一高效方法，不是list的成员，记住它！！！！！
		std::advance(it, 3);           // "it" points now to 30
		//后面的范围都是[ )这种。
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
		//void swap(list& x);两个容器内容彼此交换。
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
		//保持数据的唯一性。使用前要先排序。
		//第一种没有参数的，保留相同值中的第一个。
		//第二种根据条件保留第一个。
		//条件分两种：函数与类。函数只需名字出现；类要实现一个operator()操作符，并在语句中出现括号。
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

	if (0) {//练习，学习上面。void unique()

		list<int> intList = { 99,2,47,99,26,51,2,46 };
		//--------------不排序使用是什么样呢----------------------------
		intList.unique();//不排序就使用没效果，除非相邻有相等的值。
		//coutList(intList);
		intList.push_front(99);
		//coutList(intList);//99被删除一个。证明：unique()只当数据已经排序，只比较相邻元素之间的值大小，
		intList.unique();//若相等，就删除后面的，保留第一个。
		//coutList(intList);
		//--------------不排序使用是什么样呢----------------------------

		//--------------若排序使用是什么样呢----------------------------
		intList.sort();
		//coutList(intList);
		intList.unique();
		//coutList(intList);
		//相等值只保留了一个。效果达到。
		//--------------若排序使用是什么样呢----------------------------



		//--------------根据条件排序使用是什么样呢----------------------------
		intList.unique(maxof);//只保留大的值，最后的结果是只剩一个最小的。哈哈！！！！
		cout << "----" << endl;
		coutList(intList);

		//取整后相加单数的，只保留一个
		intList = { 12,13,17,26,31,33,38,49 };
		coutList(intList);
		intList.unique(oddnumber);
		coutList(intList);//哈哈，符合预期，成功！

		//--------------根据条件排序使用是什么样呢----------------------------


	}


	//3.排序list::sort()
	//(1)void sort();默认排序
	//(2)template <class Compare>
	//	void sort(Compare comp);//根据自设条件排序
	if (0) {
		std::list<std::string> mylist;
		std::list<std::string>::iterator it;
		mylist.push_back("one");
		mylist.push_back("two");
		mylist.push_back("Three");
		mylist.push_back("Thread");//添加了两个元素
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


	//4.list.get_allocator()   分配器
	if (0) {//http://www.cplusplus.com/reference/memory/allocator/?kw=allocator(有关allocator类）

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
	//迭代器
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

/*-----------------------------函数------------------------------------------------------------------
*/

//建立一个模板函数，用于输出vector容器内的所有元素
//vector存储元素的内存地址是连续的，因而可以用下面
//[]操作符存储元素，也可以用begin()+2之类的……
template<typename TVector>
void coutVector(vector<TVector>& myvector) {

	for (int i = 0;i < myvector.size();i++) {
		cout << myvector[i] << " ";
	}
	cout << endl;
}


//建立一个模板函数，用于输出list容器内的所有元素

template<typename TList>
void coutList(list<TList>& myList) {
	//特别注意：带有模板的类定义一个对象时，在前面一定要加一个typename,否则，编译器不知道它
	//是一个自定义的类。如后才是正确的：typename list<TList>::iterator it。
	for (typename list<TList>::iterator it = myList.begin();it != myList.end();it++) {
		//由于list存储元素的内存地址并不连续，所以不能使用[]或者begin()+2之类的……
		cout << *it << " ";
	}
	cout << endl;
}


//list::remove_if相关的函数
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


//list::unique()相关的函数

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

//list::sort()相关函数

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