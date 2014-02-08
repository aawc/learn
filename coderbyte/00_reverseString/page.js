'use strict';

var jumpToContent = document.getElementById('jumpToContent');
var jumpToContentText = jumpToContent.innerText;
var jumpToContentReverse = jumpToContentText.split('').reverse().join('');
console.log(jumpToContentReverse);