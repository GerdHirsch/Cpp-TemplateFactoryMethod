/*
Gerd
*/

#include "Implementation.h"
#include "Application.h"

//#include<memory>
#include<iostream>
using namespace std;

using Impl1 = Implementation<Application, MyDocument>;
using Impl2 = Implementation2<Application, MyDocument>;

struct BrokenInvariant{ //don´t inherit from Implementation<..>
	Implementation<BrokenInvariant, MyDocument> impl;
};

int main(){
	cout << "=== TemplateFactoryMethod ===" << endl;

//	BrokenInvariant bi;
//	bi.impl.TemplateMethod();

	Application application;
	Interface &app = application;
//	app.printThis();

	cout << "=== app.TemplateMethod() ===" << endl;
	app.TemplateMethod();
//	cout << "=== app.TemplateMethod_2() ===" << endl;
//	app.TemplateMethod_2();

	cout << hex;
	cout 	<< "&app: " << &app
			<< " Impl1: " << addressof<Impl1>(application)
//			<< " Impl2: " << addressof<Impl2>(app)
			<< endl;
}
