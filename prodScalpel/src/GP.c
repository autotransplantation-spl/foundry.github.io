#include "ListOfInt.h"
#include "ListOfString.h"
#include "Mapping.h"
#include "MappingCandidate.h"
#include "DeclarationSymbolTable.h"
#include "GenTrans.h"
#include "PrepareForGP.h"
#include "GlobalDeclarations.h"
#include "GPIndividual.h"
#include "IndividualInstantiator.h"
#include "DependencyListWithID.h"
#include "Skeleton.h"
#include "GIReduction.h"
#include <pthread.h>

#include "folderContent.h"


#include "GlobalDeclarations.h"

#define _GNU_SOURCE
//#define __USE_GNU
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <libgen.h>
#include "Utils.h"

#include "ListOfFunctionForGraph.h"

#define POPULATION_LENGTH  80
#define NUMBER_OF_GENERATIONS 1000
#define FITNESS_FOR_COMPILE_PERCENTAGE 0.35
#define FITNESS_FOR_SUCCESFUL_RUN_PERCENTAGE 0.35

char TempImplantationDirectory [250];

int ALL_TEST_CASE_PASSED = 0;

double TEST_CASES_PERCENTAGE = 0;
int BUILD_OR_NOT = 0;
int IMPLEMENT_FUNCTIONALITY = 0;
int generationNumber = 1;

GPIndividual * SUCCESFULL_INDIVIDUAL = NULL;

static unsigned int x, y, z, c;

unsigned int JKISS() {
	unsigned long long t;

	x = 314527869 * x + 1234567;
	y ^= y << 5;
	y ^= y >> 7;
	y ^= y << 22;
	t = 4294584393ULL * z + c;
	c = t >> 32;
	z = t;

	return x + y + z;
}

static unsigned int x1, y1, z1, c1;

unsigned int JKISSOperation() {
	unsigned long long t1;

	x1 = 314527869 * x1 + 1234567;
	y1 ^= y1 << 5;
	y1 ^= y1 >> 7;
	y1 ^= y1 << 22;
	t1 = 4294584393ULL * z1 + c1;
	c1 = t1 >> 32;
	z = t1;

	return x1 + y1 + z1;
}

static unsigned int x2, y2, z2, c2;

unsigned int JKISSAbstractMappings() {
	unsigned long long t2;

	x2 = 314527869 * x2 + 1234567;
	y2 ^= y2 << 5;
	y2 ^= y2 >> 7;
	y2 ^= y2 << 22;
	t2 = 4294584393ULL * z2 + c2;
	c2 = t2 >> 32;
	z2 = t2;

	return x2 + y2 + z2;
}

static unsigned int x3, y3, z3, c3;

unsigned int JKISSCrossoverSelector() {
	unsigned long long t3;

	x3 = 314527869 * x3 + 1234567;
	y3 ^= y3 << 5;
	y3 ^= y3 >> 7;
	y3 ^= y3 << 22;
	t3 = 4294584393ULL * z3 + c3;
	c3 = t3 >> 32;
	z3 = t3;

	return x3 + y3 + z3;
}

static unsigned int x4, y4, z4, c4;

unsigned int JKISSLoclDecl() {
	unsigned long long t4;

	x4 = 314527869 * x4 + 1234567;
	y4 ^= y4 << 5;
	y4 ^= y4 >> 7;
	y4 ^= y4 << 22;
	t4 = 4294584393ULL * z4 + c4;
	c4 = t4 >> 32;
	z4 = t4;

	return x4 + y4 + z4;
}

static unsigned int x5, y5, z5, c5;

unsigned int JKISSPopulationSelection() {
	unsigned long long t5;

	x5 = 314527869 * x5 + 1234567;
	y5 ^= y5 << 5;
	y5 ^= y5 >> 7;
	y5 ^= y5 << 22;
	t5 = 4294584393ULL * z5 + c5;
	c5 = t5 >> 32;
	z5 = t5;

	return x5 + y5 + z5;
}

static unsigned int x6, y6, z6, c6;

unsigned int JKISSStrings() {
	unsigned long long t6;

	x6 = 314527869 * x6 + 1234567;
	y6 ^= y6 << 5;
	y6 ^= y6 >> 7;
	y6 ^= y6 << 22;
	t6 = 4294584393ULL * z6 + c6;
	c6 = t6 >> 32;
	z6 = t6;

	return x6 + y6 + z6;
}

unsigned int devrand(void) {
	int fn;
	unsigned int r;

	fn = open("/dev/random", O_RDONLY);
	while (fn == -1 || read(fn, &r, 4) != 4) {
		close(fn);
		fn = open("/dev/random", O_RDONLY);
	}
	close(fn);
	return r;
}

unsigned int devurand(void) {
	int fn;
	unsigned int r;

	fn = open("/dev/urandom", O_RDONLY);
	while (fn == -1 || read(fn, &r, 4) != 4) {
		close(fn);
		fn = open("/dev/urandom", O_RDONLY);
	}
	close(fn);
	return r;
}

void randomNumbersSeeding() {
	switch (seeds_type) {
	case 0: {
		x = devurand();
		y = devurand();
		z = devurand();
		c = devurand();

		x1 = devurand();
		y1 = devurand();
		z1 = devurand();
		c1 = devurand();

		x2 = devurand();
		y2 = devurand();
		z2 = devurand();
		c2 = devurand();

		x3 = devurand();
		y3 = devurand();
		z3 = devurand();
		c3 = devurand();

		x4 = devurand();
		y4 = devurand();
		z4 = devurand();
		c4 = devurand();

		x5 = devurand();
		y5 = devurand();
		z5 = devurand();
		c5 = devurand();

		x6 = devurand();
		y6 = devurand();
		z6 = devurand();
		c6 = devurand();
		break;
	}
	case 1: {
		x = devrand();
		y = devrand();
		z = devrand();
		c = devrand();

		x1 = devrand();
		y1 = devrand();
		z1 = devrand();
		c1 = devrand();

		x2 = devrand();
		y2 = devrand();
		z2 = devrand();
		c2 = devrand();

		x3 = devrand();
		y3 = devrand();
		z3 = devrand();
		c3 = devrand();

		x4 = devrand();
		y4 = devrand();
		z4 = devrand();
		c4 = devrand();

		x5 = devrand();
		y5 = devrand();
		z5 = devrand();
		c5 = devrand();

		x6 = devrand();
		y6 = devrand();
		z6 = devrand();
		c6 = devrand();

		break;
	}
	case 2: {
		FILE * seedFile = fopen(RandomNumberSeedsFile, "r");
        if(seedFile==NULL) {
            printf("Seed file is not found in %s. Please check if ti exist or if the path is correct.\n",RandomNumberSeedsFile);
            exit(1);
        }
		char * line;
		line = (char *) malloc(2001 * sizeof(char));
		fgets(line, 2000, seedFile);
		sscanf(line, "%u %u %u %u", &x, &y, &z, &c);
		fgets(line, 2000, seedFile);
		sscanf(line, "%u %u %u %u", &x1, &y1, &z1, &c1);
		fgets(line, 2000, seedFile);
		sscanf(line, "%u %u %u %u", &x2, &y2, &z2, &c2);
		fgets(line, 2000, seedFile);
		sscanf(line, "%u %u %u %u", &x3, &y3, &z3, &c3);
		fgets(line, 2000, seedFile);
		sscanf(line, "%u %u %u %u", &x4, &y4, &z4, &c4);
		fgets(line, 2000, seedFile);
		sscanf(line, "%u %u %u %u", &x5, &y5, &z5, &c5);
		fgets(line, 2000, seedFile);
		sscanf(line, "%u %u %u %u", &x6, &y6, &z6, &c6);
#if 0
		FILE * testSeads = fopen("testSEEDS.out", "w");
		fprintf(testSeads, "%u %u %u %u #SEEDS for 0\n", x, y, z, c);
		fprintf(testSeads, "%u %u %u %u #SEEDS for 1\n", x1, y1, z1, c1);
		fprintf(testSeads, "%u %u %u %u #SEEDS for 2\n", x2, y2, z2, c2);
		fprintf(testSeads, "%u %u %u %u #SEEDS for 3\n", x3, y3, z3, c3);
		fprintf(testSeads, "%u %u %u %u #SEEDS for 4\n", x4, y4, z4, c4);
		fprintf(testSeads, "%u %u %u %u #SEEDS for 5\n", x5, y5, z5, c5);
		fprintf(testSeads, "%u %u %u %u #SEEDS for 6\n", x6, y6, z6, c6);
		fclose(testSeads);
#endif
		fclose(seedFile);
		break;
	}
	default: {
		break;
	}
	}
}

unsigned int randomIndexJKISSStrings(unsigned int max,
		ListOfInt * listOfExisting) {
	// Generate a random number:
	unsigned int x;
	x = JKISSStrings() % max;
	int count;
	//how much time to try to find an unique line
	count = 200;
	if (listOfExisting != NULL) {
		int s = 0;
		while (s == 0 && count > 0) {
			count--;
			s = 1;
			ListOfInt * p = listOfExisting;
			while (p != NULL) {
				if (p->value == x) {
					s = 0;
				}
				p = p->next;
			}
			if (s == 0) {
				x = rand() % max;
			}
		}
		if (count < 0) {
			return -1;
		}
	}
	return x;
}

unsigned int randomIndexJKISSPopulationSelection(unsigned int max,
		ListOfInt * listOfExisting) {
	// Generate a random number:
	unsigned int x;
	x = JKISSPopulationSelection() % max;
	int count;
	//how much time to try to find an unique line
	count = 200;
	if (listOfExisting != NULL) {
		int s = 0;
		while (s == 0 && count > 0) {
			count--;
			s = 1;
			ListOfInt * p = listOfExisting;
			while (p != NULL) {
				if (p->value == x) {
					s = 0;
				}
				p = p->next;
			}
			if (s == 0) {
				x = rand() % max;
			}
		}
		if (count < 0) {
			return -1;
		}
	}
	return x;
}

unsigned int randomIndexJKISSLoclDecl(unsigned int max,
		ListOfInt * listOfExisting) {
	// Generate a random number:
	unsigned int x;
	x = JKISSLoclDecl() % max;
	int count;
	//how much time to try to find an unique line
	count = 200;
	if (listOfExisting != NULL) {
		int s = 0;
		while (s == 0 && count > 0) {
			count--;
			s = 1;
			ListOfInt * p = listOfExisting;
			while (p != NULL) {
				if (p->value == x) {
					s = 0;
				}
				p = p->next;
			}
			if (s == 0) {
				x = rand() % max;
			}
		}
		if (count < 0) {
			return -1;
		}
	}
	return x;
}

unsigned int randomIndexJKISSCrossoverSelector(unsigned int max,
		ListOfInt * listOfExisting) {
	// Generate a random number:
	unsigned int x;
	x = JKISSCrossoverSelector() % max;
	int count;
	//how much time to try to find an unique line
	count = 200;
	if (listOfExisting != NULL) {
		int s = 0;
		while (s == 0 && count > 0) {
			count--;
			s = 1;
			ListOfInt * p = listOfExisting;
			while (p != NULL) {
				if (p->value == x) {
					s = 0;
				}
				p = p->next;
			}
			if (s == 0) {
				x = rand() % max;
			}
		}
		if (count < 0) {
			return -1;
		}
	}
	return x;
}

unsigned int randomIndexJKISSAbstractMappings(unsigned int max,
		ListOfInt * listOfExisting) {
	// Generate a random number:
	unsigned int x;
	x = JKISSAbstractMappings() % max;
	int count;
	//how much time to try to find an unique line
	count = 200;
	if (listOfExisting != NULL) {
		int s = 0;
		while (s == 0 && count > 0) {
			count--;
			s = 1;
			ListOfInt * p = listOfExisting;
			while (p != NULL) {
				if (p->value == x) {
					s = 0;
				}
				p = p->next;
			}
			if (s == 0) {
				x = rand() % max;
			}
		}
		if (count < 0) {
			return -1;
		}
	}
	return x;
}

unsigned int randomIndexJKISS(unsigned int max, ListOfInt * listOfExisting) {
	// Generate a random number:
	unsigned int x;
	x = JKISS() % max;
	int count;
	//how much time to try to find an unique line
	count = 200;
	if (listOfExisting != NULL) {
		int s = 0;
		while (s == 0 && count > 0) {
			count--;
			s = 1;
			ListOfInt * p = listOfExisting;
			while (p != NULL) {
				if (p->value == x) {
					s = 0;
				}
				p = p->next;
			}
			if (s == 0) {
				x = rand() % max;
			}
		}
		if (count < 0) {
			return -1;
		}
	}
	return x;
}

unsigned int randomIndexJKISSOperation(unsigned int max,
		ListOfInt * listOfExisting) {
	// Generate a random number:
	unsigned int x;
	x = JKISSOperation() % max;
	int count;
	//how much time to try to find an unique line
	count = 200;
	if (listOfExisting != NULL) {
		int s = 0;
		while (s == 0 && count > 0) {
			count--;
			s = 1;
			ListOfInt * p = listOfExisting;
			while (p != NULL) {
				if (p->value == x) {
					s = 0;
				}
				p = p->next;
			}
			if (s == 0) {
				x = rand() % max;
			}
		}
		if (count < 0) {
			return -1;
		}
	}
	return x;
}

int randomIndex(unsigned int max, ListOfInt * listOfExisting) {
	// Generate a random number:
	int x;
	x = rand() % max;
	int count;
	//how much time to try to find an unique line
	count = 200;
	if (listOfExisting != NULL) {
		int s = 0;
		while (s == 0 && count > 0) {
			count--;
			s = 1;
			ListOfInt * p = listOfExisting;
			while (p != NULL) {
				if (p->value == x) {
					s = 0;
				}
				p = p->next;
			}
			if (s == 0) {
				x = rand() % max;
			}
		}
		if (count < 0) {
			return -1;
		}
	}
	return x;
}

void addOneRandomCurrentMappingDeclarationSymbolTable(
		DeclarationSymbolTable * head) {
	while (head) {
		//select randomly a possible mapping for current mapping
		int lengthOfPossibleMappingsDeclaration = countElementsInListOfString(
				head->possibleMappings);
		int randomSelectedDeclarationMapping = randomIndexJKISSStrings(
				lengthOfPossibleMappingsDeclaration, NULL);
		char * selectedItemDeclaration = nthElementInListString(
				head->possibleMappings, randomSelectedDeclarationMapping);
		addNewCurrentMappingDeclarationSymbolTable(&head, head->id,
				selectedItemDeclaration);
		head = head->next;
	}
}

//computeFitness

double computeFitnessForSuccesfulIndividual(char * IndividualMakeFileTarget,
		int TotalIDsInHostSymbolTable, int MappedHostIDsInIndividual,
		int LOCsInCurrentIndividual, char ** checkResults) {
	double fitness = 0;
	double fitnessForCompile = 0;
	double fitnessForTestCases = 0;
	double fitnessForSuccesfulRun = 0;

	char * command;
	command = (char *) malloc(1000 * sizeof(char));
    /* LOSCHANGE */
#if 1 /* LOS  Keep 1 to not see the output from compile command */
	sprintf(command, "cd %s \nmake %s %s", TransplantResultLocation,
			IndividualMakeFileTarget, ConsoleStderrOutput);
#else
	sprintf(command, "export PKG_CONFIG_PATH=/usr/local/lib/pkgconfig && cd %s \nmake %s 2>&1", TransplantResultLocation,
			IndividualMakeFileTarget);
#endif
	int result = system(command);
	if (result != 0) {
		fitnessForCompile = 0;
	//	printf("\tFailed to run command make - output: > %d\n",result);
		printf("\tFailed to run command make\n\n-----------------------------------------------------\n");
	} else {
		fitnessForCompile = FITNESS_FOR_COMPILE_PERCENTAGE;

		//just if it compiled is sense in running the test suite!

		if (host_compilation) {
			char * commandRunTestCases;
			commandRunTestCases = (char *) malloc(500 * sizeof(char));

			sprintf(commandRunTestCases, "cd %s\n ./testCase.x",
					TransplantResultLocation);

			FILE *fp;
			char * line;
			line = (char *) malloc(1000 * sizeof(char));

			fp = popen(commandRunTestCases, "r");
			if (fp == NULL) {
				printf("Failed to run command\n\n");
				fitnessForTestCases = 0;
			} else {
				fflush(stdout);
				int foundPercentage = 0;
				while (!foundPercentage && fgets(line, 1000, fp) != NULL) {
					if (strstr(line, "%:") && strstr(line, "Checks:")
							&& strstr(line, "Failures:")
							&& strstr(line, "Errors:")) {
						foundPercentage = 1;
					}
					//printf("%s", line);
				}
				pclose(fp);

				//echo the line with the results in the statistics file!!!

				(*checkResults) = (char *) malloc(
						(strlen(line) + 1) * sizeof(char));
				strcpy(*checkResults, line);

				int fitnessPercentage = 0;
				if (foundPercentage) {
					sscanf(line, "%d", &fitnessPercentage);
				}
				if (fitnessPercentage >= 99) {
					ALL_TEST_CASE_PASSED = 1;
					IMPLEMENT_FUNCTIONALITY = 1;
					TEST_CASES_PERCENTAGE = fitnessPercentage;
					BUILD_OR_NOT = 1;
				}
				fitnessForTestCases = 0.35 * (fitnessPercentage / 100.00);

			}

		} else {
			char * commandRunTestCases;
			commandRunTestCases = (char *) malloc(500 * sizeof(char));

			sprintf(commandRunTestCases, "cd %s\n ./%s",
					TransplantResultLocation, IndividualMakeFileTarget);

			FILE *fp;
			char * line;
			line = (char *) malloc(1000 * sizeof(char));

			fp = popen(commandRunTestCases, "r");
			if (fp == NULL) {
				printf("Failed to run command\n\n");
				fitnessForTestCases = 0;
			} else {
				fflush(stdout);
				int foundPercentage = 0;
				while (!foundPercentage && fgets(line, 1000, fp) != NULL) {
					if (strstr(line, "%:") && strstr(line, "Checks:")
							&& strstr(line, "Failures:")
							&& strstr(line, "Errors:")) {
						foundPercentage = 1;
					}
					//printf("%s", line);
				}
				pclose(fp);

				(*checkResults) = (char *) malloc(
						(strlen(line) + 1) * sizeof(char));
				strcpy(*checkResults, line);

				int fitnessPercentage = 0;
				if (foundPercentage) {
					sscanf(line, "%d", &fitnessPercentage);
				}
				if (fitnessPercentage >= 99) {
					ALL_TEST_CASE_PASSED = 1;
					IMPLEMENT_FUNCTIONALITY = 1;
					TEST_CASES_PERCENTAGE = fitnessPercentage;
					BUILD_OR_NOT = 1;
				}
				fitnessForTestCases = 0.35 * (fitnessPercentage / 100.00);

				char * startingChecks = strstr(line, "Checks");
				int checksNumber, failuresNumber, errorNumber;
				char * checksMarker, *failuresMarker, *errorsMarker;
				checksMarker = (char *) malloc(500 * sizeof(char));
				failuresMarker = (char *) malloc(500 * sizeof(char));
				errorsMarker = (char *) malloc(500 * sizeof(char));

				sscanf(startingChecks, "%s %d, %s %d, %s %d", checksMarker,
						&checksNumber, failuresMarker, &failuresNumber,
						errorsMarker, &errorNumber);
				if (checksNumber > 0) {
					fitnessForSuccesfulRun = (checksNumber - errorNumber)
							/ checksNumber;

					fitnessForSuccesfulRun = fitnessForSuccesfulRun
							* FITNESS_FOR_SUCCESFUL_RUN_PERCENTAGE;
				}
			}
		}

	}
	//fcloseall();
	fitness = fitnessForCompile + fitnessForTestCases + fitnessForSuccesfulRun; //+ fitnessForLOCs; //+ fitnessForMappedIDs;
	return fitness;
}

double computeFitness(char * IndividualMakeFileTarget,
		int TotalIDsInHostSymbolTable, int MappedHostIDsInIndividual,
		int LOCsInCurrentIndividual, char * localTransplantResultLocation) {
	double fitness = 0;
	double fitnessForCompile = 0;
	double fitnessForTestCases = 0;
	double fitnessForSuccesfulRun = 0;

   /* char * commandMake;
    commandMake = (char *) malloc(1000 * sizeof(char));
    sprintf(commandMake, "make %s%s", localTransplantResultLocation, ConsoleStderrOutput);
    int resultCmdMake = system(commandMake);
    if (resultCmdMake != 0) {
        printf("\tCommand Make filed\n");
    }*/
    char * ConsoleOutputError;
    ConsoleOutputError = (char *) malloc(1000 * sizeof(char));
    sprintf(ConsoleOutputError," > /dev/null 2> %sErrorFile.out",localTransplantResultLocation);
    char * command;
	command = (char *) malloc(1000 * sizeof(char));
	///sprintf(command, "cd %s \nmake %s %s", localTransplantResultLocation, IndividualMakeFileTarget, ConsoleStderrOutput);
    sprintf(command, "cd %s \nmake %s %s", localTransplantResultLocation, IndividualMakeFileTarget, ConsoleStderrOutput);
	int result = system(command);
	if (result != 0) {
		fitnessForCompile = 0;
        printf("\tInvalid individual.\n\n-----------------------------------------------------\n");
	} else {
		fitnessForCompile = FITNESS_FOR_COMPILE_PERCENTAGE;

		//just if it compiled is sense in running the test suite!

		if (host_compilation) {
			char * commandRunTestCases;
			commandRunTestCases = (char *) malloc(500 * sizeof(char));

			sprintf(commandRunTestCases, "cd %s\n ./testCase.x",
					localTransplantResultLocation);

			FILE *fp;
			char * line;
			line = (char *) malloc(1000 * sizeof(char));

			fp = popen(commandRunTestCases, "r");
			if (fp == NULL) {
				///printf("Failed to run command\n");
				fitnessForTestCases = 0;
			} else {
				fflush(stdout);
				int foundPercentage = 0;
				while (!foundPercentage && fgets(line, 1000, fp) != NULL) {
					if (strstr(line, "%:") && strstr(line, "Checks:")
							&& strstr(line, "Failures:")
							&& strstr(line, "Errors:")) {
						foundPercentage = 1;
					}
					//printf("%s", line);
				}
				///pclose(fp);

				int fitnessPercentage = 0;
				if (foundPercentage) {
					sscanf(line, "%d", &fitnessPercentage);
				}

				printf("FitnessPercentage: %d\n",fitnessPercentage);
				if (fitnessPercentage >= 99) {
					ALL_TEST_CASE_PASSED = 1;
					IMPLEMENT_FUNCTIONALITY = 1;
					TEST_CASES_PERCENTAGE = fitnessPercentage;
					BUILD_OR_NOT = 1;
				}
				fitnessForTestCases = 0.35 * (fitnessPercentage / 100.00);
				char * startingChecks = strstr(line, "Checks");
				int checksNumber, failuresNumber, errorNumber;
				char * checksMarker, *failuresMarker, *errorsMarker;
				checksMarker = (char *) malloc(500 * sizeof(char));
				failuresMarker = (char *) malloc(500 * sizeof(char));
				errorsMarker = (char *) malloc(500 * sizeof(char));

				sscanf(startingChecks, "%s %d, %s %d, %s %d", checksMarker,
						&checksNumber, failuresMarker, &failuresNumber,
						errorsMarker, &errorNumber);

                printf("\t%s",startingChecks);

                fgets(line, 1000, fp);
                printf("\t%s\n",line);
                pclose(fp);
				printf("------------------------------------------------------\n");

				if (checksNumber > 0) {
					fitnessForSuccesfulRun = (checksNumber - errorNumber)
							/ checksNumber;

					fitnessForSuccesfulRun = fitnessForSuccesfulRun
							* FITNESS_FOR_SUCCESFUL_RUN_PERCENTAGE;
				}

			}

		} else {
			char * commandRunTestCases;
			commandRunTestCases = (char *) malloc(500 * sizeof(char));

			sprintf(commandRunTestCases, "cd %s\n ./%s",
					localTransplantResultLocation, IndividualMakeFileTarget);

			FILE *fp;
			char * line;
			line = (char *) malloc(1000 * sizeof(char));

			fp = popen(commandRunTestCases, "r");
			if (fp == NULL) {
				printf("Failed to run command\n");
				fitnessForTestCases = 0;
			} else {
				fflush(stdout);
				int foundPercentage = 0;
				while (!foundPercentage && fgets(line, 1000, fp) != NULL) {
					if (strstr(line, "%:") && strstr(line, "Checks:")
							&& strstr(line, "Failures:")
							&& strstr(line, "Errors:")) {
						foundPercentage = 1;
					}

					//printf("Line: %s\n", line);
				}


				int fitnessPercentage = 0;
				if (foundPercentage) {
					sscanf(line, "%d", &fitnessPercentage);
				}
				printf("\tFitnessPercentage: %d\n",fitnessPercentage);
				if (fitnessPercentage >= 99) {
					ALL_TEST_CASE_PASSED = 1;
					IMPLEMENT_FUNCTIONALITY = 1;
					TEST_CASES_PERCENTAGE = fitnessPercentage;
					BUILD_OR_NOT = 1;
					/// losaqui localTransplantResultLocation
				}
				fitnessForTestCases = 0.35 * (fitnessPercentage / 100.00);

				char * startingChecks = strstr(line, "Checks");
				int checksNumber, failuresNumber, errorNumber, fileNumber;
				char * checksMarker, *failuresMarker, *errorsMarker, *fileMarker;
				checksMarker = (char *) malloc(500 * sizeof(char));
				failuresMarker = (char *) malloc(500 * sizeof(char));
				errorsMarker = (char *) malloc(500 * sizeof(char));
				fileMarker = (char *) malloc(500 * sizeof(char));
                if(startingChecks!=NULL) {
                    sscanf(startingChecks, "%s %d, %s %d, %s %d, %s %d", checksMarker,
                           &checksNumber, failuresMarker, &failuresNumber,
                           errorsMarker, &errorNumber, fileMarker, &fileNumber);
                }
				printf("\t%s",startingChecks);

				fgets(line, 1000, fp);
				printf("\t%s\n",line);
                pclose(fp);
			///	pclose(fp);
				printf("-----------------------------------------------------\n");

				if (checksNumber > 0) {
					fitnessForSuccesfulRun = (checksNumber - errorNumber)
							/ checksNumber;

					fitnessForSuccesfulRun = fitnessForSuccesfulRun
							* FITNESS_FOR_SUCCESFUL_RUN_PERCENTAGE;
				}
			}
		}

	}
	//fcloseall();
	fitness = fitnessForCompile + fitnessForTestCases + fitnessForSuccesfulRun; //+ fitnessForLOCs; //+ fitnessForMappedIDs;
	return fitness;
}

void randomlySelectOneAbstactMappingAndOnePossibleMappingForIt(
		ArrayOfMappingCandidates currentMappingCandidateArray) {
	//int lengthOfAbstractMappings = count
	int randAbstractMapping = randomIndexJKISSAbstractMappings(
			currentMappingCandidateArray.count, NULL);
	//construct the list of abstract mappings
	MappingCandidate * selectedMappingCandidate =
			currentMappingCandidateArray.array[randAbstractMapping];
	//select randomly a possible mapping for current mapping
	int lengthOfPossibleMappingsAbstract = countElementsInListOfString(
			selectedMappingCandidate->possibleMappings);
	if (lengthOfPossibleMappingsAbstract > 1) {
		char * initialMappingCandidateCurrentMapping;
		initialMappingCandidateCurrentMapping = (char *) malloc(
				500 * sizeof(char));
		strcpy(initialMappingCandidateCurrentMapping,
				selectedMappingCandidate->currentMapping);

		int randomSelectedAbstractMapping = randomIndexJKISSStrings(
				lengthOfPossibleMappingsAbstract, NULL);
		char * selectedItemAbstractDeclaration = nthElementInListString(
				selectedMappingCandidate->possibleMappings,
				randomSelectedAbstractMapping);

		ListOfInt * alreadySelectedIndex = NULL;
		addNewInt(&alreadySelectedIndex, randomSelectedAbstractMapping);
		while (!strcmp(initialMappingCandidateCurrentMapping,
				selectedItemAbstractDeclaration)) {
			randomSelectedAbstractMapping = randomIndexJKISSStrings(
					lengthOfPossibleMappingsAbstract, alreadySelectedIndex);
			addNewInt(&alreadySelectedIndex, randomSelectedAbstractMapping);
			selectedItemAbstractDeclaration = nthElementInListString(
					selectedMappingCandidate->possibleMappings,
					randomSelectedAbstractMapping);
		}

		addNewCurrentMapping(&selectedMappingCandidate,
				selectedMappingCandidate->id, selectedItemAbstractDeclaration);
	}
}

ListOfInt * randomlySelectOneLOC(ArrayOfStrings SkeletonLOCsArray,
		ListOfInt * alreadySelectedLOCs) {
	//first generate a random index for a statement
	int randLOC = randomIndexJKISS(SkeletonLOCsArray.count,
			alreadySelectedLOCs);
	//construct the list of selected LOCs
	ListOfInt * listOfSelectedLOCsForIndividual = NULL;
	addNewInt(&listOfSelectedLOCsForIndividual, randLOC);

	return listOfSelectedLOCsForIndividual;
}

void randomlyAddANewLocalDeclarationMapping(
		DeclarationSymbolTable * GraftSymbolTablePossibleMatching) {

	int numberOfMappedElementsMorePosibilities =
			numberOfElementsWithCurrentMappingWithMoreThanOnePossibleMappings(
					GraftSymbolTablePossibleMatching);
	//check if at least one was found
	if (numberOfMappedElementsMorePosibilities > 0) {
		int randomSelectedReplaceDeclaration = randomIndexJKISSLoclDecl(
				numberOfMappedElementsMorePosibilities, NULL);
		DeclarationSymbolTable * selectedElement =
				nthElementWithCurrentMappingMoreThanOnePossible(
						GraftSymbolTablePossibleMatching,
						randomSelectedReplaceDeclaration);

		int lengthOfPosibilitiesNoCurrent =
				countElementsInListOfStringNotAnElement(
						selectedElement->possibleMappings,
						selectedElement->currentMapping);

		int randomIndexListOfString = randomIndexJKISSStrings(
				lengthOfPosibilitiesNoCurrent, NULL);

		char * newSelectedDeclMapping =
				nthElementInListStringExceptingOneString(
						selectedElement->possibleMappings,
						randomIndexListOfString,
						selectedElement->currentMapping);

		free(selectedElement->currentMapping);
		selectedElement->currentMapping = (char *) malloc(
				(strlen(newSelectedDeclMapping) + 1) * sizeof(char));

		strcpy(selectedElement->currentMapping, newSelectedDeclMapping);
	}

	/*
	 //this should be tried just for declarations with possible mappings
	 int randDeclarationMapping = randomIndex(lengthOfDeclarationMappings, NULL);
	 DeclarationSymbolTable * searchedEl = nthElementInDeclarationSymbolTablePointer(GraftSymbolTablePossibleMatching,
	 randDeclarationMapping);
	 //select randomly a possible mapping for current mapping
	 int lengthOfPossibleMappingsDeclaration = countElementsInListOfString(searchedEl->possibleMappings);
	 int randomSelectedDeclarationMapping = randomIndex(lengthOfPossibleMappingsDeclaration, NULL);
	 char * selectedItemDeclaration = nthElementInListString(searchedEl->possibleMappings,
	 randomSelectedDeclarationMapping);
	 addNewCurrentMappingDeclarationSymbolTable(&searchedEl, searchedEl->id, selectedItemDeclaration);

	 ListOfString * listOfDeclarationMappings = NULL;
	 addNewDeclarationSymbolTableToListOfStringForGPIndividual(&listOfDeclarationMappings, searchedEl->declarationMarker,
	 searchedEl->id, selectedItemDeclaration);

	 return listOfDeclarationMappings;
	 */

	//listOfDeclarationMappings = declarationSymbolTableToListOfStringForGPIndividual(searchedEl);
}
//For every LOC from the Skeleton add the used AbstractVariable,
//and for every declaration, add the declared variable Name, before this, in the prepare for GP

