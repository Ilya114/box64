#ifndef __CUSTOM_MEM__H_
#define __CUSTOM_MEM__H_
#include <unistd.h>
#include <stdint.h>


typedef struct box64context_s box64context_t;

void* customMalloc(size_t size);
void* customCalloc(size_t n, size_t size);
void* customRealloc(void* p, size_t size);
void customFree(void* p);

#define kcalloc     customCalloc
#define kmalloc     customMalloc
#define krealloc    customRealloc
#define kfree       customFree

#ifdef DYNAREC
typedef struct dynablock_s dynablock_t;
// custom protection flag to mark Page that are Write protected for Dynarec purpose
uintptr_t AllocDynarecMap(size_t size);
void FreeDynarecMap(uintptr_t addr);

void addDBFromAddressRange(uintptr_t addr, size_t size);
void cleanDBFromAddressRange(uintptr_t addr, size_t size, int destroy);

dynablock_t* getDB(uintptr_t idx);
int getNeedTest(uintptr_t idx);
int addJumpTableIfDefault64(void* addr, void* jmp); // return 1 if write was succesfull
int setJumpTableIfRef64(void* addr, void* jmp, void* ref); // return 1 if write was succesfull
void setJumpTableDefault64(void* addr);
void setJumpTableDefaultRef64(void* addr, void* jmp);
int isJumpTableDefault64(void* addr);
uintptr_t getJumpTable64(void);
uintptr_t getJumpTableAddress64(uintptr_t addr);
uintptr_t getJumpAddress64(uintptr_t addr);

#define JMPTABL_SHIFT3 18
#define JMPTABL_SHIFT2 18
#define JMPTABL_SHIFT1 18
#define JMPTABL_SHIFT0 10
#define JMPTABL_START3 (JMPTABL_START2+JMPTABL_SHIFT2)
#define JMPTABL_START2 (JMPTABL_START1+JMPTABL_SHIFT1)
#define JMPTABL_START1 (JMPTABL_START0+JMPTABL_SHIFT0)
#define JMPTABL_START0 0
#define JMPTABLE_MASK3 ((1<<JMPTABL_SHIFT3)-1)
#define JMPTABLE_MASK2 ((1<<JMPTABL_SHIFT2)-1)
#define JMPTABLE_MASK1 ((1<<JMPTABL_SHIFT1)-1)
#define JMPTABLE_MASK0 ((1<<JMPTABL_SHIFT0)-1)
#endif

#define PROT_DYNAREC    0x80
#define PROT_DYNAREC_R  0x40
#define PROT_NOPROT     0x20
#define PROT_MMAP       0x10
#define PROT_DYN        (PROT_DYNAREC | PROT_DYNAREC_R | PROT_NOPROT)
#define PROT_CUSTOM     (PROT_DYNAREC | PROT_DYNAREC_R | PROT_MMAP | PROT_NOPROT)

void updateProtection(uintptr_t addr, size_t size, uint32_t prot);
void setProtection(uintptr_t addr, size_t size, uint32_t prot);
void setProtection_mmap(uintptr_t addr, size_t size, uint32_t prot);
void freeProtection(uintptr_t addr, size_t size);
void refreshProtection(uintptr_t addr);
uint32_t getProtection(uintptr_t addr);
int getMmapped(uintptr_t addr);
void loadProtectionFromMap(void);
#ifdef DYNAREC
void protectDB(uintptr_t addr, size_t size);
void unprotectDB(uintptr_t addr, size_t size, int mark);    // if mark==0, the blocks are not marked as potentially dirty
int isprotectedDB(uintptr_t addr, size_t size);
int IsInHotPage(uintptr_t addr);
int AreaInHotPage(uintptr_t start, uintptr_t end);
void AddHotPage(uintptr_t addr);
#endif
void* find32bitBlock(size_t size);
void* find31bitBlockNearHint(void* hint, size_t size);
void* find47bitBlock(size_t size);
void* find47bitBlockNearHint(void* hint, size_t size);

// unlock mutex that are locked by current thread (for signal handling). Return a mask of unlock mutex
int unlockCustommemMutex(void);
// relock the muxtex that were unlocked
void relockCustommemMutex(int locks);

void init_custommem_helper(box64context_t* ctx);
void fini_custommem_helper(box64context_t* ctx);

#ifdef DYNAREC
// ---- StrongMemoryModel
void addLockAddress(uintptr_t addr);    // add an address to the list of "LOCK"able
int isLockAddress(uintptr_t addr);  // return 1 is the address is used as a LOCK, 0 else
#endif

#endif //__CUSTOM_MEM__H_
