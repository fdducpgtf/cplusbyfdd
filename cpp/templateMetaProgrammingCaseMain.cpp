#include <iostream>
#include<typeinfo>

using namespace std;


//#define ISPRIME
#ifdef ISPRIME
//�ο����£�http://www.cnblogs.com/devymex/p/3326793.html

typedef unsigned int uint;

template<uint n, uint m>
struct isDivisible {
	static const uint r = (n%m == 0 ? 0 : n);
};


template<uint n, uint m>
struct isLessThanOrEqualToSquare {
	static const uint r = m * m <= n ? (m + 1) : 0;
};

template<uint n, uint m>
struct recursiveCheck {
	static const uint r = recursiveCheck<
		isDivisible<n, m>::r,
		isLessThanOrEqualToSquare<n, m>::r
	>::r;

};

template<uint n>
struct recursiveCheck<n, 0> {
	static const uint r = 1;

};

template<uint m>
struct recursiveCheck<0, m> {
	static const uint r = 0;
};

template<uint n>
struct isPrime {
	static const uint r = recursiveCheck<n, 2>::r;
};

template<>
struct isPrime<1> {
	static const uint r = 2;
};

template<>
struct isPrime<2> {
	static const uint r = 1;
};
#endif // ISPRIME

//#define SUM
#ifdef SUM
//��һ���㷨��
template<unsigned int n>
struct sum {
	static const unsigned int value = sum<n - 1>::value+n;
};

template<>
struct sum<0> {
	static const unsigned int value = 0;
};

//�ڶ����㷨����һ�����Ƶݹ����ơ�
template<unsigned int start,unsigned int end>
struct piecewiseSummation {
	static const unsigned int middle = (start + end) / 2;
	static const unsigned int  value = 
		piecewiseSummation<start, middle>::value +
		piecewiseSummation<middle + 1, end>::value;
};

template<unsigned int end>
struct piecewiseSummation<end, end> {
	static const unsigned int value = end;
};

//����ʱ���
//int sum(int max) {
//	if (max > 0) {
//		int temp = max;
//		return temp + sum(--max);
//	}
//	else {
//		return max;
//	}
//
//}



#endif // SUM

//#define BINARYTODECIMAL
#ifdef BINARYTODECIMAL
using uint = unsigned int;
template<uint binary>
struct BinaryToDecimal {
	static const uint decimalValue = binary % 10 + 
		BinaryToDecimal<binary / 10>::decimalValue * 2;
};

template<>
struct BinaryToDecimal<0> {
	static const uint decimalValue = 0;
};



#endif // BINARYTODECIMAL


//#define RUNTIMECODE
#ifdef RUNTIMECODE


//��ͬ��ģ��Ԫ��̣�������תʮ��������ʱ�Ĵ��룺
unsigned binary(unsigned long N) {

	//bit��ʼֵΪ1�������Ʊ�ʾҲΪ1��
	//N%10,�õ������Ƶĸ�λ���֣����Ϊ1---->bitΪ 1-->ʮ���� 1;
	//N=N/10,N%10,�õ������Ƶĸ�λ���֣����Ϊ1---->bit<<=1Ϊ�� 10-->ʮ���� 2;
	//N=N/10,N%10,�õ������Ƶĸ�λ���֣����Ϊ1---->bit<<=1Ϊ�� 100-->ʮ���� 4;
	//N=N/10,N%10,�õ������Ƶĸ�λ���֣����Ϊ1---->bit<<=1Ϊ�� 1000-->ʮ���� 8;
	//����

	unsigned result = 0;
	for (unsigned bit = 1;N;N /= 10, bit <<= 1) {
		if (N % 10)
			result += bit;
	}
	return result;
}

#endif // !RUNTIMECODE


//#define		ADD_CONST_REFERENCE
#ifdef ADD_CONST_REFERENCE

template <bool b, typename T>
struct add_const_reference;

template <typename T>
struct add_const_ref
{
	using type = typename add_const_reference<std::is_reference<T>::value, T>::type;
};

template <typename T>
struct add_const_reference<false, T>
{
	using type = typename std::add_lvalue_reference<typename std::add_const<T>::type>::type;
};

