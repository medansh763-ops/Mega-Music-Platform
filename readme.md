# Mega Music Streaming Program

This is a **C++ console-based music streaming program** created as a compilation of 10 lab exercises.  
The program demonstrates various C++ concepts while simulating a simple music platform where users can register, add songs, create playlists, play songs, rate them, and even create mashups.

---

## Features and Concepts Implemented

1. **Classes & Objects + Default Arguments**  
   - `Song` and `SongFull` classes represent songs.  
   - Default arguments are used in constructors to assign default values when no input is given.

2. **Friend Function**  
   - `Playlist` class has a friend function `showPlaylist()` which can access private song data inside playlists.

3. **Constructors (Default & Parameterized)**  
   - `Song`, `User`, and `SongFull` classes demonstrate default and parameterized constructors.

4. **Static Members & Functions**  
   - `Platform` class keeps track of total users using a static member and static functions.

5. **Function Overloading**  
   - `Display` class shows overloaded functions to display song information with or without a prefix.

6. **Unary Operator Overloading**  
   - `Rating` class allows incrementing (`++`) or decrementing (`--`) song ratings.

7. **Binary Operator Overloading**  
   - Two `SongFull` objects can be combined using the `+` operator to create a mashup.

8. **Multi-level Inheritance**  
   - `User` → `Subscriber` demonstrates multi-level inheritance with user plans.

9. **Multiple Inheritance**  
   - `SongFull` inherits from `Song`, `SongInfo`, and `SongStats` to combine multiple functionalities.

10. **Basic Input/Output**  
    - All interactions are through **console input/output** using `cin` and `cout`.

---

## How to Use

1. **Compile** the program in any C++ IDE (Dev C++, Code::Blocks, etc.).
2. **Run** the executable.
3. Use the console menu to:
   - Register users
   - Add songs
   - Create playlists
   - View playlists
   - Play songs
   - Rate songs
   - Create mashups
   - Check total users

---

## Notes

- This program uses **arrays** instead of advanced data structures to keep it compatible with basic C++ compilers.  
- All user inputs are handled carefully with simple prompts to ensure the program runs smoothly.  
- Designed as a student-friendly project to demonstrate **all key OOP concepts** taught in labs.

---

Created as a part of **BCA Lab Assignment Compilation**.
