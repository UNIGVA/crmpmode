CMD:gov(playerid, params[])
{
    if(PlayerInfo[playerid][pMember] < 1 || PlayerInfo[playerid][pRang] < 8) return YouCannotUseThisFunc(playerid);
    if(IsAOpg(playerid)) return YouCannotUseThisFunc(playerid);
    if(PlayerInfo[playerid][pMute] > 0) return SCM(playerid, red, "� ������ ������ � ��� ���������� ����!");

    extract params -> new string: text[144]; else return SCM(playerid, yellow, "[���������]: {FFFFFF}����������� /gov [�����]");

    new string[128];
    format(string, sizeof(string), "���. ������� %s[%d]: %s", PlayerInfo[playerid][pName], playerid, text);
    return SCMTA(0x4466CCFF, string);
}