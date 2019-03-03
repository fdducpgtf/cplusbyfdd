#include<iostream>

#include<algorithm>

#include<numeric>

#include<list>

#include<vector>

#include<time.h>

#include <functional> 

#include <memory>

#include<string>



using namespace std;



#define TWENTY



class Person {

public:

	Person(string myname, int myage) :name(myname), age(myage) {



	}

	void coutPerson() {

		cout << "name:" << name << ";" << "age:" << age << endl;

	}

private:

	string name;

	int age;



};





class Animal

{

public:

#if 1        //��ʹΪ0��û��Ĭ�Ϲ���Ҳ�ǿ��ԣ�

	Animal() : num(0)

	{

		cout << "Animal constructor default" << endl;

	}

#endif

	Animal(int _num) : num(_num)

	{

		cout << "Animal constructor param" << endl;

	}



	~Animal()

	{

		cout << "Animal destructor" << endl;

	}



	void show()

	{

		cout << this->num << endl;

	}



private:

	int num;

};









struct IsOdd_class {

	bool operator() (const int& x) const { return x % 2 == 1; }

	typedef int argument_type;

} IsOdd_object;









struct relatedClassOfFunction {



#ifdef ONE

	void operator() (int i) { std::cout << i << ' '; }

#endif // ONE



} relatedObjectOfFunction;

//------------------------------------------------------------------------------------------------



//ifFunctiontOfTwoParameters------------------------��غ���------------------------------------------------------

bool ifFunctiontOfTwoParameters(int, int);

//--------------------------------------------------------------------------------------------------------



//ifFunctiontOfOneParameter------------------------��غ���------------------------------------------------------

bool ifFunctiontOfOneParameter(int);

//--------------------------------------------------------------------------------------------------------



// function generator :

int RandomNumber() { return (std::rand() % 100); }



// class generator:

struct c_unique {

	int current;

	c_unique() { current = 0; }

	int operator()() { return ++current; }

} UniqueNumber;





void coutDBinary(double dval) {

	static int flag = 0;

	if (!flag) {

		cout << "0.";

		flag = 1;

	}



	double dtmp = dval * 2;

	cout << int(dtmp);

	dtmp = dtmp - int(dtmp);

	if (dtmp > 0) {

		coutDBinary(dtmp);

	}



}







