/* 
 * File:   Skeleton.h
 * Author: ---
 *
 * Created on 19 June 2014, 00:44
 */

#ifndef SKELETON_H
#define	SKELETON_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "Mapping.h"
#include "DependencyList.h"
#include "SymbolTable.h"


    void instantiateGraftSkeletonInInterface(ListOfString * Skeleton, char * InterfaceSourceCode,
            char * finalHostInterfaceOutput, char * headerFileForCoreFeature);

    Mapping * createGraftSkeleton(char * transformedFctLOCs, char * instantiatonMappings, char * TXLPath, char * skeletonOutput,
            char * existingMappings, char * temporaryFolder, char * HostSymbolTableFile,
            SymbolTable ** FinalGraftSymbolTable, DependencyList ** GraftStatementsDependencies,
    		ListOfString * reverseCallGraph, char * TXLTemporaryFolder);

    void fixLineNumbers(ListOfString * element);
    
    void createDependencyList(char * TXLPath, char * skeletonOutput, char * dependencyListOutput);

#ifdef	__cplusplus
}
#endif

#endif	/* SKELETON_H */