GPIndividual * generateInitialPopulation(
		MappingCandidate * MappingCandidatesForGP,
		DeclarationSymbolTable * GraftSymbolTablePossibleMatching,
		int lengthOfMappingCandidates, int lengthOfDeclarationMappings,
		ListOfString * SkeletonSourceCode, ArrayOfStrings SkeletonLOCsArray,
		char * GraftInterfaceTempOutput, char * InterfaceHeaderWithGlobalDecl,
		int TotalIDsInHostSymbolTable,
		DependencyList * ListOfDependenciesForStatements,
		char * skeletonInterfaceSourceCodeOutput,
		DependencyListWithID * dependencyListForAbstract,
		char * finalInterfaceHeaderForCompilation,
		SymbolTable * HostSymbolTable, char * TXLTemporaryFolder, ListOfString * listOfSourceFiles) {
	//generate initial population
	//random 1 statement selection
	//random 1 mapping (function argument or graft declaration mapping)

	fflush(stdout);

	GPIndividual * InitialPopulation = NULL;

	//test the correct one is passing the test suite!!!!!!!

#if 0
	int x = 0;
	if (x == 0) {
		ListOfString * originalInterfaceHeaderLOCs = readListOfStringFromFile(
				InterfaceHeaderWithGlobalDecl);
		printAListOfStrings(originalInterfaceHeaderLOCs,
				finalInterfaceHeaderForCompilation);
		ListOfInt * listOfSelectedLOCsForIndividual = NULL; //= randomlySelectOneLOC(SkeletonLOCsArray, NULL);

#if 1
		for (int jj = 0; jj < SkeletonLOCsArray.count; jj++) {
			addNewInt(&listOfSelectedLOCsForIndividual, jj);
		}
#endif

		//addNewInt(&listOfSelectedLOCsForIndividual, 7);

#if 0
		addNewInt(& listOfSelectedLOCsForIndividual, 14);
		addNewInt(& listOfSelectedLOCsForIndividual, 18);
		addNewInt(& listOfSelectedLOCsForIndividual, 19);
		addNewInt(& listOfSelectedLOCsForIndividual, 20);
		addNewInt(& listOfSelectedLOCsForIndividual, 21);
		addNewInt(& listOfSelectedLOCsForIndividual, 56);
		addNewInt(& listOfSelectedLOCsForIndividual, 57);
		addNewInt(& listOfSelectedLOCsForIndividual, 67);
		addNewInt(& listOfSelectedLOCsForIndividual, 74);
		addNewInt(& listOfSelectedLOCsForIndividual, 82);
		addNewInt(& listOfSelectedLOCsForIndividual, 83);
		addNewInt(& listOfSelectedLOCsForIndividual, 93);
		addNewInt(& listOfSelectedLOCsForIndividual, 94);
		addNewInt(& listOfSelectedLOCsForIndividual, 98);
		addNewInt(& listOfSelectedLOCsForIndividual, 99);
#endif

		MappingCandidate * copyOfOriginalMappingCandidate =
				copyListOfMappingCandidate(MappingCandidatesForGP);
		ArrayOfMappingCandidates arrayForCurrentMappingCandidate =
				returnListOfCandidatesWithMoreThanOnePossibleMappingPointers(
						copyOfOriginalMappingCandidate);
		if (arrayForCurrentMappingCandidate.count > 0) {
			//randomlySelectOneAbstactMappingAndOnePossibleMappingForIt(arrayForCurrentMappingCandidate);
		}
		Mapping * currentMappings = mappingCandidateToListOfMappingsForCurrent(
				copyOfOriginalMappingCandidate);

		Mapping * aux = currentMappings;
#if 1
		while(aux) {
			if(!strcmp(aux->source, "$ABSTRACT_2")) {
				aux->destination = (char *) malloc(100 * sizeof(char));
				strcpy(aux->destination,"$_main_sum");
			} else if(!strcmp(aux->source, "$ABSTRACT_3")) {
				aux->destination = (char *) malloc(100 * sizeof(char));
				strcpy(aux->destination,"$_foo_mean1");
			}
			aux = aux->next;
		}
#endif
		DeclarationSymbolTable * copyOfOriginalGraftDeclarationSymbolTable =
				copyDeclarationSymbolTableList(
						GraftSymbolTablePossibleMatching);

		DeclarationSymbolTable * auxFitted =
				copyOfOriginalGraftDeclarationSymbolTable;
#if 1
		while (auxFitted) {
			if (strstr(auxFitted->declarationMarker, "/* DECL: 1 */")) {
				auxFitted ->currentMapping = (char *) malloc(500 * sizeof (char));
				strcpy(auxFitted->currentMapping, "$_host_l");
			}
			auxFitted = auxFitted ->next;
		}
#endif
		GPIndividual * newIndividual = addNewGPIndividual(&InitialPopulation,
				NULL, listOfSelectedLOCsForIndividual, currentMappings, -1,
				copyOfOriginalMappingCandidate,
				copyOfOriginalGraftDeclarationSymbolTable);
		int MappedGraftHostIDs = returnNumberOfMappedIDsToHostSymbolTable(
				HostSymbolTable, newIndividual);
		instantiateGPCandidateWithExistingGlobalAndCoreFeatureGromGPIndividual(
				SkeletonSourceCode, SkeletonLOCsArray, newIndividual,
				ListOfDependenciesForStatements, GraftInterfaceTempOutput,
				skeletonInterfaceSourceCodeOutput,
				finalInterfaceHeaderForCompilation, dependencyListForAbstract,
				TXLTemporaryFolderMainThread);
		int LOCsInIndividual = countElementsInListOfInt(
				newIndividual->selectedLOCs);
		double fitness = computeFitness("Individual.x",
				TotalIDsInHostSymbolTable, MappedGraftHostIDs, LOCsInIndividual,
				TransplantResultLocation);
		//add the computed fitness
		newIndividual->fitness = fitness;
		printf("\t Fitness for individual: %s is : %0.2f\n", "Individual.x",
				fitness);
		fflush(stdout);
	}

	return NULL;

#endif

	for (int i = 0; i < POPULATION_LENGTH; i++) {

		//write in the final interface header, the initial one, with global declarations + graft function header
		//for instantiating it again, without keeping the other declarations
		ListOfString * originalInterfaceHeaderLOCs = readListOfStringFromFile(
				InterfaceHeaderWithGlobalDecl);
		printAListOfStrings(originalInterfaceHeaderLOCs,
				finalInterfaceHeaderForCompilation);

		//first generate a random LOC addition
		ListOfInt * listOfSelectedLOCsForIndividual = randomlySelectOneLOC(
				SkeletonLOCsArray, NULL);

		//make a new copy, since it should be new
		MappingCandidate * copyOfOriginalMappingCandidate =
				copyListOfMappingCandidate(MappingCandidatesForGP);

		//array of mapping candidates is needed here, since the individual is not yet computted
		ArrayOfMappingCandidates arrayForCurrentMappingCandidate =
				returnListOfCandidatesWithMoreThanOnePossibleMappingPointers(
						copyOfOriginalMappingCandidate);
		//just if there exists!
		if (arrayForCurrentMappingCandidate.count > 0) {
			randomlySelectOneAbstactMappingAndOnePossibleMappingForIt(
					arrayForCurrentMappingCandidate);
		}
		Mapping * currentMappings = mappingCandidateToListOfMappingsForCurrent(
				copyOfOriginalMappingCandidate);

		//add a random declaration mapping if it is the case (random selection; 50% chances)
		DeclarationSymbolTable * copyOfOriginalGraftDeclarationSymbolTable =
				copyDeclarationSymbolTableList(
						GraftSymbolTablePossibleMatching);

		addOneRandomCurrentMappingDeclarationSymbolTable(
                copyOfOriginalGraftDeclarationSymbolTable);

		//construct the list of abstract declaration mappings

		//change one declaration in declaration symbol table, if it is possible
		//randomlyAddANewLocalDeclarationMapping(copyOfOriginalGraftDeclarationSymbolTable);

		GPIndividual * newIndividual = addNewGPIndividual(&InitialPopulation,
				NULL, listOfSelectedLOCsForIndividual, currentMappings, -1,
				copyOfOriginalMappingCandidate,
				copyOfOriginalGraftDeclarationSymbolTable);
		//newIndividual->candidateMappings = copyOfOriginalMappingCandidate;
		//newIndividual->candidateDeclarationSymbolTable = copyOfOriginalGraftDeclarationSymbolTable;

		int MappedGraftHostIDs = returnNumberOfMappedIDsToHostSymbolTable(
				HostSymbolTable, newIndividual);

		instantiateGPCandidateWithExistingGlobalAndCoreFeatureGromGPIndividual(
				SkeletonSourceCode, SkeletonLOCsArray, newIndividual,
				ListOfDependenciesForStatements, GraftInterfaceTempOutput,
				skeletonInterfaceSourceCodeOutput,
				finalInterfaceHeaderForCompilation, dependencyListForAbstract,
				TXLTemporaryFolder, listOfSourceFiles);

		int LOCsInIndividual = countElementsInListOfInt(
				newIndividual->selectedLOCs);

		double fitness = computeFitness("Individual.x",
				TotalIDsInHostSymbolTable, MappedGraftHostIDs, LOCsInIndividual,
				TransplantResultLocation);

		if (fitness >= 1.04) {
			SUCCESFULL_INDIVIDUAL = newIndividual;
		}

		//add the computed fitness
		newIndividual->fitness = fitness;

		printf("G0 - Fitness for individual: %s is : %0.2f\n", "Individual.x",
				fitness);
		fflush(stdout);

	}
	return InitialPopulation;
}

#define END_INDIVIDUAL_MARKER "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"

//readtransplantecandidate file from individual instantiator

GPIndividual * readPopulation(char * inputCandidate,
		Mapping ** FinalMappingsInIndividual,
		ListOfString ** MappedDeclarations,
		ListOfInt ** ListOfCandidateSelectedLines) {

	GPIndividual * population = NULL;

	//count the number of mapped graft IDs to Host Symbol Table

	FILE * fin = fopen(inputCandidate, "r");

	char * line;
	line = (char *) malloc(3000 * sizeof(char));

	//read abstract mappings
	while (fgets(line, 2999, fin) != NULL) {
		fgets(line, 2999, fin);
		while (strcmp(line, DeclarationMappingsMarker)) {

			char * source;
			char * destination;
			source = (char*) malloc(500 * sizeof(char));
			destination = (char*) malloc(500 * sizeof(char));
			source = (char *) malloc(500 * sizeof(char));
			destination = (char *) malloc(500 * sizeof(char));
			sscanf(line, "%s %s", source, destination);
			addNewMapping(&(*FinalMappingsInIndividual), source, destination);
			free(source);
			free(destination);
			fgets(line, 2999, fin);
		}

		fgets(line, 2999, fin);
		while (strcmp(line, IndividualLinesMarker)) {

			char * declMarker;
			char * source;
			char * destination;

			declMarker = (char*) malloc(500 * sizeof(char));
			source = (char*) malloc(500 * sizeof(char));
			destination = (char*) malloc(500 * sizeof(char));
			char * token = strtok(line, "@");
			strcpy(declMarker, token);
			token = strtok(NULL, "@");
			strcpy(source, token);
			token = strtok(NULL, "@");
			strcpy(destination, token);
			//last character in destination is end of line
			destination[strlen(destination) - 1] = '\0';

			addNewMapping(&(*FinalMappingsInIndividual), source, destination);
			addNewString(&(*MappedDeclarations), declMarker);
			fgets(line, 2999, fin);
			free(declMarker);
			free(source);
			free(destination);
		}

		fgets(line, 2999, fin);
		while (strcmp(line, END_INDIVIDUAL_MARKER)) {
			int value;
			sscanf(line, "%d", &value);
			addNewInt(&(*ListOfCandidateSelectedLines), value);
		}

	}
	free(line);
	fclose(fin);
	return population;
}

GPIndividual * crossoverTwoGPIndividualsHalfAndAddAllCurrentDeclarations(
		GPIndividual * first, GPIndividual * second) {

	GPIndividual * springIndividual = copyAnGPIndividualCandidate(first);

	//in current individual, keep first half from its LOC and add the second half from the second individual
	ListOfInt * newListOfLOCs = NULL;
	int countOfLOCsInCurrentIndividual = countElementsInListOfInt(
			springIndividual->selectedLOCs);
	int countOfLOCsInSecondIndividual = countElementsInListOfInt(
			second->selectedLOCs);

	//if one of them has just 1 LOC, add it for both of them
	if (countOfLOCsInCurrentIndividual == 1) {
		countOfLOCsInCurrentIndividual++;
	}
	if (countOfLOCsInSecondIndividual == 1) {
		//since here, it will be parsed the first countOfLOCsInSecondIndividualElements
		countOfLOCsInSecondIndividual--;
	}

	//half from both of them
	countOfLOCsInCurrentIndividual = countOfLOCsInCurrentIndividual / 2;
	countOfLOCsInSecondIndividual = countOfLOCsInSecondIndividual / 2;

	ListOfInt * auxLOCsFirstIndividual = springIndividual->selectedLOCs;
	ListOfInt * auxLOCsSecondIndividual = second->selectedLOCs;

	while (auxLOCsFirstIndividual && countOfLOCsInCurrentIndividual) {
		if (!searchAnIntInListOfInt(newListOfLOCs,
				auxLOCsFirstIndividual->value)) {
			addNewInt(&newListOfLOCs, auxLOCsFirstIndividual->value);
			countOfLOCsInCurrentIndividual--;
		}
		auxLOCsFirstIndividual = auxLOCsFirstIndividual->next;
	}

	while (countOfLOCsInSecondIndividual) {
		auxLOCsSecondIndividual = auxLOCsSecondIndividual->next;
		countOfLOCsInSecondIndividual--;
	}

	while (auxLOCsSecondIndividual) {
		if (!searchAnIntInListOfInt(newListOfLOCs,
				auxLOCsSecondIndividual->value)) {
			addNewInt(&newListOfLOCs, auxLOCsSecondIndividual->value);
		}
		auxLOCsSecondIndividual = auxLOCsSecondIndividual->next;
	}

	//HERE ADD NEW INDIVIDUAL!!!
	freeListOfInt(&springIndividual->selectedLOCs);
	springIndividual->selectedLOCs = newListOfLOCs;

	//solve abstract values combinations; half from first and half from second
	//in current individual, keep first half from its LOC and add the second half from the second individual
	MappingCandidate * newListMappingCandidates = NULL;
	int countOfMappingCandidatesInCurrentIndividual =
			countElementsInListOfMappingCandidate(
					springIndividual->candidateMappings);
	int countOfMappingCandidatesInSecondIndividual =
			countElementsInListOfMappingCandidate(second->candidateMappings);

	//special case if they are odd numbers
	//half from both of them; should be equal
	if (countOfMappingCandidatesInCurrentIndividual % 2 == 0) {
		countOfMappingCandidatesInCurrentIndividual =
				countOfMappingCandidatesInCurrentIndividual / 2;

	} else {
		countOfMappingCandidatesInCurrentIndividual =
				(countOfMappingCandidatesInCurrentIndividual / 2) + 1;

	}
	//countOfMappingCandidatesInCurrentIndividual = countOfMappingCandidatesInCurrentIndividual / 2;
	countOfMappingCandidatesInSecondIndividual =
			countOfMappingCandidatesInSecondIndividual / 2;

	MappingCandidate * auxMappingCandidateFirstIndividual =
			springIndividual->candidateMappings;
	MappingCandidate * auxMappingCandidatesSecondIndividual =
			second->candidateMappings;

	while (auxMappingCandidateFirstIndividual
			&& countOfMappingCandidatesInCurrentIndividual) {
		addNewMappingCandidateFromMappingCandidateElement(
				&newListMappingCandidates, auxMappingCandidateFirstIndividual);
		countOfMappingCandidatesInCurrentIndividual--;
		auxMappingCandidateFirstIndividual =
				auxMappingCandidateFirstIndividual->next;
	}

	while (countOfMappingCandidatesInSecondIndividual) {
		auxMappingCandidatesSecondIndividual =
				auxMappingCandidatesSecondIndividual->next;
		countOfMappingCandidatesInSecondIndividual--;
	}

	while (auxMappingCandidatesSecondIndividual) {
		addNewMappingCandidateFromMappingCandidateElement(
				&newListMappingCandidates,
				auxMappingCandidatesSecondIndividual);
		auxMappingCandidatesSecondIndividual =
				auxMappingCandidatesSecondIndividual->next;
	}

	//here add new individual!!!
	freeMappingCandidateList(&springIndividual->candidateMappings);
	springIndividual->candidateMappings = newListMappingCandidates;

	//solve local declarations mappings; half from first and half from second
	//in current individual, keep first half from its LOC and add the second half from the second individual
	DeclarationSymbolTable * newListDeclarationSymbolTable = NULL;

	DeclarationSymbolTable * auxDeclarationSymbolTableFirstIndividual =
			springIndividual->candidateDeclarationSymbolTable;
	DeclarationSymbolTable * auxDeclarationSymbolTableSecondIndividual =
			second->candidateDeclarationSymbolTable;

	//the two individuals symbol table should be in concordance, so we can do here like this
	while (auxDeclarationSymbolTableFirstIndividual
			&& auxDeclarationSymbolTableSecondIndividual) {

		if (auxDeclarationSymbolTableFirstIndividual->currentMapping
				&& !auxDeclarationSymbolTableSecondIndividual->currentMapping) {
			//just first has current mapping, so add it
			addNewDeclarationSymbolTableFromDeclSymbolTableEl(
					&newListDeclarationSymbolTable,
					auxDeclarationSymbolTableFirstIndividual);
		} else if (!auxDeclarationSymbolTableFirstIndividual->currentMapping
				&& auxDeclarationSymbolTableSecondIndividual->currentMapping) {
			//just the second individual has current mapping, so add it!
			addNewDeclarationSymbolTableFromDeclSymbolTableEl(
					&newListDeclarationSymbolTable,
					auxDeclarationSymbolTableSecondIndividual);
		} else if (auxDeclarationSymbolTableFirstIndividual->currentMapping
				&& auxDeclarationSymbolTableSecondIndividual->currentMapping) {
			//both of them have, so random choose
			int randomFirstOrSecond = randomIndexJKISSStrings(2, NULL);
			if (randomFirstOrSecond == 0) {
				addNewDeclarationSymbolTableFromDeclSymbolTableEl(
						&newListDeclarationSymbolTable,
						auxDeclarationSymbolTableFirstIndividual);
			} else {
				addNewDeclarationSymbolTableFromDeclSymbolTableEl(
						&newListDeclarationSymbolTable,
						auxDeclarationSymbolTableSecondIndividual);
			}
		} else {
			//no one has, so both of them are the same; just choose the first one
			addNewDeclarationSymbolTableFromDeclSymbolTableEl(
					&newListDeclarationSymbolTable,
					auxDeclarationSymbolTableFirstIndividual);
		}

		auxDeclarationSymbolTableFirstIndividual =
				auxDeclarationSymbolTableFirstIndividual->next;
		auxDeclarationSymbolTableSecondIndividual =
				auxDeclarationSymbolTableSecondIndividual->next;
	}

	//here add new GPIndividual
	freeDeclarationSymbolTable(
			&springIndividual->candidateDeclarationSymbolTable);
	springIndividual->candidateDeclarationSymbolTable =
			newListDeclarationSymbolTable;

	return springIndividual;
}

GPIndividual * crossoverTwoGPIndividuals(GPIndividual * first,
		GPIndividual * secondIndividual) {

	GPIndividual * springIndividual = copyAnGPIndividualCandidate(first);
	GPIndividual * second = copyAnGPIndividualCandidate(secondIndividual);

	//in current individual, keep first half from its LOC and add the second half from the second individual
	ListOfInt * newListOfLOCs = NULL;
	int countOfLOCsInCurrentIndividual = countElementsInListOfInt(
			springIndividual->selectedLOCs);
	int countOfLOCsInSecondIndividual = countElementsInListOfInt(
			second->selectedLOCs);

	//if one of them has just 1 LOC, add it for both of them
	if (countOfLOCsInCurrentIndividual == 1) {
		countOfLOCsInCurrentIndividual++;
	}
	if (countOfLOCsInSecondIndividual == 1) {
		//since here, it will be parsed the first countOfLOCsInSecondIndividualElements
		countOfLOCsInSecondIndividual--;
	}

	//half from both of them
	countOfLOCsInCurrentIndividual = countOfLOCsInCurrentIndividual / 2;
	countOfLOCsInSecondIndividual = countOfLOCsInSecondIndividual / 2;

	ListOfInt * auxLOCsFirstIndividual = springIndividual->selectedLOCs;
	ListOfInt * auxLOCsSecondIndividual = second->selectedLOCs;

	while (auxLOCsFirstIndividual && countOfLOCsInCurrentIndividual) {
		if (!searchAnIntInListOfInt(newListOfLOCs,
				auxLOCsFirstIndividual->value)) {
			addNewInt(&newListOfLOCs, auxLOCsFirstIndividual->value);
			countOfLOCsInCurrentIndividual--;
		}
		auxLOCsFirstIndividual = auxLOCsFirstIndividual->next;
	}

	while (countOfLOCsInSecondIndividual) {
		auxLOCsSecondIndividual = auxLOCsSecondIndividual->next;
		countOfLOCsInSecondIndividual--;
	}

	while (auxLOCsSecondIndividual) {
		if (!searchAnIntInListOfInt(newListOfLOCs,
				auxLOCsSecondIndividual->value)) {
			addNewInt(&newListOfLOCs, auxLOCsSecondIndividual->value);
		}
		auxLOCsSecondIndividual = auxLOCsSecondIndividual->next;
	}

	//HERE ADD NEW INDIVIDUAL!!!
	freeListOfInt(&springIndividual->selectedLOCs);
	springIndividual->selectedLOCs = newListOfLOCs;

	//solve abstract values combinations; half from first and half from second
	//in current individual, keep first half from its LOC and add the second half from the second individual

	//new version, random selection at every step from a current one first or sec individual
	//the number of elements and the order of them is the same for both of them!!
	MappingCandidate * newListMappingCandidates = NULL;

	MappingCandidate * auxMappingCandidateFirstIndividual =
			springIndividual->candidateMappings;
	MappingCandidate * auxMappingCandidatesSecondIndividual =
			second->candidateMappings;

	while (auxMappingCandidateFirstIndividual
			&& auxMappingCandidatesSecondIndividual) {
		int firstOrSecond = randomIndexJKISSStrings(2, NULL);

		if (firstOrSecond == 0) {
			addNewMappingCandidateFromMappingCandidateElement(
					&newListMappingCandidates,
					auxMappingCandidateFirstIndividual);
		} else {
			addNewMappingCandidateFromMappingCandidateElement(
					&newListMappingCandidates,
					auxMappingCandidatesSecondIndividual);
		}

		auxMappingCandidateFirstIndividual =
				auxMappingCandidateFirstIndividual->next;
		auxMappingCandidatesSecondIndividual =
				auxMappingCandidatesSecondIndividual->next;

	}

	/*
	 MappingCandidate * newListMappingCandidates = NULL;
	 int countOfMappingCandidatesInCurrentIndividual =
	 countElementsInListOfMappingCandidate(springIndividual->candidateMappings);
	 int countOfMappingCandidatesInSecondIndividual =
	 countElementsInListOfMappingCandidate(second->candidateMappings);

	 //special case if they are odd numbers
	 //half from both of them; should be equal
	 if (countOfMappingCandidatesInCurrentIndividual % 2 == 0) {
	 countOfMappingCandidatesInCurrentIndividual = countOfMappingCandidatesInCurrentIndividual / 2;

	 } else {
	 countOfMappingCandidatesInCurrentIndividual = (countOfMappingCandidatesInCurrentIndividual / 2) + 1;

	 }
	 //countOfMappingCandidatesInCurrentIndividual = countOfMappingCandidatesInCurrentIndividual / 2;
	 countOfMappingCandidatesInSecondIndividual = countOfMappingCandidatesInSecondIndividual / 2;

	 MappingCandidate * auxMappingCandidateFirstIndividual = springIndividual->candidateMappings;
	 MappingCandidate * auxMappingCandidatesSecondIndividual = second->candidateMappings;

	 while (auxMappingCandidateFirstIndividual && countOfMappingCandidatesInCurrentIndividual) {
	 addNewMappingCandidateFromMappingCandidateElement(&newListMappingCandidates,
	 auxMappingCandidateFirstIndividual);
	 countOfMappingCandidatesInCurrentIndividual--;
	 auxMappingCandidateFirstIndividual = auxMappingCandidateFirstIndividual->next;
	 }

	 while (countOfMappingCandidatesInSecondIndividual) {
	 auxMappingCandidatesSecondIndividual = auxMappingCandidatesSecondIndividual->next;
	 countOfMappingCandidatesInSecondIndividual--;
	 }

	 while (auxMappingCandidatesSecondIndividual) {
	 addNewMappingCandidateFromMappingCandidateElement(&newListMappingCandidates,
	 auxMappingCandidatesSecondIndividual);
	 auxMappingCandidatesSecondIndividual = auxMappingCandidatesSecondIndividual->next;
	 }

	 //here add new individual!!!
	 freeMappingCandidateList(&springIndividual->candidateMappings);
	 springIndividual->candidateMappings = newListMappingCandidates;
	 */

	//solve local declarations mappings; half from first and half from second
	//in current individual, keep first half from its LOC and add the second half from the second individual
	//new Version... the number of elements are not necesarry the same, so in this case
	//we will search for element!!
	DeclarationSymbolTable * newListDeclarationSymbolTable = NULL;

	DeclarationSymbolTable * auxDeclarationSymbolTableFirstIndividual =
			springIndividual->candidateDeclarationSymbolTable;
	DeclarationSymbolTable * auxDeclarationSymbolTableSecondIndividual =
			second->candidateDeclarationSymbolTable;

	while (auxDeclarationSymbolTableFirstIndividual) {

		DeclarationSymbolTable * elementInSecond =
				searchAnElementInDeclarationSymbolTable(
						auxDeclarationSymbolTableSecondIndividual,
						auxDeclarationSymbolTableFirstIndividual);

		if (elementInSecond) {
			int firstOrSecond = randomIndexJKISSStrings(2, NULL);
			if (firstOrSecond == 0) {

			} else {
				free(auxDeclarationSymbolTableFirstIndividual->currentMapping);
				auxDeclarationSymbolTableFirstIndividual->currentMapping =
						(char *) malloc(1000 * sizeof(char));
				strcpy(auxDeclarationSymbolTableFirstIndividual->currentMapping,
						elementInSecond->currentMapping);
			}

			free(elementInSecond->currentMapping);
			free(elementInSecond->declarationMarker);
			free(elementInSecond->type);

			elementInSecond->currentMapping = NULL;
			elementInSecond->declarationMarker = NULL;
			elementInSecond->type = NULL;
		}

		addNewDeclarationSymbolTableFromDeclSymbolTableEl(
				&newListDeclarationSymbolTable,
				auxDeclarationSymbolTableFirstIndividual);

		auxDeclarationSymbolTableFirstIndividual =
				auxDeclarationSymbolTableFirstIndividual->next;
	}

	while (auxDeclarationSymbolTableSecondIndividual) {

		if (auxDeclarationSymbolTableSecondIndividual->declarationMarker
				&& auxDeclarationSymbolTableSecondIndividual->type) {
			addNewDeclarationSymbolTableFromDeclSymbolTableEl(
					&newListDeclarationSymbolTable,
					auxDeclarationSymbolTableSecondIndividual);
		}

		auxDeclarationSymbolTableSecondIndividual =
				auxDeclarationSymbolTableSecondIndividual->next;
	}

	/*
	 DeclarationSymbolTable * newListDeclarationSymbolTable = NULL;
	 int countOfDeclarationSymbolTableInCurrentIndividual =
	 countElementsInDeclarationSymbolTable(springIndividual->candidateDeclarationSymbolTable);
	 int countOfDeclarationSymbolTableInSecondIndividual =
	 countElementsInDeclarationSymbolTable(second->candidateDeclarationSymbolTable);

	 //special case if they are odd numbers
	 //half from both of them; should be equal
	 if (countOfDeclarationSymbolTableInCurrentIndividual % 2 == 0) {
	 countOfDeclarationSymbolTableInCurrentIndividual = countOfDeclarationSymbolTableInCurrentIndividual / 2;

	 } else {
	 countOfDeclarationSymbolTableInCurrentIndividual = (countOfDeclarationSymbolTableInCurrentIndividual / 2) + 1;

	 }
	 countOfDeclarationSymbolTableInSecondIndividual = countOfDeclarationSymbolTableInSecondIndividual / 2;




	 DeclarationSymbolTable * auxDeclarationSymbolTableFirstIndividual =
	 springIndividual->candidateDeclarationSymbolTable;
	 DeclarationSymbolTable * auxDeclarationSymbolTableSecondIndividual =
	 second->candidateDeclarationSymbolTable;

	 while (auxDeclarationSymbolTableFirstIndividual && countOfDeclarationSymbolTableInCurrentIndividual) {

	 addNewDeclarationSymbolTableFromDeclSymbolTableEl(&newListDeclarationSymbolTable,
	 auxDeclarationSymbolTableFirstIndividual);

	 countOfDeclarationSymbolTableInCurrentIndividual--;
	 auxDeclarationSymbolTableFirstIndividual = auxDeclarationSymbolTableFirstIndividual->next;
	 }

	 while (countOfDeclarationSymbolTableInSecondIndividual) {
	 auxDeclarationSymbolTableSecondIndividual = auxDeclarationSymbolTableSecondIndividual->next;
	 countOfDeclarationSymbolTableInSecondIndividual--;
	 }

	 while (auxDeclarationSymbolTableSecondIndividual) {
	 addNewDeclarationSymbolTableFromDeclSymbolTableEl(&newListDeclarationSymbolTable,
	 auxDeclarationSymbolTableSecondIndividual);
	 auxDeclarationSymbolTableSecondIndividual = auxDeclarationSymbolTableSecondIndividual->next;
	 }
	 */

	//here add new GPIndividual
	freeDeclarationSymbolTable(
			&springIndividual->candidateDeclarationSymbolTable);
	springIndividual->candidateDeclarationSymbolTable =
			newListDeclarationSymbolTable;

	return springIndividual;
}

GPIndividual * crossoverTwoGPIndividualsAllLOCs(GPIndividual * first,
		GPIndividual * secondIndividual) {

	GPIndividual * springIndividual = copyAnGPIndividualCandidate(first);
	GPIndividual * second = copyAnGPIndividualCandidate(secondIndividual);

	//in current individual, keep both LOCs
	ListOfInt * newListOfLOCs = NULL;
	ListOfInt * auxLOCsFirstIndividual = springIndividual->selectedLOCs;
	ListOfInt * auxLOCsSecondIndividual = second->selectedLOCs;

	while (auxLOCsFirstIndividual) {
		addNewInt(&newListOfLOCs, auxLOCsFirstIndividual->value);
		auxLOCsFirstIndividual = auxLOCsFirstIndividual->next;
	}

	while (auxLOCsSecondIndividual) {
		if (!searchAnIntInListOfInt(newListOfLOCs,
				auxLOCsSecondIndividual->value)) {
			addNewInt(&newListOfLOCs, auxLOCsSecondIndividual->value);
		}
		auxLOCsSecondIndividual = auxLOCsSecondIndividual->next;
	}

	/*
	 ListOfInt * newListOfLOCs = NULL;
	 int countOfLOCsInCurrentIndividual = countElementsInListOfInt(springIndividual->selectedLOCs);
	 int countOfLOCsInSecondIndividual = countElementsInListOfInt(second->selectedLOCs);

	 //if one of them has just 1 LOC, add it for both of them
	 if (countOfLOCsInCurrentIndividual == 1) {
	 countOfLOCsInCurrentIndividual++;
	 }
	 if (countOfLOCsInSecondIndividual == 1) {
	 //since here, it will be parsed the first countOfLOCsInSecondIndividualElements
	 countOfLOCsInSecondIndividual--;
	 }

	 //half from both of them
	 countOfLOCsInCurrentIndividual = countOfLOCsInCurrentIndividual / 2;
	 countOfLOCsInSecondIndividual = countOfLOCsInSecondIndividual / 2;

	 ListOfInt * auxLOCsFirstIndividual = springIndividual->selectedLOCs;
	 ListOfInt * auxLOCsSecondIndividual = second->selectedLOCs;

	 while (auxLOCsFirstIndividual && countOfLOCsInCurrentIndividual) {
	 addNewInt(&newListOfLOCs, auxLOCsFirstIndividual->value);
	 countOfLOCsInCurrentIndividual--;
	 auxLOCsFirstIndividual = auxLOCsFirstIndividual->next;
	 }

	 while (countOfLOCsInSecondIndividual) {
	 auxLOCsSecondIndividual = auxLOCsSecondIndividual->next;
	 countOfLOCsInSecondIndividual--;
	 }

	 while (auxLOCsSecondIndividual) {
	 if (!searchAnIntInListOfInt(newListOfLOCs, auxLOCsSecondIndividual->value)) {
	 addNewInt(&newListOfLOCs, auxLOCsSecondIndividual->value);
	 }
	 auxLOCsSecondIndividual = auxLOCsSecondIndividual->next;
	 }
	 */

	//HERE ADD NEW INDIVIDUAL!!!
	freeListOfInt(&springIndividual->selectedLOCs);
	springIndividual->selectedLOCs = newListOfLOCs;

	//solve abstract values combinations; half from first and half from second
	//in current individual, keep first half from its LOC and add the second half from the second individual

	//new version, random selection at every step from a current one first or sec individual
	//the number of elements and the order of them is the same for both of them!!
	MappingCandidate * newListMappingCandidates = NULL;

	MappingCandidate * auxMappingCandidateFirstIndividual =
			springIndividual->candidateMappings;
	MappingCandidate * auxMappingCandidatesSecondIndividual =
			second->candidateMappings;

	while (auxMappingCandidateFirstIndividual
			&& auxMappingCandidatesSecondIndividual) {
		int firstOrSecond = randomIndexJKISSStrings(2, NULL);

		if (firstOrSecond == 0) {
			addNewMappingCandidateFromMappingCandidateElement(
					&newListMappingCandidates,
					auxMappingCandidateFirstIndividual);
		} else {
			addNewMappingCandidateFromMappingCandidateElement(
					&newListMappingCandidates,
					auxMappingCandidatesSecondIndividual);
		}

		auxMappingCandidateFirstIndividual =
				auxMappingCandidateFirstIndividual->next;
		auxMappingCandidatesSecondIndividual =
				auxMappingCandidatesSecondIndividual->next;

	}

	/*
	 MappingCandidate * newListMappingCandidates = NULL;
	 int countOfMappingCandidatesInCurrentIndividual =
	 countElementsInListOfMappingCandidate(springIndividual->candidateMappings);
	 int countOfMappingCandidatesInSecondIndividual =
	 countElementsInListOfMappingCandidate(second->candidateMappings);

	 //special case if they are odd numbers
	 //half from both of them; should be equal
	 if (countOfMappingCandidatesInCurrentIndividual % 2 == 0) {
	 countOfMappingCandidatesInCurrentIndividual = countOfMappingCandidatesInCurrentIndividual / 2;

	 } else {
	 countOfMappingCandidatesInCurrentIndividual = (countOfMappingCandidatesInCurrentIndividual / 2) + 1;

	 }
	 //countOfMappingCandidatesInCurrentIndividual = countOfMappingCandidatesInCurrentIndividual / 2;
	 countOfMappingCandidatesInSecondIndividual = countOfMappingCandidatesInSecondIndividual / 2;

	 MappingCandidate * auxMappingCandidateFirstIndividual = springIndividual->candidateMappings;
	 MappingCandidate * auxMappingCandidatesSecondIndividual = second->candidateMappings;

	 while (auxMappingCandidateFirstIndividual && countOfMappingCandidatesInCurrentIndividual) {
	 addNewMappingCandidateFromMappingCandidateElement(&newListMappingCandidates,
	 auxMappingCandidateFirstIndividual);
	 countOfMappingCandidatesInCurrentIndividual--;
	 auxMappingCandidateFirstIndividual = auxMappingCandidateFirstIndividual->next;
	 }

	 while (countOfMappingCandidatesInSecondIndividual) {
	 auxMappingCandidatesSecondIndividual = auxMappingCandidatesSecondIndividual->next;
	 countOfMappingCandidatesInSecondIndividual--;
	 }

	 while (auxMappingCandidatesSecondIndividual) {
	 addNewMappingCandidateFromMappingCandidateElement(&newListMappingCandidates,
	 auxMappingCandidatesSecondIndividual);
	 auxMappingCandidatesSecondIndividual = auxMappingCandidatesSecondIndividual->next;
	 }

	 //here add new individual!!!
	 freeMappingCandidateList(&springIndividual->candidateMappings);
	 springIndividual->candidateMappings = newListMappingCandidates;
	 */

	//solve local declarations mappings; half from first and half from second
	//in current individual, keep first half from its LOC and add the second half from the second individual
	//new Version... the number of elements are not necesarry the same, so in this case
	//we will search for element!!
	DeclarationSymbolTable * newListDeclarationSymbolTable = NULL;

	DeclarationSymbolTable * auxDeclarationSymbolTableFirstIndividual =
			springIndividual->candidateDeclarationSymbolTable;
	DeclarationSymbolTable * auxDeclarationSymbolTableSecondIndividual =
			second->candidateDeclarationSymbolTable;

	while (auxDeclarationSymbolTableFirstIndividual) {

		DeclarationSymbolTable * elementInSecond =
				searchAnElementInDeclarationSymbolTable(
						auxDeclarationSymbolTableSecondIndividual,
						auxDeclarationSymbolTableFirstIndividual);

		if (elementInSecond) {
			int firstOrSecond = randomIndexJKISSStrings(2, NULL);
			if (firstOrSecond == 0) {

			} else {
				free(auxDeclarationSymbolTableFirstIndividual->currentMapping);
				auxDeclarationSymbolTableFirstIndividual->currentMapping =
						(char *) malloc(1000 * sizeof(char));
				strcpy(auxDeclarationSymbolTableFirstIndividual->currentMapping,
						elementInSecond->currentMapping);
			}

			free(elementInSecond->currentMapping);
			free(elementInSecond->declarationMarker);
			free(elementInSecond->type);

			elementInSecond->currentMapping = NULL;
			elementInSecond->declarationMarker = NULL;
			elementInSecond->type = NULL;
		}

		addNewDeclarationSymbolTableFromDeclSymbolTableEl(
				&newListDeclarationSymbolTable,
				auxDeclarationSymbolTableFirstIndividual);

		auxDeclarationSymbolTableFirstIndividual =
				auxDeclarationSymbolTableFirstIndividual->next;
	}

	while (auxDeclarationSymbolTableSecondIndividual) {

		if (auxDeclarationSymbolTableSecondIndividual->declarationMarker
				&& auxDeclarationSymbolTableSecondIndividual->type) {
			addNewDeclarationSymbolTableFromDeclSymbolTableEl(
					&newListDeclarationSymbolTable,
					auxDeclarationSymbolTableSecondIndividual);
		}

		auxDeclarationSymbolTableSecondIndividual =
				auxDeclarationSymbolTableSecondIndividual->next;
	}

	/*
	 DeclarationSymbolTable * newListDeclarationSymbolTable = NULL;
	 int countOfDeclarationSymbolTableInCurrentIndividual =
	 countElementsInDeclarationSymbolTable(springIndividual->candidateDeclarationSymbolTable);
	 int countOfDeclarationSymbolTableInSecondIndividual =
	 countElementsInDeclarationSymbolTable(second->candidateDeclarationSymbolTable);

	 //special case if they are odd numbers
	 //half from both of them; should be equal
	 if (countOfDeclarationSymbolTableInCurrentIndividual % 2 == 0) {
	 countOfDeclarationSymbolTableInCurrentIndividual = countOfDeclarationSymbolTableInCurrentIndividual / 2;

	 } else {
	 countOfDeclarationSymbolTableInCurrentIndividual = (countOfDeclarationSymbolTableInCurrentIndividual / 2) + 1;

	 }
	 countOfDeclarationSymbolTableInSecondIndividual = countOfDeclarationSymbolTableInSecondIndividual / 2;




	 DeclarationSymbolTable * auxDeclarationSymbolTableFirstIndividual =
	 springIndividual->candidateDeclarationSymbolTable;
	 DeclarationSymbolTable * auxDeclarationSymbolTableSecondIndividual =
	 second->candidateDeclarationSymbolTable;

	 while (auxDeclarationSymbolTableFirstIndividual && countOfDeclarationSymbolTableInCurrentIndividual) {

	 addNewDeclarationSymbolTableFromDeclSymbolTableEl(&newListDeclarationSymbolTable,
	 auxDeclarationSymbolTableFirstIndividual);

	 countOfDeclarationSymbolTableInCurrentIndividual--;
	 auxDeclarationSymbolTableFirstIndividual = auxDeclarationSymbolTableFirstIndividual->next;
	 }

	 while (countOfDeclarationSymbolTableInSecondIndividual) {
	 auxDeclarationSymbolTableSecondIndividual = auxDeclarationSymbolTableSecondIndividual->next;
	 countOfDeclarationSymbolTableInSecondIndividual--;
	 }

	 while (auxDeclarationSymbolTableSecondIndividual) {
	 addNewDeclarationSymbolTableFromDeclSymbolTableEl(&newListDeclarationSymbolTable,
	 auxDeclarationSymbolTableSecondIndividual);
	 auxDeclarationSymbolTableSecondIndividual = auxDeclarationSymbolTableSecondIndividual->next;
	 }
	 */

	//here add new GPIndividual
	freeDeclarationSymbolTable(
			&springIndividual->candidateDeclarationSymbolTable);
	springIndividual->candidateDeclarationSymbolTable =
			newListDeclarationSymbolTable;

	return springIndividual;
}