int cplusSTLCaseMain() {







	//for_each----STL�⺯��------------------------------------------------------------

		//���õ�������ʵ����������ڲ�Ԫ�صı�����

		//ʵ�ַ�ʽ�����֣�һ���Ǻ�������������ΪԪ��ʵ�����ͣ��� 

		//�ڶ��֣�����һ���ࣨһ��Ϊstruct�ࣩ��������ʵ��һ����operator()���ĳ�Ա������

		//�����Ҳ��Ԫ��ʵ�����͡�

		//�����ԭ���ǣ�for_eachģ�庯���ӵ��������Ԫ�ط�Χ��������ÿ��Ԫ�أ��Զ���ÿ��Ԫ�ص�

		//���ô��ݸ�֮ǰ����ģ����������Ա������

	//



#ifdef ONE 

/*function template   <algorithm>

std::for_each

template <class InputIterator, class Function>

Function for_each(InputIterator first, InputIterator last, Function fn);



	Apply function to range

		Applies function fn to each of the elements in the range[first, last).



*/







	std::list<int> mylist;

	mylist.push_back(10);

	mylist.push_back(20);

	mylist.push_back(30);

	//��һ�֣����ú���ʵ��Ԫ�ر���

	std::cout << "1-mylist contains:";

	for_each(mylist.begin(), mylist.end(), ifFunctiontOfOneParameter);

	std::cout << endl;



	// �ڶ��֣�������ĳ�Ա������ʵ����ġ�()���������ĺ���ʵ�֡�

	std::cout << "2-mylist contains:";

	for_each(mylist.begin(), mylist.end(), relatedObjectOfFunction);

	std::cout << endl;



	//�ܽ᣺����ʵ���Ե���Щ��������ģ��������ڴ�����ظ�ʹ�ã���ֲ��ǿ��



#endif // ONE







//find����-----------------STL�⺯��-------------------------------------------------------------

	//find()��Ȼ���õ��������в��ң������ҵ��ĵ�һ����Ӧ�ĵ����������򣬷���end()��������

	//�Ƿ��ҵ����ȶԷ��صĵ�������end()���������бȽϾ�֪���ˡ�

#ifdef TWO

	/*function template   <algorithm>

	std::find

	template <class InputIterator, class T>

	InputIterator find(InputIterator first, InputIterator last, const T& val);

	Find value in range

		Returns an iterator to the first element in the range[first, last) that compares equal to val.

		If no such element is found, the function returns last.

*/









	list<int> intList = { 12,23,4,5,93,49,8,2 };

	list<int>::iterator iter, tmp;

	int searchVal = 49;

	iter = find(intList.begin(), intList.end(), searchVal);

	if (iter == intList.end()) {

		cout << "ֵΪ��" << searchVal << " ��Ԫ��û���ҵ���" << endl;

		return 0;

	}



	int i = 1;

	for (tmp = intList.begin();tmp != intList.end();tmp++, i++) {

		if (tmp == iter)

			break;

	}

	cout << searchVal << "--->�ڵ�" << i << "��Ԫ�ص�λ���ҵ���(�ܹ�" << intList.size() << "������" << endl;



	//find����-----------------STL�⺯��-------------------------------------------------------------











#endif // TWO











//find_if------------------------STL�⺯��------------------------------------------------------

//std::find_if_not 

#ifdef THREE

/*function template <algorithm>

std::find_if

template <class InputIterator, class UnaryPredicate>

   InputIterator find_if (InputIterator first, InputIterator last, UnaryPredicate pred);

Find element in range

Returns an iterator to the first element in the range [first,last) for which pred returns true.

If no such element is found, the function returns last.



*/





/*function template <algorithm>

std::find_if_not

template <class InputIterator, class UnaryPredicate>

   InputIterator find_if_not (InputIterator first, InputIterator last, UnaryPredicate pred);

Find element in range (negative condition)

Returns an iterator to the first element in the range [first,last) for which pred returns false.

If no such element is found, the function returns last.



*/

	list<int> intList = { 21,23,0,4,41,7100,19,51 };

	list<int>::iterator iter;

	//firstDigitOfNumbe�����ǵ�һλ���֣����λ����1���ͷ���true��

	iter = find_if(intList.begin(), intList.end(), ifFunctiontOfOneParameter);

	if (iter != intList.end()) {//û���ҵ���find_if�ͷ���end()���������Դ˿���Ϊ�ҵ��������ݡ�

		cout << "��һ������Ҫ������ҵ���ֵ�ǣ�" << *iter << endl;

	}

	else {

		cout << "û��һ������Ҫ���Ԫ�ر��ҵ���" << endl;

	}









	//find_if------------------------STL�⺯��------------------------------------------------------





#endif // THREE









//find_end---------------------------STL�⺯��---------------------------------------------------------

//std::search(���������ĵ�һ������find_end���Ƿ������������һ����

//����ǲ���һ�����У�����һ��Ԫ�ء�����Ȼ���԰ѷ�Χ���һ��Ԫ�أ�



#ifdef FOUR

/*function template <algorithm>

std::find_end

equality (1)	template <class ForwardIterator1, class ForwardIterator2>

				ForwardIterator1 find_end (ForwardIterator1 first1, ForwardIterator1 last1,

							  ForwardIterator2 first2, ForwardIterator2 last2);

predicate (2)	template <class ForwardIterator1, class ForwardIterator2, class BinaryPredicate>

				ForwardIterator1 find_end (ForwardIterator1 first1, ForwardIterator1 last1,

							  ForwardIterator2 first2, ForwardIterator2 last2,

							  BinaryPredicate pred);

Find last subsequence in range

Searches the range [first1,last1) for the last occurrence of the sequence defined by [first2,last2),

and returns an iterator to its first element, or last1 if no occurrences are found.



The elements in both ranges are compared sequentially using operator== (or pred, in version (2)):

A subsequence of [first1,last1) is considered a match only when this is true

for all the elements of [first2,last2).



This function returns the last of such occurrences.

For an algorithm that returns the first instead, see search.

*/





/*std::search

equality (1)	template <class ForwardIterator1, class ForwardIterator2>

				ForwardIterator1 search (ForwardIterator1 first1, ForwardIterator1 last1,

							ForwardIterator2 first2, ForwardIterator2 last2);

predicate (2)	template <class ForwardIterator1, class ForwardIterator2, class BinaryPredicate>

				ForwardIterator1 search (ForwardIterator1 first1, ForwardIterator1 last1,

							ForwardIterator2 first2, ForwardIterator2 last2,

							BinaryPredicate pred);

Search range for subsequence

Searches the range [first1,last1) for the first occurrence of the sequence

defined by [first2,last2), and returns an iterator to its first element,

or last1 if no occurrences are found.



The elements in both ranges are compared sequentially

using operator== (or pred, in version (2)):

A subsequence of [first1,last1) is considered

a match only when this is true for all the elements of [first2,last2).



This function returns the first of such occurrences.

For an algorithm that returns the last instead, see find_end.

*/



	list<int> searchedList = { 1,2,3,4,5,6,7,8,9,10,11,22,33,4,5,6,7,8,9,100,111,121,151 };

	list<int> targetList = { 5,6,7,8 };

	list<int>::iterator iter;





	//�������ַ������һ������ͬ���ǣ�������������ı�������������Ͳ�һ���ˡ�

	iter = find_end(searchedList.begin(), searchedList.end(), targetList.begin(), targetList.end());

	//iter = find_end(searchedList.begin(), searchedList.end(), targetList.begin(), targetList.end(),ifFunctiontOfTwoParameters);

	//�������ַ���





	if (iter != searchedList.end()) {

		for (;iter != searchedList.end();iter++) {

			cout << *iter << " ";

		}//�����5,6,7,8,9,100,111,121,151��ȷʵ�����һ��λ�á�

		cout << endl;

	}

	else {

		cout << "û���ҵ���" << endl;

	}





	//find_end---------------------------STL�⺯��---------------------------------------------------------



#endif // FOUR



//find_first_of---------------STL�⺯��---------------------------------------------------------------



#ifdef FIVE

/*function template <algorithm>

std::find_first_of

C++11

equality (1)		template <class InputIterator, class ForwardIterator>

					InputIterator find_first_of (InputIterator first1, InputIterator last1,

								   ForwardIterator first2, ForwardIterator last2);

predicate (2)		template <class InputIterator, class ForwardIterator, class BinaryPredicate>

					InputIterator find_first_of (InputIterator first1, InputIterator last1,

								   ForwardIterator first2, ForwardIterator last2,

								   BinaryPredicate pred);

Find element from set in range

Returns an iterator to the first element in the range [first1,last1)

that matches any of the elements in [first2,last2).

If no such element is found, the function returns last1.



The elements in [first1,last1) are sequentially compared to each of the values

in [first2,last2) using operator== (or pred, in version (2)), until a pair matches.

*/



	list<int> searchedList = { 1,2,3,14,55,6,7,8,9,10,11,22,33,4,5,6,7,8,9,100,111,121,151 };

	list<int> targetList = { 5,151,7,10,999 };

	list<int>::iterator iter;

	//iter = find_first_of(searchedList.begin(), searchedList.end(), targetList.begin(), targetList.end());

	iter = find_first_of(searchedList.begin(), searchedList.end(), targetList.begin(), targetList.end(), ifFunctiontOfTwoParameters);



	if (iter != searchedList.end()) {

		for (;iter != searchedList.end();iter++) {

			cout << *iter << " ";

		}

		cout << endl;

	}

	else {

		cout << "û���ҵ���" << endl;

	}

























	//find_first_of------------------------------------------------------------------------------







#endif // FIVE







//std::search_n---------------STL�⺯��-------------------------------------------------------



#ifdef SIX

/*std::search_n

equality (1)	template <class ForwardIterator, class Size, class T>

				ForwardIterator search_n (ForwardIterator first, ForwardIterator last,

							 Size count, const T& val);

predicate (2)	template <class ForwardIterator, class Size, class T, class BinaryPredicate>

				ForwardIterator search_n ( ForwardIterator first, ForwardIterator last,

							  Size count, const T& val, BinaryPredicate pred );

Search range for elements

Searches the range [first,last) for a sequence of count elements,

each comparing equal to val (or for which pred returns true).



The function returns an iterator to the first of such elements,

or last if no such sequence is found.

*/



//std::search_n-----------------------------------------------------------------------





#endif // SIX



//std::adjacent_find----------STL�⺯��-----------------------------------------------------------



#ifdef SEVEN

/*std::adjacent_find

equality (1)

template <class ForwardIterator>

   ForwardIterator adjacent_find (ForwardIterator first, ForwardIterator last);

predicate (2)

template <class ForwardIterator, class BinaryPredicate>

   ForwardIterator adjacent_find (ForwardIterator first, ForwardIterator last,

								  BinaryPredicate pred);

Find equal adjacent elements in range

Searches the range [first,last) for the first occurrence of two consecutive elements that match, and returns an iterator to the first of these two elements, or last if no such pair is found.



Two elements match if they compare equal using operator== (or using pred, in version (2)).

*/





	list<int> intList = { 10,20,31,41,40,30,40,80,80,80,90,90,81,91 };

	list<int>::iterator iter, tmpiter;

	iter = intList.begin();

	while (1) {

		//��һ�����������Զ����������ҷ��������ĵ�һ��ֵ����ȻҲ�����Զ������ȡ�

		iter = adjacent_find(iter, intList.end(), ifFunctiontOfTwoParameters);

		//iter = adjacent_find(intList.begin(), intList.end());//Ĭ����������ȣ����ҵ�һ���ظ�ֵ



		if (iter != intList.end())

			tmpiter = iter++;

		else

			break;



		for (;tmpiter != intList.end();tmpiter++) {

			cout << *tmpiter << " ";

		}

		cout << endl;



	}













	//std::adjacent_find---------------------------------------------------------------------







#endif // SEVEN







//std::count----------------------------------------------------------------------------------------------------

//std::count_if



#ifdef EIGHT

	/*std::count

template <class InputIterator, class T>

typename iterator_traits<InputIterator>::difference_type

	count (InputIterator first, InputIterator last, const T& val);



Count appearances of value in range

Returns the number of elements in the range [first,last) that compare equal to val.



The function uses operator== to compare the individual elements to val.

	*/



	/*std::count_if

template <class InputIterator, class UnaryPredicate>

  typename iterator_traits<InputIterator>::difference_type

	count_if (InputIterator first, InputIterator last, UnaryPredicate pred);



Return number of elements in range satisfying condition

Returns the number of elements in the range [first,last) for which pred is true.

	*/



	list<int> intList = { 10,20,31,41,522,20,41,41,10,99,86 };

	//��һ�ַ�����Ĭ�������Ϊ����������

	int targetInt = 41;

	int n = count(intList.begin(), intList.end(), targetInt);

	cout << targetInt << "�ڱ��г����ˣ�-->" << n << "�Ρ�" << endl;

	//�ڶ��ַ������Զ�������������

	n = count_if(intList.begin(), intList.end(), ifFunctiontOfOneParameter);

	cout << "�����������ڱ��г����ˣ�-->" << n << "�Ρ�" << endl;









	//std::count----------------------------------------------------------------------------------------------------



#endif // EIGHT



//std::equal---------------------------------------------------------------------------------------------------

//std::equal_range

#ifdef NINE

	/*std::equal

equality (1)

template <class InputIterator1, class InputIterator2>

  bool equal (InputIterator1 first1, InputIterator1 last1,

			  InputIterator2 first2);

predicate (2)

template <class InputIterator1, class InputIterator2, class BinaryPredicate>

  bool equal (InputIterator1 first1, InputIterator1 last1,

			  InputIterator2 first2, BinaryPredicate pred);

Test whether the elements in two ranges are equal

Compares the elements in the range [first1,last1) with those in the range beginning at first2, and returns true if all of the elements in both ranges match.



The elements are compared using operator== (or pred, in version (2)).

	*/









	/*std::equal_range

default (1)

template <class ForwardIterator, class T>

  pair<ForwardIterator,ForwardIterator>

	equal_range (ForwardIterator first, ForwardIterator last, const T& val);

custom (2)

template <class ForwardIterator, class T, class Compare>

  pair<ForwardIterator,ForwardIterator>

	equal_range (ForwardIterator first, ForwardIterator last, const T& val,

				  Compare comp);

Get subrange of equal elements

Returns the bounds of the subrange that includes all the elements

of the range [first,last) with values equivalent to val.



The elements are compared using operator< for the first version,

and comp for the second. Two elements, a and b are considered

equivalent if (!(a<b) && !(b<a)) or if (!comp(a,b) && !comp(b,a)).



The elements in the range shall already be sorted according to

this same criterion (operator< or comp), or at least partitioned with respect to val.



If val is not equivalent to any value in the range, the subrange returned

has a length of zero, with both iterators pointing to

the nearest value greater than val, if any, or to last,

if val compares greater than all the elements in the range.



	*/



	//#define NINE_1

#ifdef NINE_1

	if (0) {



		int myints[] = { 20,40,60,80,100 };               //   myints: 20 40 60 80 100

		std::vector<int>myvector(myints, myints + 5);     // myvector: 20 40 60 80 100



		// using default comparison:

		if (std::equal(myvector.begin(), myvector.end(), myints))

			std::cout << "The contents of both sequences are equal.\n";

		else

			std::cout << "The contents of both sequences differ.\n";



		myvector[3] = 81;                                 // myvector: 20 40 60 81 100



		// using predicate comparison:

		if (std::equal(myvector.begin(), myvector.end(), myints, ifFunctiontOfTwoParameters))

			std::cout << "The contents of both sequences are equal.\n";

		else

			std::cout << "The contents of both sequences differ.\n";



	}

#endif // NINE_1















	//#define NINE_2

#ifdef NINE_2

//��Ҫ���Ƚ��õĺ����Ի��ˣ���ʵ�ȽϺ�����������ģ�

//����ǧ��Ҫ��Ϊ�����Խ��û��Ӱ�죬��ʵ������Ӱ��ġ�

//��Ϊ������Ӱ����ȵĺ��塣���������ɵ�������Ĭ����ȫһ�£���Ϊû��ʹ��ȵĺ��巢���仯����

//���ͶԽ��û�С���֮���Խ����Ӱ�졣

//�������һ��eqval_rangeʹ��ǰ������ʹ���������������������10��ȡ�����ٱȽϴ�С����󰴽������С�

//����������20,22��������ȵģ�����ȡ��ĸ����Ѿ��˸ı䡣���Խ����20��ȵ����У����б�20���20��һ�����

//Ҳ����Ϊ��ȵġ����صı߽統Ȼ�Ǹ����֡���ȡ���ͬ����Ľ���ˡ�����!����㶮�˱ȽϺ����������ˡ�





//equal_range����ʼ����Ѱ����ָ����ֵ��ȵ����䣺[ ��

//���û����ȵģ��ֱ�����Ԫ�ش���С���֡�

//��Ԫ�ض����������У��������һ��Ԫ�أ�����end())��λ�ã�

//�ڽ��򣬷���0,0�� 

//��Ԫ�ض�С���������У�����0,0���ڽ����У��������һ��Ԫ�أ�����end())��λ�á�



	if (1) {



		int myints[] = { 10,20,30,20,33,20,22,14,20 };

		std::vector<int> v(myints, myints + 8);                         // 10 20 30 30 20 10 10 20

		std::pair<std::vector<int>::iterator, std::vector<int>::iterator> bounds;



		// using default comparison:

		std::sort(v.begin(), v.end());									// 10 10 10 20 20 20 30 30

		bounds = std::equal_range(v.begin(), v.end(), 20);				//          ^        ^

		for (unsigned int i = 0;i < v.size();i++) {

			cout << v[i] << " ";

		}

		cout << endl;

		std::cout << "bounds at positions " << (bounds.first - v.begin());

		std::cout << " and " << (bounds.second - v.begin()) << '\n';





		// using "ifFunctiontOfTwoParameters" as comp:

		std::sort(v.begin(), v.end(), ifFunctiontOfTwoParameters);							// 30 30 20 20 20 10 10 10

		bounds = std::equal_range(v.begin(), v.end(), 20, ifFunctiontOfTwoParameters);		//       ^        ^

		for (unsigned int i = 0;i < v.size();i++) {

			cout << v[i] << " ";

		}

		cout << endl;

		std::cout << "bounds at positions " << (bounds.first - v.begin());

		std::cout << " and " << (bounds.second - v.begin()) << '\n';

	}

#endif // NINE_2











#endif // NINE



	//std::all_of-----------------------------------------------------------------------------------------------

	//std::any_of



#ifdef TEN

/*std::all_of

template <class InputIterator, class UnaryPredicate>

  bool all_of (InputIterator first, InputIterator last, UnaryPredicate pred);

Test condition on all elements in range

Returns true if pred returns true for all the elements in the range [first,last) or if the range is empty, and false otherwise.



*/





/*std::any_of

template <class InputIterator, class UnaryPredicate>

  bool any_of (InputIterator first, InputIterator last, UnaryPredicate pred);

Test if any element in range fulfills condition

Returns true if pred returns true for any of the elements in the range [first,last), and false otherwise.



If [first,last) is an empty range, the function returns false.

*/



	list<int> intList = { 1,31,39,73,27,95 };

	if (all_of(intList.begin(), intList.end(), ifFunctiontOfOneParameter)) {

		cout << "��������Ԫ�ض��Ƿ��������ģ�" << endl;

	}

	else {

		cout << "����������һ��Ԫ���ǲ����������ģ�" << endl;

	}



	if (any_of(intList.begin(), intList.end(), ifFunctiontOfOneParameter)) {

		cout << "����������һ��Ԫ���Ƿ��������ģ�" << endl;

	}

	else {

		cout << "���е�Ԫ�ض��ǲ����������ģ�" << endl;

	}



















#endif // TEN





	//std::binary_search----------------------------------------------------------------------------------------





#ifdef	ELEVEN

	/*std::binary_search

		default (1)

		template <class ForwardIterator, class T>

	bool binary_search(ForwardIterator first, ForwardIterator last,

		const T& val);

	custom(2)

		template <class ForwardIterator, class T, class Compare>

	bool binary_search(ForwardIterator first, ForwardIterator last,

		const T& val, Compare comp);

*/







	int myints[] = { 1,2,3,4,5,4,3,2,1 };

	std::vector<int> v(myints, myints + 9);                         // 1 2 3 4 5 4 3 2 1



	// using default comparison:

	std::sort(v.begin(), v.end());



	std::cout << "looking for a 3... ";

	if (std::binary_search(v.begin(), v.end(), 3))

		std::cout << "found!\n"; else std::cout << "not found.\n";



	// using myfunction as comp:

	std::sort(v.begin(), v.end(), ifFunctiontOfTwoParameters);



	std::cout << "looking for a 6... ";

	if (std::binary_search(v.begin(), v.end(), 6, ifFunctiontOfTwoParameters))

		std::cout << "found!\n"; else std::cout << "not found.\n";



#endif // ELEVEN





	//std::copy --------------------------------------------------------------------------------------------------

	//std::copy_backward

	//std::copy_if

	//std::copy_n

#ifdef TWELVE

	/*std::copy

		template <class InputIterator, class OutputIterator>

	OutputIterator copy(InputIterator first, InputIterator last, OutputIterator result);

	std::copy_backward

		template <class BidirectionalIterator1, class BidirectionalIterator2>

	BidirectionalIterator2 copy_backward(BidirectionalIterator1 first,

		BidirectionalIterator1 last,

		BidirectionalIterator2 result);

	std::copy_if

		template <class InputIterator, class OutputIterator, class UnaryPredicate>

	OutputIterator copy_if(InputIterator first, InputIterator last,

		OutputIterator result, UnaryPredicate pred);

	std::copy_n

		template <class InputIterator, class Size, class OutputIterator>

	OutputIterator copy_n(InputIterator first, Size n, OutputIterator result);

	*/





	if (0) {//�Ӻ��濪ʼ���ƣ�ֱ���ܸ�������Ԫ�ء�

		std::vector<int> myvector;



		// set some values:

		for (int i = 1; i <= 5; i++)

			myvector.push_back(i * 10);          // myvector: 10 20 30 40 50



		myvector.resize(myvector.size() + 3);  // allocate space for 3 more elements



		std::copy_backward(myvector.begin(), myvector.begin() + 5, myvector.end());



		std::cout << "myvector contains:";

		for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)

			std::cout << ' ' << *it;

		std::cout << '\n';



	}



	if (0) {

		list<int> intList = { 1,2,3,4,5,6,7,8,9,0 };

		list<int> otherList = { 0,1,2,9,8,7 };



		list<int>::iterator iter = copy_if(intList.begin(),

			intList.end(),

			++otherList.begin(),

			ifFunctiontOfOneParameter);

		cout << *iter << endl;//���صĵ�����ָ����Ԫ�������һ��Ԫ�ص���һ��λ�á�

		iter = otherList.begin();

		for (;iter != otherList.end();iter++) {

			cout << *iter << " ";

		}

		cout << endl;



	}

