


def python_primes(nb_primes):
    """
    Pure python and not very smart prime finder.
    Yes, yes I know there are better algorithms.
    This is a benchmark and that doesn't matter.
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