CMD:pay(playerid, params[])
{
    extract params -> new to_player, money; else return SCM(playerid, blue, "[���������] {FFFFFF}�����������: /pay [ID ������] [���-�� �����]");
    if(!IsPlayerConnected(to_player) || PlayerInfo[to_player][pLogin] == false) return PlayerOffLine(playerid);
    if(to_player == playerid) return SCM(playerid, red, "�� ������� ���� ID!");
    new Float:x, Float:y, Float:z;
    GetPlayerPos(to_player, x, y, z);
    if(!IsPlayerInRangeOfPoint(playerid, 10.0, x, y, z)) return SCM(playerid, red, "����� ������ �� ���!");
    if(money < 1) return SCM(playerid, blue, "[���������] {FFFFFF}�����������: /pay [ID ������] [���-�� �����]");
    if(PlayerInfo[playerid][pCash] < money) return SCM(playerid, red, "� ��� ��� ������� �����");
    if(PlayerInfo[playerid][bAdmin] < 1 && PlayerInfo[playerid][pVIP] > 0 && money > 50000) return SCM(playerid, red, "�� �� ������ �������� ����� 50.000 ������!");
    if(PlayerInfo[playerid][bAdmin] < 1 && PlayerInfo[playerid][pVIP] < 1 && money > 10000) return SCM(playerid, red, "�� �� ������ �������� ����� 10.000 ������!");
    
    new string[144];
    format(string, sizeof(string), "�� �������� %s %d ������", PlayerInfo[to_player][pName], money);
    SCM(playerid, green, string);

    format(string, sizeof(string), "%s ������� ��� %d ������", PlayerInfo[playerid][pName], money);
    SCM(to_player, green, string);

    format(string, sizeof(string), "���� ������ � ������� �� %s", PlayerInfo[to_player][pName]);
    cmd::me(playerid, string);

    GiveMoney(playerid, -money, "/pay");
    GiveMoney(to_player, money, "/pay");
    return 1;
}