#endif // TWELVE



	//std::fill---------------------------------------------------------------------------------------

	//std::fill_n





#ifdef THIRTEEN

	/*std::fill

		template <class ForwardIterator, class T>

	void fill(ForwardIterator first, ForwardIterator last, const T& val);



	std::fill_n

		template <class OutputIterator, class Size, class T>

	OutputIterator fill_n(OutputIterator first, Size n, const T& val);

	*/



	if (0) {

		std::vector<int> myvector(8);                       // myvector: 0 0 0 0 0 0 0 0



		std::fill(myvector.begin(), myvector.begin() + 4, 5);   // myvector: 5 5 5 5 0 0 0 0

		std::fill(myvector.begin() + 3, myvector.end() - 2, 8);   // myvector: 5 5 5 8 8 8 0 0



		std::cout << "myvector contains:";

		for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)

			std::cout << ' ' << *it;

		std::cout << '\n';



	}



	if (0) {

		std::vector<int> myvector(8, 10);        // myvector: 10 10 10 10 10 10 10 10



		std::fill_n(myvector.begin(), 4, 20);     // myvector: 20 20 20 20 10 10 10 10

		std::fill_n(myvector.begin() + 3, 3, 33);   // myvector: 20 20 20 33 33 33 10 10



		std::cout << "myvector contains:";

		for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)

			std::cout << ' ' << *it;

		std::cout << '\n';

	}



