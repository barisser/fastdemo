


def python_primes(nb_primes):
    found = [2]

    if nb_primes > 10**4:
        nb_primes = 10**4

    found_length = 1
    n = 3

    while found_length < nb_primes:
        is_prime = True
        for f in found:
            if n % f == 0:
                is_prime = False

        if is_prime:
            found.append(n)
            found_length += 1
        n += 2

    return found