// CarRentalForm.h - Handles Car Rental Bookings
#ifndef CARRENTALFORM_H
#define CARRENTALFORM_H

#include "BookingForm.h"
#include <array>
class CarRentalForm : public BookingForm {
public:
    CarRentalForm(sf::RenderWindow& win, DialogueManager* manager);    
    std::string getFormType() const override;
private:
};

#endif // CARRENTALFORM_H
