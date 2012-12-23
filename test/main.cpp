/*
 * main.cpp
 *
 *  Created on: 2012-12-20
 *      Author: litao07
 */


#include "gtest/gtest.h"
#include "gmock/gmock.h"

int main(int argc, char** argv) {
	::testing::GTEST_FLAG(output) = "xml:\\reports\\gtest_reports.xml";
	::testing::InitGoogleMock(&argc, argv);
	return RUN_ALL_TESTS();
}

