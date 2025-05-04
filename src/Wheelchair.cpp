#pragma once

#include "Wheelchair.h"

Wheelchair::Wheelchair(int& yOffset)
	: YesOrNo(yOffset, "Wheelchair Accessibility?")
{
}
//====================================
bool Wheelchair::crossFieldTest(const SeatingPreference& seatingPreference) const
{
	if (isYes())
		return seatingPreference.crossFieldTest(*this);
	else
		return true;
}
