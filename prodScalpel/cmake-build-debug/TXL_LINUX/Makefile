PROGS	=	addAdditionalIncludes.x	addCoreFeatureToInterface.x addInterfaceToHost.x AllLineMarkersExtractor.x createInterface.x c.x ExtractAllDefinedFunctionsName.x ExtractAllFunctionsNameInAFile.x ExtractGlobalDefinitionStructDeclarations.x GenerateDeclarationDependenciesForDonorVariablesInAbstractMappings.x GenerateSymbolTableForLocalDefinedVariables.x GlobalVarTypesDeclDependencyCOREFUNCTIONS.x GlobalVarTypesDeclDependencyINTERFACE.x graftSymbolTable.x HostSymbolTable.x ifdef.x InsertAllSourceCodeFromInputAtTheBegginingOfOutput.x instantiateFunctionsInSkeleton.x instantiateSkeletonInInterface.x MarkFunctionCall.x multiplFiles.x MutationCandidateExtractor.x PrettyPrintWithAnnotations.x readReverseCallGraph.x replaceStaticFunctions.x SolveDeclarationDependencies.x 


SEC_PROGS	=	Unused/additionals.x Unused/callExternalProg.x Unused/CallTemplatsEtractor.x Unused/cflowReader.x Unused/gprofReader.x Unused/grammarRewrite.x Unused/instantiateFunctionSkeletonInProgram.x Unused/interactive.x Unused/multipleOld.x Unused/oldSymbolTable.x Unused/readReverseCallGraphFCTWithArgs.x Unused/readReverseCallGraphNonSymbol.x Unused/readReverseGraphCompleteFunctionRewrite.x Unused/replace.x Unused/symbols.x Unused/testComments.x Unused/TestReadReverseCompound.x Unused/TestSeparateDeclarations.x






all: $(PROGS)

clean:
	rm -f *.x

%.x : %.txl
	txlc -s 4000 $<
