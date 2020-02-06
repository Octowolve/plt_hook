#include <memory.h>
#include <dlfcn.h>
#include <cstdio>
#include <cstdlib>
#include <jni.h>
#include <pthread.h>

#include "plthook.h"
#include "Logger.h"

void print_plt_entries(const char *filename)
{
    plthook_t *plthook;
    unsigned int pos = 0; /* This must be initialized with zero. */
    const char *name;
    void **addr;

    if (plthook_open(&plthook, filename) != 0) {
        printf("plthook_open error: %s\n", plthook_error());
        return;
    }
    while (plthook_enum(plthook, &pos, &name, &addr) == 0) {
        printf("%p(%p) %s\n", addr, *addr, name);
    }
    plthook_close(plthook);
    return;
}

void* hack_thread(void*) {
    print_plt_entries("libil2cpp.so");
    return NULL;
}



__attribute__((constructor))
void libloaded() {
    LOGI("I have been loaded. Mwuahahahaha");
    pthread_t ptid;
    pthread_create(&ptid, NULL, hack_thread, NULL);
}