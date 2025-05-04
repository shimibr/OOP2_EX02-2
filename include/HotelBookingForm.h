#ifndef HOTELBOOKINGFORM_H
#define HOTELBOOKINGFORM_H

#include "BookingForm.h"
class HotelBookingForm : public BookingForm {
public:
    HotelBookingForm(sf::RenderWindow& win, DialogueManager* manager);
    std::string getFormType() const override;
private:
    
};

#endif // HOTELBOOKINGFORM_H
