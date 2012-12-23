/*
 * engine.h
 *
 *  Created on: 2012-12-20
 *      Author: litao07
 */

#ifndef ENGINE_H_
#define ENGINE_H_

class Engine
{
public:
	virtual ~Engine(){}
	virtual bool start()=0;
	virtual bool stop()=0;
	virtual bool hasStarted()=0;
	virtual unsigned int setGearOrder(unsigned int gearOrderIn) const=0;
	virtual void serialNum(unsigned int &serialNum)=0;
};

#endif /* ENGINE_H_ */
