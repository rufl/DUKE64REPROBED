#ifndef DUKE64_ASSET_HOOKS_H
#define DUKE64_ASSET_HOOKS_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

int duke64_try_play_external_sound(int sound_id, int sprite_id);
int duke64_try_start_external_music(int music_id);
void duke64_stop_external_music(void);

#ifdef __cplusplus
}
#endif

#endif