GPIndividual * crossoverTwoGPIndividualsAllLOCsNewVers(GPIndividual * first,
		GPIndividual * secondIndividual) {

	GPIndividual * springIndividual = copyAnGPIndividualCandidate(first);
	GPIndividual * second = copyAnGPIndividualCandidate(secondIndividual);

	//in current individual, keep both LOCs
	ListOfInt * newListOfLOCs = NULL;
	ListOfInt * auxLOCsFirstIndividual = springIndividual->selectedLOCs;
	ListOfInt * auxLOCsSecondIndividual = second->selectedLOCs;

	while (auxLOCsFirstIndividual) {
		addNewInt(&newListOfLOCs, auxLOCsFirstIndividual->value);
		auxLOCsFirstIndividual = auxLOCsFirstIndividual->next;
	}

	while (auxLOCsSecondIndividual) {
		if (!searchAnIntInListOfInt(newListOfLOCs,
				auxLOCsSecondIndividual->value)) {
			addNewInt(&newListOfLOCs, auxLOCsSecondIndividual->value);
		}
		auxLOCsSecondIndividual = auxLOCsSecondIndividual->next;
	}

	/*
	 ListOfInt * newListOfLOCs = NULL;
	 int countOfLOCsInCurrentIndividual = countElementsInListOfInt(springIndividual->selectedLOCs);
	 int countOfLOCsInSecondIndividual = countElementsInListOfInt(second->selectedLOCs);

	 //if one of them has just 1 LOC, add it for both of them
	 if (countOfLOCsInCurrentIndividual == 1) {
	 countOfLOCsInCurrentIndividual++;
	 }
	 if (countOfLOCsInSecondIndividual == 1) {
	 //since here, it will be parsed the first countOfLOCsInSecondIndividualElements
	 countOfLOCsInSecondIndividual--;
	 }

	 //half from both of them
	 countOfLOCsInCurrentIndividual = countOfLOCsInCurrentIndividual / 2;
	 countOfLOCsInSecondIndividual = countOfLOCsInSecondIndividual / 2;

	 ListOfInt * auxLOCsFirstIndividual = springIndividual->selectedLOCs;
	 ListOfInt * auxLOCsSecondIndividual = second->selectedLOCs;

	 while (auxLOCsFirstIndividual && countOfLOCsInCurrentIndividual) {
	 addNewInt(&newListOfLOCs, auxLOCsFirstIndividual->value);
	 countOfLOCsInCurrentIndividual--;
	 auxLOCsFirstIndividual = auxLOCsFirstIndividual->next;
	 }

	 while (countOfLOCsInSecondIndividual) {
	 auxLOCsSecondIndividual = auxLOCsSecondIndividual->next;
	 countOfLOCsInSecondIndividual--;
	 }

	 while (auxLOCsSecondIndividual) {
	 if (!searchAnIntInListOfInt(newListOfLOCs, auxLOCsSecondIndividual->value)) {
	 addNewInt(&newListOfLOCs, auxLOCsSecondIndividual->value);
	 }
	 auxLOCsSecondIndividual = auxLOCsSecondIndividual->next;
	 }
	 */

	//HERE ADD NEW INDIVIDUAL!!!
	freeListOfInt(&springIndividual->selectedLOCs);
	springIndividual->selectedLOCs = newListOfLOCs;

	//solve abstract values combinations; half from first and half from second
	//in current individual, keep first half from its LOC and add the second half from the second individual

	//new version, random selection at every step from a current one first or sec individual
	//the number of elements and the order of them is the same for both of them!!
	MappingCandidate * newListMappingCandidates = NULL;

	MappingCandidate * auxMappingCandidateFirstIndividual =
			springIndividual->candidateMappings;
	//MappingCandidate * auxMappingCandidatesSecondIndividual = second->candidateMappings;

	while (auxMappingCandidateFirstIndividual) {
		addNewMappingCandidateFromMappingCandidateElement(
				&newListMappingCandidates, auxMappingCandidateFirstIndividual);
		auxMappingCandidateFirstIndividual =
				auxMappingCandidateFirstIndividual->next;
	}

	/*
	 MappingCandidate * newListMappingCandidates = NULL;
	 int countOfMappingCandidatesInCurrentIndividual =
	 countElementsInListOfMappingCandidate(springIndividual->candidateMappings);
	 int countOfMappingCandidatesInSecondIndividual =
	 countElementsInListOfMappingCandidate(second->candidateMappings);

	 //special case if they are odd numbers
	 //half from both of them; should be equal
	 if (countOfMappingCandidatesInCurrentIndividual % 2 == 0) {
	 countOfMappingCandidatesInCurrentIndividual = countOfMappingCandidatesInCurrentIndividual / 2;

	 } else {
	 countOfMappingCandidatesInCurrentIndividual = (countOfMappingCandidatesInCurrentIndividual / 2) + 1;

	 }
	 //countOfMappingCandidatesInCurrentIndividual = countOfMappingCandidatesInCurrentIndividual / 2;
	 countOfMappingCandidatesInSecondIndividual = countOfMappingCandidatesInSecondIndividual / 2;

	 MappingCandidate * auxMappingCandidateFirstIndividual = springIndividual->candidateMappings;
	 MappingCandidate * auxMappingCandidatesSecondIndividual = second->candidateMappings;

	 while (auxMappingCandidateFirstIndividual && countOfMappingCandidatesInCurrentIndividual) {
	 addNewMappingCandidateFromMappingCandidateElement(&newListMappingCandidates,
	 auxMappingCandidateFirstIndividual);
	 countOfMappingCandidatesInCurrentIndividual--;
	 auxMappingCandidateFirstIndividual = auxMappingCandidateFirstIndividual->next;
	 }

	 while (countOfMappingCandidatesInSecondIndividual) {
	 auxMappingCandidatesSecondIndividual = auxMappingCandidatesSecondIndividual->next;
	 countOfMappingCandidatesInSecondIndividual--;
	 }

	 while (auxMappingCandidatesSecondIndividual) {
	 addNewMappingCandidateFromMappingCandidateElement(&newListMappingCandidates,
	 auxMappingCandidatesSecondIndividual);
	 auxMappingCandidatesSecondIndividual = auxMappingCandidatesSecondIndividual->next;
	 }

	 //here add new individual!!!
	 freeMappingCandidateList(&springIndividual->candidateMappings);
	 springIndividual->candidateMappings = newListMappingCandidates;
	 */

	//solve local declarations mappings; half from first and half from second
	//in current individual, keep first half from its LOC and add the second half from the second individual
	//new Version... the number of elements are not necesarry the same, so in this case
	//we will search for element!!
	DeclarationSymbolTable * newListDeclarationSymbolTable = NULL;

	DeclarationSymbolTable * auxDeclarationSymbolTableFirstIndividual =
			springIndividual->candidateDeclarationSymbolTable;
	//DeclarationSymbolTable * auxDeclarationSymbolTableSecondIndividual =
	//        second->candidateDeclarationSymbolTable;

	while (auxDeclarationSymbolTableFirstIndividual) {
		addNewDeclarationSymbolTableFromDeclSymbolTableEl(
				&newListDeclarationSymbolTable,
				auxDeclarationSymbolTableFirstIndividual);
		auxDeclarationSymbolTableFirstIndividual =
				auxDeclarationSymbolTableFirstIndividual->next;
	}

	/*
	 DeclarationSymbolTable * newListDeclarationSymbolTable = NULL;
	 int countOfDeclarationSymbolTableInCurrentIndividual =
	 countElementsInDeclarationSymbolTable(springIndividual->candidateDeclarationSymbolTable);
	 int countOfDeclarationSymbolTableInSecondIndividual =
	 countElementsInDeclarationSymbolTable(second->candidateDeclarationSymbolTable);

	 //special case if they are odd numbers
	 //half from both of them; should be equal
	 if (countOfDeclarationSymbolTableInCurrentIndividual % 2 == 0) {
	 countOfDeclarationSymbolTableInCurrentIndividual = countOfDeclarationSymbolTableInCurrentIndividual / 2;

	 } else {
	 countOfDeclarationSymbolTableInCurrentIndividual = (countOfDeclarationSymbolTableInCurrentIndividual / 2) + 1;

	 }
	 countOfDeclarationSymbolTableInSecondIndividual = countOfDeclarationSymbolTableInSecondIndividual / 2;




	 DeclarationSymbolTable * auxDeclarationSymbolTableFirstIndividual =
	 springIndividual->candidateDeclarationSymbolTable;
	 DeclarationSymbolTable * auxDeclarationSymbolTableSecondIndividual =
	 second->candidateDeclarationSymbolTable;

	 while (auxDeclarationSymbolTableFirstIndividual && countOfDeclarationSymbolTableInCurrentIndividual) {

	 addNewDeclarationSymbolTableFromDeclSymbolTableEl(&newListDeclarationSymbolTable,
	 auxDeclarationSymbolTableFirstIndividual);

	 countOfDeclarationSymbolTableInCurrentIndividual--;
	 auxDeclarationSymbolTableFirstIndividual = auxDeclarationSymbolTableFirstIndividual->next;
	 }

	 while (countOfDeclarationSymbolTableInSecondIndividual) {
	 auxDeclarationSymbolTableSecondIndividual = auxDeclarationSymbolTableSecondIndividual->next;
	 countOfDeclarationSymbolTableInSecondIndividual--;
	 }

	 while (auxDeclarationSymbolTableSecondIndividual) {
	 addNewDeclarationSymbolTableFromDeclSymbolTableEl(&newListDeclarationSymbolTable,
	 auxDeclarationSymbolTableSecondIndividual);
	 auxDeclarationSymbolTableSecondIndividual = auxDeclarationSymbolTableSecondIndividual->next;
	 }
	 */

	//here add new GPIndividual
	freeDeclarationSymbolTable(
			&springIndividual->candidateDeclarationSymbolTable);
	springIndividual->candidateDeclarationSymbolTable =
			newListDeclarationSymbolTable;

	return springIndividual;
}

void checkLOCInIndividual(GPIndividual * individual) {
	ListOfInt * aux = individual->selectedLOCs;
	while (aux) {
		if (aux->value == 11) {
			//int x;
			//x = 10;
		}
		aux = aux->next;
	}
}

#define NO_THREADS 8

struct fitnessThreadArgs {
	GPIndividual * head;
	SymbolTable * HostSymbolTable;
	ListOfString * SkeletonSourceCode;
	ArrayOfStrings * SkeletonLOCsArray;
	char * GraftInterfaceTempOutput;
	char * InterfaceHeaderWithGlobalDecl;
	int TotalIDsInHostSymbolTable;
	DependencyList * ListOfDependenciesForStatements;
	char * skeletonInterfaceSourceCodeOutput;
	DependencyListWithID * dependencyListForAbstract;
	char * finalInterfaceHeaderForCompilation;
	int start;
	int end;
	int threadID;
	char * TXLTemporaryFolderCurrent;
	char * TransplantResultLocation;
};

typedef struct fitnessThreadArgs FitnessThreadArgs;

pthread_mutex_t lock;

void readGPIndividualThread(GPIndividual * candidate,
		Mapping ** FinalMappingsInIndividual,
		ListOfString ** MappedDeclarations,
		ListOfInt ** ListOfCandidateSelectedLines) {

	char * line;
	line = (char *) malloc(3000 * sizeof(char));

	pthread_mutex_lock(&lock);

	Mapping * auxCandidateAbstractMappings = candidate->listOfAbstractMappings;

	while (auxCandidateAbstractMappings) {

		addNewMapping(&(*FinalMappingsInIndividual),
				auxCandidateAbstractMappings->source,
				auxCandidateAbstractMappings->destination);
		auxCandidateAbstractMappings = auxCandidateAbstractMappings->next;
	}

	ListOfString * auxDeclMappings = candidate->MappedDeclarations;
	while (auxDeclMappings) {

		strcpy(line, auxDeclMappings->el);

		char * declMarker;
		char * source;
		char * destination;

		declMarker = (char*) malloc(1500 * sizeof(char));
		source = (char*) malloc(1500 * sizeof(char));
		destination = (char*) malloc(1500 * sizeof(char));
		char * token = strtok(line, "@");
		strcpy(declMarker, token);
		token = strtok(NULL, "@");
		strcpy(source, token);
		token = strtok(NULL, "@");
		if (!token) {
		}
		strcpy(destination, token);
		//last character in destination is end of line .... It is not the case here, since
		//it was generated from the variables in the individual
		//destination[strlen(destination) - 1] = '\0';

		addNewMapping(&(*FinalMappingsInIndividual), source, destination);
		addNewString(&(*MappedDeclarations), declMarker);

		free(declMarker);
		free(source);
		free(destination);

		auxDeclMappings = auxDeclMappings->next;
	}

	ListOfInt * auxSourceCodeLines = candidate->selectedLOCs;
	while (auxSourceCodeLines) {
		addNewInt(&(*ListOfCandidateSelectedLines), auxSourceCodeLines->value);
		auxSourceCodeLines = auxSourceCodeLines->next;
	}
	free(line);
	pthread_mutex_unlock(&lock);
}

ListOfString * generateNewSkeletonForCandidateFromGPIndividualThread(
		ArrayOfStrings SkeletonLOCsArray, ListOfString * SkeletonSourceCode,
		GPIndividual * individual,
		DependencyList * ListOfDependenciesForStatements,
		ListOfString ** TheListOfTransplantedMarkers,
		DependencyListWithID * dependencyListForAbstract,
		char * TXLTemporaryFolder) {

	Mapping * FinalMappingsInIndividual = NULL;
	ListOfString * MappedDeclarations = NULL;
	ListOfInt * ListOfCandidateSelectedLines = NULL;

	//mapped declarations are declarations from the skeleton, which are mapped to variables from the host,
	//so there is no need to transplant the variable declarations on which these are dependent
	readGPIndividualThread(individual, &FinalMappingsInIndividual,
			&MappedDeclarations, &ListOfCandidateSelectedLines);

	DependencyList * additionalDependenciesForAbstract =
			generateAdditionalsDeclarationsDependenciesForAbstractInstantiationsToDonorIDs(
					dependencyListForAbstract, FinalMappingsInIndividual);

	ListOfString * neededMarkersForTransplant = NULL;

	//add all the line markers from the SkeletonLOC array, at the position selected by GP
	ListOfInt * aux = ListOfCandidateSelectedLines;
	while (aux) {
		if (!searchStringInListOfStrings(neededMarkersForTransplant,
				SkeletonLOCsArray.array[aux->value])) {
			addNewString(&neededMarkersForTransplant,
					SkeletonLOCsArray.array[aux->value]);
		}
		aux = aux->next;
	}

	//add the return marker, since it is the return of the interface and must always be presented
	addNewString(&neededMarkersForTransplant, RETURN_MARKER);

	ListOfString * auxNeededMarkers = neededMarkersForTransplant;

	//generate the complete list of dependencies into new one
	DependencyList * completeListOfDependencies = NULL;
	addDependencyListToAnExistingOne(&completeListOfDependencies,
			ListOfDependenciesForStatements);
	addDependencyListToAnExistingOne(&completeListOfDependencies,
			additionalDependenciesForAbstract);

	//for all added line markers, add the one from dependency, if they are not mapped
	//BUGGGGGGGGGGG!!!!!!!!!!!
	// TODO: check here
	while (auxNeededMarkers) {
		//memory leak!!! returnDependencyForAMarker makes new one, while adding adds also
		ListOfString * neededDepsForCurrent =
				returnDependencyForAMarkerNewPointers(
						completeListOfDependencies, auxNeededMarkers->el);
		if (neededDepsForCurrent) {
			ListOfString * auxListString = neededDepsForCurrent;
			//maybe this is infinite.. it should be checked that the new marker is not already in the list
			while (auxListString) {
				if (!searchStringInListOfStrings(MappedDeclarations,
						auxListString->el)
						&& !searchStringInListOfStrings(
								neededMarkersForTransplant,
								auxListString->el)) {
					addNewString(&neededMarkersForTransplant,
							auxListString->el);
				}
				auxListString = auxListString->next;
			}
			freeListOfStrings(&neededDepsForCurrent);
		}
		auxNeededMarkers = auxNeededMarkers->next;
	}

	*TheListOfTransplantedMarkers = neededMarkersForTransplant;

	ListOfString * candidateLOCs = NULL;
	ListOfString * auxSkeletonCode = SkeletonSourceCode;

	while (auxSkeletonCode) {
		//add some marker for LABEL ABST!!!, not like this
		if (!strstr(auxSkeletonCode->el, "/*")
				&& !strstr(auxSkeletonCode->el, "//")
				&& !strstr(auxSkeletonCode->el, "LABEL_ABST")
				&& !strstr(auxSkeletonCode->el, "break")) {
			addNewString(&candidateLOCs, auxSkeletonCode->el);
		} else {
			auxNeededMarkers = neededMarkersForTransplant;
			//add just once every line, even if it is needed for more then one declaration
			int signal = 0;
			while (auxNeededMarkers && !signal) {
				if (strstr(auxSkeletonCode->el, auxNeededMarkers->el)) {
					//the current line in skeleton was identified, so it should be added just once
					signal = 1;
					addNewString(&candidateLOCs, auxSkeletonCode->el);
					//printf("%s\n", auxSkeletonCode->el);

				}
				auxNeededMarkers = auxNeededMarkers->next;
			}
		}
		auxSkeletonCode = auxSkeletonCode->next;
	}

	//print the initial function file, for individual instantiator
	char * initialFunctionFile;
	initialFunctionFile = (char *) malloc(500 * sizeof(char));
	sprintf(initialFunctionFile, "%stemp_individual_for_instantiation.out",
			TXLTemporaryFolder);

	printAListOfStrings(candidateLOCs, initialFunctionFile);

	//print the initial mappings file, for individual instantiator
	char * initialMappingsFile;
	initialMappingsFile = (char *) malloc(500 * sizeof(char));

    sprintf(initialMappingsFile,
            "%stemp_mappings_for_candidate_instantiation.out",
            TXLTemporaryFolder);

    FILE * symbolTableResults = fopen(initialMappingsFile, "w");
    Mapping * currentListOfMappings = FinalMappingsInIndividual;

    while (currentListOfMappings) {
        if(strchr(currentListOfMappings->destination, '\"')){
            char *formatedDestinationTypeString = (char *) malloc((strlen(currentListOfMappings->destination) + 4) * sizeof(char));
            //sprintf(formatedDestinationTypeString,"\\%s \\\"", strtok(currentListOfMappings->destination, "\"");
            sprintf(formatedDestinationTypeString,"\\\"%s \\\"", readSubstring("\"",currentListOfMappings->destination, "\""));
            fprintf(symbolTableResults, "\"%s\" \"%s\" ", currentListOfMappings->source,
                    formatedDestinationTypeString);
        }
        else
            fprintf(symbolTableResults, "\"%s\" \"%s\" ", currentListOfMappings->source, currentListOfMappings->destination);

        currentListOfMappings = currentListOfMappings->next;
    }
    fclose(symbolTableResults);

	ListOfString * candidateLOCsInstantiated =
			instantiateCurrentIndividualInSkeleton(initialFunctionFile,
					initialMappingsFile, TXLTemporaryFolder);
	return candidateLOCsInstantiated;
}

void instantiateGPCandidateWithExistingGlobalAndCoreFeatureGromGPIndividualThread(
		ListOfString * SkeletonSourceCode, ArrayOfStrings SkeletonLOCsArray,
		GPIndividual * individual,
		DependencyList * ListOfDependenciesForStatements,
		char * GraftInterfaceTempOutput,
		char * skeletonInterfaceSourceCodeOutput,
		char * finalGraftInterfaceFile,
		DependencyListWithID * dependencyListForAbstract,
		char * TXLTemporaryFolder) {

	//Mapped Host Graft IDs used here just for compiliance with the instantiate a candidate with just its own needed
	//global declarations, where this will be also changed

	char * finalHostInterfaceOutput;
	finalHostInterfaceOutput = (char *) malloc(500 * sizeof(char));
	sprintf(finalHostInterfaceOutput, "%stemp_interface_source_file.out",
			TXLTemporaryFolder);
	ListOfString * TheListOfTransplantedMarkers = NULL;
	fflush(stdout);
	//bug place!!!!
	ListOfString * candidateSourceCode =
			generateNewSkeletonForCandidateFromGPIndividualThread(
					SkeletonLOCsArray, SkeletonSourceCode, individual,
					ListOfDependenciesForStatements,
					&TheListOfTransplantedMarkers, dependencyListForAbstract,
					TXLTemporaryFolder);

	fflush(stdout);
	instantiateGraftSkeletonInInterface(candidateSourceCode,
			GraftInterfaceTempOutput, skeletonInterfaceSourceCodeOutput,
			JustCoreFeatureHeaderName);
	fflush(stdout);

	char * localSourceOutputCoreFunctionalities = (char *) malloc(
			1000 * sizeof(char));
	sprintf(localSourceOutputCoreFunctionalities, "%sInterfaceCoreFunctionality.c",
			TXLTemporaryFolder);

	addLocsFromSourceToDestination(skeletonInterfaceSourceCodeOutput,
			localSourceOutputCoreFunctionalities, TXLToolsPath);

	char * localSkeletonCoreFeatureHeader = (char *) malloc(
			1000 * sizeof(char));
	sprintf(localSkeletonCoreFeatureHeader, "%sNeededFunctionsHeader.h",
			TXLTemporaryFolder);

	//HERE write to interface
	addLocsFromSourceToDestination(finalGraftInterfaceFile,
			localSkeletonCoreFeatureHeader, TXLToolsPath);
	fflush(stdout);
}

void * computeFitnessForAListOfGPIndividualsOnThread(void * args) {
	FitnessThreadArgs * argsFitnessThread = (FitnessThreadArgs *) args;

#if 1

	GPIndividual * head = argsFitnessThread->head;
	SymbolTable * HostSymbolTable = argsFitnessThread->HostSymbolTable;
	ListOfString * SkeletonSourceCode = argsFitnessThread->SkeletonSourceCode;
	ArrayOfStrings SkeletonLOCsArray = *(argsFitnessThread->SkeletonLOCsArray);
	char * GraftInterfaceTempOutput =
			argsFitnessThread->GraftInterfaceTempOutput;
	char * InterfaceHeaderWithGlobalDecl =
			argsFitnessThread->InterfaceHeaderWithGlobalDecl;
	int TotalIDsInHostSymbolTable = argsFitnessThread->TotalIDsInHostSymbolTable;
	DependencyList * ListOfDependenciesForStatements =
			argsFitnessThread->ListOfDependenciesForStatements;
	char * skeletonInterfaceSourceCodeOutput =
			argsFitnessThread->skeletonInterfaceSourceCodeOutput;
	DependencyListWithID * dependencyListForAbstract =
			argsFitnessThread->dependencyListForAbstract;
	char * finalInterfaceHeaderForCompilation =
			argsFitnessThread->finalInterfaceHeaderForCompilation;
	char * TXLTemporaryFolder = argsFitnessThread->TXLTemporaryFolderCurrent;
	int start = argsFitnessThread->start;
	int end = argsFitnessThread->end;

	char * localTransplantResultLocation =
			argsFitnessThread->TransplantResultLocation;

	int count = end - start;

	//go into the area of the list for this thread;
	while (head && start) {
		head = head->next;
		start--;
	}

	//write in the final interface header, the initial one, with global declarations + graft function header
	//for instantiating it again, without keeping the other declarations
	ListOfString * originalInterfaceHeaderLOCs = readListOfStringFromFile(
			InterfaceHeaderWithGlobalDecl);
	printAListOfStrings(originalInterfaceHeaderLOCs,
			finalInterfaceHeaderForCompilation);

	while (head && count) {
		count--;
		checkLOCInIndividual(head);
		int MappedGraftHostIDs = returnNumberOfMappedIDsToHostSymbolTable(
				HostSymbolTable, head);
		instantiateGPCandidateWithExistingGlobalAndCoreFeatureGromGPIndividualThread(
				SkeletonSourceCode, SkeletonLOCsArray, head,
				ListOfDependenciesForStatements, GraftInterfaceTempOutput,
				skeletonInterfaceSourceCodeOutput,
				finalInterfaceHeaderForCompilation, dependencyListForAbstract,
				TXLTemporaryFolder);

		int LOCsInIndividual = countElementsInListOfInt(head->selectedLOCs);
		double fitness = computeFitness("Individual.x",
				TotalIDsInHostSymbolTable, MappedGraftHostIDs, LOCsInIndividual,
				localTransplantResultLocation);
		if (fitness >= 1.04) {
			SUCCESFULL_INDIVIDUAL = head;

			///losaqui localTransplantResultLocation
		}
		//add the computed fitness
		head->fitness = fitness;
		printf("G%d - Fitness for individual: %s is : %0.2f\n",generationNumber, "Individual.x",
				fitness);
		//printf("\t THREAD: %d ;\n", argsFitnessThread->threadID);
		head = head->next;
	}
#endif

#if 0
	printf("\t THREAD: %d ;\n", argsFitnessThread->threadID);
#endif

	return NULL;
}

void computeFitnessMultithread(GPIndividual * head,
		SymbolTable * HostSymbolTableS[NO_THREADS],
		ListOfString * SkeletonSourceCodeS[NO_THREADS],
		ArrayOfStrings SkeletonLOCsArrayS[NO_THREADS],
		char * GraftInterfaces[NO_THREADS],
		char * IntHeaderGlobalFcts[NO_THREADS], int TotalIDsInHostSymbolTable,
		DependencyList * ListOfDependenciesForStatementsS[NO_THREADS],
		char * TransplantedSourceFiles[NO_THREADS],
		DependencyListWithID * dependencyListForAbstractS[NO_THREADS],
		char * TransplantedHeaderFiles[NO_THREADS], int currentPopulationlength,
		char * TXLTemporaryFolders[NO_THREADS],
		char * ThreadTransplantResultLocations[NO_THREADS]) {

	int step = currentPopulationlength / NO_THREADS;
	int currentPos = 0;

	pthread_t listOfThreads[NO_THREADS];

	if (pthread_mutex_init(&lock, NULL) != 0) {
		printf("\n mutex init failed\n");
	}

	for (int i = 0; i < NO_THREADS - 1; i++) {

		FitnessThreadArgs * myArg;
		myArg = (FitnessThreadArgs *) malloc(sizeof(FitnessThreadArgs));

		//GPIndividual * newGpInd = copyListOfGPIndividual(head);

		myArg->head = head;
		myArg->HostSymbolTable = HostSymbolTableS[i];
		myArg->SkeletonSourceCode = SkeletonSourceCodeS[i];
		myArg->SkeletonLOCsArray = &SkeletonLOCsArrayS[i];
		myArg->GraftInterfaceTempOutput = GraftInterfaces[i];
		myArg->InterfaceHeaderWithGlobalDecl = IntHeaderGlobalFcts[i];
		myArg->TotalIDsInHostSymbolTable = TotalIDsInHostSymbolTable;
		myArg->ListOfDependenciesForStatements =
				ListOfDependenciesForStatementsS[i];
		myArg->skeletonInterfaceSourceCodeOutput = TransplantedSourceFiles[i];
		myArg->dependencyListForAbstract = dependencyListForAbstractS[i];
		myArg->finalInterfaceHeaderForCompilation = TransplantedHeaderFiles[i];

		myArg->TransplantResultLocation = ThreadTransplantResultLocations[i];

		myArg->start = currentPos;
		myArg->end = currentPos + step;

		myArg->threadID = i;

		myArg->TXLTemporaryFolderCurrent = TXLTemporaryFolders[i];

		pthread_create(&listOfThreads[i], NULL,
				computeFitnessForAListOfGPIndividualsOnThread, myArg);
		//pthread_join(pth, NULL);

		currentPos += step;

	}
	//for the last one we need to add the end element
	FitnessThreadArgs * myArg;
	myArg = (FitnessThreadArgs *) malloc(sizeof(FitnessThreadArgs));
	//GPIndividual * newGpInd = copyListOfGPIndividual(head);
	myArg->head = head;
	myArg->HostSymbolTable = HostSymbolTableS[NO_THREADS - 1];
	myArg->SkeletonSourceCode = SkeletonSourceCodeS[NO_THREADS - 1];
	myArg->SkeletonLOCsArray = &SkeletonLOCsArrayS[NO_THREADS - 1];
	myArg->GraftInterfaceTempOutput = GraftInterfaces[NO_THREADS - 1];
	myArg->InterfaceHeaderWithGlobalDecl = IntHeaderGlobalFcts[NO_THREADS - 1];
	myArg->TotalIDsInHostSymbolTable = TotalIDsInHostSymbolTable;
	myArg->ListOfDependenciesForStatements =
			ListOfDependenciesForStatementsS[NO_THREADS - 1];
	myArg->skeletonInterfaceSourceCodeOutput =
			TransplantedSourceFiles[NO_THREADS - 1];
	myArg->dependencyListForAbstract =
			dependencyListForAbstractS[NO_THREADS - 1];
	myArg->finalInterfaceHeaderForCompilation =
			TransplantedHeaderFiles[NO_THREADS - 1];

	myArg->TransplantResultLocation = ThreadTransplantResultLocations[NO_THREADS
			- 1];

	myArg->threadID = NO_THREADS - 1;

	myArg->start = currentPos;
	myArg->end = 32767;

	myArg->TXLTemporaryFolderCurrent = TXLTemporaryFolders[NO_THREADS - 1];

	pthread_create(&listOfThreads[NO_THREADS - 1], NULL,
			computeFitnessForAListOfGPIndividualsOnThread, myArg);

	for (int j = 0; j < NO_THREADS; j++) {
		pthread_join(listOfThreads[j], NULL);
	}

	pthread_mutex_destroy(&lock);

}

