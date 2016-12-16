/*
 * Interface.h
 *
 *  Created on: 16.12.2016
 *      Author: Gerd
 */

#ifndef INTERFACE_H_
#define INTERFACE_H_

struct Interface{
	virtual void TemplateMethod() = 0;
	virtual void printThis() = 0;
};



#endif /* INTERFACE_H_ */
