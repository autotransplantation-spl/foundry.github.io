/* 
 * File:   Mapping.h
 * Author: ---
 *
 * Created on 27 June 2014, 18:33
 */

#ifndef MAPPING_H
#define	MAPPING_H

#ifdef	__cplusplus
extern "C" {
#endif

    struct mapping {
        char * source;
        char * destination;

        struct mapping * next;
    };

    typedef struct mapping Mapping;

    void freeMapping(Mapping ** head);

    void addNewMapping(Mapping ** head, char * source, char * destination);

    Mapping * copyListOfMapping(Mapping * head);

    void printAListOfMappings(Mapping * head, char * outputFile);
    
    void printAListOfMappingsStringlit(Mapping * head, char * outputFile);



#ifdef	__cplusplus
}
#endif

#endif	/* MAPPING_H */

