
#include "WorldDataFactory.h"
#include "WorldData.h" 
#include "Room.h" 
#include "ItemList.h"

//todo: GameItems.h
#include "Items/BrickFunctions.h"
#include "Items/GoldPieceFunctions.h" 
#include "Items/KeyFunctions.h" 
#include "Items/KeyDoorFunctions.h" 
#include "Items/MatFunctions.h"


/* TODO REQUIRED: Build room 0 */
Room* Room0_Build()
{
	Room* room = NULL;

	room = Room_Create("You're in your Pizza Delivery vehicle, (Used Red PT Cruiser) you finally made it to your destination.\n\"What kind of guy lives in a tower in the middle of nowhere on a steep cliff?\"\nYou look at the pizza, and see there is a list of special instructions.\n\n \"\"\n");

	/*
	Delivery Instructions:
	
	Once you make it to my house, please unlock the door with the key hidden under the mat and bring it upstairs. My legs don't work as good as they used to!
	*/

	Room_AddRoomExit(room, "north", 1);
	Room_AddRoomExitShortcut(room, "n", 1);

	return room;
}

Room* Room1_Build()
{
	Room* room = NULL;

	room = Room_Create("The tower looms over you.\n You look down to see the doormat, it's marked with the words \"A Wizard's Welcome!\"\n\nYou can either get the key like the delivery instructions said, or you can leave it here and call it a night.\n");

	//the difference between Room_AddRoomExit and Room_AddRoomExitShortcut is that shortcut does not appear in the help menu
	Room_AddRoomExit(room, "exit", 7);
	Room_AddRoomExitShortcut(room, "leave", 7);
	Room_AddRoomExitShortcut(room, "l", 7);

	ItemList_AddItem(Room_GetItemList(room), Mat_Build());

	return room;
}

Room* Room2_Build()
{
	Room* room = NULL;

	room = Room_Create("You go down the ladder.\n\nYou see a sign, it reads: \"What is the name of the wizard's dog?\"\nYou're unsure of what to do, as this game has no \"say\" command.\n");
	
	Room_AddRoomExit(room, "up", 1);
	Room_AddRoomExitShortcut(room, "u", 1);
	Room_AddRoomExitShortcut(room, "ladder", 1);

	return room;
}


Room* Room3_Build()
{
	Room* room = NULL;

	room = Room_Create("You enter the tower.\n\nThe first room is small.\n");

	ItemList_AddItem(Room_GetItemList(room), Key_Build());

	Room_AddRoomExit(room, "up", 1);
	Room_AddRoomExitShortcut(room, "u", 1);

	/* return the new room */
	return room;
}

WorldData* CreateInitialWorldData()
{
	WorldData* worldData;

	int roomCount = 7;

	/* create the new WorldData object with 3 rooms */
	worldData = WorldData_Create("Welcome to my GAM100 Game!\n\n", roomCount);

	/* build each room and assign them to the world data */
	WorldData_SetRoom(worldData, 0, Room0_Build());

	WorldData_SetRoom(worldData, 1, Room1_Build());
	WorldData_SetRoom(worldData, 2, Room2_Build());
	WorldData_SetRoom(worldData, 3, Room3_Build());

	/* return the new object */
	return worldData;
}