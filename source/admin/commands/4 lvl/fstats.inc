CMD:fstats(playerid)
{
    if(PlayerInfo[playerid][bAdmin] < 4) return ShowCommandNotFound(playerid);

    new adm, smi, pps, heal, vdv, opg_o, opg_s, fsb;
    new bus, taxi, mech, truck;
    foreach(new i : Player)
    {
        switch(PlayerInfo[i][pMember])
        {
            case 1: adm++;
            case 2: smi++;
            case 3: pps++;
            case 4: heal++;
            case 5: vdv++;
            case 6: opg_o++;
            case 7: opg_s++;
            case 8: fsb++;
        }
        switch(PlayerInfo[i][pJob])
        {
            case 1: bus++;
            case 2: taxi++;
            case 3: mech++;
            case 4: truck++;
        }
    }
    new string[512];
    format(string, sizeof(string), "\
    {FFFFFF}������������� ������: %d\n\
    ���: %d\n\
    �������: %d\n\
    ��������: %d\n\
    ���: %d\n\
    ��� ����������: %d\n\
    ��� �����������: %d\n\
    ���: %d\n\n\
    �������� ��������: %d\n\
    ��������: %d\n\
    ������������: %d\n\
    �������������: %d", adm, smi, pps, heal, vdv, opg_o, opg_s, fsb, bus, taxi, mech, truck);
    return SPD(playerid, D_NULL, DIALOG_STYLE_MSGBOX, "{"cblue"}���������� �����/�����������", string, "�������", "");
}