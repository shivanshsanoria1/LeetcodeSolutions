## Commands

### 1. Run 'stats-generator-script.sh'
```
./stats/generator/stats-generator-script.sh
```

#### 1.1 Give permissions (before running)
```
chmod +x ./stats/generator/stats-generator-script.sh
```

---

### 2. Run 'stats-generator.js'
```
node ./stats/generator/stats-generator.js
```

---

### 3. Run 'chart-generator.py'
```
source ./stats/generator/.venv/bin/activate
```

```
python3 ./stats/generator/chart-generator.py
```

```
deactivate
```

#### 3.1 Setup the virtual environment (before step-1)
```
python3 -m venv ./stats/generator/.venv
```

#### 3.2 Needs the following dependencies installed (before step-2)
```
pip install matplotlib
pip install PyGObject
pip install config
```

#### OR

#### 3.2 Recreate the same environment with
```
pip install -r ./stats/setup-info/requirements.txt
```

#### 3.3 Find the dependencies currently installed
```
pip list --format=freeze
```

---

### 4. Run 'algo-stats-generator.js'
```
node ./algorithms/stats/algo-stats-generator.js
```

---

### 5. Push code to github repo

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