void computeFitnessForAListOfGPIndividuals(GPIndividual * head,
		SymbolTable * HostSymbolTable, ListOfString * SkeletonSourceCode,
		ArrayOfStrings SkeletonLOCsArray, char * GraftInterfaceTempOutput,
		char * InterfaceHeaderWithGlobalDecl, int TotalIDsInHostSymbolTable,
		DependencyList * ListOfDependenciesForStatements,
		char * skeletonInterfaceSourceCodeOutput,
		DependencyListWithID * dependencyListForAbstract,
		char * finalInterfaceHeaderForCompilation, char * TXLTemporaryFolder, char * listOfSourceFilesTargetPath) {

	//write in the final interface header, the initial one, with global declarations + graft function header
	//for instantiating it again, without keeping the other declarations
	ListOfString * originalInterfaceHeaderLOCs = readListOfStringFromFile(
			InterfaceHeaderWithGlobalDecl);
	printAListOfStrings(originalInterfaceHeaderLOCs,
			finalInterfaceHeaderForCompilation);

	while (head) {
		checkLOCInIndividual(head);
		int MappedGraftHostIDs = returnNumberOfMappedIDsToHostSymbolTable(
				HostSymbolTable, head);
		instantiateGPCandidateWithExistingGlobalAndCoreFeatureGromGPIndividual(
				SkeletonSourceCode, SkeletonLOCsArray, head,
				ListOfDependenciesForStatements, GraftInterfaceTempOutput,
				skeletonInterfaceSourceCodeOutput,
				finalInterfaceHeaderForCompilation, dependencyListForAbstract,
				TXLTemporaryFolder, listOfSourceFilesTargetPath);

		int LOCsInIndividual = countElementsInListOfInt(head->selectedLOCs);
		double fitness = computeFitness("Individual.x",
				TotalIDsInHostSymbolTable, MappedGraftHostIDs, LOCsInIndividual,
				TransplantResultLocation);
		if (fitness >= 1.04) {
			SUCCESFULL_INDIVIDUAL = head;
		}
		//add the computed fitness
		head->fitness = fitness;
		printf("\tFitness for individual: %s %d is : %0.2f\n", "Individual.x",
				head->ID, fitness);
		head = head->next;
	}
}

GPIndividual * removeExcedingIndividualsRandomForSameFitness(
		GPIndividual ** head, int desiredLength) {
	//GPIndividual * aux = *head;

	//starting from 1, since 1 is added from beginning, for holding the previous element in list
	int count = 1;
	GPIndividual * listOfRemovedIndividuals = NULL;

	double currentFitness;

	GPIndividual * auxFirstWithCurrentFitness = *head;
	GPIndividual * auxPrev = *head;
	GPIndividual * auxForRemoveIndividuals = auxPrev->next;
	while (count < desiredLength && auxForRemoveIndividuals) {
		//add all the individuals with the same fitness
		currentFitness = auxForRemoveIndividuals->fitness;

		auxFirstWithCurrentFitness = auxForRemoveIndividuals;
		auxForRemoveIndividuals = auxForRemoveIndividuals->next;
		auxPrev = auxPrev->next;
		count++;

		while (auxForRemoveIndividuals
				&& auxForRemoveIndividuals->fitness == currentFitness) {
			auxForRemoveIndividuals = auxForRemoveIndividuals->next;
			auxPrev = auxPrev->next;
			count++;
		}
	}

	if (auxForRemoveIndividuals) {

		GPIndividual * auxAddRemovedIndividuals = auxForRemoveIndividuals;

		//first add all removed individuals in the list for crossover
		while (auxAddRemovedIndividuals) {
			MappingCandidate * newMappingCandidate = copyListOfMappingCandidate(
					auxAddRemovedIndividuals->candidateMappings);
			DeclarationSymbolTable * newDeclSymbolTable =
					copyDeclarationSymbolTableList(
							auxAddRemovedIndividuals->candidateDeclarationSymbolTable);
			addNewGPIndividual(&listOfRemovedIndividuals,
					auxAddRemovedIndividuals->MappedDeclarations,
					auxAddRemovedIndividuals->selectedLOCs,
					auxAddRemovedIndividuals->listOfAbstractMappings,
					auxAddRemovedIndividuals->fitness, newMappingCandidate,
					newDeclSymbolTable);
			auxAddRemovedIndividuals = auxAddRemovedIndividuals->next;
		}

		//then remove it from the initial population
		freeListOfGPIndividual(&auxForRemoveIndividuals);
		auxPrev->next = NULL;
		auxForRemoveIndividuals = NULL;
	}

	if (count == desiredLength) {

	} else {
		int elementsToBeRemoved = count - desiredLength;
		while (elementsToBeRemoved > 0) {
			int elementsWithSameFitnessAtTheEnd =
					countElementsInListOfGPIndividual(
							auxFirstWithCurrentFitness);

			if (elementsWithSameFitnessAtTheEnd) {
				int randomRemoveIndex = randomIndexJKISSPopulationSelection(
						elementsWithSameFitnessAtTheEnd, NULL);
				if (!removeNthGPIndividual(&auxFirstWithCurrentFitness,
						randomRemoveIndex, &listOfRemovedIndividuals)) {
					elementsToBeRemoved++;
				}
			}

			elementsToBeRemoved--;
		}
	}

	return listOfRemovedIndividuals;

}
//add more to local decl mapping

int returnTypeOfMutation(int possibleDifferentMappingsInAbstract,
		int possibleDifferentMappingsInLocal, int numberOfLOCs) {

	//0 means LOC mutation
	//1 means abstract mutation
	//2 means local mapping mutation

	if (possibleDifferentMappingsInAbstract == 0
			&& possibleDifferentMappingsInLocal == 0) {
		return 0;
	} else if (possibleDifferentMappingsInAbstract == 0) {
		int totalCount = possibleDifferentMappingsInLocal + numberOfLOCs;
		int randomSelector = randomIndexJKISSOperation(totalCount, NULL);
		if (randomSelector < possibleDifferentMappingsInLocal) {
			//return local
			return 2;
		} else {
			//return LOC mutation
			return 0;
		}

	} else if (possibleDifferentMappingsInLocal == 0) {
		int totalCount = possibleDifferentMappingsInAbstract + numberOfLOCs;
		int randomSelector = randomIndexJKISSOperation(totalCount, NULL);
		if (randomSelector < possibleDifferentMappingsInAbstract) {
			//return local
			return 1;
		} else {
			//return LOC mutation
			return 0;
		}
	} else {
		//all of them are possible
		int totalCount = possibleDifferentMappingsInAbstract
				+ possibleDifferentMappingsInLocal + numberOfLOCs;
		int randomSelector = randomIndexJKISSOperation(totalCount, NULL);
		if (randomSelector < possibleDifferentMappingsInAbstract) {
			//abstract mapping
			return 1;
		} else if ((randomSelector > possibleDifferentMappingsInAbstract)
				&& (randomSelector < possibleDifferentMappingsInLocal)) {
			//local mapping
			return 2;
		} else {
			return 0;
		}
	}
}

void newGeneration(GPIndividual ** population, ArrayOfStrings SkeletonLOCsArray,
		int lengthOfMappingCandidate, SymbolTable * HostSymbolTable,
		ListOfString * SkeletonSourceCode, char * GraftInterfaceTempOutput,
		char * InterfaceHeaderWithGlobalDecl, int TotalIDsInHostSymbolTable,
		DependencyList * ListOfDependenciesForStatements,
		char * skeletonInterfaceSourceCodeOutput,
		DependencyListWithID * dependencyListForAbstract,
		char * finalInterfaceHeaderForCompilation,
		MappingCandidate * MappingCandidatesForGP,
		DeclarationSymbolTable * GraftSymbolTablePossibleMatching,
		char * GraftInterfaces[NO_THREADS],
		char * IntHeaderGlobalFcts[NO_THREADS],
		char * TransplantResultsLocations[NO_THREADS],
		char * TransplantedSourceFiles[NO_THREADS],
		char * TransplantedHeaderFiles[NO_THREADS],
		SymbolTable * HostSymbolTableS[NO_THREADS],
		ListOfString * SkeletonSourceCodeS[NO_THREADS],
		ArrayOfStrings SkeletonLOCsArrayS[NO_THREADS],
		DependencyList * ListOfDependenciesForStatementsS[NO_THREADS],
		DependencyListWithID * dependencyListForAbstractS[NO_THREADS],
		char * TXLTemporaryFolders[NO_THREADS], char * TXLTemporaryFolder, ListOfString * listOfSourceFiles) {

	syncronizeGPIndividualID(*population);
	sortPopulationByFitness(&(*population));

	//second half of population for crossover!!!

	//int crossoverPopulationRemoveNumber = POPULATION_LENGTH / 2;

	//first copy the old population, into a new GPIndividual list
	GPIndividual * newPopulation = copyListOfGPIndividual(*population);

	GPIndividual * populationForCrossover = copyListOfGPIndividual(*population);

	GPIndividual * auxPopulation = newPopulation;
	//for every individual in the initial population do crossover or mutation

	GPIndividual * addedIndividualsAfterCrossOver = NULL;

	int lengthPopForCrossover = countElementsInListOfGPIndividual(
			populationForCrossover);
	//int lengthSelectedPopulation = countElementsInListOfGPIndividual(newPopulation);

	//BUG CROSSOVER!!!! TO BE CHECKED!!!

	while (auxPopulation) {

		int randCrossoverMutation = randomIndexJKISSOperation(4, NULL);

		//just now!!!
		//randCrossoverMutation = 0;

		//add also reproduction!!!!

		if (randCrossoverMutation == 0 || randCrossoverMutation == 1
				|| randCrossoverMutation == 2) {
			//MUTATION
			int randCrossoverMutationType = randomIndexJKISSOperation(6, NULL);

			//just now!!
			//randCrossoverMutationType = 0;

			//if the others are not possible, than do LOC mutation!!!
			if (randCrossoverMutationType == 0 || randCrossoverMutationType == 1
					|| randCrossoverMutationType == 2

					|| randCrossoverMutationType == 3
					|| randCrossoverMutationType == 4
					|| randCrossoverMutationType == 5

					|| (auxPopulation->arrayOfCandidateMappingsWithMoreThanOnePossibleMapping.count
							== 0 && (randCrossoverMutationType == 3))
					|| (countElementsWithMoreThenOnePossibleMappingsDeclarationSymbolTable(
							auxPopulation->candidateDeclarationSymbolTable) == 0
							&& randCrossoverMutationType == 5)
					|| (countElementsWithMoreThenOnePossibleMappingsDeclarationSymbolTable(
							auxPopulation->candidateDeclarationSymbolTable) == 0
							&& auxPopulation->arrayOfCandidateMappingsWithMoreThanOnePossibleMapping.count
									== 0)) {
				//LOC mutation
				int typeOfLOCMutation = randomIndexJKISSOperation(3, NULL);
				int elementsInListOfLOCs = countElementsInListOfInt(
						auxPopulation->selectedLOCs);

				//just now!!!
				//typeOfLOCMutation = 0;

				if (typeOfLOCMutation == 0 || typeOfLOCMutation == 1
						|| !elementsInListOfLOCs) {
					//ADDITION
					ListOfInt * selectedLOC = randomlySelectOneLOC(
							SkeletonLOCsArray, auxPopulation->selectedLOCs);
					addNewInt(&auxPopulation->selectedLOCs, selectedLOC->value);
				} else {
					//DELETION

					int randomDeletionPosition = randomIndexJKISSOperation(
							elementsInListOfLOCs, NULL);
					deleteElementInListOfIntAtPosition(
							&auxPopulation->selectedLOCs,
							randomDeletionPosition);
				}

			} else if ((((randCrossoverMutationType == 3
					|| randCrossoverMutationType == 4)
					&& (auxPopulation->arrayOfCandidateMappingsWithMoreThanOnePossibleMapping.count
							> 0)))
					|| ((auxPopulation->candidateDeclarationSymbolTable == NULL)
							&& (auxPopulation->arrayOfCandidateMappingsWithMoreThanOnePossibleMapping.count
									> 0))) {
				//abstract mappings mutation
				//in all cases, replace one current abstract mapping with other one
				randomlySelectOneAbstactMappingAndOnePossibleMappingForIt(
						auxPopulation->arrayOfCandidateMappingsWithMoreThanOnePossibleMapping);
				//mapping return value not used in this case; syncronize at the end

			} else {
				//declaration mutation
				//int typeOfDeclarationMutation = randomIndex(3, NULL);
				randomlyAddANewLocalDeclarationMapping(
						auxPopulation->candidateDeclarationSymbolTable);
			}

		} else if (randCrossoverMutation == 3) {
			//crossover

			//first randomly select one individual from the initial population
			//the length should be the population length; check a little here
			//ids should be ok so, the exception is the id of the current individual
			ListOfInt * exception = NULL;
			addNewInt(&exception, auxPopulation->ID);
			int randomSecondIndividual = randomIndexJKISSCrossoverSelector(
					lengthPopForCrossover, NULL); //lengthPopForCrossover should be here!!!

			GPIndividual * copyOfIndividualInOldPopulation =
					nthElementInListOfGPIndividual(populationForCrossover,
							randomSecondIndividual);

			//GPIndividual * springIndividual = crossoverTwoGPIndividualsAllLOCsNewVers(auxPopulation, copyOfIndividualInOldPopulation);

			//GPIndividual * springIndividual2 = crossoverTwoGPIndividualsAllLOCsNewVers(copyOfIndividualInOldPopulation, auxPopulation);

			//GPIndividual * springIndividual3 = crossoverTwoGPIndividualsAllLOCs(auxPopulation, copyOfIndividualInOldPopulation);

			//old version of crossover
			GPIndividual * springIndividual = crossoverTwoGPIndividuals(
					auxPopulation, copyOfIndividualInOldPopulation);

			GPIndividual * springIndividual2 = crossoverTwoGPIndividuals(
					copyOfIndividualInOldPopulation, auxPopulation);

			GPIndividual * springIndividual3 = crossoverTwoGPIndividualsAllLOCs(
					auxPopulation, copyOfIndividualInOldPopulation);

			//GPIndividual * springIndividual3 = crossoverTwoGPIndividualsHalfAndAddAllCurrentDeclarations(auxPopulation, copyOfIndividualInOldPopulation);

			//GPIndividual * springIndividual4 = crossoverTwoGPIndividualsHalfAndAddAllCurrentDeclarations(copyOfIndividualInOldPopulation, auxPopulation);

			//addedIndividualsAfterCrossOver

			//addGPCandidateToAListPointerCopy(&addedIndividualsAfterCrossOver, springIndividual);

			//replace auxPopulation current element with springIndividual

			freeListOfInt(&(auxPopulation->selectedLOCs));
			freeMappingCandidateList(&(auxPopulation->candidateMappings));
			freeDeclarationSymbolTable(
					&(auxPopulation->candidateDeclarationSymbolTable));
			freeListOfStrings(&auxPopulation->MappedDeclarations);
			auxPopulation->fitness = 0;
			freeMapping(&auxPopulation->listOfAbstractMappings);

			auxPopulation->selectedLOCs = springIndividual->selectedLOCs;
			auxPopulation->candidateMappings =
					springIndividual->candidateMappings;
			auxPopulation->candidateDeclarationSymbolTable =
					springIndividual->candidateDeclarationSymbolTable;

			addGPCandidateToAListPointerCopy(&addedIndividualsAfterCrossOver,
					springIndividual2);
			addGPCandidateToAListPointerCopy(&addedIndividualsAfterCrossOver,
					springIndividual3);

		} else {
			//reproduction
			int x;
			// we should never enter here, so let it signal division by 0
			x = 10 / 0;
		}

		auxPopulation = auxPopulation->next;
	}

	//syncronize the computed values in all the population
	syncronizeAListOfGPIndividuals(newPopulation);
	syncronizeAListOfGPIndividuals(addedIndividualsAfterCrossOver);

	//compute the fitness just for the entire population, since it is new!!!
#if 0
	computeFitnessForAListOfGPIndividuals(newPopulation,
			HostSymbolTable, SkeletonSourceCode, SkeletonLOCsArray,
			GraftInterfaceTempOutput, InterfaceHeaderWithGlobalDecl,
			TotalIDsInHostSymbolTable, ListOfDependenciesForStatements,
			skeletonInterfaceSourceCodeOutput, dependencyListForAbstract,
			finalInterfaceHeaderForCompilation, TXLTemporaryFolderMainThread);

	computeFitnessForAListOfGPIndividuals(addedIndividualsAfterCrossOver,
			HostSymbolTable, SkeletonSourceCode, SkeletonLOCsArray,
			GraftInterfaceTempOutput, InterfaceHeaderWithGlobalDecl,
			TotalIDsInHostSymbolTable, ListOfDependenciesForStatements,
			skeletonInterfaceSourceCodeOutput, dependencyListForAbstract,
			finalInterfaceHeaderForCompilation, TXLTemporaryFolderMainThread);
#endif

#if 0

	int currentLengthForMT = countElementsInListOfGPIndividual(newPopulation);

	computeFitnessMultithread(newPopulation, HostSymbolTableS,
			SkeletonSourceCodeS, SkeletonLOCsArrayS, GraftInterfaces,
			IntHeaderGlobalFcts, TotalIDsInHostSymbolTable,
			ListOfDependenciesForStatementsS, TransplantedSourceFiles,
			dependencyListForAbstractS, TransplantedHeaderFiles,
			currentLengthForMT, TXLTemporaryFolders,
			TransplantResultsLocations);

	currentLengthForMT = countElementsInListOfGPIndividual(addedIndividualsAfterCrossOver);
	computeFitnessMultithread(addedIndividualsAfterCrossOver, HostSymbolTableS,
			SkeletonSourceCodeS, SkeletonLOCsArrayS, GraftInterfaces,
			IntHeaderGlobalFcts, TotalIDsInHostSymbolTable,
			ListOfDependenciesForStatementsS, TransplantedSourceFiles,
			dependencyListForAbstractS, TransplantedHeaderFiles,
			currentLengthForMT, TXLTemporaryFolders,
			TransplantResultsLocations);
#endif

	addListOfGPIndividualToAnExistingOne(&newPopulation,
			addedIndividualsAfterCrossOver);
#if 1

	//multithreading implementation

	int currentLengthForMT = countElementsInListOfGPIndividual(newPopulation);

	computeFitnessMultithread(newPopulation, HostSymbolTableS,
			SkeletonSourceCodeS, SkeletonLOCsArrayS, GraftInterfaces,
			IntHeaderGlobalFcts, TotalIDsInHostSymbolTable,
			ListOfDependenciesForStatementsS, TransplantedSourceFiles,
			dependencyListForAbstractS, TransplantedHeaderFiles,
			currentLengthForMT, TXLTemporaryFolders,
			TransplantResultsLocations);

	//computeFitnessForAListOfGPIndividuals(newPopulation, HostSymbolTable,
	//		SkeletonSourceCode, SkeletonLOCsArray, GraftInterfaceTempOutput,
	//		InterfaceHeaderWithGlobalDecl, TotalIDsInHostSymbolTable,
	//		ListOfDependenciesForStatements, skeletonInterfaceSourceCodeOutput,
	//		dependencyListForAbstract, finalInterfaceHeaderForCompilation);
#endif

	/*Probable redundant!!!*/syncronizeGPIndividualID(newPopulation);

	//sort the population according to the fitness
	sortPopulationByFitness(&newPopulation);

	//keep just population length individual in current population
	//for the moment just the first ones, but in the case that there are individuals at the end
	//with equal fitness this should be randomly selection

	removeExcedingIndividualsRandomForSameFitness(&newPopulation,
	POPULATION_LENGTH);

	ListOfInt * existingLOCs = syncronizeGPIndividualID(newPopulation);
	ListOfInt * unselectedLines = NULL;

	for (int i = 0; i < SkeletonLOCsArray.count; i++) {
		if (!searchAnIntInListOfInt(existingLOCs, i)) {
			addNewInt(&unselectedLines, i);
		}
	}

	int countOfNonSelectedLOCs = countElementsInListOfInt(unselectedLines);
	int lengthOfNonSelectedLOCs = countOfNonSelectedLOCs;

	//if population length is too low
	int currentLength = countElementsInListOfGPIndividual(newPopulation);
	if (currentLength < POPULATION_LENGTH) {

		//first add chromosomes that does not exists!!!

		ListOfInt * newSelectedLOCs = NULL;
		while (currentLength < POPULATION_LENGTH && countOfNonSelectedLOCs) {
			int randLOCIndex = randomIndexJKISS(lengthOfNonSelectedLOCs,
					newSelectedLOCs);
			int randLOC = nthElementInListOfInt(unselectedLines, randLOCIndex);

			addNewInt(&newSelectedLOCs, randLOC);
			currentLength++;
			countOfNonSelectedLOCs--;

			//write in the final interface header, the initial one, with global declarations + graft function header
			//for instantiating it again, without keeping the other declarations
			ListOfString * originalInterfaceHeaderLOCs =
					readListOfStringFromFile(InterfaceHeaderWithGlobalDecl);
			printAListOfStrings(originalInterfaceHeaderLOCs,
					finalInterfaceHeaderForCompilation);
			//first generate a random LOC addition
			ListOfInt * listOfSelectedLOCsForIndividual = NULL;
			addNewInt(&listOfSelectedLOCsForIndividual, randLOC);
			//make a new copy, since it should be new
			MappingCandidate * copyOfOriginalMappingCandidate =
					copyListOfMappingCandidate(MappingCandidatesForGP);
			//array of mapping candidates is needed here, since the individual is not yet computted
			ArrayOfMappingCandidates arrayForCurrentMappingCandidate =
					returnListOfCandidatesWithMoreThanOnePossibleMappingPointers(
							copyOfOriginalMappingCandidate);
			//just if there exists!
			if (arrayForCurrentMappingCandidate.count > 0) {
				randomlySelectOneAbstactMappingAndOnePossibleMappingForIt(
						arrayForCurrentMappingCandidate);
			}
			Mapping * currentMappings =
					mappingCandidateToListOfMappingsForCurrent(
							copyOfOriginalMappingCandidate);
			//add a random declaration mapping if it is the case (random selection; 50% chances)
			DeclarationSymbolTable * copyOfOriginalGraftDeclarationSymbolTable =
					copyDeclarationSymbolTableList(
							GraftSymbolTablePossibleMatching);
			//construct the list of abstract declaration mappings
			//change one declaration in declaration symbol table, if it is possible
			randomlyAddANewLocalDeclarationMapping(
					copyOfOriginalGraftDeclarationSymbolTable);
			GPIndividual * newIndividual = addNewGPIndividual(&newPopulation,
					NULL, listOfSelectedLOCsForIndividual, currentMappings, -1,
					copyOfOriginalMappingCandidate,
					copyOfOriginalGraftDeclarationSymbolTable);
			//newIndividual->candidateMappings = copyOfOriginalMappingCandidate;
			//newIndividual->candidateDeclarationSymbolTable = copyOfOriginalGraftDeclarationSymbolTable;
			int MappedGraftHostIDs = returnNumberOfMappedIDsToHostSymbolTable(
					HostSymbolTable, newIndividual);
			instantiateGPCandidateWithExistingGlobalAndCoreFeatureGromGPIndividual(
					SkeletonSourceCode, SkeletonLOCsArray, newIndividual,
					ListOfDependenciesForStatements, GraftInterfaceTempOutput,
					skeletonInterfaceSourceCodeOutput,
					finalInterfaceHeaderForCompilation,
					dependencyListForAbstract, TXLTemporaryFolder, listOfSourceFiles);
			int LOCsInIndividual = countElementsInListOfInt(
					newIndividual->selectedLOCs);
			double fitness = computeFitness("Individual.x",
					TotalIDsInHostSymbolTable, MappedGraftHostIDs,
					LOCsInIndividual, TransplantResultLocation);
			if (fitness >= 1.04) {
				SUCCESFULL_INDIVIDUAL = newIndividual;
			}

			//add the computed fitness
			newIndividual->fitness = fitness;
			printf("\tFitness for individual: %s is : %0.2f\n", "Individual.x",
					fitness);
			fflush(stdout);

		}

		while (currentLength < POPULATION_LENGTH) {
			//write in the final interface header, the initial one, with global declarations + graft function header
			//for instantiating it again, without keeping the other declarations
			ListOfString * originalInterfaceHeaderLOCs =
					readListOfStringFromFile(InterfaceHeaderWithGlobalDecl);
			printAListOfStrings(originalInterfaceHeaderLOCs,
					finalInterfaceHeaderForCompilation);
			//first generate a random LOC addition
			ListOfInt * listOfSelectedLOCsForIndividual = randomlySelectOneLOC(
					SkeletonLOCsArray, NULL);
			//make a new copy, since it should be new
			MappingCandidate * copyOfOriginalMappingCandidate =
					copyListOfMappingCandidate(MappingCandidatesForGP);
			//array of mapping candidates is needed here, since the individual is not yet computted
			ArrayOfMappingCandidates arrayForCurrentMappingCandidate =
					returnListOfCandidatesWithMoreThanOnePossibleMappingPointers(
							copyOfOriginalMappingCandidate);
			//just if there exists!
			if (arrayForCurrentMappingCandidate.count > 0) {
				randomlySelectOneAbstactMappingAndOnePossibleMappingForIt(
						arrayForCurrentMappingCandidate);
			}
			Mapping * currentMappings =
					mappingCandidateToListOfMappingsForCurrent(
							copyOfOriginalMappingCandidate);
			//add a random declaration mapping if it is the case (random selection; 50% chances)
			DeclarationSymbolTable * copyOfOriginalGraftDeclarationSymbolTable =
					copyDeclarationSymbolTableList(
							GraftSymbolTablePossibleMatching);
			//construct the list of abstract declaration mappings
			//change one declaration in declaration symbol table, if it is possible
			randomlyAddANewLocalDeclarationMapping(
					copyOfOriginalGraftDeclarationSymbolTable);
			GPIndividual * newIndividual = addNewGPIndividual(&newPopulation,
					NULL, listOfSelectedLOCsForIndividual, currentMappings, -1,
					copyOfOriginalMappingCandidate,
					copyOfOriginalGraftDeclarationSymbolTable);
			//newIndividual->candidateMappings = copyOfOriginalMappingCandidate;
			//newIndividual->candidateDeclarationSymbolTable = copyOfOriginalGraftDeclarationSymbolTable;
			int MappedGraftHostIDs = returnNumberOfMappedIDsToHostSymbolTable(
					HostSymbolTable, newIndividual);
			instantiateGPCandidateWithExistingGlobalAndCoreFeatureGromGPIndividual(
					SkeletonSourceCode, SkeletonLOCsArray, newIndividual,
					ListOfDependenciesForStatements, GraftInterfaceTempOutput,
					skeletonInterfaceSourceCodeOutput,
					finalInterfaceHeaderForCompilation,
					dependencyListForAbstract, TXLTemporaryFolder, listOfSourceFiles);
			int LOCsInIndividual = countElementsInListOfInt(
					newIndividual->selectedLOCs);
			double fitness = computeFitness("Individual.x",
					TotalIDsInHostSymbolTable, MappedGraftHostIDs,
					LOCsInIndividual, TransplantResultLocation);

			if (fitness >= 1.04) {
				SUCCESFULL_INDIVIDUAL = newIndividual;
			}

			//add the computed fitness
			newIndividual->fitness = fitness;
			printf("\tFitness for individual: %s is : %0.2f\n", "Individual.x",
					fitness);
			fflush(stdout);
			currentLength++;
		}
	}

	//sort the population according to the fitness
	sortPopulationByFitness(&newPopulation);
	syncronizeGPIndividualID(newPopulation);

	//int countIndividualsNewPop = countElementsInListOfGPIndividual(newPopulation);

	freeListOfGPIndividual(&(*population));

	(*population) = newPopulation;

}

//addCurrentMarkerDeclarationSymbolTable

void addCurrentMarkerDeclarationSymbolTable(DeclarationSymbolTable * head) {
	while (head) {
		//add the marekr for the current value in donor!!!
		addNewCurrentMappingDeclarationSymbolTable(&head, head->id,
		CURRENT_DECLARATION_DONOR_MAPPING_SIGN);
		head = head->next;
	}
}

void addOneRandomCurrentMappingMappingCandidate(MappingCandidate * head) {
	while (head) {
		//select randomly a possible mapping for current mapping
		int lengthOfPossibleMappingsDeclaration = countElementsInListOfString(
				head->possibleMappings);
		if (lengthOfPossibleMappingsDeclaration) {
			int randomSelectedDeclarationMapping = randomIndexJKISSStrings(
					lengthOfPossibleMappingsDeclaration, NULL);
			char * selectedItemDeclaration = nthElementInListString(
					head->possibleMappings, randomSelectedDeclarationMapping);
			addNewCurrentMapping(&head, head->id, selectedItemDeclaration);
		}
		head = head->next;
	}
}







void extractASTFromFunctions( char * functionSourceForASTGeneration, char * diretory, char * txlProgsPath, char *  graftSourceCodeFile, char * sourceOutputFile){

	createFile(sourceOutputFile);

	char * implantationContentFile;
	implantationContentFile = (char *) malloc(500 * sizeof (char));
	sprintf(implantationContentFile, "%stemp_list_function_files_for_implantation.out", TempImplantationDirectory);

	addAStringsInTheFile(functionSourceForASTGeneration,implantationContentFile);

	/* Create NeedFunctionHeader.h to vein functions declaration */
	char * headerOutputFile;
	headerOutputFile = (char *) malloc(500 * sizeof (char));
	sprintf(headerOutputFile, "%sNeedFunctionHeader.h", TempImplantationDirectory);
	createFile(headerOutputFile);

	/* Create headerContentFile.h to vein functions declaration */
	char * sourceFileForImplanation;
	sourceFileForImplanation = (char *) malloc(500 * sizeof (char));
	sprintf(sourceFileForImplanation, "%ssourceFilesInDonor.out", TempImplantationDirectory);
	createFile(sourceFileForImplanation);

	/* Create headerContentFile.h to vein functions declaration */
	char * headerContentFileForImplantation;
	headerContentFileForImplantation = (char *) malloc(500 * sizeof (char));
	sprintf(headerContentFileForImplantation, "%stemp_list_of_header_files.out", TempImplantationDirectory);
	createFile(headerContentFileForImplantation);

	char *command;
	command = (char *) malloc(2000 * sizeof(char *));

	/* Create list of functions target */
	char * tempCurrentTargetFunctionPath;
	tempCurrentTargetFunctionPath = (char *) malloc(500 * sizeof (char));
	sprintf(tempCurrentTargetFunctionPath, "%stemp_list_function_files_for_implantation.out", TempImplantationDirectory);
	//createFile(tempCurrentTargetFunctionPath);

	/* Create list of functions target */
	char * listOfNeededFilesForImpplantation;
	listOfNeededFilesForImpplantation = (char *) malloc(500 * sizeof (char));
	sprintf(listOfNeededFilesForImpplantation, "%stemp_list_of_header_files_for_implantation.out", TempImplantationDirectory);
	//createFile(listOfNeededHeadFilesForVein);

	char * ifDefProgramPath;

	if (strcmp(TXLToolsPath, "./")) {
		ifDefProgramPath = (char *) malloc(
				(strlen(TXLToolsPath) + 10) * sizeof(char));
		sprintf(ifDefProgramPath, "%sifdef.x", TXLToolsPath);
	} else {
		ifDefProgramPath = (char *) malloc(10 * sizeof(char));
		sprintf(ifDefProgramPath, "./ifdef.x");
	}
	sprintf(command, "./%smultiFilesExtraction.x %s %s %s %s %s %s %s %s %s%s %s",
			txlProgsPath, transplantHostInputFile, graftSourceCodeFile, headerOutputFile,
			sourceOutputFile, implantationContentFile, sourceFileForImplanation, headerContentFileForImplantation,
			listOfNeededFilesForImpplantation, TXLToolsPath, ifDefProgramPath,
			ConsoleStderrOutput);

	int status = system(command);
	if (status != 0) {
		printf("ERROR AST from %s!\n", functionSourceForASTGeneration);
		exit(1);
	}

}

ListOfFunctionSourceFile * searchFunctionDuplication(ListOfFunctionSourceFile * listOfFunctionInOrgan, ListOfFunctionSourceFile * listOfFunctionInHost){

	ListOfFunctionSourceFile * listOfDuplicatedFunction= NULL;

	while(listOfFunctionInOrgan){
		char * currentFct = NULL;
		currentFct = (char *) malloc(100 * sizeof (char));
		strcpy(currentFct, listOfFunctionInOrgan->functionName);

		char * sourceFile = NULL;
		sourceFile = (char *) malloc(100 * sizeof (char));
		strcpy(sourceFile, listOfFunctionInOrgan->sourceFile);

		if (searchFunctionAndFileInListOfFunctionsSourceFile(listOfFunctionInHost, currentFct, sourceFile)){
			addNewFunctionSourceFile(&listOfDuplicatedFunction, currentFct, sourceFile);
		}
		listOfFunctionInOrgan = listOfFunctionInOrgan->next;
		free(currentFct);
		free(sourceFile);
	}
	return listOfDuplicatedFunction;
}

