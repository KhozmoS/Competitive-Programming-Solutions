#include <string.h>
#include <stdio.h>
#include <ctype.h>
char cad[1000], *ptr;int r;
int main() {
    gets(cad);
    while (cad[0] != '*') {
        ptr = strtok(cad, " ");r = 0;
        while (((ptr = strtok(NULL, " ")) != NULL) && !r) 
            if (toupper(ptr[0]) != toupper(cad[0])) r = 1;
        printf("%c\n", !r ? 'Y':'N');
        gets(cad);
    }
}