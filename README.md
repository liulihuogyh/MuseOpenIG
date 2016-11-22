The Muse OpenIG.  An opensource OpenSceneGraph based image generator application suite.
Documentation, sample datasets and Binary Downloads for some platforms available at: http://openig.compro.net

# Muse OpenIG V2.0.4
- Camel case file naming convention as in OSG, osgearth, SilverLining, Triton and bunch of other modern software projects.
  The file names were lowercase since the start of the project was on Linux with QtCreator. Now it matches the known
  opensource standards

- Core-OpenIG openig.h/cpp renamed to Engine.h/cpp. It is unobvious the file name to be different then the contained class

- Core-Base/Attributes.h renamed to Types.h - this was also due historical reasons from the time where this file was
  containing only the Attributes struct before adding more stuff into

- Small optimization for F+

- Use of upper case only commands across all the CMakeLists.txt .. it was mixed lower/upper from copying code

- Fixed few build scripts to get clean build on Windows removed ccl.lib and instead used the variables from the
  CMake macros - ${CCL_LIBRARY}

- SilverLining plugin has some new commands: createcloudfile, loadcloudfile, removecloudfile and enableclouds. These new commands
  are used to create a cloud layer and save it to a file at start of the OpenIG application so that you can use the loadcloudfile
  command later during realtime and not have as long of a delay before the clouds are loaded into the SL atmosphere. To even make this
  faster you can load the clouds into the SL amosphere already disabled, then just re-enable them when you want them visible.
  The enable happens almost immediately.  This is the purpose of the new enableclouds command, using it you can disable or enable a
  cloud layer from showing on your scene.  Once the layer is disabled, it no longer cause a performance hit within your application,
  its like it is not there at all.  The enableclouds command just requires the OIG ID number of the cloud layer and a true or false.
  We also added an optional enable argument to the current addclouds command, which can be used to load the cloud layer enabled or
  disabled now using true/false as the new argument at the end of the argument list, true being the layer is enabled and visible.

- NickT - fixed a bug in the lightenable command that dealt with lights that are animated/pulsing and would not turn off.  These
  animaged lights now turn on/off correctly via the enablelight command.

- Updated Sundogs SilverLining to 4.073 and Triton to 3.76 for the Windows binary release, these releases contain bug fixes and some
  performance increases.

- Remove Plugin-Muse as it was confusing some users since it will not compile due to missing some proprietary include files and libs.
  It was only meant to serve as an example plugin.

- The Dataset binaries that go with this binary release have also been updated due to some changes in a few of the models xml config
  files.

- This release has been tested on Windows 7 with VS2013 SP3 and QT5.4.2 and on OpenSuSE 64bit Linux 13.2, Qt 5.4.2 and the latest GCC
  compiler and linker as of this release.  The Windows binary installers were built with the just referenced packages.

# Muse OpenIG V2.0.3
  UDP network protocol is no longer defaulted to be a broadcast only, configurable
  via the network plugins xml config/datafile, as requested in pull request #5 & #6
  on the public GitHub OpenIG website, by jenglish.

  Some content has been moved into the new Core-Utils directory, just keep in
  mind in case of compile time errors after updating.

  Visual/Artistic only changes to A320 demo

  A few other misc updates and/or changes.

# Muse OpenIG V2.0.2
#  New CIGI plugin -- Sample code demonstrates how to implement the CIGI protocol with OpenIG.
   This new OpenIG plugin is based on and uses Boeing's CIGI Class Library.  Boeing also provides a
   CIGI Host Emulator application for Windows based systems and we have integrated
   it with our Application-Earth OSGEarth test application to give you a very basic working example
   to use as a starting point for your CIGI implementation.  The emulator is not available as part
   of OpenIG but can be downloaded separately at: [Boeing Emulator](http://cigi.sourceforge.net/products.php)
   along with their CIGI Class Library and associated documentation.

# Since V2.0.0 -- Features a Forward Plus lighting system plugin, as its default lighting method!!!
-----------------------------------------------------------------------------------------------------------------
Dependencies for compiling from source:
--------------------------------------
*   Minimum of OpenSceneGraph 3.3.7
    A patched version of OSG 3.3.7 is available on our [Downloads](http://openig.compro.net/download-openig.html)
    page, that contains some updates and allows full functionality
    of all features of MuseOpenIG.
*   We now recommend you upgrade your OSG release to at least 3.4.0(3.5.3 Dev.)
    in order to get the best OpenIG experience.

*   QT 5.4.1/later or CMake 3.X/later
*   Boost C++ Libraries 1.54 or later

Additional Dependencies for V1.1.0 and later if you want to include any of these new capabilities:
---------------------------------------------------------------------------------------
*  SunDog Software's SilverLining V4.024 & later -- Sky, 3D Cloud and Weather SDK
   on http://sundog-soft.com/sds/features/real-time-3d-clouds/
*  SunDog Software's Triton V3.38 & later-- Ocean and 3D Water SDK
   on http://sundog-soft.com/sds/features/ocean-and-water-rendering-with-triton
*  Bullet Physics SDK, version 2.82-r2704 or later, available on [GitHub](https://github.com/bulletphysics)
*  osgWorks version 3.0.0, available on [GitHub](https://github.com/mccdo/osgworks)
*  osgBullet version 3.0.0, available on [GitHub](https://github.com/mccdo/osgBullet)
*  OSGEarth version 2.6, available on [GitHub](https://github.com/gwaldron/osgearth)
*  MyGUI is a cross-platform library for creating graphical user interfaces (GUIs) for games and 3D applications.
   This is required if you want to use the UI-Plugin which provides a GUI interface for setting the
   lighting parameters contained in the test terrain database directory/master.flt.osg.lighting.xml datafile.
   MyGUI is available on [GitHub](https://github.com/MyGUI/mygui)

Additional Dependencies for V2.0.0 and later if you want to include any of the new Forward+ capabilities:
---------------------------------------------------------------------------------------
*  SunDog Software's SilverLining V4.042 & later -- Sky, 3D Cloud and Weather SDK
   on http://sundog-soft.com/sds/features/real-time-3d-clouds/
*  SunDog Software's Triton V3.51 & later-- Ocean and 3D Water SDK
   on http://sundog-soft.com/sds/features/ocean-and-water-rendering-with-triton

Hardware Dependancies
--------------------------------------------------------------------------------------------------
* NVidia GPU -- fully supported
* ATI GPU    -- fully supported as of the V2.0.0 release
