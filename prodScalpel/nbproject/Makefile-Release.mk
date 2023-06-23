#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/DeclarationSymbolTable.o \
	${OBJECTDIR}/DeclarationWithHeaderDefinition.o \
	${OBJECTDIR}/DependencyList.o \
	${OBJECTDIR}/DependencyListWithID.o \
	${OBJECTDIR}/FeatureInterface.o \
	${OBJECTDIR}/FunctionCallDependency.o \
	${OBJECTDIR}/FunctionElement.o \
	${OBJECTDIR}/GIReduction.o \
	${OBJECTDIR}/GP.o \
	${OBJECTDIR}/GPIndividual.o \
	${OBJECTDIR}/GlobalDeclarations.o \
	${OBJECTDIR}/IndividualInstantiator.o \
	${OBJECTDIR}/ListOfFunctionSourceFile.o \
	${OBJECTDIR}/ListOfInt.o \
	${OBJECTDIR}/ListOfString.o \
	${OBJECTDIR}/MappingCandidate.o \
	${OBJECTDIR}/Mappping.o \
	${OBJECTDIR}/MarkFunctionCall.o \
	${OBJECTDIR}/OptionParser.o \
	${OBJECTDIR}/PrepareForGP.o \
	${OBJECTDIR}/ReductionIndividual.o \
	${OBJECTDIR}/Skeleton.o \
	${OBJECTDIR}/SkeletonMapping.o \
	${OBJECTDIR}/SymbolTable.o \
	${OBJECTDIR}/Utils.o \
	${OBJECTDIR}/coreFunctionExtractor.o \
	${OBJECTDIR}/folderContent.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/reverseCallGraph.o


# C Compiler Flags
CFLAGS=-std=gnu99 -pthread

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gentrans

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gentrans: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gentrans ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/DeclarationSymbolTable.o: DeclarationSymbolTable.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DeclarationSymbolTable.o DeclarationSymbolTable.c

${OBJECTDIR}/DeclarationWithHeaderDefinition.o: DeclarationWithHeaderDefinition.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DeclarationWithHeaderDefinition.o DeclarationWithHeaderDefinition.c

${OBJECTDIR}/DependencyList.o: DependencyList.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DependencyList.o DependencyList.c

${OBJECTDIR}/DependencyListWithID.o: DependencyListWithID.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DependencyListWithID.o DependencyListWithID.c

${OBJECTDIR}/FeatureInterface.o: FeatureInterface.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/FeatureInterface.o FeatureInterface.c

${OBJECTDIR}/FunctionCallDependency.o: FunctionCallDependency.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/FunctionCallDependency.o FunctionCallDependency.c

${OBJECTDIR}/FunctionElement.o: FunctionElement.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/FunctionElement.o FunctionElement.c

${OBJECTDIR}/GIReduction.o: GIReduction.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/GIReduction.o GIReduction.c

${OBJECTDIR}/GP.o: GP.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/GP.o GP.c

${OBJECTDIR}/GPIndividual.o: GPIndividual.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/GPIndividual.o GPIndividual.c

${OBJECTDIR}/GlobalDeclarations.o: GlobalDeclarations.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/GlobalDeclarations.o GlobalDeclarations.c

${OBJECTDIR}/IndividualInstantiator.o: IndividualInstantiator.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/IndividualInstantiator.o IndividualInstantiator.c

${OBJECTDIR}/ListOfFunctionSourceFile.o: ListOfFunctionSourceFile.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ListOfFunctionSourceFile.o ListOfFunctionSourceFile.c

${OBJECTDIR}/ListOfInt.o: ListOfInt.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ListOfInt.o ListOfInt.c

${OBJECTDIR}/ListOfString.o: ListOfString.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ListOfString.o ListOfString.c

${OBJECTDIR}/MappingCandidate.o: MappingCandidate.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MappingCandidate.o MappingCandidate.c

${OBJECTDIR}/Mappping.o: Mappping.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Mappping.o Mappping.c

${OBJECTDIR}/MarkFunctionCall.o: MarkFunctionCall.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MarkFunctionCall.o MarkFunctionCall.c

${OBJECTDIR}/OptionParser.o: OptionParser.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/OptionParser.o OptionParser.c

${OBJECTDIR}/PrepareForGP.o: PrepareForGP.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PrepareForGP.o PrepareForGP.c

${OBJECTDIR}/ReductionIndividual.o: ReductionIndividual.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ReductionIndividual.o ReductionIndividual.c

${OBJECTDIR}/Skeleton.o: Skeleton.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Skeleton.o Skeleton.c

${OBJECTDIR}/SkeletonMapping.o: SkeletonMapping.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SkeletonMapping.o SkeletonMapping.c

${OBJECTDIR}/SymbolTable.o: SymbolTable.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SymbolTable.o SymbolTable.c

${OBJECTDIR}/Utils.o: Utils.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Utils.o Utils.c

${OBJECTDIR}/coreFunctionExtractor.o: coreFunctionExtractor.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/coreFunctionExtractor.o coreFunctionExtractor.c

${OBJECTDIR}/folderContent.o: folderContent.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/folderContent.o folderContent.c

${OBJECTDIR}/main.o: main.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.c

${OBJECTDIR}/reverseCallGraph.o: reverseCallGraph.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/reverseCallGraph.o reverseCallGraph.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gentrans

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
