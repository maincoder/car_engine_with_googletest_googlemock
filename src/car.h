/*
 * car.h
 *
 *  Created on: 2012-12-20
 *      Author: litao07
 */

#ifndef CAR_H_
#define CAR_H_

#include "engine.h"

class Car
{
public:
	Car(Engine *engineIn)
	{
		engine = engineIn;
		engine->stop();
		engineStarted=false;
		gearOrder=-1;
	}

	void startEngine()
	{
		if (engineStarted)
		{
			return;
		}
		else
		{
			engineStarted=engine->start();
			engineStarted=true;
		}
	}

	void stopEngine()
	{
		if (!engineStarted)
		{
			return;
		}
		else
		{
			engine->stop();
			engineStarted=false;
		}
	}

	bool hasEngineStarted()
	{
		return engineStarted;
	}

	void switchGear(unsigned int gearOrderIn)
	{
		if (engineStarted)
		{
			gearOrder=engine->setGearOrder(gearOrderIn);
		}
		else
		{
			gearOrder = -1;
		}
	}

	unsigned int getGearOrder()
	{
		return gearOrder;
	}

	unsigned int getEngineSerialNumber()
	{
		unsigned int engineSerialNum;
		engine->serialNum(engineSerialNum);
		return engineSerialNum;
	}
private:
	Engine *engine;
	bool engineStarted;
	unsigned int gearOrder;
};

#endif /* CAR_H_ */
