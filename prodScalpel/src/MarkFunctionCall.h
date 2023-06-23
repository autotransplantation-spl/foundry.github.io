/* 
 * File:   MarkFunctionCalls.h
 * Author: ---
 *
 * Created on 01 July 2014, 01:37
 */

#ifndef MARKFUNCTIONCALLS_H
#define	MARKFUNCTIONCALLS_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include "FunctionCallDependency.h"
#include "DependencyList.h"
#include "FunctionCallDependency.h"
   
    
CallDependency * removeUnwantedFunctionsAndReturnCallDependencies(char * SkeletonFile, char * FinalSkeletonOut,
        DependencyList * ListOfDependenciesForStatements, char * outputDefinedFunctions, char * TXLTemporaryFolder);

void createListOfDonorFunctions(char * TXLProgsPath, char * listOfSourceFiles, char * outputFile);

void createListOfFileFunctions(char * directoryPah, char * TXLProgsPath, char * listOfSourceFiles, char * outputFile);

#ifdef	__cplusplus
}
#endif

#endif	/* MARKFUNCTIONCALLS_H */

