/*
Gerd
*/

#include "Implementation.h"
#include "Application.h"

#include<iostream>
using namespace std;

template<class T>
size_t getAdressOf(T& t){ return reinterpret_cast<size_t>(&t);}

using Impl1 = Implementation<Application, MyDocument>;
using Impl2 = Implementation2<Application, MyDocument>;

int main(){
	cout << "=== TemplateFactoryMethod ===" << endl;

	Application application;
	Interface &app = application;
	app.printThis();

	cout << "=== app.TemplateMethod() ===" << endl;
	app.TemplateMethod();
//	cout << "=== app.TemplateMethod_2() ===" << endl;
//	app.TemplateMethod_2();

	cout << hex;
	cout 	<< "&app: " << &app
			<< " Impl1: " << getAdressOf<Impl1>(application)
//			<< " Impl2: " << getAdressOf<Impl2>(app)
			<< endl;
}
