#include "OptionParser.h"
#include "Utils.h"
#include "SkeletonMapping.h"
#include "ListOfString.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <getopt.h>
//#include <iscsi/iscsi.h>

char * SourceOutputCoreFunctionalities;
char * InterfaceCoreFunctionality;
char donorSourceFileFolder [250];
char transplantWorkFolderMainThread [250];
char * TXLToolsPath;
char * ProductBase;
char transplantHostInputFile [255];
char listOfCoreFunctionsFile [255];
char conditionalDirectives [255];
char donorEntryFile [255];
char donorEntryFunction [255];

char txlFileHost [255];
//char * inputFileGraft;
char txlFileGraft [255];
char txlFileTransplant [255];
char transplantOutputFile [255];
#if 1 /* MULTIFILES */
char * TXLTemporaryMultiFileFolder = NULL;
#endif
char compileCommand [255];
char outputFileName [255];
char transplantCFile [255];
char * TXLTemporaryFolderMainThread;
char * DoxygenFolder;
char * SkeletonFile;
char * DebugFolder;
char * TransplantResultLocation;
char * AcceptedFunctionsForGP;
char * SkeletonCoreFeatureHeader;
char * InterfaceHeaderFileName;
char * JustCoreFeatureHeaderName;
//char * GraftFunctionName;
char * InterfaceWithCoreFeatureFileName;
char * TemporaryInterface;
char * StatisticsFile;
char * TransplantLogFolder;
char * RandomNumberSeedsFile;
char * CFLAGS_FILE;

char HostProject [500];

char * IfDefProgramPath;

char functionsFile [100];

ListOfString * ListOfCoreFunctions;
ListOfString * ListOfTargetFunctions;

void fixEnvironmentAndGlobalVariables() {
    //copy txl program names
    strcpy(txlFileHost, "HostSymbolTable.x");
    strcpy(txlFileGraft, "graftSymbolTable.x");
    strcpy(txlFileTransplant, "addGraftToHost.x");
    //cleanTransplantWorkFolder(transplantWorkFolder);
    //createADirIfItNotExists(transplantWorkFolder);
    //createADirIfItNotExists(TXLTemporaryFolder);
    //createADirIfItNotExists(TransplantResultLocation);

}


int exclude_functions = 0;
int transplant_log = 0;
int transplant_stats = 0;
int seeds_type = 0;
int host_compilation = 0;
int has_cflags = 0;

