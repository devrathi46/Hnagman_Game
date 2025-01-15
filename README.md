# Hangman Game in C++

## Overview
This is a simple implementation of the classic **Hangman Game** in C++ using **Object-Oriented Programming (OOP)** principles. The game allows a player to guess a hidden word by entering one letter at a time, with a limited number of incorrect guesses allowed.

## Features
- Object-Oriented Design
- Encapsulation of game logic within classes
- Dynamic word selection
- Tracks player's progress and remaining attempts
- Displays a visual representation of the hangman

## Gameplay
The game selects a word from a predefined list, and the player has to guess the word one letter at a time. The player loses if they exceed the maximum allowed incorrect guesses.

---

## Project Structure
The program uses OOP concepts such as **classes**, **objects**, and **inheritance**. Below is an outline of the key components:

### Classes
1. **HangmanGame**
   - Manages the overall game logic, including word selection, tracking guesses, and determining win/loss conditions.
2. **WordManager**
   - Handles the selection of a random word from a predefined list and ensures uniqueness.
3. **Player**
   - Manages player-specific data, such as their current guesses and remaining attempts.

---

## Prerequisites
- A C++ compiler (e.g., GCC, Clang, or MSVC)
- Basic knowledge of C++ and OOP concepts

---

## How to Run
1. Clone this repository:
   ```bash
   git clone https://github.com/<your-username>/hangman-oop.git
   cd hangman-oop
