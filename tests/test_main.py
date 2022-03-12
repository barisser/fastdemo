import time

import fastdemo


def benchmark_primes(func, n):
	start = time.time()
	_ = func(n)
	return time.time() - start


def test_primes():
	n_primes = 1000

	funcs = [fastdemo.python_primes, fastdemo.cython_lite_primes, fastdemo.cython_primes]

	for f in funcs:
		t = benchmark_primes(f, n_primes)
		print("Function {} took {} seconds.".format(f.__name__, t))
