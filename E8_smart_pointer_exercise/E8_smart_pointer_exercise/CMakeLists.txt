cmake_minimum_required(VERSION 3.9)
project(E8_smart_pointer_exercise)

set(CMAKE_CXX_STANDARD 14)
# no need to set the working directory in the CLion UI, but executable will be created within the source code directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

set(SOURCE_FILES Dungeon.cpp Dungeon.h GameCharacter.cpp GameCharacter.h Weapon.cpp Weapon.h Dice.h Dice.cpp Sword.cpp Sword.h Bow.cpp Bow.h Orc.cpp Orc.h Knight.cpp Knight.h Wizard.cpp Wizard.h Skeleton.cpp Skeleton.h MageKnight.cpp MageKnight.h Inventory.h Vault.h Potion.cpp Potion.h Utilities.h GameFileException.cpp GameFileException.h splash_screen.h splash_screen.cpp FakeJPEG.cpp FakeJPEG.h)
add_executable(E8_smart_pointer_exercise main.cpp ${SOURCE_FILES})