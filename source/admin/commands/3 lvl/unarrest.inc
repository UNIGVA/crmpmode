CMD:unarrest(playerid, params[]){
    if(PlayerInfo[playerid][bAdmin] < 3) 
        return ShowCommandNotFound(playerid);
    extract params -> new to_player; else return SCM(playerid, blue, !"[���������]: {FFFFFF}����������� /unarrest [ID ������]");
    if(!IsPlayerConnected(to_player) || !PlayerInfo[to_player][pLogin])
        return PlayerOffLine(playerid);
    if(PlayerInfo[to_player][pKPZ] < 1)
        return SCM(playerid, red, !"������ ����� �� ��������� � ���.");

    PlayerInfo[to_player][pKPZ] = -1;
    SaveAccounts(to_player);
    SetSpawnVokzal(to_player);

    new string[144];
    format(string, sizeof(string), "������������� %s �������� ��� �������� �� ���.", PlayerInfo[playerid][pName]);
    SCM(to_player, white, string);

    format(string, sizeof(string), "�� ��������� ������ %s �� ��� ��������.", PlayerInfo[to_player][pName]);
    SCM(to_player, white, string);

    format(string, sizeof(string), "[A] ������������� %s[%d] �������� �������� ������ %s[%d] �� ���.", PlayerInfo[playerid][pName], playerid, PlayerInfo[to_player][pName], to_player);
    SCMA(grey, string);
    return 1;
}