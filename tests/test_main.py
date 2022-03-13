import time

import fastcode
import fastdemo


def benchmark_primes(func, n):
	start = time.time()
	answer = func(n)
	return time.time() - start, answer


def test_primes():
	n_primes = 10000

	funcs = [fastdemo.python_primes, fastdemo.cython_lite_primes, fastdemo.cython_primes, fastcode.fastprimes]

	for f in funcs:
		t, answer = benchmark_primes(f, n_primes)
		assert answer[100] == 541
		print("Function {} took {} seconds.".format(f.__name__, t))
