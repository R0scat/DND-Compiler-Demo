# Dungeons and Dragons manager

A C++14 console application for creating and managing Dungeons & Dragons (D&D) characters and campaigns. The project provides both a Player Mode for character creation and management, and a Dungeon Master Mode for campaign and entity management.

## Features

- **Player Mode**
  - Guided character creation (name, class, race, level)
  - Attribute and ability assignment based on class and race
  - Character details display
  - Interactive menu for character management

- **Dungeon Master Mode**
  - Entity management (creatures, effects, etc.)
  - Menu-driven interface for campaign management

- **Core System**
  - Object-oriented design with classes for entities, effects, races, classes, and more
  - Use of design patterns (Singleton for main menu)
  - Extensible architecture for adding new features

## File Structure

- `DND in Compiler.cpp` — Main entry point, menu logic, and mode selection
- `player_character.h/cpp` — Player character class and logic
- `class.h/cpp` — Character class definitions and logic
- `race.h/cpp` — Race definitions and logic
- `atribute_helper.h/cpp` — Attribute reading and assignment
- `entity.h/cpp` — Base entity class (for all game objects)
- `effect.h/cpp` — Effect system for buffs/debuffs
- `creature.h/cpp` — Creature definitions
- `entity_manager.h/cpp` — Management of all entities in the game
- `dm_helper.h` — Dungeon Master utilities and menu
- `dnd_helper.h` — Helper functions for D&D logic and UI
- `main_menu.h/cpp` — Singleton menu implementation

## Getting Started

### Prerequisites

- Visual Studio 2022 or compatible C++14 compiler
- Standard C++14 libraries

### Building

1. Open the solution in Visual Studio 2022.
2. Build the solution (`Ctrl+Shift+B`).

### Running

1. Run the compiled executable.
2. Choose between Player Mode or Dungeon Master Mode from the main menu.

## Usage

- **Player Mode:** Follow prompts to create a character, select class/race/level, and manage your character.
- **Dungeon Master Mode:** Use the menu to manage entities and campaign elements.

## Extending

- Add new classes/races by editing `class.h/cpp` and `race.h/cpp`.
- Add new effects in `effect.h/cpp`.
- Expand menu options in `main_menu.h/cpp` and related helpers.


