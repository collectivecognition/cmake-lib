#include <iostream>
#include "Foo.h"
using namespace std;

Foo::Foo(string value):value(value){}

void Foo::test(){
	cout << "Value = " << this->value << endl;
}

