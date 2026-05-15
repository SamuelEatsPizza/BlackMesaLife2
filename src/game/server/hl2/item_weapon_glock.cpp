//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose: Handling for the suit batteries.
//
// $NoKeywords: $
//=============================================================================//

#include "cbase.h"
#include "hl2_player.h"
#include "basecombatweapon.h"
#include "gamerules.h"
#include "items.h"
#include "engine/IEngineSound.h"

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

class CItemGlock : public CItem
{
public:
	DECLARE_CLASS(CItemGlock, CItem);

	void Spawn(void)
	{
		Precache();
		SetModel("models/weapons/w_glock.mdl");
		BaseClass::Spawn();
	}
	void Precache(void)
	{
		PrecacheModel("models/weapons/w_glock.mdl");

		PrecacheScriptSound("ItemBattery.Touch");

	}
	bool MyTouch(CBasePlayer* pPlayer)
	{
		pPlayer->GiveNamedItem("weapon_glock");
		UTIL_Remove(this);
		return true;
	}
};

LINK_ENTITY_TO_CLASS(item_weapon_glock, CItemGlock);
PRECACHE_REGISTER(item_weapon_glock);

