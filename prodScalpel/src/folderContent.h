/* 
 * File:   folderContent.h
 * Author: ---
 *
 * Created on 18 June 2014, 23:47
 *
 * Edited by --- on 14 January 2018, 22:54
 *   - Added functions: generateCallGraphs, renameFileToFunctionName, removeAllFilesFromADirectory,
 *   removeSpecificTypeOfFileFromDirectory, copySpecificFilesFromADirToAnother and copyFilesFromADirToAnother
 */

#ifndef FOLDERCONTENT_H
#define	FOLDERCONTENT_H

#include "ListOfString.h"
#ifdef	__cplusplus
extern "C" {
#endif
    void readFilesFromDirWithFormat(char * path, FILE * fout, char * endChar);
    void renameFileToFunctionName( char * path, char * fileType);
    void readFilesFromDir (char * path, FILE * fout, char endChar);
    void readFilesNameFromDir(char * path, FILE * fout, char endChar);
    void readFilesFromDirWithOutQuotationMarks(char * path, FILE * fout, char endChar);

    int isInListOfNeededFiles(char ** listOfFiles, int length, char * currentFile);
    int copyFilesFromADirToAnother(char * src, char * dest);
    int removeAllFilesFromADirectory(char * dirPath);
    int removeAFileFromADirectory(char * filePath);
    int removeSpecificTypeOfFileFromDirectory(char * dirPath, char * fileType);
    int copySpecificFilesFromADirToAnother(char * src, char * dest, char * fileType );
    int file_exists(char * filename);
    int removeFilesTempDoxygenAutoScalpelDirectory(char * dirPath);
    int isDirectory(const char* name);
    int copyFilesFromDir(char * src, char * dest, char * fileType );
    int recursiveDelete(char* dirname);

    void countFunctionFilesFromDir(char * path, FILE * fout, char * endChar);
    void addANewStringLNInTheEndFile(char* inString, char * outputFile);
    void addAStringsInTheEndFile(char* inString, char * outputFile);
    void addAStringsInTheFile(char* inString, char * outputFile) ;
    void addAStringsInTheEndFileLN(char* inString, char * outputFile);

    void createFile(char * outputFile);
    void clearFile(const char *filename);
    void createADirectory(char *outputFolder);

    int isDirectoryExists(const char *path);
    int isDirectoryEmpty(char *dirname);

    ListOfString * getListOfFilesFromDir(char * directory, char * temporaryFolder);
    int ASTIsEqual(char * sourceFileASTFromOrgan, char * sourceFileASTFromHost);
    int diffIsStatic(char * sourceFileASTFromOrgan, char * sourceFileASTFromHost);
    int mergeElements( char * mergeResultFile, char * sourceFileASTFromOrgan, char * sourceFileASTFromHost, char * organIFDEFMarker);
    void openFileInAppendMode(char * outputFile);
    void addAStringsInTheExitingFileLN(char* inString, char * outputFile);

    int copyAFileFromDirToOther(char * src, char * dest);
    int copyAFilesToAnotherAtBegging(char * src, char * dest);
    void printListOfFunctionNameInADirectory(char * sourceDirectory, char * outputListOfSourceFilesFromDonor, char type );

#ifdef	__cplusplus
}
#endif

#endif	/* FOLDERCONTENT_H */

