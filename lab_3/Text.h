#pragma once
#include <iostream>
#include "Font.h"
#include <Windows.h>

namespace text
{
    enum class Color
    {
        BLUE = 1,
        GREEN = 2,
        CYAN = 3,
        RED = 4,
        PURPLE = 5,
        YELLOW = 6,
        WHITE = 7,
    };

    class Text
    {
    private:
        std::string m_text;
        font::Font m_font;
        int m_size;
        int m_width;
        Color m_color;
        COORD m_coord;
        HANDLE m_hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        std::vector<int> m_letter_indexes;

    public:
        Text(std::string& text, int size, Color color, COORD coord) : m_text(text), m_font(size),
            m_size(size), m_width(m_font.GetWidth()), m_color(color), m_coord(coord)
        {
            for (char i : m_text)
                m_letter_indexes.push_back(static_cast<int>(i) - static_cast<int>('A'));
        }

        void Print()
        {
            SetConsoleTextAttribute(m_hStdOut, (int)m_color);
            SetConsoleCursorPosition(m_hStdOut, m_coord);

            if (m_size == 1)
                std::cout << m_text;
            else
            {
                for (int i = 0; i < m_size; i++)
                {
                    for (int j : m_letter_indexes)
                    {
                        if (j > -28)
                        {
                            for (int k = 0; k <= m_width; k++)
                                std::cout << m_font.GetFont()[i][k + m_width * j + j];
                            std::cout << " ";

                        }
                        else std::cout << "\t";
                    }

                    std::cout << std::endl;
                    m_coord.Y++;
                    SetConsoleCursorPosition(m_hStdOut, m_coord);
                }
            }

            SetConsoleTextAttribute(m_hStdOut, int(Color::WHITE));
        }
    };
}
