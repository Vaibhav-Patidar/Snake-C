🐍 Snake Game in C (NCURSES)
🎓 First Semester End-Semester Project

A classic terminal-based Snake Game built entirely in C using the ncurses library.
This game was developed as my First Sem End-Sem Project, featuring:

Smooth snake movement

Random food spawning

Score + High Score system

Increasing game speed

Clean & centered Game Over screen

Full ncurses-based UI

🔥 Game Preview (Terminal Output)
+-----------------------------------------+
|        S N A K E    G A M E 🐍          |
|                                         |
|                 o###                    |
|                                         |
|                 $                       |
+-----------------------------------------+

🚀 Features
🟩 Smooth Real-Time Movement

Controlled using arrow keys with nodelay() for lag-free gameplay.

🍎 Random Food Generation

Food appears at random valid positions inside the boundary using rand().

📈 Scoring System

Every food eaten:

Increases score

Increases speed (game gets harder)

Updates high score

Displayed on Game Over screen.

💀 Game Over Screen

Centered and clean output like:

GAME OVER
Press any key to continue...
Final Score: 7  |  High Score: 12

🛠️ Technologies Used

C Language

ncurses (graphics + input)

unistd.h (usleep)

time.h (rand seeding)

Makefile

🎮 Controls
Key	Action
⬆️	Move Up
⬇️	Move Down
⬅️	Move Left
➡️	Move Right
ESC	Quit Game
📦 Installation & Running
1. Install ncurses (if needed)

macOS:

brew install ncurses


Ubuntu/Debian:

sudo apt install libncurses5-dev libncursesw5-dev

2. Build the game

Using Makefile:

make


Or manually:

cc main.c start.c gameover.c eating.c -lncurses -o snake

3. Run the game
./snake

📁 Project Structure
Snake-C/
│
├── main.c          # Core game logic and loop
├── start.c         # Start screen and initialization
├── printing.c      # Snake rendering functions
├── eating.c        # Food spawning logic
├── gameover.c      # Game over screen + final score + high score
│
├── start.h
├── printing.h
├── eating.h
├── gameover.h
│
├── Makefile
└── README.md

🧠 Game Logic Summary

Main loop handles:

Input

Movement

Screen redraw

Collision detection

Food eating

Food is displayed until eaten

When eaten:

Score increases

New food spawns

Speed increases gradually

Game ends when snake hits border

Game Over screen displays score + high score

⭐ Future Improvements

Snake body growth

Self-collision detection

Difficulty modes

High score saved to file

Better start menu

Sound effects (terminal bell)

🙌 Author

Vaibhav Patidar
First Semester • End-Sem Project
C Programming + NCURSES
