#pragma once


struct Mutex
{
	bool Locked;
	Mutex() : Locked(false)
	{};
};


void lock(Mutex *pm); // lock mutex pointed to pm
void unlock(Mutex *pm); // unlock the mutex

class Uncopyable
{
protected:
	Uncopyable() {};
	~Uncopyable() {};
private:
	Uncopyable(const Uncopyable&);
	Uncopyable& operator=(const Uncopyable&);
};


class Lock //: private Uncopyable
{
public:
	explicit Lock(Mutex *pm) : mutexPtr(pm, unlock)	// init shared_ptr with the Mutex to point to and the unlock func as deleter
	{
		lock(mutexPtr.get());	// acquire resource
	}
	// destructor is not needed, rely on default copmpiler-generated

private:
	std::tr1::shared_ptr<Mutex> mutexPtr;	// use shared_ptr instead of raw pointer
};




