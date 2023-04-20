/******************************************************************************
filename    KeyDoorFunctions.c
author      Preston Campbell
DP email    p.campbell@digipen.edu

Brief Description:
Item that makes sure you have the items necessary to open the door.

******************************************************************************/
#include "stdafx.h" /* NULL, UNREFERENCED_PARAMETER */
#include "KeyDoorFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_EndGame */
#include "ItemList.h" /* ItemList_FindItem */
#include "Item.h" /* Item_Create */

typedef struct WorldData WorldData;


/* Helper: The action performed when the key door is used. */
void KeyDoor_Use(CommandContext context, GameState* gameState, WorldData* worldData)
{
	Item* key; /* the key in the user's inventory */
	/* Item* mat; the mat in the user's inventory */

	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(worldData);

	/* find the gold piece in the user's inventory */
	key = ItemList_FindItem(gameState->inventory, "key");

	/* find the mat in the user's inventory */
	//mat = ItemList_FindItem(gameState->inventory, "mat");

	/* check both items */
	
	/* uncomment once mat is available
	if (mat != NULL)
	{
		printf("I have to return the mat before I can use the door.\n");
		return;
	}
	*/
	
	if (key == NULL)
	{
		/* both items were not found - tell the user about the problem and take no further action */
		printf("I need a key to open the door.\n");
		return;
	}

	/* go to the next room */
	gameState->currentRoomIndex = 2;
	printf("[You open the door.]\n");
}


/* Build a "exit door" object */
Item* KeyDoor_Build()
{
	/* Create a "exit door" item, using the functions defined in this file */
	return Item_Create("door", "The door is locked.\n", false, KeyDoor_Use, NULL, NULL);
}