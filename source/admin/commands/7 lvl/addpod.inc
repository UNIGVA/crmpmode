CMD:addpod(playerid)
{
    if(PlayerInfo[playerid][bAdmin] < 7) return ShowCommandNotFound(playerid);
    if(totalpodezd >= MAX_PODEZDS) return SCM(playerid, red, "�� ������� �������� ����� ���������.");

    last_pod_id++;
    new Float:x, Float:y, Float:z, sql[144];
    GetPlayerPos(playerid, x, y, z);

    format(sql, sizeof(sql), "INSERT INTO `podezd` (`pod_x`, `pod_y`, `pod_z`) VALUES ('%f', '%f', %f)", x, y, z);
    mysql_tquery(connects, sql, "", "");

    for(new i = 0; i != 8; i++)
    {
        format(sql, sizeof(sql), "INSERT INTO `kvart` (`kvart_type`, `kvart_pod_id`) VALUES ('%d', '%d')", i, last_pod_id);
        mysql_tquery(connects, sql, "", "");           
    }
    return SCM(playerid, green, "������� ������� ������. �� �������� ����� ������������.");
}

CMD:setpodcarpos(playerid, params[])
{
    if(PlayerInfo[playerid][bAdmin] < 7) return ShowCommandNotFound(playerid);
    if(!IsPlayerInAnyVehicle(playerid)) return SCM(playerid, red, "�� ������ ��������� � ����������.");
    
    extract params -> new podezd_id; else return SCM(playerid, blue, "[���������]: {FFFFFF}����������� /setpodcarpos [ID ��������]");
    if(podezd_id >= MAX_PODEZDS) return SCM(playerid, red, "������ �������� ���.");


    new Float:x, Float:y, Float:z, Float:angle;
    GetVehiclePos(GetPlayerVehicleID(playerid), x, y, z);
    GetVehicleZAngle( GetPlayerVehicleID(playerid), angle);

    foreach(new i : Allpodezd) if(podezd_id == PodezdInfo[i][pod_id])
    {

        PodezdInfo[i][a_car_pos_x] = x;
        PodezdInfo[i][a_car_pos_y] = y;
        PodezdInfo[i][a_car_pos_z] = z;
        PodezdInfo[i][a_car_pos_a] = angle;

        new sql[256];
        format
        (
            sql, sizeof(sql), "UPDATE `podezd` SET `a_car_pos_x` = '%f', `a_car_pos_y` = '%f', `a_car_pos_z` = '%f', `a_car_pos_a` = '%f' WHERE `pod_id` = '%d'",
            PodezdInfo[i][a_car_pos_x],
            PodezdInfo[i][a_car_pos_y],
            PodezdInfo[i][a_car_pos_z],
            PodezdInfo[i][a_car_pos_a],
            PodezdInfo[i][pod_id]
        );
        mysql_tquery(connects, sql, "", "");

        SCM(playerid, green, "�� ���������� ����� ������ ���� ����� ��������.");
        return 1;
    }


    return SCM(playerid, red, "������ �������� ���!");
}