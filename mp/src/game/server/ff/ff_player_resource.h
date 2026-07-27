//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose: Fortress Forever's CPlayerResource
//
// $NoKeywords: $
//=============================================================================//

#ifndef FF_PLAYER_RESOURCE_H
#define FF_PLAYER_RESOURCE_H
#ifdef _WIN32
#pragma once
#endif

#include "ff_player_shared.h"

class CFFPlayerResource : public CPlayerResource, public CGameEventListener
{
	DECLARE_CLASS( CFFPlayerResource, CPlayerResource );

public:
	DECLARE_SERVERCLASS();

	CFFPlayerResource();

	virtual void FireGameEvent( IGameEvent *event );

	virtual void UpdatePlayerData( void );
	virtual void Spawn( void );

	int	GetTotalScore( int iIndex );

	void SetEventTeamStatus( int iValue ) { m_iEventTeamStatus = iValue; }
	uint32 GetEventTeamStatus( void ) { return m_iEventTeamStatus; }

	void SetPlayerClassWhenKilled( int iIndex, int iClass );

protected:
	virtual void UpdateConnectedPlayer( int iIndex, CBasePlayer *pPlayer ) OVERRIDE;
	virtual void UpdateDisconnectedPlayer( int iIndex ) OVERRIDE;

	CNetworkArray( int, m_iFortPoints, MAX_PLAYERS + 1 );
	CNetworkArray( int, m_iArmor, MAX_PLAYERS + 1 );
	CNetworkArray( int, m_iClass, MAX_PLAYERS + 1 );	// |-- Mirv: Class info

	CNetworkArray( int, m_iChannel, MAX_PLAYERS + 1 );	// |-- Mirv: Channel info
	CNetworkArray( int, m_iAssists, MAX_PLAYERS + 1 );
	CNetworkVar( bool, m_bIsIntermission );
};

#endif // FF_PLAYER_RESOURCE_H
