/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    UtPod t;
    
    cout << "adding songs" << endl;

    Song s1("Artist 1", "Song 1", 4);
    int result = t.addSong(s1);
    cout << "add result = " << result << endl;
          
    Song s2("Artist 2", "Song 2", 5);
    result = t.addSong(s2);
    cout << "add result = " << result << endl;
    
    Song s3("Artist 3", "Song 3", 6);
    result = t.addSong(s3);
    cout << "add result = " << result << endl;
       
    Song s4("Artist 4", "Song 4", 7);
    result = t.addSong(s4);
    cout << "add result = " << result << endl;
       
    Song s5("Artist 5", "Song 5", 241);
    result = t.addSong(s5);
    cout << "add result = " << result << endl;

    t.showSongList();

    cout << endl << "===========================================" << endl;
    cout << "sort function" << endl;

    t.sortSongList();   
    t.showSongList();

    cout << endl << "===========================================" << endl;
    cout << "shuffle function" << endl;

    t.shuffle();
    t.showSongList();

    cout << endl << "===========================================" << endl;
       
    cout << "remove song 2" << endl;

    result = t.removeSong(s2);
    cout << "delete result = " << result << endl;

    t.showSongList();

    cout << endl << "===========================================" << endl;
    cout << "remove songs 1,4,5" << endl;

    result = t.removeSong(s1);
    cout << "delete result = " << result << endl;
 
    result = t.removeSong(s5);
    cout << "delete result = " << result << endl;
    
    result = t.removeSong(s4);
    cout << "delete result = " << result << endl;
       
    t.showSongList();

    cout << endl << "===========================================" << endl;
    cout << "remove nonexistent song" << endl;

    Song notInList("not in list", "don't add", 1);
    result = t.removeSong(notInList);
    cout << "delete result = " << result << endl;

    cout << endl << "===========================================" << endl;
    cout << "construct smaller UtPod and try to add song that won't fit" << endl;

    UtPod small(240);
    result = small.addSong(s5);
    cout << "add result = " << result << endl;

    cout << endl << "===========================================" << endl;
    cout << "clear UtPod" << endl;
 
    t.showSongList();
    t.clearMemory();
    t.showSongList();

/* 
   getRemainingMemory
   remove with two of the same song
   try sorting with one song
*/

    cout << endl << "===========================================" << endl;
    cout << "sort one song" << endl;
    
    t.addSong(s1);
    t.showSongList();
    t.sortSongList();
    t.showSongList();

    cout << endl << "===========================================" << endl;
    cout << "remove first of duplicate songs" << endl;
    
    t.addSong(s2);
    t.addSong(s1);
    t.showSongList();
    t.removeSong(s1);
    t.showSongList();

    cout << endl << "===========================================" << endl;
    cout << "clear UtPod, add Song 1 & show remaining memory" << endl;

    t.clearMemory();
    cout << "total memory = " << t.getTotalMemory() << endl;
    cout << "memory required for Song 1 = " << s1.getSize() << endl;
    t.addSong(s1);
    cout << "remaining memory = " << t.getRemainingMemory() << endl;

    cout << endl << "===========================================" << endl;
    cout << "shuffle one song" << endl;

    t.showSongList();
    t.shuffle();
    t.showSongList();

    cout << endl << "===========================================" << endl;
    cout << "edit Song 1 data" << endl;

    cout << "Song 1 title: " << s1.getTitle() << endl;
    cout << "Song 1 artist: " << s1.getArtist() << endl;
    cout << "Song 1 size: " << s1.getSize() << endl;

    s1.setTitle("Song 1A");
    s1.setArtist("Artist 1A");
    s1.setSize(15);

    cout << "Song 1 title: " << s1.getTitle() << endl;
    cout << "Song 1 artist: " << s1.getArtist() << endl;
    cout << "Song 1 size: " << s1.getSize() << endl;
}
