#ifndef _H_KEYBOARD_INPUT_
#define _H_KEYBOARD_INPUT_

#include <cstdlib>
#include <memory>
#include <vector>
#include <string>

#include <LEDTableEngine/core/baseInput.hpp>
#include <LEDTableEngine/inputHandlers/keyboard.hpp>

namespace led{
  /**
   * @brief Input handler implementation that takes the input from a keyboard.
   * Keyboard events are directly parsed from the keyboard event file.
   */
class KeyboardInput : public BaseInput {
public:

    KeyboardInput(std::string keyboardDev);
    virtual ~KeyboardInput();

    bool                        initialize();
    BaseInput::InputEvents getInputEvents();
    size_t                 getSupportedPlayerCnt();

private:

    cKeyboard m_keyboard;
    std::string m_keyboardDevName;
};
}

#endif // ifndef _H_KEYBOARD_INPUT_
