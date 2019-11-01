//Song Header File

#ifndef Song_h
#define Song_h

#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class Song{

   private:
      static const int DEFAULT_SIZE = 0;

      string title;
      string artist;
      int size;

   public:
      Song();

      Song(string title, string artist, int size);

      void setTitle(string title);
         
      void setArtist(string artist);

      void setSize(int size);

      string getTitle() const;

      string getArtist() const;

      int getSize() const;

      void swap(Song &s);

      bool operator >(Song const &rhs);
      bool operator <(Song const &rhs);
      bool operator ==(Song const &rhs);
      
  //    ~Song();
};

#endif
