#include <iostream>
#include "Controls.h"
#include "ControlFactories.h"

int main()
{
	setlocale(LC_ALL, "rus");

	factories::ControlFactory* windows = new factories::WindowsControlFactory();

    std::cout << "Label: " << std::endl;

    controls::Label* label = windows->createLabel();
    label->setPosition(1, 1);
    std::cout << label->getPosition().X << ", "  << label->getPosition().Y << std::endl;
    label->setText("APP");
    std::cout << label->getText() << std::endl;

    std::cout << std::endl << "TextBox: " << std::endl;

    controls::TextBox* textBox = windows->createTextBox();
    textBox->setText("Hello");
    std::cout << textBox->getText() << std::endl;

    std::cout << std::endl << "ComboBox: " << std::endl;

    controls::ComboBox* comboBox = windows->createComboBox();
    comboBox->setSelectedIndex(0);
    std::cout << comboBox->getSelectedIndex() << std::endl;
    comboBox->setItems('ы');
    std::cout << comboBox->getItems() << std::endl;

    std::cout << std::endl << "Button: " << std::endl;

    controls::Button* button = windows->createButton();
    button->setText("Press me");
    std::cout << button->getText() << std::endl;
    button->Click();

    controls::Form* form = windows->createForm();
    form->addControl(label);

    delete windows;
    delete form;
    delete label;
    delete textBox;
    delete comboBox;
    delete button;

    return 0;
}