#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

// we are going to create a linked list string containg charachters.
struct character
{
    char element;
    struct character* next;

};
typedef struct character character;
typedef struct character* string;



// we are going to describe all the functions that we're going to use in the source file.

int length_string(string); //this function read a string(linked list) and return it's length
void write_string(string); // this function read a string and return a void but prints the contains of the string 
void add_string(char , string*); // this function add a char in the end of a string and returns void.
void del_string(string*); // this function delete teh first char of a string.
void free_string(string*);// this function will free the string.

int read_string(int,string*,int);// do same thing as function read but for string 
char * read_lines(int);
