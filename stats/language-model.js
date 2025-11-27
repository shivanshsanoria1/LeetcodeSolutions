const path = require("node:path");

const languages = {
  cpp: {
    name: 'cpp',
    formalName: 'C++',
    extension: 'cpp',
    type: 'general',
    dirNames: [
      'CPP [0001-0500]', 
      'CPP [0501-1000]',
      'CPP [1001-1500]',
      'CPP [1501-2000]',
      'CPP [2001-2500]',
      'CPP [2501-3000]',
      'CPP [3001-3500]',
      'CPP [3501-4000]',
    ],
    dirPaths: [
      path.join(__dirname, '..', 'CPP [0001-0500]'),
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
    dirNames: ['Javascript'],
    dirPaths: [path.join(__dirname, '..', 'Javascript')]
  },

  mysql: {
    name: 'mysql',
    formalName: 'MySQL',
    extension: 'sql',
    type: 'database',
    dirNames: ['MySQL'],
    dirPaths: [path.join(__dirname, '..', 'MySQL')]
  },
}

module.exports = {languageModel: languages}