#endif // THIRTEEN



	//std::generate-------------------------------------------------------------------------------------------------

	//std::generate_n



#ifdef FOURTEEN

/*std::generate

		template <class ForwardIterator, class Generator>

	void generate(ForwardIterator first, ForwardIterator last, Generator gen);

	Generate values for range with function

		Assigns the value returned by successive calls to gen to the elements in the range[first, last).

*/



/*	std::generate_n



		template <class OutputIterator, class Size, class Generator>

	OutputIterator generate_n(OutputIterator first, Size n, Generator gen);



	Generate values for sequence with function

		Assigns the value returned by successive calls to gen to the first n elements of the sequence pointed by first.



*/

//��ָ���ĺ����Զ�����ָ����Χ��generate())��ָ������(generate_n())��Ԫ�ء�

	if (1) {

		std::srand(unsigned(time(0)));



		std::vector<int> myvector(8);



		std::generate(myvector.begin(), myvector.end(), RandomNumber);



		std::cout << "myvector contains:";

		for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)

			std::cout << ' ' << *it;

		std::cout << '\n';



		std::generate(myvector.begin(), myvector.end(), UniqueNumber);



		std::cout << "myvector contains:";

		for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)

			std::cout << ' ' << *it;

		std::cout << '\n';



	}

	if (1) {

		int myarray[9];



		std::generate_n(myarray, 9, UniqueNumber);



		std::cout << "myarray contains:";

		for (int i = 0; i < 9; ++i)

			std::cout << ' ' << myarray[i];

		std::cout << '\n';



	}











