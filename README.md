# WayToTheGlory

**WayToTheGlory** is a 2D action game where you, the player, must defeat a dragon by attacking it with your spear while dodging its fireball attacks. The game is designed to be played in a resolution of **1280x800** and offers an engaging challenge with dynamic gameplay mechanics.

---

## **Gameplay Overview**

- **Objective**: Defeat the dragon before it defeats you.
- **Player Actions**:
  - Move around the map using `W`, `A`, `S`, `D`.
  - Attack the dragon using the `Space` key.
- **Dragon Actions**:
  - The dragon will attack you with fireballs after a short delay.
  - Avoid its attacks while dealing damage to win.
- **Meteorites**:
  - Meteorites spawn randomly on the map and can heal the dragon if left unchecked.
  - Destroy meteorites to prevent the dragon from regaining health.

---

## **Features**

- **Dynamic Combat**:
  - Attack the dragon with precise timing while dodging its fireballs.
- **Health System**:
  - Both the player and the dragon have health bars displayed on the screen.
- **Meteorite Mechanics**:
  - Meteorites spawn periodically and can heal the dragon.
- **Victory and Defeat Conditions**:
  - Victory: Defeat the dragon.
  - Defeat: If your health reaches zero, the game ends.
- **Custom Exceptions**:
  - The game uses a robust exception-handling system for file loading, invalid entities, and game state errors.

---

## **Controls**

| Key          | Action                  |
|--------------|-------------------------|
| `W`          | Move Up                 |
| `A`          | Move Left               |
| `S`          | Move Down               |
| `D`          | Move Right              |
| `Space`      | Attack                  |
| `Escape`     | Exit the Game           |

---

## **How to Play**

1. **Start the Game**:
   - Launch the game executable.
   - The game window will open with a resolution of **1280x800**(you can extend it to fulscreen if you want).

2. **Defeat the Dragon**:
   - Use the movement keys to dodge the dragon's attacks.
   - Attack the dragon using the `Space` key.

3. **Avoid Meteorites**:
   - Destroy meteorites before they heal the dragon.

4. **Win or Lose**:
   - If the dragon's health reaches zero, you win.
   - If your health reaches zero, you lose.

---

## **Installation**

1. **Clone the Repository**:
   ```terminal Linux/Windows/MAC
   git clone https://github.com/nailedion/WayToTheGlory.git
   cd WayToTheGlory

2. **Install Dependencies**
    -Ensure you have SFML(2.6.2) installed.
    -Use the UCRT64 version of MinGW if you're on Windows.

3. **Build the game**
    -Use the provided task.json in Visual Studio Code to build the project.
    -OR USE THE COMMAND: g++ -std=c++17 -IC:/msys64/mingw64/include -IC:/msys64/mingw64/include/SFML -LC:/msys64/mingw64/lib *.cpp -lsfml-graphics -lsfml-window -lsfml-system -o WayToTheGlory.exe

4. **Run the game**
 1) ./WayToTheGlory.exe
 2) Double click on the executable file.

## **File Structure**

WayToTheGlory/
```
├── Animation.cpp/.h         # Handles sprite animations
├── Attack.cpp/.h            # Player attack logic
├── Entity.cpp/.h            # Base class for all entities
├── ExceptionTypes.cpp/.h    # Custom exception classes
├── GameManager.cpp/.h       # Manages meteorites and game logic
├── main.cpp                 # Main game loop
├── Meteorite.cpp/.h         # Meteorite logic
├── Monster.cpp/.h           # Dragon (monster) logic
├── MonsterAttack.cpp/.h     # Dragon's attack logic
├── Player.cpp/.h            # Player logic
├── Textures/                # Game textures (e.g., dragon, player, meteorite)
├── Fonts/                   # Fonts used in the game
└── .vscode/                 # VSCode configuration files
```

## **Credits**
 - Developer: Bâcă Ionuț-Adelin
 - Inspiration: Metin2
 - Libraries Used: SFML
 - Tutorials that inspired my code: https://www.youtube.com/watch?v=axIgxBQVBg0&list=PL21OsoBLPpMOO6zyVlxZ4S4hwkY_SLRW9
 - Modified Textures from:  https://craftpix.net/freebies/free-rpg-monster-sprites-pixel-art/ ;
                            https://craftpix.net/freebies/2d-fantasy-knight-free-sprite-sheets/ ;
                            The meteorites are the lvl 35 metins.

## **Tips**
    If you've made it this far, you must be a geek 🤓 like me. Want some tips?
    -The dragon has a shorter attack range on its right side, so try attacking from there.
    -If the dragon collides with meteorites, it will destroy them.
    -The game warns you not to reach 0 HP — if the dragon has low HP, you can afford to lose some, but be careful.
    -You have 100 HP, the dragon has 500 HP, and you both deal 10 damage per hit.
    -Every 60 seconds, meteorites appear. Each meteorite heals the dragon by 5 HP every 10 seconds.

Enjoy the game and good luck defeating the dragon! 🐉

## **Tasks for the second project**
```
  -The Player, Monster, and Meteorite classes are derived from the Entity base class.
  -The update virtual function, defined in the Meteorite class and specific to the theme, is invoked through a pointer to the base class.
  -In the Meteorite class we find a virtual constructor.
  -In the Player's constructor we find the call of the Entity's constructor.
  -Entity has operator overloading = and dynamic cast in the Meteorite class.
  -The FileLoadException, InvalidEntityException, StateException exceptions from GameException.
```

## **Tasks for the third project**
```
  -I've made GameManager and Player singleton classes.
  -I’ve made GameManager a template class. Now, if needed, it can be used for other entities as well (with slight modifications to the function names [Update/update with uppercase/lowercase] and possibly a few [pure] virtual functions, but I don’t need to do that right now).
  -Implemented the removeIfPtr template function to verify if the meteorites are alive. If they aren't(checked by the lambda function) it will remove them from the vector.
```