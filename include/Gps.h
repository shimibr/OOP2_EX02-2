#pragma once
#include "YesOrNo.h"
#include "CarType.h"

class Gps : public YesOrNo
{
public:
	Gps(int& yOffset);
	bool crossFieldTest(const CarType& carType) const override;
private:

};