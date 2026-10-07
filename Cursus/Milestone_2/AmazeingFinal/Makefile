PYTHON = python3
PIP = pip3
MAIN = a_maze_ing.py
VENV = .venv
WHL = mlx-2.2-py3-none-any.whl

install:
	$(PIP) install -r requirements.txt
	$(PIP) install $(WHL)

run:
	$(PYTHON) $(MAIN) config.txt

validate:
	$(PYTHON) maze_analyzer.py maze.txt

debug:
	$(PYTHON) -m pdb $(MAIN) config.txt

clean:
	rm -rf __pycache__
	rm -rf .mypy_cache
	find . -type d -name "__pycache__" -exec rm -rf {} +
	rm -rf mazegen.egg-info

fclean: clean
	rm -rf $(VENV)
	rm -f maze.txt

lint:
	flake8 .
	mypy . --warn-return-any \
	       --warn-unused-ignores \
	       --ignore-missing-imports \
	       --disallow-untyped-defs \
	       --check-untyped-defs

lint-strict:
	flake8 .
	mypy . --strict