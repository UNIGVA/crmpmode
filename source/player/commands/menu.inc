enum E_CMDS_ORG_STRUCT
{
	ORG_INFO[1048]
};

new help_cmds_org_list[8][E_CMDS_ORG_STRUCT] =
{
	{
		"{ffffff}������� �����������: {ffcc00}������������� �������{ffffff}\n\n"\
		"/free [id ������] [����] - ��������� ������ �� ���\n"\
		"/tazer [id ������] - ������� ������ ��������������"
	},
	{
		"\n{ffffff}������� �����������: {ffcc00}���������-�������� ������ (���){ffffff}\n\n"\
		"/open - ������� ������\n"\
		"/tazer [id ������] - ������� ������ ��������������\n"\
		"/su [id ������] [�������] - �������� ������ � ������\n"\
		"/clear [id ������] - ����� � ������ ������\n"\
		"/arrest [id ������] - �������� ������ � ���\n"\
		"/incar [id ������] - �������� ������ � ������\n"\
		"/cuff [id ������] - ������ ��������� �� ������\n"\
		"/uncuff [id ������] - ����� ��������� � ������\n"\
		"/stopcar - �������/�������� ����\n"\
		"/deject [id ������] - �������� �������� ������ �� ����\n"\
		"/m [�����] - ������� � �������\n"\
		"/ticket [id ������] [�����] [�������] - �������� ����� ������\n"\
		"/calling - ������ �������� �������"
	},
	{
		"\n{ffffff}������� �����������: {ffcc00}������ ����������� ������ (���){ffffff}\n\n"\
		"/heal [id ������] [���������] - �������� ������ �� 100 ��\n"\
		"/calling - ������ �������� �������"
	},
	{
		"\n{ffffff}������� �����������: {ffcc00}��������-��������� ������ (���){ffffff}\n\n"\
		"/openvdv - ������� ������\n"\
		"/putmet [����������] - �������� ������ �� ����� ���\n"\
		"/getmet [����������] - ����� ������ �� ������ ���"
	},
	{
		"\n{ffffff}������� �����������: {ffcc00}�������� �������� ���������� (���){ffffff}\n\n"\
		"/edit - ������������� ����������\n"\
		"/news - ����"
	},
	{
		"\n{ffffff}������� �����������: {ffcc00}�������������� ���������� ����������� (���){ffffff}\n\n"\
		"/bizwar - ������ ����� �� �������\n"\
		"/makegun - ������� ������\n"\
		"/tie [id ������] - ������� ������\n"\
		"/untie [id ������] - ��������� ������\n"\
		"/sellgun [id ������] [���-�� ��������] [����] - ������� ������ ������\n"\
		"/selldrugs [id ������] [���-�� ����] [����] - ������� ��������� ������"
	},
	{
		"\n{ffffff}������� �����������: {ffcc00}�����{ffffff}\n\n"\
		"/find - ���������� ������ ������ ������� � �����������\n"\
		"/r [�����] - �������� � �� ��� �����������/������\n"\
		"/rb [�����] - �������� � ��� ��� �����������/������\n"\
		"/d [�����] - IC (RP) ���.��� ������� (��� ��� ����������!)\n"\
		"/db [�����] - OOC (NoNRP) ���.��� ������� (��� ��� ����������!)"
	},
	{
		"\n{ffffff}������� �����������: {ffcc00}�����/�����������{ffffff}\n\n"\
		"/invite [ID ������] - ������� ������ � ���� �������\n"\
		"/uninvite [ID ������] [������� ����������] - ������� ������\n"\
		"/uninviteoff [��� ������] [������� ����������] - ������� ������ �������\n"\
		"/showall - ���������� ���� ������ �������\n"\
		"/rang [ID ������] [+/-] - �������� ������/�������� ������\n"\
		"/r [����] - IC (RP) ��� �������\n"\
		"/rb[�����] - OOC (NoNRP) ��� �������)\n"\
		"/d [�����] - IC (RP) ���.��� ������� (��� ��� ����������!)\n"\
		"/db [�����] - OOC (NoNRP) ���.��� ������� (��� ��� ����������!)\n"\
		"/gov [�����] - ������� (���������� ������)\n"\
		"/changeskin [ID ������] - �������� ���� (���������) ������ (�������� ������ ��� 8+ ������)"
	}
};

