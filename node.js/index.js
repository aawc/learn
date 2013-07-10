var server = require("./server"),
	router = require("./router"),
	requestHandlers = require("./requestHandlers");

var handle = {}
handle["/"] = requestHandlers.home;
handle["/home"] = requestHandlers.home;
handle["/start"] = requestHandlers.start;
handle["/upload"] = requestHandlers.upload;
handle["/node"] = requestHandlers.node;

server.start(router.route, handle);