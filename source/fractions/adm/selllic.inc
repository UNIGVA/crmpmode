CMD:selllic(playerid, params[])
{
    if(PlayerInfo[playerid][pMember] != TEAM_ADM) return YouCannotUseThisFunc(playerid);

    extract params -> new to_player, type; else return SCM(playerid, blue, "[���������]: {FFFFFF}����������� /selllic [ID ������] [��� ��������]");

    if(!IsPlayerConnected(to_player) || PlayerInfo[to_player][pLogin] != true) return PlayerOffLine(playerid);
    if(type > 3 || type < 1) return SCM(playerid, red, "�� ������ 3 � �� ����� 1!");
    if(PlayerInfo[to_player][pCash] < lic_price[type]) return SCM(playerid, red, "� ������ ������������ �����!");
    if(playerid == to_player) return SCM(playerid, red, "�� ������� ���� ID!");

    return SendProposition(playerid, to_player, PROPOSITION_TYPE_SELLLIC, type);
}