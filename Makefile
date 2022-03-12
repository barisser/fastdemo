clean:
	rm -rf build; rm -rf dist; rm -rf *.egg-info; rm -rf fastdemo/*.so;rm -rf fastdemo/*.c

venv:
	virtualenv venv && . venv/bin/activate && pip install setup.py && pip install cython

build: clean
	python setup.py build_ext --inplace

test: build
	python setup.py install && pytest -s -vvv --pdb tests

publish:
	rm -rf dist && python setup.py sdist bdist_wheel && \
	twine upload --repository-url https://upload.pypi.org/legacy/ dist/*
