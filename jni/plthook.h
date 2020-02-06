#ifndef PLTHOOK_H
#define PLTHOOK_H 1

#define PLTHOOK_SUCCESS              0
#define PLTHOOK_FILE_NOT_FOUND       1
#define PLTHOOK_INVALID_FILE_FORMAT  2
#define PLTHOOK_FUNCTION_NOT_FOUND   3
#define PLTHOOK_INVALID_ARGUMENT     4
#define PLTHOOK_OUT_OF_MEMORY        5
#define PLTHOOK_INTERNAL_ERROR       6
#define PLTHOOK_NOT_IMPLEMENTED      7

typedef struct plthook plthook_t;

#ifdef __cplusplus
extern "C" {
#endif

int plthook_open(plthook_t **plthook_out, const char *filename);
int plthook_open_by_handle(plthook_t **plthook_out, void *handle);
int plthook_open_by_address(plthook_t **plthook_out, void *address);
int plthook_enum(plthook_t *plthook, unsigned int *pos, const char **name_out, void ***addr_out);
int plthook_replace(plthook_t *plthook, const char *funcname, void *funcaddr, void **oldfunc);
void plthook_close(plthook_t *plthook);
const char *plthook_error(void);

#ifdef __cplusplus
}; /* extern "C" */
#endif

#endif