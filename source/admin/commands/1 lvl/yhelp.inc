CMD:yhelp(playerid)
{
    if(PlayerInfo[playerid][bAdmin] < 1 && PlayerInfo[playerid][bYoutube] == 0) return ShowCommandNotFound(playerid);
    SPD(playerid, D_NULL, DIALOG_STYLE_MSGBOX, "{"cblue"}UNIGVA | YHELP", "\
	{"cblue"}/up, /down, /left, /right, /before, /after {FFFFFF}- ��������������� �� ��������� ����������\n\
	{"cblue"}/tp {FFFFFF}- �������� �� ���� �����\n\
	{"cblue"}/hp {FFFFFF}- ������ ���� 100 ��\n\
	{"cblue"}/arm {FFFFFF}- ������ ���� 100 �����\n\
	{"cblue"}/getskin {FFFFFF}- ������ ���� ��������� ����\n\
	{"cblue"}/veh {FFFFFF}- ������� ���������\n\
	{"cblue"}/delveh {FFFFFF}- ������� ���������\n\
	{"cblue"}/fixveh {FFFFFF}- ��������������� ���������\n\
	{"cblue"}/y - {FFFFFF}- ����� �������� � ���������������\n\
	{"cblue"}/youtubers {FFFFFF}- ������� ������\
	", "�������", "");
	return 1;
}