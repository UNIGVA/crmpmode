CMD:msg(playerid, params[])
{
    if(PlayerInfo[playerid][bAdmin] < 2) return ShowCommandNotFound(playerid);
    if(sscanf(params, "s[100]", params[0])) return SCM(playerid, white, "{"cblue"}� [���������]{"cwhite"}: ����������� /msg [�����]");
	stringer[0] = EOS;
	format(stringer, 150, "������������� %s: %s", PlayerInfo[playerid][pName], params[0]);
	SCMTA(yellow, stringer);
	return 1;
}