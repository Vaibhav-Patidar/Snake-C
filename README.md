🐍 Snake Game in C (NCURSES)
🎓 First Semester End-Semester Project

A classic terminal-based Snake Game built entirely in C using the ncurses library.
This project was created as my First Semester End-Sem Project.

🚀 Features

🟩 Smooth real-time snake movement

🍎 Random food spawning

📈 Score & High Score system

⚡ Speed increases as you eat food

💀 Clean, centered Game Over screen

🎨 ncurses-based UI

🎯 Border collision detection

🖥️ Game Preview (Terminal Style)
+----------------------------------------+
|            S N A K E   G A M E         |
|                                        |
|                o###                    |
|                  $                     |
|                                        |
+----------------------------------------+


(This is a simplified preview — actual output depends on your terminal size.)

🎮 Controls
Key	Action
⬆️	Move Up
⬇️	Move Down
⬅️	Move Left
➡️	Move Right
ESC	Quit Game
🛠️ Tech Used

C Programming

ncurses

time.h

unistd.h

stdlib.h

Makefile

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

3. Run it
./snake

📁 Project Structure
Snake-C/
│
├── main.c          # Core game loop
├── start.c         # Start screen
├── printing.c      # Snake rendering
├── eating.c        # Food spawning logic
├── gameover.c      # Game Over + score display
│
├── start.h
├── printing.h
├── eating.h
├── gameover.h
│
├── Makefile
└── README.md

🧠 Game Logic Summary

Snake moves based on arrow keys

Food spawns randomly inside the border

Score increases on food eat

Snake speed increases as score increases

Collision with border → Game Over

Game Over screen shows:

Final Score

High Score (saved in memory)

Game restarts after key press

✨ Future Improvements

Snake body growth

Self-collision detection

Difficulty settings

Permanent high score saved to file

Sound effects

👨‍💻 Author

Vaibhav Patidar
First Semester — End Semester Project
