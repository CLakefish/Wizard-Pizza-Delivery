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

#include "DropCommandHandler.h"

#include "Room.h" /*  */
#include "ItemList.h" /*  */
#include "CommandHandler.h" /* Function declarations */
#include "Items/KeyFunctions.h"

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

	if (gameState->currentRoomIndex == 1)
	{
		printf("What's this? The mat was hiding an entire room underneath it!\n\nYou can now go down.\n");
	}
	else if (gameState->currentRoomIndex == 2)
	{
		printf("As you pick up the mat, you see that a key has magically appeared under the mat!\n\nYou now have a key.\n");
		ItemList_AddItem(&gameState->inventory, Key_Build());
		
		/* remove the mat from the player's invetory */
		item = ItemList_FindItem(gameState->inventory, "mat");
		gameState->inventory = ItemList_Remove(gameState->inventory, item);
	}

	Room_AddRoomExit(currentRoom, "down", 2);
	Room_AddRoomExitShortcut(currentRoom, "d", 2);
	Room_AddRoomExitShortcut(currentRoom, "mat", 2);
}

void Mat_Drop(CommandContext context, GameState* gameState, WorldData* worldData)
{
	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(worldData);

	if (gameState->currentRoomIndex == 2)
	{
		printf("You place down the mat. You hear a 'ding!' sound, but you still don't see a key.\n");
	}
}

void Mat_Use(CommandContext context, GameState* gameState, WorldData* worldData)
{
	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(worldData);

	/*this is just copied and pasted from the drop command handler, I could create a better system for making the use function and drop function the same but I'm not taking the time to decouple stuff in someone else's code */

	/* find the dropped item in the player's inventory */
	Item* droppedItem = ItemList_FindItem(gameState->inventory, "mat");
	
	if (droppedItem == NULL)
	{
		//this shouldn't happen, but who knows what could happen in this messed up world we live in
		return;
	}

	/* remove the item from inventory and assign the inventory pointer back to the game state */
	gameState->inventory = ItemList_Remove(gameState->inventory, droppedItem);

	/* add the item to the room's item list */
	Room* room = WorldData_GetRoom(worldData, gameState->currentRoomIndex);
	
	ItemList** roomItemsPtr = Room_GetItemList(room);
	*roomItemsPtr = ItemList_Add(*roomItemsPtr, droppedItem);

	//drop
	Mat_Drop(context, gameState, worldData);
}

/* Build a "mat" object */
Item* Mat_Build()
{
	/* Create a "mat" item, using the functions defined in this file */
	return Item_Create("mat", NULL, true, Mat_Use, Mat_Take, Mat_Drop);
}