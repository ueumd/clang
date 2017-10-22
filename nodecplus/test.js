/**
 * node-gyp configure
 node-gyp build
 */
var app = require('./build/Release/test.node');
app.hello('test', (data) => {
  console.log('arg:' + data);
});

// console.log(app.add(10, 20))

app.add(10, 20, (data) => {
  console.log(11111111111)
  console.log('value: '+ data)
})