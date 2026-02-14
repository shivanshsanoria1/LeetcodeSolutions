## Commands

### Run 'stats-generator.sh'
```
./stats/generator/stats-generator-script.sh
```

#### Give permissions (before running)
```
chmod +x ./stats/generator/stats-generator.sh
```

### Run 'stats-generator.js'
```
node ./stats/generator/stats-generator.js
```

---

### Run 'chart-generator.py'
```
source ./stats/generator/.venv/bin/activate
```

```
python3 ./stats/generator/chart-generator.py
```

```
deactivate
```

#### Setup the virtual environment (before step-1)
```
python3 -m venv ./stats/generator/.venv
```

#### Needs the following dependencies installed (before step-2)
```
pip install matplotlib
pip install PyGObject
pip install config
```

#### OR

#### Recreate the same environment with
```
pip install -r ./stats/setup-info/requirements.txt
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
