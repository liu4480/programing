#include <iostream>
#include "Python.h"

using namespace std;
//g++ main.cpp -o main -I/usr/include/python2.7/ -lpython2.7
int function_from_python(int a, int b)
{
    Py_Initialize();

    int res;
    PyObject *pModule = NULL;
    PyObject *pFunc = NULL;
    PyObject *pArgs = NULL;
    PyObject *pResult = NULL;

    PyRun_SimpleString("import sys");  
    PyRun_SimpleString("print '---import sys---'");   
    PyRun_SimpleString("sys.path.append('./')");

    if(!(pModule = PyImport_Import(PyString_FromString("python_called"))))
    //if(!(pModule=PyImport_Import(PyString_FromString("math"))))
    {
        cout << "Get module failed!" << endl;
        exit(-1);
    }

    if(!(pFunc = PyObject_GetAttrString(pModule, "add_func")))
    {
        cout << "Get func failed!" << endl;
        exit(-2);
    }

    pArgs = Py_BuildValue("ii", a, b);

    pResult = PyObject_CallObject(pFunc, pArgs);

    res = PyInt_AsLong(pResult);

    if(pArgs)
        Py_DECREF(pArgs);
    if(pFunc)
        Py_DECREF(pFunc);

    Py_Finalize();

    return res;
}

int main()
{
    cout << "C/C++ call python function:" << endl;
    cout << function_from_python(3, 5) << endl;
    return 0;
}
