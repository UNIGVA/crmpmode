CMD:setname(playerid,params[])
{
    stringer[0] = EOS;
	if(PlayerInfo[playerid][bAdmin] < 3) return ShowCommandNotFound(playerid);
	if(sscanf(params,"i",params[0])) return SCM(playerid,white, "{"cblue"}� [���������]{"cwhite"}: /setname [ID]");
	if(!PlayerInfo[params[0]][pLogin] && !IsPlayerConnected(params[0])) return 1;
    new playerName[MAX_PLAYER_NAME+1];
    GetPVarString(params[0], "WantNickChange", playerName, MAX_PLAYER_NAME);
	if(!strlen(playerName)) return SCM(playerid,white,"����� �� ������� ����� �� ����� ����");
	format(stringer,128,"[A] %s ������ ��� ������ %s �� %s",PlayerInfo[playerid][pName],PlayerInfo[params[0]][pName],playerName);
	SCMA(0x00CC66FF,stringer);

	if(GetPVarInt(params[0],"changename_fix")) return 1;
	ChangeName(params[0]);
	return 1;
}
publics CallChangeName(playerid)
{
	new rows, fields;
	cache_get_data(rows, fields);
	if(rows)
	{
		SCM(playerid, white, "������ ������� �����");
		DeletePVar(playerid,"WantNickChange");
		return 1;
	}

 	new playerName[MAX_PLAYER_NAME+1];
    GetPVarString(playerid, "WantNickChange", playerName, MAX_PLAYER_NAME);

	format(stringer,512,"[A] %s[%d] ����� ����� �� ����� ����. �������� ���: %s",PlayerInfo[playerid][pName],playerid,playerName);
	SCMA(0x00CC66FF,stringer);
	SCMA(0x00CC66FF,"����� ������� ��� ��� ����������� /setname");
	SCM(playerid, white, "{"cgreen"}� [�������]{"cwhite"}: ������ �� ����� ���� ���������� �������������");
	return 1;
}
stock ChangeName(playerid)
{
 	new playerName[MAX_PLAYER_NAME+1];
    GetPVarString(playerid, "WantNickChange", playerName, MAX_PLAYER_NAME);

    stringer[0] = EOS;
	format(stringer,512, "UPDATE `accounts` SET `pName` = '%s' WHERE `pName` = '%s' LIMIT 1",playerName,PlayerInfo[playerid][pName]);
	mysql_tquery(connects, stringer, "", "");

	format(stringer, 512, "UPDATE `referals` SET `login` = '%s' WHERE `login` = '%s'", playerName,PlayerInfo[playerid][pName]);
	mysql_tquery(connects, stringer, "", "");

	format(stringer, 512, "UPDATE `referals` SET `login_invited` = '%s' WHERE `login_invited` = '%s'", playerName,PlayerInfo[playerid][pName]);
	mysql_tquery(connects, stringer, "", "");

	format(stringer, 512, "UPDATE `nakazania` SET `AdminName` = '%s' WHERE `AdminName` = '%s'", playerName,PlayerInfo[playerid][pName]);
	mysql_tquery(connects, stringer, "", "");

	format(stringer, 512, "UPDATE `nakazania` SET `Name` = '%s' WHERE `Name` = '%s'", playerName,PlayerInfo[playerid][pName]);
	mysql_tquery(connects, stringer, "", "");
	
	format(stringer, 512, "UPDATE `kvart` SET `kvart_Owner` = '%s' WHERE `kvart_Owner` = '%s'", playerName,PlayerInfo[playerid][pName]);
	mysql_tquery(connects, stringer, "", "");
	
	format(stringer, 512, "UPDATE `houses` SET `hOwner` = '%s' WHERE `hOwner` = '%s'", playerName,PlayerInfo[playerid][pName]);
	mysql_tquery(connects, stringer, "", "");
	
	format(stringer, 512, "UPDATE `fines` SET `fined` = '%s' WHERE `fined` = '%s'", playerName,PlayerInfo[playerid][pName]);
	mysql_tquery(connects, stringer, "", "");
	
	format(stringer, 512, "UPDATE `familys` SET `fCreatorName` = '%s' WHERE `fCreatorName` = '%s'", playerName,PlayerInfo[playerid][pName]);
	mysql_tquery(connects, stringer, "", "");
	
	format(stringer, 512, "UPDATE `bussines` SET `bOwner` = '%s' WHERE `bOwner` = '%s'", playerName,PlayerInfo[playerid][pName]);
	mysql_tquery(connects, stringer, "", "");
	
	format(stringer, 512, "UPDATE `bans` SET `AdminNick` = '%s' WHERE `AdminNick` = '%s'", playerName,PlayerInfo[playerid][pName]);
	mysql_tquery(connects, stringer, "", "");

	if(PlayerInfo[playerid][pBizID] != -1){
		foreach(new i : Allbusiness){
			if(BusinessInfo[i][bID] == PlayerInfo[playerid][pBizID]){
				format(BusinessInfo[i][bOwner], 50, "%s", playerName);
				UpdateBusiness(i);
				break;
			}
		}
	}
	if(PlayerInfo[playerid][pHomeID] != -1){
		foreach(new i : Allhouses){
			if(HouseInfo[i][hID] == PlayerInfo[playerid][pHomeID]){
				format(HouseInfo[i][hOwner], 50, "%s", playerName);
				SaveHouse(i);
				break;
			}
		}
	}
	if(PlayerInfo[playerid][pKvartID] != -1){
		foreach(new i : Allkvart){
			if(KvartInfo[i][kvart_id] == PlayerInfo[playerid][pKvartID]){
				format(KvartInfo[i][kvart_Owner], 50, "%s", playerName);
				SaveKvart(i);
				break;
			}
		}
	}

 	stringer[0] = EOS;
	new year, month, day, strstre[30];
 	getdate(year, month, day);
 	format(strstre,sizeof(strstre),"%d/%d/%d",day,month,year);
	mysql_format(connects, stringer, sizeof(stringer), "INSERT INTO `name_log` (`nOldName`, `nNewName`, `nDate`) VALUES ('%s', '%s', '%s')", PlayerInfo[playerid][pName], playerName, strstre);
	mysql_tquery(connects, stringer);

	format(stringer,100, "����� %s ������ ��� �� %s",PlayerInfo[playerid][pName],playerName);
	SCMA(orange, stringer);
	SetPVarInt(playerid,"changename_fix",true);
	SetPlayerName(playerid, playerName);
	strmid(PlayerInfo[playerid][pName], playerName, 0, strlen(playerName), 31);

 	SCM(playerid, white, "{"cgreen"}� [�������]{"cwhite"}: ��������� ����� ��� � ���� CR-MP");

	DeletePVar(playerid,"WantNickChange");
	return 1;
}