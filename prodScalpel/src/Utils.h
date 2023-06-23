/* 
 * File:   Utils.h
 * Author: ---
 *
 * Created on 27 June 2014, 18:56
 *
 * Changed by --- on 11 January 2018, 18:04
 *      Added function: redeSubstring(...);
 */

#ifndef UTILS_H
#define	UTILS_H

#ifdef	__cplusplus
extern "C" {
#endif

    /*BEGGING STACK CODE*/

    struct Stack {// A structure to represent a stack
        int top;
        unsigned capacity;
        int* array;
    };
    struct Stack* createAStack(unsigned capacity);
    int isEmpty(struct Stack* stack);
    void push(struct Stack* stack, int item);
    int pop(struct Stack* stack);
    int peek(struct Stack* stack);
    /*END STACK*/

    int isInListOfNeededFiles(char ** listOfFiles, int length, char * currentFile);

    void readDirContent(char * path, char** listOfNeededHeaderFiles, int length, char * outputFolder);

    void copyNeededFiles(char * listOfNeededIncludeFiles, char * pathToDonor, char * transplantWorkingFolder,
            char * locationToCopyFiles);

    void prettyPrintSourceCode(char * TXLProgsPath, char * tempSkeleton, char * finalSkeleton);
    
    void prettyPrintSourceCodeNoAnnotations(char * TXLProgsPath, char * source, char * destination);

    int countlines(char *filename);

    void addLinesFromTempIntoDestinationFile(char * tempFileSource, char  * istDestination);

    int isInListOfExtractedFunctions(char * listOfFiles, char * currentFile);

    int isInFile(char * search, char * currentFilePath);

    int fileExists(const char* filename);

    char * readSubstring( const char *p1, const char *str, const char *p2);

    static void removeSpecialCharacter(char *data);

    int isValidFuncitonName(char *data);

    int isInListOfNeededFunctions(char ** listOfFunctionsTarget, char * currentFile);

    int get_size(const char* file_name);

    char * removeSpaceInString(char * str);

    void removeFirst(char * str, const char * toRemove);

    char * getTime();
#ifdef	__cplusplus
}
#endif

#endif	/* UTILS_H */

