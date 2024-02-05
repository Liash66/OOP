#include <memory>
#include "Command.h"

namespace keys
{
#ifndef LAB_4_KEY_H
#define LAB_4_KEY_H

    class Key
    {
    public:
        std::string m_name;
        std::shared_ptr<commands::Command> m_command;

    public:
        Key(std::string name, std::shared_ptr<commands::Command> command) : m_name(std::move(name)), m_command(std::move(command))
        {}
    };

#endif
}