/******************************************************************************
filename    keyFunctions.c
author      Hugo D.
DP email    hugo.devant@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines the functions to create a specific item, the "key".

******************************************************************************/
#include "stdafx.h" /* NULL, UNREFERENCED_PARAMETER */
#include "keyFUnctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_ChangeScore, GameState_EndGame */
#include "GameFlags.h" /* GameFlags_IsInList, GameFlags_Add */
#include "Item.h" /* Item_Create */

typedef struct WorldData WorldData;


/* Helper: The action performed when the egg is taken. */
void Key_Take(CommandContext context, GameState* gameState, WorldData* worldData)
{
	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(worldData);

	/* safety check on the parameters */
	if (gameState == NULL)
	{
		return; /* take no action if the parameters are invalid */
	}

	/* check if the egg has already been scored */
	if (!GameFlags_IsInList(gameState->gameFlags, "keyScored"))
	{
		/* tell the user that something cool happens when they pick up the key */
		printf("You got $0.10 extra as a tip! \n");
		/* add to the user's score */
		GameState_ChangeScore(gameState, 0.10);
		/* the key has not been scored, so mark the flag */
		gameState->gameFlags = GameFlags_Add(gameState->gameFlags, "keyScored");
	}
}

/* Build a "egg" object */
Item* Key_Build()
{
	/* Create a "key" item, using the functions defined in this file */
	return Item_Create("key", "A rusty old key, marked with strange runes. \n", true, NULL, Key_Take, NULL);
}