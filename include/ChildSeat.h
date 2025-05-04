#pragma once
#include "YesOrNo.h"
#include "CarType.h"

class  ChildSeat : public YesOrNo
{
public:
	ChildSeat(int& yOffset);
	bool crossFieldTest(const CarType& carType) const override;
private:

};