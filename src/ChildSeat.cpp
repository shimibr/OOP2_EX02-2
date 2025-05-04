#include "ChildSeat.h"

ChildSeat::ChildSeat(int& yOffset)
	: YesOrNo(yOffset, "Child Seat needed?")
{
}

bool ChildSeat::crossFieldTest(const CarType& carType) const
{
		if (isYes())
			return carType.crossFieldTest(*this);
		else
			return true;
}
