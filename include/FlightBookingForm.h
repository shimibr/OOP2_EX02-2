#ifndef FLIGHTBOOKINGFORM_H
#define FLIGHTBOOKINGFORM_H

#include "BookingForm.h"
#include <SFML/Graphics.hpp>

class FlightBookingForm : public BookingForm {

public:
    FlightBookingForm(sf::RenderWindow& win, DialogueManager* manager);  // ✅ Updated constructor
    std::string getFormType() const override;
};

#endif // FLIGHTBOOKINGFORM_H
