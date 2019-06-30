#ifndef STATEMENU_H_
#define STATEMENU_H_

#include <stdlib.h>
#include "Version.h"
#include <Aurealis/Utils/StateManager.h>
#include <Aurealis/Utils/GameState.h>
#include <Aurealis/Graphics/RenderManager.h>
#include <Aurealis/Utils/Logger.h>
#include <Aurealis/Utils/Timer.h>
#include <Aurealis/Utils/pgeZip.h>
#include <Aurealis/Utils/pgeDir.h>
#include <Aurealis/Graphics/TextureUtil.h>
#include <Aurealis/Utils/pge.h>

#include <Aurealis/System/SystemManager.h>
#include <Aurealis/Graphics/Camera.h>
#include <Aurealis/Graphics/Sprite.h>

#include <pspiofilemgr.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include<fstream>
#include<iostream>

#include <dirent.h>
#include <fcntl.h>
#include <errno.h>

#ifdef __PSP__
	#include <sys/stat.h>
#endif


#include <Aurealis/Audio/SoundManager.h>

using namespace Aurealis::Graphics;
using namespace Aurealis::Utils;
using namespace Aurealis::System;
using namespace Aurealis::Audio;
using namespace Aurealis;

class SaveFile
{
public:

	int saveVersion;
	bool compression;
	char worldGameMode;
	char worldName[50];
	bool locked;
	std::string fileName;

	int saveSize;
};

class TP
{
public:
    Sprite* packSprite;
	std::string name;
	std::string description;
};

class StateMenu : public CGameState
{
public:
	StateMenu();
	virtual ~StateMenu();

	void Init();
	void Enter();
	void CleanUp();

	void Pause();
	void Resume();

	void HandleEvents(StateManager* sManager);
	void Update(StateManager* sManager);
	void Draw(StateManager* sManager);

private:

	void ScanSaveFiles(const char* dirName);
	void ScanTexturePacks(const char* dirName);
	void DrawText(int x,int y, unsigned int color, float size, const char *message, ...);
	inline bool fileExists(const std::string& name);
	int fileSize(const std::string& name);

    unsigned int hash(const char* s, unsigned int seed);

private:

    typedef struct Statistics
    {
        unsigned short blockPlaced;
        unsigned short blockDestroyed;
        unsigned short daysInGame;
        unsigned short minutesPlayed;
        unsigned short itemsCrafted;
        unsigned short itemsSmelted;
        unsigned short jumps;
        unsigned short dies;
        unsigned short foodEaten;
        unsigned short badlyFalls;
        unsigned short blocksWalked;
        unsigned short treesGrowned;
        unsigned short cropsGrowned;
        unsigned short soilPlowed;
        unsigned short timeInWater;
        unsigned short timeInAir;
        unsigned short damageRecieved;
    } st;

    typedef struct Options
    {
        bool useMipsTexturing;
        bool detailedSky;
        bool fastRendering;
        bool mipMapTexturing;
        bool freezeDayTime;
        bool sounds;
        bool music;
        bool autoJump;
        bool worldBlockAnimation;
        bool fogRendering;
        bool smoothLighting;
        bool particles;
        bool guiDrawing;

        float fov;
        char horizontalViewDistance;
        char verticalViewDistance;
        int difficult;
    } opt;

    st mainStatistics;
    opt mainOptions;

    float bx, by;
    bool directionx;
    bool directiony;

	Texture *texLogo, *texRectangles, *texButton;

    Sprite *buttonSmallSprite;
	Sprite *sbuttonSmallSprite;
	Sprite *nbuttonSmallSprite;

	Sprite *buttonSprite;
	Sprite *sbuttonSprite;

	Sprite *nbuttonSprite;

	Sprite *mbuttonSprite;
	Sprite *smbuttonSprite;

	Sprite *logoSprite;
	Sprite *lamecraftSprite;

	Sprite *rectFilledSprite;
	Sprite *rectEmptySprite;

	Sprite *blackBackground;

	Texture* bgTex[24];
	float op1;
	float animTime;
	Timer timer;

	int currTime;


	Sprite* bg[24];

    // converter vars
    bool schematicExists;

	short newW_width;
	short newW_height;
	short newW_length;

	char newW_gameMode;
	bool newW_deleteCaves;
	int conversionStage;
	int errorType;

	std::string lol;

    int converterPos;
	//

    int SplashNumber;
    float splashSize;
	bool isPaused;
    unsigned int seed_1;
	int selectPos;
	int loadSelectPos;
	int loadSavePos;
	int aboutPos;
	char worldName[32];

    float size_f;

	float fontcolor;
	bool fontcoloroption;

	bool saveSubmenu;
	int saveSubMenuSelect;

    pgeZip* theZip;

	int loadSaveStart;
	int loadSaveEnd;
	int loadSaveMax;

	short animationscreen;
	short menuState;//0 main,1 load,2 options

	int nextSaveFileNumber;
	std::string nextSaveFileName;

	std::vector<SaveFile> saveFilesList;
	std::vector<TP> texturePackList;
	std::string newWorldName;
	std::string newWorldSeed;
	std::string newWorldNamestr;
	//options for parametric map generation
	bool makeTrees;
	bool makeWater;
	bool makeCaves;
    int terrainBuilder;
	short gameMode;
	int worldType;

    short generateSelectPose;

	//game version
	short currentVersion;

	int tpCurrent;
	int tpMax;
	int tpEnd;
	int tpStart;
	int tpPos;
	int tpSelectPos;
};

#endif
