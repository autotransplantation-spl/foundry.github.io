/* 
 * File:   coreFunctionExtractor.h
 * Author: ---
 *
 * Created on 19 June 2014, 17:53
 */

#ifndef COREFUNCTIONEXTRACTOR_H
#define	COREFUNCTIONEXTRACTOR_H

#ifdef	__cplusplus
extern "C" {
#endif

void extractCoreFunctionality(char * graftMethod, char * graftFileFullPath, char * donorSourceFiles, char * transplantWorkingFolder,
        char * txlProgsPath, char * TXLTemp, char * tempFolder, char * headerOutputFile,
        char * sourceOutputFile) ;


#ifdef	__cplusplus
}
#endif

#endif	/* COREFUNCTIONEXTRACTOR_H */

