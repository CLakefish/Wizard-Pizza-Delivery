
#include "WorldDataFactory.h" 
#include "WorldData.h" 
#include "Room.h" 
#include "ItemList.h"
#include "BrickFunctions.h"
#include "GoldPieceFunctions.h" 
#include "ExitDoorFunctions.h" 


/* TODO REQUIRED: Build room 0 */
Room* Room0_Build()
{
	Room* room = NULL;

	room = Room_Create("You're in your Pizza Delivery vehicle, (Used Red PT Cruiser) you finally made it to your destination.\n\"What kind of guy lives in a tower in the middle of nowhere on a steep cliff?\"\nYou look at the pizza, and see there is a list of special instructions carved in the pepperoni.\n\n \"If you make it to my house, please unlock the door with the key hidden under the mat and bring it up-stairs. My legs don't work as good as they used to!\"\n");

	Room_AddRoomExit(room, "Car Door", 1);
	Room_AddRoomExitShortcut(room, "door", 1);
	Room_AddRoomExitShortcut(room, "car door", 1);
	Room_AddRoomExitShortcut(room, "d", 1);

	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	return room;
}


/* TODO REQUIRED: Build room 1 */
Room* Room1_Build()
{
	Room* room = NULL;

	room = Room_Create("You step outside of your car and walk up to the front door, the tower looming over you.\n You look down to see the doormat, its marked with the words \"i don no\" with a photo of Jerry Seinfeld shrugging. \n\n You can either get the key like the order said, or you can leave it here and call it a night.\n");

	Room_AddRoomExit(room, "Leave", 7);
	Room_AddRoomExitShortcut(room, "leave", 7);
	Room_AddRoomExitShortcut(room, "l", 7);

	return room;
}


/* TODO REQUIRED: Build room 2 */
Room* Room2_Build()
{
	/* TODO: Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* TODO REQUIRED: Call Room_Create with the Room 2 description:
	"This is room 2.  The room is isolated from the others, but you can see a crack in the east wall, just large enough to get through.\n" */
	room = Room_Create("This is room 2.\n\n The room is isolated from the others but you can see a crack in the east wall, just large enough to get through.\n");


	/* TODO REQUIRED: Add an Exit "east" to Room 0 */
	/* TODO BASIC: Add exit shortcuts for "e" and "crack" */

	Room_AddRoomExit(room, "east", 3);
	Room_AddRoomExitShortcut(room, "e", 3);

	/* TODO REQUIRED: Add a gold piece to the list of items in the room */
	ItemList_AddItem(Room_GetItemList(room), GoldPiece_Build(room));

	/* return the new room */
	return room;
}

Room* Room3_Build()
{
	Room* room = NULL;

	room = Room_Create("This is the end room. Thanks for playing!");

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