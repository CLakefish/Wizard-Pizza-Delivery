
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

	room = Room_Create("You're in your Pizza Delivery vehicle, (Used Red PT Cruiser) you finally made it to your destination.\n 'What kind of guy lives in a tower in the middle of nowhere on a steep cliff?' \n You look at the pizza, and see there is a list of special instructions carved in the pepperoni.\n\n 'If you make it to my house, please unlock the door with the key hidden under the mat and bring it up-stairs. My legs don't work as good as they used too!'");

	Room_AddRoomExit(room, "Door", 1);
	Room_AddRoomExitShortcut(room, "d", 1);

	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	return room;
}


/* TODO REQUIRED: Build room 1 */
Room* Room1_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;
	
	/* TODO REQUIRED: Call Room_Create with the Room 1 description:
	"This is room 1.  There is a large mirror here, and it shimmers as you approach.\n" */

	room = Room_Create("This is room 1.\n\n There is a large mirror here, and it shimmers as you approach. \n");

	/* TODO REQUIRED: Add an Exit "through the mirror" to Room 2 */

	Room_AddRoomExit(room, "through mirror", 2);
	/* TODO BASIC: Add exit shortcuts for "through mirror" and "mirror" */

	Room_AddRoomExitShortcut(room, "mirror", 2);
	Room_AddRoomExitShortcut(room, "m", 2);

	/* TODO REQUIRED: Add an Exit "south" back to Room 0 */
	/* TODO BASIC: Add room exit shortcut for "s" */

	Room_AddRoomExit(room, "south", 0);
	Room_AddRoomExitShortcut(room, "s", 0);


	/* TODO REQUIRED: Add a brick to the list of items in the room */
	ItemList_AddItem(Room_GetItemList(room), Brick_Build(room));

	/* return the new room */
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

	int roomCount = 4;

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