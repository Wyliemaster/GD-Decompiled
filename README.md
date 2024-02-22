 English | [Russian](README-RU.md) | [Czech](README-CZ.md) | [Spanish](README-ES.md) | [简体中文](README-CN.md)

# GD-Decompiled
 An attempt to get the source code for Geometry Dash through reverse engineering and decompiling the game.  
I Calloc Have forked this repository for decompling other sources within 2.2 and beyond while wylie is off doing other things (Until he makes a 2.2 repository)
For now I shall dump what I do have for 2.204 and android v2.205 in here. Feel free to submit pull requests here so I can look at them I would like this to be an official repo for the people of geode to start using temporarly...


## Tools Used
See this [repo](https://github.com/CallocGD/Geometry-Dash-Miscellaneous-Decomp-Tools)


## My Goals with this fork
- To have all of `Manager` class components completely decompiled and reverse engineered as they can be the most difficult parts of gd's code to understand. They also make up a large chunk of the game and have numerous functions involved with them and I am also working on providing bindings to geode at the same time as more parts and variable names are being discovered. Understanding these componentes will allow for better mods to be made in the future as well as for understanding how http requests are made (Even though these have been well documentented already thanks to wyliemaster).
- I am Using Andorid Version 2.205 with ghidra and some help from [geode's bindings](https://github.com/geode-sdk/bindings) to help assist me with reverse engineering GD. I will be altering some of Wylie's original class member names in order to match with geode's class member names to help them mod GD.
- I will mainly be reverse engineering class objects that are not well understood by the community or haven't been fully reverse engineered yet in order to educate anyone interested...
- The Good news is that most of everyone has already found most of the puzzle pieces missing , I just have to put them all together and make sure they all fit.

## How Can I Contribute?
- Unlike WylieMaster, I'm not very skilled yet at naming class members by myself and I have chosen to simply leave that puzzle up to the Geode and it's many contributors and volunteers so that nothing remains in conflict. So in trade, the more class-members you find and add to the [geode bindings](https://github.com/geode-sdk/bindings) the more class objects and functions I will be able to reverse engineer.
- Downloading [Ghidra](https://github.com/NationalSecurityAgency/ghidra) or [IDA Pro](https://hex-rays.com/IDA-pro/) and Reverse engineering some of these class objects and members by youself. I am looking for other contributors besides just myself to volunteer in this effort.


## IMPORTANT

- This Project is intended to be used as reference material to assist with modding.
- Educating people on how geometry dash is built under the hood. 
- This repository is <b>not</b> a matching decompilation
- This code is NOT intended to be compiled. I don't condone pirating the game!! I sure hope you bought it with your own money first!

Classes that ive pushed but haven't finished will be found in [Issues](https://github.com/Wyliemaster/GD-Decompiled/issues).

## Buy GD

if for some reason you haven't already i recommend you go and buy GD

- [Android](https://play.google.com/store/apps/details?id=com.robtopx.geometryjump&hl=en_GB&gl=US)
- [IOS](https://apps.apple.com/us/app/geometry-dash/id625334537)
- [windows/mac](https://store.steampowered.com/app/322170/Geometry_Dash/)

## want to know more about the game?

if you want to know about the game and how various aspects work, you can find documentation [here](https://github.com/Wyliemaster/gddocs)
