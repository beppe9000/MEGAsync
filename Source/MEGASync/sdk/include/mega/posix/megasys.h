/**
 * @file mega/posix/megasys.h
 * @brief Mega SDK platform-specific includes (Posix)
 *
 * (c) 2013 by Mega Limited, Wellsford, New Zealand
 *
 * This file is part of the MEGA SDK - Client Access Engine.
 *
 * Applications using the MEGA API must present a valid application key
 * and comply with the the rules set forth in the Terms of Service.
 *
 * The MEGA SDK is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * @copyright Simplified (2-clause) BSD License.
 *
 * You should have received a copy of the license along with this
 * program.
 */

#ifndef MEGA_POSIX_OS_H
#define MEGA_POSIX_OS_H 1

// platform dependent constants
#include "mega/config.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <assert.h>
#include <memory.h>
#include <time.h>

// Linux specific includes

// XXX: posix
//#define _POSIX_SOURCE
//#define _LARGE_FILES
//#define _LARGEFILE64_SOURCE
//#define _GNU_SOURCE 1
//#define _FILE_OFFSET_BITS 64
#define __DARWIN_C_LEVEL 199506L

#include <sys/stat.h>
#include <sys/time.h>
#include <utime.h>
#include <stdio.h>
#include <stdarg.h>
#include <fcntl.h>
#include <glob.h>
#include <dirent.h>

#include <sys/un.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <termios.h>

#ifndef __MACH__
#include <endian.h>
#endif

#ifdef HAVE_SENDFILE
#include <sys/sendfile.h>
#endif

#ifdef USE_INOTIFY
#include <sys/inotify.h>
#endif

#include <sys/select.h>

#include <curl/curl.h>
//#endif // end of Linux specific includes

#ifndef FD_COPY
#define FD_COPY(s, d) (memcpy ((d), (s), sizeof (fd_set)))
#endif

#ifdef __MACH__

// FIXME: revisit OS X support
#include <machine/endian.h>
#include <strings.h>
#include <sys/time.h>
#define CLOCK_MONOTONIC 0
int clock_gettime(int, struct timespec* t)
{
    struct timeval now;
    int rv = gettimeofday(&now,NULL);
    if (rv) return rv;
    t->tv_sec  = now.tv_sec;
    t->tv_nsec = now.tv_usec*1000;
    return 0;
}

#endif
#endif // MEGA_POSIX_OS_H
