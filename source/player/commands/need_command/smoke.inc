CMD:smoke(playerid)
{
    if(PlayerInfo[playerid][pLighter] <= 0) return SCM(playerid, red, "� ��� ��� ���������!");
    if(PlayerInfo[playerid][pSmoke] <= 0) return SCM(playerid, red, "� ��� ��� �������!");
    
    GetPlayerHealth(playerid, PlayerInfo[playerid][pHP]);
    
    if( PlayerInfo[playerid][pHP] + 10 > 100) return SCM(playerid, red, "��� �� ����� ������ ������!");

    PlayerInfo[playerid][pLighter]--;
    PlayerInfo[playerid][pSmoke]--;
    PlayerInfo[playerid][pHP] += 10;
    SetPlayerHealth(playerid, PlayerInfo[playerid][pHP]);
    GameTextForPlayer(playerid, "~g~ +10 HP", 3000, 1);
    SetPlayerSpecialAction(playerid, SPECIAL_ACTION_SMOKE_CIGGY);
    return 1;
}