/*
 * ApplicationImplementation.h
 *
 *  Created on: 24.05.2016
 *      Author: Gerd
 */

#ifndef IMPLEMENTATION_H_
#define IMPLEMENTATION_H_

#include <iostream>

template<class ConcreteApplication, class Document>
class Implementation{
	using this_type = ConcreteApplication;
	int i;
public:
	void TemplateMethod(){
		std::cout << "Implementation::TemplateMethod()" << std::endl;
		this->NonHookMethod();
		This()->AbstractHookMethod();
		This()->HookMethod1();
		This()->HookMethod2(42);
		This()->HookMethod4();

		Document d = This()->FactoryMethod();
		This()->TemplateHookMethod();
	}
protected:
	void printThis(){
		std::cout << "Implementation This():" << This() << " this: " << this << std::endl;
	}
	this_type* This(){
		return static_cast<this_type*>(this);
	}
	void HookMethod1(){
		std::cout << "Implementation::HookMethod1()" << std::endl;
	}
	void TemplateHookMethod(){
		std::cout << "Implementation::TemplateHookMethod()" << std::endl;

		This()->HookMethod2();
		This()->HookMethod4(43);
	}
	void HookMethod2(){
		std::cout << "Implementation::HookMethod2()" << std::endl;
	}
	void HookMethod2(int){
		std::cout << "Implementation::HookMethod2(int)" << std::endl;
	}
	void HookMethod3(){
		std::cout << "Implementation::HookMethod3()" << std::endl;
	}
	void HookMethod4(){
		std::cout << "Implementation::HookMethod4()" << std::endl;
	}
	void HookMethod4(int){
		std::cout << "Implementation::HookMethod4(int)" << std::endl;
	}
	void NonHookMethod(){
		std::cout << "Implementation::NonHookMethod()" << std::endl;
	}
};

#endif /* IMPLEMENTATION_H_ */
