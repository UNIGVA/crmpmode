publics minuteupdate()
{
    {
        new hour, minute, second;
        gettime(hour, minute, second);

        if(minute % 10 == 0)
        {
            if(minute % 2 == 0) 
                AdvertiseOne();
            else 
                AdvertiseTwo();
        }
    }
    #if defined advert__minuteupdate
        return advert__minuteupdate();
    #else
        return 1;
    #endif
}
#if defined _ALS_minuteupdate
    #undef minuteupdate
#else 
    #define _ALS_minuteupdate
#endif

#define minuteupdate advert__minuteupdate
#if defined advert__minuteupdate
    forward advert__minuteupdate();
#endif

stock AdvertiseOne()
{
	SendClientMessageToAll(lightgreen,"__________________________________________________________________________________________________________");
	SendClientMessageToAll(lightgreen,"                                                                                                          ");
    SendClientMessageToAll(-1,"{99CC00}��������� �������������� �������: vk.com/un_chernov /donate");
    SendClientMessageToAll(-1,"{99CC00}������� ����� - ������ ������. ��� ����������� ���������� ������� ��� ���");
    SendClientMessageToAll(-1,"{99CC00}��� ������������� ��������/�����, �������: /menu, ����� ��������: \"�������/������ �� �������\"");
    SendClientMessageToAll(-1,"{99CC00}��� �������� ���������� �� ������ ����� � /gps, /menu");
    SendClientMessageToAll(lightgreen,"__________________________________________________________________________________________________________");
}

stock AdvertiseTwo()
{
	SendClientMessageToAll(lightblue,"__________________________________________________________________________________________________________");
	SendClientMessageToAll(lightblue,"                                                                                                          ");
    SendClientMessageToAll(blue,"�������������� �� ������ �������: vk.com/unigvafre");
    SendClientMessageToAll(blue,"�������, ����������� � �������� ������� ��� ���");
    SendClientMessageToAll(lightblue,"__________________________________________________________________________________________________________");
}