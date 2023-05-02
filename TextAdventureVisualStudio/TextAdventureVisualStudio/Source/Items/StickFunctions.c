/******************************************************************************
filename    EggFunctions.c
author      Matthew Picioccio
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines the functions to create a specific item, the "egg".

******************************************************************************/
#include "stdafx.h" /* NULL, UNREFERENCED_PARAMETER */
#include "StickFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_ChangeScore, GameState_EndGame */
#include "GameFlags.h" /* GameFlags_IsInList, GameFlags_Add */
#include "Item.h" /* Item_Create */
#include "Room.h" /* Add_Exit */

typedef struct WorldData WorldData;


/* Helper: The action performed when the brick is taken. */
void Stick_Take(CommandContext context, GameState* gameState, WorldData* worldData)
{
	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(worldData);

	if (gameState == NULL)
	{
		return; /* take no action if the parameters are invalid */
	}

	/* Give the user a hint about how the brick might be used, whenever it is picked up. */
	printf("The stick is oddly light with the words \"Uhhh... handle with care\" enscribed into it.\n");
}


/* Helper: The action performed when the brick is used. */
void Stick_Use(CommandContext context, GameState* gameState, WorldData* worldData)
{
	Room* currentRoom;

	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(worldData);

	/* go to the next room */
	if (gameState->currentRoomIndex == 4)
	{
		currentRoom = WorldData_GetRoom(worldData, 4);

		printf("You flick the stick with your wrist and a bolt of lightning shoots out, vaporizing the bookshelf in front of you\n\nYeah maybe that wasn't a good idea...\n\nYou make it to the other side, and see that the entryway is very clean. The wooden door on your left has sounds coming from inside of it. It sounds like metal clanging.\n\n");

		printf("You can now go through the \"door\" exit");

		Room_AddRoomExit(currentRoom, "door", 6);
		Room_AddRoomExitShortcut(currentRoom, "d", 6);
	}
	else
	{
		printf("You can't use the stick here\n");
	}
}


/* Build a "brick" object */
Item* Stick_Build()
{
	/* Create a "brick" item, using the functions defined in this file */
	return Item_Create("stick", "wooden stick", true, Stick_Use, Stick_Take, NULL);
}