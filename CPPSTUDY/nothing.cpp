#include "stdafx.h"
#include <iostream>
#include <stdlib.h>

#include <functional>
#include <random>

#include <string>
#include <sstream>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
#include <array>
#include <map>
#include <set>
#include <unordered_map>
#include <cmath>

using namespace std;

class Temp {

public:

	Temp() {

		cout << "Create Temp" << endl;

	}

	~Temp() {

		cout << "Destroy Temp" << endl;

	}

};



class Base {

private:

	Temp t;

public:

	Base() {

		cout << "Create Base" << endl;

	}

	~Base() {

		cout << "Destroy Base" << endl;

	}

	virtual void show() const {

		cout << "show Base" << endl;

	}

};



class Derived : public Base {

public:

	Derived() {



	}

	void show() const {
		cout << "show Derived" << endl;

	}

};



void test(Base obj) {

	obj.show();

}



int main(void) {

	Derived myDerived;

	cout << "before call func" << endl;

	test(myDerived);

	cout << "after call func" << endl;

	return 0;

}
