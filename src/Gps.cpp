#pragma once
#include "Gps.h"

Gps::Gps(int& yOffset)
	:YesOrNo(yOffset, "GPS needed?")
{
}
//=========================================
bool Gps::crossFieldTest(const CarType& carType) const
{
	if(isYes())
	return carType.crossFieldTest(*this);
	else
		return true;
}
