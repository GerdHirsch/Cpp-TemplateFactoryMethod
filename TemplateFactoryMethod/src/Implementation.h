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
	void TemplateMethod(){
		if(std::is_base_of
				<	Implementation<ConcreteApplication, Document>,
					ConcreteApplication
				>::value)
			std::cout << "Implementation<ConcreteApplication, Document> is_base_of ConcreteApplication: true" << std::endl;

			static_assert
			(
				std::is_base_of
					<	Implementation<ConcreteApplication, Document>,
						ConcreteApplication
					>::value, "message"
			);



		std::cout << "Implementation::TemplateMethod()" << std::endl;
		std::cout << "---------------------------------" << std::endl;
		this->NonHookMethod();
		This()->AbstractHookMethod();
		This()->HookMethod1();
		This()->HookMethod2(42);
		This()->HookMethod4();
		This()->StaticHookMethod1();
		This()->StaticHookMethod2();

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
	static void StaticHookMethod1(){
		std::cout << "Implementation::StaticHookMethod1()" << std::endl;
	}
	static void StaticHookMethod2(){
		std::cout << "Implementation::StaticHookMethod2()" << std::endl;
	}
	void NonHookMethod(){
		std::cout << "Implementation::NonHookMethod()" << std::endl;
	}
};

#endif /* IMPLEMENTATION_H_ */
