## ofxaddons bingo!

A collection of [simple mashups](https://twitter.com/genekogan/status/602844080733839360) of [addons](http://www.ofxaddons.com) for [openframeworks](http://www.openframeworks.cc). Please contribute!

#### Why?

There are 1000+ libraries made for openFrameworks which do vastly disparate things. Combining them--even in silly ways--helps to stir new ideas, and show others nifty ways of extending OF's functionality.

#### What's included

The following examples are currently included.

**glitch_japan** :: glitching the flag of Japan ([ofxPostGlitch](https://github.com/maxillacult/ofxPostGlitch) + [ofxJapan](https://github.com/motoishmz/ofxJapan))
**libccv_instagram** :: making Instagram searches from image classifications of webcam image (([ofxCcv](https://github.com/kylemcdonald/ofxCcv) + [ofxInstagram](https://github.com/DHaylock/ofxInstagram))
**markovChain_macMouse** :: moves your mouse around according to a Hidden Markov Model ()

More to come.

#### Installation

Clone this repo into your 'apps' folder, so that 'ofxaddons-bingo' is inside 'apps'. Then installed the required addons (or at least the ones from the examples you wish to run).

This is a complete list of all the addons used in this collection. Each project uses two or more of these: [ofxPostGlitch](https://github.com/maxillacult/ofxPostGlitch), [ofxJapan](https://github.com/motoishmz/ofxJapan), [ofxCcv](https://github.com/kylemcdonald/ofxCcv), [ofxInstagram](https://github.com/DHaylock/ofxInstagram), [ofxMarkovChain](https://github.com/elaye/ofxMarkovChain), [ofxMacMouse](https://github.com/2bbb/ofxMacMouse)

If you want to quickly clone all of the required addons, `cd` to this repo, and run the following script:

    sh clone_addons.sh

To use the `libccv_instagram` example, you must also follow the additional installation instructions found in those repos. You must swap in your authorization token for the Instagram example.


#### Contribute

This repo is open to contributions! Think up creative ways to mash up any and all addons, and make a pull request and I will add the new example. Please adhere to the following guidelines:

- the project folder should be inside 'ofxaddons-bingo', at the same level as the others.
- use the following naming convention to keep things consistent: the name of the two (or more) addons used with the "ofx" stripped off and a dash between them. 
- please note the addons used and any specific installation instructions. 
- please make a GIF!!! you can use [ofxGifEncoder](https://github.com/jesusgollonet/ofxGifEncoder), [ofxGifRecorder](https://github.com/ofnode/ofxGifRecorder), [Giphy](http://giphy.com/), etc. Please send that to me separately if possible to keep the size of the repo down.

