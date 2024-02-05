#include <windows.h>
#include "VirtualKeyboard.h"
#include "Command.h"

int main() {
    setlocale(LC_ALL, "rus");

    virtual_keyboard::VirtualKeyboard keyboard;

    keyboard.assignAction("1", std::make_unique<commands::Command_1>());
    keyboard.assignAction("a", std::make_unique<commands::Command_a>());
    keyboard.assignAction("shift+1", std::make_unique<commands::Command_shift_1>());
    keyboard.assignAction("shift+a", std::make_unique<commands::Command_shift_a>());

    keyboard.pressKey("1");
    keyboard.pressKey("a");
    keyboard.pressKey("shift+1");
    keyboard.pressKey("shift+a");

    keyboard.assignAction("1", std::make_unique<commands::Command_a>());
    keyboard.assignAction("a", std::make_unique<commands::Command_1>());

    keyboard.pressKey("1");
    keyboard.pressKey("a");

    keyboard.undo("shift+1");
    keyboard.pressKey("shift+1");
    keyboard.undo();

    return 0;
}