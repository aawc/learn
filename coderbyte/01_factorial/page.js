'use strict';

function factorial(n) {
    if (!n || n <= 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

var jumpToContent = document.getElementById('jumpToContent');
var jumpToContentText = jumpToContent.innerText;
var fact = factorial(jumpToContentText.length);
console.log(fact);