#endif // FOURTEEN



	//std::includes----------------------------------------------------------------------





#ifdef FIFTEEN

/*	std::includes

		template <class InputIterator1, class InputIterator2>

	bool includes(InputIterator1 first1, InputIterator1 last1,

		InputIterator2 first2, InputIterator2 last2);



	template <class InputIterator1, class InputIterator2, class Compare>

	bool includes(InputIterator1 first1, InputIterator1 last1,

		InputIterator2 first2, InputIterator2 last2, Compare comp);

	Test whether sorted range includes another sorted range

		Returns true if the sorted range[first1, last1) contains all the elements in the sorted range[first2, last2).



		The elements are compared using operator< for the first version, and comp for the second.Two elements, a and b are considered equivalent if (!(a < b) && !(b < a)) or if (!comp(a, b) && !comp(b, a)).



		The elements in the range shall already be ordered according to this same criterion(operator< or comp).

*/



	int container[] = { 5,10,15,20,25,30,35,40,45,50 };

	int continent[] = { 40,30,20,10 };



	std::sort(container, container + 10);

	std::sort(continent, continent + 4);



	// using default comparison:

	if (std::includes(container, container + 10, continent, continent + 4))

		std::cout << "container includes continent!\n";



	// using myfunction as comp:

	std::sort(container, container + 10, ifFunctiontOfTwoParameters);

	std::sort(continent, continent + 4, ifFunctiontOfTwoParameters);



	if (std::includes(container, container + 10, continent, continent + 4, ifFunctiontOfTwoParameters))

		std::cout << "container includes continent!\n";