ALTX:menu("/mn", "/mm");
CMD:menu(playerid)
{
    ShowMenu(playerid);
	return 1;
}
CMD:ask(playerid)
{
	return SPD(playerid, D_MENU_ASK, DIALOG_STYLE_INPUT, !"{"cblue"}������ ������", !"{FFFFFF}�� ����������� ����� �������� ���� ������, ������� - {"cblue"}/help {"cwhite"}� ���������, ���� �� �� ����� ����� �� ��� ������, �� �� ������ ��� ��� ������!\n\n����������, �������� �� ������ � ����� � ������������� ��� ������� � ��������� �����!", !"�����", !"�����");
}
CMD:report(playerid)
{
	return SPD(playerid, D_MENU_REP, DIALOG_STYLE_INPUT, !"{"cblue"}������ ������", !"{FFFFFF}���� �� �������� ����������, �� ����� �� ������ �� ���� ������ ������!\n\n���������� �������� ID ���������� � ������ ������� ��� ���������.\n� ������, ���� ���������� {"cred"}������� {FFFFFF}, �� � ��� ���� ��������������, ��� �� ������� �������, \n�� �� ������ ������ ������ �� ����� ������.", !"�����", !"�����");
}

stock ShowMenu(playerid)
{
	SPD(playerid, 8, DIALOG_STYLE_LIST, !"{"cblue"}����", !"\
	{"cblue"}1. {FFFFFF}����������\n\
	{"cblue"}2. {FFFFFF}������� �������\n\
	{"cblue"}3. {FFFFFF}������ ��������\n\
	{"cblue"}4. {FFFFFF}������� / ������ �� �������\n\
	{"cblue"}5. {FFFFFF}����� NonRP ����\n\
	{"cblue"}6. {FFFFFF}������������ ���������\n\
	{"cblue"}7. {FFFFFF}�������������� ������", !"�����", !"������");
	return 1;
}


