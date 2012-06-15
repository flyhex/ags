#ifndef __AC_SOUNDCACHE_H
#define __AC_SOUNDCACHE_H

// PSP: A simple sound cache. The size can be configured in the config file.
// The data rate while reading from disk on the PSP is usually between 500 to 900 kiB/s,
// caching the last used sound files therefore improves game performance.

//#define SOUND_CACHE_DEBUG

// PSP: Additional header for the sound cache.
#if defined(PSP_VERSION)
#include <pspsdk.h>
#include <psprtc.h>
#endif

typedef struct
{
    char* file_name;
    int number;
    int free;
    unsigned int last_used;
    unsigned int size;
    char* data;
    int reference;
} sound_cache_entry_t;

extern int psp_use_sound_cache;
extern int psp_sound_cache_max_size;
extern int psp_audio_cachesize;
extern int psp_midi_preload_patches;

void clear_sound_cache();
void sound_cache_free(char* buffer, bool is_wave);
char* get_cached_sound(const char* filename, bool is_wave, long* size);


#endif // __AC_SOUNDCACHE_H