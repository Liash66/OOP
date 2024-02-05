#pragma once
#include <vector>
#include <string>
#include <fstream>

namespace font
{
    class Font
    {
    private:
        std::string m_alphabet_str;
        std::vector<std::string> m_font;
        int m_size;
        int m_width;
        std::string m_filepath;
        std::ifstream m_file;

    public:
        Font(int size) : m_size(size), m_filepath(std::to_string(m_size) + ".txt")
        {
            if (size == 1)
                m_width = 1;
            else
            {
                m_width = 0;
                int count = 0;

                m_file.open(m_filepath);

                if (!m_file.is_open())
                    std::cerr << std::to_string(m_size) + "Error: File doesn't open";

                while (!m_file.eof())
                {
                    std::getline(m_file, m_alphabet_str);
                    m_font.push_back(m_alphabet_str);
                }

                while (true)
                {
                    for (int i = 0; i < m_size; i++)
                        if (m_font[i][m_width] != ' ')
                        {
                            count = 0;
                            break;
                        }
                        else count++;

                    if (count == m_size)
                        break;

                    m_width++;
                }
            }
        }

        ~Font()
        {
            m_file.close();
        }

        int GetWidth()
        {
            return m_width;
        }

        std::vector<std::string>& GetFont()
        {
            return m_font;
        }
    };
}