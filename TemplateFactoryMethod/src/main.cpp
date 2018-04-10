/*
Gerd
*/

#include "Implementation.h"
#include "Application.h"

#include<iostream>
using namespace std;

void demoAddress();
void demoBrokenInvariant();

int main(){
	cout << "=== TemplateFactoryMethod ===" << endl;

	Application application;
	Interface &app = application;
	cout << "=== app.TemplateMethod() ===" << endl;

	// simulates one virtual call from a framework
	// the rest could be inlined
	app.TemplateMethod();
}
//---------------------------------------------------------------------
using Impl1 = Implementation<Application, MyDocument>;
using Impl2 = Implementation2<Application, MyDocument>;

void demoAddress(){
	Application application;
	Interface &app = application;
	app.printThis();

	cout << hex;
	cout 	<< "&app: " << &app
			<< " Impl1: " << std::addressof<Impl1>(application)
//			<< " Impl2: " << std::addressof<Impl2>(app)
			<< endl;
}

//---------------------------------------------------------------------
struct BrokenInvariant{ //don´t inherit from Implementation<..>
	Implementation<BrokenInvariant, MyDocument> impl;
};
void demoBrokenInvariant(){
	//	BrokenInvariant bi;
	//	bi.impl.TemplateMethod();
}

