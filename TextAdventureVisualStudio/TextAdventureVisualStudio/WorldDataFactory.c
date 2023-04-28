
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
#include "Items/StickFunctions.h" 


/* TODO REQUIRED: Build room 0 */
Room* Room0_Build()
{
	//by carson
	Room* room = NULL;

	room = Room_Create("You're in your Pizza Delivery vehicle, (Used Red PT Cruiser) you finally made it to your destination.\n\"What kind of guy lives in a tower in the middle of nowhere on a steep cliff?\"\nYou look at the pizza, and see there is a list of special instructions.\n\n\"Once you make it to my house, please unlock the door with the key hidden under the mat and bring it upstairs. My legs don't work as good as they used to!\"\n");

	Room_AddRoomExit(room, "north", 1);
	Room_AddRoomExitShortcut(room, "n", 1);

	return room;
}

Room* Room1_Build()
{
	//by carson and preston
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
	//by preston
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

	room = Room_Create("You enter the tower.\n\n The approach the first room, following a large staircase that took 5 minutes to go up. \n The room is very cluttered, filled with books and shelves that have been thrown about or knocked over.\n\n Theres a door on the other side you can just barely spot\n To your left is a door which is slightly open, and in front of you is a small hole big enough to fit the pizza in.\n");

	ItemList_AddItem(Room_GetItemList(room), Key_Build());

	Room_AddRoomExit(room, "left", 4);
	Room_AddRoomExitShortcut(room, "l", 4);

	Room_AddRoomExit(room, "hole", 5);
	Room_AddRoomExitShortcut(room, "h", 5);

	/* return the new room */
	return room;
}

Room* Room4_Build()
{
	Room* room = NULL;

	room = Room_Create("You enter into the left room, just as messy as the room before.\n\nTheres another door on the other side, but a knocked over bookshelf blocks your path.\n");

	Room_AddRoomExit(room, "back", 3);
	Room_AddRoomExitShortcut(room, "b", 3);

	return room;
}

Room* Room5_Build()
{
	Room* room = NULL;

	room = Room_Create("You squeeze your way through the gap, holding the pizza in the air.\n\nYou can't make it to the door cause of somethin idk, but there is a cool stick in the corner.\n\n");

	ItemList_AddItem(Room_GetItemList(room), Stick_Build());

	Room_AddRoomExit(room, "back", 3);
	Room_AddRoomExitShortcut(room, "b", 3);

	return room;
}

Room* Room6_Build()
{
	Room* room = NULL;

	room = Room_Create("");

	Room_AddRoomExit(room, "door", 7);
	
	return room;
}

Room* Room7_Build()
{
	Room* room = NULL;

	room = Room_Create("You hear loud crashing and bangs, as footsteps near the door. The door swings open, revealing a small cobblestone room with a cauldron inside, emitting a light green light.\n\n \"Finally! The last ingredient! Thanks for following my instructions!\"\n\n The wizard rummages through his blue robe pocket, and swings out a leather wallet.\n\n \"I believe I owe you $13... lets see here, one... two... etc...\"\n\n You've completed your task, you can either leave or go inside the wizards' room.");

	Room_AddRoomExit(room, "wizard room", 8);
	Room_AddRoomExitShortcut(room, "wr", 8);
	Room_AddRoomExit(room, "leave", NULL);
	Room_AddRoomExitShortcut(room, "l", NULL);

	return room;
}

Room* Room8_Build()
{
	Room* room = NULL;

	room = Room_Create("You enter the wizard's room, but its pretty weird to enter in without asking. You peek into the cauldron, as the pizza is lowered into it. As the pizza crust touches the strange green liquid, it starts to bubble. The liquid becomes brighter and brighter. It starts to swirl around.\n\n Suddenly, the cheese in the pizza starts to expand. The cauldron releases a blast of cheese up into the air. The wizard cheers, \"Yes, YES!\" The cheese blows a hole into the ceiling of the tower.\n\n The tower starts to rumble. You need to leave this place. \n\n You race down the stairs, get out the door, and run to your Red PT Cruiser. You drive away as a tsunami of cheese overtakes the area.");

	return room
}	

WorldData* CreateInitialWorldData()
{
	WorldData* worldData;

	int roomCount = 7 + 1;

	/* create the new WorldData object with 3 rooms */
	worldData = WorldData_Create("Welcome to my GAM100 Game!\n\n", roomCount);

	/* build each room and assign them to the world data */
	WorldData_SetRoom(worldData, 0, Room0_Build());

	WorldData_SetRoom(worldData, 1, Room1_Build());
	WorldData_SetRoom(worldData, 2, Room2_Build());
	WorldData_SetRoom(worldData, 3, Room3_Build());

	WorldData_SetRoom(worldData, 4, Room4_Build());
	WorldData_SetRoom(worldData, 5, Room5_Build());
	WorldData_SetRoom(worldData, 6, Room6_Build());

	WorldData_SetRoom()

	/* return the new object */
	return worldData;
}