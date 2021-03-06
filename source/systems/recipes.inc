stock ShowDialogSelectRecipe(playerid)
{
	SPD
	(
		playerid, D_SELECT_RECIPE, DIALOG_STYLE_LIST,
		"{"cblue"}�������",
		"{"cblue"}1. {FFFFFF}���������\n"\
		"{"cblue"}2. {FFFFFF}���������-�������\n"\
		"{"cblue"}3. {FFFFFF}���������\n"\
		"{"cblue"}4. {FFFFFF}��������� ��������\n"\
		"{"cblue"}5. {FFFFFF}����������� ��������\n"\
		"{"cblue"}6. {FFFFFF}�������",
		"�������", "������"
    );
    return 1;
}

stock ShowDialogBuyRecipeGuns(playerid)
{
	SPD
	(
		playerid, D_BUY_RECIPE_GUNS, DIALOG_STYLE_LIST,
		"{"cblue"}���������\n",\
		"{"cblue"}1. {FFFFFF}9mm - 20 000 ������\n"\
		"{"cblue"}2. {FFFFFF}SDPistol - 40 000 ������\n"\
		"{"cblue"}3. {FFFFFF}���� - 100 000 ������",
		"�������", "�����"
    );
	return 1;
}

stock ShowDialogBuyRecipeGuns_2(playerid)
{
	SPD
	(
		playerid, D_BUY_RECIPE_GUNS_2, DIALOG_STYLE_LIST,
		"{"cblue"}���������-�������\n",\
		"{"cblue"}1. {FFFFFF}���-9 - 50 000 ������\n"\
		"{"cblue"}2. {FFFFFF}��� - 75 000 ������\n"\
		"{"cblue"}3. {FFFFFF}��5 - 120 000 ������",
		"�������", "�����"
    );
    return 1;
}

stock ShowDialogBuyRecipeGuns_3(playerid)
{
	SPD
	(
		playerid, D_BUY_RECIPE_GUNS_3, DIALOG_STYLE_LIST,
		"{"cblue"}���������\n",\
		"{"cblue"}1. {FFFFFF}������ - 120 000 ������\n"\
		"{"cblue"}2. {FFFFFF}����� - 150 000 ������\n"\
		"{"cblue"}3. {FFFFFF}������ �������� - 200 000 ������",
		"�������", "�����"
    );
    return 1;
}

stock ShowDialogBuyRecipeGuns_4(playerid)
{
	SPD
	(
		playerid, D_BUY_RECIPE_GUNS_4, DIALOG_STYLE_LIST,
		"{"cblue"}��������� ��������\n",\
		"{"cblue"}1. {FFFFFF}��-47 - 200 000 ������\n"\
		"{"cblue"}2. {FFFFFF}�4 - 300 000 ������",
		"�������", "�����"
    );
    return 1;
}

stock ShowDialogBuyRecipeGuns_5(playerid)
{
	SPD
	(
		playerid, D_BUY_RECIPE_GUNS_5, DIALOG_STYLE_LIST,
		"{"cblue"}����������� ��������\n",\
		"{"cblue"}1. {FFFFFF}Contry Rifle - 150 000 ������\n"\
		"{"cblue"}2. {FFFFFF}Sniper Rifle - 300 000 ������",
		"�������", "�����"
    );
    return 1;
}

