CMD:skill(playerid, params[]){
    extract params -> new to_player; else return SCM(playerid, blue, "[���������]: {FFFFFF}����������� /skill [ID ������]");
    if(!IsPlayerConnected(to_player) || !PlayerInfo[to_player][pLogin]) return PlayerOffLine(playerid);
    new Float: x, Float: y, Float:z;
    GetPlayerPos(to_player, x, y, z);
    if(!IsPlayerInRangeOfPoint(playerid, 10.0, x, y, z)) return SCM(playerid, red, !"����� ������ �� ���.");

    SendProposition(playerid, to_player, PROPOSITION_TYPE_SKILL);
    return 1;
}