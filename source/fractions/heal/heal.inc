CMD:heal(playerid, params[])
{
    if(PlayerInfo[playerid][pMember] != TEAM_HEAL) return YouCannotUseThisFunc(playerid);

    extract params -> new to_player, price; else return SCM(playerid, yellow, "[���������]: {FFFFFF}����������� /heal [ID ������] [����]");

    if(!IsPlayerConnected(to_player) || PlayerInfo[to_player][pLogin] == false) return PlayerOffLine(playerid);
    if(price < 100 || price > 500) return SCM(playerid, red, "���� �� ����� 100 � �� ����� 500 ������!");
    if(PlayerInfo[to_player][pCash] < price) return SCM(playerid, red, "� ������ ��� ������� �����!");
    if(to_player == playerid) return SCM(playerid, red, "�� ������� ���� ID!");

    return SendProposition(playerid, to_player, PROPOSITION_TYPE_HEAL, price);
}