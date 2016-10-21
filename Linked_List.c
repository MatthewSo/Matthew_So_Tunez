/* John Park and Matthew So */
/* Period 4 */
/* Project 0: Tunez */
/* October 21, 2016 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Linked_List.h"

song_node * insert_front(char nname[256], char nartist[256], song_node *SN) {
  song_node * add = (song_node * )calloc(1,sizeof(song_node));
  strncpy(add->name, nname, 256);
  strncpy(add->artist, nartist, 256);
  add->next = SN;
  return add;
}

 void print_list( song_node * SN ) {
   printf("[ "); 
   while(SN) {
     printf("\t[%s] by %s,\n", SN->name, SN->artist) ; 
     SN = SN->next; 
  } 
   printf("]\n"); 
 }

 void print_single( song_node * SN ) {
   printf("[ ");
   if(SN){
     printf("\t[%s] by %s,\n", SN->name, SN->artist) ;}
   printf("]\n"); 
 } 


size_t length(song_node * SN) {
    int ret = 0;
    for (; SN != 0; SN = SN->next){
      ret+=1;
    }
    return ret;
}

song_node * find_artist(char nartist[256], song_node * SN) {
  for (; SN != 0; SN = SN->next) {
    if (strncmp(nartist, SN->artist, 256) == 0) {
    return SN;
    }
  }
  return 0;
}

song_node * find_name(char nname[256], song_node * SN) {
  for (; SN != 0; SN = SN->next) {
    if (strncmp(nname, SN->name, 256) == 0) {
    return SN;
    }
  }
  return 0;
}

song_node *random_node(song_node *SN) {
    int i  = rand()%length(SN);
    for (; i > 0; SN = SN->next) {
      i += -1;
    }
    return SN;
}

song_node * remove_song( char * name, char * artist, song_node * SN ){
  if( strcmp( SN->name, name ) == 0 && strcmp( SN->artist, artist ) == 0 ){
    song_node * temp1 = SN->next;
    return temp1;
  }
  else{
    song_node * temp = SN;
    while( temp->next ){
      if( strcmp( temp->next->name, name ) == 0 && strcmp( temp->next->artist, artist) == 0 ){
        song_node * temp2 = temp->next;
        temp->next = temp2->next;
        free(temp2);
        return SN;
      }
      temp = temp->next;
    }
    return SN;
  }
}

void free_list( song_node * SN ) {
  song_node *f = SN;
  while ( SN ) {
    SN = SN->next;
    printf("freeing node: %d\n", f->name );
    free(f);
    f = SN;    
  }
}


song_node *insert_inOrder( char * nname, char * nartist, song_node * SN){
  song_node * temp = SN;
  if (SN == 0) {
    return insert_front(nname,nartist,SN);
  }

  if (SN->next == 0) {
    if (strcmp(nartist,SN->artist) < 0 || (strcmp(nartist,SN->artist) == 0 && strcmp(nname,SN->name) < 0))
      SN = insert_front(nname,nartist,SN);
    else {
      SN->next = insert_front(nname,nartist,NULL);
    }
    return SN;
  }

  if (strcmp(nartist,SN->artist) < 0 || (strcmp(nartist,SN->artist) == 0 && strcmp(nname,SN->name) < 0)) {
    return insert_front(nname,nartist,SN);
  }
  while (SN->next) { 
    if (strcmp(nartist,SN->next->artist) < 0 || (strcmp(nartist,SN->next->artist) == 0 && strcmp(nname,SN->next->name) < 0)) {
      SN->next = insert_front(nname,nartist,SN->next);
      return temp;
    }
    SN = SN->next;
  }
  SN->next = insert_front(nname,nartist,NULL);
  return temp;
  
}