#endif // FIFTEEN



	//std::inplace_merge-------------------------------------------------------------------------------------



#ifdef SIXTEEN

/*

	std::inplace_merge

		default (1)

		template <class BidirectionalIterator>

	void inplace_merge(BidirectionalIterator first, BidirectionalIterator middle,

		BidirectionalIterator last);

	custom(2)

		template <class BidirectionalIterator, class Compare>

	void inplace_merge(BidirectionalIterator first, BidirectionalIterator middle,

		BidirectionalIterator last, Compare comp);

	Merge consecutive sorted ranges

		Merges two consecutive sorted ranges : [first, middle) and [middle, last),

		putting the result into the combined sorted range[first, last).



		The elements are compared using operator< for the first version,

		and comp for the second.The elements in both ranges shall already

		be ordered according to this same criterion(operator< or comp).

		The resulting range is also sorted according to this.



		The function preserves the relative order of elements with equivalent values,

		with the elements in the first range preceding those equivalent in the second.



*/



//��֮Ϊ���鲢���򡱣���ͬһ�����ڷֳ����Σ�ÿ�����������������򣬼�inplace_merge().

	int first[] = { 5,10,15,20,25 };

	int second[] = { 50,40,30,20,10 };

	std::vector<int> v(10);

	std::vector<int>::iterator it;



	std::sort(first, first + 5);

	std::sort(second, second + 5);



	it = std::copy(first, first + 5, v.begin());

	std::copy(second, second + 5, it);



	std::inplace_merge(v.begin(), v.begin() + 5, v.end());



	std::cout << "The resulting vector contains:";

	for (it = v.begin(); it != v.end(); ++it)

		std::cout << ' ' << *it;

	std::cout << '\n';



	//����һ��

	vector<int> vint = { 1,2,5,8,77,89,4,7,9,93,100,200 };

	//���������ڣ��������Ѿ�����ͬһ��˳���ź��򣬵���������

	//��������inplace_merge()����



	std::inplace_merge(vint.begin(), vint.begin() + 6, vint.end());

	for (int i = 0;i < vint.size();i++) {

		cout << vint[i] << " ";

	}

	cout << endl;

	//�����ȫ��ȷ��ע��ֶε��м�ֵ��λ�á�





