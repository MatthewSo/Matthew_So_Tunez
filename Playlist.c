#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Playlist.h"

int getIndex(char c){
  if (c == 'a'){
    return 0;}
  if (c == 'b'){
    return 1;}
  if (c == 'c'){
    return 2;}
  if (c == 'd'){
    return 3;}
  if (c == 'e'){
    return 4;}
  if (c == 'f'){
    return 5;}
  if (c == 'g'){
    return 6;}
  if (c == 'h'){
    return 7;}
  if (c == 'i'){
    return 8;}
  if (c == 'j'){
    return 9;}
  if (c == 'k'){
    return 10;}
  if (c == 'l'){
    return 11;}
  if (c == 'm'){
    return 12;}
  if (c == 'n'){
    return 13;}
  if (c == 'o'){
    return 14;}
  if (c == 'p'){
    return 15;}
  if (c == 'q'){
    return 16;}
  if (c == 'r'){
    return 17;}
  if (c == 's'){
    return 18;}
  if (c == 't'){
    return 19;}
  if (c == 'u'){
    return 20;}
  if (c == 'v'){
    return 21;}
  if (c == 'w'){
    return 22;}
  if (c == 'x'){
    return 23;}
  if (c == 'y'){
    return 24;}
  if (c == 'a'){
    return 25;}
  else{
    return -1;}}
  


void add_song(table * t, char * nname, char * nartist) {
  int i = getIndex(nartist[0]);
  table[i] = insert_inOrder(nname, nartist, table[i]);
}

song_node * search_name(table * t, char * name){
  int i = 0;
  song_node * temp;
  for (;i<26;i++){
    temp = find_name(name, t[i]);
    if(temp > 0){
      return temp;}
  }
  return 0;
}

song_node *search_artist(table * t, char * artist) {
  int i = getIndex(artist[0]);
  return find_artist(artist, t[i]);
}

void print_letter(table * t, char c) {
  printf("All '%c' songs:", c);
  int i = getIndex(c);
  print_list(t[i]);
}

void print_library(table * t){
  printf("Showing full library:");
  char c = 'a';
  int i = 0;
  for (;i < 26; i++,c++){
    print_letter(t, c);}
}

void delete_song( table * t, char * name, char * artist){
  int i = 0;
  for(;i<26;i++){
    if( t[i] != 0 ){
      song_node * temp = remove_song( t[i], name, artist);
      t[i] = temp;
    }
  }
}

void delete( table * t ){
  int i =0;
  for(;i<26;i++){
    t[i] = free_list( t[i] );
  }
}
