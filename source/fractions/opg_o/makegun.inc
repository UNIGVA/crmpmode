enum
    E_GUN_DATA
{
	makegun_name[32],
	gun_metal,
	gun_id
};

new const
    gunlist[][E_GUN_DATA] =
{
	{"��������", 15, 22},
	{"�������� � ����������", 12, 23},
	{"Desert Eagle", 15, 24},
	{"���-9", 15, 32},
	{"���", 17, 28},
	{"��5", 20, 29},
	{"��������", 17, 25},
	{"�����", 20, 26},
	{"������ ��������", 25, 27},
	{"��-47", 25, 30},
	{"�4", 30, 31},
	{"Country Rifle", 20, 34},
	{"Sniper Rifle", 30, 33}
};

CMD:makegun(playerid)
{
    if(!IsAOpg(playerid) && PlayerInfo[playerid][pVIP] < 1) return YouCannotUseThisFunc(playerid);

    ShowPlayerDialogCreateGun(playerid);
    return 1;
}

stock ShowPlayerDialogCreateGun(playerid)
{
	new old_gun;
	new count;
	new fmt_str[80];
	new text[(sizeof fmt_str) * 10];

	for(new i; i < 12; i++)
	{
		if(old_gun == gunlist[i][gun_id]) continue;

		dialog_listitem_values[playerid][count] = i;
		count ++;

		old_gun = gunlist[i][gun_id];

		format(fmt_str, sizeof fmt_str, "{"cblue"}%d. {ffffff}%s{"cblue"}(%d �������)\n", i+1, gunlist[i][makegun_name], gunlist[i][gun_metal]);
		strcat(text, fmt_str);
	}

	SPD(playerid, D_CREATE_GUN, DIALOG_STYLE_LIST, "{"cblue"}�������� ������", text, "�������", "������");
	return 1;
}


