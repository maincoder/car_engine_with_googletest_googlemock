/*
 * testcar.cpp
 *
 *  Created on: 2012-12-20
 *      Author: litao07
 */


#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../src/car.h"
#include "../src/engine.h"

using namespace testing;

const unsigned int GearMAX = 5;
const unsigned int SerialNum=8888;

class MockEngine : public Engine
{
public:
	MOCK_METHOD0(start,bool());
    MOCK_METHOD0(stop, bool());
    MOCK_METHOD0(hasStarted, bool());
    MOCK_CONST_METHOD1(setGearOrder, unsigned int(unsigned int gearOrderIn));
    MOCK_METHOD1(serialNum, void(unsigned int &serialNum));
};

class TestCar : public ::testing::Test
{
public:
	virtual void SetUp()
	{
		mockEngine = new MockEngine();
		ASSERT_TRUE(mockEngine!=NULL);
		car = new Car(mockEngine);
		ASSERT_TRUE(car!=NULL);

		EXPECT_CALL(*mockEngine, start())
			.Times(AnyNumber())
			.WillRepeatedly(Return(true));
		EXPECT_CALL(*mockEngine, stop())
			.Times(AnyNumber())
			.WillRepeatedly(Return(true));
	}
	virtual void TearDown()
	{
		delete mockEngine;
		mockEngine = NULL;
		delete car;
		car = NULL;
	}
public:
	Car *car;
	MockEngine *mockEngine;
};

TEST_F(TestCar, StartAndStopTheCar)
{
	car->startEngine();
	EXPECT_TRUE(car->hasEngineStarted());
	car->stopEngine();
	EXPECT_FALSE(car->hasEngineStarted());
}

TEST_F(TestCar, DriverSwitchTheGear)
{
	EXPECT_CALL(*mockEngine, setGearOrder(Le(GearMAX)))
			.Times(1)
			.WillRepeatedly(ReturnArg<0>());
	unsigned int presetGearOrder = 1;
	car->startEngine();
	car->switchGear(presetGearOrder);
	EXPECT_EQ(presetGearOrder, car->getGearOrder());
	car->stopEngine();
}


TEST_F(TestCar, ValidateEngineSerialNum)
{
	EXPECT_CALL(*mockEngine, serialNum(_))
		.Times(AtLeast(1))
		.WillOnce(SetArgReferee<0>(SerialNum));

	EXPECT_EQ(SerialNum, car->getEngineSerialNumber());
}
