#pragma once
#include <iostream>
#include <vector>
#include <string>

struct position
{
	int X, Y;
};

namespace controls
{
	class Control
	{
	protected:
		position m_position;

	public:
		virtual void setPosition(int X, int Y)
		{
			m_position = { X, Y };
		}

		virtual position getPosition()
		{
			return m_position;
		}
	};

	class Form : public Control
	{
	private:
		std::vector<Control*> m_controls;

	public:
		void addControl(Control* control)
		{
			m_controls.push_back(control);
		}
	};

	class Label : public Control
	{
	private:
		std::string m_text;

	public:
		void setText(const std::string& text)
		{
			m_text = text;
		}

		std::string getText()
		{
			return m_text;
		}
	};

	class TextBox : public Control
	{
	private:
		std::string m_text;

	public:
		void setText(const std::string& text)
		{
			OnValueChanged(text);
			m_text = text;
		}

		std::string getText()
		{
			return m_text;
		}

		void OnValueChanged(const std::string& text)
		{
			if (m_text != text)
				std::cout << "Текст изменился" << std::endl;
		}
	};

	class ComboBox : public Control
	{
	private:
		int m_selectedIndex;
		std::string m_items;

	public:
		int getSelectedIndex()
		{
			return m_selectedIndex;
		}

		void setSelectedIndex(const int& selectedIndex)
		{
			m_selectedIndex = selectedIndex;
		}

		void setItems(const char& item)
		{
			if (m_items.size() == 0)
				m_items.push_back(item);
			else
				m_items[m_selectedIndex] = item;
		}

		std::string getItems()
		{
			return m_items;
		}
	};

	class Button : public Control
	{
	private:
		std::string m_text;

	public:
		void setText(const std::string& text)
		{
			m_text = text;
		}

		std::string getText()
		{
			return m_text;
		}

		void Click()
		{
			std::cout << "Click..." << std::endl;
		}
	};
}