CMD:pepsi(playerid)
{
    if(PlayerInfo[playerid][pPepsi] <= 0) return SCM(playerid, red, "� ��� ��� �����!");
    if(PlayerInfo[playerid][pNeedDrink] + 5 > 100) return SCM(playerid, red, "�� �� ������ ����!");

    PlayerInfo[playerid][pPepsi]--;
    PlayerInfo[playerid][pNeedToilet] -= 4;
    if(PlayerInfo[playerid][pNeedToilet] < 0) PlayerInfo[playerid][pNeedToilet] = 0;
    PlayerInfo[playerid][pNeedDrink] += 5;
    SetPlayerSpecialAction(playerid, SPECIAL_ACTION_DRINK_SPRUNK);
    return SCM(playerid, blue, "�� ������ �����, ��� ����� ������� �����!");
}