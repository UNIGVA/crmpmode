CMD:drink(playerid)
{
    if(PlayerInfo[playerid][pBeer] <= 0) return SCM(playerid, red, "� ��� ��� ����!");
    if(PlayerInfo[playerid][pNeedDrink] + 10 > 100) return SCM(playerid, red, "�� �� ������ ����!");

    PlayerInfo[playerid][pBeer]--;
    PlayerInfo[playerid][pNeedToilet] -= 8;
    if(PlayerInfo[playerid][pNeedToilet] < 0) PlayerInfo[playerid][pNeedToilet] = 0;
    PlayerInfo[playerid][pNeedDrink] += 10;
    SetPlayerSpecialAction(playerid, SPECIAL_ACTION_DRINK_BEER);
    return SCM(playerid, blue, "�� ������ ����, ��� ����� ������� �����!");
}