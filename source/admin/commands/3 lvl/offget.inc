CMD:offget(playerid, params[])
{
    if(PlayerInfo[playerid][bAdmin] < 3) return ShowCommandNotFound(playerid);

    extract params -> new string: to_player[24]; else return SCM(playerid, blue, "[���������] {FFFFFF}�����������: /offget [NICK ������]");

    for(new i = 0; i < sizeof(SuperNick_S); i++) if(!strcmp(to_player, SuperNick_S[i], true)) return SCM(playerid, red, "�� �� ������ ���������� ���������� ������� ������!");

    foreach(new i : Player)
    {
        if(!strcmp(PlayerInfo[i][pName], to_player))
        {
            return SCM(playerid, red, "����� �� �������! {FFFFFF}����������� /stat [ID ������]");
        }
    }

    new string[128];
    format(string, sizeof(string), "SELECT * FROM `accounts` WHERE `pName` = '%s'", to_player);
    mysql_tquery(connects, string, "OffGet", "ds", playerid, to_player);
    return 1;
}

publics OffGet(playerid, to_player[])
{
    new rows, fields;
    cache_get_data(rows, fields);
    if(rows)
    {
        new lvl, cash, bmoney, ip[16];

        
        lvl = cache_get_field_content_int(0, "pLVL");
        cash = cache_get_field_content_int(0, "pCash");
        bmoney = cache_get_field_content_int(0, "pBCash");
        cache_get_field_content(0, "pLastIP", ip, connects, 144);


        new string[256];
        format(string, sizeof(string), "{FFFFFF}��� ������: %s\n������� ������: %d\n���-�� �����: %d\n���-�� ����� � �����: %d\nLast IP: %s", to_player, lvl, cash, bmoney, ip);

        SPD(playerid, D_NULL, DIALOG_STYLE_MSGBOX, "{"cblue"}���������� ������ OffLine", string, "�������", "");
    }
    else
    {
        SCM(playerid, red, "������ ������ ���!");
    }
}

