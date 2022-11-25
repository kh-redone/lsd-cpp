#include "header.h"

// length_string return the number of elements in a string.
int length_string(string S)
{
    int n=0;
    while (S != NULL)
    {
        S=S->next;
        n++;
    }
    return n;
}

// add_string add a char at the end of a string
void add_string(char c, string* S)
{
    string * temp= S;
    string new_char = (string) malloc(sizeof(character));
    new_char->element=c;
    new_char->next=NULL;
    if (*S == NULL)
        *S=new_char;
    else
    {
        string  temp= *S;
        while (temp->next != NULL)
        {
            temp=temp->next;
        }
        temp->next=new_char;
    }
    return ;
}
// del_string delete the first element of a string
void del_string(string* S)
{
    if (*S != NULL)
    {
        string temp = *S;
        *S=(*S)->next;
        free(temp);
    }
    return;
}
char * read_lines(int rd)
{
    int found_n =0;
    int index_nextline; // index_next line will contain the index of the element in the string that is equal to '/n'
    static string S; // we define a static string so that the value of S doesn't change when we call the function more than one time.
    int l=length_string(S);
    while (found_n == 0)
    {
        int i=0;
        if (S != NULL)
        {
            string temp = S;
            while (temp != NULL)
            {
                if (temp->element == '\n')
                {
                    index_nextline = i;
                    found_n=1;
                    break;
                }
                temp=temp->next;
                i++;
            }
        }
        if ( S == NULL || i == length_string(S))
        {
            char * readable = malloc(BUFFER_SIZE+1);
            int nb_char = read(rd,readable,BUFFER_SIZE);
            readable[nb_char]='\0';
            l=length_string(S); // l contains the length of the actual string 
            int a=0;
            for (int i=0 ; i<nb_char ; i++)
            {
                add_string(readable[i],&S);
                if (readable[i] =='\n' && a==0 ) 
                    {
                        index_nextline =l+i; // the condition a=0 is seated so we can store into index_nextline the value of the index of the first  element in readable that equals to '/n'
                        found_n=1;
                        a=1;
                    }
            }
            /*
            upon the fact the fact that the end is reached in what concerns reading the file, we'll have to exit our while statement so we can print
            the next line considering that S is conatining the rest of characters that i need to print in the next line.
            */
            if (nb_char == 0)
                {
                    if (S != NULL)
                    {
                        index_nextline = length_string(S)-1;
                        found_n=1;
                    }
                    else return NULL;

                }
        }
    }
    // allocation of the memory for the variable result , and the range is index_nextline+2 because we need to keep a bit for '\n' and '\0
    char* result =(char*) malloc((index_nextline+2) * sizeof (char)); // result is the char* conatining the line we are going to return
    string temp=S;
    for (int i=0 ; i<index_nextline+1 ; i++)
    {
        result[i]=temp->element; // on stock result a partir du string S jusqua l'indice containing '/n'
        temp=temp->next;
        //printf("\n%d",i);
        del_string(&S); // we delete the first character that we stored in result soo in next call of the function S will contain just the characters of the next line (charcaters after the first '\n')
    }
    result[index_nextline+1]='\0';
    return result;
}
