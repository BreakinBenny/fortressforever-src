//	=============== Fortress Forever ==============
//	======== A modification for Half-Life 2 =======
//
//	@file c_ff_materialproxies.h
//	@author Patrick O'Leary (Mulchman)
//	@date 09/23/2005
//	@brief Fortress Forever Material Proxies
//
//	REVISIONS
//	---------
//	09/23/2005,	Mulchman: 
//		First created
//
//	08/10/2006, Mulchman:
//		Removed some unneeded stuff. I don't think a
//		couple of these are used anymore, though.
//
// 04/11/2007, Mulchman:
//		Adding team score mat proxies

#ifndef FF_MATERIALPROXIES_H
#define FF_MATERIALPROXIES_H

#include "materialsystem/imaterialproxy.h"
#include "functionproxy.h"

// Forward declarations
class IMaterialVar;
enum MaterialVarType_t;
class C_BaseEntity;

#include "c_ff_player.h"

//=============================================================================
//
//	class C_TeamColorMaterialProxy
//
//=============================================================================

// Generic TeamColor material proxy. Provides basic functionality
// for easily adding additional team colored proxies. Just supply
// an appropriate $value that will get modified and appropriate
// names of the team color values (in the .vmt).
class C_TeamColorMaterialProxy : public IMaterialProxy
{
public:
	C_TeamColorMaterialProxy(void);
	virtual ~C_TeamColorMaterialProxy(void);
	virtual bool Init(IMaterial* pMaterial, KeyValues* pKeyValues);
	virtual void OnBind(void* pC_BaseEntity);
	virtual void Release(void) { delete this; }
	IMaterial* GetMaterial(void) { return m_pValue->GetOwningMaterial(); };

	// is this a good idea?
	friend class C_Color_TeamColorMaterialProxy;

private:
	// Actual $ value we will be modifying in the .vmt to adjust
	// the team coloring
	IMaterialVar* m_pValue;

	// Array of vectors to hold the team coloring values
	// that are read in from the .vmt
	// 0 = blue
	// 1 = red
	// 2 = yellow
	// 3 = green
	Vector			m_vecTeamColorVals[4];

protected:
	// This gets overridden by the super class
	const char** m_ppszStrings;

};

//=============================================================================
//
//	class C_Color_TeamColorMaterialProxy
//
//=============================================================================
class C_Color_TeamColorMaterialProxy : public C_TeamColorMaterialProxy
{
public:
	C_Color_TeamColorMaterialProxy(void);
	bool Init(IMaterial* pMaterial, KeyValues* pKeyValues);

};

//=============================================================================
//
//	class C_Refract_TeamColorMaterialProxy
//
//=============================================================================
class C_Refract_TeamColorMaterialProxy : public C_TeamColorMaterialProxy
{
public:
	C_Refract_TeamColorMaterialProxy(void);

};

//=============================================================================
//
//	class C_FFPlayerVelocityMaterialProxy
//
//=============================================================================
class C_FFPlayerVelocityMaterialProxy : public CResultProxy
{
	//-------------------------------------------------------------------------
	// Purpose: Can get the velocity of the player the material is applied to
	// (not just for the local player!)
	//-------------------------------------------------------------------------

public:
	C_FFPlayerVelocityMaterialProxy(void);
	virtual ~C_FFPlayerVelocityMaterialProxy(void);

	virtual bool Init(IMaterial* pMaterial, KeyValues* pKeyValues);
	virtual void OnBind(void* pC_BaseEntity);

};

//=============================================================================
//
//	class C_FFLocalPlayerVelocityMaterialProxy
//
//=============================================================================
class C_FFLocalPlayerVelocityMaterialProxy : public CResultProxy
{
	//-------------------------------------------------------------------------
	// Purpose: Gets local players' velocity
	//-------------------------------------------------------------------------

public:
	C_FFLocalPlayerVelocityMaterialProxy(void);
	virtual ~C_FFLocalPlayerVelocityMaterialProxy(void);

	virtual bool Init(IMaterial* pMaterial, KeyValues* pKeyValues);
	virtual void OnBind(void* pC_BaseEntity);

};

//=============================================================================
//
//	class C_FFWeaponVelocityMaterialProxy
//
//=============================================================================
class C_FFWeaponVelocityMaterialProxy : public CResultProxy
{
	//-------------------------------------------------------------------------
	// Purpose: Can get the velocity of the player who owns the weapon this
	// material is applied to (not just for the local player!)
	//-------------------------------------------------------------------------

public:
	C_FFWeaponVelocityMaterialProxy(void);
	virtual ~C_FFWeaponVelocityMaterialProxy(void);

	virtual bool Init(IMaterial* pMaterial, KeyValues* pKeyValues);
	virtual void OnBind(void* pC_BaseEntity);

};

//=============================================================================
//
//	class C_FFSpyCloakMaterialProxy
//
//=============================================================================
class C_FFSpyCloakMaterialProxy : public CResultProxy
{
public:
	C_FFSpyCloakMaterialProxy(void);
	virtual ~C_FFSpyCloakMaterialProxy(void);

	virtual bool Init(IMaterial* pMaterial, KeyValues* pKeyValues);
	virtual void OnBind(void* pC_BaseEntity);

};

//=============================================================================
//
//	class C_FFTeamScore_MaterialProxy
//
//=============================================================================
class C_FFTeamScore_MaterialProxy : public CResultProxy
{
public:
	C_FFTeamScore_MaterialProxy(void);

	virtual bool Init(IMaterial* pMaterial, KeyValues* pKeyValues);
	virtual void OnBind(void* pC_BaseEntity);

protected:
	int m_iTeam;
};

//=============================================================================
//
//	class C_FFTeamScore_Blue_MaterialProxy
//
//=============================================================================
class C_FFTeamScore_Blue_MaterialProxy : public C_FFTeamScore_MaterialProxy
{
public:
	C_FFTeamScore_Blue_MaterialProxy(void)
	{
		m_iTeam = FF_TEAM_BLUE;
	}
};

//=============================================================================
//
//	class C_FFTeamScore_Red_MaterialProxy
//
//=============================================================================
class C_FFTeamScore_Red_MaterialProxy : public C_FFTeamScore_MaterialProxy
{
public:
	C_FFTeamScore_Red_MaterialProxy(void)
	{
		m_iTeam = FF_TEAM_RED;
	}
};

//=============================================================================
//
//	class C_FFTeamScore_Yellow_MaterialProxy
//
//=============================================================================
class C_FFTeamScore_Yellow_MaterialProxy : public C_FFTeamScore_MaterialProxy
{
public:
	C_FFTeamScore_Yellow_MaterialProxy(void)
	{
		m_iTeam = FF_TEAM_YELLOW;
	}
};

//=============================================================================
//
//	class C_FFTeamScore_Green_MaterialProxy
//
//=============================================================================
class C_FFTeamScore_Green_MaterialProxy : public C_FFTeamScore_MaterialProxy
{
public:
	C_FFTeamScore_Green_MaterialProxy(void)
	{
		m_iTeam = FF_TEAM_GREEN;
	}
};

#endif // FF_MATERIALPROXIES_H
