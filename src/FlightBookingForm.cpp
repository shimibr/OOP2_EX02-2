#include "FlightBookingForm.h"
#include "DialogueManager.h"
#include <iostream>
#include <ctime>  // For getting current date
#include <FieldToInputSelect.h>

FlightBookingForm::FlightBookingForm(sf::RenderWindow& win, DialogueManager* manager)
    : BookingForm(win,manager) 
{
	m_inputFields.push_back(std::make_unique<FieldToInput>(m_yOffset += 50, "Departure Airport:"));
	m_inputFields.push_back(std::make_unique<FieldToInput>(m_yOffset += 50, "Arrival Airport:"));
	m_inputFields.push_back(std::make_unique<FieldToInput>(m_yOffset += 50, "Departure Date:"));
	m_inputFields.push_back(std::make_unique<FieldToInputSelect>(m_yOffset += 50, "Preferred Time:", std::vector<std::string>{"Morning", "Noon", "Evening", "Night", "Don't Care"}, 0));
    setbuttons();
}

std::string FlightBookingForm::getFormType() const {
    return "Flight Booking";
}


