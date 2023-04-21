/******************************************************************************
filename    MatFunctions.c
author      Preston C.
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines the functions to create a specific item, the "mat".

******************************************************************************/
#include "stdafx.h" /* NULL, UNREFERENCED_PARAMETER */
#include "GameState.h" /* struct GameState, GameState_ChangeScore, GameState_EndGame, GameState_SetRoom */
#include "GameFlags.h" /* GameFlags_IsInList, GameFlags_Add */
#include "Item.h" /* Item_Create */

#include "Room.h" /*  */
#include "ItemList.h"

typedef struct WorldData WorldData;


/* Helper: The action performed when the mat is taken. */
void Mat_Take(CommandContext context, GameState* gameState, WorldData* worldData)
{
	Room* currentRoom;
	Item* item;
	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(worldData);

	/* safety check on the parameters */
	if (gameState == NULL)
	{
		return; /* take no action if the parameters are invalid */
	}
	/* Item* mat; the mat in the user's inventory */

	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(worldData);

	currentRoom = WorldData_GetRoom(worldData, 1);

	printf("What's this? The mat wasn't a mat at all, but a wooden door hiding an entire room underneath it!\n\nYou can now go down.\n");

	Room_AddRoomExit(currentRoom, "down", 2);
	Room_AddRoomExitShortcut(currentRoom, "d", 2);
	Room_AddRoomExitShortcut(currentRoom, "mat", 2);


	/* remove the mat from the player's invetory */
	item = ItemList_FindItem(gameState->inventory, "mat");
	gameState->inventory = ItemList_Remove(gameState->inventory, item);
}

/* Build a "mat" object */
Item* Mat_Build()
{
	/* Create a "mat" item, using the functions defined in this file */
	return Item_Create("mat", NULL, true, NULL, Mat_Take, NULL);
}