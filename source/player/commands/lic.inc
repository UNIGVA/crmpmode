CMD:lic(playerid, params[])
{
    extract params -> new to_player; else return SCM(playerid, blue, "[���������]: {FFFFFF}����������� /lic [ID ������]");

    if(!IsPlayerConnected(to_player) || PlayerInfo[to_player][pLogin] != true) return PlayerOffLine(playerid);

	new fmt_msg[128];

	format(fmt_msg, sizeof fmt_msg, "�� �������� ���� �������� %s [%d]", PlayerInfo[to_player][pName], to_player);
	SCM(playerid, -1, fmt_msg);
	
	format(fmt_msg, sizeof fmt_msg, "___________[ �������� ]___________");
	SCM(to_player, -1, fmt_msg);
	SCM(to_player, -1, "");
	
	format(fmt_msg, sizeof fmt_msg, "��� �������: %s", PlayerInfo[playerid][pName]);
	SCM(to_player, -1, fmt_msg);
	
	format(fmt_msg, sizeof fmt_msg, "�������� ��������� A: %s | �������� ��������� B: %s", PlayerInfo[playerid][pLicA] == 1 ? ("����") : ("���"), PlayerInfo[playerid][pLicB] == 1 ? ("����") : ("���"));
	SCM(to_player, -1, fmt_msg);
	
	format(fmt_msg, sizeof fmt_msg, "�������� ��������� C: %s | �������� ��������� D: %s", PlayerInfo[playerid][pLicC] == 1 ? ("����") : ("���"), PlayerInfo[playerid][pLicD] == 1 ? ("����") : ("���"));
	SCM(to_player, -1, fmt_msg);

	format(fmt_msg, sizeof fmt_msg, "�������� �� �������: %s | �������� �����: %s", PlayerInfo[playerid][pLicBiz] == 1 ? ("����") : ("���"), PlayerInfo[playerid][pLicFly] == 1 ? ("����") : ("���"));
	SCM(to_player, -1, fmt_msg);

	format(fmt_msg, sizeof fmt_msg, "�������� �� ������: %s", PlayerInfo[playerid][pLicGun] == 1 ? ("����") : ("���"));
	SCM(to_player, -1, fmt_msg);
	
	SCM(to_player, -1, "_______________________________________");
    return 1;
}