#include "DependencyListWithID.h"
#include "GenTrans.h"
#include "IndividualInstantiator.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <malloc.h>

void freeDependencyListWithID(DependencyListWithID ** head) {
    DependencyListWithID * aux;
    while (* head) {
        aux = *head;
        * head = (*head) -> next;
        freeListOfStrings(&(aux->ListOfDependencies));
        aux->ListOfDependencies = NULL;
        free(aux->Statement);
        free(aux->DependendID);
        aux->DependendID = NULL;
        aux->Statement = NULL;
        aux->next = NULL;
        free(aux);
        aux = NULL;
    }
    (* head) = NULL; //just in case...
}

DependencyListWithID * searchDependencyListWithIDForAnElement(DependencyListWithID * head, char * statement,
        char * dependendID) {
    DependencyListWithID * p;
    p = head;
    int s = 0;
    while (p && !s) {
        if (!strcmp(p->Statement, statement) && !strcmp(p->DependendID, dependendID)) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

void addNewStatementDependencyListWithID(DependencyListWithID ** head, char * statement,
        char * ID) {
    DependencyListWithID * newEl = (DependencyListWithID *) malloc(1 * sizeof (DependencyListWithID));
    newEl->Statement = (char *) malloc((strlen(statement) + 1) * sizeof (char));
    strcpy(newEl->Statement, statement);
    newEl->ListOfDependencies = NULL;
    newEl->next = NULL;
    
    newEl->DependendID = NULL;
    if(ID){
        newEl->DependendID = (char *) malloc ((strlen(ID) + 1) * sizeof(char));
        strcpy(newEl->DependendID, ID);
    }
    if (* head == NULL) {
        * head = newEl;
    } else {
        DependencyListWithID * p;
        p = *head;
        while (p ->next) {
            p = p->next;
        }
        p ->next = newEl;
    }
}

int addNewDependencyListWithID(DependencyListWithID ** head, char * statement, char * ID, 
        char * declaration) {
    DependencyListWithID * p;
    p = *head;
    int s = 0;
    while (p -> next && s == 0) {
        if (!strcmp(statement, p->Statement) && !strcmp(ID, p->DependendID)) {
            s = 1;
        } else {
            p = p->next;
        }
    }
    if (!strcmp(p->Statement, statement) && !strcmp(ID, p->DependendID)) {
        s = 1;
    }
    if (s == 0) {
        return 0;
    } else {
        addNewString(&(p->ListOfDependencies), declaration);
        return 1;
    }
}

void printADependencyListWithID(char * outputFile, DependencyListWithID * head) {
    FILE * fout = fopen(outputFile, "w");
    DependencyListWithID * p;
    p = head;
    while (p) {
        ListOfString * aux;
        aux = p->ListOfDependencies;
        fprintf(fout, "FUNCTION_NAME : \n%s\n", p->Statement);
        //not sure if it is case to print this
        fprintf(fout, "DEPENDEND_ID: \n %s\n", p->DependendID);
        fprintf(fout, "DECLARATION_LIST : \n");
        while (aux) {
            fprintf(fout, "%s\n", aux->el);
            aux = aux->next;
        }
        fprintf(fout, "%s", LINE_END);
        p = p ->next;
    }
    fclose(fout);
}

DependencyListWithID * readDependencyListWithIDFromFile(char * inputFile) {
    FILE * fin = fopen(inputFile, "r");
    char * line;
    line = (char *) malloc(800 * sizeof (char));
    DependencyListWithID * ListOfDeclarationsDependencies = NULL;
    char * currentStatement;
    currentStatement = (char*) malloc(800 * sizeof (char));
    while (fgets(line, 400, fin) != NULL) {
        fgets(line, 400, fin);
        //sscanf(line, "%s", currentStatement);
        char * dependendID;
        dependendID = (char *) malloc (500 * sizeof(char));
        
        char * token = strtok(line, "@");
        strcpy(currentStatement, token);
        currentStatement[strlen(currentStatement) - 1] = 0;
        
        
        token = strtok(NULL, "@");
        sscanf(token, "%s", dependendID);

        
        addNewStatementDependencyListWithID(&ListOfDeclarationsDependencies, currentStatement, dependendID);
        int s = 0;
        fgets(line, 400, fin);
        while (s == 0 && fgets(line, 400, fin) != NULL) {
            if (!strcmp(line, LINE_END)) {
                s = 1;
            } else {
                strtok(line, "\n");
                addNewDependencyListWithID(&ListOfDeclarationsDependencies, currentStatement, dependendID, line);
            }
        }
    }
    free(line);
    free(currentStatement);
    fclose(fin);
    return ListOfDeclarationsDependencies;
}

ListOfString * returnDependencyListWithIDForAMarkerNewPointers(DependencyListWithID * head,
        char * ID, char ** dependencyLineMarker) {
    ListOfString * dependencyListForMarker = NULL;
    int signal = 0;
    while (head && !signal) {
        if ( strstr(ID, head->DependendID)/* !strcmp(head->DependendID, ID)*/) {
            signal = 1;
        } else {
            head = head->next;
        }
    }
    if (signal) {
        free(*dependencyLineMarker);
        *dependencyLineMarker = (char *) malloc ((sizeof(head->Statement) + 1) * sizeof(char));
        strcpy(*dependencyLineMarker, head->Statement);
        dependencyListForMarker = copyCompleteListOfString(head->ListOfDependencies);
    }
    return dependencyListForMarker;
}

void addDependencyListWithIDToAnExistingOne(DependencyListWithID ** destination, DependencyListWithID * source) {
    DependencyListWithID * auxSource = source;
    while (auxSource) {
        addNewStatementDependencyListWithID(&(*destination), auxSource->Statement, auxSource->DependendID);

        ListOfString * auxDep = auxSource->ListOfDependencies;

        while (auxDep) {
            addNewDependencyListWithID(&(*destination), auxSource->Statement, auxSource->DependendID, auxDep->el);
            auxDep = auxDep->next;
        }
        auxSource = auxSource->next;
    }
}


DependencyListWithID * copyDependencyListWithID(DependencyListWithID * initial){
	DependencyListWithID * newDepList = NULL;
	addDependencyListWithIDToAnExistingOne(&newDepList, initial);
	return newDepList;
}


void createListOfDependencyListWithIDForDonorAbstractMappings(char * graftWithHostVarInstantiated,
        char * neededMarkersFile,
        char * outputFile, char * TXLProgsPath) {
    char * commandTXL;
    commandTXL = (char *) malloc(1000 * sizeof (char));
    printf("\t\t[TXL] GenerateDeclarationDependenciesForDonorVariablesInAbstractMappings.x >> Generate Declaration Dependencies For Donor Variables In Abstract Mappings\n");
    sprintf(commandTXL, "ulimit -s 65353 && %sGenerateDeclarationDependenciesForDonorVariablesInAbstractMappings.x %s %s %s %s",
            TXLProgsPath, graftWithHostVarInstantiated, neededMarkersFile,
            outputFile, ConsoleNullOutput);
    int status = system(commandTXL);
    fflush(stdout);
    if (status != 0) {
        printf("ERROR! GenerateDeclarationDependenciesForDonorVariablesInAbstractMappings.x \n");
        printf("\t%s\n", commandTXL);
        system("open ErrorFile.out");
        exit(1);
    }
#ifdef DEBUGING
    else
        printf("\t\t\t|>> temp_dependencies_for_abstract.out\n");
#endif
    free(commandTXL);
}

DependencyListWithID * dependencyListWithIDForDeclWithAbstractValues(Mapping * ListOfMappingsFromCurrentDonor,
        ListOfString * FinalSkeletonSourceCode, ListOfString * ListOfMarkersForAbstractVariables,
		char * TXLTemporaryFolder) {
    printf("\tGenerating dependency list with id for declaration with abstract values\n");
	// BUG: Dependency list is not constructed according the new unique local var names
	// TODO: fix this!!!

    char * tempMappingsFileAbstractNeededDependnecies = (char *) malloc(100 * sizeof (char));
    sprintf(tempMappingsFileAbstractNeededDependnecies, "%stemp_mapping_file_abstract_dependencies.out", TXLTemporaryFolder);

    char * tempSkeletonFile = (char *) malloc(100 * sizeof (char));
    sprintf(tempSkeletonFile, "%stemp_skeleton_for_abstract_dependencies.out", TXLTemporaryFolder);
#ifdef DEBUGING
    printf("\t\t|>> temp_skeleton_for_abstract_dependencies.out\n");
#endif
    printAListOfStrings(FinalSkeletonSourceCode, tempSkeletonFile);

    char * tempSkeletonFileWithAllIdsFromGraftInstantiated = (char *) malloc(100 * sizeof (char));
    sprintf(tempSkeletonFileWithAllIdsFromGraftInstantiated, "%stemp_skeleton_with_all_ids_from_donor.out", TXLTemporaryFolder);

    char * tempFileWithMarkersForAbstractIDs = (char *) malloc(100 * sizeof (char));
    sprintf(tempFileWithMarkersForAbstractIDs, "%stemp_list_of_markers_for_abstract_ids.out", TXLTemporaryFolder);
#ifdef DEBUGING
    printf("\t\t|>> temp_list_of_markers_for_abstract_ids.out\n");
#endif
    printAListOfMappingsStringlit(ListOfMappingsFromCurrentDonor, tempMappingsFileAbstractNeededDependnecies);

    ListOfString * skeletonInstantiatedWithAbstractFromDonor = instantiateCurrentIndividualInSkeleton
            (tempSkeletonFile, tempMappingsFileAbstractNeededDependnecies, TXLTemporaryFolder);
    ListOfString  * skeletonInstantiatedWithAbstractFromDonorOnlyDecl = NULL;

    ///printAListOfStrings(skeletonInstantiatedWithAbstractFromDonor, tempSkeletonFileWithAllIdsFromGraftInstantiated);
    addNewString(&skeletonInstantiatedWithAbstractFromDonorOnlyDecl, skeletonInstantiatedWithAbstractFromDonor->el);
    while(skeletonInstantiatedWithAbstractFromDonor->next){
        if(strstr(skeletonInstantiatedWithAbstractFromDonor->el, "/* DECL:") || strstr(skeletonInstantiatedWithAbstractFromDonor->el, "//Mappings for function:"))
            addNewString(&skeletonInstantiatedWithAbstractFromDonorOnlyDecl, skeletonInstantiatedWithAbstractFromDonor->el);

        skeletonInstantiatedWithAbstractFromDonor = skeletonInstantiatedWithAbstractFromDonor->next;
    }
    addNewString(&skeletonInstantiatedWithAbstractFromDonorOnlyDecl, skeletonInstantiatedWithAbstractFromDonor->el);
    printAListOfStrings(skeletonInstantiatedWithAbstractFromDonorOnlyDecl, tempSkeletonFileWithAllIdsFromGraftInstantiated);
#ifdef DEBUGING
    printf("\t\t|>> temp_list_of_markers_for_abstract_ids.out\n");
#endif
    printAListOfStringsWithSpaces(ListOfMarkersForAbstractVariables, tempFileWithMarkersForAbstractIDs);
#ifdef DEBUGING
    printf("\t\t|>> temp_skeleton_with_all_ids_from_donor.out\n");
#endif
    fflush(stdout);

    char * tempOutputFileNeededDependenciesForAbstract;
    tempOutputFileNeededDependenciesForAbstract = (char *) malloc(500 * sizeof (char));
    sprintf(tempOutputFileNeededDependenciesForAbstract, "%stemp_dependencies_for_abstract.out", TXLTemporaryFolder);

#ifdef GENERATE_DECLARATION_DEPENDENCIES_FOR_DONOR_VARIABLE_IN_ABSTRACT_MAPPINGS
    printf("\tCreate list of dependency list with ID for Donor abstract mappings\n");
    createListOfDependencyListWithIDForDonorAbstractMappings(tempSkeletonFileWithAllIdsFromGraftInstantiated,
            tempFileWithMarkersForAbstractIDs, tempOutputFileNeededDependenciesForAbstract, TXLToolsPath);
#endif
    fflush(stdout);
    
    DependencyListWithID * dependencyListForAbstract = NULL;

    dependencyListForAbstract = readDependencyListWithIDFromFile(tempOutputFileNeededDependenciesForAbstract);

    fflush(stdout);
    return dependencyListForAbstract;
}
