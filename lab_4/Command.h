#include <iostream>

namespace commands
{
#ifndef LAB_4_COMMAND_H
#define LAB_4_COMMAND_H

    class Command
    {
    public:
        virtual void execute() = 0;
    };

    class Command_1 : public Command
    {
    public:
        void execute() override
        {
            std::cout << "1";
        }
    };

    class Command_a : public Command
    {
    public:
        void execute() override
        {
            std::cout << "a";
        }
    };

    class Command_shift_1 : public Command
    {
    public:
        void execute() override
        {
            std::cout << "!";
        }
    };

    class Command_shift_a : public Command
    {
    public:
        void execute() override
        {
            std::cout << "A";
        }
    };

#endif
}