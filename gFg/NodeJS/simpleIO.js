var http = require('http');
var fs = require('fs');
var server = http.createServer();

server.on('request', function(req, res){

	res.writeHead(200, {'Content-Type':'image/png'});
	fs.createReadStream('./img.png').pipe(res);
	//res.end	("Hello");


});


server.listen(5000);