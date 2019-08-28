#pragma once
#include <Shadow/Utils/Input.hpp>

namespace Minecraft::Common{
    using namespace Shadow::Utils;
struct Controls {
	// Actions
	int jump;
	int destroy;
	int place;

	// Walk
	int walkLeft;
	int walkRight;
	int walkUp;
	int walkDown;

	// Look
	int lookLeft;
	int lookRight;
	int lookUp;
	int lookDown;

	// Hotbar
	int hotLeft;
	int hotRight;
	int toggleSprint;
    int toggleCrouch;

    //Menu
	int pauseMenu;
};

extern Controls g_Control;

void loadControls();
void writeControls();
}