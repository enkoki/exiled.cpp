# C++ Dungeon RPG

A terminal-based RPG written in **C++**.

The project is built around object-oriented programming and is designed to gradually evolve into a dungeon-crawling RPG where the player progresses through floors, fights enemies, gains experience, earns gold, and becomes stronger.

---

## Features

### Current

* Turn-based combat system
* Player character system
* Multiple player classes

  * Samurai
  * Warrior
* Enemy system
* Enemy Factory for creating enemies
* Health, attack, and defense stats
* Experience and leveling
* Gold rewards
* Enemy bleed resistance
* Colored terminal UI
* ASCII-based game interface

### Planned

* Dungeon system
* Floors 1–100
* Floor-based enemy pools
* Elite enemies
* Floor 100 boss
* Progressive enemy difficulty
* Loot and item system
* Weapons and equipment
* Armor system
* Consumables
* Save/load system
* Player progression
* Quests and events

---

## Project Structure

```text
├── CMakeLists.txt
├── compile_flags.txt
├── game
├── include
│   ├── ascii
│   │   ├── Colors.h
│   │   ├── Logo.h
│   │   └── UI.h
│   │
│   ├── battle
│   │   └── Battle.h
│   │
│   └── entities
│       ├── Character.h
│       │
│       ├── npc
│       │   ├── EnemyFactory.h
│       │   └── Enemy.h
│       │
│       └── player
│           ├── Player.h
│           └── classes
│               ├── Samurai.h
│               └── Warrior.h
│
├── main.cpp
├── Makefile
├── README.md
│
└── src
    ├── ascii
    │   └── UI.cpp
    │
    ├── battle
    │   └── Battle.cpp
    │
    └── entities
        ├── Character.cpp
        │
        ├── npc
        │   ├── Enemy.cpp
        │   └── EnemyFactory.cpp
        │
        └── player
            ├── Player.cpp
            └── classes
                ├── Samurai.cpp
                └── Warrior.cpp
```

---

## Architecture

The project uses a basic object-oriented architecture.

### Character

`Character` acts as the base class for entities that participate in combat.

It contains common attributes such as:

* HP
* Attack
* Defense
* Level

Both players and enemies can build upon this base class.

```text
Character
   │
   ├── Player
   │     ├── Samurai
   │     └── Warrior
   │
   └── Enemy
```

---

### Player

`Player` represents the player's character and handles player-specific functionality such as:

* Experience
* Leveling
* Gold
* Combat actions
* Player progression

Player classes can specialize the base player behavior.

---

### Player Classes

Currently available classes:

#### Samurai

A class focused around offensive combat and specialized abilities.

#### Warrior

A class focused around durability and direct combat.

More classes can be added later without changing the core player system.

---

### Enemy

`Enemy` represents enemies encountered during combat.

Enemies have attributes such as:

* Name
* HP
* Attack
* Defense
* Level
* Experience reward
* Gold reward
* Bleed resistance
* Enemy type

---

### EnemyFactory

`EnemyFactory` is responsible for creating enemies.

Instead of constructing enemies directly throughout the game, the factory provides a central place for enemy creation.

Conceptually:

```text
Game
 │
 ▼
EnemyFactory
 │
 ├── Goblin
 ├── Orc
 ├── Skeleton
 └── ...
```

This will become particularly useful when the dungeon system is implemented.

---

## Battle System

The battle system handles combat between the player and enemies.

A simplified battle flow is:

```text
Player
   │
   ▼
Encounter Enemy
   │
   ▼
Start Battle
   │
   ├── Player Action
   │       │
   │       ▼
   │    Damage Enemy
   │
   ├── Enemy Action
   │       │
   │       ▼
   │    Damage Player
   │
   └── Repeat
           │
           ▼
      Battle Result
```

When an enemy is defeated, the player receives rewards such as:

```text
XP
Gold
```

---

# Dungeon System

The long-term goal of the project is to introduce a **100-floor dungeon**.

The player starts at:

```text
Floor 1
```

and progresses toward:

```text
Floor 100
```

Each floor will contain enemies appropriate to its difficulty.

A potential progression system:

```text
Floor 1–10
    ↓
Early enemies

Floor 11–20
    ↓
Stronger enemies

Floor 21–30
    ↓
Advanced enemies

...

Floor 91–99
    ↓
Elite enemies

Floor 100
    ↓
Boss
```

The dungeon will control progression, while the enemy factory will handle enemy creation.

```text
        Dungeon
                 │
        Current Floor
        Enemy Pool
                 │
                 ▼
        EnemyFactory
                 │
                 ▼
            Enemy
                 │
                 ▼
            Battle
                 │
                 ▼
        XP / Gold / Loot
                 │
                 ▼
            Next Floor
```

This separation keeps the different systems responsible for different things.

---

# Building the Project

The project supports both **Make** and **CMake**.

## Using Make

```bash
make
```

Then run:

```bash
./game
```

If your Makefile provides a clean target:

```bash
make clean
```

followed by:

```bash
make
```

---

## Using CMake

Create a build directory:

```bash
mkdir build
cd build
```

Configure the project:

```bash
cmake ..
```

Build:

```bash
cmake --build .
```

Then run the generated executable.

---

# Requirements

* C++ compiler with modern C++ support
* `g++` or `clang++`
* Make
* CMake

Recommended:

```text
C++17 or newer
```

---

# Concepts Used

This project is also intended as a practical way to learn and experiment with C++.

Some of the concepts used include:

* Classes
* Inheritance
* Polymorphism
* Encapsulation
* Constructors
* Member functions
* Header/source separation
* Namespaces
* STL containers
* `std::vector`
* Factory pattern
* Random number generation
* Object-oriented game architecture
* CMake
* Makefiles

---

# Project Goals

The main goal is to build a small but expandable RPG while learning how larger C++ projects are structured.

The intended gameplay loop is:

```text
Create Character
      ↓
Enter Dungeon
      ↓
Fight Enemies
      ↓
Gain XP & Gold
      ↓
Level Up
      ↓
Become Stronger
      ↓
Progress Through Dungeon
      ↓
Fight Boss
      ↓
Reach Floor 100
```

The project will gradually expand as new systems are introduced.

---

# Development Status

This project is currently under active development.

### Systems

| System            | Status         |
| ----------------- | -------------- |
| Character         | Completed      |
| Player            | Completed      |
| Warrior           | Completed      |
| Samurai           | Completed      |
| Enemy             | Completed      |
| Enemy Factory     | Completed      |
| Battle            | Completed      |
| ASCII UI          | Completed      |
| Dungeon           | In Development |
| Floor progression | In Development |
| Enemy scaling     | In Development |
| Bosses            | In Development |
| Inventory         | Planned        |
| Equipment         | Planned        |
| Loot              | Planned        |
| Save system       | Planned        |

---

# Roadmap

### Phase 1 — Core RPG

* Character system
* Player system
* Player classes
* Enemy system
* Enemy factory
* Battle system

### Phase 2 — Dungeon

* Create dungeon system
* Create floor system
* Implement floors 1–100
* Floor-based enemy pools
* Enemy difficulty scaling
* Boss encounters

### Phase 3 — Progression

* Improved XP system
* Level progression
* Stats
* Skills
* Class abilities

### Phase 4 — RPG Systems

* Inventory
* Weapons
* Armor
* Items
* Loot
* Shops
* Save/load

---

## License

This project is currently a personal learning/development project.

License information can be added when the project is ready for distribution.
