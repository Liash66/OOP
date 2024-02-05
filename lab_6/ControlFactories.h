#pragma once
#include "Controls.h"

namespace factories
{
	class ControlFactory
	{
	public:
		virtual controls::Form* createForm() = 0;

		virtual controls::Label* createLabel() = 0;

		virtual controls::TextBox* createTextBox() = 0;

		virtual controls::ComboBox* createComboBox() = 0;

		virtual controls::Button* createButton() = 0;
	};

    class WindowsControlFactory : public ControlFactory
    {
        controls::Form* createForm() override
        {
            return new controls::Form();
        }

        controls::Label* createLabel() override {
            return new controls::Label();
        }

        controls::TextBox* createTextBox() override {
            return new controls::TextBox();
        }

        controls::ComboBox* createComboBox() override {
            return new controls::ComboBox();
        }

        controls::Button* createButton() override {
            return new controls::Button();
        }
    };

    class LinuxControlFactory : public ControlFactory
    {
        controls::Form* createForm() override
        {
            return new controls::Form();
        }

        controls::Label* createLabel() override {
            return new controls::Label();
        }

        controls::TextBox* createTextBox() override {
            return new controls::TextBox();
        }

        controls::ComboBox* createComboBox() override {
            return new controls::ComboBox();
        }

        controls::Button* createButton() override {
            return new controls::Button();
        }
    };

    class MacOSControlFactory : public ControlFactory
    {
        controls::Form* createForm() override
        {
            return new controls::Form();
        }

        controls::Label* createLabel() override {
            return new controls::Label();
        }

        controls::TextBox* createTextBox() override {
            return new controls::TextBox();
        }

        controls::ComboBox* createComboBox() override {
            return new controls::ComboBox();
        }

        controls::Button* createButton() override {
            return new controls::Button();
        }
    };
}