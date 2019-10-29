#include "UtPod.h"

using namespace std;

Song::Song(){
   title = "Untitled";
   artist = "Unnamed Artist";
   size = DEFAULT_SIZE;
}

Song::Song(string title, string artist, int size){
   this->title = title;
   this->artist = artist;
   this->size = size;
}

void Song::setTitle(string title){
   this->title = title;
}

void Song::setArtist(string artist){
   this->artist = artist;
}

void Song::setSize(int size){
   this->size = size;
}

string Song::getTitle() const{
   return title;
}

string Song::getArtist() const{
   return artist;
}

int Song::getSize() const{
   return size;
}

bool Song::operator >(Song const &rhs){
   if(artist > rhs.artist)
      return true;
   if((artist == rhs.artist) && (title > rhs.title))
      return true;
   if(artist == rhs.artist && (title == rhs.title) && (size > rhs.size))
      return true;

   return false;
}

bool Song::operator <(Song const &rhs){
  if(artist < rhs.artist) 
      return true;
   if((artist == rhs.artist) && (title < rhs.title))
      return true;
   if(artist == rhs.artist && (title == rhs.title) && (size < rhs.size))
      return true;

   return false;

}

bool Song::operator ==(Song const &rhs){
   return ((artist == rhs.artist) && (title == rhs.title) && (size == rhs.size));
}
