#ifndef __MINICVCONFIG_H__
#define __MINICVCONFIG_H__
#include <stdio.h>
#include <sys/types.h>   
#include <dirent.h>

#define FIL FILE

#define NORETURN
#define FATFS
#define FA_READ
#define FA_OPEN_EXISTING

#define OMV_FB_ALLOC_SIZE               2048       // minimum fb alloc size
#define OMV_FB_ALLOC_SIZE_END			2047








typedef FILE FIL;
typedef DIR FF_DIR;
typedef char TCHAR;
typedef uint8_t BYTE;
typedef uint32_t UINT;
#define FR_OK 0
typedef int FRESULT;//FR_OK
typedef struct stat FILINFO;



























#define DBGLOG_TRACE(format, ...)

#define DBGLOG_DEBUG(format, ...)


#define DBGLOG_ERROR(format, ...)
void __DMB();
void __disable_irq();
void __enable_irq();
void __LDREXW();
void __STREXW();
void __WFI();
void mp_hal_ticks_ms();

// #define __UXTB_RORn(a,b) 

// #define IMAGE_LBP_API
// #define IMAGE_ORB_API












#define IMLIB_ENABLE_FIND_LINES 1
#define IMLIB_ENABLE_FIND_LINE_SEGMENTS 1

#define IMLIB_ENABLE_GET_REGRESSION 1

#define IMLIB_ENABLE_FIND_CIRCLES 1
#define IMLIB_ENABLE_FIND_RECTS 1
#define IMLIB_ENABLE_QRCODES 1

#define IMLIB_ENABLE_APRILTAGS 1

#define IMLIB_ENABLE_APRILTAGS 1

#define IMLIB_ENABLE_DATAMATRICES 1

#define IMLIB_ENABLE_BARCODES 1
#define IMLIB_ENABLE_BINARY_OPS 1

// #define IMLIB_ENABLE_FIND_DISPLACEMENT 1






#endif
