## Commands

### Run 'stats-generator.js'

```
node ./stats/stats-generator.js
```

---

### Run 'chart-generator.py'

```
source ./stats/.venv/bin/activate
```

```
python3 ./stats/chart-generator.py
```

```
deactivate
```

#### Needs the following dependencies installed (before step 2)

```
pip install matplotlib
pip install PyGObject
pip install config
```

#### OR

#### Recreate the same environment with

```
pip install -r ./stats/requirements.txt
```

#### Find the dependencies currently installed

```
pip list --format=freeze
```

---

### Push code to github repo

```
git add .
```

```
git commit -m "message goes here"
```

```
git push -u origin main
```

---