stock ShowDialogBuyRecipeGuns_6(playerid)
{
	SPD
	(
		playerid, D_BUY_RECIPE_GUNS_6, DIALOG_STYLE_LIST,
		"{"cblue"}�������\n",\
		"{"cblue"}1. {FFFFFF}������� ������� - 150 000 ������\n"\
		"{"cblue"}2. {FFFFFF}�������� �������� - 300 000 ������\n"\
		"{"cblue"}3. {FFFFFF}���������� ������� - 600 000 ������",
		"�������", "�����"
    );
    return 1;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch(dialogid)
    {
        case D_SELECT_RECIPE:
        {
            if(!response) return 1;
            else
            {
                switch(listitem)
                {
                    case 0: ShowDialogBuyRecipeGuns(playerid);
                    case 1: ShowDialogBuyRecipeGuns_2(playerid);
                    case 2: ShowDialogBuyRecipeGuns_3(playerid);
                    case 3: ShowDialogBuyRecipeGuns_4(playerid);
                    case 4: ShowDialogBuyRecipeGuns_5(playerid);
                    case 5: ShowDialogBuyRecipeGuns_6(playerid);
                }
            }

        }
        case D_BUY_RECIPE_GUNS:
        {
            if(!response) return ShowDialogSelectRecipe(playerid);
            else
            {
                switch(listitem)
                {
                    case 0:
                    {
                        if(PlayerInfo[playerid][R_9MM] == 1)
                        {
                            ShowDialogBuyRecipeGuns(playerid);
                            return SCM(playerid, red, "� ��� ��� ���� ������ ������!");
                        }                       
                        if(PlayerInfo[playerid][pCash] < 20000)
                        {
                            ShowDialogBuyRecipeGuns(playerid);
                            return SCM(playerid, red, "� ��� �� ���������� �����!");
                        }

                        GiveMoney(playerid, -20000, "������� ������� �� ������");
                        SCM(playerid, green, "�� ������� ������ ������ ��� ������ 9MM!");
                        PlayerInfo[playerid][R_9MM] = 1;
                    }
                    case 1:
                    {
                        if(PlayerInfo[playerid][R_USP] == 1)
                        {
                            ShowDialogBuyRecipeGuns(playerid);
                            return SCM(playerid, red, "� ��� ��� ���� ������ ������!");
                        }                       
                        if(PlayerInfo[playerid][pCash] < 40000)
                        {
                            ShowDialogBuyRecipeGuns(playerid);
                            return SCM(playerid, red, "� ��� �� ���������� �����!");
                        }

                        GiveMoney(playerid, -40000, "������� ������� �� ������");
                        SCM(playerid, green, "�� ������� ������ ������ ��� ������ SDPistol!");
                        PlayerInfo[playerid][R_USP] = 1;
                    }
                    case 2:
                    {
                        if(PlayerInfo[playerid][R_DEAGLE] == 1)
                        {
                            ShowDialogBuyRecipeGuns(playerid);
                            return SCM(playerid, red, "� ��� ��� ���� ������ ������!");
                        }                       
                        if(PlayerInfo[playerid][pCash] < 100000)
                        {
                            ShowDialogBuyRecipeGuns(playerid);
                            return SCM(playerid, red, "� ��� �� ���������� �����!");
                        }

                        GiveMoney(playerid, -100000, "������� ������� �� ������");
                        SCM(playerid, green, "�� ������� ������ ������ ��� ������ Desert Eagle!");
                        PlayerInfo[playerid][R_DEAGLE] = 1;
                    }
                }

            }
        }
        case D_BUY_RECIPE_GUNS_2:
        {
            if(!response) return ShowDialogSelectRecipe(playerid);
            else
            {
                switch(listitem)
                {
                    case 0:
                    {
                        if(PlayerInfo[playerid][R_TEK9] == 1)
                        {
                            ShowDialogBuyRecipeGuns_2(playerid);
                            return SCM(playerid, red, "� ��� ��� ���� ������ ������!");
                        }                       
                        if(PlayerInfo[playerid][pCash] < 50000)
                        {
                            ShowDialogBuyRecipeGuns_2(playerid);
                            return SCM(playerid, red, "� ��� �� ���������� �����!");
                        }

                        GiveMoney(playerid, -50000, "������� ������� �� ������");
                        SCM(playerid, green, "�� ������� ������ ������ ��� ������ Tec9!");
                        PlayerInfo[playerid][R_TEK9] = 1;
                    }
                    case 1:
                    {
                        if(PlayerInfo[playerid][R_USI] == 1)
                        {
                            ShowDialogBuyRecipeGuns_2(playerid);
                            return SCM(playerid, red, "� ��� ��� ���� ������ ������!");
                        }                       
                        if(PlayerInfo[playerid][pCash] < 75000)
                        {
                            ShowDialogBuyRecipeGuns_2(playerid);
                            return SCM(playerid, red, "� ��� �� ���������� �����!");
                        }

                        GiveMoney(playerid, -75000, "������� ������� �� ������");
                        SCM(playerid, green, "�� ������� ������ ������ ��� ������ ���!");
                        PlayerInfo[playerid][R_USI] = 1;
                    }
                    case 2:
                    {
                        if(PlayerInfo[playerid][R_MP5] == 1)
                        {
                            ShowDialogBuyRecipeGuns_2(playerid);
                            return SCM(playerid, red, "� ��� ��� ���� ������ ������!");
                        }                       
                        if(PlayerInfo[playerid][pCash] < 120000)
                        {
                            ShowDialogBuyRecipeGuns_2(playerid);
                            return SCM(playerid, red, "� ��� �� ���������� �����!");
                        }

                        GiveMoney(playerid, -120000, "������� ������� �� ������");
                        SCM(playerid, green, "�� ������� ������ ������ ��� ������ ��5!");
                        PlayerInfo[playerid][R_MP5] = 1;
                    }
                }

            }
        }
        case D_BUY_RECIPE_GUNS_3:
        {
            if(!response) return ShowDialogSelectRecipe(playerid);
            else
            {
                switch(listitem)
                {
                    case 0:
                    {
                        if(PlayerInfo[playerid][R_SHOTGUN] == 1)
                        {
                            ShowDialogBuyRecipeGuns_3(playerid);
                            return SCM(playerid, red, "� ��� ��� ���� ������ ������!");
                        }                       
                        if(PlayerInfo[playerid][pCash] < 120000)
                        {
                            ShowDialogBuyRecipeGuns_3(playerid);
                            return SCM(playerid, red, "� ��� �� ���������� �����!");
                        }

                        GiveMoney(playerid, -120000, "������� ������� �� ������");
                        SCM(playerid, green, "�� ������� ������ ������ ��� ������ ������!");
                        PlayerInfo[playerid][R_SHOTGUN] = 1;
                    }
                    case 1:
                    {
                        if(PlayerInfo[playerid][R_SAWED_OF] == 1)
                        {
                            ShowDialogBuyRecipeGuns_3(playerid);
                            return SCM(playerid, red, "� ��� ��� ���� ������ ������!");
                        }                       
                        if(PlayerInfo[playerid][pCash] < 150000)
                        {
                            ShowDialogBuyRecipeGuns_3(playerid);
                            return SCM(playerid, red, "� ��� �� ���������� �����!");
                        }

                        GiveMoney(playerid, -150000, "������� ������� �� ������");
                        SCM(playerid, green, "�� ������� ������ ������ ��� ������ �����!");
                        PlayerInfo[playerid][R_SAWED_OF] = 1;
                    }
                    case 2:
                    {
                        if(PlayerInfo[playerid][R_FIGHT_SHOTGUN] == 1)
                        {
                            ShowDialogBuyRecipeGuns_3(playerid);
                            return SCM(playerid, red, "� ��� ��� ���� ������ ������!");
                        }                       
                        if(PlayerInfo[playerid][pCash] < 200000)
                        {
                            ShowDialogBuyRecipeGuns_3(playerid);
                            return SCM(playerid, red, "� ��� �� ���������� �����!");
                        }

                        GiveMoney(playerid, -200000, "������� ������� �� ������");
                        SCM(playerid, green, "�� ������� ������ ������ ��� ������ ������ ��������!");
                        PlayerInfo[playerid][R_FIGHT_SHOTGUN] = 1;
                    }
                }
            }
        }
        case D_BUY_RECIPE_GUNS_4:
        {
            if(!response) return ShowDialogSelectRecipe(playerid);
            else
            {
                switch(listitem)
                {
                    case 0:
                    {
                        if(PlayerInfo[playerid][R_AK47] == 1)
                        {
                            ShowDialogBuyRecipeGuns_4(playerid);
                            return SCM(playerid, red, "� ��� ��� ���� ������ ������!");
                        }                       
                        if(PlayerInfo[playerid][pCash] < 200000)
                        {
                            ShowDialogBuyRecipeGuns_4(playerid);
                            return SCM(playerid, red, "� ��� �� ���������� �����!");
                        }

                        GiveMoney(playerid, -200000, "������� ������� �� ������");
                        SCM(playerid, green, "�� ������� ������ ������ ��� ������ ��-47!");
                        PlayerInfo[playerid][R_AK47] = 1;
                    }
                    case 1:
                    {
                        if(PlayerInfo[playerid][R_M4] == 1)
                        {
                            ShowDialogBuyRecipeGuns_4(playerid);
                            return SCM(playerid, red, "� ��� ��� ���� ������ ������!");
                        }                       
                        if(PlayerInfo[playerid][pCash] < 300000)
                        {
                            ShowDialogBuyRecipeGuns_4(playerid);
                            return SCM(playerid, red, "� ��� �� ���������� �����!");
                        }

                        GiveMoney(playerid, -300000, "������� ������� �� ������");
                        SCM(playerid, green, "�� ������� ������ ������ ��� ������ �4!");
                        PlayerInfo[playerid][R_M4] = 1;
                    }
                }
            }
        }
        case D_BUY_RECIPE_GUNS_5:
        {
            if(!response) return ShowDialogSelectRecipe(playerid);
            else
            {
                switch(listitem)
                {
                    case 0:
                    {
                        if(PlayerInfo[playerid][R_COUNTRY_RIFLE] == 1)
                        {
                            ShowDialogBuyRecipeGuns_5(playerid);
                            return SCM(playerid, red, "� ��� ��� ���� ������ ������!");
                        }                       
                        if(PlayerInfo[playerid][pCash] < 150000)
                        {
                            ShowDialogBuyRecipeGuns_5(playerid);
                            return SCM(playerid, red, "� ��� �� ���������� �����!");
                        }

                        GiveMoney(playerid, -150000, "������� ������� �� ������");
                        SCM(playerid, green, "�� ������� ������ ������ ��� ������ Country Rifle!");
                        PlayerInfo[playerid][R_COUNTRY_RIFLE] = 1;
                    }
                    case 1:
                    {
                        if(PlayerInfo[playerid][R_SNIPER_RIFLE] == 1)
                        {
                            ShowDialogBuyRecipeGuns_5(playerid);
                            return SCM(playerid, red, "� ��� ��� ���� ������ ������!");
                        }                       
                        if(PlayerInfo[playerid][pCash] < 300000)
                        {
                            ShowDialogBuyRecipeGuns_5(playerid);
                            return SCM(playerid, red, "� ��� �� ���������� �����!");
                        }

                        GiveMoney(playerid, -300000, "������� ������� �� ������");
                        SCM(playerid, green, "�� ������� ������ ������ ��� ������ ������������ ���������!");
                        PlayerInfo[playerid][R_SNIPER_RIFLE] = 1;
                    }
                }
            }
        }
        case D_BUY_RECIPE_GUNS_6:
        {
            if(!response) return ShowDialogSelectRecipe(playerid);
            else
            {
                switch(listitem)
                {
                    case 0:
                    {
                        if(PlayerInfo[playerid][R_SMOKE] == 1)
                        {
                            ShowDialogBuyRecipeGuns_6(playerid);
                            return SCM(playerid, red, "� ��� ��� ���� ������ ������!");
                        }                       
                        if(PlayerInfo[playerid][pCash] < 150000)
                        {
                            ShowDialogBuyRecipeGuns_6(playerid);
                            return SCM(playerid, red, "� ��� �� ���������� �����!");
                        }

                        GiveMoney(playerid, -150000, "������� ������� �� ������");
                        SCM(playerid, green, "�� ������� ������ ������ ��� ������ ������� �������!");
                        PlayerInfo[playerid][R_SMOKE] = 1;
                    }
                    case 1:
                    {
                        if(PlayerInfo[playerid][R_MOLOTOV] == 1)
                        {
                            ShowDialogBuyRecipeGuns_6(playerid);
                            return SCM(playerid, red, "� ��� ��� ���� ������ ������!");
                        }                       
                        if(PlayerInfo[playerid][pCash] < 300000)
                        {
                            ShowDialogBuyRecipeGuns_6(playerid);
                            return SCM(playerid, red, "� ��� �� ���������� �����!");
                        }

                        GiveMoney(playerid, -300000, "������� ������� �� ������");
                        SCM(playerid, green, "�� ������� ������ ������ ��� ������ �������� ��������!");
                        PlayerInfo[playerid][R_MOLOTOV] = 1;
                    }
                    case 2:
                    {
                        if(PlayerInfo[playerid][R_GRENADE] == 1)
                        {
                            ShowDialogBuyRecipeGuns_6(playerid);
                            return SCM(playerid, red, "� ��� ��� ���� ������ ������!");
                        }                       
                        if(PlayerInfo[playerid][pCash] < 600000)
                        {
                            ShowDialogBuyRecipeGuns_6(playerid);
                            return SCM(playerid, red, "� ��� �� ���������� �����!");
                        }

                        GiveMoney(playerid, -600000, "������� ������� �� ������");
                        SCM(playerid, green, "�� ������� ������ ������ ��� ������ ���������� �������!");
                        PlayerInfo[playerid][R_GRENADE] = 1;
                    }
                    
                }
            }
        }
    }
	#if	defined	recipes__OnDialogResponse
		return recipes__OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnDialogResponse
	#undef	OnDialogResponse
#else
	#define	_ALS_OnDialogResponse
#endif

#define	OnDialogResponse recipes__OnDialogResponse
#if	defined	recipes__OnDialogResponse
	forward recipes__OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys == 1024)
    {
        if(IsPlayerInRangeOfPoint(playerid, 2.0, 2003.2611,1339.8290,26.1513))
        {
            ShowDialogSelectRecipe(playerid);
        }
    }
	#if	defined	recipes__OnPlayerKeyStateChange
		return recipes__OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnPlayerKeyStateChange
	#undef	OnPlayerKeyStateChange
#else
	#define	_ALS_OnPlayerKeyStateChange
#endif

#define	OnPlayerKeyStateChange recipes__OnPlayerKeyStateChange
#if	defined	recipes__OnPlayerKeyStateChange
	forward recipes__OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
#endif