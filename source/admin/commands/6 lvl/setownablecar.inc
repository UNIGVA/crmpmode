CMD:setownablecar(playerid, params[])
{
    if(PlayerInfo[playerid][bAdmin] < 6) return ShowCommandNotFound(playerid);

    extract params -> new string: to_player[32], model_id, cost_oc_car; else return SCM(playerid, blue, "[���������]: {FFFFFF}����������� /setownablecar [NickName ������] [������ ����] [��������� ����]");
    if(model_id < 400 || model_id > 611) return SCM(playerid, red, "������ ���� �� ����� 400 � �� ����� 611.");

    foreach(new i : Player)
    {
        if(!strcmp(PlayerInfo[i][pName], to_player, false))
        {
            if(PlayerInfo[i][pCarID] != -1) return SCM(playerid, red, "� ������� ������ ������� ����.");

            new query[120];
            format
            (
                query, sizeof query,
                "INSERT INTO `ownable_cars` (`owner_id`,`model_id`,`color`,`cost_car`) VALUES ('%d','%d','%d, %d', '%d')",
                PlayerInfo[playerid][pID],
                model_id,
                0,0,
                cost_oc_car
            );
            mysql_tquery(connects, query, "", "");
            PlayerInfo[i][pCarID] = model_id;

            format(query, sizeof(query), "�� ������ ������ %s ������ ��������� [������: %d] [���������: %d]", to_player, model_id, cost_oc_car);
            SCM(playerid, white, query);
            return 1;
        }
    }
    new sql[144];
    format(sql, sizeof(sql), "SELECT * FROM `accounts` WHERE `pName` = '%s'", to_player);
    mysql_tquery(connects, sql, "CheckPlayerForSetOwnableCar", "isii", playerid, to_player, model_id, cost_oc_car);
    return 1;
}

publics CheckPlayerForSetOwnableCar(playerid, to_player[], model_id, cost_oc_car)
{
    static rows[2];
    cache_get_data(rows[0], rows[1]);
    if(rows[0])
    {
        static carid, owner_id;
        carid = cache_get_field_content_int(0, "pCarID");
        owner_id = cache_get_field_content_int(0, "pID");

        if(carid != -1) return SCM(playerid, red, "� ������� ������ ������� ������ ���������.");

        new query[120];
        format
        (
            query, sizeof query,
            "INSERT INTO `ownable_cars` (`owner_id`,`model_id`,`color`,`cost_car`) VALUES ('%d','%d','%d, %d', '%d')",
            owner_id,
            model_id,
            0,0,
            cost_oc_car
        );
        mysql_tquery(connects, query, "", "");

        format(query, sizeof(query), "UPDATE `accounts` SET `pCarID` = '%d' WHERE `pName` = '%s'", model_id, to_player);
        mysql_tquery(connects, query, "", "");

        format(query, sizeof(query), "�� ������ ������ %s ������ ��������� [������: %d] [���������: %d]", to_player, model_id, cost_oc_car);
        SCM(playerid, white, query);
    }
    else
    {
        return SCM(playerid, red, "������ ������ ���.");
    }
    return 1;
}