#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Affiche l'aide du programme
void printHelp(char * prgName) {
    printf("%s\n", prgName);
    printf(" Displays the content of a txt or binary file\n");
    printf(" Usage:\n");
    printf(" %s <opt> <fileName> (<nb>)\n", prgName);
    printf(" where:\n");
    printf(" <opt> is either '-txt' or '-bin' (txt or bin file).\n");
    printf(" <fileName> is the name of the file to display.\n");
    printf(" <nb> is the number of display to achieve.\n");
    printf(" Optinal, default 1.\n");
}
// Affiche l'erreur errStr, puis l'aide du programme
void printError(char * prgName, char * errStr) {
    printf("Error : '%s'\n", errStr);
    printHelp(prgName);
}
int main(int argc, char *argv[]){
    int mode ; // 0 => txt ; 1 => binary
    char *fileName = NULL;
    FILE * filePtr = NULL;
    int nbDisplay = 1;
    int i;
    ///////
    // parsing des arguments
    ///////
    if(argc < 3 || argc > 4) {
        printError( argv[0], "number of args invalid" );
        return EXIT_FAILURE;
    }
    // affichage aide
    if( strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "-help") == 0) {
        printHelp(argv[0]);
        return EXIT_SUCCESS;
    }
    // type de fichier
    if( strcmp(argv[1], "-txt") == 0) {
        mode = 0;
    } else if( strcmp(argv[1], "-bin") == 0) {
        mode = 1;
    } else {
        printError( argv[0], "-txt or -bin required" );
        exit(EXIT_FAILURE); // equivalent a return EXIT_FAILURE;
    }
    // nom du fichier
    fileName = argv[2];
    
    // entier
    if(argc == 4) {
        // on attend un entier !
    if( sscanf(argv[3], "%d", &nbDisplay) != 1) {
        printError( argv[0], "Integer awaited" );
        exit(EXIT_FAILURE); // equivalent a return EXIT_FAILURE;
    }
}
///////
// c'est parti !
///////
switch(mode) {
    case 0:
        filePtr = fopen (fileName, "rt");
    break;
    case 1:
        filePtr = fopen (fileName, "rb");
    break;
}
if(filePtr == NULL) {
    printError( argv[0], "Cannot open file" );
    exit(EXIT_FAILURE); // equivalent a return EXIT_FAILURE;
}
for(i = 0 ; i < nbDisplay ; i ++) {
    switch(mode) {
    case 0:
        // displayTxtFile(filePtr);
        // fct supposee existante
        break;
    case 1:
        // displayBinFile(filePtr);
        // fct supposee existante
        break;
    }
    }
    
    fclose(filePtr);
    return EXIT_SUCCESS;
}
