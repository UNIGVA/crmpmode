CMD:switchskin(playerid, params[]){
    if(PlayerInfo[playerid][pMember] != TEAM_FSB) return YouCannotUseThisFunc(playerid);
    extract params -> new skin_id; else return SCM(playerid, blue, "[���������]: {FFFFFF}����������� /switchskin [ID ����� (1 - 300)]");
    if(skin_id < 1 || skin_id > 299) return SCM(playerid, red, "����������� ����� �� 0 �� 299.");
    cmd::me(playerid, "����������");
    SCM(playerid, blue, "�� �����������. �� �������� ����� ���������� ������� � �����.");
    return SetPlayerSkin(playerid, skin_id);
}