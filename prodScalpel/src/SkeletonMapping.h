/* 
 * File:   SkeletonMapping.h
 * Author: ---
 *
 * Created on 27 June 2014, 18:37
 */

#ifndef SKELETONMAPPING_H
#define	SKELETONMAPPING_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "Mapping.h"

    struct skeletonMapping {
        char * functionName;
        Mapping * mappings;

        struct skeletonMapping * next;
    };

    typedef struct skeletonMapping SkeletonMapping;

    void freeSkeletonMapping(SkeletonMapping ** head);

    SkeletonMapping * returnMappingsForFunction(SkeletonMapping * head, char * name);

    SkeletonMapping * addNewSkeletonMapping(SkeletonMapping ** head, char * name);

#ifdef	__cplusplus
}
#endif

#endif	/* SKELETONMAPPING_H */

