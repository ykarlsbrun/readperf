/*
 * File:   records.h
 * Author: urs
 *
 * Created on August 8, 2011, 9:48 AM
 */

#ifndef _RECORDS_H
#define	_RECORDS_H

#ifdef	__cplusplus
extern "C" {
#endif
    
    
#include    <stdio.h>
#include    "origperf.h"
#include    "tree.h"
    
#define RECORD_TREE_LINK  ptl
    
    struct record_t {
        TREE_ENTRY(record_t)      RECORD_TREE_LINK;
	u32 pid, tid;
	u32 cpu;
        u64 time;
        u64 nr;
	u64 id;
        enum perf_event_type type;
    };
    
    struct record_mmap {
        struct record_t header;
	u64 start;
	u64 len;
	u64 pgoff;
	char filename[PATH_MAX];
    };
    
    struct record_comm {
        struct record_t header;
	char comm[16];
    };
    
    struct record_fork {
        struct record_t header;
	u32 ppid;
	u32 ptid;
    };
    
    struct record_sample {
        struct record_t header;
	u64 ip;
	u64 period;
    };
    
    typedef TREE_HEAD(_OrderTree, record_t) record_order_tree_t;
    
    record_order_tree_t init_record_order();
//    bool add_event( record_order_tree_t *tree, u64 ev_nr, const union perf_event *evt );
    bool add_record_order( record_order_tree_t *tree, struct record_t *rec );
    void iterate_order( record_order_tree_t *tree, void (*callback)(struct record_t *proc, void *data), void *data );
    
#ifdef	__cplusplus
}
#endif

#endif	/* _RECORDS_H */

