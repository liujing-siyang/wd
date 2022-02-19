#ifndef __WD_TEMPLATE_SINGLETON_H__
#define __WD_TEMPLATE_SINGLETON_H__

#include <iostream>
using std::cout;
using std::endl;


template <class T>
class Singleton
{
public:
	template <class... Args>//<typename T1, typename T2,......>
	static T * getInstance(Args... args)//T1 t1, T2 t2//T1 = int a float b double d 
	{
		if(nullptr == _pInstance)
        {
			_pInstance = new T(args...);
			_auto;//为了在模板参数推导时创建_auto对象
		}
		return _pInstance;
	}

private:
	class AutoRelease
	{
	public:
		AutoRelease()
        {	
            cout << "AutoRelease()" << endl;	
        }

		~AutoRelease()
        {
			if(_pInstance)
            {
				delete _pInstance;
				cout << "~AutoRelease()" << endl;
			}
		}
	};

private:
	Singleton()
    {
        cout << "Singleton()" << endl;
    }

	~Singleton()
    {
        cout << "~Singleton()" << endl;
    }

private:
	static T * _pInstance;
	static AutoRelease _auto;//int a
};

template <class T> 
T * Singleton<T>::_pInstance = nullptr;

template <class T>
typename Singleton<T>::AutoRelease Singleton<T>::_auto;

#endif
