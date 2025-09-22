#include <iostream>
#include <string>
using namespace std;

/* ============================================================
   CLASS DEFINITIONS
   ============================================================ */

// 1. Classes & Objects + Default Arguments
class Song {
    string title, artist;
    int rating;   // 0–5
    float duration; 

public:
    // Constructors
    Song() {
        title = "Shape of You";
        artist = "Ed Sheeran";
        duration = 4.0;
        rating = 3;
    }

    Song(string t, string a, float d, int r = 3) {
        title = t;
        artist = a;
        duration = d;
        rating = r;
    }

    // Function Overloading (display variations)
    void display(string t) {
        cout << "Now playing: " << t << endl;
    }
    void display(string t, string a) {
        cout << "Now playing: " << t << " by " << a << endl;
    }
    void display(string t, string a, float d) {
        cout << "Now playing: " << t << " by " << a << " [" << d << " mins]" << endl;
    }

    // Default argument
    void play(int id = 1) {
        cout << "Playing track #" << id << ": " << title << " by " << artist << endl;
    }

    // Unary operator overloading (++ / --)
    void operator++() {
        if (rating < 5) rating++;
    }
    void operator--() {
        if (rating > 0) rating--;
    }

    // Binary operator overloading (+)
    Song operator+(Song &other) {
        string mashup = title + " x " + other.title;
        int avgRating = (rating + other.rating) / 2;
        return Song(mashup, artist + " & " + other.artist, (duration + other.duration) / 2, avgRating);
    }

    void showDetails() {
        cout << "Title: " << title << "\nArtist: " << artist
             << "\nDuration: " << duration << " mins"
             << "\nRating: " << rating << "/5\n";
    }

    friend class Playlist; // friend function will access
};

// 2. Friend Function
class Playlist {
    string name;
public:
    Playlist(string n = "My Playlist") : name(n) {}

    friend void showDetails(Song s, Playlist p);
};
void showDetails(Song s, Playlist p) {
    cout << "\n[Friend Function Access]\nPlaylist: " << p.name << endl;
    s.showDetails();
}

// 3. Static Functions
class User {
    string username;
    static int count;
public:
    void addUser(string u) {
        username = u.empty() ? "guest" : u;
        count++;
    }
    void displayUser() { cout << "User: " << username << endl; }
    static void displayCount() {
        cout << "Total users: " << count << endl;
    }
};
int User::count = 0;

// 4. Inheritance
class Subscription : public User {
    string plan;
public:
    void setPlan(string p) { plan = p.empty() ? "Free" : p; }
    void displayPlan() { cout << "Subscription Plan: " << plan << endl; }
};

class Library : public Subscription {
    string favSong;
public:
    void setFav(string s) { favSong = s.empty() ? "Unknown" : s; }
    void showLibrary() { cout << "Favourite Song: " << favSong << endl; }
};

// Multiple Inheritance
class Content {
protected:
    string genre;
};
class Artist {
protected:
    string artistName;
};
class FullSong : public Content, public Artist {
    string title;
public:
    void setDetails(string t, string g, string a) {
        title = t; genre = g; artistName = a;
    }
    void show() {
        cout << "Song: " << title << " | Genre: " << genre << " | Artist: " << artistName << endl;
    }
};

/* ============================================================
   MAIN PROGRAM
   ============================================================ */
int main() {
    Song s1("Numb", "Linkin Park", 3.5, 4);
    Song s2("Karma Police", "Radiohead", 4.2, 5);
    Playlist p("Rock Mix");

    User u1;
    u1.addUser("Medansh");

    Library lib;
    lib.setPlan("Premium");
    lib.setFav("Paradise");

    FullSong fs;
    fs.setDetails("Yellow", "Alt Rock", "Coldplay");

    int choice;
    do {
        cout << "\n===== Mega Music Streaming Platform =====\n";
        cout << "1. Play Song (default arg)\n2. Show Song Info (overloading)\n3. Rate Songs (++/--)\n";
        cout << "4. Create Mashup (+)\n5. Friend Function Demo\n6. User & Static Function\n";
        cout << "7. Multi-level Inheritance Demo\n8. Multiple Inheritance Demo\n0. Exit\nEnter choice: ";
        cin >> choice;
        cin.ignore();

        switch(choice) {
            case 1: s1.play(); break;
            case 2: s1.display("Numb"); s1.display("Numb","Linkin Park"); s1.display("Numb","Linkin Park",3.5); break;
            case 3: ++s1; --s2; cout << "Ratings updated!\n"; break;
            case 4: { Song mashup = s1 + s2; mashup.showDetails(); } break;
            case 5: showDetails(s1, p); break;
            case 6: u1.displayUser(); User::displayCount(); break;
            case 7: lib.displayUser(); lib.displayPlan(); lib.showLibrary(); break;
            case 8: fs.show(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while(choice != 0);

    return 0;
}