int implantFunctionsAfterCloneAnalyse(char * currentSourceFile, ListOfFunctionSourceFile *  ListOfAllFunctionsFromFileInHost,
				  ListOfFunctionSourceFile * ListOfAllFunctionsFromFileInOrgan, ListOfFunctionSourceFile * ListOfFunctionsToBeTransplanted,
				  ListOfFunctionSourceFile * ListOfDuplicatedFunctions, char * dirHost, char * graftSourceCodeFile,
				  char * outputFileToTheHostDirectory, char * formattedCurrentFileToTheTempImplantationDirectory){

	int retransplant = 0; //retransplant shows if any functions was changed

	char *formattedCurrentFunction;
	formattedCurrentFunction = (char *) malloc(500 * sizeof(char));

	/* Create outputOrganAST.c to organ functions declaration ---------------------------------------------------------*/
	char * sourceOutputFileForOrgan;
	sourceOutputFileForOrgan = (char *) malloc(500 * sizeof (char));
	sprintf(sourceOutputFileForOrgan, "%sOrganAST.c", TempImplantationDirectory);

	/* Create outputHostAST.c to host functions declaration -----------------------------------------------------------*/
	char * sourceOutputFileForHost;
	sourceOutputFileForHost = (char *) malloc(500 * sizeof (char));
	sprintf(sourceOutputFileForHost, "%sHostAST.c", TempImplantationDirectory);

	char *currentFunction = NULL;
	currentFunction = (char *) malloc(1000 * sizeof(char));

	char * mergeResultFile;
	mergeResultFile = (char *) malloc(500 * sizeof (char));
	sprintf(mergeResultFile, "%smergeResultFile.c", TempImplantationDirectory);

	ListOfFunctionSourceFile * reverseListOfAllFunctionsFromFileInHost = reverseListOfFunctions(ListOfAllFunctionsFromFileInHost);
	ListOfFunctionSourceFile * reverseListOfAllFunctionsFromFileInOrgan = reverseListOfFunctions(ListOfAllFunctionsFromFileInOrgan);

	int countFct = 1;
	while(reverseListOfAllFunctionsFromFileInHost) {

		//strcpy(currentFunction,readSubstring("\"", ListOfAllFunctionsFromCurrentFileInHost->el, "\""));
		strcpy(currentFunction,reverseListOfAllFunctionsFromFileInHost->functionName);
		printf("\t\t\t----------------------------------------------------------\n");
		printf("\t\t\tFunction[%d]: %s\n",countFct, currentFunction);

		if (searchForFunction(reverseListOfAllFunctionsFromFileInOrgan, currentFunction)) {
			/* Create sourcContentFileAST for AST Generation --------------------------------------------------------------*/
			printf("\t\t\tGenerating Abstract Source Trees for ...\n");
			sprintf(formattedCurrentFunction, "\"%s\" \"%s%s\"\n", currentFunction, TransplantResultLocation,
						currentSourceFile);
			extractASTFromFunctions(formattedCurrentFunction, donorSourceFileFolder, TXLToolsPath,
										graftSourceCodeFile,
										sourceOutputFileForOrgan);

			/* Create sour-cContentFileAST for AST Generation */
			sprintf(formattedCurrentFunction, "\"%s\" \"%s%s\"\n", currentFunction, dirHost, currentSourceFile);
			extractASTFromFunctions(formattedCurrentFunction, dirHost, TXLToolsPath, graftSourceCodeFile,
										sourceOutputFileForHost);
          ///
			if (ASTIsEqual(sourceOutputFileForOrgan, sourceOutputFileForHost) == 1 && diffIsStatic(sourceOutputFileForOrgan, sourceOutputFileForHost) == 1) { // elements are different
				printf("\t\t\tNaming collision detected!\n");
				mergeElements(mergeResultFile, sourceOutputFileForOrgan, sourceOutputFileForHost, conditionalDirectives);
				printf("\t\t\tReplacing Function...\n");
				/* Replace function ---------------------------------------------------------------------------------------*/
				/*removeLocsFromSourceFile(formattedCurrentFileToTheTempImplantationDirectory,
											 sourceOutputFileForHost,
											 TXLToolsPath);*/
				addLocsFromSourceToDestination(formattedCurrentFileToTheTempImplantationDirectory, mergeResultFile,
												   TXLToolsPath);
             ///   addLocsFromSourceToDestinationWithDirectives(formattedCurrentFileToTheTempImplantationDirectory, mergeResultFile, TXLToolsPath);

				///removeFunctionSourceFile(&reverseListOfAllFunctionsFromFileInOrgan, currentFunction);
				retransplant = 1;
			} else {
				printf("\t\t\tDuplication detected. Keeping function in the host file.Nothing to do\n");
				/*printf("\t\t\tInserting function in the host environment...\n");
				sprintf(formattedCurrentFunction, "\"%s\" \"%s%s\"\n", currentFunction, dirHost,
						currentSourceFile);
				extractASTFromFunctions(formattedCurrentFunction, donorSourceFileFolder, TXLToolsPath,
										graftSourceCodeFile, sourceOutputFileForOrgan);*/
				addLocsFromSourceToDestination(formattedCurrentFileToTheTempImplantationDirectory,sourceOutputFileForHost, TXLToolsPath);
				///removeFunctionSourceFile(&reverseListOfAllFunctionsFromFileInOrgan, currentFunction);

			}
            removeFunctionSourceFile(&reverseListOfAllFunctionsFromFileInOrgan, currentFunction);
		} else {
			/* Insert new function ---------------------------------------------------------------------------------------*/
			printf("\t\t\tInserting function in the host environment...\n");
			sprintf(formattedCurrentFunction, "\"%s\" \"%s%s\"\n", currentFunction, dirHost, currentSourceFile);
			extractASTFromFunctions(formattedCurrentFunction, dirHost, TXLToolsPath, graftSourceCodeFile,
									sourceOutputFileForHost);
			addLocsFromSourceToDestination(formattedCurrentFileToTheTempImplantationDirectory,
										   sourceOutputFileForHost, TXLToolsPath);
		}

		reverseListOfAllFunctionsFromFileInHost = reverseListOfAllFunctionsFromFileInHost->next;
		countFct++;

	}
	while(reverseListOfAllFunctionsFromFileInOrgan){
		retransplant = 1;
		strcpy(currentFunction,reverseListOfAllFunctionsFromFileInOrgan->functionName);
		printf("\t\t\t----------------------------------------------------------\n");
		printf("\t\t\tFunction[%d]: %s\n",countFct, currentFunction);
		printf("\t\t\tInserting new function from organ into the host environment...\n");
		sprintf(formattedCurrentFunction, "\"%s\" \"%s%s\"\n", currentFunction, TransplantResultLocation,
				currentSourceFile);
		extractASTFromFunctions(formattedCurrentFunction, donorSourceFileFolder, TXLToolsPath,
								graftSourceCodeFile, sourceOutputFileForOrgan);

		ListOfString * functionWithDirectives = addDirectivesInFunction(sourceOutputFileForOrgan);
        addAListOfStringsInTheEnd(functionWithDirectives,formattedCurrentFileToTheTempImplantationDirectory);
        freeListOfStrings(&functionWithDirectives);
	/*	addLocsFromSourceToDestination(formattedCurrentFileToTheTempImplantationDirectory,
									   sourceOutputFileForOrgan, TXLToolsPath);

        addAListOfStringsInTheEndOfFileLN(ListOfSourceHeaderFilesNeededFormatted,formattedCurrentFileToTheTempImplantationDirectory);*/
       /// addLocsFromSourceToDestinationWithDirectives
		reverseListOfAllFunctionsFromFileInOrgan = reverseListOfAllFunctionsFromFileInOrgan->next;
		countFct++;
		/*if(reverseListOfAllFunctionsFromFileInHost == NULL)
			printf("----------------------------------------------------------------\n");*/
	}

	printf("----------------------------------------------------------------\n");
	return retransplant;
}

/*
void cloneAnalyse(char * hostPath, char * ){

	char *sourceFilesInHost;
	sourceFilesInHost = (char *) malloc(500 * sizeof(char));
	sprintf(sourceFilesInHost, "%sallSouceFileInHost.out", TXLTemporaryMultiFileFolder);


}
*/
void hasNewDirective(int * newDirective, char * tempDefinesFileInHost, char * tempDefinesFileInOrgan){

	if ((*newDirective) == 1)
		return ;

	ListOfString * ListOfDirectivesInHost = readListOfStringFromFileAsWords(tempDefinesFileInHost);
	ListOfString * ListOfDirectivesInOrgan = readListOfStringFromFileAsWords(tempDefinesFileInOrgan);
	ListOfString * auxListOfDirectivesInOrgan = ListOfDirectivesInOrgan;
	while(auxListOfDirectivesInOrgan && (*newDirective) == 0){
		if(!searchStringInListOfStrings(ListOfDirectivesInHost, auxListOfDirectivesInOrgan->el))
			(*newDirective) = 1;
		auxListOfDirectivesInOrgan = auxListOfDirectivesInOrgan->next;
	}
}

int printIncludesAndDirectives(int * newDirective, char * currentFile, char * TempImplantationDirectory, char * tempHostImplantationDirectory,
								char * tempOrganImplantationDirectory, char * tempIncludeLocalLibFileInOrgan, char * tempIncludeLocalLibFileInHost) {


	char *finalFileToImplantation = (char *) malloc(500 * sizeof(char));
	sprintf(finalFileToImplantation, "%s%s", TempImplantationDirectory, currentFile);

	char *finalIncludesAndDefines;
	finalIncludesAndDefines = (char *) malloc(500 * sizeof(char));
	sprintf(finalIncludesAndDefines, "%stemp_includes_defines_to_implant.out",
			TempImplantationDirectory);

	/* Unify Defies -----------------------------------*/
	char *tempDefinesFileInOrgan;
	tempDefinesFileInOrgan = (char *) malloc(500 * sizeof(char));
	sprintf(tempDefinesFileInOrgan, "%stemp_define_file.out",
			tempOrganImplantationDirectory);

	char *tempDefinesFileInHost;
	tempDefinesFileInHost = (char *) malloc(500 * sizeof(char));
	sprintf(tempDefinesFileInHost, "%stemp_define_file.out",
			tempHostImplantationDirectory);

	/* Check if there is any new define to be inserted in the host*/
	hasNewDirective(newDirective, tempDefinesFileInHost,tempDefinesFileInOrgan);

	ListOfString * UnifiedDefines = combineLists(tempDefinesFileInHost, tempDefinesFileInOrgan);
	printAListOfStrings(UnifiedDefines, finalIncludesAndDefines);
	addLocsFromSourceToDestination(finalFileToImplantation, finalIncludesAndDefines, TXLToolsPath);

	/* Unify includes -----------------------------------*/
	char *tempIncludeLibFileInOrgan;
	tempIncludeLibFileInOrgan = (char *) malloc(500 * sizeof(char));
	sprintf(tempIncludeLibFileInOrgan, "%stemp_include_lib_file.out",
			tempOrganImplantationDirectory);

	char *tempIncludeLibFileInHost;
	tempIncludeLibFileInHost = (char *) malloc(500 * sizeof(char));
	sprintf(tempIncludeLibFileInHost, "%stemp_include_lib_file.out",
			tempHostImplantationDirectory);

	/* Check if there is any new lib to be inserted in the host*/
	hasNewDirective(newDirective, tempIncludeLibFileInHost,tempIncludeLibFileInOrgan);

	ListOfString * UnifiedIncludeLibs = combineLists(tempIncludeLibFileInHost, tempIncludeLibFileInOrgan);
	printAListOfStrings(UnifiedIncludeLibs, finalIncludesAndDefines);
	addLocsFromSourceToDestination(finalFileToImplantation, finalIncludesAndDefines, TXLToolsPath);


	/* Check if there is any new lib to be inserted in the host*/
	hasNewDirective(newDirective, tempIncludeLocalLibFileInHost,tempIncludeLocalLibFileInOrgan);
	/* Unify Local Libs -----------------------------------*/
	ListOfString * UnifiedLocalIncludeLibs = combineLists(tempIncludeLocalLibFileInHost, tempIncludeLocalLibFileInOrgan);
	printAListOfStrings(UnifiedLocalIncludeLibs, finalIncludesAndDefines);
	addLocsFromSourceToDestination(finalFileToImplantation, finalIncludesAndDefines, TXLToolsPath);

	freeListOfStrings(&UnifiedLocalIncludeLibs);
	freeListOfStrings(&UnifiedIncludeLibs);
	freeListOfStrings(&UnifiedDefines);
	free(tempDefinesFileInHost);
	free(tempIncludeLibFileInHost);
	free(tempDefinesFileInOrgan);
	free(tempIncludeLibFileInOrgan);

}

int implantGlobalDeclarationFromFile(char * formattedCurrentFileToTheTempImplantationDirectory, char * dirHost, char * currentFile){
	int retransplant = 0;
	/*Target host file ------------------------------------------------*/
	char * tempSourceHeaderFilesTargetPathFromHost;
	tempSourceHeaderFilesTargetPathFromHost= (char *) malloc(500 * sizeof(char));
	sprintf(tempSourceHeaderFilesTargetPathFromHost, "%stemp_source_header_files_target_in_host.out", TempImplantationDirectory);

	/*Target organ file ------------------------------------------------*/
	char * tempSourceHeaderFilesTargetPathFromOrgan;
	tempSourceHeaderFilesTargetPathFromOrgan= (char *) malloc(500 * sizeof(char));
	sprintf(tempSourceHeaderFilesTargetPathFromOrgan, "%stemp_source_header_files_target_in_organ.out", TempImplantationDirectory);

	/*insert target path to the host -----------------------------------*/
	char *formattedCurrentFilePath = (char *) malloc(200 * sizeof(char));

	sprintf(formattedCurrentFilePath, "\"%s%s\"", dirHost, currentFile);
	addAStringsInTheFile(formattedCurrentFilePath, tempSourceHeaderFilesTargetPathFromHost);

	/*insert target path to the organ ----------------------------------*/
	sprintf(formattedCurrentFilePath, "\"%s%s\"", TransplantResultLocation, currentFile);
	addAStringsInTheFile(formattedCurrentFilePath, tempSourceHeaderFilesTargetPathFromOrgan);

//TODO pass they as a parameter
	char * AllDefinedFunctions;
	AllDefinedFunctions = (char *) malloc(1000 * sizeof(char));
	sprintf(AllDefinedFunctions,
			"%stemp_all_defined_functions_from_current_file_int_host.out",
			TempImplantationDirectory);

	char * outputAllDefinedFunctionsInOrgan;
	outputAllDefinedFunctionsInOrgan = (char *) malloc(1000 * sizeof(char));
	sprintf(outputAllDefinedFunctionsInOrgan,
			"%stemp_all_defined_functions_from_current_file_int_organ.out",
			TempImplantationDirectory);

	//TODO END
	/* Create tempTransplantationDirectories -----------------------------------*/
	char * tempOrganImplantationDirectory;
	tempOrganImplantationDirectory = (char *) malloc(500 * sizeof (char));
	sprintf(tempOrganImplantationDirectory, "%sTempOrgan/", TempImplantationDirectory);
	isDirectory(tempOrganImplantationDirectory);
	if(!isDirectoryExists(tempOrganImplantationDirectory))
		(tempOrganImplantationDirectory);

	char * tempHostImplantationDirectory;
	tempHostImplantationDirectory = (char *) malloc(500 * sizeof (char));
	sprintf(tempHostImplantationDirectory, "%sTempHost/", TempImplantationDirectory);
	if(!isDirectoryExists(tempHostImplantationDirectory))
		createADirectory(tempHostImplantationDirectory);

	/*Extract Global declarations from organ -----------------------------------*/
	GlobalDeclarations ListOfFinalGlobalDeclarationsFromHost =
			fixGlobalDeclarations(tempHostImplantationDirectory, currentFile,
								  AllDefinedFunctions,tempSourceHeaderFilesTargetPathFromHost ,
								  TXLTemporaryFolderMainThread);
	/*Extract Global declarations from host -----------------------------------*/
	GlobalDeclarations ListOfFinalGlobalDeclarationsFromOrgan =
			fixGlobalDeclarations(tempOrganImplantationDirectory, currentFile,
								  outputAllDefinedFunctionsInOrgan, tempSourceHeaderFilesTargetPathFromOrgan,
								  TXLTemporaryFolderMainThread);

	char * outputGlobalDeclarationsFromHost;
	outputGlobalDeclarationsFromHost = (char *) malloc(500 * sizeof (char));
	sprintf(outputGlobalDeclarationsFromHost, "%sdeclarationsInHost.c", TempImplantationDirectory);

	char * outputGlobalDeclarationsFromOrgan;
	outputGlobalDeclarationsFromOrgan = (char *) malloc(500 * sizeof (char));
	sprintf(outputGlobalDeclarationsFromOrgan, "%sdeclarationsInOrgan.c", TempImplantationDirectory);


	printListOfGlobalDeclarations1(&retransplant, currentFile, TempImplantationDirectory, ListOfFinalGlobalDeclarationsFromHost,ListOfFinalGlobalDeclarationsFromOrgan,
											 outputGlobalDeclarationsFromHost, outputGlobalDeclarationsFromOrgan);

	/* LOS add local includes */
	char * tempIncludeLocalLibFileInHost;
	tempIncludeLocalLibFileInHost = (char *) malloc(500 * sizeof (char));
	sprintf(tempIncludeLocalLibFileInHost, "%stemp_include_local_lib_file.out", tempHostImplantationDirectory);
	extractAllLocalIncludesDefinitions(tempSourceHeaderFilesTargetPathFromHost, TXLToolsPath, tempIncludeLocalLibFileInHost,
									   AllDefinedFunctions);

	/* LOS add local includes */
	char * tempIncludeLocalLibFileInOrgan;
	tempIncludeLocalLibFileInOrgan = (char *) malloc(500 * sizeof (char));
	sprintf(tempIncludeLocalLibFileInOrgan, "%stemp_include_local_lib_file.out", tempOrganImplantationDirectory);
	extractAllLocalIncludesDefinitions(tempSourceHeaderFilesTargetPathFromOrgan, TXLToolsPath, tempIncludeLocalLibFileInOrgan,
									   outputAllDefinedFunctionsInOrgan);



	printIncludesAndDirectives(&retransplant, currentFile, TempImplantationDirectory,tempHostImplantationDirectory, tempOrganImplantationDirectory, tempIncludeLocalLibFileInOrgan, tempIncludeLocalLibFileInHost);
	return retransplant;
}


#ifdef ORGAN_IMPLANTATION
void implantationOrgan(char * skeletonInterfaceSourceCodeOutput, ListOfString * ListOfSourceHeaderFilesExtracted,
                       ListOfString * ListOfHeaderFilesExtracted, char * graftSourceCodeFile) {
	//copy the files into host at the host target file location and
	//rewrite the host target file

	printf("\n[PRODSCALPEL] INSERTING ORGAN INTO THE HOST_BENEFICIARY\n");

	/* Implant Interface Files ---------------------------------------------------------------------------------------*/
	char *copyOriginalHost = (char *) malloc(1000 * sizeof(char));
	sprintf(copyOriginalHost, "cp -r %s %s_ORIGINAL", HostProject,
			HostProject);
	system(copyOriginalHost);

	char *tempDir = strdup(transplantHostInputFile);
	char *dirHost = dirname(tempDir);
	strcat(dirHost, "/");

	printf("\tInserting Interface into the Host\n");
    copyAFileFromDirToOther(skeletonInterfaceSourceCodeOutput, dirHost);

	printf("\tInserting Organ header file into the Host\n");
    char *interfacHeaderFilePath = (char *) malloc(500 * sizeof(char));
    sprintf(interfacHeaderFilePath, "%s%s", TransplantResultLocation, InterfaceHeaderFileName );
    copyAFileFromDirToOther(interfacHeaderFilePath, dirHost);

    printf("\tInserting the host file with interface into the host\n");
    copyAFileFromDirToOther(hostWithInterfaceOutputFile, transplantHostInputFile);

    fflush(stdout);
	/* Extract List of Files in Host --------------------------------------------------------------------------------*/
	char *sourceFilesInHost;
	sourceFilesInHost = (char *) malloc(500 * sizeof(char));
	sprintf(sourceFilesInHost, "%sallSouceFileInHost.out", TempImplantationDirectory);
	ListOfString * listOfFilesInHost = getListOfFilesFromDir(dirHost, sourceFilesInHost);
	replaceListOfSourceFilePahtByFileName(&listOfFilesInHost, dirHost);

	/* Get List of source and header files extracted ------------------------------------------------------------------*/
	///ListOfString * ListOfSourceHeaderFilesExtracted = readListOfStringFromFileAsWords(listOfSourceFilesTargetPath);
	//ListOfString * ListOfHeaderFilesExtracted  = readListOfStringFromFileAsWords(listOfHeaderFilesTargetPath);
	while(ListOfHeaderFilesExtracted){
		addNewString(&ListOfSourceHeaderFilesExtracted, ListOfHeaderFilesExtracted->el);
		ListOfHeaderFilesExtracted = ListOfHeaderFilesExtracted->next;
	}
	fflush(stdout);
	/* Organ implantation ---------------------------------------------------------------------------------------------*/
	ListOfString * auxListOfSourceHeaderFilesExtracted = ListOfSourceHeaderFilesExtracted;
	char *currentSourceFile = NULL;
	currentSourceFile = (char *) malloc(1000 * sizeof(char));
	int numberFile = 1;
	SourceFileElementsList * currentSourceWithListOfDuplicatedElements = NULL;
	SourceFileElementsList * currentSourceWithListOfElementsToBeTransplanted = NULL;
	SourceFileElementsList * currentSourceWithListOfAllFunctionsInHost = NULL;

	char *formattedCurrentFileToTheHostDirectory = (char *) malloc(500 * sizeof(char));
	char *tempCurrentFileFromHostToImplantationDirectory = (char *) malloc(500 * sizeof(char));
	char *formattedCurrentFileToTheTempImplantationDirectory = (char *) malloc(500 * sizeof(char));
	char *formattedCurrentFileTransplantCodeDiretory = (char *) malloc(500 * sizeof(char));
	char *commandCopySourceFiles = (char *) malloc(5000 * sizeof(char));

	GlobalDeclarations ListOfFinalGlobalDeclarations ;
/// Unnecessary: savel list os files has already transplanted
/*    char *tempListOfFilesImplanted;
    tempListOfFilesImplanted = (char *) malloc(500 * sizeof(char));
    sprintf(tempListOfFilesImplanted, "%stemp_files_already_implanted.out", TempImplantationDirectory);
    ListOfString * ListOfFilesImplanted = readListOfStringFromFileAsWords(tempListOfFilesImplanted);
*/
	while(auxListOfSourceHeaderFilesExtracted){
		strcpy(currentSourceFile, auxListOfSourceHeaderFilesExtracted->el);
		printf("\tAnalysing [%d] %s to insert ...\n", numberFile, currentSourceFile);
        if(!strcmp(currentSourceFile, "ex.c"))
            printf("Aqui");
	//	if(!searchStringInListOfStrings(ListOfFilesImplanted, currentSourceFile)) {
            /*Check if current source file already exist in the host directory --------------------------------------------*/
            if (searchStringInListOfStrings(listOfFilesInHost, currentSourceFile)) {
                /* Get list of functions in the host ------------------------------------------------------------------------------*/
                char *outputAllDefinedFunctionsFromCurrentFileInHost = (char *) malloc(200 * sizeof(char));
                sprintf(outputAllDefinedFunctionsFromCurrentFileInHost, "%stemp_all_defined_functions_from_current_file_int_host.out", TempImplantationDirectory);

                char *currentHostFilePath = (char *) malloc(200 * sizeof(char));
                sprintf(currentHostFilePath,"%stemp_host_file_target.out", TempImplantationDirectory);
                char *formattedCurrentFilePathFromHost = (char *) malloc(200 * sizeof(char));;
                sprintf(formattedCurrentFilePathFromHost, "\"%s%s\"", dirHost, currentSourceFile);
                addAStringsInTheFile(formattedCurrentFilePathFromHost, currentHostFilePath);

                ListOfFunctionSourceFile *ListOfFunctionsInHost = createListOfFunctionsFromAFile(TXLToolsPath,
                                                                                                 currentHostFilePath,
                                                                                                 outputAllDefinedFunctionsFromCurrentFileInHost);
                replaceSourceFilePahtByFileName(&ListOfFunctionsInHost, dirHost);
                /*insert target path to the organ ----------------------------------*/
                char *currentOrganFilePath = (char *) malloc(200 * sizeof(char));
                sprintf(currentOrganFilePath, "%stemp_organ_file_target.out",
                        TempImplantationDirectory);

                char *outputAllDefinedFunctionsFromCurrentFileInOrgan = (char *) malloc(200 * sizeof(char));
                sprintf(outputAllDefinedFunctionsFromCurrentFileInOrgan,"%stemp_all_defined_functions_from_current_file_int_organ.out",
                        TempImplantationDirectory);

                char *formattedCurrentFilePathFromOrgan = (char *) malloc(200 * sizeof(char));
                sprintf(formattedCurrentFilePathFromOrgan, "\"%s%s\"", TransplantResultLocation, currentSourceFile);
                addAStringsInTheFile(formattedCurrentFilePathFromOrgan, currentOrganFilePath);

                ListOfFunctionSourceFile *ListOfFunctionsInOrgan = createListOfFunctionsFromAFile(TXLToolsPath,
                                                                                                  currentOrganFilePath,
                                                                                                  outputAllDefinedFunctionsFromCurrentFileInOrgan);
                /* Remove Directory path from file names-------------*/
                replaceSourceFilePahtByFileName(&ListOfFunctionsInOrgan, TransplantResultLocation);

                /* Search duplicated functions ------------------------------------------------------------------------------------*/
                ListOfFunctionSourceFile *ListOfDuplicatedFunctions = searchFunctionDuplication(ListOfFunctionsInOrgan,
                                                                                                ListOfFunctionsInHost);

                /* Create list of functions by file -------------------------------------------------------------------------------
                SourceFileElementsList *listOfFunctionsDuplicatedBySourceFile = NULL;
                addFunctionListToAnExistingOneFile(&listOfFunctionsDuplicatedBySourceFile, ListOfDuplicatedFunctions);*/

                sprintf(formattedCurrentFileToTheTempImplantationDirectory, "%s%s", TempImplantationDirectory,
                        currentSourceFile);

                /* Creating list of  all functions to be transplanted ----------------*/
                ListOfFunctionSourceFile *ListOfFunctionsToBeTransplanted = ListOfFunctionsInHost;
                ListOfFunctionSourceFile *auxListOfFunctionsInOrgan = ListOfFunctionsInOrgan;

                /*Copy current file from host to TempImplantationDirectory ----------------------------------------------------------*/
                sprintf(formattedCurrentFileToTheHostDirectory, "%s%s", dirHost, currentSourceFile);
                /*sprintf(commandCopySourceFiles, "cp %s %s", formattedCurrentFileToTheHostDirectory, TempImplantationDirectory);
                system(commandCopySourceFiles);*/
                sprintf(tempCurrentFileFromHostToImplantationDirectory, "%s%s", TempImplantationDirectory,
                        currentSourceFile);
                createFile(tempCurrentFileFromHostToImplantationDirectory);
                //copyAFileFromDirToOther(formattedCurrentFileToTheHostDirectory, TempImplantationDirectory);

                int functionImplanted;
                functionImplanted = implantFunctionsAfterCloneAnalyse(currentSourceFile, ListOfFunctionsInHost,
                                                                     ListOfFunctionsInOrgan,
                                                                     ListOfFunctionsToBeTransplanted,
                                                                     ListOfDuplicatedFunctions, dirHost,
                                                                     graftSourceCodeFile,
                                                                     tempCurrentFileFromHostToImplantationDirectory,
                                                                     formattedCurrentFileToTheTempImplantationDirectory);


                /* Clone analyse process
                cloneAnalyse(currentSourceWithListOfAllFunctionsInHost,
                             currentSourceWithListOfElementsToBeTransplanted,
                             currentSourceWithListOfDuplicatedElements, dirHost, graftSourceCodeFile,
                             auxCurrentFileFromHostToImplantationDirectory,
                             formattedCurrentFileToTheTempImplantationDirectory);*/

                /*Ex -----------------------------------------------------*/
                int declarationImplanted;
                declarationImplanted = implantGlobalDeclarationFromFile(
                        formattedCurrentFileToTheTempImplantationDirectory, dirHost,
                        currentSourceFile);

                /*check if there is any element to be inserted into the corrent file ---------------*/
                if (declarationImplanted == 1 || functionImplanted == 1) {
                    /* Remove Duplicated File from the Host directory */
                    char *removeDuplicatedSourceFileFromHostDirectory = (char *) malloc(1000 * sizeof(char));
                    sprintf(removeDuplicatedSourceFileFromHostDirectory, "rm -r -f %s",
                            formattedCurrentFileToTheHostDirectory);
                    system(removeDuplicatedSourceFileFromHostDirectory);

                    /* Copy Resulting Organ's file from TempImplantationDirectory to BeneficiaryDirectory. ----------------*/
                    sprintf(commandCopySourceFiles, "cp %s %s", formattedCurrentFileToTheTempImplantationDirectory,
                            formattedCurrentFileToTheHostDirectory);
                    system(commandCopySourceFiles);

                }
                /*} else {

                    /*sprintf(commandCopySourceFiles, "cp %s %s_BENEFICIARY/", formattedCurrentFileToTheTempImplantationDirectory, HostProject);
                    system(commandCopySourceFiles);
                    printf("\t\tSource File already is exists in the host enviroment. Nothing to be done!\n");
                }*/

            } else {
                printf("\tImplanting file %s in the host beneficiary environment.\n", currentSourceFile);
                /* There is no Source file in the Host. So it is copied to host environment -------------------------------*/
                char *formattedCurrentFileTransplantCodeDiretory = (char *) malloc(500 * sizeof(char));
                sprintf(formattedCurrentFileTransplantCodeDiretory, "%s%s", TransplantResultLocation,
                        currentSourceFile);

                //Add directive in the file
                ListOfString * fileWithDirectives = addDirectivesInFunction(formattedCurrentFileTransplantCodeDiretory);
                printAListOfStrings(fileWithDirectives,formattedCurrentFileTransplantCodeDiretory);
                freeListOfStrings(&fileWithDirectives);

                sprintf(commandCopySourceFiles, "cp %s %s", formattedCurrentFileTransplantCodeDiretory, dirHost);
                system(commandCopySourceFiles);
                fflush(stdout);

            }
            numberFile++;
            /* Add file in list of files already transplanted */
     //       addAStringsInTheEndFile(currentSourceFile,tempListOfFilesImplanted);
   //     }
        currentSourceFile++;
		auxListOfSourceHeaderFilesExtracted = auxListOfSourceHeaderFilesExtracted->next;
		fflush(stdout);

	}
    printf("\tInserting the host file with interface into the host\n");
    char *hostWithInterfacePath = (char *) malloc(5000 * sizeof(char));
    strcpy(hostWithInterfacePath, hostWithInterfaceOutputFile);

    /* Copy HostWith file*/
    char *commandCopyFileContent = (char *) malloc(500 * sizeof(char));
    sprintf(commandCopyFileContent, "cp -r %s %s", hostWithInterfacePath,transplantHostInputFile );
    int statusCommand = system(commandCopyFileContent);
    if (statusCommand != 0) {
        printf("ERROR: Copy hostWithInterface to host directory. \n\tNo such file or directory: %s\n",TransplantResultLocation);
        exit(1);
    }
  //  addLocsFromSourceToDestinationWithDirectives(transplantHostInputFile, hostWithInterfacePath, TXLToolsPath);
    //system(commandRewriteHost);

	/*ListOfFinalGlobalDeclarations = extractGlobalDeclarationFromHost(tempDirectory, TempImplantationDirectory, ListOfFinalGlobalDeclarations,
																	 sourceFilesInHost, tempSourceHeaderFilesTargetPath,
																	 AllDefinedFunctionsInDonor);*/

    /* Remove temp file from result TransplantCode directory*/
    removeSpecificTypeOfFileFromDirectory(TransplantResultLocation, "cNONExt");
    removeSpecificTypeOfFileFromDirectory(TransplantResultLocation, "cNON");
    removeSpecificTypeOfFileFromDirectory(TransplantResultLocation, "hNONExt");

	/*char *removeOldBeneficiary = (char *) malloc(1000 * sizeof(char));
	sprintf(removeOldBeneficiary, "rm -r -f %s_BENEFICIARY/",
			HostProject);
	system(removeOldBeneficiary);*/


    // * Move extracted files to the product base
    char *moveBeneficiary = (char *) malloc(200 * sizeof(char));
	sprintf(moveBeneficiary, "mv %s %s-%s/", HostProject, HostProject,
			ProductBase);
	system(moveBeneficiary);


	char *moveOriginal = (char *) malloc(1000 * sizeof(char));
	sprintf(moveOriginal, "mv %s_ORIGINAL %s", HostProject,
			HostProject);
	system(moveOriginal);

    /* Remove temp file from result TransplantCode directory*/
    char *HostProductBase = (char *) malloc(200 * sizeof(char));
    sprintf(HostProductBase, "%s-%s/", HostProject, ProductBase);
    removeSpecificTypeOfFileFromDirectory(HostProductBase, "cNONExt");
    removeSpecificTypeOfFileFromDirectory(HostProductBase, "cNON");
    removeSpecificTypeOfFileFromDirectory(HostProductBase, "hNONExt");

}
#else
void implantationOrgan(char * skeletonInterfaceSourceCodeOutput, char * listOfSourceFilesTargetPath,
					   char * listOfHeaderFilesTargetPath) {
	//copy the files into host at the host target file location and
	//rewrite the host target file

	printf("\nINSERTING ORGAN INTO THE HOST_BENEFICIARY\n");

	char *copyOriginalHost = (char *) malloc(1000 * sizeof(char));
	sprintf(copyOriginalHost, "cp -r %s %s_ORIGINAL", HostProject,
			HostProject);
	system(copyOriginalHost);

	char *tempDir = strdup(transplantHostInputFile);
	char *dir = dirname(tempDir);
	strcat(dir, "/");

	printf("Inserting Interface into the Host\n");
	char *commandCopyInterface = (char *) malloc(5000 * sizeof(char));
	sprintf(commandCopyInterface, "cp %s %s%s",
			skeletonInterfaceSourceCodeOutput, dir,
			InterfaceWithCoreFeatureFileName);
	system(commandCopyInterface);

	printf("Inserting Organ header file into the Host\n");
	char *commandCopyHeader = (char *) malloc(5000 * sizeof(char));
	sprintf(commandCopyHeader, "cp %s%s %s", TransplantResultLocation,
			InterfaceHeaderFileName, dir);
	system(commandCopyHeader);

	printf("Inserting the host file with interface into the host\n");
	char *commandRewriteHost = (char *) malloc(5000 * sizeof(char));
	sprintf(commandRewriteHost, "cp %s %s", hostWithInterfaceOutputFile,
			transplantHostInputFile);
	system(commandRewriteHost);

	char *sourceFilesInHost;
	sourceFilesInHost = (char *) malloc(500 * sizeof(char));
	sprintf(sourceFilesInHost, "%sallSouceFileInHost.out", TXLTemporaryMultiFileFolder);

	FILE *fSourceFileName = fopen(sourceFilesInHost, "w");
	readFilesFromDir(dir, fSourceFileName, 'c');
	readFilesFromDir(dir, fSourceFileName, 'h');
	fclose(fSourceFileName);// LOS: write lista with sourcefiles.c full path existing in donor file

	ListOfString *listOfFilesInHost = readListOfStringFromFile(sourceFilesInHost);
	ListOfString *auxListOfFilesInHost = listOfFilesInHost;
	char *line2 = (char *) malloc(400 * sizeof(char));
	char *currentSourceFile = (char *) malloc(1000 * sizeof(char));

	FILE *fSourceFilesExtracted = fopen(listOfSourceFilesTargetPath, "r");

	int numberFile = 1;

	printf("Inserting organ source code files\n");
	while (fgets(line2, 400, fSourceFilesExtracted) != NULL) {
		sscanf(line2, "%s", currentSourceFile);

		printf("\tFile [%d]: %s\n", numberFile, currentSourceFile);
		char *formattedCurrentFileTransplantCodeDiretory = (char *) malloc(500 * sizeof(char));
		sprintf(formattedCurrentFileTransplantCodeDiretory, "%s%s", TransplantResultLocation,
				currentSourceFile);

		char *formattedCurrentFileToTheHostDirectory = (char *) malloc(500 * sizeof(char));
		sprintf(formattedCurrentFileToTheHostDirectory, "\"%s%s\"\n", dir,
				currentSourceFile);

		char *hostBeneficiaryDirectory = (char *) malloc(500 * sizeof(char));
		sprintf(hostBeneficiaryDirectory, "%s%s", dir,
				currentSourceFile);


		if (searchStringInListOfStrings(auxListOfFilesInHost, formattedCurrentFileToTheHostDirectory)) {
			addLocsFromSourceToDestination(hostBeneficiaryDirectory, formattedCurrentFileTransplantCodeDiretory,
										   TXLToolsPath);

		} else {
			char *commandCopySourceFiles = (char *) malloc(5000 * sizeof(char));
			sprintf(commandCopySourceFiles, "cp %s %s", formattedCurrentFileTransplantCodeDiretory, dir);
			system(commandCopySourceFiles);
		}
		numberFile++;

	}
	fclose(fSourceFilesExtracted);

//LOS Implanting header files
	auxListOfFilesInHost = listOfFilesInHost;
	char * currentHeaderFile = (char *) malloc(1000 * sizeof(char));
	ListOfString * listOfHeaderFiles = readListOfStringFromFileAsWords(listOfHeaderFilesTargetPath);

	while(listOfHeaderFiles) {

		strcpy(currentHeaderFile, listOfHeaderFiles->el);

		printf("\tFile [%d]: %s\n", numberFile, currentHeaderFile);
		char *formattedCurrentFileTransplantCodeDiretory = (char *) malloc(500 * sizeof(char));
		sprintf(formattedCurrentFileTransplantCodeDiretory, "%s%s", TransplantResultLocation,
				currentHeaderFile);

		char *formattedCurrentFileToTheHostDirectory = (char *) malloc(500 * sizeof(char));
		sprintf(formattedCurrentFileToTheHostDirectory, "\"%s%s\"\n", dir,
				currentHeaderFile);

		char *hostBeneficiaryDirectory = (char *) malloc(500 * sizeof(char));
		sprintf(hostBeneficiaryDirectory, "%s%s", dir,
				currentHeaderFile);

		if (searchStringInListOfStrings(auxListOfFilesInHost, formattedCurrentFileToTheHostDirectory)) {
			addLocsFromSourceToDestination(hostBeneficiaryDirectory, formattedCurrentFileTransplantCodeDiretory,
										   TXLToolsPath);

		} else {
			char *commandCopySourceFiles = (char *) malloc(5000 * sizeof(char));
			sprintf(commandCopySourceFiles, "cp %s %s", formattedCurrentFileTransplantCodeDiretory, dir);
			system(commandCopySourceFiles);
		}
		listOfHeaderFiles = listOfHeaderFiles->next;
		numberFile++;
	}

	char *removeOldBeneficiary = (char *) malloc(1000 * sizeof(char));
	sprintf(removeOldBeneficiary, "rm -r -f %s_BENEFICIARY/",
			HostProject);
	system(removeOldBeneficiary);

	char *moveBeneficiary = (char *) malloc(1000 * sizeof(char));
	sprintf(moveBeneficiary, "mv %s %s_BENEFICIARY/", HostProject,
			HostProject);
	system(moveBeneficiary);

	char *moveOriginal = (char *) malloc(1000 * sizeof(char));
	sprintf(moveOriginal, "mv %s_ORIGINAL %s", HostProject,
			HostProject);
	system(moveOriginal);
}
#endif



