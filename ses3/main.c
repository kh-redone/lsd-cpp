#include "./functions.c"

int main()
{
    int rd = open("functions.c", O_RDONLY);
    char * line = read_lines(rd);
    /*for ( int i=0 ; i<13 ;i++)
    {
        printf("%s",line);
        line = read_lines(rd);
    }*/

   while (line != NULL)
    {
        
        printf("%s",line);
        line = read_lines(rd);
    }
    return 0;
}
