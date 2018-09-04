#include <stdio.h>
#include <ncurses.h>
#include "gamepad.h"
#include "joystick.h"
int ch, i, j, k;
double output = 0;

static void update(GAMEPAD_DEVICE dev) {
	float lx, ly, rx, ry;

	if (!GamepadIsConnected(dev)) {
		return;
	}

	GamepadStickNormXY(dev, STICK_LEFT, &lx, &ly);
	GamepadStickNormXY(dev, STICK_RIGHT, &rx, &ry);
}


void init()
{
    GamepadInit();
}

double read_joystick()
{
    GamepadUpdate();    

    if (ch == 'r') {
    	for (i = 0; i != GAMEPAD_COUNT; ++i) {
    		GamepadSetRumble((GAMEPAD_DEVICE)i, 0.25f, 0.25f);
    	}
    }

    update(GAMEPAD_0);
    i=0;

    if (GamepadIsConnected(i)) {
    	for (j = 0; j != BUTTON_COUNT; ++j) {
    		if (GamepadButtonTriggered(i, j)) {
                if (j != 0){
    			printf("button triggered: %d \n", j);
                output = j;
                }
    		}

    	}
    	for (k = 0; k != STICKDIR_COUNT; ++k) {
        	if (GamepadStickDirTriggered(i, 0, k)) {
                if (j != 0){
        		printf("stick direction:   %d \n", k);
                output = k;
                }
        	}
        }
    }
    return(output);
}