void parse_args(int argc, char * argv[]) {

	ListOfCoreFunctions = NULL;
    ListOfTargetFunctions = NULL;

    fixEnvironmentAndGlobalVariables();

    int c;
    while (1) {
        static struct option long_options[] = {
            //flag options 
            {"exclude_functions", required_argument, &exclude_functions, 1},
            {"transplant_log", required_argument, &transplant_log, 1},
            {"transplant_statistics", required_argument, &transplant_stats, 1},
            {"urandom_seeds", no_argument, &seeds_type, 0},
            {"random_seeds", no_argument, &seeds_type, 1},
            {"seeds_file", required_argument, &seeds_type, 2},
            {"host_compilation", no_argument, &host_compilation, 1},
            {"compiler_options", required_argument, &has_cflags, 1},
            //non flag options
            {"host_target", required_argument, 0, 'h'},
            {"donor_target", required_argument, 0, 'd'},
            {"txl_tools_path", required_argument, 0, 'T'},
            {"donor_folder", required_argument, 0, 'D'},
            {"workspace", required_argument, 0, 'w'},
            {"core_function", required_argument, 0, 'f'},
			{"host_project", required_argument, 0, 'B'},
			{"functions", required_argument, 0, 'F'},
            {"functions_target", required_argument, 0, 'S'},
            {"donor_entry_function", required_argument,0, 'M'},
            {"donor_entry_file", required_argument,0, 'e'},
            {"conditional_directives", required_argument,0, 'c'},
            {"product_base", required_argument,0, 't'},
            {0, 0, 0, 0}
        };

        int option_index = 0;
        c = getopt_long(argc, argv, "h:d:T:D:w:f:", long_options, &option_index);
        if (c == -1) {
            break;
        }
        switch (c) {
            case 0:
            {
                //if (long_options[option_index].flag != 0){
                //} 0,1,2,5,7
                switch (option_index) {
                    case 0:
                    {
                        AcceptedFunctionsForGP = (char *) malloc((strlen(optarg) + 1) * sizeof (char));
                        strcpy(AcceptedFunctionsForGP, optarg);
                        break;
                    }
                    case 1:
                    {
                        TransplantLogFolder = (char *) malloc((strlen(optarg) + 1) * sizeof (char));
                        strcpy(TransplantLogFolder, optarg);
                        break;
                    }
                    case 2:
                    {
                        StatisticsFile = (char *) malloc((strlen(optarg) + 1) * sizeof (char));
                        strcpy(StatisticsFile, optarg);
                        break;
                    }
                    case 5:
                    {
                        RandomNumberSeedsFile = (char *) malloc((strlen(optarg) + 1) * sizeof (char));
                        strcpy(RandomNumberSeedsFile, optarg);
                        break;
                    }
                    case 7:
                    {
                        CFLAGS_FILE = (char *) malloc((strlen(optarg) + 1) * sizeof (char));
                        strcpy(CFLAGS_FILE, optarg);
                        break;
                    }
                    case 8:{
                    	strcpy(HostProject, optarg);
                    	break;
                    }
                    case 9:{
                    	strcpy(functionsFile,optarg);
                    	ListOfCoreFunctions = readListOfStringFromFileAsWords(functionsFile);
                    	break;
                    }
                    default:
                    {
                        //do nothing, just set the flag
                        break;
                    }
                }
                break;
            }
            case 'h':
            {
                strcat(transplantHostInputFile, optarg);
                break;
            }
          /*  case 'd':
            {
                inputFileGraft = (char *) malloc((strlen(optarg) + 1) * sizeof (char));
                strcat(inputFileGraft, optarg);
                break;
            }*/
            case 'T':
            {
                TXLToolsPath = (char *) malloc((strlen(optarg) + 1) * sizeof (char));
                strcpy(TXLToolsPath, optarg);
                break;
            }
            case 't':
            {
                ProductBase = (char *) malloc((strlen(optarg) + 1) * sizeof (char));
                strcpy(ProductBase, optarg);
                break;
            }
            case 'D':
            {
                strcpy(donorSourceFileFolder, optarg);
                break;
            }
            case 'w':
            {
                strcpy(transplantWorkFolderMainThread, optarg);
                break;
            }
            case 'c':
            {
                strcpy(conditionalDirectives, optarg);
                break;
            }
            case 'M':
            {
                strcpy(donorEntryFunction, optarg);
                break;
            }
            case 'e':
            {
                strcpy(donorEntryFile, optarg);
                break;
            }
            case 'f':
            {
               /* GraftFunctionName = (char *) malloc((strlen(optarg) + 1) * sizeof (char));
                strcpy(GraftFunctionName, optarg);
                break;*/
            }
            case 'B':
            {
            	strcpy(HostProject, optarg);
            	break;
            }
            case 'F':
            {
                sprintf(functionsFile, optarg);
            	ListOfCoreFunctions = readListOfStringFromFileAsWords(functionsFile);

                break;
            }
#if 1 /* MULTIORGAN TRANSPLANT*/
            case 'S':
            {
                strcpy(listOfCoreFunctionsFile,optarg);
               // ListOfTargetFunctions = readListOfStringFromFileAsWords(functionsTragetFile);
                break;
            }
#endif
        }
    }

    if (!TXLToolsPath) {
        TXLToolsPath = (char *) malloc(5 * sizeof (char));
        strcpy(TXLToolsPath, "./");
    }

    TXLTemporaryFolderMainThread = (char *) malloc((strlen(transplantWorkFolderMainThread) + 8) * sizeof (char));
    sprintf(TXLTemporaryFolderMainThread, "%sTemp/", transplantWorkFolderMainThread);
    fflush(stdout);

    TransplantResultLocation = (char *) malloc((strlen(transplantWorkFolderMainThread) + 20) * sizeof (char));
    sprintf(TransplantResultLocation, "%sTransplantCode/", transplantWorkFolderMainThread);
    fflush(stdout);

    SourceOutputCoreFunctionalities = (char *) malloc((strlen(TXLTemporaryFolderMainThread) + 20) * sizeof (char));
    sprintf(SourceOutputCoreFunctionalities, "%s%s", TXLTemporaryFolderMainThread, "NeededSourceCode.c");
    fflush(stdout);

    InterfaceCoreFunctionality = (char *) malloc((strlen(TXLTemporaryFolderMainThread) + 30) * sizeof (char));
    sprintf(InterfaceCoreFunctionality, "%s%s", TXLTemporaryFolderMainThread, "InterfaceCoreFunctionality.c");
    fflush(stdout);

    SkeletonFile = (char *) malloc((strlen(TXLTemporaryFolderMainThread) + 30) * sizeof (char));
    sprintf(SkeletonFile, "%sInstantiatedSkeleton.out", TXLTemporaryFolderMainThread);
    fflush(stdout);

    JustCoreFeatureHeaderName = (char *) malloc(500 * sizeof (char));
    sprintf(JustCoreFeatureHeaderName, "NeededFunctionsHeader.h");
    fflush(stdout);

    DebugFolder = (char *) malloc(500 * sizeof (char));
    strcpy(DebugFolder, "Debug/");
    fflush(stdout);

    SkeletonCoreFeatureHeader = (char *) malloc((strlen(TXLTemporaryFolderMainThread)
            + strlen(JustCoreFeatureHeaderName) + 1) * sizeof (char));
    sprintf(SkeletonCoreFeatureHeader, "%s%s", TXLTemporaryFolderMainThread, JustCoreFeatureHeaderName);

#if 1 /* MULTIFILES */
    /* LOS:  Temporary folder for source files */
    TXLTemporaryMultiFileFolder = (char *) malloc((strlen(transplantWorkFolderMainThread) + 17) * sizeof (char));
    sprintf(TXLTemporaryMultiFileFolder, "%sTempSourceFiles/", transplantWorkFolderMainThread);
#endif

    if (!strcmp(TXLToolsPath, "./")) {
        IfDefProgramPath = (char *) malloc((strlen(TXLToolsPath) + 10) * sizeof (char));
        sprintf(IfDefProgramPath, "%sifdef.x", TXLToolsPath);
    } else {
        IfDefProgramPath = (char *) malloc(10 * sizeof (char));
        sprintf(IfDefProgramPath, "./ifdef.x");
    }

}





