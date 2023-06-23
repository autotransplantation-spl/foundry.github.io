#include "DependencyList.h"
#include "GenTrans.h"
#include "IndividualInstantiator.h"
#include "Utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <malloc.h>

void freeDependencyList(DependencyList ** head) {
    DependencyList * aux;
    while (* head) {
        aux = *head;
        * head = (*head) -> next;
        freeListOfStrings(&(aux->ListOfDependencies));
        aux->ListOfDependencies = NULL;
        free(aux->Statement);
        aux->Statement = NULL;
        aux->next = NULL;
        free(aux);
        aux = NULL;
    }
    (* head) = NULL; //just in case...
}

DependencyList * searchDependenciesForAnElement(DependencyList * head, char * statement) {
    DependencyList * p;
    p = head;
    int s = 0;
    while (p && !s) {
        if (!strcmp(p->Statement, statement)) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

char * searchDependencies(ListOfString * head, char * depend) {
    ListOfString * p;
    p = head;
    while (p) {
        if (!strcmp(p->el, depend)) {
            return p->el;
        }
        p = p->next;
    }
    return NULL;
}

void addNewStatement(DependencyList ** head, char * statement) {
    DependencyList * newEl = (DependencyList *) malloc(1 * sizeof (DependencyList));
    newEl->Statement = (char *) malloc(1000 * sizeof (char));
    strcpy(newEl->Statement, statement);
    newEl->visited = 0;
    newEl->ListOfDependencies = NULL;
    newEl->next = NULL;
    if (* head == NULL) {
        * head = newEl;
    } else {
        DependencyList * p;
        p = *head;
        while (p ->next) {
            p = p->next;
        }
        p ->next = newEl;
    }
}

int searchStatment(DependencyList ** head, char * statement) {
    DependencyList * p;
    p = *head;
    int s = 0;
    while (p -> next && s == 0) {
        if (!strcmp(statement, p->Statement)) {
             return 1;
        } else {
            p = p->next;
        }
    }
    return 0;
}


int addNewDependency(DependencyList ** head, char * statement, char * declaration) {
    DependencyList * p;
    p = *head;
    int s = 0;
    while (p -> next && s == 0) {
        if (!strcmp(statement, p->Statement)) {
            s = 1;
        } else {
            p = p->next;
        }
    }
    if (!strcmp(p->Statement, statement)) {
        s = 1;
    }
    if (s == 0) {
        return 0;
    } else {
        addNewString(&(p->ListOfDependencies), declaration);
        return 1;
    }
}


int addNewDependencyInExistingOne(DependencyList ** head, char * statement, char * declaration) {
    DependencyList * p;
    p = *head;
    int s = 0, d = 0;
    while (p -> next && s == 0) {
        if (!strcmp(statement, p->Statement)) {
            s = 1;
        } else {
            p = p->next;
        }
    }
    if (!strcmp(p->Statement, statement)) {
        s = 1;
    }
    ListOfString * currentDependencies = p->ListOfDependencies;
    while(currentDependencies && d == 0){

        if(declaration!=NULL)
            if(!strcmp(currentDependencies->el, declaration))
                d = 1;
       // if(!strncmp(declaration ,p->ListOfDependencies->el,strlen(declaration)))
        //if(strstr(p->ListOfDependencies->el, declaration))

        currentDependencies = currentDependencies->next;
    }
    if (s == 0 || d == 1) {
        return 0;
    } else {
        addNewString(&(p->ListOfDependencies), declaration);
        return 1;
    }
}

int addNewDependencyInExistingStatment(DependencyList ** head, char * statement, ListOfString *sourceDep) {
    DependencyList * p;
    p = *head;
    int s = 0;
    while (p -> next && s == 0) {
        if (!strcmp(statement, p->Statement)) {
            s = 1;
        } else {
            p = p->next;
        }
    }

    if (s == 0) {
        return 0;
    }

    ListOfString * auxSourceDepList = sourceDep;
    char * newDependence = NULL;
    while(auxSourceDepList ){
        newDependence = searchDependencies(p->ListOfDependencies, auxSourceDepList->el );
        if (newDependence == NULL) {
            addNewString(&(p->ListOfDependencies),  auxSourceDepList->el);
        }
        free(newDependence);
        auxSourceDepList = auxSourceDepList->next;
    }

    return 1;
}

void printADependencyList( DependencyList * head, char * outputFile) {
    FILE * fout = fopen(outputFile, "w");
    DependencyList * p;
    p = head;
    while (p) {
        ListOfString * aux;
        aux = p->ListOfDependencies;
        fprintf(fout, "FUNCTION_NAME : \n%s\n", p->Statement);
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

DependencyList * copyDependencyList (DependencyList * initial){
	DependencyList * newDepList = NULL;
	DependencyList * aux = initial;
	while(aux){

		addNewStatement(&newDepList, aux->Statement);
		ListOfString * auxListOfStr = aux->ListOfDependencies;
		while(auxListOfStr){

			addNewDependency(&newDepList, aux->Statement, auxListOfStr->el);
			auxListOfStr = auxListOfStr->next;
		}

		aux = aux->next;
	}


	return newDepList;
}
// TODO  reduce var size  look at temp_global_dependecies.out
DependencyList * readDependencyListFromFile(char * inputFile) {
    FILE * fin = fopen(inputFile, "r");
    if (fin == NULL) {
        printf("[ERROR] %s not found%s.\n", inputFile);
        exit(1);
    }
    char * line;
    //char * initialLine;
    line = (char *) malloc(100000 * sizeof (char));
    //initialLine = line;
    DependencyList * ListOfDeclarationsDependencies = NULL;
    char * currentStatement;
    currentStatement = (char*) malloc(10000 * sizeof (char));
    while (fgets(line, 99999, fin) != NULL) {
        fgets(line, 99999, fin);
        //sscanf(line, "%s", currentStatement);
        strtok(line, "\n");
        strcpy(currentStatement, line);
        addNewStatement(&ListOfDeclarationsDependencies, currentStatement);
        int s = 0;
        fgets(line, 99999, fin);
        while (s == 0 && fgets(line, 9999, fin) != NULL) {
            if (!strcmp(line, LINE_END)) {
                s = 1;
            } else {
                strtok(line, "\n");
                addNewDependency(&ListOfDeclarationsDependencies, currentStatement, line);
            }
        }


        //line = initialLine;
    }

    free(line);
    free(currentStatement);
    fclose(fin);
    return ListOfDeclarationsDependencies;
}



DependencyList * readVarUnionDependencyListFromFile(char * inputFile) {
    FILE * fin = fopen(inputFile, "r");
    char * line;
    //char * initialLine;
    line = (char *) malloc(100000 * sizeof (char));
    //initialLine = line;
    DependencyList * ListOfDeclarationsDependencies = NULL;
    char * currentStatement;
    currentStatement = (char*) malloc(10000 * sizeof (char));
    while (fgets(line, 99999, fin) != NULL) {
        fgets(line, 99999, fin);
        //sscanf(line, "%s", currentStatement);
        strtok(line, "\n");
        strcpy(currentStatement, line);
        addNewStatement(&ListOfDeclarationsDependencies, currentStatement);
        int s = 0;
        fgets(line, 99999, fin);
        while (s == 0 && fgets(line, 99999, fin) != NULL) {
            if (!strcmp(line, LINE_END)) {
                s = 1;
            } else {
                strtok(line, "\n");
                addNewDependency(&ListOfDeclarationsDependencies, currentStatement, line);
            }
        }


        //line = initialLine;
    }
    free(line);
    free(currentStatement);
    fclose(fin);
    return ListOfDeclarationsDependencies;
}

ListOfString * returnDependencyForAMarkerNewPointers(DependencyList * head, char * marker) {
    ListOfString * dependencyListForMarker = NULL;
    int signal = 0;
    while (head && !signal) {
        if (!strcmp(head->Statement, marker)) {
            signal = 1;
        } else {
            head = head->next;
        }
    }
    if (signal) {
        dependencyListForMarker = copyCompleteListOfString(head->ListOfDependencies);
    }
    return dependencyListForMarker;
}

void setDependencyStatmentVisited(DependencyList * head, char * marker) {
    ListOfString * dependencyListForMarker = NULL;
    int signal = 0;
    while (head && !signal) {
        if (!strcmp(head->Statement, marker)) {
            signal = 1;
        } else {
            head = head->next;
        }
    }
    if (signal)
        head->visited = 1;
   //  else
     //   head->visited = 0;

}
/*
void setDependencyStatmentVisited(DependencyList ** head, char * marker) {
    ListOfString * dependencyListForMarker = NULL;
    int signal = 0;
    while ((*head) && !signal) {
        if (!strcmp((*head)->Statement, marker)) {
            signal = 1;
        } else {
            (*head) = (*head)->next;
        }
    }
    if (signal) {
        (*head)->visited = 1;
    }
}*/

int getDependencyStatmentVisited(DependencyList * head, char * marker) {
    ListOfString * dependencyListForMarker = NULL;
    int signal = 0;
    while (head && !signal) {
        if (!strcmp(head->Statement, marker)) {
            signal = 1;
        } else {
            head = head->next;
        }
    }
    if (signal) {
        return   head->visited;
    }
}
/*
void addDependencyListToAnExistingOne(DependencyList ** destination, DependencyList * source) {
    DependencyList * auxSource = source;
    while (auxSource) {
        addNewStatement(&(*destination), auxSource->Statement);

        ListOfString * auxDep = auxSource->ListOfDependencies;

        while (auxDep) {
            addNewDependency(&(*destination), auxSource->Statement, auxDep->el);
            auxDep = auxDep->next;
        }
        auxSource = auxSource->next;
    }
}*/

void addDependencyListToAnExistingOne(DependencyList ** destination, DependencyList * source) {
    DependencyList * auxSource = source;
    DependencyList * auxDestination = NULL;
    while (auxSource) {
        auxDestination = searchDependenciesForAnElement(*destination, auxSource->Statement);
        if(auxDestination == NULL){
            addNewStatement(&(*destination), auxSource->Statement);
            ListOfString * auxDep = auxSource->ListOfDependencies;
            while (auxDep) {
                addNewDependencyInExistingOne(&(*destination), auxSource->Statement, auxDep->el);
                auxDep = auxDep->next;
            }
        } else {
            ListOfString * auxDep = auxSource->ListOfDependencies;
            while (auxDep) {
                addNewDependencyInExistingOne(&(*destination), auxSource->Statement, auxDep->el);
                auxDep = auxDep->next;
            }
           // addNewDependencyInExistingStatment(&(*destination), auxSource->Statement, auxDep);
        }
        auxSource = auxSource->next;
    }

    fflush(stdout);
}



void createListOfDependenciesForDonorAbstractMappings(char * graftWithHostVarInstantiated, char * neededMarkersFile,
        char * outputFile, char * TXLProgsPath) {
    char * commandTXL;
    commandTXL = (char *) malloc(1000 * sizeof (char));
    printf("[TXL] GenerateDeclarationDependenciesForDonorVariablesInAbstractMappings.x >> Generate Declaration Dependencies For Donor Variables In Abstract Mappings \n");
    sprintf(commandTXL, "%sGenerateDeclarationDependenciesForDonorVariablesInAbstractMappings.x %s %s %s %s",
            TXLProgsPath, graftWithHostVarInstantiated, neededMarkersFile,
            outputFile, ConsoleStderrOutput);
    int status = system(commandTXL);
    if (status != 0) {
        printf("ERROR! sGenerateDeclarationDependenciesForDonorVariablesInAbstractMappings.x\n");
        printf("\t%s\n", commandTXL);
        exit(1);
    }
    free(commandTXL);
}

DependencyList * dependencyListForDeclWithAbstractValues(Mapping * ListOfMappingsFromCurrentDonor,
        ListOfString * FinalSkeletonSourceCode, ListOfString * ListOfMarkersForAbstractVariables,
		char * TXLTemporaryFolder) {
    char * tempMappingsFileAbstractNeededDependnecies;
    tempMappingsFileAbstractNeededDependnecies = (char *) malloc(500 * sizeof (char));
    sprintf(tempMappingsFileAbstractNeededDependnecies, "%stemp_mapping_file_abstract_dependencies.out", TXLTemporaryFolder);

    char * tempSkeletonFile;
    tempSkeletonFile = (char *) malloc(500 * sizeof (char));
    sprintf(tempSkeletonFile, "%stemp_skeleton_for_abstract_dependencies.out", TXLTemporaryFolder);

    char * tempSkeletonFileWithAllIdsFromGraftInstantiated;
    tempSkeletonFileWithAllIdsFromGraftInstantiated = (char *) malloc(500 * sizeof (char));
    sprintf(tempSkeletonFileWithAllIdsFromGraftInstantiated, "%stemp_skeleton_with_all_ids_from_donor.out", TXLTemporaryFolder);

    char * tempFileWithMarkersForAbstractIDs;
    tempFileWithMarkersForAbstractIDs = (char *) malloc(500 * sizeof (char));
    sprintf(tempFileWithMarkersForAbstractIDs, "%stemp_list_of_markers_for_abstract_ids.out", TXLTemporaryFolder);


    printAListOfMappingsStringlit(ListOfMappingsFromCurrentDonor, tempMappingsFileAbstractNeededDependnecies);
    printAListOfStrings(FinalSkeletonSourceCode, tempSkeletonFile);


    ListOfString * skeletonInstantiatedWithAbstractFromDonor = instantiateCurrentIndividualInSkeleton
            (tempSkeletonFile, tempMappingsFileAbstractNeededDependnecies, TXLTemporaryFolder);

    printAListOfStrings(skeletonInstantiatedWithAbstractFromDonor, tempSkeletonFileWithAllIdsFromGraftInstantiated);



    printAListOfStringsWithSpaces(ListOfMarkersForAbstractVariables, tempFileWithMarkersForAbstractIDs);


    char * tempOutputFileNeededDependenciesForAbstract;
    tempOutputFileNeededDependenciesForAbstract = (char *) malloc(500 * sizeof (char));
    sprintf(tempOutputFileNeededDependenciesForAbstract, "%stemp_dependencies_for_abstract.out", TXLTemporaryFolder);

    createListOfDependenciesForDonorAbstractMappings(tempSkeletonFileWithAllIdsFromGraftInstantiated,
            tempFileWithMarkersForAbstractIDs, tempOutputFileNeededDependenciesForAbstract, TXLToolsPath);

    DependencyList * dependencyListForAbstract = NULL;

    dependencyListForAbstract = readDependencyListFromFile(tempOutputFileNeededDependenciesForAbstract);

    return dependencyListForAbstract;
}

#define STRUCT_DECL_BEGINNING_MARKER "/* STRUCT_DECL_"
#define GLOBAL_DECL_BEGINNING_MARKER "/* GLOBAL_DECL_"
#define TYPEDEF_DECL_BEGINNING_MARKER "/* TYPEDEF_DECL_"

void addNewDependencyInAnExistingOne(ListOfString * newListOfDependencies, ListOfString * oldListOfDependencies, char * statment, GlobalDeclarationsMark globalDeclarationsMark ) {

    /*while (oldListOfDependencies) {
        if (strstr(oldListOfDependencies->el, GLOBAL_DECL_BEGINNING_MARKER)) {
            ListOfStructMark *listNormalDeclMark = globalDeclarationsMark.normalDeclarations;

            while (listNormalDeclMark) {
                if (strstr(listNormalDeclMark->oldStatment, oldListOfDependencies->el)) {
                    addNewDependency(&newListOfDependencies, statment, listNormalDeclMark->newStatment);
                    /*
                    (*newListOfDependencies)->el = NULL;
                    (*newListOfDependencies)->el = (char *) malloc(
                            (strlen(listNormalDeclMark->newStatment) + 1) * sizeof(char));
                    strcpy((*newListOfDependencies)->el, listNormalDeclMark->newStatment);
                    listNormalDeclMark = listNormalDeclMark->next;
                }
            }
            oldListOfDependencies = oldListOfDependencies->next;
        }
    }*/
}

void addNewStatmentInAnExistingDependeciesList(char ** newStatment, ListOfStructMark * globalDeclarationsMark,char * oldStatment) {
    char * newSt = (char *) malloc(1 * sizeof (char));

    while(globalDeclarationsMark){
        if(strstr(oldStatment, globalDeclarationsMark->oldStatment)) {
       //     newStatment = (char *) malloc((strlen(globalDeclarationsMark->newStatment) + 1) * sizeof (char));
            strcpy(newStatment, globalDeclarationsMark->newStatment);
        }
        globalDeclarationsMark = globalDeclarationsMark->next;
    }

}

char * returnNewMark(ListOfStructMark * listOfStructMark, char * oldMark){
    char *newMark = (char *) malloc(100 * sizeof (char));
    while (listOfStructMark){
        if(!strcmp(oldMark, listOfStructMark->oldStatment)) {
            strcpy(newMark, listOfStructMark->newStatment);
            return newMark;
        }
        listOfStructMark = listOfStructMark->next;
    }

    return NULL;
}

void addNewDependencyListMark(DependencyList ** NewListOfDependency, DependencyList * GlobalCurrentDependencyList, ListOfStructMark * listOfStructMark ){
    DependencyList * GlobalDependencyList = GlobalCurrentDependencyList;

    char * newStatment = NULL;
    char * oldStatement = (char *) malloc(100 * sizeof (char));
    char *currentDependency = (char *) malloc(100 * sizeof (char));
    while (GlobalDependencyList) {
        strcpy(oldStatement, GlobalDependencyList->Statement);
        newStatment = returnNewMark(listOfStructMark, oldStatement);
        if(newStatment) {
            addNewStatement(NewListOfDependency, newStatment);
            ListOfString *currentListOfDependencies = GlobalDependencyList->ListOfDependencies;
            while (currentListOfDependencies) {
                strcpy(currentDependency, currentListOfDependencies->el);
                char *newDependencyMark = returnNewMark(listOfStructMark, currentDependency);
                if(newDependencyMark== NULL)
                    printf("erro aqui");

                addNewDependency(NewListOfDependency, newStatment, newDependencyMark);
                currentListOfDependencies = currentListOfDependencies->next;
            }
        }else{
            printf("ERROR: statment %s does not mapped",oldStatement);
            exit(1);
        }
        GlobalDependencyList = GlobalDependencyList->next;
    }
    free(oldStatement);
    free(newStatment);
    free(currentDependency);
}

