/*
 * Ascent MMORPG Server
 * Copyright (C) 2005-2010 Ascent Team <http://www.ascentemulator.net/>
 *
 * This software is  under the terms of the EULA License
 * All title, including but not limited to copyrights, in and to the AscentNG Software
 * and any copies there of are owned by ZEDCLANS INC. or its suppliers. All title
 * and intellectual property rights in and to the content which may be accessed through
 * use of the AscentNG is the property of the respective content owner and may be protected
 * by applicable copyright or other intellectual property laws and treaties. This EULA grants
 * you no rights to use such content. All rights not expressly granted are reserved by ZEDCLANS INC.
 *
 */

#ifndef _VEHICLE_H
#define _VEHICLE_H

class SERVER_DECL Vehicle : public Creature
{
public:
	Vehicle(uint64 guid);
	~Vehicle();

	void InitSeats(uint32 vehicleEntry, Player* pRider = NULL);
	virtual void Update(uint32 time);
	bool Load(CreatureSpawn *spawn, uint32 mode, MapInfo *info);
	void Load(CreatureProto * proto_, float x, float y, float z, float o = 0.0f);
	void OnPushToWorld();
	void Despawn(uint32 delay, uint32 respawntime);
	void DeleteMe();
	void SafeDelete();
	void MoveVehicle(float x, float y, float z, float o);
	void AddPassenger(Unit* pPassenger);
	void AddPassenger(Unit* pPassenger, uint8 requestedseat, bool force = false);
	void RemovePassenger(Unit* pPassenger);
	void RemoveAllPassengers();
	bool HasPassenger(Unit* pPassenger);
	void SendSpells(uint32 entry, Player* plr);
	void setDeathState(DeathState s);
	void SetSpeed(PlayerSpeedType SpeedType, float value);
	void ChangeSeats(Unit* pPassenger, uint8 seatid);
	void ChangePowerType();
	uint32 GetVehiclePowerType() { return (vehicleData ? vehicleData->powerType : 0); };
	uint16 GetMoveFlags2() const;

		
	////////////////////////////////////////////////////////////////////////
	//void MovePassengerToNextSeat(Unit* passenger)
	//  Moves the specified passenger to the next seat
	//
	//Parameter(s)
	//  Unit* passenger  -  Pointer to the passnger we want to move
	//
	//Return Value
	//  None
	//
	//
	////////////////////////////////////////////////////////////////////////
	void MovePassengerToNextSeat(Unit* passenger);

	////////////////////////////////////////////////////////////////////////
	//void MovePassengerToPrevSeat(Unit* passenger)
	//  Moves the specified passenger to the previous seat
	//
	//Parameter(s)
	//  Unit* passenger  -  Pointer to the passenger we want to move
	//
	//Return Value
	//  None
	//
	//
	////////////////////////////////////////////////////////////////////////
	void MovePassengerToPrevSeat(Unit* passenger);
	//---------------------------------------
	// Accessors
	//---------------------------------------
	uint32 GetMaxPassengerCount() { return m_maxPassengers; }
	uint32 GetPassengerCount() { return m_passengerCount; }

	uint32 GetVehicleEntry() { return m_vehicleEntry; }
	void SetVehicleEntry(uint32 entry) { m_vehicleEntry = entry; }
	VehicleSeatEntry* GetVehicleSeatEntry(uint8 slot) { return m_vehicleSeats[slot]; } 

	Unit* GetControllingUnit() { return m_passengers[0]; }
	void SetControllingUnit(Unit* pUnit) { m_controllingUnit = pUnit; }

	int8 GetMaxSeat() { return m_seatSlotMax; }
	Unit* GetPassenger(uint8 seat)
	{
		if(seat >= 8)
			return NULL;

		return m_passengers[seat] ? m_passengers[seat] : NULL;
	}

	uint8 GetPassengerSlot(Unit* pPassenger);
	//---------------------------------------
	// End accessors
	//---------------------------------------

	bool IsFull() { return m_passengerCount == m_maxPassengers; }


	bool Initialised;
	bool m_CreatedFromSpell;
	uint32 m_mountSpell;
	

protected:
	void _BuildMovementUpdate( ByteBuffer *data, Player* target );
	void _AddToSlot(Unit* pPassenger, uint8 slot);

	void SendMsgMoveTeleportAck( WorldPacket &data, Player* plr );
	void SendMonsterMoveTransport( Unit* pPassenger, uint8 slot );
	Unit* m_controllingUnit;

	Unit* m_passengers[8];
	uint8 m_passengerCount;
	uint8 m_maxPassengers;
	int8 m_seatSlotMax;
	uint32 m_vehicleEntry;
	VehicleSeatEntry * m_vehicleSeats[8];
	VehicleEntry* vehicleData;
};

#endif