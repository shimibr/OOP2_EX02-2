#ifndef TRAINBOOKINGFORM_H
#define TRAINBOOKINGFORM_H

#include "BookingForm.h"
#include "RectangleToFill.h"

class TrainBookingForm : public BookingForm {
public:
    TrainBookingForm(sf::RenderWindow& win, DialogueManager* manager);
    std::string getFormType() const override;
};

#endif // TRAINBOOKINGFORM_H
