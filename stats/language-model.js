const path = require("node:path");

const languages = {
  cpp: {
    name: 'cpp',
    formalName: 'C++',
    extension: 'cpp',
    type: 'general',
    dirPaths: [
      path.join(__dirname, '..', 'CPP [1-500]'),
      path.join(__dirname, '..', 'CPP [0501-1000]'),
      path.join(__dirname, '..', 'CPP [1001-1500]'),
      path.join(__dirname, '..', 'CPP [1501-2000]'),
      path.join(__dirname, '..', 'CPP [2001-2500]'),
      path.join(__dirname, '..', 'CPP [2501-3000]'),
      path.join(__dirname, '..', 'CPP [3001-3500]'),
      path.join(__dirname, '..', 'CPP [3501-4000]'),
    ]
  },

  js: {
    name: 'js',
    formalName: 'Javascript',
    extension: 'js',
    type: 'general',
    dirPaths: [path.join(__dirname, '..', 'Javascript')]
  },

  mysql: {
    name: 'mysql',
    formalName: 'MySQL',
    extension: 'sql',
    type: 'database',
    dirPaths: [path.join(__dirname, '..', 'MySQL')]
  },
}

module.exports = {languageModel: languages}