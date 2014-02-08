'use strict';

function largestWordInString(input) {
    var words = input.split(' '), maxLen = 0, maxWord, i, word;
    for (i = 0; word = words[i]; i++) {
        if (word.length > maxLen) {
            maxLen = word.length;
            maxWord = word;
        }
    }
    return maxWord;
}

var jumpToContent = document.getElementById('jumpToContent');
var jumpToContentText = jumpToContent.innerText;
var maxWord = largestWordInString(jumpToContentText);
console.log(maxWord);