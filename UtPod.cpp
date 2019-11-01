#include "UtPod.h"

using namespace std;

UtPod::UtPod(){
   songs = NULL;
   memSize = MAX_MEMORY;
}

UtPod::UtPod(int size){
   songs = NULL;
   if((size > MAX_MEMORY) || (size <= 0))
      memSize = MAX_MEMORY;
   else
      memSize = size;
}

int UtPod::addSong(Song const &s){
   if((getRemainingMemory() - s.getSize()) <= 0)
     return NO_MEMORY;
   
   SongNode *temp = new SongNode;
   temp->s = s;
   temp->next = songs;
   songs = temp;
   
   return SUCCESS;
}

int UtPod::removeSong(Song const &s){
   SongNode *current = songs;

   if(songs->s == s){ 
      songs = songs->next;
      delete current;
cout<<"remove"<<endl;
      return SUCCESS;
   }
   
   while(current->next != NULL){
      if(current->next->s == s){
         SongNode *match = current->next;
         current->next = current->next->next;
         delete match;
         return SUCCESS;
      }

      else{
         current = current->next;
      }   
   }

   return NOT_FOUND;
}

void UtPod::shuffle(){
   int listLength = numSongs();
   if(listLength < 2)
      return;

   srand(time(0));
   SongNode *song1 = songs;
   SongNode *song2 = songs;

   for(int i=0; i<rand(); i++){
      for(int j=0; j<(rand() % listLength); j++){
         song1 = song1->next;
      }
      song1->s.swap(song2->s);
      song2 = song1;
      song1 = songs;
   }
}

void UtPod::showSongList(){
   SongNode *current = songs;
   while(current != NULL){
      cout << current->s.getTitle() << ", "
         << current->s.getArtist() << ", "
         << current->s.getSize() << "MB" << endl;

      current = current->next;
   }
   cout << "END OF LIST"  << endl;
}

void UtPod::sortSongList(){
   for(SongNode *p1 = songs; p1->next != NULL; p1 = p1->next){
      SongNode *min = p1;
      for(SongNode *p2 = songs->next; p2 != NULL; p2 = p2->next){
         if(p2->s < min->s)
            min = p2;
      }
      p1->s.swap(min->s);
   }
}

void UtPod::clearMemory(){
   SongNode *current = songs;
   
   while(current != NULL){
      removeSong(current->s);
      current = current->next;
   }
}

int UtPod::numSongs(){
   int total = 0;
   if(songs == NULL)
      return total;

   SongNode *current = songs;
   while(current != NULL){
      total++;
      current = current->next;
   }

   return total;
}

int UtPod::getRemainingMemory(){ //remain = memSize - total memory taken by songs
   int remain = getTotalMemory();
   SongNode *current = songs;
   while(current != NULL){
      remain -= current->s.getSize();
      current = current->next;
   }
   return remain;
}

UtPod::~UtPod(){
   clearMemory();
   delete songs;
}
