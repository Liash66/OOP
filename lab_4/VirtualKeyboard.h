#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <chrono>
#include <thread>
#include <Windows.h>
#include "Key.h"
#include "Command.h"

namespace virtual_keyboard
{
#ifndef LAB_4_VIRTUALKEYBOARD_H
#define LAB_4_VIRTUALKEYBOARD_H

    class VirtualKeyboard
    {
    private:
        std::vector<keys::Key> m_actions;
        HANDLE m_hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD m_coord_history = { 15, 0 };
        COORD m_coord_output = { 7, 1 };

        void drawInterface()
        {
            SetConsoleCursorPosition(m_hStdOut, { 0, m_coord_history.Y });
            std::cout << "История ввода:";
            SetConsoleCursorPosition(m_hStdOut, { 0, m_coord_output.Y });
            std::cout << "Вывод:" << std::endl;
        }

        void commandHistory(const std::string& key)
        {
            SetConsoleCursorPosition(m_hStdOut, m_coord_history);
            std::cout << "{" << key << "}";
            m_coord_history.X += key.length()+2;
        }

        void commandOutput(const std::shared_ptr<commands::Command>& command)
        {
            SetConsoleCursorPosition(m_hStdOut, m_coord_output);
            command->execute();
            m_coord_output.X++;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }

        void throwKeyError(const std::string& error)
        {
            SetConsoleCursorPosition(m_hStdOut, {0, max(m_coord_history.Y, m_coord_output.Y)});
            std::cout << std::endl << error;
        }

    public:
        VirtualKeyboard()
        {
            drawInterface();
        };

        ~VirtualKeyboard()
        {}

        void pressKey(const std::string& key)
        {
            commandHistory(key);

            bool assign_is = false;
            for (const auto& action : m_actions)
                if (action.m_name == key)
                {
                    commandOutput(action.m_command);
                    assign_is = true;
                    m_coord_output.X++;
                }
            if (!assign_is)
                throwKeyError("Команда для {" + key + "} отсутствует");
        }

        void assignAction(const std::string& key, std::shared_ptr<commands::Command> command)
        {
            bool assign_is = false;
            for (auto& action : m_actions)
                if (action.m_name == key)
                {
                    action = keys::Key(key, std::move(command));
                    assign_is = true;
                }
            if (!assign_is)
                m_actions.emplace_back(key, std::move(command));
        }

        void undo(const std::string& key)
        {
            if (!m_actions.empty())
                for (int i = 0; i < m_actions.size(); i++)
                    if (m_actions[i].m_name == key)
                        m_actions.erase(m_actions.begin() + i);
        }

        void undo()
        {
            if (!m_actions.empty())
            {
                for (int i = 0; i < m_actions.size(); i++)
                    m_actions.pop_back();
            }
        }
    };

#endif
}