CMD:agl(playerid, params[])
{
    if(PlayerInfo[playerid][bAdmin] < 5) return ShowCommandNotFound(playerid);

    extract params -> new to_player, what, count; else
	{
	    SCM(playerid, blue, "[���������] {ffffff}�������: /agl [id ������] [�����] [��������]");
	    SCM(playerid, white, "[�����]: ���������: 1 - A | 2 - B | 3 - C | 4 - D | ��������: 5 - �� ������� | 6 - �� ������ | 7 - �� ������");
        SCM(playerid, white, "[��������]: 0 - �������; 1 - ������;");
 		return 1;
	}
    switch(what)
    {
        case 0:
        {
		    if(count > 1 || count < 0) return SCM(playerid, red, " �� ����� 0 � �� ����� 1!");
			PlayerInfo[to_player][pLicA] = count;
			PlayerInfo[to_player][pLicB] = count;
			PlayerInfo[to_player][pLicC] = count;
			PlayerInfo[to_player][pLicD] = count;

            PlayerInfo[to_player][pLicBiz] = count;
            PlayerInfo[to_player][pLicFly] = count;
            PlayerInfo[to_player][pLicGun] = count;
			new string[128];
			if(count == 1)
			{
				format(string, sizeof(string), "�� ������ ������ %s ��� ��������", PlayerInfo[to_player][pName]);
				SCM(playerid, white, string);

				format(string, sizeof(string), "������������� %s ����� ��� ��� ��������", PlayerInfo[playerid][pName]);
				SCM(to_player, white, string);
			}
			else
			{
				format(string, sizeof(string), "�� ������� � ������ %s ��� ��������", PlayerInfo[to_player][pName]);
				SCM(playerid, white, string);

				format(string, sizeof(string), "������������� %s ������ � ��� ��� ��������", PlayerInfo[playerid][pName]);
				SCM(to_player, white, string);
			}           
        }
    	case 1:
		{
		    if(count > 1 || count < 0) return SCM(playerid, red, " �� ����� 0 � �� ����� 1!");
			PlayerInfo[to_player][pLicA] = count;
			new string[128];
			if(count == 1)
			{
				format(string, sizeof(string), "�� ������ ������ %s ����� ��������� A", PlayerInfo[to_player][pName]);
				SCM(playerid, white, string);

				format(string, sizeof(string), "������������� %s ����� ��� ����� ��������� A", PlayerInfo[playerid][pName]);
				SCM(to_player, white, string);
			}
			else
			{
				format(string, sizeof(string), "�� ������� � ������ %s ����� ��������� A", PlayerInfo[to_player][pName]);
				SCM(playerid, white, string);

				format(string, sizeof(string), "������������� %s ������ � ��� ����� ��������� A", PlayerInfo[playerid][pName]);
				SCM(to_player, white, string);
			}
		}
		case 2:
		{
		    if(count > 1 || count < 0) return SCM(playerid, red, " �� ����� 0 � �� ����� 1!");
			PlayerInfo[to_player][pLicB] = count;
			new string[128];
			if(count == 1)
			{
				format(string, sizeof(string), "�� ������ ������ %s ����� ��������� B", PlayerInfo[to_player][pName]);
				SCM(playerid, white, string);

				format(string, sizeof(string), "������������� %s ����� ��� ����� ��������� B", PlayerInfo[playerid][pName]);
				SCM(to_player, white, string);
			}
			else
			{
				format(string, sizeof(string), "�� ������� � ������ %s ����� ��������� B", PlayerInfo[to_player][pName]);
				SCM(playerid, white, string);

				format(string, sizeof(string), "������������� %s ������ � ��� ����� ��������� B", PlayerInfo[playerid][pName]);
				SCM(to_player, white, string);
			}
		}
		case 3:
		{
		    if(count > 1 || count < 0) return SCM(playerid, red, " �� ����� 0 � �� ����� 1!");
			PlayerInfo[to_player][pLicC] = count;
			new string[128];
			if(count == 1)
			{
				format(string, sizeof(string), "�� ������ ������ %s ����� ��������� C", PlayerInfo[to_player][pName]);
				SCM(playerid, white, string);

				format(string, sizeof(string), "������������� %s ����� ��� ����� ��������� C", PlayerInfo[playerid][pName]);
				SCM(to_player, white, string);
			}
			else
			{
				format(string, sizeof(string), "�� ������� � ������ %s ����� ��������� C", PlayerInfo[to_player][pName]);
				SCM(playerid, white, string);

				format(string, sizeof(string), "������������� %s ������ � ��� ����� ��������� C", PlayerInfo[playerid][pName]);
				SCM(to_player, white, string);
			}
		}
		case 4:
		{
		    if(count > 1 || count < 0) return SCM(playerid, red, " �� ����� 0 � �� ����� 1!");
			PlayerInfo[to_player][pLicD] = count;
			new string[128];
			if(count == 1)
			{
				format(string, sizeof(string), "�� ������ ������ %s ����� ��������� D", PlayerInfo[to_player][pName]);
				SCM(playerid, white, string);

				format(string, sizeof(string), "������������� %s ����� ��� ����� ��������� D", PlayerInfo[playerid][pName]);
				SCM(to_player, white, string);
			}
			else
			{
				format(string, sizeof(string), "�� ������� � ������ %s ����� ��������� D", count, PlayerInfo[to_player][pName]);
				SCM(playerid, white, string);

				format(string, sizeof(string), "������������� %s ������ � ��� ����� ��������� D", PlayerInfo[playerid][pName]);
				SCM(to_player, white, string);
			}
		}
        case 5:
        {
		    if(count > 1 || count < 0) return SCM(playerid, red, " �� ����� 0 � �� ����� 1!");
			PlayerInfo[to_player][pLicBiz] = count;
			new string[128];
			if(count == 1)
			{
				format(string, sizeof(string), "�� ������ ������ %s �������� �� �������", PlayerInfo[to_player][pName]);
				SCM(playerid, white, string);

				format(string, sizeof(string), "������������� %s ����� �������� �� �������", PlayerInfo[playerid][pName]);
				SCM(to_player, white, string);
			}
			else
			{
				format(string, sizeof(string), "�� ������� � ������ %s �������� �� �������", count, PlayerInfo[to_player][pName]);
				SCM(playerid, white, string);

				format(string, sizeof(string), "������������� %s ������ � ��� �������� �� �������", PlayerInfo[playerid][pName]);
				SCM(to_player, white, string);
			}
        }
        case 6:
        {
		    if(count > 1 || count < 0) return SCM(playerid, red, " �� ����� 0 � �� ����� 1!");
			PlayerInfo[to_player][pLicFly] = count;
			new string[128];
			if(count == 1)
			{
				format(string, sizeof(string), "�� ������ ������ %s �������� �� �����", PlayerInfo[to_player][pName]);
				SCM(playerid, white, string);

				format(string, sizeof(string), "������������� %s ����� �������� �� �����", PlayerInfo[playerid][pName]);
				SCM(to_player, white, string);
			}
			else
			{
				format(string, sizeof(string), "�� ������� � ������ %s �������� �� �����", count, PlayerInfo[to_player][pName]);
				SCM(playerid, white, string);

				format(string, sizeof(string), "������������� %s ������ � ��� �������� �� �����", PlayerInfo[playerid][pName]);
				SCM(to_player, white, string);
			}
        }
        case 7:
        {
		    if(count > 1 || count < 0) return SCM(playerid, red, " �� ����� 0 � �� ����� 1!");
			PlayerInfo[to_player][pLicGun] = count;
			new string[128];
			if(count == 1)
			{
				format(string, sizeof(string), "�� ������ ������ %s �������� �� ������", PlayerInfo[to_player][pName]);
				SCM(playerid, white, string);

				format(string, sizeof(string), "������������� %s ����� �������� �� ������", PlayerInfo[playerid][pName]);
				SCM(to_player, white, string);
			}
			else
			{
				format(string, sizeof(string), "�� ������� � ������ %s �������� �� ������", count, PlayerInfo[to_player][pName]);
				SCM(playerid, white, string);

				format(string, sizeof(string), "������������� %s ������ � ��� �������� �� ������", PlayerInfo[playerid][pName]);
				SCM(to_player, white, string);
			}
        }
        default:
        {
            SCM(playerid, blue, "[���������] {ffffff}�������: /agl [id ������] [�����] [��������]");
            SCM(playerid, white, "[�����]: ���������: 1 - A | 2 - B | 3 - C | 4 - D | ��������: 5 - �� ������� | 6 - �� ������ | 7 - �� ������");
            SCM(playerid, white, "[��������]: 0 - �������; 1 - ������;");           
        }
    }
    return 1;
}