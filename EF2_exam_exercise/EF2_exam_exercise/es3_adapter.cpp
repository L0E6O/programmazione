// Exercise 3 (10+2+2 points) - Adapter design pattern
// You are working on a Rogue-like videogame that was written to be played
// with the KEYBOARD: the game loop reads the player input through the
// KeyboardInput interface (it returns a GameCommand: move up/down/left/right,
// fire, quit). The existing keyboard reader is the class Keyboard.
// You now want the SAME game to be playable with a GAMEPAD as well, reusing a
// third-party library that provides the class Gamepad (which cannot be
// modified) with its own, incompatible interface (it reports which button is
// currently pressed).
// Solve the problem using the Adapter design pattern, so that the game loop
// (the function gameLoopTick(), which cannot be modified) can be driven by the
// gamepad: write an adapter that implements KeyboardInput and translates the
// gamepad buttons into the game commands the engine expects (10 points).
// Throw the std::invalid_argument exception if a pressed gamepad button is not
// bound to any game command (2 points).
// Draw the UML class diagram of the implemented Adapter (2 points).

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

enum class GameCommand { None, MoveUp, MoveDown, MoveLeft, MoveRight, Fire, Quit };

std::string commandName(GameCommand c) {
    switch (c) {
        case GameCommand::MoveUp:    return "the hero moves up";
        case GameCommand::MoveDown:  return "the hero moves down";
        case GameCommand::MoveLeft:  return "the hero moves left";
        case GameCommand::MoveRight: return "the hero moves right";
        case GameCommand::Fire:      return "the hero attacks";
        case GameCommand::Quit:      return "quitting the game";
        default:                     return "(idle)";
    }
}

// interface the game already uses to read input (target)
class KeyboardInput {
public:
    virtual ~KeyboardInput() {}
    virtual GameCommand readCommand() = 0;
};

// the existing keyboard reader used by the game (given)
class Keyboard : public KeyboardInput {
public:
    GameCommand readCommand() override {
        char key;
        std::cin >> key;
        switch (key) {
            case 'w': return GameCommand::MoveUp;
            case 's': return GameCommand::MoveDown;
            case 'a': return GameCommand::MoveLeft;
            case 'd': return GameCommand::MoveRight;
            case 'f': return GameCommand::Fire;
            case 'Q': return GameCommand::Quit;
            default:
                throw std::invalid_argument(std::string("unknown key: ") + key);
        }
    }
};

// third-party gamepad library: DO NOT MODIFY (adaptee)
class Gamepad {
public:
    enum Button { DPadUp, DPadDown, DPadLeft, DPadRight, ButtonA, ButtonB, Start };
    explicit Gamepad(Button pressed) : pressed(pressed) {}
    Button pressedButton() const { return pressed; }
private:
    Button pressed;
};

// the game loop: DO NOT MODIFY (works with any KeyboardInput)
void gameLoopTick(KeyboardInput& input) {
    GameCommand cmd = input.readCommand();
    std::cout << commandName(cmd) << std::endl;
}

class GamepadAdapter : public KeyboardInput {
public:
    GameCommand readCommand() override {
        Gamepad::Button pressed = commands.back().pressedButton();
        commands.pop_back();
        switch (pressed) {
            case Gamepad::Button::DPadUp: return GameCommand::MoveUp;
            case Gamepad::Button::DPadDown: return GameCommand::MoveDown;
            case Gamepad::Button::DPadLeft: return GameCommand::MoveLeft;
            case Gamepad::Button::DPadRight: return GameCommand::MoveRight;
            case Gamepad::Button::ButtonA: return GameCommand::Fire;
            case Gamepad::Button::ButtonB: return GameCommand::Quit;
            default:
                throw std::invalid_argument("Button is not bound");
        }
    }

    void addCommand(const Gamepad& command) {
        commands.push_back(command);
    }

private:
    std::vector<Gamepad> commands;
};

int main() {
    Gamepad A(Gamepad::Button::ButtonA);
    Gamepad B(Gamepad::Button::ButtonB);
    Gamepad left(Gamepad::Button::DPadLeft);
    Gamepad start(Gamepad::Button::Start);

    GamepadAdapter gPA;
    gPA.addCommand(A);
    gPA.addCommand(B);
    //gPA.addCommand(left);
    //gPA.addCommand(start);

    gameLoopTick(gPA);

    //      gameLoopTick(); show the std::invalid_argument case too
    return 0;
}
