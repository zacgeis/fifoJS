[![build status](https://secure.travis-ci.org/zacgeis/fifoJS.png)](http://travis-ci.org/zacgeis/fifoJS)
fifoJS
======

Unix named pipes for node

## Installation

npm install fifojs
        
## Examples

```javascript
var fifojs = require('fifojs');

fifojs.mkfifo('tmp/expipe', 0777); 
```