#endif // SIXTEEN



#ifdef SEVENTEEN

/*	std::sort

		default (1)

		template <class RandomAccessIterator>

	void sort(RandomAccessIterator first, RandomAccessIterator last);

	custom(2)

		template <class RandomAccessIterator, class Compare>

	void sort(RandomAccessIterator first, RandomAccessIterator last, Compare comp);

	Sort elements in range

		Sorts the elements in the range[first, last) into ascending order.



		The elements are compared using operator< for the first version, and comp for the second.



		Equivalent elements are not guaranteed to keep their original relative order(see stable_sort).



*/





















#endif // SEVENTEEN





//��������

//std::sort()

//std::make_heap();std::pop_heap();std::push_heap()��



#ifdef EIGHTEEN

	//make_heapĬ�ϴ�ѣ�make_heap(,,greater<int>())С�ѡ�Ҳ����ʹ���Լ��ĺ���

	//���Լ��ĺ���ʱ����<���Ǵ�ѣ���>����С�ѡ�������������˼��һ������Ϊ��֪������庬�塣

	int myints[] = { 10,20,30,5,15,99,2,34,28,11 };

	std::vector<int> v(myints, myints + 10);

	std::vector<int> v2 = v;//�ñ�����ʵ�֣���Ϊ������Ҫɾ��Ԫ��ֱ���ա�Ŀ�Ĳ��ı�ԭ��

	//������ǰ��

	std::make_heap(v2.begin(), v2.end());//Ĭ�ϴ��

	//����ֱ����std:sort()����

	//std::sort(v.begin(),v.end());

	//��Ȼ���ֱ�ӳ�������Ч�ʿ��ܲ�һ�������������ֻ�������ֵ���߲������ֵ��sort��ȫ������







	//std::make_heap(v2.begin(), v2.end(),ifFunctiontOfTwoParameters);//С�ѣ��������øı�

	std::cout << "initial max heap   : " << v.front() << '\n';

	int size = v2.size();//pop_back����ɾ��Ԫ�أ����Դ�С�����ڸı䡣

	for (int i = 0;i < size;i++) {

		cout << v2.front() << " ";

		pop_heap(v2.begin(), v2.end());//�����ֵ�˳��ѡ�Ĭ�ϴ��

		//pop_heap(v2.begin(), v2.end(), ifFunctiontOfTwoParameters);//С�ѣ��������øı�

		//push_heap()���ڲ�����Ԫ��ʱ������Ԫ�ؼ���ѡ�Ȼ��������Ӧ�ı仯��



		v2.pop_back();

	}

	cout << endl;

	cout << v.size() << "-" << v2.size() << endl;



