#pragma once
#include "sound_utils/audio.h"
#include "sound_utils/VirtualFile.h"
#include "sound_utils/pgeWav.h"

namespace Shadow::Audio{
    //WE HAVE 8 CHANNELS TO WORK WITH
    enum SoundChannel {
	    AUDIO_CHANNEL_MUSIC = 0,
	    AUDIO_CHANNEL_GUI = 1,
	    AUDIO_CHANNEL_PLAYER = 2,
	    AUDIO_CHANNEL_BLOCK = 3,
	    AUDIO_CHANNEL_WEATHER = 4,
	    AUDIO_CHANNEL_MOB = 5,
	    AUDIO_CHANNEL_RECORD = 6,
	    AUDIO_CHANNEL_MISC = 7
    };

    class AudioManager {
    public:
	    void init();

	    void Update();

    	void PlaySound(OSL_SOUND* sound, SoundChannel channel);
	    void PlayMusic(OSL_SOUND* music);
    };

    extern AudioManager g_AudioManager;
}