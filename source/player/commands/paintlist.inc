CMD:paintlist(playerid)
{
    new all = 0, string[144], fmt_dialog[2048] = "����� | ��� ������\t\t���-�� �������\n\n";
    foreach(new i : Player)
    {
        if(PlayerInfo[i][pPaintKills] > 0) 
        {
            all++;
            format(string, sizeof(string), "{"cblue"}%d. {FFFFFF}%s\t\t%d �������.\n", all, PlayerInfo[i][pName], PlayerInfo[i][pPaintKills]);
            strcat(fmt_dialog, string);
        }
    }
    if(all == 0) return SPD(playerid, D_NULL, DIALOG_STYLE_MSGBOX, "{"cblue"}�����-���", "{FFFFFF}������ ���������� �����-���� ����", "�������", "");
    return SPD(playerid, D_NULL, DIALOG_STYLE_MSGBOX, "{"cblue"}�����-���", fmt_dialog, "�������", "");
}