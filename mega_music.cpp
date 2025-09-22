#include <iostream>
#include <string>
using namespace std;

const int MAX_USERS = 20;
const int MAX_SONGS = 50;

// ===== Lab 1 & 2: Classes & default arguments =====
class Song {
    string title;
    string artist;
    float duration;
public:
    Song() { title = "Untitled"; artist = "Unknown"; duration = 3.0; } // default constructor
    Song(string t, string a, float d) { title = t; artist = a; duration = d; } // parameterized
    void play() { cout << "Now playing: " << title << " by " << artist << " [" << duration << " mins]\n"; }
    string getTitle() { return title; }
    string getArtist() { return artist; }
    float getDuration() { return duration; }
};

// ===== Lab 3: Friend function =====
class Playlist; // forward declaration
void showPlaylist(Playlist &p);

class Playlist {
    string name;
    Song songs[MAX_SONGS];
    int count;
public:
    Playlist() { count = 0; name = "Default"; }
    void setName(string n) { name = n; }
    void addSong(Song s) { if(count<MAX_SONGS) songs[count++] = s; }
    friend void showPlaylist(Playlist &p);
};

void showPlaylist(Playlist &p) {
    cout << "\n--- Playlist: " << p.name << " ---\n";
    for(int i=0;i<p.count;i++)
        p.songs[i].play();
}

// ===== Lab 4: Static members & functions =====
class Platform {
    static int totalUsers;
public:
    static void incrementUsers() { totalUsers++; }
    static void showTotalUsers() { cout << "Total users: " << totalUsers << "\n"; }
};
int Platform::totalUsers = 0;

// ===== Lab 5: Function overloading =====
class Display {
public:
    void showSong(Song s) { s.play(); }
    void showSong(Song s, string prefix) { cout << prefix; s.play(); }
};

// ===== Lab 6: Unary operator overloading =====
class Rating {
    int stars;
public:
    Rating() { stars = 3; }
    void show() { cout << "Rating: " << stars << "/5\n"; }
    void operator++() { if(stars<5) stars++; }
    void operator--() { if(stars>0) stars--; }
};

// ===== Lab 7: Binary operator overloading =====
Song operator+(Song &a, Song &b) {
    string title = a.getTitle() + " x " + b.getTitle();
    string artist = a.getArtist() + " & " + b.getArtist();
    float duration = (a.getDuration() + b.getDuration()) / 2;
    return Song(title, artist, duration);
}

// ===== Lab 8: Multi-level inheritance =====
class User {
protected:
    string username;
public:
    User() { username = "Guest"; }
    User(string n) { username = n; }
    string getName() { return username; }
};

class Subscriber : public User {
    string plan;
public:
    Subscriber() { plan = "Free"; }
    Subscriber(string n, string p) : User(n) { plan = p; }
    string getPlan() { return plan; }
};

// ===== Lab 9 & 10: Multiple inheritance =====
class SongInfo {
protected:
    string genre;
public:
    void setGenre(string g) { genre = g; }
    string getGenre() { return genre; }
};

class SongStats {
protected:
    int plays;
public:
    void setPlays(int p) { plays = p; }
    int getPlays() { return plays; }
};

class SongFull : public Song, public SongInfo, public SongStats {
public:
    SongFull() : Song() { setPlays(0); setGenre("Misc"); }
    SongFull(string t, string a, float d) : Song(t,a,d) { setPlays(0); setGenre("Misc"); }
    void displayFull() {
        play();
        cout << "Genre: " << getGenre() << ", Plays: " << getPlays() << "\n";
    }
};

// ===== Main Program =====
int main() {
    User users[MAX_USERS];
    int userCount = 0;

    SongFull songs[MAX_SONGS];
    int songCount = 0;

    Playlist playlists[MAX_USERS];
    int playlistCount = 0;

    int choice;
    do {
        cout << "\n--- Music Streaming Platform ---\n";
        cout << "1. Register User\n2. Add Song\n3. Create Playlist\n4. View Playlist\n5. Play Song\n6. Rate Song\n7. Create Mashup\n8. Show Total Users\n0. Exit\n";
        cout << "Enter choice: "; cin >> choice; cin.ignore();

        if(choice==1) {
            if(userCount>=MAX_USERS) { cout << "Max users reached\n"; continue; }
            string uname; cout << "Enter username: "; getline(cin, uname);
            users[userCount++] = User(uname);
            Platform::incrementUsers();
        }
        else if(choice==2) {
            if(songCount>=MAX_SONGS) { cout << "Max songs reached\n"; continue; }
            string t,a,g; float d;
            cout << "Enter song title: "; getline(cin,t);
            cout << "Enter artist: "; getline(cin,a);
            cout << "Enter duration: "; cin >> d; cin.ignore();
            songs[songCount] = SongFull(t,a,d);
            cout << "Enter genre: "; getline(cin,g);
            songs[songCount].setGenre(g);
            songCount++;
        }
        else if(choice==3) {
            if(playlistCount>=MAX_USERS) { cout << "Max playlists reached\n"; continue; }
            string pname; cout << "Enter playlist name: "; getline(cin,pname);
            playlists[playlistCount].setName(pname);
            int n; cout << "Add how many songs? "; cin >> n; cin.ignore();
            for(int i=0;i<n;i++){
                int sid; cout << "Song number (0-" << songCount-1 << "): "; cin >> sid; cin.ignore();
                if(sid>=0 && sid<songCount) playlists[playlistCount].addSong(songs[sid]);
            }
            playlistCount++;
        }
        else if(choice==4){
            for(int i=0;i<playlistCount;i++) showPlaylist(playlists[i]);
        }
        else if(choice==5){
            int sid; cout << "Play song number (0-" << songCount-1 << "): "; cin >> sid; cin.ignore();
            if(sid>=0 && sid<songCount) songs[sid].play();
        }
        else if(choice==6){
            Rating r; int op;
            cout << "Current "; r.show();
            cout << "1. Increase rating 2. Decrease rating: "; cin >> op; cin.ignore();
            if(op==1) ++r; else if(op==2) --r;
            r.show();
        }
        else if(choice==7){
            int a,b; cout << "Select two songs to mashup: "; cin >> a >> b; cin.ignore();
            if(a>=0 && b>=0 && a<songCount && b<songCount){
                Song mash = songs[a] + songs[b];
                mash.play();
            }
        }
        else if(choice==8) Platform::showTotalUsers();
    } while(choice!=0);

    cout << "Exiting platform.\n";
    return 0;
}
