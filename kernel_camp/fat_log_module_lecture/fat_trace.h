#undef TRACE_SYSTEM
#define TRACE_SYSTEM fat_log_lecture

#if !defined(_TRACE_FAT_LOG_LECTURE_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_FAT_LOG_LECTURE_H

#include <linux/tracepoint.h>
#include <linux/types.h>
#include "fat.h"

TRACE_EVENT(fat_ent_new_write,
	TP_PROTO(struct inode *inode, int new_cls, int wait),

	TP_ARGS(inode, new_cls, wait),

	TP_STRUCT__entry(
		__field(	unsigned long   , t_ino		    )
		__field(	int             , t_new		    )
		__field(	int             , t_wait		)
	),

	TP_fast_assign(
		__entry->t_ino	= inode->i_ino;
		__entry->t_new	= new_cls;
        __entry->t_wait = wait;
	),

	TP_printk("ino %lu , cluster : %d , wait : %d ", __entry->t_ino, __entry->t_new ,__entry->t_wait)
);

#endif /* _TRACE_FAT_LECTURE_H  */


#undef TRACE_INCLUDE_PATH
#define TRACE_INCLUDE_PATH .
#define TRACE_INCLUDE_FILE fat_trace
#include <trace/define_trace.h>



