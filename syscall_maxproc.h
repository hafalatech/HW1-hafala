#include <asm/errno.h>
extern int errno; 

int set_child_max_proc(int maxp)
{
        unsigned int res;
        __asm__
        (
                        "int $0x80;"
                        : "=a" (res)
                        : "0" (243) ,"b" (pid)
                        : "memory"
        );
        if (res>=(unsigned long)(-125))
        {
                errno = -res;
                res = -1;
        }
        return (int) res;
}

int get_max_proc()
{
        unsigned int res;
        __asm__
        (
                        "int $0x80;"
                        : "=a" (res)
                        : "0" (244) ,"b" (pid)
                        : "memory"
        );
        if (res>=(unsigned long)(-125))
        {
                errno = -res;
                res = -1;
        }
        return (int) res;
}

int get_subproc_count()
{
        unsigned int res;
        __asm__
        (
                        "int $0x80;"
                        : "=a" (res)
                        : "0" (245) ,"b" (pid)
                        : "memory"
        );
        if (res>=(unsigned long)(-125))
        {
                errno = -res;
                res = -1;
        }
        return (int) res;
}









Hide details
Change log
r24 by urialon1 on Nov 4, 2014   Diff
Fixing count_sons, exit.c
Go to: 	
Older revisions
 r23 by urialon1 on Nov 4, 2014   Diff 
 r17 by urialon1 on Nov 4, 2014   Diff 
All revisions of this file
File info
Size: 533 bytes, 38 lines
View raw file
File properties
svn:mime-type
text/plain
