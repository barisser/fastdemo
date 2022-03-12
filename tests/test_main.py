import time

import fastdemo


def test_primes():
	start = time.time()
	primes1 = fastdemo.python_primes(3*10**3)
	python_primes_time = time.time() - start

	print("Pure Python time: {}".format(python_primes_time))
