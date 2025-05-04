#pragma once

#include "GustOneSelect.h"

class SeatingPreference : public GustOneSelect
{
public:
	SeatingPreference(int& yOffset);
	bool crossFieldTest(const Wheelchair& wheelchair) const;

private:

};