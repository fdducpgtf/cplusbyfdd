#include <iostream>
using namespace std;

//Class grandFather
template<typename _AGE, typename _NAME>
class grandFather {
public:
	grandFather(_AGE _age, _NAME _name) : myAge(_age[2]), myName(_name[2]) {

		cout << "爷爷的名字：" << myName << ";年龄：" << myAge << endl;

	}

private:
	int myAge;
	const char * myName;
};

//Class father

template<typename _AGE, typename _NAME>
class father : public grandFather<_AGE, _NAME> {
public:
	father(_AGE _age, _NAME _name) : myAge(_age[1]), myName(_name[1]), grandFather<_AGE, _NAME>(_age, _name) {

		cout << "父亲的名字：" << myName << ";年龄：" << myAge << endl;

	}
private:
	int myAge;
	const char * myName;
};

//Class son

template<typename _AGE, typename _NAME>
class son : public father<_AGE, _NAME> {
public:
	son(_AGE _age, _NAME _name) : myAge(_age[0]), myName(_name[0]), father<_AGE, _NAME>(_age, _name) {

		cout << "儿子的名字：" << myName << ";年龄：" << myAge << endl;
	}
private:
	int myAge;
	const char * myName;
};



int templateClassCaseMain() {
	int size = 3;
	const char ** _name = new const char *[size];
	int *_age = new int[size];
	for (int i = 0;i < size;i++) {
		switch (i) {
		case 0:
			_name[i] = "son";
			_age[i] = (i + 1) * 20;
			break;
		case 1:
			_name[i] = "father";
			_age[i] = (i + 1) * 20;
			break;
		case 2:
			_name[i] = "grandFather";
			_age[i] = (i + 1) * 20;
			break;
		default:
			break;
		}
	}


	son<int *, const char **> mySon(_age, _name);

	delete[] _name;
	delete[] _age;

	return 0;
}