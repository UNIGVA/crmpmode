CMD:resetgun(playerid, params[])
{
    extract params -> new to_player; else return SCM(playerid, blue, "[���������] {FFFFFF}�����������: /resetgun [ID ������]");
    if(!IsPlayerConnected(to_player) || PlayerInfo[to_player][pLogin] == false) return PlayerOffLine(playerid);

    ResetPlayerWeaponsAC(to_player);
    new string[144];
    format(string, sizeof(string), "[A] %s[%d] ������ �� ������ � ������ %s[%d]", PlayerInfo[playerid][pName], playerid, PlayerInfo[to_player][pName], to_player);
    SCMA(grey, string);

    format(string, sizeof(string), "������������� %s ������ � ��� �� ������", PlayerInfo[playerid][pName]);
    SCM(to_player, white, string);
    return 1;
}