void moveOverOrganToIceBoxDirectory(ListOfString * listOfSourceFilesExtracted, ListOfString * listOfHeaderFilesExtracted) {

	ListOfString * auxListOfSourceFilesExtracted = listOfSourceFilesExtracted;
	ListOfString * auxListOfHeaderFilesExtracted = listOfHeaderFilesExtracted;

	char *filesOutputPath = NULL;
	char *filesInputPath = NULL;

	/* LOS * Move the over organ source files to the IceBox ( TransplantCode Directory) */
	while (auxListOfSourceFilesExtracted) {
		filesOutputPath = (char *) malloc((strlen(auxListOfSourceFilesExtracted->el) + strlen(TransplantResultLocation ) + 1) * sizeof(char));
		filesInputPath = (char *) malloc((strlen(auxListOfSourceFilesExtracted->el) + strlen(TXLTemporaryMultiFileFolder) + 1) * sizeof(char));

		char *currentSourceFile = (char *) malloc((strlen(auxListOfSourceFilesExtracted->el) + 1) * sizeof(char));
		strcpy(currentSourceFile, auxListOfSourceFilesExtracted->el);

		sprintf(filesOutputPath, "%s%s", TransplantResultLocation, currentSourceFile);
		createFile(filesOutputPath);
		sprintf(filesInputPath, "%s%s", TXLTemporaryMultiFileFolder, currentSourceFile);

		addLocsFromSourceToDestination(filesOutputPath, filesInputPath, TXLToolsPath);

		auxListOfSourceFilesExtracted = auxListOfSourceFilesExtracted->next;
	}

	/* LOS * Move the over organ header files to the IceBox ( TransplantCode Directory) */

	while(auxListOfHeaderFilesExtracted) {

		filesOutputPath = (char *) malloc((strlen(auxListOfHeaderFilesExtracted->el) + strlen(TXLTemporaryMultiFileFolder) + 1) * sizeof(char));
		filesInputPath = (char *) malloc((strlen(auxListOfHeaderFilesExtracted->el) + strlen(TransplantResultLocation) + 1) * sizeof(char));

		char * currentHeaderFile = (char *) malloc((strlen(auxListOfHeaderFilesExtracted->el) + 1) * sizeof(char));
		strcpy(currentHeaderFile, auxListOfHeaderFilesExtracted->el);

		sprintf(filesInputPath, "%s%s", TXLTemporaryMultiFileFolder,currentHeaderFile );
		sprintf(filesOutputPath, "%s%s", TransplantResultLocation, currentHeaderFile);

		/* TODO change for specific header */
        char *commandCopySourceFiles = (char *) malloc(5000 * sizeof(char));
        sprintf(commandCopySourceFiles, "mv %s %s", filesInputPath, filesOutputPath);
        int statusCommand = system(commandCopySourceFiles);
        if(statusCommand != 0) {
            printf("Erro: Trying copy header file: %s", currentHeaderFile);
            exit(1);
        }
        /* TODO change for specific header */
		/*createFile(filesOutputPath);

		addLocsFromSourceToDestination(filesOutputPath, filesInputPath, TXLToolsPath);*/

		auxListOfHeaderFilesExtracted = auxListOfHeaderFilesExtracted->next;
	}

}

#define MAKEFILE_FOR_GP
#ifdef MAKEFILE_FOR_GP
void generateMakeFileForGP(char * checkWithMainMethodFile,
                                char * InterfaceWithCoreFeature, char * interfaceHeader, ListOfString * ListOfSourceFilesPath,
                                char * ListOfHeaderFilesExtracted,
                                char * programOutput, char * outputMakeFilePath) {

    printf("[PRODSCALPEL] Generating Makefile\n");

    ListOfString * makefileLines = NULL;
    ListOfString * listOfSourceFiles = ListOfSourceFilesPath;
    ///readListOfStringFromFileAsWords(listOfSourceFilesPath);
    ListOfString * listOfObjectSourceFiles = ListOfSourceFilesPath;
    ///readListOfStringFromFileAsWords(listOfSourceFilesPath);

    //ListOfString * listOfHeaderFiles = readListOfStringFromFileAsWords(listOfSourceFilesPath);
    //ListOfString * listOfObjectSourceFiles = listOfSourceFiles;
/*	ListOfString * auxListOfSourceFiles = listOfSourceFiles;

	while(auxListOfSourceFiles){
		addNewString(&listOfObjectSourceFiles, auxListOfSourceFiles->el);
		auxListOfSourceFiles = auxListOfSourceFiles->next;
	}*/

    ListOfString * listOfHeaderFiles = ListOfHeaderFilesExtracted;
            ///readListOfStringFromFileAsWords(tempAllHeaderFilesExtractedPath);



    ListOfString * auxListOfHeaderFiles = listOfHeaderFiles;
    char * formatListOfObjectHeaderFiles = (char *) malloc(10000 * sizeof(char));
    strcpy(formatListOfObjectHeaderFiles, "");

    fflush(stdout);
    while (auxListOfHeaderFiles){
        /* Remove "/" */
        /* if(strstr(auxListOfHeaderFiles->el,"/")){
             char *position = strstr(auxListOfHeaderFiles->el, "/");
             while(strstr(position+1, "/"))
                 position = strstr(position+1, "/");

             strcat(formatListOfObjectHeaderFiles, position+1);
         } else*/
        strcat(formatListOfObjectHeaderFiles, auxListOfHeaderFiles->el);
        fflush(stdout);
        strcat(formatListOfObjectHeaderFiles, ".gch ");

        auxListOfHeaderFiles = auxListOfHeaderFiles->next;
    }

    char * lineCFLAGS;
    char * testFgets = NULL;

    if (has_cflags) {
        FILE * finCFLAGS = fopen(CFLAGS_FILE, "r");

        lineCFLAGS = (char *) malloc(1000 * sizeof(char));

        testFgets = (char *) malloc(1000 * sizeof(char));
        testFgets = fgets(lineCFLAGS, 999, finCFLAGS);
        fflush(stdout);
        fclose(finCFLAGS);
    }

    ListOfString * AuxListOfObjectSourceFiles = copyListOfString(listOfObjectSourceFiles);

    char * currentObjectSourceFile;
    fflush(stdout);
    while (AuxListOfObjectSourceFiles){
        strtok(AuxListOfObjectSourceFiles->el, ".");
        strcat(AuxListOfObjectSourceFiles->el, ".o ");
        // addNewString(&listOfObjectSourceFiles, auxlistOfObjectSourceFiles);
        AuxListOfObjectSourceFiles = AuxListOfObjectSourceFiles ->next;
        fflush(stdout);
    }

    if (!testFgets) {
        fflush(stdout);
        addNewString(&makefileLines,
                     "CHECKPACKAGE = `pkg-config --cflags --libs check`\n\n");

        char *checkWithMainMethodObjectFile = NULL;
        char *interfaceWithCoreFeatureObjectFile = NULL;

        checkWithMainMethodObjectFile = (char *) malloc(500 * sizeof(char));
        interfaceWithCoreFeatureObjectFile = (char *) malloc(
                500 * sizeof(char));

        strcpy(checkWithMainMethodObjectFile, checkWithMainMethodFile);
        strtok(checkWithMainMethodObjectFile, ".");
        strcat(checkWithMainMethodObjectFile, ".o");

        strcpy(interfaceWithCoreFeatureObjectFile, InterfaceWithCoreFeature);
        strtok(interfaceWithCoreFeatureObjectFile, ".");
        strcat(interfaceWithCoreFeatureObjectFile, ".o");

        ListOfString * auxListOfObjectSourceFiles = listOfObjectSourceFiles;
        char * formatListOfObjectSourceFiles = (char *) malloc(10000 * sizeof(char));

        while (auxListOfObjectSourceFiles){
            strcpy(formatListOfObjectSourceFiles, auxListOfObjectSourceFiles ->el);
            strcat(formatListOfObjectSourceFiles, " ");

            auxListOfObjectSourceFiles = auxListOfObjectSourceFiles ->next;
        }
        char *line;
        line = (char *) malloc(3000 * sizeof(char));

        sprintf(line, "%s:\t%s %s %s\n", programOutput,
                checkWithMainMethodObjectFile,
                interfaceWithCoreFeatureObjectFile, formatListOfObjectSourceFiles);
        addNewString(&makefileLines, line);

        sprintf(line, "\tgcc -std=gnu99 -o %s %s %s  %s -lm $(CHECKPACKAGE)\n\n",
                programOutput, checkWithMainMethodObjectFile,
                interfaceWithCoreFeatureObjectFile, formatListOfObjectSourceFiles);

        addNewString(&makefileLines, line);
/*
        //main.o:	InterfaceHeader.h main.c
        sprintf(line, "%s:\t%s %s\n", checkWithMainMethodObjectFile, interfaceHeader,
                checkWithMainMethodFile);
        addNewString(&makefileLines, line);
        //gcc -std=gnu99 -c -o main.o main.c $(CFLAGS)
        sprintf(line, "\tgcc -std=gnu99 -c -o %s %s\n\n",
                checkWithMainMethodObjectFile, checkWithMainMethodFile);
        addNewString(&makefileLines, line);
*/
        //InterfaceWithCoreFeature.o:	x_header.h InterfaceHeader.h InterfaceWithCoreFeature.c
        sprintf(line, "%s:\t%s %s %s\n", interfaceWithCoreFeatureObjectFile, formatListOfObjectHeaderFiles,
                interfaceHeader, InterfaceWithCoreFeature);
        addNewString(&makefileLines, line);

        //gcc -std=gnu99 -c -o InterfaceWithCoreFeature.o InterfaceWithCoreFeature.c $(CFLAGS)
        sprintf(line, "\tgcc -std=gnu99 -c -o %s %s\n\n",
                interfaceWithCoreFeatureObjectFile, InterfaceWithCoreFeature);
        addNewString(&makefileLines, line);

        auxListOfObjectSourceFiles = listOfObjectSourceFiles;
        ListOfString * auxListOfSourceFiles = listOfSourceFiles;
        while(auxListOfObjectSourceFiles){
            fflush(stdout);
            //x_souceFile.o:	InterfaceHeader.h x_sourceFile.c
            sprintf(line, "%s:\t%s %s %s\n", auxListOfObjectSourceFiles->el,
                    formatListOfObjectHeaderFiles, auxListOfObjectSourceFiles->el);
            addNewString(&makefileLines, line);
            //gcc -std=gnu99 -c -o x_souceFile.o x_sourceFile.c $(CFLAGS)
            sprintf(line, "\tgcc -std=gnu99 -c -o %s %s\n\n",
                    auxListOfObjectSourceFiles->el, auxListOfSourceFiles->el);
            addNewString(&makefileLines, line);

            auxListOfObjectSourceFiles = auxListOfObjectSourceFiles->next;
            auxListOfSourceFiles = auxListOfSourceFiles->next;
        }
        //LOS Add clean
        addNewString(&makefileLines,  "clean:\n\trm -rf *.o Individual.x\n");

        char * makefileOutputFile;
        makefileOutputFile = (char *) malloc(500 * sizeof(char));
        sprintf(makefileOutputFile, "%sMakefile", TransplantResultLocation);

        printAListOfStrings(makefileLines, makefileOutputFile);
    } else {
        fflush(stdout);
        char * cflagsInMakeFile = (char *) malloc(2000 * sizeof(char));
        sprintf(cflagsInMakeFile, "%s\n", lineCFLAGS);

        addNewString(&makefileLines, cflagsInMakeFile);

        addNewString(&makefileLines,
                     "CHECKPACKAGE = `pkg-config --cflags --libs check`\n\n");

        char * checkWithMainMethodObjectFile = NULL;
        char * interfaceWithCoreFeatureObjectFile = NULL;

        checkWithMainMethodObjectFile = (char *) malloc(500 * sizeof(char));
        interfaceWithCoreFeatureObjectFile = (char *) malloc(
                500 * sizeof(char));

        strcpy(checkWithMainMethodObjectFile, checkWithMainMethodFile);
        strtok(checkWithMainMethodObjectFile, ".");
        strcat(checkWithMainMethodObjectFile, ".o");

        strcpy(interfaceWithCoreFeatureObjectFile, InterfaceWithCoreFeature);
        strtok(interfaceWithCoreFeatureObjectFile, ".");
        strcat(interfaceWithCoreFeatureObjectFile, ".o");

        ListOfString * auxListOfObjectSourceFiles = listOfObjectSourceFiles;
        char * formatListOfObjectSourceFiles = (char *) malloc(10000 * sizeof(char));

        while (auxListOfObjectSourceFiles){
            strcat(formatListOfObjectSourceFiles, auxListOfObjectSourceFiles->el);
            strcat(formatListOfObjectSourceFiles, " ");
            fflush(stdout);
            auxListOfObjectSourceFiles = auxListOfObjectSourceFiles->next;
        }

        char * line;
        line = (char *) malloc(3000 * sizeof(char));

        sprintf(line, "%s:\t%s %s %s\n", programOutput,
                checkWithMainMethodObjectFile,
                interfaceWithCoreFeatureObjectFile, formatListOfObjectSourceFiles);
        addNewString(&makefileLines, line);

        sprintf(line,
                "\tgcc -std=gnu99 -o %s %s %s %s -lm $(CHECKPACKAGE) $(CFLAGS)\n\n",
                programOutput, checkWithMainMethodObjectFile,
                interfaceWithCoreFeatureObjectFile , formatListOfObjectSourceFiles);


        addNewString(&makefileLines, line);
        //main.o:	InterfaceHeader.h main.c
      /*  sprintf(line, "%s:\t%s %s\n", checkWithMainMethodObjectFile,
                interfaceHeader, checkWithMainMethodFile);
        addNewString(&makefileLines, line);
        sprintf(line, "\tgcc -std=gnu99 -c -o %s %s $(CFLAGS)\n\n",
                checkWithMainMethodObjectFile, checkWithMainMethodFile);
        addNewString(&makefileLines, line);*/

        //InterfaceWithCoreFeature.o:	x_header.h InterfaceHeader.h InterfaceWithCoreFeature.c
        sprintf(line, "%s:\t%s %s %s\n", interfaceWithCoreFeatureObjectFile, formatListOfObjectHeaderFiles,
                interfaceHeader, InterfaceWithCoreFeature);
        addNewString(&makefileLines, line);
        sprintf(line, "\tgcc -std=gnu99 -c -o %s %s $(CFLAGS)\n\n",
                interfaceWithCoreFeatureObjectFile, InterfaceWithCoreFeature);
        addNewString(&makefileLines, line);

        auxListOfObjectSourceFiles = listOfObjectSourceFiles;
        ListOfString * auxListOfSourceFiles = listOfSourceFiles;
    /*    while(auxListOfObjectSourceFiles){
            fflush(stdout);
            //x_souceFile.o:	InterfaceHeader.h x_sourceFile.c
            sprintf(line, "%s:\t%s %s %s\n", auxListOfObjectSourceFiles->el,
                    formatListOfObjectHeaderFiles,interfaceHeader, auxListOfSourceFiles->el);
            addNewString(&makefileLines, line);
            //gcc -std=gnu99 -c -o x_souceFile.o x_sourceFile.c $(CFLAGS)
            sprintf(line, "\tgcc -std=gnu99 -c -o %s %s",
                    auxListOfObjectSourceFiles->el, auxListOfSourceFiles->el);
            strcat(line, " $(CFLAGS)\n\n");
            addNewString(&makefileLines, line);

            auxListOfObjectSourceFiles = auxListOfObjectSourceFiles->next;
            auxListOfSourceFiles = auxListOfSourceFiles->next;
        }*/
        //LOS Add clean
        addNewString(&makefileLines,  "clean:\n\trm -rf *.o Individual.x\n");

        char * makefileOutputFile;
        makefileOutputFile = (char *) malloc(500 * sizeof(char));
        sprintf(makefileOutputFile, "%sMakefile", outputMakeFilePath);
        fflush(stdout);
        printAListOfStrings(makefileLines, makefileOutputFile);
    }
}

#endif

