/* 
 * File:   GenTrans.h
 * Author: ---
 *
 * Created on 25 June 2014, 19:44
 */

#ifndef GENTRANS_H
#define	GENTRANS_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "SymbolTable.h"

#include <stdio.h>
#include "ListOfString.h"
#include <time.h>

//#define RETURN_MARKER "/* RETURN_MARKER */  return ec_lnum ($_ex_exec_ln);"
#define RETURN_MARKER "/* RETURN_MARKER */  return "
#define STATEMENT_MARKER "/*@STM*/"
#define DECL_MARKER "/*@DECL*/"
#define COMPOUND_START_MARKER "//COMPOUND START:"
#define COMPOUND_END_MARKER "//COMPOUND END:"
#define MAIN_RETURN_MARKER "$ABSTRETVAL_ret_main"

#define LINE_END "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n" 
#define FUNCTION_CALL_MARKER "//call_the_function:"
#ifndef DEBUG
#define DEBUG
#endif

    extern char * ConsoleNullOutput;
    extern char * ConsoleStderrOutput;
    extern char * hostWithInterfaceOutputFile;

    SymbolTable * readSymbolTable(FILE *fin);

    extern char TempVeinDirectory [250];
    extern char TempImplantationDirectory [250];
    extern char donorSourceFileFolder [250];
    extern char tempDonorSourceFileFolder [250];
    extern char transplantWorkFolderMainThread [250];
    extern char * TXLToolsPath;
    extern char * ProductBase;
    extern char * transplantHostInputFile;
    extern char txlFileHost [255];
    extern char * inputFileGraft;

    extern char txlFileGraft [255];
    extern char txlFileTransplant [255];
    extern char transplantOutputFile [255];
    extern char compileCommand [255];
    extern char outputFileName [255];
    extern char transplantCFile [255];
    extern char HostProject [500];
    extern char initFunctionMarker [255];
    extern char initFunctionMarkerSourceFile [255];

    extern char * TXLTemporaryFolderMainThread;
    extern char * SkeletonFile;
    extern char * TransplantResultLocation;
    extern char * DoxygenFolder;
    extern char * DebugFolder;

    extern char * TXLTemporaryMultiFileFolder;
    extern char * AcceptedFunctionsForGP;

    extern char * SourceOutputCoreFunctionalities;

    extern char * InterfaceCoreFunctionality;

    extern char * SkeletonCoreFeatureHeader;

    extern char * JustCoreFeatureHeaderName;

    extern char * InterfaceHeaderFileName;

    extern char * GraftFunctionName;

    extern char * graftFileFullPath;

    extern char * InterfaceWithCoreFeatureFileName;

    extern char * TemporaryInterface;

    extern char * IfDefProgramPath;

    char *replace_str(char *str, char *orig, char *rep);

    char* str_replace(char* string, const char* substr, const char* replacement);

    extern char * TransplantLogFolder;

    extern char * StatisticsFile;

    extern char * RandomNumberSeedsFile;

    extern char * CFLAGS_FILE;

    extern char functionsFile [100];
    extern ListOfString * ListOfCoreFunctions;



    char * removeArraySizeInString(char * originalString);


    extern int exclude_functions;
    extern int transplant_log;
    extern int transplant_stats;
    extern int seeds_type;
    extern int host_compilation;
    extern int has_cflags;

    extern char listOfCoreFunctionsFile [255];
    extern char conditionalDirectives [255];
    extern char donorEntryFile [255];
    extern char donorEntryFunction [255];

    //LOS
    extern int numberOfCoreFunctions;
    extern int referenceOfCurrentTransplant;
    ListOfString * execution_log;
    clock_t begin_execution_time;

#define AbstractMappingsMarker "Abstract_Mappings:\n"
#define DeclarationMappingsMarker "Declaration_Mappings:\n"
#define IndividualLinesMarker "Statement_Line_Number:\n"
#define CURRENT_DECLARATION_DONOR_MAPPING_SIGN "MAPPED_TO_ORIGINAL_VALUE_IN_DONOR"


#ifdef	__cplusplus
}
#endif

#endif	/* GENTRANS_H */

//LOS TESTES
/*use in a small system */
#undef ADD_FUNCTION_IN_A_SINGLE_FILE

#undef ALL_DEFINITION_NAME_IN_FILE
#define MAKEFILE_MULTIFILES
#define GLOBAL_DECLARATIONS_FOR_SKELETON
#define MULTIFILES_GLOBAL_DECLARATION
#define EXTRACT_DECL_BY_FILE


// Implementation process
#define SEARCH_VAR_UNION
#define MULTIFILE_VAR_EXTRACTION
#define MAC_OSX




#define IF_MACVIM

// use it to replace static file-by-file. Recomended when work on system with more than 10k LOCs by source code file
#undef REPLACE_STATIC_BY_FILE
#undef REPLACE_STATIC_FUNCTION_DECLARATIONS

//Specific header files
#undef SPECIFIC_HEADER_FILES


/* Used when the host is a version of the donor
 * When defined our tool check if alredy there is a target function in host.
 */

#undef REDUCE_CANDIDATE

#define HEADER_FILE

//TRANSPLANT PREPARATION
#undef GENERATE_HOST_INTERFACE_FOR_ICEBOX_TESTS  // LOS FIRST RUNNING //FALSE: KEEPING THE ARTEFACTS CREATED

//PROPERTIES
// Clean all temporary folders
#undef PREOPERATIVE_REMOVE_DIRECTIVES //LOS FIRST RUNNING
#undef RESET_TRANSPLANT //LOSCHANGE23! //FALSE: KEEPING THE ARTEFACTS CREATED
#undef GENERATE_DATAS_FROM_TRANSPLANT
#define REDUCED_VEIN

#undef DONOR_IS_HOST //LOSCHANGE23
//MODULES: Able and unable modules
#define RUN_DOXYGEN //LOSCANGE23 LOS COMPLET EXECUTION LOS FIRST RUNNING
#define GENERATE_DONOR_CALL_AND_CALLED_GRAPHS
#define READ_FROM_FILE_HOST_SYMBOL_TABLE
#define GENERATE_HOST_INTERFACE
#define EXTRACT_FUNCTIONALITY_MULTIFILE
#undef GENERATE_REVERSE_CALL_GRAPH //LOSCHANGE23! //FALSE: KEEPING THE ARTEFACTS CREATED
#define VEIN_GLOBAL_EXTRACTION
#define CONSTRUCT_GRAFT_SKELETON
#define INSTANTIATE_FUCNTIONS_IN_SKELETON
#define INITIAL_FUNCTIONS_IN_SKELETON
#define INSTANTIATE_CURRENT_INDIVIDUAL_IN_SKELETON
#define GENERATE_DECLARATION_DEPENDENCIES_FOR_DONOR_VARIABLE_IN_ABSTRACT_MAPPINGS

#define EXTRACT_GLOBAL_DECLARATION
#define EXTRACT_DEPENDENCY_GLOBAL_LIST_FROM_VEIN
#define EXTRACT_GLOBAL_DEPENDENCIES
#define EXTRACT_NEEDED_FUNCTION_AND_GLOBAL_DECL_FOR_SKELETON
#define EXTRACT_INCLUDES_AND_DIRECTIVES
#define ORGAN_IMPLANTATION

//Transplantation check
#undef TEST_RESULTS
#define DEBUGING
#undef DEBUGING2
#undef FAST_RUNNING
#undef FAST_RUNNING2 //LOSCHANGE23 LOS undef to  COMPLET EXECUTION
#define EXPERIMENT_RUN
#undef PRUNER