CMD:mycoords(playerid)
{
	new Float:x, Float:y, Float:z;
	GetPlayerPos(playerid, x, y, z);

	new string[128];
	format(string, sizeof(string), "���� ����������: %f, %f, %f", x, y, z);
	return SCM(playerid, blue, string);
}