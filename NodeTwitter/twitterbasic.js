var util = require('util'),
    twitter = require('twitter');
var twit = new twitter({
    consumer_key: 'rLlJVRd3iccSMPA2FcVegSnYn',
    consumer_secret: 'dfEpJILR8zf3A4PJ8xVNQwzRddX6iifqXCDCWW0FTc7WvCZbyM',
    access_token_key: '154431320-9d5OB8ZutByaemDyu7IYoC9LdQbAmjI9iwVJyypV',
    access_token_secret: 'LrLi0SFYyKGR5Pdkqit2Fos3sD8KMp3woiYrgr3fOXZnW'
});

// twit.search('#node', function(data) {
//     console.log(util.inspect(data));
// });

twit.stream('statuses/sample', function(stream) {
    stream.on('data', function(data) {
        console.log(util.inspect(data));
    });
});