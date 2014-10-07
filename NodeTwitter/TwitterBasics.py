from TwitterSearch import *
try:
    tso = TwitterSearchOrder() # create a TwitterSearchOrder object
    tso.setKeywords(['ALS Ice Bucket']) # let's define all words we would like to have a look for
    tso.setLanguage('en') # we want to see German tweets only
    tso.setCount(7) # please dear Mr Twitter, only give us 7 results per page
    tso.setIncludeEntities(False) # and don't give us all those entity information

    # it's about time to create a TwitterSearch object with our secret tokens
    ts = TwitterSearch(
        consumer_key = 'rLlJVRd3iccSMPA2FcVegSnYn',
        consumer_secret = 'dfEpJILR8zf3A4PJ8xVNQwzRddX6iifqXCDCWW0FTc7WvCZbyM',
        access_token = '154431320-9d5OB8ZutByaemDyu7IYoC9LdQbAmjI9iwVJyypV',
        access_token_secret = 'LrLi0SFYyKGR5Pdkqit2Fos3sD8KMp3woiYrgr3fOXZnW'
     )

    for tweet in ts.searchTweetsIterable(tso): # this is where the fun actually starts :)
        #print( '@%s tweeted: %s' % ( tweet['user']['screen_name'], tweet['text'] ) )
        print(tweet)



    #print(dir(ts))

except TwitterSearchException as e: # take care of all those ugly errors if there are some
    print(e)