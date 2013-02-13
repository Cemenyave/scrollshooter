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

	//Создаёт обработчик заданного типа в динамической памяти, сохраняет указатель на него в пуле обработчиков и возвращает полученный указатель
	Handler *AddHandler(Handler *rHandler);

	//Удаляет обработчик
	void DropHandler(Handler *rObjHandler);

	//Регистрирует тип обработчика
	void RegistrHandlerType(std::string rhandlerType);

	void ClearHandlerPool(void);
};