template <typename T>
struct add_const_reference<true, T>
{
	using type = typename std::remove_reference<T>::type;
};

#endif // ADD_CONST_REFERENCE


//#define RETURNTYPEOFSUM
#ifdef RETURNTYPEOFSUM

//���sum(a+b)
template<typename T,bool>
struct ReturnType ;  

template<typename T>
struct ReturnType<T,false> {
	using type = int;
};

template<typename T>
struct ReturnType<T, true> {
	using type = T;
};


template<typename T>
typename ReturnType<T,!std::is_same<T,char>::value>::type  sum(T a, T b){
	using type= typename ReturnType<T, !std::is_same<T, char>::value>::type;
	type value = a + b;
	return value;
} 

#endif // RETURNTYPEOFSUM

#define MYSWAP
#ifdef MYSWAP
#include <string>

template<typename T>
struct typeDE;

template<>
struct typeDE<char>{
	string myname= "char";
	friend ostream &operator<<(ostream &output, typeDE<char> &d) {
		output << d.myname;
		return output;
	}
};

template<>
struct typeDE<int*> {
	string myname = "int*";
	friend ostream &operator<<(ostream &output, typeDE<int*> &d) {
		output << d.myname;
		return output;
	}
};

template<>
struct typeDE<long*> {
	string myname = "long*";
	friend ostream &operator<<(ostream &output, typeDE<long*> &d) {
		output << "long*";
		return output;
	}
};



#endif // MYSWAP



int templateMetaProgrammingCaseMain(){

	

	
	

#ifdef ADD_CONST_REFERENCE

	using a = int&;
	using b = int;

	std::cout << std::is_same<b, typename add_const_ref<a>::type>::value << std::endl;

	using c = int const&;

	std::cout << std::is_same<c, typename add_const_ref<b>::type>::value << std::endl;
	
	
#undef ADD_CONST_REFERENCE	
#endif ADD_CONST_REFERENCE



#ifdef ISPRIME
#undef ISPRIME

	int primes[] = {
			isPrime<1>::r, isPrime<2>::r, isPrime<3>::r, isPrime<4>::r,
			isPrime<5>::r, isPrime<6>::r, isPrime<7>::r, isPrime<8>::r,
			isPrime<9>::r, isPrime<10>::r, isPrime<11>::r, isPrime<12>::r,
			isPrime<13>::r, isPrime<14>::r, isPrime<15>::r, isPrime<16>::r,
	};
	for (int i = 0; i < sizeof(primes) / sizeof(primes[0]); ++i) {
		switch (primes[i])
		{
		case 0:
			cout << "���� " << i + 1 << "���Ǻ�����" << endl;
			break;
		case 1:
			cout << "���� " << i + 1 << "����������" << endl;
			break;
		case 2:
			cout << "���� " << i + 1 << "���Ȳ���������Ҳ���Ǻ�����" << endl;
			break;
		default:
			break;
		}
	}
		


#endif // ISPRIME
	 
#ifdef SUM
#undef SUM
//Ƕ�ײ�β�����500
	cout << "1+...+499�ĺ��ǣ�" << sum<499>::value<< endl;
//�����и����Ƕ�ײ��
	cout << "1+...+10000�ĺ��ǣ�" << piecewiseSummation<1, 10000>::value << endl;

#endif // SUM

#ifdef BINARYTODECIMAL

	cout << "11111111ʮ����ֵΪ�� " 
		<< BinaryToDecimal<11111111>::decimalValue 
		<< endl;//output: 255


#undef BINARYTODECIMAL
#endif // BINARYTODECIMAL


#ifdef RUNTIMECODE

	cout << binary(10110) << endl;

#undef RUNTIMECODE
#endif // !RUNTIMECODE

#ifdef RETURNTYPEOFSUM

	char a = 'z', b = 'y';
	float m = 8.9f, n = 9.7f;
	cout << sum<char>(a, b) << endl;
	cout << sum<float>(m, n) << endl;


#undef RETURNTYPEOFSUM
#endif RETURNTYPEOFSUM
	

#ifdef MYSWAP

	
	typeDE<int*> kk;
	cout << kk << endl;
	




	


	
	


	

#undef MYSWAP
#endif // MYSWAP







	return 0;
}