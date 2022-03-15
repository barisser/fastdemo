#from cpython.mem cimport PyMem_Malloc, PyMem_Realloc, PyMem_Free
from libc.stdlib cimport malloc, free

def cython_lite_primes(nb_primes):
    """
    Clone of our pure python implementation, but
    compiled with Cython.
    Let's not add any Cython magic to this 'lite' version
    so we can see what just Cython alone can do to vanilla Python.
    """
    found = [2]
    found_length = 2
    n = 3

    while found_length < nb_primes:
        is_prime = True
        for f in found:
            if n % f == 0:
                is_prime = False
                break
            if f*f > n:
                break

        if is_prime:
            found.append(n)
            found_length += 1
        n += 2

    return [1] + found


def cython_primes(int nb_primes):
    """
    Clone of our pure python implementation, but
    compiled with Cython.
    This time we actually try to optimize using Cython.
    """
    if nb_primes > 100000:
        nb_primes = 100000
    cdef int[100000] found
    found[0] = 1
    found[1] = 2
    cdef int found_length = 2
    cdef int n = 3
    cdef int i

    while found_length < nb_primes:
        is_prime = True
        i = 1
        while i < found_length and is_prime:
            f = found[i]
            if n % f == 0:
                is_prime = False
                break
            if f*f > n:
                break
            i += 1

        if is_prime:
            found[found_length] = n
            found_length = found_length + 1
        n += 2

    return found