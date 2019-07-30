#include "AudioManager.hpp"

namespace Shadow::Audio{
    void AudioManager::init()
    {
	    VirtualFileInit();
	    oslInitAudio();
    }

    void AudioManager::Update()
    {
	    oslAudioVSync();
    }

    void AudioManager::PlaySound(OSL_SOUND * sound, SoundChannel channel)
    {
	    oslPlaySound(sound, channel);
    }

    void AudioManager::PlayMusic(OSL_SOUND * music)
    {
	    oslPlaySound(music, AUDIO_CHANNEL_MUSIC);
    }

    AudioManager g_AudioManager = AudioManager();
}