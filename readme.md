# Mega Music Streaming Platform (C++ Lab Integration)

This program integrates all lab exercises into a single **Mega Program** for demonstration.

## Features & Concepts Used

1. **Classes & Objects** → `Song` class (basic play function).  
2. **Default Arguments** → `Song::play()` uses default ID = 1.  
3. **Friend Function** → `showDetails(Song, Playlist)` displays private info.  
4. **Constructors** → Default & Parameterized constructors in `Song`.  
5. **Static Data Members & Functions** → `User::count` tracks total users.  
6. **Function Overloading** → `Song::display()` shows song info in multiple formats.  
7. **Unary Operator Overloading** → `++` and `--` adjust song rating.  
8. **Binary Operator Overloading** → `+` creates mashup of two songs.  
9. **Multi-level Inheritance** → `User → Subscription → Library`.  
10. **Multiple Inheritance** → `FullSong` inherits from both `Content` and `Artist`.  

---

## How to Run
1. Compile:  
   ```bash
   g++ mega_music.cpp -o mega_music