public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	switch(dialogid)
	{
		case 8:
		{
			if(response)
			{
				switch(listitem)
				{
					case 0: stats_player(playerid, playerid);
					case 1: SPD(playerid, 11, DIALOG_STYLE_LIST, "{"cblue"}������� ������", "{"cblue"}1. {FFFFFF}������� �����������\n{"cblue"}2. {FFFFFF}������� �����\n{"cblue"}3. {FFFFFF}������� ������������\n{"cblue"}4. {FFFFFF}������� �������\n{"cblue"}5. {FFFFFF}������� ���������", "�����", "������");
					case 2: SPD(playerid, 13, DIALOG_STYLE_LIST, "{"cblue"}������������ ��������", "{"cblue"}1. {FFFFFF}����� ������", "�����", "�����");
					case 3: SPD(playerid, D_MENU_ASK_REP, DIALOG_STYLE_LIST, !"{"cblue"}������� / ������ �� �������", !"{"cblue"}1. {FFFFFF}������ ������\n{"cblue"}2. {FFFFFF}������ �� ������", !"�����", !"�����");
					case 4: SPD(playerid, 9, DIALOG_STYLE_INPUT, "{"cblue"}����� ����", "{"cwhite"}���� ��� ���-���� �� ����������� ���������� RolePlay, �� �� ������ ��� �������.\n\n������: {"cblue"}Andrey_Sergeev, Ekaterina_Petrova", "�����", "������");
					case 5:
					{
						stringer[0] = EOS;
						format(stringer, 500, "\
						{"cblue"}1. {FFFFFF}3D TextDraw\t\t| %s {"cred"}(BETA){"cwhite"}\n\
						{"cblue"}2. {FFFFFF}�������� ���\n\
						{"cblue"}3. {FFFFFF}������� ��������",
						((PlayerInfo[playerid][pLogo] == 0) ? ("{"clred"}��������") : ("{"cblue"}�������")));
						SPD(playerid, 10, DIALOG_STYLE_LIST, "{"cblue"}������������ ���������", stringer, "�����", "�����");
					}
					case 6: cmd::donate(playerid);
					//case 6: SPD(playerid, 12, DIALOG_STYLE_INPUT, "{"cblue"}������������� �����", "{"cwhite"}������� �����, ������� �� ������ ������������ �� �������� �������!", "�����", "�����");
				}
			}
		}
		case 9:
		{
			if(response)
			{
				if(!strlen(inputtext)) return SPD(playerid, 9, DIALOG_STYLE_INPUT, "{"cblue"}����� ����", "{"cwhite"}���� ��� ���-���� �� ����������� ���������� RolePlay, �� �� ������ ��� �������.\n\n������: {"cblue"}Andrey_Sergeev, Ekaterina_Petrova", "�����", "������");
				if(IsTextInvalid(inputtext)) return SPD(playerid, 9, DIALOG_STYLE_INPUT, "{"cblue"}����� ����", "{"cwhite"}���� ��� ���-���� �� ����������� ���������� RolePlay, �� �� ������ ��� �������.\n\n������: {"cblue"}Andrey_Sergeev, Ekaterina_Petrova", "�����", "������");
				if(strlen(inputtext) < 6 || strlen(inputtext) > 24) return SPD(playerid, 9, DIALOG_STYLE_INPUT, "{"cblue"}����� ����", "{"cwhite"}���� ��� ���-���� �� ����������� ���������� RolePlay, �� �� ������ ��� �������.\n\n������: {"cblue"}Andrey_Sergeev, Ekaterina_Petrova", "�����", "������");
				stringer[0] = EOS;
				SetPVarString(playerid,"WantNickChange", inputtext);
				format(stringer,128, "SELECT `pName` FROM `accounts` WHERE `pName` = '%s' LIMIT 1", inputtext);
				mysql_tquery(connects, stringer,  "CallChangeName", "d", playerid);
			}
		}
		case 10:
		{
			if(response)
			{
				switch(listitem)
				{
					case 0:
					{
						if(PlayerInfo[playerid][pLogo] == 0)
						{
							PlayerInfo[playerid][pLogo] = 1;
							SCM(playerid, white, "{"cgreen"}[�������]{"cwhite"}: �� �������� 3D TextDraw!");
							for(new i = 0; i < 3; i++) TextDrawHideForPlayer(playerid, logotype_td[i]);

							TextDrawShowForPlayer(playerid, logotype_td[3]);
						}
						else
						{
							PlayerInfo[playerid][pLogo] = 0;
							SCM(playerid, white, "{"cgreen"}[�������]{"cwhite"}: �� ��������� 3D TextDraw!");
							TextDrawHideForPlayer(playerid, logotype_td[3]);

							for(new i = 0; i < 3; i++) TextDrawShowForPlayer(playerid, logotype_td[i]);
						}
					}
					case 1:
					{
						for(new i = 0; i < 100; i++)
						{
							SCM(playerid, white, "");
						}
						SCM(playerid, white, "�� ������� �������� ���!");
					}
					case 2:{
						if(response){
							SPD(playerid, D_MENU_SET_TELEGRAM_ID, DIALOG_STYLE_INPUT, !"{"cblue"}���� | Telegram", !"\
							{ffffff}������� ��� �������� ID, ���� ����� �������������� ��������� ������ ����.\n\
							������ ���� �������� ID �� ������ ��� �� � ����� ����, ���������������� �������� /get_my_id\n\
							������ �� ��� telegram bot: {"cblue"}t.me/unigva_rp_bot{ffffff}\n\n\
							{"cblue"}����������: {ffffff}���� �� ������� ����������� telegramid, �� �� ������� �������������� ��������� ������ ����.\
							", !"�������", !"�������");
						} else return 1;
					}
				}
			}
		}
		case D_MENU_SET_TELEGRAM_ID:{
			if(response){
				if(!strlen(inputtext)){
					SPD(playerid, D_MENU_SET_TELEGRAM_ID, DIALOG_STYLE_INPUT, !"{"cblue"}���� | Telegram", !"\
					{ffffff}������� ��� �������� ID, ���� ����� �������������� ��������� ������ ����.\n\
					������ ���� �������� ID �� ������ ��� �� � ����� ����, ���������������� �������� /get_my_id\n\
					������ �� ��� telegram bot: {"cblue"}t.me/unigva_rp_bot{ffffff}\n\n\
					{"cblue"}����������: {ffffff}���� �� ������� ����������� telegramid, �� �� ������� �������������� ��������� ������ ����.\
					", !"�������", !"�������");
					return 1;
				}
				if(!IsNumeric(inputtext)){
					SPD(playerid, D_MENU_SET_TELEGRAM_ID, DIALOG_STYLE_INPUT, !"{"cblue"}���� | Telegram", !"\
					{ffffff}������� ��� �������� ID, ���� ����� �������������� ��������� ������ ����.\n\
					������ ���� �������� ID �� ������ ��� �� � ����� ����, ���������������� �������� /get_my_id\n\
					������ �� ��� telegram bot: {"cblue"}t.me/unigva_rp_bot{ffffff}\n\n\
					{"cblue"}����������: {ffffff}���� �� ������� ����������� telegramid, �� �� ������� �������������� ��������� ������ ����.\
					", !"�������", !"�������");
					return 1;					
				}
				PlayerInfo[playerid][pTelegramId] = strval(inputtext);
				SaveAccounts(playerid);
				SCM(playerid, blue, !"�� ������� ������� Telegram ID.");
			}else return 1;
		}
		case 11:
		{
			if(response)
			{
				switch(listitem)
				{
					case 0:{
						ShowPlayerDialog
						(
							playerid, D_MENU_ORG_COMMANDS, DIALOG_STYLE_LIST,
							!"{"cblue"}������� �����������",
							!"\
							{"cblue"}1. {ffffff}������������� ������\n\
							{"cblue"}2. {ffffff}���������-�������� ������ (���)\n\
							{"cblue"}3. {ffffff}������ ����������� ������ (���)\n\
							{"cblue"}4. {ffffff}��������-��������� ������ (���)\n\
							{"cblue"}5. {ffffff}�������� �������� ���������� (���)\n\
							{"cblue"}6. {ffffff}�������������� ���������� ����������� (���)\n\
							{"cblue"}7. {ffffff}����� ������� �����������\n\
							{"cblue"}8. {ffffff}������� �������/������������ �����������\
							",
							!"�����", !"������"
						);
					}
					case 1:{
						ShowPlayerDialog
						(
							playerid, D_NULL, DIALOG_STYLE_MSGBOX,
							"{"cblue"}������� ��� ������",
							"\n{ffffff}�������: {ffcc00}�����{ffffff}\n\n\
							/calling - ���������� ������ ������� (�������)\n\
							/repair [id ������] [���������] - �������� ���� ������ (�������)\n\
							/jskill - ���������� ���� ������� ������ (������������)\n\
							/end - �������� ������ (������� ����)\n\
							",
							"�������", ""
						);
					}
					case 2:{
						ShowPlayerDialog
						(
							playerid, D_NULL, DIALOG_STYLE_MSGBOX,
							"{ffcc00}������� ������������",
							"\n{ffffff}������� ������������: {ffcc00}���������, ���, ������{ffffff}\n\n\
							/lock [1] - �������/������� ������ ���������\n\
							/sellcar - ������� ���� �����������\n\
							/sellmycar [id ������] [����] - ������� ���� ������\n\
							/buybiz - ������ ������\n\
							/business - ���������� ��������\n\
							/sellmybusiness [id ������] [����] - ������� ������ ������\n\
							/sellhome - ������� ��� �����������\n\
							/sellmyhome [id ������] [����] - ������� ��� ������\n\
							/hlock - ������� ���\n\
							/hopen - ������� ���\n\
							/home - ���� ����\n\
							/use - ���������� ������ ����\n\
							/rlock - �������/������� ����� � �����\n\
							/klock - �������/������� ��������",
							"�������", ""
						);
					}
					case 3:{
						ShowPlayerDialog
						(
							playerid, D_NULL, DIALOG_STYLE_MSGBOX,
							"{ffcc00}������� �������",
							"\n{ffffff}�������: {ffcc00}�������{ffffff}\n\n\
							/rb [�����] - �������� � ��� ��� �����������\n\
							/r [�����] - �������� � �� ��� �����������\n\
							/db [�����] - �������� � ��� ��� ������������\n\
							/d [�����] - �������� � �� ��� ������������\n\
							/gov [�����] - �������� � ��� �������\n\
							/ad [�����] - ������ ����������\n\
							/me [�����] - �������� ������ �� 1 ����\n\
							/try [�����] - �������� ������ �� �����\n\
							/do [�����] - �������� ������ �� 3 ����\n\
							/b [�����] - �������� � ��� ���\n\
							/s [�����] - �������� � ���\n\
							/call [����� ��������] - ���������\n\
							/p - ����� ������\n\
							/h - �������� ������\n\
							/sms [����� ��������] [�����] - �������� ��� ������\n\
							/togphone - ��������� �������",
							"�������", ""
						);
					}
					case 4:{
						ShowPlayerDialog
						(
							playerid, D_NULL, DIALOG_STYLE_MSGBOX,
							"{ffcc00}������� ���������",
							"\n{ffffff}�������: {ffcc00}���������{ffffff}\n\n\
							/drugs [����������] - ������������ ���������\n\
							/en - ��������� ��������� � ����������\n\
							/rem - ����������� ������ ������������ � ����������\n\
							/myskill - ����������� ������ �������� �������\n\
							/skill [id ������] - �������� ������ ������ �������� �������\n\
							/gotomp - ��������������� �� �����������\n\
							/pass [id ������] - �������� �������\n\
							/lic [id ������] - �������� ��������\n\
							/time - ���������� �����\n\
							/leaders - ���������� ������� � ����\n\
							/eject [id ������] - �������� ������ �� ����\n\
							/carpass [id ������] - �������� ��������� �� ����\n\
							/tune - ��������� ������� �� ��� ���� � ���\n\
							/gps - ��������� �� �������\n\
							/pay [id ������] [���-��] - �������� ������ ������\n\
							/anim [����� ��������] - ��������",
							"�������", ""
						);
					}
				}
			}
		}
		case D_MENU_ORG_COMMANDS:{
			if(response){
				ShowPlayerDialog
				(
					playerid, D_MENU_ORGS_COMMANDS, DIALOG_STYLE_MSGBOX, 
					!"{"cblue"}������� �����������",
					help_cmds_org_list[listitem][ORG_INFO],
					!"�����", !""
				);
			}
		}
		case D_MENU_ORGS_COMMANDS:{
			if(!response || response){
				ShowPlayerDialog
				(
					playerid, D_MENU_ORG_COMMANDS, DIALOG_STYLE_LIST,
					!"{"cblue"}������� �����������",
					!"\
					{"cblue"}1. {ffffff}������������� ������\n\
					{"cblue"}2. {ffffff}���������-�������� ������ (���)\n\
					{"cblue"}3. {ffffff}������ ����������� ������ (���)\n\
					{"cblue"}4. {ffffff}��������-��������� ������ (���)\n\
					{"cblue"}5. {ffffff}�������� �������� ���������� (���)\n\
					{"cblue"}6. {ffffff}�������������� ���������� ����������� (���)\n\
					{"cblue"}7. {ffffff}����� ������� �����������\n\
					{"cblue"}8. {ffffff}������� �������/������������ �����������\
					",
					!"�����", !"������"
				);				
			}
		}
		case 12:
		{
			if(response)
			{
				if(!strval(inputtext)) return SPD(playerid, 12, DIALOG_STYLE_INPUT, "{"cblue"}������������� �����", "{"cwhite"}������� �����, ������� �� ������ ����������� �� �������� �������!", "�����", "�����");
				if(PlayerInfo[playerid][pCash] < 0 || strval(inputtext) > PlayerInfo[playerid][pCash]) return SCM(playerid, red, "� ��� �� ���������� �����.");
				PlayerInfo[playerid][pCash] -= strval(inputtext);
			}
		}
		case 13:
		{
			if(!response) return ShowMenu(playerid);
			else
			{
				switch(listitem)
				{
					case 0: return SPD(playerid, D_CHECK_PASS, DIALOG_STYLE_INPUT, "{"cblue"}����� ������", "{FFFFFF}������� ������������ ������:", "�����", "�����");
				}
			}
		}
		case D_CHECK_PASS:
		{
			if(!response) return ShowMenu(playerid);
			else
			{
				if(!strlen(inputtext))
				{
					SCM(playerid, red, "�� ������ �� �����!");
					return SPD(playerid, D_CHECK_PASS, DIALOG_STYLE_INPUT, "{"cblue"}����� ������", "{FFFFFF}������� ������������ ������:", "�����", "�����");
				}

				new mysqlstr[144];
				mysql_format(connects, mysqlstr, sizeof(mysqlstr),"SELECT * FROM `accounts` WHERE `pName` = '%s' AND `pKey` = MD5('%s')", PlayerInfo[playerid][pName], inputtext);
				mysql_function_query(connects, mysqlstr, true, "CheckPassChangePass","ds", playerid, inputtext);
				return 1;
			}
		}
		case D_CHANGE_PASS:
		{
			if(!response) return ShowMenu(playerid);
			else
			{
				if(strlen(inputtext) < 6 || strlen(inputtext) > 20)
				{
					SPD(playerid, D_CHANGE_PASS, DIALOG_STYLE_INPUT, "{"cblue"}����� ������", "{"cwhite"}������� ����� ������ ��� ������ ��������.\n�� ����� ������������� ��� ������ ����� �� ������.\n\n{"cblue"}����������:\n\
					- ������ ������ ���� ������� (������: s9cQ17)\n- ������ ������ �������� �� ���� � ����\n- ������������ ����� ������ �� 6 �� 20 ��������.", "�����", "������");
					return 1;
				}
				for(new i = strlen(inputtext); i != 0; --i)
				switch(inputtext[i])
				{
					case '�'..'�', '�'..'�', '=', ' ':
					{
						SPD(playerid, D_CHANGE_PASS, DIALOG_STYLE_INPUT, "{"cblue"}����� ������", "{"cwhite"}������� ����� ������ ��� ������ ��������.\n�� ����� ������������� ��� ������ ����� �� ������.\n\n{"cblue"}����������:\n\
						- ������ ������ ���� ������� (������: s9cQ17)\n- ������ ������ �������� �� ���� � ����\n- ������������ ����� ������ �� 6 �� 20 ��������.", "�����", "������");
						return SCM(playerid, red, "�� ������ ���������!");
					}
				}
				strdel(PlayerInfo[playerid][pKey], 0, 24);
				strmid(PlayerInfo[playerid][pKey], inputtext, 0, strlen(inputtext), 64);

				new string[256];
				format(string, sizeof(string), "UPDATE `accounts` SET `pKey` = MD5('%s') WHERE `pName` = '%s' LIMIT 1", PlayerInfo[playerid][pKey], PlayerInfo[playerid][pName]);
				mysql_tquery(connects, string, "", "");

				format(string, sizeof(string), "{"cblue"}��� ����� ������: {"cyellow"}%s{"cblue"}. ������������ ��� �� ������! ���� �� ��� ��������, �� �� �� ������� ����� �� �������!", PlayerInfo[playerid][pKey]);
				SCM(playerid, blue, string);
			}
		}
		case D_MENU_ASK_REP:
		{
		    if(!response) return ShowMenu(playerid);
		    else
		    {
		        switch(listitem)
		        {
		            case 0: SPD(playerid, D_MENU_ASK, DIALOG_STYLE_INPUT, !"{"cblue"}������ ������", !"{FFFFFF}�� ����������� ����� �������� ���� ������, ������� - {"cblue"}/help {"cwhite"}� ���������, ���� �� �� ����� ����� �� ��� ������, �� �� ������ ��� ��� ������!\n\n����������, �������� �� ������ � ����� � ������������� ��� ������� � ��������� �����!", !"�����", !"�����");
					case 1: SPD(playerid, D_MENU_REP, DIALOG_STYLE_INPUT, !"{"cblue"}������ ������", !"{FFFFFF}���� �� �������� ����������, �� ����� �� ������ �� ���� ������ ������!\n\n���������� �������� ID ���������� � ������ ������� ��� ���������.\n� ������, ���� ���������� {"cred"}������� {FFFFFF}, �� � ��� ���� ��������������, ��� �� ������� �������, \n�� �� ������ ������ ������ �� ����� ������.", !"�����", !"�����");
				}
		    }
		}
		case D_MENU_ASK:
		{
			if(!response) return SPD(playerid, D_MENU_ASK_REP, DIALOG_STYLE_LIST, !"{"cblue"}������� / ������ �� �������", !"{"cblue"}1. {FFFFFF}������ ������\n{"cblue"}2. {FFFFFF}������ ������ �� ������", !"�����", !"�����");
			else
			{
			    new len = strlen(inputtext);
			    if(1 <= len <= 80)
			    {
			    	new string[256];
				    format(string, sizeof(string), "[A] ������ �� %s[%d]: {"cyellow"}%s", PlayerInfo[playerid][pName], playerid, inputtext);
				    SCM(playerid, green, string);
				    return SCMA(green, string);
			    }
			    else
			    {
			        SCM(playerid, red, !"������� ������� ���������");
			        return SPD(playerid, D_MENU_ASK, DIALOG_STYLE_INPUT, !"{"cblue"}������ ������", !"{FFFFFF}�� ����������� ����� �������� ���� ������, ������� - {"cblue"}/help {"cwhite"}� ���������, ���� �� �� ����� ����� �� ��� ������, �� �� ������ ��� ��� ������!\n\n����������, �������� �� ������ � ����� � ������������� ��� ������� � ��������� �����!", !"�����", !"�����");
			    }
			}
		}
		case D_MENU_REP:
		{
			if(!response) return SPD(playerid, D_MENU_ASK_REP, DIALOG_STYLE_LIST, !"{"cblue"}������� / ������ �� �������", !"{"cblue"}1. {FFFFFF}������ ������\n{"cblue"}2. {FFFFFF}������ ������ �� ������", !"�����", !"�����");
			else
			{
			    new len = strlen(inputtext);
			    if(1 <= len <= 80)
			    {
			    	new string[256];
				    format(string, sizeof(string), "[A] ������ �� %s[%d]: {"cyellow"}%s", PlayerInfo[playerid][pName], playerid, inputtext);
				    SCM(playerid, green, string);
				    return SCMA(green, string);
			    }
			    else
			    {
			        SCM(playerid, red, !"������� ������� ���������");
					return SPD(playerid, D_MENU_REP, DIALOG_STYLE_INPUT, !"{"cblue"}������ ������", !"{FFFFFF}���� �� �������� ����������, �� ����� �� ������ �� ���� ������ ������!\n\n���������� �������� ID ���������� � ������ ������� ��� ���������.\n� ������, ���� ���������� {"cred"}������� {FFFFFF}, �� � ��� ���� ��������������, ��� �� ������� �������, \n�� �� ������ ������ ������ �� ����� ������.", !"�����", !"�����");
			    }
			}
		}
	}
	#if	defined	menu__OnDialogResponse
		return menu__OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnDialogResponse
	#undef	OnDialogResponse
#else
	#define	_ALS_OnDialogResponse
#endif

#define	OnDialogResponse menu__OnDialogResponse
#if	defined	menu__OnDialogResponse
	forward menu__OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif