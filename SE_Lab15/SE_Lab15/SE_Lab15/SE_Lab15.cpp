#include "stdafx.h"
#include <iostream>
#include <locale>
#include <cwchar>

#include "Error.h"	//��������� ������
#include "Parm.h"	//��������� ����������
#include "Log.h"	//������ � ����������
#include "In.h"		//���� ��������� �����

int _tmain(int argc, _TCHAR* argv[]) 
{
	setlocale(LC_ALL, "rus");


	std::cout << " --- ���� IN::getin --- " << std::endl << std::endl;
	try
	{
		Parm::PARM parm = Parm::getparm(argc, argv);
		In::IN in = In::getin(parm.in);
		std::cout << in.text << std::endl;
		std::cout << "����� ��������: " << in.size << std::endl;
		std::cout << "����� �����: " << in.lines << std::endl;
		std::cout << "����������: " << in.ignor << std::endl;
		std::ofstream Out(parm.out);
		Out << in.text;
		Out.close();
	}
	catch (Error::ERROR e) {
		std::cout << "������ " << e.id << ": " << e.message << std::endl << std::endl;
	};

	Log::LOG log;
	try
	{
		Parm::PARM parm = Parm::getparm(argc, argv);
		log = Log::getlog(parm.log);
		Log::WriteLine(log, (char*)"����:", (char*)" ��� ������ \n", "");
		Log::WriteLine(log, (char*)"����:", (char*)" ��� ������ \n", "");
		Log::WriteLog(log);
		Log::WriteParm(log, parm);
		In::IN in = In::getin(parm.in);
		Log::WriteIn(log, in);
		Log::Close(log);
	}
	catch(Error::ERROR e)
	{
		Log::WriteError(log, e);
	};


	system("pause");
	return 0;
}

