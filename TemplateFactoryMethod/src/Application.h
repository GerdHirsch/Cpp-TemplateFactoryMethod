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
};

class App2{

};

class Application
		:
		public Implementation<Application, MyDocument>
//		, public Implementation2<Application, MyDocument>

{
	using base_type = Implementation<Application, MyDocument>;
//	using base_type2 = Implementation2<Application, MyDocument>;
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
		std::cout << "Application::TemplateHookMethod()" << std::endl;
		HookMethod2();
		base_type::HookMethod2();
		Method();
		base_type::HookMethod3();
	}

	void AbstractHookMethod(){
		std::cout << "Application::AbstractHookMethod()" << std::endl;
	}

	void Method(){
		std::cout << "Application::Method()" << std::endl;
	}
	using base_type::HookMethod2;
	void HookMethod2(){
		std::cout << "Application::HookMethod2()" << std::endl;
	}
	void HookMethod4(){
		std::cout << "Application::HookMethod4()" << std::endl;
	}
	void HookMethod4_2(){
		std::cout << "Application::HookMethod4_2()" << std::endl;
	}
	void NonHookMethod(){
		std::cout << "Application::NonHookMethod()" << std::endl;
	}

};
#endif /* APPLICATION_H_ */
