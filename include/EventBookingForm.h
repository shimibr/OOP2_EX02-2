#ifndef EVENTBOOKINGFORM_H
#define EVENTBOOKINGFORM_H
#pragma once

#include "BookingForm.h"

class EventBookingForm : public BookingForm {
public:
    EventBookingForm(sf::RenderWindow& win, DialogueManager* manager);
    std::string getFormType() const override;
};

#endif // EVENTBOOKINGFORM_H