public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch(dialogid)
    {
        case D_MAKEGUN_PATRONS:
        {
            if(!response) return ShowPlayerDialogCreateGun(playerid);
            else
            {
                if(!strlen(inputtext) || !IsNumeric(inputtext)) return SPD(playerid, D_MAKEGUN_PATRONS, DIALOG_STYLE_INPUT, !"{"cblue"}�������� ������ | �������", !"{FFFFFF}������� ���������� ��������, ������� ������ ��������� � ������:", !"�����", !"�����");
                if(PlayerInfo[playerid][pPatr] < strval(inputtext)) return SPD(playerid, D_MAKEGUN_PATRONS, DIALOG_STYLE_INPUT, !"{"cblue"}�������� ������ | �������", !"{"cred"}� ��� ��� ������ ���������� ��������!\n\n{FFFFFF}������� ���������� ��������, ������� ������ ��������� � ������!", !"�����", !"�����");
            
                new i = dialog_listitem[playerid];
                new string[144];
                format(string, sizeof(string), "{"cblue"}�� ������� {"cyellow"}%s {"cblue"}� ������� ��������� {"cyellow"}%d {"cblue"}������", gunlist[i][makegun_name], strval(inputtext));
                SCM(playerid, blue, string);

                GivePlayerWeaponAC(playerid, gunlist[i][gun_id], strval(inputtext));
                PlayerInfo[playerid][pMetall] -= gunlist[i][gun_metal];
            }
        }
        case D_CREATE_GUN:
        {
            if(!response) return 1;
            else
            {
                switch(listitem)
                {
                    case 0:
                    {
                        if(PlayerInfo[playerid][R_9MM] < 1) return SCM(playerid, red, "� ��� ��� ������� �� ������ ������!");
                        if(PlayerInfo[playerid][pMetall] < gunlist[listitem][gun_metal]) return SCM(playerid, red, "� ��� ������������ �������!");

                        dialog_listitem[playerid] = listitem;
                        SPD(playerid, D_MAKEGUN_PATRONS, DIALOG_STYLE_INPUT, "{"cblue"}�������� ������ | �������", "{FFFFFF}������� ���������� ��������, ������� ������ ��������� � ������!", "�����", "�����");
                    }
                    case 1:
                    {
                        if(PlayerInfo[playerid][R_USP] < 1) return SCM(playerid, red, "� ��� ��� ������� �� ������ ������!");
                        if(PlayerInfo[playerid][pMetall] < gunlist[listitem][gun_metal]) return SCM(playerid, red, "� ��� ������������ �������!");

                        dialog_listitem[playerid] = listitem;
                        SPD(playerid, D_MAKEGUN_PATRONS, DIALOG_STYLE_INPUT, "{"cblue"}�������� ������ | �������", "{FFFFFF}������� ���������� ��������, ������� ������ ��������� � ������!", "�����", "�����");
                    }
                    case 2:
                    {
                        if(PlayerInfo[playerid][R_DEAGLE] < 1) return SCM(playerid, red, "� ��� ��� ������� �� ������ ������!");
                        if(PlayerInfo[playerid][pMetall] < gunlist[listitem][gun_metal]) return SCM(playerid, red, "� ��� ������������ �������!");

                        dialog_listitem[playerid] = listitem;
                        SPD(playerid, D_MAKEGUN_PATRONS, DIALOG_STYLE_INPUT, "{"cblue"}�������� ������ | �������", "{FFFFFF}������� ���������� ��������, ������� ������ ��������� � ������!", "�����", "�����");
                    }
                    case 3:
                    {
                        if(PlayerInfo[playerid][R_TEK9] < 1) return SCM(playerid, red, "� ��� ��� ������� �� ������ ������!");
                        if(PlayerInfo[playerid][pMetall] < gunlist[listitem][gun_metal]) return SCM(playerid, red, "� ��� ������������ �������!");

                        dialog_listitem[playerid] = listitem;
                        SPD(playerid, D_MAKEGUN_PATRONS, DIALOG_STYLE_INPUT, "{"cblue"}�������� ������ | �������", "{FFFFFF}������� ���������� ��������, ������� ������ ��������� � ������!", "�����", "�����");
                    }
                    case 4:
                    {
                        if(PlayerInfo[playerid][R_USI] < 1) return SCM(playerid, red, "� ��� ��� ������� �� ������ ������!");
                        if(PlayerInfo[playerid][pMetall] < gunlist[listitem][gun_metal]) return SCM(playerid, red, "� ��� ������������ �������!");

                        dialog_listitem[playerid] = listitem;
                        SPD(playerid, D_MAKEGUN_PATRONS, DIALOG_STYLE_INPUT, "{"cblue"}�������� ������ | �������", "{FFFFFF}������� ���������� ��������, ������� ������ ��������� � ������!", "�����", "�����");
                    }
                    case 5:
                    {
                        if(PlayerInfo[playerid][R_MP5] < 1) return SCM(playerid, red, "� ��� ��� ������� �� ������ ������!");
                        if(PlayerInfo[playerid][pMetall] < gunlist[listitem][gun_metal]) return SCM(playerid, red, "� ��� ������������ �������!");

                        dialog_listitem[playerid] = listitem;
                        SPD(playerid, D_MAKEGUN_PATRONS, DIALOG_STYLE_INPUT, "{"cblue"}�������� ������ | �������", "{FFFFFF}������� ���������� ��������, ������� ������ ��������� � ������!", "�����", "�����");
                    }
                    case 6:
                    {
                        if(PlayerInfo[playerid][R_SHOTGUN] < 1) return SCM(playerid, red, "� ��� ��� ������� �� ������ ������!");
                        if(PlayerInfo[playerid][pMetall] < gunlist[listitem][gun_metal]) return SCM(playerid, red, "� ��� ������������ �������!");

                        dialog_listitem[playerid] = listitem;
                        SPD(playerid, D_MAKEGUN_PATRONS, DIALOG_STYLE_INPUT, "{"cblue"}�������� ������ | �������", "{FFFFFF}������� ���������� ��������, ������� ������ ��������� � ������!", "�����", "�����");
                    }
                    case 7:
                    {
                        if(PlayerInfo[playerid][R_SAWED_OF] < 1) return SCM(playerid, red, "� ��� ��� ������� �� ������ ������!");
                        if(PlayerInfo[playerid][pMetall] < gunlist[listitem][gun_metal]) return SCM(playerid, red, "� ��� ������������ �������!");

                        dialog_listitem[playerid] = listitem;
                        SPD(playerid, D_MAKEGUN_PATRONS, DIALOG_STYLE_INPUT, "{"cblue"}�������� ������ | �������", "{FFFFFF}������� ���������� ��������, ������� ������ ��������� � ������!", "�����", "�����");
                    }
                    case 8:
                    {
                        if(PlayerInfo[playerid][R_FIGHT_SHOTGUN] < 1) return SCM(playerid, red, "� ��� ��� ������� �� ������ ������!");
                        if(PlayerInfo[playerid][pMetall] < gunlist[listitem][gun_metal]) return SCM(playerid, red, "� ��� ������������ �������!");

                        dialog_listitem[playerid] = listitem;
                        SPD(playerid, D_MAKEGUN_PATRONS, DIALOG_STYLE_INPUT, "{"cblue"}�������� ������ | �������", "{FFFFFF}������� ���������� ��������, ������� ������ ��������� � ������!", "�����", "�����");
                    }
                    case 9:
                    {
                        if(PlayerInfo[playerid][R_AK47] < 1) return SCM(playerid, red, "� ��� ��� ������� �� ������ ������!");
                        if(PlayerInfo[playerid][pMetall] < gunlist[listitem][gun_metal]) return SCM(playerid, red, "� ��� ������������ �������!");

                        dialog_listitem[playerid] = listitem;
                        SPD(playerid, D_MAKEGUN_PATRONS, DIALOG_STYLE_INPUT, "{"cblue"}�������� ������ | �������", "{FFFFFF}������� ���������� ��������, ������� ������ ��������� � ������!", "�����", "�����");
                    }
                    case 10:
                    {
                        if(PlayerInfo[playerid][R_M4] < 1) return SCM(playerid, red, "� ��� ��� ������� �� ������ ������!");
                        if(PlayerInfo[playerid][pMetall] < gunlist[listitem][gun_metal]) return SCM(playerid, red, "� ��� ������������ �������!");

                        dialog_listitem[playerid] = listitem;
                        SPD(playerid, D_MAKEGUN_PATRONS, DIALOG_STYLE_INPUT, "{"cblue"}�������� ������ | �������", "{FFFFFF}������� ���������� ��������, ������� ������ ��������� � ������!", "�����", "�����");
                    }
                    case 11:
                    {
                        if(PlayerInfo[playerid][R_COUNTRY_RIFLE] < 1) return SCM(playerid, red, "� ��� ��� ������� �� ������ ������!");
                        if(PlayerInfo[playerid][pMetall] < gunlist[listitem][gun_metal]) return SCM(playerid, red, "� ��� ������������ �������!");

                        dialog_listitem[playerid] = listitem;
                        SPD(playerid, D_MAKEGUN_PATRONS, DIALOG_STYLE_INPUT, "{"cblue"}�������� ������ | �������", "{FFFFFF}������� ���������� ��������, ������� ������ ��������� � ������!", "�����", "�����");
                    }
                    case 12:
                    {
                        if(PlayerInfo[playerid][R_SNIPER_RIFLE] < 1) return SCM(playerid, red, "� ��� ��� ������� �� ������ ������!");
                        if(PlayerInfo[playerid][pMetall] < gunlist[listitem][gun_metal]) return SCM(playerid, red, "� ��� ������������ �������!");

                        dialog_listitem[playerid] = listitem;
                        SPD(playerid, D_MAKEGUN_PATRONS, DIALOG_STYLE_INPUT, "{"cblue"}�������� ������ | �������", "{FFFFFF}������� ���������� ��������, ������� ������ ��������� � ������!", "�����", "�����");
                    }
                }
            }
        }
    }
	#if	defined	makegun__OnDialogResponse
		return makegun__OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnDialogResponse
	#undef	OnDialogResponse
#else
	#define	_ALS_OnDialogResponse
#endif

#define	OnDialogResponse makegun__OnDialogResponse
#if	defined	makegun__OnDialogResponse
	forward makegun__OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif