#ifndef PYHELPER_HPP
#define PYHELPER_HPP
#pragma once

// The installed Python distribution only ships release import libraries
// (no python3xx_d.lib). Temporarily undefine _DEBUG so Python.h doesn't
// request the debug-suffixed library when building this project in Debug mode.
#ifdef _DEBUG
#define PYHELPER_RESTORE_DEBUG
#undef _DEBUG
#endif
#include <Python.h>
#ifdef PYHELPER_RESTORE_DEBUG
#define _DEBUG
#undef PYHELPER_RESTORE_DEBUG
#endif

class CPyInstance
{
public:
	CPyInstance()
	{
		Py_Initialize();
	}

	~CPyInstance()
	{
		Py_Finalize();
	}
};


class CPyObject
{
private:
	PyObject *p;
public:
	CPyObject() : p(NULL)
	{}

	CPyObject(PyObject* _p) : p(_p)
	{}


	~CPyObject()
	{
		Release();
	}

	PyObject* getObject()
	{
		return p;
	}

	PyObject* setObject(PyObject* _p)
	{
		return (p = _p);
	}

	PyObject* AddRef()
	{
		if (p)
		{
			Py_INCREF(p);
		}
		return p;
	}

	void Release()
	{
		if (p)
		{
			Py_DECREF(p);
		}

		p = NULL;
	}

	PyObject* operator ->()
	{
		return p;
	}

	bool is()
	{
		return p ? true : false;
	}

	operator PyObject*()
	{
		return p;
	}

	PyObject* operator = (PyObject* pp)
	{
		p = pp;
		return p;
	}

	operator bool()
	{
		return p ? true : false;
	}
};

#endif
