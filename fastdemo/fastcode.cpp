#include <iostream>
#include <vector>

#define PY_SSIZE_T_CLEAN
#include "Python.h"

// helpful resource https://github.com/microsoft/python-sample-vs-cpp-extension/blob/master/superfastcode/module.cpp

double square(double n) {
	return n*n;
}

std::vector<int> primes(int n_primes) {
	std::vector<int> primes;
	primes.push_back(1);
	primes.push_back(2);
	int found_length = 2;
	int is_prime = 1;
	int n = 3;

	while (found_length < n_primes) {
		is_prime = 1;
		for (int i=1;i<found_length;i++) {
			if (n % primes[i] == 0) {
				is_prime = 0;
				break;
			}
			if (primes[i] * primes[i] > n) {
				break;
			}
		}
		if (is_prime == 1) {
			primes.push_back(n);
			found_length++;
		}
		n = n + 2;
	}
	return primes;
}


PyObject* fastsquare(PyObject *, PyObject* o) {
	double value = PyFloat_AsDouble(o);
	return PyFloat_FromDouble(square(value));
}

PyObject* fastprimes(PyObject *, PyObject* o) {
	int intvalue = PyLong_AsLong(o);
	std::vector<int> canswer = primes(intvalue);
	PyObject* listObj = PyList_New(0);

	for (int i=0;i<canswer.size();i++) {
		PyObject* num = PyLong_FromLong(canswer[i]);
		PyList_Append(listObj, num);
	}
	return listObj;
}

static struct PyMethodDef fastcode_methods[] = {
	// The first property is the name exposed to Python, testfunc, the second is the C++
	// function name that contains the implementation.
	{ "fastsquare", (PyCFunction)fastsquare, METH_O, nullptr },
	{ "fastprimes", (PyCFunction)fastprimes, METH_O, nullptr},
	// Terminate the array with an object containing nulls.
	{ nullptr, nullptr, 0, nullptr }
};

static PyModuleDef fastcode_module = {
	PyModuleDef_HEAD_INIT,
	"fastcode",                        // Module name to use with Python import statements
	"Provides some functions, but faster",  // Module description
	0,
	fastcode_methods                   // Structure that defines the methods of the module
};

PyMODINIT_FUNC PyInit_fastcode() {
	return PyModule_Create(&fastcode_module);
}
