#include <iostream>
#include <string>

using namespace std;

struct Song
{
  string title;
  string artist;
  Song *prev;
  Song *next;
};

class Playlist
{
private:
  Song *head;
  Song *tail;

public:
  Playlist()
  {
    head = nullptr;
    tail = nullptr;
  }

  // Add song to the playlist
  void addSong(string title, string artist)
  {
    Song *newSong = new Song;
    newSong->title = title;
    newSong->artist = artist;
    newSong->prev = nullptr;
    newSong->next = nullptr;

    if (head == nullptr)
    {
      head = tail = newSong;
    }
    else
    {
      tail->next = newSong;
      newSong->prev = tail;
      tail = newSong;
    }
  }

  // Display the playlist
  void displayPlaylist()
  {
    Song *temp = head;
    if (temp == nullptr)
    {
      cout << "Playlist is empty!" << endl;
      return;
    }

    while (temp != nullptr)
    {
      cout << "Title: " << temp->title << ", Artist: " << temp->artist << endl;
      temp = temp->next;
    }
  }

  // Remove a song by title
  void removeSong(string title)
  {
    Song *temp = head;

    while (temp != nullptr && temp->title != title)
    {
      temp = temp->next;
    }

    if (temp == nullptr)
    {
      cout << "Song not found!" << endl;
      return;
    }

    if (temp == head)
    {
      head = head->next;
      if (head != nullptr)
        head->prev = nullptr;
    }
    else if (temp == tail)
    {
      tail = tail->prev;
      if (tail != nullptr)
        tail->next = nullptr;
    }
    else
    {
      temp->prev->next = temp->next;
      temp->next->prev = temp->prev;
    }

    delete temp;
    cout << "Song removed!" << endl;
  }
};

int main()
{
  Playlist playlist;
  int choice;
  string title, artist;

  do
  {
    cout << "\n--- Playlist Menu ---\n";
    cout << "1. Add Song\n";
    cout << "2. Remove Song\n";
    cout << "3. Display Playlist\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
      cout << "Enter song title: ";
      cin.ignore();
      getline(cin, title);
      cout << "Enter artist name: ";
      getline(cin, artist);
      playlist.addSong(title, artist);
      break;
    case 2:
      cout << "Enter song title to remove: ";
      cin.ignore();
      getline(cin, title);
      playlist.removeSong(title);
      break;
    case 3:
      cout << "\nCurrent Playlist:\n";
      playlist.displayPlaylist();
      break;
    case 4:
      cout << "Exiting...\n";
      break;
    default:
      cout << "Invalid choice. Please try again.\n";
    }
  } while (choice != 4);

  return 0;
}