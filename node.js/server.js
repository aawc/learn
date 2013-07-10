var http = require("http"),
	url = require("url");

function start(route, handle) {
	function onRequest(request, response) {
		var postData = "";
		var count = 0;
		var pathname = url.parse(request.url).pathname;
		console.log('Request for: ' + pathname);

		request.setEncoding("utf8");
		request.addListener("data", function(postDataChunk) {
			postData += postDataChunk;
			count++;
			console.log('Count: ' + count + '; Length: ' + postData.length);
		});

		request.addListener("end", function() {
			route(handle, pathname, response, postData);
		});
	};

	http.createServer(onRequest).listen(8888);
};

exports.start = start;