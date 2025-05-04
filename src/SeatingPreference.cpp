#pragma once

#include "SeatingPreference.h"

SeatingPreference::SeatingPreference(int& yOffset)
	: GustOneSelect(yOffset, "Seating Preference", std::vector<std::string>{ "General Admission", "Front Row", "VIP Section", "Aisle Seat" }, 0)
{
}