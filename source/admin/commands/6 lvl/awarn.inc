CMD:awarn(playerid, params[])
{
    if(PlayerInfo[playerid][bAdmin] < 6) return ShowCommandNotFound(playerid);

    extract params -> new to_player, string: reason[128]; else return SCM(playerid, yellow, "[���������]: {FFFFFF}����������� /awarn [ID ������] [�������]");
    if(!IsPlayerConnected(to_player) || PlayerInfo[to_player][pLogin] == false) return PlayerOffLine(playerid);
    if(PlayerInfo[to_player][bAdmin] < 1) return SCM(playerid, red, "����� �� �������� ���������������!");

    PlayerInfo[to_player][pWarnA]++;

    new string[128];
    format(string, sizeof(string), "�� ������� �����. ������� %s [%d|3]. �������: %s", PlayerInfo[to_player][pName], PlayerInfo[to_player][pWarnA], reason);
    SCM(playerid, blue, string);

    format(string, sizeof(string), "������������ %s ������ ��� �����. ������� [%d|3]. �������: %s", PlayerInfo[playerid][pName], PlayerInfo[to_player][pWarnA], reason);
    SCM(to_player, white, string);

    format(string, sizeof(string), "[A] %s[%d] ������ �����. ������� %s[%d] [%d|3]. �������: %s", PlayerInfo[playerid][pName], playerid, PlayerInfo[to_player][pName], to_player, PlayerInfo[to_player][pWarnA], reason);
    SCMA(grey, string);

    if(PlayerInfo[to_player][pWarnA] >= 3) 
    {
        format(string, sizeof(string), "%s ��� ���� � ����� ��������������. �������: 3 ��������", PlayerInfo[to_player][pName]);
        SCM(playerid, blue, string);

        format(string, sizeof(string), "�� ���� ����� � ����� ��������������. �������: 3 ��������");
        SCM(to_player, white, string);

        PlayerInfo[to_player][bAdmin] = 0;
        PlayerInfo[to_player][pMember] = 0;
        PlayerInfo[to_player][pWarnA] = 0;
        PlayerInfo[to_player][pRang] = 0;
        PlayerInfo[to_player][pFSkin] = -1;
        SetPlayerSkin(to_player, PlayerInfo[to_player][pChar]);
    }
    SaveAccounts(to_player);
    return 1;
}