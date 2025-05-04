#pragma once
#include "GustOneSelect.h"

class CarType : public GustOneSelect
{
public:
	CarType(int& yOffset);
	bool crossFieldTest(const Gps& gps) const override;
	bool crossFieldTest(const ChildSeat& childSeat) const override;
private:
};