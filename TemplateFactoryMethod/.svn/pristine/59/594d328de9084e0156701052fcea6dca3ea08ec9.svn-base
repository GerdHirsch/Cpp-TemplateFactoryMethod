/*
 * ApplicationImplementation.h
 *
 *  Created on: 24.05.2016
 *      Author: Gerd
 */

#ifndef IMPLEMENTATION2_H_
#define IMPLEMENTATION2_H_

#include <iostream>

template<class ConcreteApplication, class Document>
class Implementation2{
	using this_type = ConcreteApplication;
	double d;
public:
	void TemplateMethod_2(){
		std::cout << "Implementation2::TemplateMethod_2()" << std::endl;
		this->NonHookMethod();
		This()->AbstractHookMethod();
		This()->HookMethod1_2();

		This()->HookMethod4_2();


//		Document d = This()->FactoryMethod();
//		This()->TemplateHookMethod();
	}
protected:
	void printThis(){
		std::cout << "Implementation2 This():" << This() << " this: " << this << std::endl;
	}
	this_type* This(){
		return static_cast<this_type*>(this);
	}
	void HookMethod1_2(){
		std::cout << "Implementation2::HookMethod1_2()" << std::endl;
	}
	void NonHookMethod(){
		std::cout << "Implementation2::NonHookMethod()" << std::endl;
	}
	void HookMethod4_2(){
		std::cout << "Implementation::HookMethod4_2()" << std::endl;
	}
};

#endif /* IMPLEMENTATION2_H_ */
