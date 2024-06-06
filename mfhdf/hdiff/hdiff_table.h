/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Copyright by The HDF Group.                                               *
 * Copyright by the Board of Trustees of the University of Illinois.         *
 * All rights reserved.                                                      *
 *                                                                           *
 * This file is part of HDF.  The full HDF copyright notice, including       *
 * terms governing use, modification, and redistribution, is contained in    *
 * the COPYING file, which can be found at the root of the source code       *
 * distribution tree, or in https://support.hdfgroup.org/ftp/HDF/releases/.  *
 * If you do not have access to either file, you may request a copy from     *
 * help@hdfgroup.org.                                                        *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef HDIFF_TABLE_H
#define HDIFF_TABLE_H

#include "hdf.h"
#include "mfhdf.h"

#ifdef __cplusplus
extern "C" {
#endif

/*struct to store the tag/ref and path of an object
 the pair tag/ref uniquely identifies an HDF object */
typedef struct dobj_info_t {
    int32 tag;
    int32 ref;
    char  obj_name[H4_MAX_NC_NAME];
    int   flags[2];
    /*flags that store matching object information
      between the 2 files
      object exists in file = 1
      does not exist        = 0
    */
} dobj_info_t;

/*struct that stores all objects */
typedef struct dtable_t {
    uint32       size;
    uint32       nobjs;
    dobj_info_t *objs;
} dtable_t;

/* table methods */
void dtable_init(dtable_t **table);
void dtable_free(dtable_t *table);
int  dtable_search(dtable_t *table, int32 tag, int32 ref);
void dtable_add(dtable_t *table, int32 tag, int32 ref, char *obj_name);
void dtable_print(dtable_t *table, char *header);

#ifdef __cplusplus
}
#endif

#endif /* HDIFF_TABLE_H */
