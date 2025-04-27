// CarRentalForm.h - Handles Car Rental Bookings
#ifndef CARRENTALFORM_H
#define CARRENTALFORM_H

#include "BookingForm.h"
#include <array>
class CarRentalForm : public BookingForm {
    std::string pickupLocation, dropOffLocation, carType;
public:
    CarRentalForm(sf::RenderWindow& win, DialogueManager* manager);    
    std::string getFormType() const override;
    void render(sf::RenderWindow& window) override;
private:
    void setDefaultValues();
};

#endif // CARRENTALFORM_H
