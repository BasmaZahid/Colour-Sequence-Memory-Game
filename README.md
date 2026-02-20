# Color Sequence Memory Game 🎮
This is a pattern-based memory challenge developed in **C** using the **Raylib** library as part of my CFP Lab at PIEAS.

## Description
The game challenges players to memorize and replicate a randomized sequence of colors. It features a dynamic difficulty system where the sequence length increases with every successful level.

## Files
* `main.c` – The core game engine and logic.
* `makefile` – Build instructions for the project.
* `README.md` – Documentation (you are here!).

## Technical Highlights
* **State Machine:** Managed transitions between Menu, Computer Sequence, and Player Input.
* **Input Handling:** Real-time mouse collision detection for interactive gameplay.
* **Data Modeling:** Used C `structs` to handle tile states and game properties.

## How to Run
1. **Prerequisites:** Ensure you have the Raylib library installed on your system.
2. **Compile:** Use the following command:
   `gcc main.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o color_game`
3. **Run:** `./color_game`

## Author
**Basma Zahid**
CIS Student at PIEAS
