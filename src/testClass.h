#ifndef _TESTCLASS_H_
#define _TESTCLASS_H_

class A
{
private:
public:
	A();
	virtual ~A();
	virtual void poop(void) const = 0;
};

class B : public A
{
private:
public:
	B();
	~B();
	//void poop(void) const {}
};

template<class T>
class C : public A
{
private:
public:
	C();
	~C();
	void poop(void) const {}
};

template<class T>
class D
{
private:
public:
	D();
	virtual ~D();
	virtual void pop(void) const = 0;
};

template<class T>
inline void D<T>::pop(void) const {}

class E : public D<int>
{
private:

public:
	E();
	virtual ~E();
	//virtual void pop(void) const {}
};





#endif