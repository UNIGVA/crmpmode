new TMask[MAX_PLAYERS];

CMD:mask(playerid)
{
    if(PlayerInfo[playerid][pMask] <= 0) return SCM(playerid, red, "� ��� ��� �����!");
    if(GetPVarInt(playerid, "pMask") == 1) return SCM(playerid, red, "�� ��� ��� ������ �����!");

    PlayerInfo[playerid][pMask]--;
    SetPlayerColor(playerid, 0xFFFFFF00);
    ApplyAnimation(playerid, "SHOP","ROB_Shifty", 4.0, false, 0, 0, 0, 0);
    cmd::me(playerid, "����� �����");
    SetPVarInt(playerid, "pMask", 1);
    SCM(playerid, blue, "�� ������ ����� �����! ���� �������������� ������ �� 10 �����!");
    TMask[playerid] = SetTimerEx("PlayerMask", 1000*60*10, false, "i", playerid);
    return 1;
}

publics PlayerMask(playerid)
{
    SetPlayerColor(playerid, 0xFFFFFFFF);
    SCM(playerid, blue, "10 ����� ������, � ��� ���� ����� �����.");
    DeletePVar(playerid, "pMask");
    return 1;
}