#ifndef BOOKINGFORM_H
#define BOOKINGFORM_H

#include "FieldToInput.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <array>
#include <RecPress.h>
class DialogueManager;

struct PersonalInfo {
    std::string name;
    std::string id;
    std::string address;
    std::string email;
};

class BookingForm {
protected:

    void setbuttons();
	std::vector<std::unique_ptr<FieldToInput>> m_inputFields;

    std::vector<std::string> fieldLabels;
    std::vector<std::string> userInput;
    std::size_t activeField = 0;
    sf::Clock cursorTimer;
    bool showCursor = true;
    int m_yOffset = 0;

    sf::RenderWindow& window;
    DialogueManager* formManager;
    PersonalInfo personalInfo;

    virtual void setDefaultValues() ;
    void openConfirmationWindow();

public:
    BookingForm(sf::RenderWindow& win, DialogueManager* manager);
    virtual ~BookingForm() = default;
    virtual std::string getFormType() const = 0;
    virtual void render(sf::RenderWindow& window);
    virtual void handleInput(sf::Event event);
private:
	void checkAllFieldsFilled();
	std::vector<RecPress> m_buttons;
	bool m_allFieldsFilled = false;
};

#endif // BOOKINGFORM_H
