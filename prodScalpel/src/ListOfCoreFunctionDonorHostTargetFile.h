/* 
 * File:   ListOfCoreFunctionDonorTargetFile.h
 * Author: ---
 * Created on 30 August 2017, 6:12
 */

#ifndef LISTOFFUNCTIONSOURCEFILE_H
#define	LISTOFFUNCTIONSOURCEFILE_H

#ifdef	__cplusplus
extern "C" {
#endif

    struct listOfCoreFunctionDonorHostTargetFile {
        char * coreFunctionName;
        char * donorTargetFile;
        char * hostTargetFile;
        struct listOfCoreFunctionDonorTargetFile * next;
    };

    typedef struct listOfCoreFunctionDonorTargetFile ListOfCoreFunctionDonorTargetFile;

    void freeListOfCoreFunctionDonoHostTargetFile(ListOfCoreFunctionDonorTargetFile ** head);
    
    void addNewCoreFunctionDonorHostTargetFile(ListOfCoreFunctionDonorTargetFile ** head, char * functionName, char * sourceFile, char * hostTargetFile);
    
    int removeCoreFunctionDonorHostSourceFile(ListOfCoreFunctionDonorTargetFile ** head, char * functionName);
    
    void printAListOfCoreFunctionDonorHostTargetFile(ListOfCoreFunctionDonorTargetFile * head, char * outputFile);
    
    int searchForFunction(ListOfCoreFunctionDonorTargetFile * head, char * searchedFunctionName);
    
    int countElementsInListOfFunctionsSourceFile(ListOfCoreFunctionDonorTargetFile * head);


#ifdef	__cplusplus
}
#endif

#endif	/* LISTOFCOREFUNCTIONDONORTARGETFILE_H */

