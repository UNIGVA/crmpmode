CMD:delveh(playerid,params[])
{
	if(PlayerInfo[playerid][bAdmin] < 4 && PlayerInfo[playerid][bYoutube] == 0) return ShowCommandNotFound(playerid);
	if(!TotalAdminVehicles) return 1;
	new vehh = -1;
	if(!strlen(params)){
		if(GetPlayerState(playerid) != 2) return SCM(playerid,  red, "�� �� � ����������.");
		vehh = GetPlayerVehicleID(playerid);
	}
	else{
		extract params -> new id; else return SCM(playerid, blue, "[���������]: {FFFFFF}����������� /delveh [ID ����������]");
		if(!IsValidVehicle(id))
			return SCM(playerid, red, "���� ��� ����� ID ���!");
		vehh = id;
	}
	new slot = -1;
	for(new i = 0; i < TotalAdminVehicles; i++)
	{
	    if(vehh == AVehicle[i])
	    {
	    	slot=i;
	    	break;
	    }

	}
	if(slot == -1) return SCM(playerid,  red, "���� ���������� �� �������� �������������");
	stringer[0] = EOS;
	format(stringer, 128, "[A] %s ������ ���������� [model: %d] [vehicleid: %d]", PlayerInfo[playerid][pName],GetVehicleModel(AVehicle[slot]),AVehicle[slot]);
	SCMA(grey, stringer);
	if(IsValidVehicle(AVehicle[slot]))
	{
		DestroyVehicle(AVehicle[slot]);
		vehicle[AVehicle[slot]][veh_limit] = 0.0;
	}
	AVehicle[slot] = 0;
    TotalAdminVehicles--;
	return 1;
}