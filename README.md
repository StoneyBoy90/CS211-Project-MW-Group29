# CS211-Project-MW-Group29
- CS211 group project: 2048 and Luhn checksum checker, written in C++.
- Repository: https://github.com/StoneyBoy90/CS211-Project-MW-Group29

# Group 29
- Jacob Stoner: StoneyBoy90.
- Brody: BrodyBazelle

# Projects

- 2048 Game: a 5x5 console game.
- Luhn Program: Checks a 16-digit number.

# Task Plan

- Week 1: Create repository, complete the left movement, and begin other directions.
- Week 2: Finish movements, the game controls, scoring, and save/load. Complete the Luhn program.
- Week 3: Test programs, finish the documentation, and prepare for submission.

# Build and Run Commands
Run commands from the project's root folder.

- 2048 Game
```
clang++ -std=c++17 -Wall -Wextra -pedantic game2048/main.cpp game2048/2048_helper.cpp -o game2048/main
./game2048/main
```

- Luhn Program
```
clang++ -std=c++17 -Wall -Wextra -pedantic luhn/main.cpp luhn/luhn_helper.cpp -o luhn/main
./luhn/main
```

# Controls

- 2048 Game
Keys 'u,d,l,r' are your up, down, left, and right movements.
To start a new game press 'n' and confirm this choice with 'y/n'.
For assistance from the help menu, press 'h'.
Save your game by pressing 's', each time you save, the previously saved game will be overwritten. The saved game is stored in savegame.txt in the folder where you run the program.
Press 'o' and you will open your saved game to play some more.
When you're beat, press 'e' to exit the game.
To try the sample, copy game2048/sample_save.txt into the project's root folder as savegame.txt, then run game and press 'o'. This will load the sample saved game. Copying the sample replaces any existing savegame.txt.

- Luhn Program
Enter exactly 16 digits, as found on credit cards, with no spaces or letters.
A checksum returned as Valid does not mean a card exists or is active.
To exit the program, press 'e'.