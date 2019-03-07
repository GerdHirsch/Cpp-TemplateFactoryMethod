/*
 * Application.h
 *
 *  Created on: 24.05.2016
 *      Author: Gerd
 */

#ifndef APPLICATION_H_
#define APPLICATION_H_

#include <iostream>

#include "Implementation.h"
#include "Implementation2.h"

class MyDocument{
public:
	MyDocument(){
		std::cout << "MyDocument::MyDocument()" << std::endl;
	}
	void operation1(){
		std::cout << "MyDocument::operation1()" << std::endl;
	}
};

class Application
		: // Invariant: inherits from ...
		public Implementation<Application, MyDocument>
//		, public Implementation2<Application, MyDocument>

{
	// type to access base_type ;-)
	using base_type = Implementation<Application, MyDocument>;
//	using base_type2 = Implementation2<Application, MyDocument>;

	// Hookmethods are typically protected, (in case of dynamic polymorphism)
	// to be overriden or called from derived classes as needed.
	// but with CRTP it works the otherway around
	// hence to give access to protected elements
	// base_type must be declared as friend
	friend base_type;
//	friend base_type2;

public:
	void printThis(){
		base_type::printThis();
//		base_type2::printThis();
		std::cout << "Application this:" << this << std::endl;
	}
protected:
	MyDocument FactoryMethod(){
		return MyDocument();
	}
	void TemplateHookMethod(){
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		// not declared and not called in base class
		Method();

		// calls overriden method
		HookMethod2();
		// calls base_type method
		base_type::HookMethod2();

		// calls in both cases base_type method
		HookMethod3(); // not "overriden" shadowed
		base_type::HookMethod3();
	}

	// there is not even a declaration in the baseclass
	// for this method, but called via This()->AbstractHookMethod
	void AbstractHookMethod(){
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}

	// not declared and not called in base class
	void Method(){
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}

	// make the overloads from base visible
	// two overloads
	using base_type::HookMethod2;
	// "overrides" shadows name HookMethod2 all overloads
	void HookMethod2(){
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}

	// "overrides" shadows name HookMethod4
	// no overloads hence no using declaration is needed
	void HookMethod4(){
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
// static polymorphic Methods:
	static void StaticHookMethod2(){
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
	//static // in baseclass
	void StaticHookMethod3(){
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
	// Non static in baseclass
	static void NonStaticHookMethod(){
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}

	// a NonHookMethod should not be redefined in
	// derived classes, cause it yield different
	// behavior for the same message to the same object
	// and that�s strange
	// similar to non-virtual Methods redefined
	// in derived classes
	void NonHookMethod(){
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}

};
#endif /* APPLICATION_H_ */
