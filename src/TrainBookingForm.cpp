#include "TrainBookingForm.h"
#include "DialogueManager.h"
#include <iostream>
#include <ctime>  // For getting current date
#include <RectanglText.h>
#include <FieldToInputSelect.h>

TrainBookingForm::TrainBookingForm(sf::RenderWindow& win, DialogueManager* manager)
    : BookingForm(win, manager)
{
    m_inputFields.push_back(std::make_unique<FieldToInput>(m_yOffset += 50, "Departure Station:"));
    m_inputFields.push_back(std::make_unique<FieldToInput>(m_yOffset += 50, "Arrival Station:"));
    m_inputFields.push_back(std::make_unique<FieldToInput>(m_yOffset += 50, "Departure Date:"));
    m_inputFields.push_back(std::make_unique<FieldToInput>(m_yOffset += 50, "Number of Passengers:"));
    m_inputFields.push_back(std::make_unique<FieldToInputSelect>(m_yOffset += 50, "Preferred Time:", std::vector<std::string>{"Morning", "Noon", "Evening", "Night", "Don't Care"}, 0));
    m_inputFields.push_back(std::make_unique<FieldToInputSelect>(m_yOffset += 50, "Special Requests:", std::vector<std::string>{"Quiet Zone", "Family Section", "First Class", "None"}, 0));
    setbuttons();
}

std::string TrainBookingForm::getFormType() const {
    return "Train Booking";
}


