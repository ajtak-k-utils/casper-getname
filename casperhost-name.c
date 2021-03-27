#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void writeFile(char *array){
    FILE *file = fopen("/etc/casperhost-name", "w");
    fputs(array, file);
    fclose(file); 
}

int main(void){
    int c, i, y;
    
    char keyboardArray[25] = "";;    
    char *r = keyboardArray;
    int counter = 0;

    for (i = 0; i < 11; i++){
        printf ("... Please wait .");
        for(y = 0; y < i; y++){
            printf (".");
        }
        printf ("\n");
        sleep (1);
    }

    printf("\n");
    printf("###########################################################\n");
    printf("####                                                   ####\n");
    printf("####          Welcome in Ubungu Autoinstaller          ####\n");
    printf("####                                                   ####\n");
    printf("###########################################################\n\n");

    system ("/bin/stty -g > casperhost-stty");
    system ("/bin/stty raw -echo >/dev/null 2>/dev/null");

    printf("\r\n\r\n");
    printf("Computer hostname: ");
    while((c = getchar())) {
        if(c == 0x0D || c == 0x0A || c == 13){
            break;
        } else if(c == 0x7F){
            for(;counter>0; counter--){
                *r-- = 0;
            }
            printf("\r\n -> Backspace preseed, enter again: ");
        } else {
            *r++ = c;
            ++counter;
            putchar(c);
        }
     }
    system ("/bin/stty $(cat casperhost-stty)");
    system ("rm casperhost-stty");

    printf("\n\n");
    printf("Setting hostname: %s ... Please wait...\n\n", keyboardArray);
    writeFile(keyboardArray);

    return 0;
}