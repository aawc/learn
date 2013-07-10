var exec = require("child_process").exec,
	querystring = require("querystring");

function home(response, postData) {
	console.log("Request handler 'home' was called.");

	var body = '<html>'+
	'<head>'+
	'<meta http-equiv="Content-Type" content="text/html; '+
	'charset=UTF-8" />'+
	'</head>'+
	'<body>'+
	'<form action="/upload" method="post">'+
	'<textarea name="text" rows="20" cols="60"></textarea>'+
	'<input type="submit" value="Submit text" />'+
	'</form>'+
	'</body>'+
	'</html>';

	response.writeHead(200, {"Content-Type": "text/html"});
	response.write(body);
	response.end();
};

function start(response, postData) {
	console.log("Request handler 'start' was called.");

	exec("cd && pushd \\ && cd && dir /s /b *.*proj && popd && cd", function (error, stdout, stderr) {
		response.writeHead(200, {"Content-Type": "text/plain"});
		if (error === null) {
			response.write(stdout);
		}
		else {
			response.write('' + error);
		}
		response.end();
	});
};

function node(response, postData) {
	exec("type ..\\..\\NodeBeginnerBook\\index.html", function (error, stdout, stderr) {
		response.writeHead(200, {"Content-Type": "text/html"});
		if (stdout !== "") {
			response.write(stdout);
		}
		else {
			response.write(stderr);
		}
		response.end();
	});
};

function upload(response, postData) {
	console.log("Request handler 'upload' was called.");
	response.writeHead(200, {"Content-Type": "text/html"});
	response.write(querystring.parse(postData).text);
	response.end();
};

exports.home = home;
exports.start = start;
exports.upload = upload;
exports.node = node;