#if 1 //LOSMULTIFILESIMPLEMENTATION
void GPAlgorithm2(ListOfString * SkeletonSourceCode,
				 char * GraftInterfaceTempOutput,
				 char * sourceOutputCoreFunctionality,
				 char * InterfaceCoreFunctionality,
				 char * skeletonInterfaceSourceCodeOutput,
				 ArrayOfStrings SkeletonLOCsArray,
				 DependencyList * ListOfDependenciesForStatements,
				 CallDependency * ListOfNeededFunctionsForAllLOCs,
				 GlobalDeclarations ListOfFinalGlobalDeclarations,
				 DependencyList * GlobalDependencyList,
				 DependencyList * SkeletonDependenciesOnGlobals,
				 char * tempGlobalDeclarations,
				 char * definedGlobalTypesAndVariablesFile, char * GraftFunctionName,
				 char * interfaceHeaderGlobalsAndGraftFunction,
				 int TotalIDsInHostSymbolTable,
				 MappingCandidate * MappingCandidatesForGP,
				 DeclarationSymbolTable * GraftSymbolTablePossibleMatching,
				 Mapping * CurrentDonorMappings,
				 DependencyListWithID * dependencyListForAbstract,
				 char * tempDefinesFile, char *tempIncludeLibFile,
				 char * finalInterfaceForCompilation, SymbolTable * HostSymbolTable,
				 char * GlobalFctDependOutput,
				 ListOfString * listOfSourceFiles,
				 ListOfString * listOfHeaderFiles,
				 DependencyList * GlobalDependencyListMultiFiles, ListOfString * TheListOfTransplantedMarkers) {

	fflush(stdout);
    char * logFolderPath = TransplantLogFolder;
    char * outputFile = (char *) malloc(500 * sizeof(int));

#if 0
	printAListOfStrings(SkeletonSourceCode, "skeletoOutputtest.out");
#endif

	//first seed the pseudo number generators

	randomNumbersSeeding();

	//first warm up pseudo generators

#if 0
	FILE * rand1 = fopen("rand1.out", "w");
	FILE * rand2 = fopen("rand2.out", "w");
	FILE * rand3 = fopen("rand3.out", "w");
	FILE * rand4 = fopen("rand4.out", "w");
	FILE * rand5 = fopen("rand5.out", "w");
	FILE * rand6 = fopen("rand6.out", "w");
	FILE * rand7 = fopen("rand7.out", "w");
#endif
	for (int i = 0; i < 2000; i++) {
		unsigned int x = JKISS();
		unsigned int y = JKISSOperation();
		unsigned int z = JKISSAbstractMappings();
		unsigned int a = JKISSCrossoverSelector();
		unsigned int b = JKISSLoclDecl();
		unsigned int c = JKISSPopulationSelection();
		unsigned int d = JKISSStrings();

#if 0
		fprintf(rand1, "%u ", x);
		fprintf(rand2, "%u ", y);
		fprintf(rand3, "%u ", z);
		fprintf(rand4, "%u ", a);
		fprintf(rand5, "%u ", b);
		fprintf(rand6, "%u ", c);
		fprintf(rand7, "%u ", d);
#endif

	}
    TheListOfTransplantedMarkers = createTheListOfAllMarkers(
            SkeletonSourceCode, TXLTemporaryFolderMainThread);

    ListOfString * graftInterfaceTempOutputForFinalInstantiation =
            readListOfStringFromFile(GraftInterfaceTempOutput);

	/*ListOfString * sourceOutputCoreFunctionalitiesForFinalInstantiation =
			readListOfStringFromFile(SourceOutputCoreFunctionalities);*/

    ListOfString * sourceOutputCoreFunctionalitiesForFinalInstantiation =
            readListOfStringFromFile(InterfaceCoreFunctionality);

	ListOfString * neededFunctionHeaderInitialOutput = readListOfStringFromFile(
			SkeletonCoreFeatureHeader);

	char * graftInterfaceTempOutputForFinalInstantiationFile;
	graftInterfaceTempOutputForFinalInstantiationFile = (char *) malloc(
			1000 * sizeof(char));

	sprintf(graftInterfaceTempOutputForFinalInstantiationFile,
			"%stemp_interface_temp_output_final_instantiation.out",
			TXLTemporaryFolderMainThread);
    printAListOfStrings(graftInterfaceTempOutputForFinalInstantiation,
                        graftInterfaceTempOutputForFinalInstantiationFile);


	moveOverOrganToIceBoxDirectory(listOfSourceFiles, listOfHeaderFiles);

#if 0 /* MULTIFILES */

	char * sourceContentFilesTarget;
	sourceContentFilesTarget = (char *) malloc(500 * sizeof(char));
	sprintf(sourceContentFilesTarget, "%stemp_list_of_source_files_extracted.out", TXLTemporaryMultiFileFolder);

	/* rewrite tempGlobalDeclarations for tempGlobalDeclarationsMultiFiles */
	char * tempGlobalDeclarationsMultiFiles;
	tempGlobalDeclarationsMultiFiles = (char *) malloc(500 * sizeof(char));
	sprintf(tempGlobalDeclarationsMultiFiles, "%stemp_global_variable_declarations",
			TXLTemporaryMultiFileFolder); //LOSTEMP TXLTemporaryFolderMainThread TXLTemporaryMultiFileFolder

	/* rewrite definedGlobalTypesAndVariablesFile for definedGlobalTypesAndVariablesMultiFiles */
	char * definedGlobalTypesAndVariablesMultiFiles;
	definedGlobalTypesAndVariablesMultiFiles = (char *) malloc(500 * sizeof(char));
	sprintf(definedGlobalTypesAndVariablesMultiFiles, "%stemp_global_type_var_declarations.out",
			TXLTemporaryMultiFileFolder);

	char * currentSourceFile;
	currentSourceFile = (char*) malloc(400 * sizeof(char));
	char *line;
	line = (char *) malloc(400 * sizeof(char));
	FILE * fin = fopen(sourceContentFilesTarget, "r");

	char * currentOutputSourcePath;
	currentOutputSourcePath = (char *) malloc(500 * sizeof(char));

	DependencyList * DependencyListGlobalCoreFunctionsMultiFiles = NULL;

	// TODO rewrite this MULTIFILES code, add include core feature header
	// LOS  create new file with include: #include "InterfaceHeader.h" in order to be add in all files
	char * includeCoreFeatureHeader;
	includeCoreFeatureHeader = (char *) malloc(1000 * sizeof(char));
	sprintf(includeCoreFeatureHeader, "#include \"%s\"\n",
			InterfaceHeaderFileName);

	char * headerFileForCoreFeaturePath;
	headerFileForCoreFeaturePath = (char *) malloc(400 * sizeof(char));
	sprintf(headerFileForCoreFeaturePath, "%stemp_interface_header.out", TXLTemporaryMultiFileFolder);
	//printAListOfStrings(includeCoreFeatureHeader, headerFileForCoreFeaturePath);
	FILE * fout = fopen(headerFileForCoreFeaturePath, "w");
	fprintf(fout, "%s", includeCoreFeatureHeader);
	fclose(fout);

	char * listOfHeadFilesTargetPath;
	listOfHeadFilesTargetPath = (char *) malloc(500 * sizeof(char));
	sprintf(listOfHeadFilesTargetPath, "%stemp_list_of_header_files.out", TXLTemporaryMultiFileFolder);

/* LOS: Insert global declaration in each source file extracted */
	while (fgets(line, 400, fin) != NULL) {
		sscanf(line, "%s", currentSourceFile);

		sprintf(currentOutputSourcePath, "%s%s", TXLTemporaryMultiFileFolder, currentSourceFile);

		extractNeededFunctionsAndGlobalDeclarationsForSelectedLOCsInMultiFiles(
				currentOutputSourcePath, ListOfNeededFunctionsForAllLOCs,
				ListOfFinalGlobalDeclarationsMultiFiles, GlobalDependencyListMultiFiles,
				SkeletonDependenciesOnGlobals, tempGlobalDeclarationsMultiFiles,
				definedGlobalTypesAndVariablesMultiFiles, SkeletonSourceCode,
				TheListOfTransplantedMarkers, GlobalFctDependOutput,
				TXLTemporaryMultiFileFolder);

		/* Insert include InterfaceHeade.h */
		addLocsFromSourceToDestination(currentOutputSourcePath,
									   headerFileForCoreFeaturePath, TXLToolsPath);

	}
	fclose(fin);
#endif

#if 0 /* MULTIFILES */

	constructListOfGlobalDeclarationsMultiFiles( TXLTemporaryMultiFileFolder, TXLTemporaryFolderMainThread );
	fflush(stdout);
#endif

	//first, add to the MappingCandidatesForGp the values in current donor source code for mappings
	//try to add the values from the mapping table
	//first check it with random

	//addNewCurrentMappingFromMappings(&MappingCandidatesForGP, CurrentDonorMappings);
	addOneRandomCurrentMappingMappingCandidate(MappingCandidatesForGP);

	fflush(stdout);

	//for the ones that are not in current mappings (ie. entry point arguments), randomly select one from possible
	//or remove it from mapping candidates, since it is not possible to map it if there is not any possible
	//mapping

	MappingCandidate * auxMappingCandidate = MappingCandidatesForGP;

	while (auxMappingCandidate) {
		int signal = 0;
		//just if there is not already a current mapping
		if (!auxMappingCandidate->currentMapping) {
			if (!auxMappingCandidate->possibleMappings) {
				//remove mapping candidate
				//first go to the next element, since the current one will be removed;
				char * auxID = (char *) malloc(500 * sizeof(char));
				strcpy(auxID, auxMappingCandidate->id);

				char * auxType = (char *) malloc(500 * sizeof(char));
				strcpy(auxType, auxMappingCandidate->type);

				auxMappingCandidate = auxMappingCandidate->next;
				removeMappingCandidate(&MappingCandidatesForGP, auxID, auxType);

				free(auxID);
				free(auxType);

				signal = 1;
			} else {
				int lengthPossibleMappings = countElementsInListOfString(
						auxMappingCandidate->possibleMappings);
				int randomIndexPossibleMapping = randomIndexJKISSStrings(
						lengthPossibleMappings, NULL);

				char * selectedMappingString = nthElementInListString(
						auxMappingCandidate->possibleMappings,
						randomIndexPossibleMapping);
				addNewCurrentMapping(&MappingCandidatesForGP,
									 auxMappingCandidate->id, selectedMappingString);
			}
		}
		if (!signal) {
			auxMappingCandidate = auxMappingCandidate->next;
		}
	}

	//length of Mapping Candidates
	int lengthOfMappingCandidate = countElementsInListOfMappingCandidate(
			MappingCandidatesForGP);

	/* LOS Add all defines in InterfaceCoreFunctionality.c */
///	addLocsFromSourceToDestination(interfaceHeaderGlobalsAndGraftFunction, tempDefinesFile, TXLToolsPath);

	/* LOS Add all includes in InterfaceCoreFunctionality.c */
///	addLocsFromSourceToDestination(interfaceHeaderGlobalsAndGraftFunction,tempIncludeLibFile, TXLToolsPath);

	DeclarationSymbolTable * justElementsWithPossibleMappings =
			returnNewDeclSymbolTableJustForElementsWithPossibleMappings(
					GraftSymbolTablePossibleMatching);
#if 0
	printDeclarationSymbolTable("/home/---/Development/TEST_ST.out", justElementsWithPossibleMappings);
	printAMappingCandidateList("/home/---/Development/mapCand.out", MappingCandidatesForGP);
	FILE * testFout  = fopen("/home/---/Development/locsArray.out", "w");
	for(int i = 0; i < SkeletonLOCsArray.count; i++){
		fprintf(testFout,"%s\n",SkeletonLOCsArray.array[i]);
	}
	fclose(testFout);

#endif

	addOneRandomCurrentMappingDeclarationSymbolTable(
			justElementsWithPossibleMappings);
	//initially add current marker at all of them!!
	//addCurrentMarkerDeclarationSymbolTable(justElementsWithPossibleMappings);

	int lengthOfDeclarationMappings = countElementsInDeclarationSymbolTable(
			justElementsWithPossibleMappings);

	/*
	 ArrayOfMappingCandidates testArrayMapping = returnListOfCandidatesWithMoreThanOnePossibleMappingPointers(MappingCandidatesForGP);
	 testArrayMapping.array[0]->currentMapping = NULL;
	 testArrayMapping.array[0]->possibleMappings = NULL;
	 */
    char * localSkeletonCoreFeatureHeader = (char *) malloc (1000 * sizeof(char));
    sprintf(localSkeletonCoreFeatureHeader, "%sNeededFunctionsHeader.h", TXLTemporaryFolderMainThread);

    addLocsFromSourceToDestination(finalInterfaceForCompilation,interfaceHeaderGlobalsAndGraftFunction, TXLToolsPath);

    addLocsFromSourceToDestination(finalInterfaceForCompilation,
                                   localSkeletonCoreFeatureHeader, TXLToolsPath);

    char * localSourceOutputCoreFunctionalities = (char *) malloc (1000 * sizeof(char));
    sprintf(localSourceOutputCoreFunctionalities, "%sInterfaceCoreFunctionality.c", TXLTemporaryFolderMainThread);
    addLocsFromSourceToDestination( skeletonInterfaceSourceCodeOutput, graftInterfaceTempOutputForFinalInstantiationFile, TXLToolsPath);

    addLocsFromSourceToDestination(skeletonInterfaceSourceCodeOutput,
                                   localSourceOutputCoreFunctionalities, TXLToolsPath);

    /* Remove annotation from function interface  InterfaceWithCoreFeature.c */
    ListOfString * interfaceContent = readListOfStringFromFile(skeletonInterfaceSourceCodeOutput);
    replaceOneLineInALIst(&interfaceContent, "__INTERFACE_FUNCTION", "\t//__INTERFACE_FUNCTION\n");
    printAListOfStrings(interfaceContent, skeletonInterfaceSourceCodeOutput);
    /* Run make clean */
	char * commandMakeClean;
    commandMakeClean = (char *) malloc(1000 * sizeof(char));
    sprintf(commandMakeClean, "cd %s \nmake clean %s", TransplantResultLocation, ConsoleStderrOutput);

    int resultCmdMakeClean = system(commandMakeClean);
    if (resultCmdMakeClean != 0) {
        printf("\tCommand Make Clean Failed.\n");
        exit(1);
    }

    ListOfString * auxListOfHeaderFiles = listOfHeaderFiles;
    fflush(stdout);
    char * commandMakeHeader;
    commandMakeHeader = (char *) malloc(500 * sizeof(char));
    while (auxListOfHeaderFiles){
        sprintf(commandMakeHeader, "cd %s \ngcc %s %s", TransplantResultLocation, auxListOfHeaderFiles->el, ConsoleStderrOutput);
        int resultCmdMakeHeader = system(commandMakeHeader);
        if (resultCmdMakeHeader != 0) {
            printf("\tCommand Make header Failed. The over-organ extracted is not compiling.\n");
            exit(1);
        }
        auxListOfHeaderFiles = auxListOfHeaderFiles->next;
    }
    free(commandMakeHeader);

    printf("\n======================================================\n");
    printf("COMPILING OVER-ORGAN...\n");
    char * commandMake = (char *) malloc(1000 * sizeof(char));
    sprintf(commandMake, "cd %s \nmake %s", TransplantResultLocation, ConsoleStderrOutput);
    int resultCmdMake = system(commandMake);
    if (resultCmdMake != 0) {
        printf("\tCommand Make Failed. The over-organ extracted is not compiling.\n");
        char * openErrorFile = (char *) malloc(1000 * sizeof(char));
        sprintf(openErrorFile, "cd %s \nErrorFile.out", TransplantResultLocation);
        system(openErrorFile);
        exit(1);
    }else

        printf("OK\n");
    printf("======================================================\n");

    ///generateMakeFileForGP("main_organ.c", InterfaceWithCoreFeatureFileName, InterfaceHeaderFileName, listOfSourceFiles, listOfHeaderFiles, "Individual.x", TransplantResultLocation);

    ///implantationOrgan(skeletonInterfaceSourceCodeOutput, listOfSourceFiles, listOfHeaderFiles, inputFileGraft);

    printf("[PRODSCALPEL] Starting GP process...\n");
    printf("\tGENERATION NUMBER: 0 =================================\n");

	GPIndividual * listOfInitialPopulation = generateInitialPopulation(
			MappingCandidatesForGP, justElementsWithPossibleMappings,
			lengthOfMappingCandidate, lengthOfDeclarationMappings,
			SkeletonSourceCode, SkeletonLOCsArray, GraftInterfaceTempOutput,
			interfaceHeaderGlobalsAndGraftFunction, TotalIDsInHostSymbolTable,
			ListOfDependenciesForStatements, skeletonInterfaceSourceCodeOutput,
			dependencyListForAbstract, finalInterfaceForCompilation,
			HostSymbolTable, TXLTemporaryFolderMainThread, listOfSourceFiles);

	sortPopulationByFitness(&listOfInitialPopulation);

#ifdef REDUCE_CANDIDATE
	char * fileOfReducedIndividual = (char *) malloc(
			3000 * sizeof(char));
	sprintf(fileOfReducedIndividual,
			"%sReducedInterfaceWithCoreFeature.c",
			TransplantResultLocation);

	reduceCandidate(skeletonInterfaceSourceCodeOutput, fileOfReducedIndividual,TXLTemporaryFolderMainThread);

#endif

///	char * logFolderPath = TransplantLogFolder;
///	char * outputFile = (char *) malloc(500 * sizeof(int));

	//clean LOG folder, if there is a LOG folder
    char * stepTime = (char *) malloc(500 * sizeof(int));
    sprintf(stepTime, "Adaptation stage..: %s", getTime());
    printf("%s",stepTime);
    addNewString(&execution_log, stepTime);

	if (logFolderPath) {
		char * commandCleanFolder;
		commandCleanFolder = (char *) malloc(1000 * sizeof(char));
		sprintf(commandCleanFolder, "cd %s \n rm *.*", logFolderPath);
		int x = system(commandCleanFolder);
		if (x) {
			printf("ERROR CLEEAN FOLDER!\n");
			printf("%s\n", commandCleanFolder);
		}

		sprintf(outputFile, "%slog_generation_initialPopulation.out",
				logFolderPath);
		printAListOfGPIndividual(listOfInitialPopulation, outputFile);
	}

	//int generationNumber = 1;

	// First prepare for multithreading, so just copy all the transplant working folder

	char * GraftInterfaces[NO_THREADS];
	char * IntHeaderGlobalFcts[NO_THREADS];
	char * TransplantResultsLocations[NO_THREADS];
	char * TransplantedSourceFiles[NO_THREADS];
	char * TransplantedHeaderFiles[NO_THREADS];
	SymbolTable * HostSymbolTableS[NO_THREADS];
	ListOfString * SkeletonSourceCodeS[NO_THREADS];
	ArrayOfStrings SkeletonLOCsArrayS[NO_THREADS];
	DependencyList * ListOfDependenciesForStatementsS[NO_THREADS];
	DependencyListWithID * dependencyListForAbstractS[NO_THREADS];
	char * TXLTemporaryFolders[NO_THREADS];

	char * transplantResultLocationNoSlash = (char *) malloc(
			strlen(TransplantResultLocation) + 1 * sizeof(char));
	strcpy(transplantResultLocationNoSlash, TransplantResultLocation);
	transplantResultLocationNoSlash[strlen(transplantResultLocationNoSlash) - 1] =
			0;

	char * transplantWorkFolderNoSlash = (char *) malloc(
			strlen(transplantWorkFolderMainThread) + 1 * sizeof(char));
	strcpy(transplantWorkFolderNoSlash, transplantWorkFolderMainThread);
	transplantWorkFolderNoSlash[strlen(transplantWorkFolderNoSlash) - 1] = 0;

	for (int i = 0; i < NO_THREADS; i++) {
		char * commandCp = (char *) malloc(2000 * sizeof(char));
		sprintf(commandCp,
				"cp -r %s %s-%d && cp %s %s-%d/graftIntTempOut.out && cp %s %s-%d/interfaceHeaderGlobalAndGraft.out && cp -r %s %s/TEMP-%d",
				TransplantResultLocation, transplantResultLocationNoSlash, i,
				GraftInterfaceTempOutput, transplantResultLocationNoSlash, i,
				interfaceHeaderGlobalsAndGraftFunction,
				transplantResultLocationNoSlash, i,
				TXLTemporaryFolderMainThread, transplantWorkFolderNoSlash, i);
		int statusCp = system(commandCp);
		if (statusCp != 0) {
			printf("ERROR! copy for multithread");
			fflush(stdout);
		}

		TransplantResultsLocations[i] = (char *) malloc(1000 * sizeof(char));
		sprintf(TransplantResultsLocations[i], "%s-%d/",
				transplantResultLocationNoSlash, i);
		GraftInterfaces[i] = (char *) malloc(1000 * sizeof(char));
		sprintf(GraftInterfaces[i], "%s-%d/graftIntTempOut.out",
				transplantResultLocationNoSlash, i);
		IntHeaderGlobalFcts[i] = (char *) malloc(1000 * sizeof(char));
		sprintf(IntHeaderGlobalFcts[i],
				"%s-%d/interfaceHeaderGlobalAndGraft.out",
				transplantResultLocationNoSlash, i);
		TransplantedSourceFiles[i] = (char *) malloc(1000 * sizeof(char));
		sprintf(TransplantedSourceFiles[i], "%s-%d/InterfaceWithCoreFeature.c",
				transplantResultLocationNoSlash, i);
		TransplantedHeaderFiles[i] = (char *) malloc(1000 * sizeof(char));
		sprintf(TransplantedHeaderFiles[i], "%s-%d/InterfaceHeader.h",
				transplantResultLocationNoSlash, i);

		TXLTemporaryFolders[i] = (char *) malloc(1000 * sizeof(char));
		sprintf(TXLTemporaryFolders[i], "%s/TEMP-%d/",
				transplantWorkFolderNoSlash, i);

		HostSymbolTableS[i] = copySymbolTableList(HostSymbolTable);
		SkeletonSourceCodeS[i] = copyCompleteListOfString(SkeletonSourceCode);
		SkeletonLOCsArrayS[i] = copyArrayOfStrings(SkeletonLOCsArray);
		ListOfDependenciesForStatementsS[i] = copyDependencyList(
				ListOfDependenciesForStatements);
		dependencyListForAbstractS[i] = copyDependencyListWithID(
				dependencyListForAbstract);

		free(commandCp);

	}
  ///  free(transplantResultLocationNoSlash);
 /*   instantiateAnIndividualFromGPIndividual(SkeletonSourceCode,
                                            graftInterfaceTempOutputForFinalInstantiationFile,
                                            SourceOutputCoreFunctionalities,
                                            skeletonInterfaceSourceCodeOutput, SkeletonLOCsArray,
                                            ListOfDependenciesForStatements,
                                            ListOfNeededFunctionsForAllLOCs, ListOfFinalGlobalDeclarations,
                                            GlobalDependencyList, SkeletonDependenciesOnGlobals,
                                            tempGlobalDeclarations, definedGlobalTypesAndVariablesFile,
                                            GraftFunctionName, finalInterfaceForCompilation,
                                            TotalIDsInHostSymbolTable, listOfInitialPopulation,
                                            dependencyListForAbstract, GlobalFctDependOutput,
                                            TXLTemporaryFolderMainThread);


    implantationOrgan(skeletonInterfaceSourceCodeOutput, listOfSourceFilesTargetPath, listOfHeaderFilesTargetPath, inputFileGraft);
*/
	//implantationOrgan(skeletonInterfaceSourceCodeOutput, listOfSourceFilesTargetPath, listOfHeaderFilesTargetPath, inputFileGraft);

	while (generationNumber <= NUMBER_OF_GENERATIONS && !ALL_TEST_CASE_PASSED) {

		printf("GENERATION NUMBER: %d  =================================\n", generationNumber);
#if 0 //LOS REDUCE CANDIDATE TEST
		char * fileOfReducedIndividual = (char *) malloc(
				3000 * sizeof(char));
		sprintf(fileOfReducedIndividual,
				"%sReducedInterfaceWithCoreFeature.c",
				TransplantResultLocation);

		reduceCandidate(skeletonInterfaceSourceCodeOutput, fileOfReducedIndividual,TXLTemporaryFolderMainThread);

#endif

#ifdef EXPERIMENT_RUN
        /* Checking execution timeout */
        clock_t current_execution_time = clock();
        int time_spent = (int)(current_execution_time - begin_execution_time) / CLOCKS_PER_SEC;
      //  if( time_spent > 14000){
      if (generationNumber > 270){
            //clean LOG folder, if there is a LOG folder
            char * stepTime = (char *) malloc(500 * sizeof(int));
            sprintf(stepTime, "Adaptation time: %sExecution timeout: %d minutes.\n", getTime(),time_spent);
            strcat(stepTime, "Execution aborting!!\n");
            addNewString(&execution_log, stepTime);
            if (logFolderPath) {
                sprintf(outputFile, "%slog_execution.out", logFolderPath);
                printAListOfStrings(execution_log, outputFile);
            }
            printf("Execution time: %d\n", time_spent);
            printf("Execution timeout, aborting!!");

          // log_execution
          char * logFolderPath = TransplantLogFolder;
          char * outputFile = (char *) malloc(500 * sizeof(int));
          sprintf(stepTime, "Finishing..: %s", getTime());
          printf("%s",getTime());
          addNewString(&execution_log, stepTime);

          if (logFolderPath) {
              sprintf(outputFile, "%slog_execution.out", logFolderPath);
              printAListOfStrings(execution_log, outputFile);
          }

          exit(1);
        }else{
            printf("[PRODSCALPEL] Execution time: %d\n",time_spent );
        }
#endif

		newGeneration(&listOfInitialPopulation, SkeletonLOCsArray,
					  lengthOfMappingCandidate, HostSymbolTable, SkeletonSourceCode,
					  GraftInterfaceTempOutput,
					  interfaceHeaderGlobalsAndGraftFunction,
					  TotalIDsInHostSymbolTable, ListOfDependenciesForStatements,
					  skeletonInterfaceSourceCodeOutput, dependencyListForAbstract,
					  finalInterfaceForCompilation, MappingCandidatesForGP,
					  justElementsWithPossibleMappings, GraftInterfaces,
					  IntHeaderGlobalFcts, TransplantResultsLocations,
					  TransplantedSourceFiles, TransplantedHeaderFiles,
					  HostSymbolTableS, SkeletonSourceCodeS, SkeletonLOCsArrayS,
					  ListOfDependenciesForStatementsS, dependencyListForAbstractS,
					  TXLTemporaryFolders, TXLTemporaryFolderMainThread, listOfSourceFiles);

		if (logFolderPath) {
			sprintf(outputFile, "%slog_generation_%d.out", logFolderPath,
					generationNumber);
			printAListOfGPIndividual(listOfInitialPopulation, outputFile);
		}
		generationNumber++;


	}

	if (ALL_TEST_CASE_PASSED) {

		char * checkResults = NULL;
		if (!SUCCESFULL_INDIVIDUAL) {
			//bug... if the individuals are compiled directly in the host, the maximum fitness will be
			//0.7, and succesfull_individual will be null. In this case, add the first individual in
			//the population!
			SUCCESFULL_INDIVIDUAL = listOfInitialPopulation;
		}

		if (SUCCESFULL_INDIVIDUAL) {
			//generate the final version of transplant, for the first individual in population
			//without unneded declarations!!!
			FILE * cleanInterfaceCode = fopen(skeletonInterfaceSourceCodeOutput,
											  "w");
			FILE * cleanInterfaceHeader = fopen(finalInterfaceForCompilation,
												"w");
			fclose(cleanInterfaceCode);
			fclose(cleanInterfaceHeader);

			//temporary interface source code and header, rewritten to original

			printAListOfStrings(
					sourceOutputCoreFunctionalitiesForFinalInstantiation,
					SourceOutputCoreFunctionalities);
			printAListOfStrings(neededFunctionHeaderInitialOutput,
								SkeletonCoreFeatureHeader);

			//TO BE PRESERVED:
			//GraftInterfaceTempOutput
			//SourceOutputCoreFunctionalities
			//
			ListOfString * originalInterfaceHeaderLOCs =
					readListOfStringFromFile(
							interfaceHeaderGlobalsAndGraftFunction);
			printAListOfStrings(originalInterfaceHeaderLOCs,
								finalInterfaceForCompilation);

			char * individualFileName;
			individualFileName = (char *) malloc(500 * sizeof(char));
			sprintf(individualFileName, "%stemp_fitted_individual_LOCS.out",
					TXLTemporaryFolderMainThread);

			printAGPIndividual(listOfInitialPopulation, individualFileName);


			instantiateAnIndividualFromGPIndividual(SkeletonSourceCode,
													graftInterfaceTempOutputForFinalInstantiationFile,
													SourceOutputCoreFunctionalities,
													skeletonInterfaceSourceCodeOutput, SkeletonLOCsArray,
													ListOfDependenciesForStatements,
													ListOfNeededFunctionsForAllLOCs,
													ListOfFinalGlobalDeclarations, GlobalDependencyList,
													SkeletonDependenciesOnGlobals, tempGlobalDeclarations,
													definedGlobalTypesAndVariablesFile, GraftFunctionName,
													finalInterfaceForCompilation, TotalIDsInHostSymbolTable,
													SUCCESFULL_INDIVIDUAL, dependencyListForAbstract,
													GlobalFctDependOutput, TXLTemporaryFolderMainThread);
			double fitness = computeFitnessForSuccesfulIndividual(
					"Individual.x", TotalIDsInHostSymbolTable, 0, 0,
					&checkResults);
			printf("Last Individual Fitness: %f", fitness);
			char * fileOfReducedIndividual = (char *) malloc(
					3000 * sizeof(char));
			sprintf(fileOfReducedIndividual,
					"%sReducedInterfaceWithCoreFeature.c",
					TransplantResultLocation);


#ifdef ORGAN_IMPLANTATION
		//implantationOrgan(skeletonInterfaceSourceCodeOutput, listOfSourceFilesTargetPath, listOfHeaderFilesTargetPath);



        sprintf(stepTime, "Implantation stage..: %s", getTime());
        printf("%s",stepTime);
        addNewString(&execution_log, stepTime);

        implantationOrgan(skeletonInterfaceSourceCodeOutput, listOfSourceFiles, listOfHeaderFiles, inputFileGraft);

        // log_execution
        char * logFolderPath = TransplantLogFolder;
        char * outputFile = (char *) malloc(500 * sizeof(int));
        sprintf(stepTime, "Finishing..: %s", getTime());
        printf("%s",getTime());
        addNewString(&execution_log, stepTime);

        if (logFolderPath) {
            sprintf(outputFile, "%slog_execution.out", logFolderPath);
            printAListOfStrings(execution_log, outputFile);
        }

#endif
			//for the moment disable GI Reduction!!! and adding the feature to H'
#if 0

			reduceCandidate(skeletonInterfaceSourceCodeOutput, fileOfReducedIndividual,TXLTemporaryFolders);
#endif

			fflush(stdout);
		}


        //COPYING NEW MAKEFILE TO HOST POST-OPERATIVE

       /* printf("\tInserting the host file with interface into the host\n");
        char *makefileWithTransplantedFiles = (char *) malloc(5000 * sizeof(char));
        strcpy(makefileWithTransplantedFiles, hostWithInterfaceOutputFile);
        addLocsFromSourceToDestinationWithDirectives(transplantHostInputFile, hostWithInterfacePath, TXLToolsPath);*/
        char * makeFileInHost = (char *) malloc(200 * sizeof(char));
        sprintf(makeFileInHost, "%sMakefile", transplantWorkFolderMainThread);

        if(!file_exists(makeFileInHost)){
            char * removeOutputFile = (char *) malloc(200 * sizeof(char));
            sprintf(removeOutputFile, "rm %s", outputFile);
            int removeCommand = system(removeOutputFile);
            if (removeCommand != 0) {
                printf("ERROR: Trying remove make file!!\n");
                exit(1);
            }
        }
        char *HostProductBase = (char *) malloc(200 * sizeof(char));
        sprintf(HostProductBase, "%s-%s/", HostProject, ProductBase);

        char * commandCopyNewMakeFileToHost = (char *) malloc(2000 * sizeof(char));
        sprintf(commandCopyNewMakeFileToHost, "cp %sMakefile %sMakefile", transplantWorkFolderMainThread, HostProductBase);
        printf("[PRODSCALPEL] Copying new Makefile to Host post-operative directory ...\n");
        int resultCmdCopy = system(commandCopyNewMakeFileToHost);
        if (resultCmdCopy != 0) {
            printf("\tError copying new Makefile to host post-operative!!\n");
            exit(1);
        }

        char *finalSourcePath;
        finalSourcePath = (char *) malloc(200 * sizeof(char));

        /* Run make clean */
        char * commandMakeClean;
        commandMakeClean = (char *) malloc(1000 * sizeof(char));
        sprintf(commandMakeClean, "cd %s \nmake clean %s", HostProductBase, ConsoleStderrOutput);

        int resultCmdMakeClean = system(commandMakeClean);
        if (resultCmdMakeClean != 0) {
            printf("\tCommand Make Clean Failed.\n");
            exit(1);
        }

        printf("\n======================================================\n");
        printf("[PRODSCALPEL] Compiling Host post-operative...\n");
        char * commandMake = (char *) malloc(1000 * sizeof(char));
        sprintf(commandMake, "cd %s \nmake %s", HostProductBase, ConsoleStderrOutput);
        int resultCmdMake = system(commandMake);
        if (resultCmdMake != 0) {
            printf("\tCommand Make Failed. The Host post-operative is not compiling.\n");
            char * openErrorFile = (char *) malloc(1000 * sizeof(char));
            sprintf(openErrorFile, "cd %s \nErrorFile.out", TransplantResultLocation);
            system(openErrorFile);
            exit(1);
        }else
            printf("OK\n");
        printf("======================================================\n");

        //RUNNING POST-OPERATIVE TESTS
        printf("[PRODSCALPEL] Running post-operative tests\n");
        char * commandRunTestCases;
        commandRunTestCases = (char *) malloc(500 * sizeof(char));

        ///sprintf(commandRunTestCases, "cd %s\n ./test.sh", HostProductBase);
        sprintf(commandRunTestCases, "cd %s\n ./test_product_line.sh test_output.txt", HostProductBase);

        int status = system(commandRunTestCases);
        if (status == 0)
            printf("ERROR: POST-OPERATIVE TESTS!!\n");
        else
            printf("ALLTESTCASESPASSED!!!\n");

        if (logFolderPath) {

			sprintf(outputFile, "%sLASTSUCCESFULLGENERATION!!!!.out",
					logFolderPath);
			FILE * ffffff = fopen(outputFile, "w");
			fprintf(ffffff, "SUCCESSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS!!!!!!\n");
			fclose(ffffff);

            //LOS Time registration in Log_execution file


		}


		if (transplant_stats) {
			FILE * statsFile = fopen(StatisticsFile, "w");
			fprintf(statsFile,
					"BUILD: %d \nFUNCTIONALITY_IMPLEMENTED: %d \nTEST_CASES_PERCENTAGE: %4.2f \nNO_GENERATIONS: %d\n",
					BUILD_OR_NOT, IMPLEMENT_FUNCTIONALITY,
					TEST_CASES_PERCENTAGE, generationNumber);
			if (checkResults) {
				fprintf(statsFile, "Results Isolation Test Suite:\n");
				fprintf(statsFile, "%s\n", checkResults);
			}

			fclose(statsFile);
		}

		//exit(0);
	} else {

		char * checkResults = NULL;

		//generate the final version of transplant, for the first individual in population
		//without unneded declarations!!!
		FILE * cleanInterfaceCode = fopen(skeletonInterfaceSourceCodeOutput,
										  "w");
		FILE * cleanInterfaceHeader = fopen(finalInterfaceForCompilation, "w");
		fclose(cleanInterfaceCode);
		fclose(cleanInterfaceHeader);

		//temporary interface source code and header, rewritten to original

		printAListOfStrings(
				sourceOutputCoreFunctionalitiesForFinalInstantiation,
                InterfaceCoreFunctionality);
		printAListOfStrings(neededFunctionHeaderInitialOutput,
							SkeletonCoreFeatureHeader);

		//TO BE PRESERVED:
		//GraftInterfaceTempOutput
		//SourceOutputCoreFunctionalities
		//
		ListOfString * originalInterfaceHeaderLOCs = readListOfStringFromFile(
				interfaceHeaderGlobalsAndGraftFunction);
		printAListOfStrings(originalInterfaceHeaderLOCs,
							finalInterfaceForCompilation);

		char * individualFileName;
		individualFileName = (char *) malloc(500 * sizeof(char));
		sprintf(individualFileName, "%stemp_fitted_individual_LOCS.out",
				TXLTemporaryFolderMainThread);

		//printAGPIndividual(listOfInitialPopulation, individualFileName);

		instantiateAnIndividualFromGPIndividual(SkeletonSourceCode,
												graftInterfaceTempOutputForFinalInstantiationFile,
                                                InterfaceCoreFunctionality,
												skeletonInterfaceSourceCodeOutput, SkeletonLOCsArray,
												ListOfDependenciesForStatements,
												ListOfNeededFunctionsForAllLOCs, ListOfFinalGlobalDeclarations,
												GlobalDependencyList, SkeletonDependenciesOnGlobals,
												tempGlobalDeclarations, definedGlobalTypesAndVariablesFile,
												GraftFunctionName, finalInterfaceForCompilation,
												TotalIDsInHostSymbolTable, listOfInitialPopulation,
												dependencyListForAbstract, GlobalFctDependOutput,
												TXLTemporaryFolderMainThread);
		double fitness = computeFitnessForSuccesfulIndividual("Individual.x",
															  TotalIDsInHostSymbolTable, 0, 0, &checkResults);

		printf("Last Individual Fitness: %f", fitness);
		fflush(stdout);

		TEST_CASES_PERCENTAGE = listOfInitialPopulation->fitness
								- FITNESS_FOR_COMPILE_PERCENTAGE;

		IMPLEMENT_FUNCTIONALITY = TEST_CASES_PERCENTAGE > 0.5 ? 1 : 0;
		BUILD_OR_NOT =
				listOfInitialPopulation->fitness
				> FITNESS_FOR_COMPILE_PERCENTAGE ? 1 : 0;

		// generationNumber

		if (transplant_stats) {
			FILE * statsFile = fopen(StatisticsFile, "w");
			fprintf(statsFile,
					"BUILD: %d \nFUNCTIONALITY_IMPLEMENTED: %d \nTEST_CASES_PERCENTAGE: %4.2f \nNO_GENERATIONS: %d\n",
					BUILD_OR_NOT, IMPLEMENT_FUNCTIONALITY,
					TEST_CASES_PERCENTAGE, generationNumber);

			if (checkResults) {
				fprintf(statsFile, "Results Isolation Test Suite:\n");
				fprintf(statsFile, "%s\n", checkResults);
			}

			fclose(statsFile);
		}

		//	exit(1);
	}
	fflush(stdout);

	//this is the place for GP!!!
	//for loop instantiation for all population, params for instantiateGPCandidateWithExistingGlobalAndCoreFeature
	//are send to GP algorithm

	/*
	 ListOfString * originalInterfaceHeaderLOCs = readListOfStringFromFile(interfaceHeaderGlobalsAndGraftFunction);
	 printAListOfStrings(originalInterfaceHeaderLOCs, finalInterfaceForCompilation);


	 int MappedGraftHostIDs;
	 MappedGraftHostIDs = instantiateGPCandidateWithExistingGlobalAndCoreFeature(SkeletonSourceCode,
	 SkeletonLOCsArray, "/home/---/Desktop/BuggedIndividual", ListOfDependenciesForStatements,
	 GraftInterfaceTempOutput, skeletonInterfaceSourceCodeOutput, finalInterfaceForCompilation);

	 double fitness = computeFitness("Individual.x", TotalIDsInHostSymbolTable, MappedGraftHostIDs);
	 printf("Fitness for individual: %s is : %0.2f\n", "Individual.x", fitness);
	 */

	fflush(stdout);
}

