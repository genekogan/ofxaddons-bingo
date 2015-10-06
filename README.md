## ofxaddons bingo!

A collection of [simple mashups](https://twitter.com/genekogan/status/602844080733839360) of [addons](http://www.ofxaddons.com) for [openframeworks](http://www.openframeworks.cc). 


#### Why?

There are 1000+ libraries made for openFrameworks which do vastly different things. Combining them--even in silly ways--helps stir new ideas and supplements the examples the addons come with.
 

#### What

The following examples are currently included.

**glitch_japan** :: glitching the flag of Japan ([ofxPostGlitch](https://github.com/maxillacult/ofxPostGlitch) + [ofxJapan](https://github.com/motoishmz/ofxJapan))

**libccv_instagram** :: making Instagram searches from image classifications of webcam images ([ofxCcv](https://github.com/kylemcdonald/ofxCcv) + [ofxInstagram](https://github.com/DHaylock/ofxInstagram))

**markovChain_macMouse** :: moves your mouse around according to a Markov Chain ([ofxMarkovChain](https://github.com/elaye/ofxMarkovChain) + [ofxMacMouse](https://github.com/2bbb/ofxMacMouse))

**facetracker_box2d*** :: it blows bubbles out of your eyes ([ofxFaceTracker](https://github.com/kylemcdonald/ofxFaceTracker) + [ofxBox2d](https://github.com/vanderlin/ofxBox2d))


#### Install

Clone this repo into your 'apps' folder, so that 'ofxaddons-bingo' is inside 'apps'. Then install the required addons (or at least the ones from the examples you wish to run).

This is a complete list of all the addons used in this collection. Each project uses two or more of the following: [ofxPostGlitch](https://github.com/maxillacult/ofxPostGlitch), [ofxJapan](https://github.com/motoishmz/ofxJapan), [ofxCcv](https://github.com/kylemcdonald/ofxCcv), [ofxInstagram](https://github.com/DHaylock/ofxInstagram), [ofxMarkovChain](https://github.com/elaye/ofxMarkovChain), [ofxMacMouse](https://github.com/2bbb/ofxMacMouse), [ofxFaceTracker](https://github.com/kylemcdonald/ofxFaceTracker), [ofxBox2d](https://github.com/vanderlin/ofxBox2d), [ofxCv](https://github.com/kylemcdonald/ofxCv)

Or run this script from the repo's root directory:

    sh clone_addons.sh

To use the `libccv_instagram` example, you must also follow the additional installation instructions found in those repos for downloading the classifier, and registering an authorization token with Instagram to use the API. 


#### Contribute!

Think up creative ways to mash up addons, and make a pull request and I'll add it. Please adhere to the following conventions:

- the project folder should be inside 'ofxaddons-bingo', at the same level as the others.
- use the following naming convention to keep things consistent: the name of the two (or more) addons used with the "ofx" stripped off and a dash between them. 
- please add an entry for it in this README including a description and the addons used.
- optional: tweet it at [@ofxaddons](http://www.twitter.com/ofxaddons)! and make a picture! [ofxGifEncoder](https://github.com/jesusgollonet/ofxGifEncoder) and [ofxGifRecorder](https://github.com/ofnode/ofxGifRecorder) are super for making gifs.

