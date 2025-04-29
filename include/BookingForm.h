#ifndef BOOKINGFORM_H
#define BOOKINGFORM_H

#include "FieldToInput.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <array>
#include <RecPress.h>
class DialogueManager;

class BookingForm {
protected:

    void setbuttons();
	std::vector<std::unique_ptr<FieldToInput>> m_inputFields;
    int m_yOffset = 0;

public:
    BookingForm(sf::RenderWindow& win, DialogueManager* manager);
    virtual ~BookingForm() = default;

    void handleInput(sf::Event event);
    void render(sf::RenderWindow& window);

    virtual std::string getFormType() const = 0;
private:
    void openConfirmationWindow();
	void checkAllFieldsFilled();

    sf::RenderWindow& window;
    DialogueManager* formManager;
	std::vector<RecPress> m_buttons;
	bool m_allFieldsFilled = false;
    std::size_t m_activeField = 0;
};

#endif // BOOKINGFORM_H


//void FlightBookingForm::setDefaultValues() {
//    time_t now = time(0);
//    tm ltm;
//    localtime_s(&ltm, &now);  // ✅ Safe alternative to localtime()
//
//    userInput[6] = std::to_string(1900 + ltm.tm_year) + "-" +
//        std::to_string(1 + ltm.tm_mon) + "-" +
//        std::to_string(ltm.tm_mday);
//
//    userInput[7] = "Don't Care";  // ✅ Default time selection
//}