#else
void GPAlgorithm(ListOfString * SkeletonSourceCode,
				 char * GraftInterfaceTempOutput,
				 char * sourceOutputCoreFunctionality,
				 char * InterfaceCoreFunctionality,
				 char * skeletonInterfaceSourceCodeOutput,
				 ArrayOfStrings SkeletonLOCsArray,
				 DependencyList * ListOfDependenciesForStatements,
				 CallDependency * ListOfNeededFunctionsForAllLOCs,
				 GlobalDeclarations ListOfFinalGlobalDeclarations,
				 DependencyList * GlobalDependencyList,
				 DependencyList * SkeletonDependenciesOnGlobals,
				 char * tempGlobalDeclarations,
				 char * definedGlobalTypesAndVariablesFile, char * GraftFunctionName,
				 char * interfaceHeaderGlobalsAndGraftFunction,
				 int TotalIDsInHostSymbolTable,
				 MappingCandidate * MappingCandidatesForGP,
				 DeclarationSymbolTable * GraftSymbolTablePossibleMatching,
				 Mapping * CurrentDonorMappings,
				 DependencyListWithID * dependencyListForAbstract,
				 char * tempDefinesFile, char *tempIncludeLibFile,
				 char * finalInterfaceForCompilation, SymbolTable * HostSymbolTable,
				 char * GlobalFctDependOutput,
				 char * listOfSourceFilesTargetPath,
				 GlobalDeclarations ListOfFinalGlobalDeclarationsMultiFiles,
				 DependencyList * GlobalDependencyListMultiFiles ) {

	fflush(stdout);

#if 0
	printAListOfStrings(SkeletonSourceCode, "skeletoOutputtest.out");
#endif

	//first seed the pseudo number generators

	randomNumbersSeeding();

	//first warm up pseudo generators

#if 0
	FILE * rand1 = fopen("rand1.out", "w");
	FILE * rand2 = fopen("rand2.out", "w");
	FILE * rand3 = fopen("rand3.out", "w");
	FILE * rand4 = fopen("rand4.out", "w");
	FILE * rand5 = fopen("rand5.out", "w");
	FILE * rand6 = fopen("rand6.out", "w");
	FILE * rand7 = fopen("rand7.out", "w");
#endif
	for (int i = 0; i < 2000; i++) {
		unsigned int x = JKISS();
		unsigned int y = JKISSOperation();
		unsigned int z = JKISSAbstractMappings();
		unsigned int a = JKISSCrossoverSelector();
		unsigned int b = JKISSLoclDecl();
		unsigned int c = JKISSPopulationSelection();
		unsigned int d = JKISSStrings();

#if 0
		fprintf(rand1, "%u ", x);
		fprintf(rand2, "%u ", y);
		fprintf(rand3, "%u ", z);
		fprintf(rand4, "%u ", a);
		fprintf(rand5, "%u ", b);
		fprintf(rand6, "%u ", c);
		fprintf(rand7, "%u ", d);
#endif

	}

	ListOfString * TheListOfTransplantedMarkers = createTheListOfAllMarkers(
			SkeletonSourceCode, TXLTemporaryFolderMainThread);

	ListOfString * graftInterfaceTempOutputForFinalInstantiation =
			readListOfStringFromFile(GraftInterfaceTempOutput);
	//NeededSourceCode.c
	ListOfString * sourceOutputCoreFunctionalitiesForFinalInstantiation =
			readListOfStringFromFile(SourceOutputCoreFunctionalities);
	ListOfString * neededFunctionHeaderInitialOutput = readListOfStringFromFile(
			SkeletonCoreFeatureHeader);

	char * graftInterfaceTempOutputForFinalInstantiationFile;
	graftInterfaceTempOutputForFinalInstantiationFile = (char *) malloc(
			1000 * sizeof(char));
	sprintf(graftInterfaceTempOutputForFinalInstantiationFile,
			"%stemp_interface_temp_output_final_instantiation.out",
			TXLTemporaryFolderMainThread);
	printAListOfStrings(graftInterfaceTempOutputForFinalInstantiation,
			graftInterfaceTempOutputForFinalInstantiationFile);

	fflush(stdout);

	//extract also the list of needed globals for the core functions called in the forward call graph!!!
// LOS:TEMP
	/*extractNeededFunctionsAndGlobalDeclarationsForSelectedLOCs(
			InterfaceCoreFunctionality, ListOfNeededFunctionsForAllLOCs,
			ListOfFinalGlobalDeclarations, GlobalDependencyList,
			SkeletonDependenciesOnGlobals, tempGlobalDeclarations,
			definedGlobalTypesAndVariablesFile, SkeletonSourceCode,
			TheListOfTransplantedMarkers, GlobalFctDependOutput,
			TXLTemporaryFolderMainThread);*/

#if 1 /* MULTIFILES */

	char * sourceContentFilesTarget;
	sourceContentFilesTarget = (char *) malloc(500 * sizeof(char));
	sprintf(sourceContentFilesTarget, "%stemp_list_of_source_files_extracted.out", TXLTemporaryMultiFileFolder);

	/* rewrite tempGlobalDeclarations for tempGlobalDeclarationsMultiFiles */
	char * tempGlobalDeclarationsMultiFiles;
	tempGlobalDeclarationsMultiFiles = (char *) malloc(500 * sizeof(char));
	sprintf(tempGlobalDeclarationsMultiFiles, "%stemp_global_variable_declarations",
			TXLTemporaryMultiFileFolder); //LOSTEMP TXLTemporaryFolderMainThread TXLTemporaryMultiFileFolder

	/* rewrite definedGlobalTypesAndVariablesFile for definedGlobalTypesAndVariablesMultiFiles */
	char * definedGlobalTypesAndVariablesMultiFiles;
	definedGlobalTypesAndVariablesMultiFiles = (char *) malloc(500 * sizeof(char));
	sprintf(definedGlobalTypesAndVariablesMultiFiles, "%stemp_global_type_var_declarations.out",
			TXLTemporaryMultiFileFolder);

	char * currentSourceFile;
	currentSourceFile = (char*) malloc(400 * sizeof(char));
	char *line;
	line = (char *) malloc(400 * sizeof(char));
	FILE * fin = fopen(sourceContentFilesTarget, "r");

	char * currentOutputSourcePath;
	currentOutputSourcePath = (char *) malloc(500 * sizeof(char));

	DependencyList * DependencyListGlobalCoreFunctionsMultiFiles = NULL;

	// TODO rewrite this MULTIFILES code, add include core feature header
    // LOS  create new file with include: #include "InterfaceHeader.h" in order to be add in all files
    char * includeCoreFeatureHeader;
	includeCoreFeatureHeader = (char *) malloc(1000 * sizeof(char));
	sprintf(includeCoreFeatureHeader, "#include \"%s\"\n",
			InterfaceHeaderFileName);

	char * headerFileForCoreFeaturePath;
	headerFileForCoreFeaturePath = (char *) malloc(400 * sizeof(char));
	sprintf(headerFileForCoreFeaturePath, "%stemp_interface_header.out", TXLTemporaryMultiFileFolder);
	//printAListOfStrings(includeCoreFeatureHeader, headerFileForCoreFeaturePath);
	FILE * fout = fopen(headerFileForCoreFeaturePath, "w");
	fprintf(fout, "%s", includeCoreFeatureHeader);
	fclose(fout);

	char * listOfHeadFilesTargetPath;
	listOfHeadFilesTargetPath = (char *) malloc(500 * sizeof(char));
	sprintf(listOfHeadFilesTargetPath, "%stemp_list_of_header_files.out", TXLTemporaryMultiFileFolder);

/* LOS: Insert global declaration in each source file extracted */
	while (fgets(line, 400, fin) != NULL) {
		sscanf(line, "%s", currentSourceFile);

		sprintf(currentOutputSourcePath, "%s%s", TXLTemporaryMultiFileFolder, currentSourceFile);

		extractNeededFunctionsAndGlobalDeclarationsForSelectedLOCsInMultiFiles(
				currentOutputSourcePath, ListOfNeededFunctionsForAllLOCs,
				ListOfFinalGlobalDeclarationsMultiFiles, GlobalDependencyListMultiFiles,
				SkeletonDependenciesOnGlobals, tempGlobalDeclarationsMultiFiles,
				definedGlobalTypesAndVariablesMultiFiles, SkeletonSourceCode,
				TheListOfTransplantedMarkers, GlobalFctDependOutput,
				TXLTemporaryMultiFileFolder);

		/* Insert include InterfaceHeade.h */
		addLocsFromSourceToDestination(currentOutputSourcePath,
									   headerFileForCoreFeaturePath, TXLToolsPath);

    }
	fclose(fin);
#endif

#if 0 /* MULTIFILES */

    constructListOfGlobalDeclarationsMultiFiles( TXLTemporaryMultiFileFolder, TXLTemporaryFolderMainThread );
	fflush(stdout);
#endif

	//first, add to the MappingCandidatesForGp the values in current donor source code for mappings
	//try to add the values from the mapping table
	//first check it with random

	//addNewCurrentMappingFromMappings(&MappingCandidatesForGP, CurrentDonorMappings);
	addOneRandomCurrentMappingMappingCandidate(MappingCandidatesForGP);

	fflush(stdout);

	//for the ones that are not in current mappings (ie. entry point arguments), randomly select one from possible
	//or remove it from mapping candidates, since it is not possible to map it if there is not any possible
	//mapping

	MappingCandidate * auxMappingCandidate = MappingCandidatesForGP;

	while (auxMappingCandidate) {
		int signal = 0;
		//just if there is not already a current mapping
		if (!auxMappingCandidate->currentMapping) {
			if (!auxMappingCandidate->possibleMappings) {
				//remove mapping candidate
				//first go to the next element, since the current one will be removed;
				char * auxID = (char *) malloc(500 * sizeof(char));
				strcpy(auxID, auxMappingCandidate->id);

				char * auxType = (char *) malloc(500 * sizeof(char));
				strcpy(auxType, auxMappingCandidate->type);

				auxMappingCandidate = auxMappingCandidate->next;
				removeMappingCandidate(&MappingCandidatesForGP, auxID, auxType);

				free(auxID);
				free(auxType);

				signal = 1;
			} else {
				int lengthPossibleMappings = countElementsInListOfString(
						auxMappingCandidate->possibleMappings);
				int randomIndexPossibleMapping = randomIndexJKISSStrings(
						lengthPossibleMappings, NULL);

				char * selectedMappingString = nthElementInListString(
						auxMappingCandidate->possibleMappings,
						randomIndexPossibleMapping);
				addNewCurrentMapping(&MappingCandidatesForGP,
						auxMappingCandidate->id, selectedMappingString);
			}
		}
		if (!signal) {
			auxMappingCandidate = auxMappingCandidate->next;
		}
	}

	//length of Mapping Candidates
	int lengthOfMappingCandidate = countElementsInListOfMappingCandidate(
			MappingCandidatesForGP);

	addLocsFromSourceToDestination(interfaceHeaderGlobalsAndGraftFunction,
			tempDefinesFile, TXLToolsPath);
	addLocsFromSourceToDestination(interfaceHeaderGlobalsAndGraftFunction,
			tempIncludeLibFile, TXLToolsPath);

	DeclarationSymbolTable * justElementsWithPossibleMappings =
			returnNewDeclSymbolTableJustForElementsWithPossibleMappings(
					GraftSymbolTablePossibleMatching);
#if 0
	printDeclarationSymbolTable("/home/---/Development/TEST_ST.out", justElementsWithPossibleMappings);
	printAMappingCandidateList("/home/---/Development/mapCand.out", MappingCandidatesForGP);
	FILE * testFout  = fopen("/home/---/Development/locsArray.out", "w");
	for(int i = 0; i < SkeletonLOCsArray.count; i++){
		fprintf(testFout,"%s\n",SkeletonLOCsArray.array[i]);
	}
	fclose(testFout);

#endif

	addOneRandomCurrentMappingDeclarationSymbolTable(
			justElementsWithPossibleMappings);
	//initially add current marker at all of them!!
	//addCurrentMarkerDeclarationSymbolTable(justElementsWithPossibleMappings);

	int lengthOfDeclarationMappings = countElementsInDeclarationSymbolTable(
			justElementsWithPossibleMappings);

	/*
	 ArrayOfMappingCandidates testArrayMapping = returnListOfCandidatesWithMoreThanOnePossibleMappingPointers(MappingCandidatesForGP);
	 testArrayMapping.array[0]->currentMapping = NULL;
	 testArrayMapping.array[0]->possibleMappings = NULL;
	 */



	printf("GENERATION NUMBER: 0 =================================\n");

	GPIndividual * listOfInitialPopulation = generateInitialPopulation(
			MappingCandidatesForGP, justElementsWithPossibleMappings,
			lengthOfMappingCandidate, lengthOfDeclarationMappings,
			SkeletonSourceCode, SkeletonLOCsArray, GraftInterfaceTempOutput,
			interfaceHeaderGlobalsAndGraftFunction, TotalIDsInHostSymbolTable,
			ListOfDependenciesForStatements, skeletonInterfaceSourceCodeOutput,
			dependencyListForAbstract, finalInterfaceForCompilation,
			HostSymbolTable, TXLTemporaryFolderMainThread, listOfSourceFilesTargetPath);

	sortPopulationByFitness(&listOfInitialPopulation);

	char * logFolderPath = TransplantLogFolder;
	char * outputFile = (char *) malloc(500 * sizeof(int));

	//clean LOG folder, if there is a LOG folder
	if (logFolderPath) {
		char * commandCleanFolder;
		commandCleanFolder = (char *) malloc(1000 * sizeof(char));
		sprintf(commandCleanFolder, "cd %s \n rm *.*", logFolderPath);
		int x = system(commandCleanFolder);
		if (x) {
			printf("ERROR CLEEAN FOLDER!\n");
			printf("%s\n", commandCleanFolder);
		}

		sprintf(outputFile, "%slog_generation_initialPopulation.out",
				logFolderPath);
		printAListOfGPIndividual(listOfInitialPopulation, outputFile);
	}

	int generationNumber = 1;

	// First prepare for multithreading, so just copy all the transplant working folder

	char * GraftInterfaces[NO_THREADS];
	char * IntHeaderGlobalFcts[NO_THREADS];
	char * TransplantResultsLocations[NO_THREADS];
	char * TransplantedSourceFiles[NO_THREADS];
	char * TransplantedHeaderFiles[NO_THREADS];
	SymbolTable * HostSymbolTableS[NO_THREADS];
	ListOfString * SkeletonSourceCodeS[NO_THREADS];
	ArrayOfStrings SkeletonLOCsArrayS[NO_THREADS];
	DependencyList * ListOfDependenciesForStatementsS[NO_THREADS];
	DependencyListWithID * dependencyListForAbstractS[NO_THREADS];
	char * TXLTemporaryFolders[NO_THREADS];

	char * transplantResultLocationNoSlash = (char *) malloc(
			strlen(TransplantResultLocation) + 1 * sizeof(char));
	strcpy(transplantResultLocationNoSlash, TransplantResultLocation);
	transplantResultLocationNoSlash[strlen(transplantResultLocationNoSlash) - 1] =
			0;

	char * transplantWorkFolderNoSlash = (char *) malloc(
			strlen(transplantWorkFolderMainThread) + 1 * sizeof(char));
	strcpy(transplantWorkFolderNoSlash, transplantWorkFolderMainThread);
	transplantWorkFolderNoSlash[strlen(transplantWorkFolderNoSlash) - 1] = 0;

	for (int i = 0; i < NO_THREADS; i++) {
		char * commandCp = (char *) malloc(2000 * sizeof(char));
		sprintf(commandCp,
				"cp -r %s %s-%d && cp %s %s-%d/graftIntTempOut.out && cp %s %s-%d/interfaceHeaderGlobalAndGraft.out && cp -r %s %s/TEMP-%d",
				TransplantResultLocation, transplantResultLocationNoSlash, i,
				GraftInterfaceTempOutput, transplantResultLocationNoSlash, i,
				interfaceHeaderGlobalsAndGraftFunction,
				transplantResultLocationNoSlash, i,
				TXLTemporaryFolderMainThread, transplantWorkFolderNoSlash, i);
		int statusCp = system(commandCp);
		if (statusCp != 0) {
			printf("ERROR! copy for multithread");
			fflush(stdout);
		}

		TransplantResultsLocations[i] = (char *) malloc(1000 * sizeof(char));
		sprintf(TransplantResultsLocations[i], "%s-%d/",
				transplantResultLocationNoSlash, i);
		GraftInterfaces[i] = (char *) malloc(1000 * sizeof(char));
		sprintf(GraftInterfaces[i], "%s-%d/graftIntTempOut.out",
				transplantResultLocationNoSlash, i);
		IntHeaderGlobalFcts[i] = (char *) malloc(1000 * sizeof(char));
		sprintf(IntHeaderGlobalFcts[i],
				"%s-%d/interfaceHeaderGlobalAndGraft.out",
				transplantResultLocationNoSlash, i);
		TransplantedSourceFiles[i] = (char *) malloc(1000 * sizeof(char));
		sprintf(TransplantedSourceFiles[i], "%s-%d/InterfaceWithCoreFeature.c",
				transplantResultLocationNoSlash, i);
		TransplantedHeaderFiles[i] = (char *) malloc(1000 * sizeof(char));
		sprintf(TransplantedHeaderFiles[i], "%s-%d/InterfaceHeader.h",
				transplantResultLocationNoSlash, i);

		TXLTemporaryFolders[i] = (char *) malloc(1000 * sizeof(char));
		sprintf(TXLTemporaryFolders[i], "%s/TEMP-%d/",
				transplantWorkFolderNoSlash, i);

		HostSymbolTableS[i] = copySymbolTableList(HostSymbolTable);
		SkeletonSourceCodeS[i] = copyCompleteListOfString(SkeletonSourceCode);
		SkeletonLOCsArrayS[i] = copyArrayOfStrings(SkeletonLOCsArray);
		ListOfDependenciesForStatementsS[i] = copyDependencyList(
				ListOfDependenciesForStatements);
		dependencyListForAbstractS[i] = copyDependencyListWithID(
				dependencyListForAbstract);

		free(commandCp);
	}

	while (generationNumber <= NUMBER_OF_GENERATIONS && !ALL_TEST_CASE_PASSED) {

		printf("GENERATION NUMBER: %d  =================================\n", generationNumber);

		newGeneration(&listOfInitialPopulation, SkeletonLOCsArray,
				lengthOfMappingCandidate, HostSymbolTable, SkeletonSourceCode,
				GraftInterfaceTempOutput,
				interfaceHeaderGlobalsAndGraftFunction,
				TotalIDsInHostSymbolTable, ListOfDependenciesForStatements,
				skeletonInterfaceSourceCodeOutput, dependencyListForAbstract,
				finalInterfaceForCompilation, MappingCandidatesForGP,
				justElementsWithPossibleMappings, GraftInterfaces,
				IntHeaderGlobalFcts, TransplantResultsLocations,
				TransplantedSourceFiles, TransplantedHeaderFiles,
				HostSymbolTableS, SkeletonSourceCodeS, SkeletonLOCsArrayS,
				ListOfDependenciesForStatementsS, dependencyListForAbstractS,
				TXLTemporaryFolders, TXLTemporaryFolderMainThread, listOfSourceFilesTargetPath);

		if (logFolderPath) {
			sprintf(outputFile, "%slog_generation_%d.out", logFolderPath,
					generationNumber);
			printAListOfGPIndividual(listOfInitialPopulation, outputFile);
		}
		generationNumber++;
	}

	if (ALL_TEST_CASE_PASSED) {

		char * checkResults = NULL;
		if (!SUCCESFULL_INDIVIDUAL) {
			//bug... if the individuals are compiled directly in the host, the maximum fitness will be
			//0.7, and succesfull_individual will be null. In this case, add the first individual in
			//the population!
			SUCCESFULL_INDIVIDUAL = listOfInitialPopulation;
		}

		if (SUCCESFULL_INDIVIDUAL) {
			//generate the final version of transplant, for the first individual in population
			//without unneded declarations!!!
			FILE * cleanInterfaceCode = fopen(skeletonInterfaceSourceCodeOutput,
					"w");
			FILE * cleanInterfaceHeader = fopen(finalInterfaceForCompilation,
					"w");
			fclose(cleanInterfaceCode);
			fclose(cleanInterfaceHeader);

			//temporary interface source code and header, rewritten to original

			printAListOfStrings(
					sourceOutputCoreFunctionalitiesForFinalInstantiation,
					SourceOutputCoreFunctionalities);
			printAListOfStrings(neededFunctionHeaderInitialOutput,
					SkeletonCoreFeatureHeader);

			//TO BE PRESERVED:
			//GraftInterfaceTempOutput
			//SourceOutputCoreFunctionalities
			//
			ListOfString * originalInterfaceHeaderLOCs =
					readListOfStringFromFile(
							interfaceHeaderGlobalsAndGraftFunction);
			printAListOfStrings(originalInterfaceHeaderLOCs,
					finalInterfaceForCompilation);

			char * individualFileName;
			individualFileName = (char *) malloc(500 * sizeof(char));
			sprintf(individualFileName, "%stemp_fitted_individual_LOCS.out",
					TXLTemporaryFolderMainThread);

			printAGPIndividual(listOfInitialPopulation, individualFileName);

			instantiateAnIndividualFromGPIndividual(SkeletonSourceCode,
					graftInterfaceTempOutputForFinalInstantiationFile,
					SourceOutputCoreFunctionalities,
					skeletonInterfaceSourceCodeOutput, SkeletonLOCsArray,
					ListOfDependenciesForStatements,
					ListOfNeededFunctionsForAllLOCs,
					ListOfFinalGlobalDeclarations, GlobalDependencyList,
					SkeletonDependenciesOnGlobals, tempGlobalDeclarations,
					definedGlobalTypesAndVariablesFile, GraftFunctionName,
					finalInterfaceForCompilation, TotalIDsInHostSymbolTable,
					SUCCESFULL_INDIVIDUAL, dependencyListForAbstract,
					GlobalFctDependOutput, TXLTemporaryFolderMainThread);
			double fitness = computeFitnessForSuccesfulIndividual(
					"Individual.x", TotalIDsInHostSymbolTable, 0, 0,
					&checkResults);
			printf("Last Individual Fitness: %f", fitness);

			char * fileOfReducedIndividual = (char *) malloc(
					3000 * sizeof(char));
			sprintf(fileOfReducedIndividual,
					"%sReducedInterfaceWithCoreFeature.c",
					TransplantResultLocation);

			//for the moment disable GI Reduction!!! and adding the feature to H'
#if 0

			reduceCandidate(skeletonInterfaceSourceCodeOutput,
					fileOfReducedIndividual);
#endif

#if 1
			//copy the files into host at the host target file location and
			//rewrite the host target file
            // LOS
		/*	char * copyOriginalHost = (char *) malloc(1000 * sizeof(char));
			sprintf(copyOriginalHost, "cp -r %s %s_ORIGINAL", HostProject,
					HostProject);
			system(copyOriginalHost);
*/

			char* tempDir = strdup(transplantHostInputFile);
			char* dir = dirname(tempDir);

			char * commandCopyInterface = (char *) malloc(5000 * sizeof(char));
			sprintf(commandCopyInterface, "cp %s %s/%s",
					skeletonInterfaceSourceCodeOutput, dir,
					InterfaceWithCoreFeatureFileName);



/*
			char * commandCopyHeader = (char *) malloc(5000 * sizeof(char));
			sprintf(commandCopyHeader, "cp %s%s %s/%s", TransplantResultLocation,
					InterfaceHeaderFileName, dir,InterfaceHeaderFileName);
*/
            char * commandCopyHeader = (char *) malloc(5000 * sizeof(char));
            sprintf(commandCopyHeader, "cp %s%s %s", TransplantResultLocation,
                    InterfaceHeaderFileName, dir);

            char * commandRewriteHost = (char *) malloc(5000 * sizeof(char));
            sprintf(commandRewriteHost, "cp %s %s", hostWithInterfaceOutputFile,
                    transplantHostInputFile);



			system(commandRewriteHost);
			system(commandCopyInterface);
			system(commandCopyHeader);

#if 1 /* MULTIFILES */
			char * sourceFilesExtractedPath = (char *) malloc(3000 * sizeof(char));
			sprintf(sourceFilesExtractedPath, "%stemp_list_of_source_files_extracted.out",
					TXLTemporaryMultiFileFolder);
			FILE * fSourceFilesExtracted = fopen(sourceFilesExtractedPath, "r");

			char *line;
			line = (char *) malloc(400 * sizeof(char));

			char * currentSourceFile = (char *) malloc(1000 * sizeof(char));
			char * commandCopySourceFiles  = (char *) malloc(5000 * sizeof(char));


			while (fgets(line, 400, fSourceFilesExtracted) != NULL) {
					sscanf(line, "%s", currentSourceFile);

				sprintf(commandCopySourceFiles, "cp %s%s %s", TransplantResultLocation, currentSourceFile, dir);
				system(commandCopySourceFiles);

			}
			fclose(fSourceFilesExtracted);
#endif



           /* char * removeOldBeneficiary = (char *) malloc(1000 * sizeof(char));
            sprintf(removeOldBeneficiary, "rm -r -f %s_BENEFICIARY/",
                    HostProject);
            system(removeOldBeneficiary);*/

     /*       char * moveBeneficiary = (char *) malloc(1000 * sizeof(char));
            sprintf(moveBeneficiary, "mv %s %s_BENEFICIARY/", HostProject,
                    HostProject);
            system(moveBeneficiary);

            char * moveOriginal = (char *) malloc(1000 * sizeof(char));
            sprintf(moveOriginal, "mv %s_ORIGINAL %s", HostProject,
                    HostProject);
            system(moveOriginal);
*/
			char * renameInterface = (char *) malloc(1000 * sizeof(char));
			sprintf(renameInterface, "mv %s/%s  %s/%s_%s", HostProject, InterfaceWithCoreFeatureFileName,HostProject, GraftFunctionName, InterfaceWithCoreFeatureFileName);
			system(renameInterface);
			/*
					dir,
					InterfaceWithCoreFeatureFileName, dir, GraftFunctionName,
					InterfaceWithCoreFeatureFileName);
			system(renameInterface);

		/*	char* featureResultDirectory = (char *) malloc(1000 * sizeof(char));
			sprintf(featureResultDirectory, "mkdir MYTAR-PIDGIN/FEATURE_%s",GraftFunctionName);

			// LOS
			char * commandCopyCoreFeature = (char *) malloc(5000 * sizeof(char));
			sprintf(commandCopyCoreFeature, "cp %s %s", skeletonInterfaceSourceCodeOutput, featureResultDirectory);

			char * commandCopyHeaderFeature = (char *) malloc(5000 * sizeof(char));
			sprintf(commandCopyHeader, "cp %s%s %s", TransplantResultLocation,
					InterfaceHeaderFileName, featureResultDirectory);

			system(featureResultDirectory); */
			//system(commandCopyCoreFeature);
		//	system(commandCopyHeaderFeature);

			/*char * commandCopyInterface = (char *) malloc(1000 * sizeof(char));
			sprintf(commandCopyInterface, "mv %s %s_%s/", HostProject,
					HostProject, GraftFunctionName);

			system(commandRewriteHost);
/*
			char * commandCopyHeader = (char *) malloc(5000 * sizeof(char));
			sprintf(commandCopyHeader, "cp %s%s %s", TransplantResultLocation,
					GraftFunctionName, dir);

*/
/*			char * commandRewriteHost = (char *) malloc(5000 * sizeof(char));
			sprintf(commandRewriteHost, "cp %s %s", hostWithInterfaceOutputFile,
					transplantHostInputFile);

			system(commandRewriteHost); */
			//system(commandCopyInterface);
		//	system(commandCopyHeader);


			// LOS: GENERATE A BENEFICIARY
		/*	char * removeOldBeneficiary = (char *) malloc(1000 * sizeof(char));
			sprintf(removeOldBeneficiary, "rm -r -f %s_BENEFICIARY/",
					HostProject);
			system(removeOldBeneficiary);

			char * moveBeneficiary = (char *) malloc(1000 * sizeof(char));
			sprintf(moveBeneficiary, "mv %s %s_%s/", HostProject,
					HostProject, GraftFunctionName);
			system(moveBeneficiary);

			char * moveOriginal = (char *) malloc(1000 * sizeof(char));
			sprintf(moveOriginal, "mv %s_ORIGINAL %s", HostProject,
					HostProject);
			system(moveOriginal); */

#endif

			fflush(stdout);
		}

		printf("ALLTESTCASESPASSED!!!\n");
		if (logFolderPath) {
			sprintf(outputFile, "%sLASTSUCCESFULLGENERATION!!!!.out",
					logFolderPath);
			FILE * ffffff = fopen(outputFile, "w");
			fprintf(ffffff, "SUCCESSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS!!!!!!\n");
			fclose(ffffff);
		}


		if (transplant_stats) {
			FILE * statsFile = fopen(StatisticsFile, "w");
			fprintf(statsFile,
					"BUILD: %d \nFUNCTIONALITY_IMPLEMENTED: %d \nTEST_CASES_PERCENTAGE: %4.2f \nNO_GENERATIONS: %d\n",
					BUILD_OR_NOT, IMPLEMENT_FUNCTIONALITY,
					TEST_CASES_PERCENTAGE, generationNumber);
			if (checkResults) {
				fprintf(statsFile, "Results Isolation Test Suite:\n");
				fprintf(statsFile, "%s\n", checkResults);
			}

			fclose(statsFile);
		}

		//exit(0);
	} else {

		char * checkResults = NULL;

		//generate the final version of transplant, for the first individual in population
		//without unneded declarations!!!
		FILE * cleanInterfaceCode = fopen(skeletonInterfaceSourceCodeOutput,
				"w");
		FILE * cleanInterfaceHeader = fopen(finalInterfaceForCompilation, "w");
		fclose(cleanInterfaceCode);
		fclose(cleanInterfaceHeader);

		//temporary interface source code and header, rewritten to original

		printAListOfStrings(
				sourceOutputCoreFunctionalitiesForFinalInstantiation,
				SourceOutputCoreFunctionalities);
		printAListOfStrings(neededFunctionHeaderInitialOutput,
				SkeletonCoreFeatureHeader);

		//TO BE PRESERVED:
		//GraftInterfaceTempOutput
		//SourceOutputCoreFunctionalities
		//
		ListOfString * originalInterfaceHeaderLOCs = readListOfStringFromFile(
				interfaceHeaderGlobalsAndGraftFunction);
		printAListOfStrings(originalInterfaceHeaderLOCs,
				finalInterfaceForCompilation);

		char * individualFileName;
		individualFileName = (char *) malloc(500 * sizeof(char));
		sprintf(individualFileName, "%stemp_fitted_individual_LOCS.out",
				TXLTemporaryFolderMainThread);

		//printAGPIndividual(listOfInitialPopulation, individualFileName);

		instantiateAnIndividualFromGPIndividual(SkeletonSourceCode,
				graftInterfaceTempOutputForFinalInstantiationFile,
				SourceOutputCoreFunctionalities,
				skeletonInterfaceSourceCodeOutput, SkeletonLOCsArray,
				ListOfDependenciesForStatements,
				ListOfNeededFunctionsForAllLOCs, ListOfFinalGlobalDeclarations,
				GlobalDependencyList, SkeletonDependenciesOnGlobals,
				tempGlobalDeclarations, definedGlobalTypesAndVariablesFile,
				GraftFunctionName, finalInterfaceForCompilation,
				TotalIDsInHostSymbolTable, listOfInitialPopulation,
				dependencyListForAbstract, GlobalFctDependOutput,
				TXLTemporaryFolderMainThread);
		double fitness = computeFitnessForSuccesfulIndividual("Individual.x",
				TotalIDsInHostSymbolTable, 0, 0, &checkResults);

		printf("Last Individual Fitness: %f", fitness);
		fflush(stdout);

		TEST_CASES_PERCENTAGE = listOfInitialPopulation->fitness
				- FITNESS_FOR_COMPILE_PERCENTAGE;

		IMPLEMENT_FUNCTIONALITY = TEST_CASES_PERCENTAGE > 0.5 ? 1 : 0;
		BUILD_OR_NOT =
				listOfInitialPopulation->fitness
						> FITNESS_FOR_COMPILE_PERCENTAGE ? 1 : 0;

		// generationNumber

		if (transplant_stats) {
			FILE * statsFile = fopen(StatisticsFile, "w");
			fprintf(statsFile,
					"BUILD: %d \nFUNCTIONALITY_IMPLEMENTED: %d \nTEST_CASES_PERCENTAGE: %4.2f \nNO_GENERATIONS: %d\n",
					BUILD_OR_NOT, IMPLEMENT_FUNCTIONALITY,
					TEST_CASES_PERCENTAGE, generationNumber);

			if (checkResults) {
				fprintf(statsFile, "Results Isolation Test Suite:\n");
				fprintf(statsFile, "%s\n", checkResults);
			}

			fclose(statsFile);
		}

	//	exit(1);
	}
	fflush(stdout);

	//this is the place for GP!!!
	//for loop instantiation for all population, params for instantiateGPCandidateWithExistingGlobalAndCoreFeature
	//are send to GP algorithm

	/*
	 ListOfString * originalInterfaceHeaderLOCs = readListOfStringFromFile(interfaceHeaderGlobalsAndGraftFunction);
	 printAListOfStrings(originalInterfaceHeaderLOCs, finalInterfaceForCompilation);


	 int MappedGraftHostIDs;
	 MappedGraftHostIDs = instantiateGPCandidateWithExistingGlobalAndCoreFeature(SkeletonSourceCode,
	 SkeletonLOCsArray, "/home/---/Desktop/BuggedIndividual", ListOfDependenciesForStatements,
	 GraftInterfaceTempOutput, skeletonInterfaceSourceCodeOutput, finalInterfaceForCompilation);

	 double fitness = computeFitness("Individual.x", TotalIDsInHostSymbolTable, MappedGraftHostIDs);
	 printf("Fitness for individual: %s is : %0.2f\n", "Individual.x", fitness);
	 */

	fflush(stdout);
}

#endif

/*
void organImplantation(char * graftSourceCodeFile){

	printf("[PRODSCALPEL] Clone Analyse\n");

	sprintf(TempImplantationDirectory, "%sTempImplantationDirectory/", transplantWorkFolderMainThread);
	isDirectory(TempImplantationDirectory);

	/* Get list of functions in the host -----------------------------------------------------------------------------
	char *allSourceFilesInHost;
	allSourceFilesInHost = (char *) malloc(500 * sizeof(char));
	sprintf(allSourceFilesInHost, "%sallSouceFileInHost.out", TempImplantationDirectory);
	char *tempDir = strdup(transplantHostInputFile);
	char *dirHost = dirname(tempDir);
	strcat(dirHost, "/");

	char * outputAllDefinedFunctionsInHost;
	outputAllDefinedFunctionsInHost = (char *) malloc(1000 * sizeof(char));
	sprintf(outputAllDefinedFunctionsInHost,
			"%stemp_all_defined_functions_int_host.out",
			TempImplantationDirectory);

	FILE *fSourceFileName = fopen(allSourceFilesInHost, "w");
	readFilesFromDir(dirHost, fSourceFileName, 'c');
	readFilesFromDir(dirHost, fSourceFileName, 'h');
	fclose(fSourceFileName);// LOS: write lista with sourcefiles.c full path existing in donor file

	createListOfHostFunctions(TXLToolsPath, allSourceFilesInHost, outputAllDefinedFunctionsInHost);

	ListOfFunctionSourceFile * listOfFunctionsInHost = readFunctionsFilesFromFile(outputAllDefinedFunctionsInHost);

	/* Remove path from source file name
	replaceSourceFilePahtByFileName(&listOfFunctionsInHost, dirHost);

	/* Read list of functions in organ -------------------------------------------------------------------------------
	char *listOfFunctionsFilesTargetFormatedPath = NULL;
	listOfFunctionsFilesTargetFormatedPath = (char *) malloc(500 * sizeof(char));
	sprintf(listOfFunctionsFilesTargetFormatedPath, "%slist_of_functions_file_target.out", TXLTemporaryMultiFileFolder);

	ListOfFunctionSourceFile * listOfFunctionsInOrgan = readFunctionsFilesFromFile(listOfFunctionsFilesTargetFormatedPath);
	/* Remove path from source file name
	replaceSourceFilePahtByFileName(&listOfFunctionsInOrgan, donorSourceFileFolder);

	ListOfFunctionSourceFile * ListOfDuplicatedFunctions = searchFunctionDuplication(listOfFunctionsInOrgan, listOfFunctionsInHost);

	ListOfFunctionSourceFile * auxListOfDuplicatedFunctions  = ListOfDuplicatedFunctions;

	char *formattedCurrentFunction;
	formattedCurrentFunction = (char *) malloc(500 * sizeof(char));
	while(auxListOfDuplicatedFunctions) {

		/* Create outputOrganAST.c to organ functions declaration
		char * sourceOutputFileForOrgan;
		sourceOutputFileForOrgan = (char *) malloc(500 * sizeof (char));
		sprintf(sourceOutputFileForOrgan, "%sOrganAST.c", TempImplantationDirectory);
		createFile(sourceOutputFileForOrgan);

		/* Create sourcContentFileAST for AST Generation

		//sprintf(formattedCurrentFunction, "\"%s\" \"%s%s\"\n", currentFct, donorSourceFiles, line2);
		sprintf(formattedCurrentFunction, "\"%s\" \"%s%s\"\n", auxListOfDuplicatedFunctions->functionName,
				donorSourceFileFolder, auxListOfDuplicatedFunctions->sourceFile);
		extractASTFromFunctions(formattedCurrentFunction, donorSourceFileFolder,TXLToolsPath, graftSourceCodeFile, sourceOutputFileForOrgan);

		/* Create outputHostAST.c to host functions declaration
		char * sourceOutputFileForHost;
		sourceOutputFileForHost = (char *) malloc(500 * sizeof (char));
		sprintf(sourceOutputFileForHost, "%sHostAST.c", TempImplantationDirectory);
		createFile(sourceOutputFileForHost);

		/* Create sourcContentFileAST for AST Generation
		sprintf(formattedCurrentFunction, "\"%s\" \"%s%s\"\n", auxListOfDuplicatedFunctions->functionName,
				dirHost, auxListOfDuplicatedFunctions->sourceFile);

		char * formattedSourceFileForHost = NULL;
		formattedSourceFileForHost = (char *) malloc((strlen(TempImplantationDirectory) + strlen(auxListOfDuplicatedFunctions->sourceFile) + 10) * sizeof (char *));
		sprintf(formattedSourceFileForHost, "%s%s", TempImplantationDirectory, auxListOfDuplicatedFunctions->sourceFile);

		extractASTFromFunctions(formattedCurrentFunction, dirHost, TXLToolsPath, graftSourceCodeFile, sourceOutputFileForHost);

		//cloneAnalyse(sourceOutputFileForOrgan, auxListOfFunctionsWithNameCollision->sourceFile);

		auxListOfDuplicatedFunctions = auxListOfDuplicatedFunctions->next;

		printf("----------------------------------------------------------\n");
	}


 }*/
/*
void cloneAnalyse(SourceFileElementsList *  ListOfAllFunctionsFromFileInHost, SourceFileElementsList * listOfElementsToBeTransplantedBySourceFile, SourceFileElementsList * listOfElementsBySourceFile, char * dirHost, char * graftSourceCodeFile,
				  char * outputFileToTheHostDirectory, char * formattedCurrentFileToTheTempImplantationDirectory){

	char *currentSourceFile = NULL;
	currentSourceFile = (char *) malloc(1000 * sizeof(char));
	strcpy(currentSourceFile, listOfElementsToBeTransplantedBySourceFile->sourceFile);
	ListOfString * ListOfFunctionsToBeTransplanted = listOfElementsToBeTransplantedBySourceFile->functions;
	ListOfString * ListOfDuplicatedFunctions = listOfElementsBySourceFile->functions;
	ListOfString * ListOfAllFunctionsFromCurrentFileInHost = ListOfAllFunctionsFromFileInHost->functions;

	char *formattedCurrentFunction;
	formattedCurrentFunction = (char *) malloc(500 * sizeof(char));

	/* Create outputOrganAST.c to organ functions declaration ---------------------------------------------------------
	char * sourceOutputFileForOrgan;
	sourceOutputFileForOrgan = (char *) malloc(500 * sizeof (char));
	sprintf(sourceOutputFileForOrgan, "%sOrganAST.c", TempImplantationDirectory);

	/* Create outputHostAST.c to host functions declaration -----------------------------------------------------------
	char * sourceOutputFileForHost;
	sourceOutputFileForHost = (char *) malloc(500 * sizeof (char));
	sprintf(sourceOutputFileForHost, "%sHostAST.c", TempImplantationDirectory);

	char *currentFunction = NULL;
	currentFunction = (char *) malloc(1000 * sizeof(char));

	char * mergeResultFile;
	mergeResultFile = (char *) malloc(500 * sizeof (char));
	sprintf(mergeResultFile, "%smergeResultFile.c", TempImplantationDirectory);

	int countFct = 1;
	while(ListOfFunctionsToBeTransplanted) {

		strcpy(currentFunction,readSubstring("\"", ListOfFunctionsToBeTransplanted->el, "\""));
		printf("\t\t\t----------------------------------------------------------\n");
		printf("\t\t\tFunction[%d]: %s\n",countFct, currentFunction);

		if (searchStringInListOfStrings(ListOfDuplicatedFunctions, currentFunction)) {
			/* Create sourcContentFileAST for AST Generation --------------------------------------------------------------
			printf("\t\t\tGenerating Abstract Source Trees for ...\n");
			sprintf(formattedCurrentFunction, "\"%s\" \"%s%s\"\n", currentFunction, TransplantResultLocation,
					currentSourceFile);
			extractASTFromFunctions(formattedCurrentFunction, donorSourceFileFolder, TXLToolsPath,
									graftSourceCodeFile,
									sourceOutputFileForOrgan);

			/* Create sourcContentFileAST for AST Generation
			sprintf(formattedCurrentFunction, "\"%s\" \"%s%s\"\n", currentFunction, dirHost, currentSourceFile);
			extractASTFromFunctions(formattedCurrentFunction, dirHost, TXLToolsPath, graftSourceCodeFile,
									sourceOutputFileForHost);

			if (ASTIsEqual(sourceOutputFileForOrgan, sourceOutputFileForHost)) {
				printf("\t\t\tNaming collision detected!\n");
				mergeElements(mergeResultFile, sourceOutputFileForOrgan, sourceOutputFileForHost, "F_WRITE");
				printf("\t\t\tReplacing Function...\n");
				/* Replace function ---------------------------------------------------------------------------------------
				removeLocsFromSourceFile(formattedCurrentFileToTheTempImplantationDirectory,
										 sourceOutputFileForHost,
										 TXLToolsPath);
				addLocsFromSourceToDestination(formattedCurrentFileToTheTempImplantationDirectory, mergeResultFile,
											   TXLToolsPath);
			} else {
				printf("\t\t\tDuplication detected. Keeping function in the host file.\n");
			}

		} else {
			/* Insert new function ---------------------------------------------------------------------------------------
			printf("\t\t\tInserting function in the host environment...\n");
			sprintf(formattedCurrentFunction, "\"%s\" \"%s%s\"\n", currentFunction, donorSourceFileFolder,
					currentSourceFile);
			extractASTFromFunctions(formattedCurrentFunction, donorSourceFileFolder, TXLToolsPath,
									graftSourceCodeFile, sourceOutputFileForOrgan);
			addLocsFromSourceToDestination(formattedCurrentFileToTheTempImplantationDirectory,
										   sourceOutputFileForOrgan, TXLToolsPath);
		}
		//cloneAnalyse(sourceOutputFileForOrgan, auxListOfFunctionsWithNameCollision->sourceFile);

		ListOfFunctionsToBeTransplanted = ListOfFunctionsToBeTransplanted->next;
		countFct++;
		if(ListOfFunctionsToBeTransplanted == NULL)
			printf("----------------------------------------------------------------\n");
	}

}*/

