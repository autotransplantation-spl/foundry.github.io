/* 
 * File:   FeatureInterface.h
 * Author: ---
 *
 * Created on 21 June 2014, 16:14
 */

#ifndef FEATUREINTERFACE_H
#define	FEATUREINTERFACE_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "FeatureInterface.h"    


    void generateHostInterface(SymbolTable * head, char * tempFilesPath,
            char * TXLPath, char * graftFile, char * outputFileName,
            char * interfaceHeaderFile, char * hostTargetPlaceFile, char * newInterfaceFileName,
            char * justInterfaceFileName, char * theGraftFunctionName);


#ifdef	__cplusplus
}
#endif

#endif	/* FEATUREINTERFACE_H */

