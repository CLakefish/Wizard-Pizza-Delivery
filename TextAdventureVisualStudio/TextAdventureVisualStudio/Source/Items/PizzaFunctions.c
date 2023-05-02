/******************************************************************************
filename    BrickFunctions.c
author      Matthew Picioccio
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines the functions to create a specific item, the "brick".

******************************************************************************/
#include "stdafx.h" /* UNREFERENCED_PARAMETER, NULL*/
#include "PizzaFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_ChangeScore */
#include "GameFlags.h" /* GameFlags_IsInList */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetItemList, Room_SetDescription */
#include "ItemList.h" /* ItemList_FindItem, ItemList_Remove, ItemList_Add */
#include "Item.h" /* Item_Create */


/* Helper: The action performed when the pizza is taken. */
void Pizza_Take(CommandContext context, GameState* gameState, WorldData* worldData)
{
	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);

	Room* currentRoom = WorldData_GetRoom(worldData, gameState->currentRoomIndex);

	Room_AddRoomExit(currentRoom, "north", 1);
	Room_AddRoomExitShortcut(currentRoom, "n", 1);

	printf("Now you that you have the pizza, you can go north.\n");
}


/* Helper: The action performed when the pizza is used. */
void Pizza_Use(CommandContext context, GameState* gameState, WorldData* worldData)
{
	/* safety check on the parameters */
	if ((gameState == NULL) || (worldData == NULL))
	{
		return; /* take no action if the parameters are invalid */
	}

	/* check if the user is using the brick out of their inventory */
	if (context != CommandContext_Item_Inventory)
	{
		/* the user doesn't have the brick - inform the user of the problem and take no action */
		printf("You must have the pizza before you can use it.\n");
		return;
	}


	if (gameState->currentRoomIndex == 6)
	{
		GameState_EndGame(gameState, "You enter the wizard's room, but its pretty weird to enter in without asking. You peek into the cauldron, as the pizza is lowered into it. As the pizza crust touches the strange green liquid, it starts to bubble. The liquid becomes brighter and brighter. It starts to swirl around.\n\nSuddenly, the cheese in the pizza starts to expand. The cauldron releases a blast of cheese up into the air. The wizard cheers, \"Yes, YES!\" The cheese blows a hole into the ceiling of the tower.\n\nThe tower starts to rumble. You need to leave this place.\n\nYou race down the stairs, get out the door, and run to your Red PT Cruiser. You drive away as a tsunami of cheese overtakes the area.\n\nYou have completed Wizard Pizza Delivery!\n\n");
	}
	else
	{
		printf("You cannot use the pizza here.\n");
	}
}


/* Build a "brick" object */
Item* Pizza_Build()
{
	/* Create a "pizza" item, using the functions defined in this file */
	return Item_Create("pizza", "Cheese and pepperoni", true, Pizza_Use, Pizza_Take, NULL);
}