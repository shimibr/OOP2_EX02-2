#pragma once
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
    virtual bool checkCrossField() { return true; }
    void openConfirmationWindow();
	void checkAllFieldsFilled();

    sf::RenderWindow& window;
    DialogueManager* formManager;
	std::vector<RecPress> m_buttons;
	bool m_allFieldsFilled = false;
    std::size_t m_activeField = 0;
};

#endif // BOOKINGFORM_H


