#include "UtPod.h"

using namespace std;

UtPod::UtPod(){
   songs = NULL;
   memSize = MAX_MEMORY;
   srand(time(0));
}

UtPod::UtPod(int size){
   songs = NULL;
   if((size > MAX_MEMORY) || (size <= 0))
      memSize = MAX_MEMORY;
   else
      memSize = size;
   srand(time(0));
}

int UtPod::addSong(Song const &s){
   
}
