CMD:sellgun(playerid, params[])
{
    if(!IsAOpg(playerid) && PlayerInfo[playerid][pVIP] < 1) return YouCannotUseThisFunc(playerid);

    extract params -> new to_player, patrons, price; else return SCM(playerid, blue, "[���������]: {FFFFFF}����������� /sellgun [ID ������] [���-�� ��������] [����]");
    if(to_player == playerid) return SCM(playerid, red, "�� ������� ���� ID!");
    if(!IsPlayerConnected(to_player) || PlayerInfo[to_player][pLogin] == false) return PlayerOffLine(playerid);
	if(!GetPlayerWeapon(playerid)) return SCM(playerid, red, "�������� � ���� ������, ������� ������ �������!");
	new ammo = GetPlayerAmmo(playerid);
	if(ammo < patrons) return SCM(playerid, red, "� ��� ��� ������� ��������!");
    if(PlayerInfo[to_player][pCash] < price) return SCM(playerid, red, "� ������ �� ���������� �����!");

	SetPVarInt(playerid, "weapon_id", GetPlayerWeapon(playerid));

    return SendProposition(playerid, to_player, PROPOSITION_TYPE_SELLDRUGS, patrons, price);
}