/*******************************************************************
 * File automatically generated by rebuild_wrappers.py (v2.2.0.18) *
 *******************************************************************/
#ifndef __wrappedsdl2imageTYPES_H_
#define __wrappedsdl2imageTYPES_H_

#ifndef LIBNAME
#error You should only #include this file inside a wrapped*.c file
#endif
#ifndef ADDED_FUNCTIONS
#define ADDED_FUNCTIONS() 
#endif

typedef void* (*pFp_t)(void*);
typedef void* (*pFpi_t)(void*, int32_t);
typedef int32_t (*iFppi_t)(void*, void*, int32_t);
typedef void* (*pFpip_t)(void*, int32_t, void*);
typedef void* (*pFppi_t)(void*, void*, int32_t);
typedef void* (*pFppip_t)(void*, void*, int32_t, void*);

#define SUPER() ADDED_FUNCTIONS() \
	GO(IMG_LoadBMP_RW, pFp_t) \
	GO(IMG_LoadCUR_RW, pFp_t) \
	GO(IMG_LoadGIF_RW, pFp_t) \
	GO(IMG_LoadICO_RW, pFp_t) \
	GO(IMG_LoadJPG_RW, pFp_t) \
	GO(IMG_LoadLBM_RW, pFp_t) \
	GO(IMG_LoadPCX_RW, pFp_t) \
	GO(IMG_LoadPNG_RW, pFp_t) \
	GO(IMG_LoadPNM_RW, pFp_t) \
	GO(IMG_LoadTGA_RW, pFp_t) \
	GO(IMG_LoadTIF_RW, pFp_t) \
	GO(IMG_LoadWEBP_RW, pFp_t) \
	GO(IMG_LoadXCF_RW, pFp_t) \
	GO(IMG_LoadXPM_RW, pFp_t) \
	GO(IMG_LoadXV_RW, pFp_t) \
	GO(IMG_Load_RW, pFpi_t) \
	GO(IMG_SavePNG_RW, iFppi_t) \
	GO(IMG_LoadTyped_RW, pFpip_t) \
	GO(IMG_LoadTexture_RW, pFppi_t) \
	GO(IMG_LoadTextureTyped_RW, pFppip_t)

#endif // __wrappedsdl2imageTYPES_H_
