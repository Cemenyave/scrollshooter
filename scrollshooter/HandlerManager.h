#pragma once
class Handler;
class HandlerManager
{
	typedef std::shared_ptr<Handler> HandlerPtr;
	typedef std::vector<HandlerPtr> HandlerPool;

	HandlerPool mHandlerPool;
public:
	HandlerManager(void);
	~HandlerManager(void);

	//������ ���������� ��������� ���� � ������������ ������, ��������� ��������� �� ���� � ���� ������������ � ���������� ���������� ���������
	Handler *AddHandler(Handler *rHandler);

	//������� ����������
	void DropHandler(Handler *rObjHandler);

	//������������ ��� �����������
	void RegistrHandlerType(std::string rhandlerType);

	void ClearHandlerPool(void);
};

