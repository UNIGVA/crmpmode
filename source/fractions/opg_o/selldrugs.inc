CMD:selldrugs(playerid, params[])
{
    if(!IsAOpg(playerid) && PlayerInfo[playerid][pVIP] < 1) return YouCannotUseThisFunc(playerid);

    extract params -> new to_player, patrons, price; else return SCM(playerid, blue, "[���������]: {FFFFFF}����������� /selldrugs [ID ������] [��. ����������] [����]");
    if(to_player == playerid) return SCM(playerid, red, "�� ������� ���� ID!");
    if(!IsPlayerConnected(to_player) || PlayerInfo[to_player][pLogin] == false) return PlayerOffLine(playerid);
	if(PlayerInfo[playerid][pDrugs] < patrons) return SCM(playerid, red, "� ��� ��� ������� ����������!");
    if(PlayerInfo[to_player][pCash] < price) return SCM(playerid, red, "� ������ �� ���������� �����!");

    return SendProposition(playerid, to_player, PROPOSITION_TYPE_SELLDRUGS, patrons, price);
}