#endif // EIGHTEEN





	//std::partial_sort

	//std:partial_sort_copy;



	//std:partition���ࣨtrue,false)���� http://www.cplusplus.com/reference/algorithm/partition/

	//std:partition_copy���ิ�� http://www.cplusplus.com/reference/algorithm/partition_copy/

#ifdef NINETEEN



/*	std::partial_sort http://www.cplusplus.com/reference/algorithm/partial_sort/

		default (1)//��������

		template <class RandomAccessIterator>

	void partial_sort(RandomAccessIterator first, RandomAccessIterator middle,

		RandomAccessIterator last);

	custom(2)

		template <class RandomAccessIterator, class Compare>

	void partial_sort(RandomAccessIterator first, RandomAccessIterator middle,

		RandomAccessIterator last, Compare comp);

	Partially sort elements in range

		Rearranges the elements in the range[first, last), in such a way that the elements before middle are the smallest elements in the entire range and are sorted in ascending order, while the remaining elements are left without any specific order.



		The elements are compared using operator< for the first version, and comp for the second.



		http://www.cplusplus.com/reference/algorithm/partial_sort_copy/

		std::partial_sort_copy//�Բ���Ԫ�����򲢸���

default (1)

template <class InputIterator, class RandomAccessIterator>

  RandomAccessIterator

	partial_sort_copy (InputIterator first,InputIterator last,

					   RandomAccessIterator result_first,

					   RandomAccessIterator result_last);

custom (2)

template <class InputIterator, class RandomAccessIterator, class Compare>

  RandomAccessIterator

	partial_sort_copy (InputIterator first,InputIterator last,

					   RandomAccessIterator result_first,

					   RandomAccessIterator result_last, Compare comp);

Copy and partially sort range

Copies the smallest elements in the range [first,last) to [result_first,result_last), sorting the elements copied. The number of elements copied is the same as the distance between result_first and result_last (unless this is more than the amount of elements in [first,last)).



The range [first,last) is not modified.



The elements are compared using operator< for the first version, and comp for the second.

*/





	int myints[] = { 9,8,7,6,5,4,3,2,1 };

	std::vector<int> myvector(5);



	// using default comparison (operator <):

	std::partial_sort_copy(myints, myints + 9, myvector.begin(), myvector.end(), ifFunctiontOfTwoParameters);



	// using function as comp

	//std::partial_sort_copy(myints, myints + 9, myvector.begin(), myvector.end(), ifFunctiontOfTwoParameters);



	// print out content:

	std::cout << "myvector contains:";

	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)

		std::cout << ' ' << *it;

	std::cout << '\n';







#endif // NINETEEN



#ifdef TWENTY



	double d = 0.75;

	coutDBinary(d);

	cout << endl;





#endif // TWENTY





	//69

	return 0;

}











//*************************************************************************************************************



//ifFunctiontOfOneParameter------------------------��غ���------------------------------------------------------

bool ifFunctiontOfOneParameter(int i) {



#ifdef ONE

	std::cout << i << ' ';

	return true;

#endif // ONE



#ifdef THREE

	int tmp = i;

	for (;tmp >= 10;tmp /= 10);

	return tmp == 1 ? true : false;



#endif // THREE



#ifdef EIGHT

	return i % 2;

#endif // EIGHT





#ifdef TEN

	return i % 2;

#endif // TEN



#ifdef TWELVE



	return i > 5;



#endif // TWELVE





	return true;

}







//-----------------------------------------------------------------------------------------------------------------







//ifFunctiontOfTwoParameters------------------------��غ���------------------------------------------------------

bool ifFunctiontOfTwoParameters(int i, int j) {

#ifdef FOUR

	return (i == j);



#endif // FOUR



#ifdef FIVE

	return (i == j);//Ҳ�����ж�������������i=2*j�ȵȡ�



#endif // FIVE



#ifdef SEVEN

	return (i == j);

#endif // SEVEN



#ifdef NINE_1

	return (i == j);

#endif // NINE_1





#ifdef NINE_2

	int m = i / 10;

	int n = j / 10;



	bool bl = m > n;

	return bl;

#endif // NINE_2



#ifdef ELEVEN

	return i > j;

#endif // ELEVEN



#ifdef FIFTEEN

	return i > j;

#endif // FIFTEEN



#ifdef SEVENTEEN

	return i < j;

#endif // SEVENTEEN



#ifdef EIGHTEEN

	return i > j;

#endif // EIGHTEEN



#ifdef NINETEEN

	return i > j;

#endif // NINETEEN

	return true;

}



//-----------------------------------------------------------------------------------------------------------



//*************************************************************************************************************