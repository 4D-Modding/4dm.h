#pragma once

#include "4dm.h"

namespace fdm
{
	namespace Packet
	{
		enum ClientPacket : uint16_t
		{
			// the login details packet must always be the first one,
			// so that when players join with the wrong client version,
			// they will always get the correct error message.
			C_LOGIN_DETAILS = 0,
			C_SKIN_DATA,
			C_JOIN,
			C_REJOIN,
			C_CHAT_MESSAGE,
			C_BLOCK_BREAK_START,
			C_BLOCK_BREAK_CANCEL,
			C_BLOCK_BREAK_FINISH,
			C_MOVEMENT_UPDATE,
			C_RENDER_DIST,
			C_CHUNK_REQUEST,
			C_ENTITY_REQUEST,
			C_PLAYER_SKIN_REQUEST,
			C_HOTBAR_SLOT_SELECT,
			C_INVENTORY_ACTION,
			C_INVENTORY_OPEN,
			C_ITEM_COLLECT,
			C_ITEM_THROW_HOTBAR,
			C_ITEM_THROW_CURSOR,
			// when the local EntityPlayer performs an action on another entity
			//C_ENTITY_ACTION,
			C_ITEM_ACTION,
			C_ITEM_ACTION_ENTITY,
			C_HITTING_START,
			C_HITTING_STOP,
			C_ACTION_START,
			C_ACTION_STOP,
			C_CROUCH_START,
			C_CROUCH_STOP,
			C_JUMP,
			C_LOOK,
		};
		enum ServerPacket : uint16_t
		{
			// the invalid version packet must always be the first one,
			// so that when players join with the wrong client version,
			// they will always get the correct error message.
			S_ERROR_VERSION_INVALID = 0,
			S_ERROR_SERVER_FULL,
			S_ERROR_UUID_INVALID,
			S_ERROR_UUID_ALREADY_LOGGED_IN,
			S_LOGIN_SUCCESS,
			S_QUEUE_STATUS,
			S_DEATH,
			S_CHAT_MESSAGE_SERVER,
			S_CHAT_MESSAGE_PLAYER,
			S_CHUNK_DATA,
			//S_CHUNK_UNLOAD,
			S_ENTITY_DATA,
			S_ENTITY_KILL,
			S_ENTITY_UPDATE,
			S_ENTITY_ACTION,
			S_ENTITY_TRANSFER,
			S_BLOCK_UPDATE,
			S_RENDER_DIST,
			S_HOTBAR_SLOT_SELECT,
			S_INVENTORY_ACTION,
			S_INVENTORY_UPDATE,
			S_ITEM_ACTION,
			S_ITEM_ACTION_ENTITY,
			S_ITEM_COLLECT,
			S_ITEM_THROW_HOTBAR,
			S_ITEM_THROW_CURSOR,
			S_PLAYER_SKIN_DATA,
			S_PLAYER_MOVEMENT_UPDATE,
			S_PLAYER_EQUIP,
			S_PLAYER_BLOCK_BREAK_START,
			S_PLAYER_BLOCK_BREAK_STOP,
			//S_PLAYER_PLACE,
			S_PLAYER_HITTING_START,
			S_PLAYER_HITTING_STOP,
			S_PLAYER_ACTION_START,
			S_PLAYER_ACTION_STOP,
			S_PLAYER_CROUCH_START,
			S_PLAYER_CROUCH_STOP,
			S_PLAYER_JUMP,
			S_PLAYER_LOOK,
			S_CHUNK_UPDATE,
		};
	}
}