/*
 * ApplicationImplementation.h
 *
 *  Created on: 24.05.2016
 *      Author: Gerd
 */

#ifndef IMPLEMENTATION_H_
#define IMPLEMENTATION_H_

#include "Interface.h"

#include <type_traits>
#include <iostream>

template<class ConcreteApplication, class Document>
class Implementation : public Interface {
	using this_type = ConcreteApplication;

// is_base_of<..> not possible cause of incomplete type ConreteApplication
//	static_assert(is_base_of<this_type, Implementation>::value, "ConcreteApplication must inherit from Implementation<ConcreteApplication>");
//	static_assert
//	(
//			std::is_base_of
//							<	Implementation<ConcreteApplication, Document>,
//								ConcreteApplication
//							>::value, "message"
//	);

	int i;
public:
	Implementation(){
		std::cout << "Implementation::Implementation() " << __PRETTY_FUNCTION__ << std::endl;
		This()->StaticHookMethod1();
		This()->StaticHookMethod2();
	}
	void TemplateMethod(){
//		if(std::is_base_of
//				<	Implementation<ConcreteApplication, Document>,
//					ConcreteApplication
//				>::value)
//			std::cout << "Implementation<ConcreteApplication, Document> is_base_of ConcreteApplication: true" << std::endl;

		std::cout << "Implementation::TemplateMethod() " << __PRETTY_FUNCTION__ << std::endl;
		std::cout << "---------------------------------" << std::endl;
		// With this-> the scope of the call context is Implementation<..>
		// and therefore the name NonHookMethod is not searched in the derived class
		this->NonHookMethod();

		// there not even a declaration in this class
		// for this method
		// a call via This()-> is similar to a call to a virtual function
		// in case of AbstractHookMethod(), to a pure virtual one
		// but virtual is replaced by name shadowing
		// and there are different rules for static polymorphism
		This()->AbstractHookMethod();

		// not redefined in Application
		This()->HookMethod1();

		//two overloads must made visible via using .. in derived class
		This()->HookMethod2(42);

		// is redefined in Application
		This()->HookMethod4();

		// not redefined in Application
		This()->StaticHookMethod1();
		// is redefined in Application
		This()->StaticHookMethod2();
		// is redefined in Application, but not static
		This()->StaticHookMethod3();
		// is redefined in Application, but static
		This()->NonStaticHookMethod();

		std::cout << "---------------------------------" << std::endl;
		Document d = This()->FactoryMethod();
		d.operation1();

		std::cout << "---------------------------------" << std::endl;
		This()->TemplateHookMethod();
		std::cout << "---------------------------------" << std::endl;
	}
protected:
	void printThis(){
		std::cout << "Implementation This():" << This() << " this: " << this << std::endl;
	}
	this_type* This(){
		static_assert
		(
			std::is_base_of // muss hier angewendet werden, weil der typ Implementation<..> erst hier vollständig ist
				<	Implementation<ConcreteApplication, Document>,
					ConcreteApplication
				>::value, "ConcreteApplication must inherit from Implementation<ConcreteApplication>!"
		);
		return static_cast<this_type*>(this);
	}

	void HookMethod1(){
		std::cout << "Implementation::HookMethod1 " << __PRETTY_FUNCTION__ << std::endl;
	}
	void TemplateHookMethod(){
		std::cout << "Implementation::TemplateHookMethod " << __PRETTY_FUNCTION__ << std::endl;

		This()->HookMethod2();
		This()->HookMethod4(43);
	}
	void HookMethod2(){
		std::cout << "Implementation::HookMethod2 " << __PRETTY_FUNCTION__ << std::endl;
	}
	void HookMethod2(int){
		std::cout << "Implementation::HookMethod2(int) " << __PRETTY_FUNCTION__ << std::endl;
	}
	void HookMethod3(){
		std::cout << "Implementation::HookMethod3 " << __PRETTY_FUNCTION__ << std::endl;
	}
	void HookMethod4(){
		std::cout << "Implementation::HookMethod4 " << __PRETTY_FUNCTION__ << std::endl;
	}
	void HookMethod4(int){
		std::cout << "Implementation::HookMethod4(int) " << __PRETTY_FUNCTION__ << std::endl;
	}
	static void StaticHookMethod1(){
		std::cout << "Implementation::StaticHookMethod1 " << __PRETTY_FUNCTION__ << std::endl;
	}
	static void StaticHookMethod2(){
		std::cout << "Implementation::StaticHookMethod2 " << __PRETTY_FUNCTION__ << std::endl;
	}
	static void StaticHookMethod3(){
		std::cout << "Implementation::StaticHookMethod3 " << __PRETTY_FUNCTION__ << std::endl;
	}
	void NonStaticHookMethod(){
		std::cout << "Implementation::NonStaticHookMethod " << __PRETTY_FUNCTION__ << std::endl;
	}

	void NonHookMethod(){ // must be called using this-> not This()->
		std::cout << "Implementation::NonHookMethod " << __PRETTY_FUNCTION__ << std::endl;
	}
};

#endif /* IMPLEMENTATION_H_ */
