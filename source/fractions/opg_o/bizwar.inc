CMD:bizwar(playerid){
    if(!IsAOpg(playerid) || PlayerInfo[playerid][pRang] < 10) return YouCannotUseThisFunc(playerid);
    if(g_capture[C_STATUS]) return SCM(playerid, red, !"� ������ ������ ��� ���� ����� �� ������.");
    if(g_capture[C_WAIT_TIME] > gettime()) return SCM(playerid, red, !"� ������� ���������� bizwar'a ������ ����� ����.");
    new bizId = -1;
    foreach(new i : Allbusiness){
        if(IsPlayerInRangeOfPoint(playerid, 5.0, BusinessInfo[i][bExitX], BusinessInfo[i][bExitY], BusinessInfo[i][bExitZ])){
            bizId = i;
            break;
        }
    }
    if(bizId == -1)
        return SCM(playerid, red, !"�� ������ ��������� ����� ��������, ������� ������ ���������.");

    if(BusinessInfo[bizId][bControl] == PlayerInfo[playerid][pMember])
        return SCM(playerid, red, !"�� �� ������ ��������� ���� �������.");
    if(BusinessInfo[bizId][bControl] < 1){
        new string[144];
        format(string, sizeof(string), "[R] �� ������� ��������� ������� %s [�%d], ������ �� ����������� ���.", business_params[ BusinessInfo[bizId][bType] ][bname], BusinessInfo[bizId][bID]);
        SCMR(PlayerInfo[playerid][pMember], green, string);
        BusinessInfo[bizId][bControl] = PlayerInfo[playerid][pMember];
        UpdateBusiness(bizId);
        return 1;
    }
    new string[144];
    format(string, sizeof(string), "{ffffff}������ ������� ����������� %s, �� ������� ��� ���������?", FractionInfo[BusinessInfo[bizId][bControl]]);
    ShowPlayerDialog
    (
        playerid, D_BIZ_WAR, DIALOG_STYLE_MSGBOX, !"{"cblue"}������ ��������", string, !"��", !"���"
    );
    SetPVarInt(playerid, "bizwar_biz_id", bizId);
    return 1;
}