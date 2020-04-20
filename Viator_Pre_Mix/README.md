# Viator Clipper

This Clipper plugin is my first fully-featured effect that I created in JUCE.

First, the audio passes through the Viator Trimmer signal flow for input gain. Then, the signal is passed through optional low-pass and high-pass filters with a smooth, 12 dB per octave slope. The clipping stage is the interesting part. There are four clipping modes to choose from that are each driven harder than the last:
-Subtle
-Soft
-Driven
-Cranked
The voice select features two voices:
-Vintage
-Modern
On the vintage voice, when the drive is turned up, a low and high shelf is boosted on the output scaled by the drive knob. With the drive knob all the way up, there is 3 dB of low and high boost. On the modern voice, the same operation happens on the mid-range part of the frequency spectrum.

This was my first idea for making a plugin that is inspired by anlog audio gear and I plan to delve more into hardware emulation in the future.
 
This trimmer plugin is the first JUCE project I finished in a final, deployable state.

It's a gain plugin that also has a phase inversion function.

Some quality of life buttons allow fine, comfortable control of the gain effect. The plus and minus buttons increment and decrement the gain by the amount shown and the fine toggle switches those buttons from 1.5 dB to .25 dB for even finer control.

Lastly, the unity button sets the slider to zero from whatever position it's currently at. The plugin's parameters are automation functioning and the plugin's state is saved when the GUI is closed and when the project is closed, which is then restored when the project is opened again.
 
![alt text](https://d30pueezughrda.cloudfront.net/juce/JUCE_banner.png "JUCE")

JUCE is an open-source cross-platform C++ application framework used for rapidly
developing high quality desktop and mobile applications, including VST, AU (and AUv3),
RTAS and AAX audio plug-ins. JUCE can be easily integrated with existing projects or can
be used as a project generation tool via the [Projucer](https://juce.com/discover/projucer),
which supports exporting projects for Xcode (macOS and iOS), Visual Studio, Android Studio,
Code::Blocks, CLion and Linux Makefiles as well as containing a source code editor and
live-coding engine which can be used for rapid prototyping.

## Getting Started
The JUCE repository contains a [master](https://github.com/weareroli/JUCE/tree/master)
and [develop](https://github.com/weareroli/JUCE/tree/develop) branch. The develop branch
contains the latest bugfixes and features and is periodically merged into the master
branch in stable [tagged releases](https://github.com/WeAreROLI/JUCE/releases)
(the latest release containing pre-built binaries can be also downloaded from the
[JUCE website](https://shop.juce.com/get-juce)).

The repository doesn't contain a pre-built Projucer so you will need to build it
for your platform - Xcode, Visual Studio and Linux Makefile projects are located in
[extras/Projucer/Builds](/extras/Projucer/Builds)
(the minumum system requirements are listed in the __System Requirements__ section below).
The Projucer can then be used to create new JUCE projects, view tutorials and run examples.
It is also possible to include the JUCE modules source code in an existing project directly,
or build them into a static or dynamic library which can be linked into a project.

For further help getting started, please refer to the JUCE
[documentation](https://juce.com/learn/documentation) and
[tutorials](https://juce.com/learn/tutorials).

## Minimum System Requirements
#### Building JUCE Projects
- __macOS__: macOS 10.11 and Xcode 7.3.1
- __Windows__: Windows 8.1 and Visual Studio 2015 64-bit
- __Linux__: GCC 4.8

#### Deployment Targets
- __macOS__: macOS 10.7
- __Windows__: Windows Vista
- __Linux__: Mainstream Linux distributions

## Contributing
For bug reports and features requests, please visit the [JUCE Forum](https://forum.juce.com/) -
the JUCE developers are active there and will read every post and respond accordingly. When
submitting a bug report, please ensure that it follows the
[issue template](/.github/ISSUE_TEMPLATE.txt).
We don't accept third party GitHub pull requests directly due to copyright restrictions
but if you would like to contribute any changes please contact us.

## License
The core JUCE modules (juce_audio_basics, juce_audio_devices, juce_blocks_basics, juce_core
and juce_events) are permissively licensed under the terms of the
[ISC license](http://www.isc.org/downloads/software-support-policy/isc-license/).
Other modules are covered by a
[GPL/Commercial license](https://www.gnu.org/licenses/gpl-3.0.en.html).

There are multiple commercial licensing tiers for JUCE 5, with different terms for each:
- JUCE Personal (developers or startup businesses with revenue under 50K USD) - free
- JUCE Indie (small businesses with revenue under 200K USD) - $35/month
- JUCE Pro (no revenue limit) - $65/month
- JUCE Educational (no revenue limit) - free for bona fide educational institutes

For full terms see [LICENSE.md](LICENSE.md).


