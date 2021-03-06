/*
 * @file
 * Iterate through the record data structure and build process data structure, 
 * update period and sample count of source functions.
 *
 * Copyright 2011 Urs Fässler, www.bitzgi.ch
 * SPDX-License-Identifier:	GPL-3.0+
 */

#ifndef _BUILDSTAT_H
#define	_BUILDSTAT_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include    "processes.h"
#include    "../perffile/records.h"
    
    bool buildstat( record_order_tree_t *tree );
    
#ifdef	__cplusplus
}
#endif

#endif	/* _BUILDSTAT_H */

