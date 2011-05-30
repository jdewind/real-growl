real-growl
==========

Description
-----------

A Growl notification library that uses native C bindings to interact with GrowlApplicationBridge rather than Growl's network API.

Synopsis
--------

### rg

    >> require 'real_growl'
    => true
    >> rg("Check out", ["Real", "Growl"], :icon => "/path/to/a/picture.jpg")
    >> rg("Google", ["Real", "Growl"], :icon => "http://www.google.com/logos/stpatricks_d4gwinner_eo09.gif")
    => nil
  
    >> RealGrowl.sticky = false
    => false
    >> RealGrowl.priority = 3
    => 3
    >> RealGrowl.icon = "/the/path/cool.png"
    => "/the/path/cool.png"
  
### Custom Application

    >> require 'real_growl'
    >> my_own_application = RealGrowl::Application.new("AppName")
    => #<RealGrowl::Application:0x1018eb6b8>
    >> my_own_application.notify(:title => "Title", :description => "Desc", :priority => 0, :sticky => true, :icon => "/path/to/image.png")

### Extras
    >> RealGrowl.installed?
    => true
    >> RealGrowl.running?
    => true

TODO
----

  * Add executable script
  * Enable growl callbacks
  
Requirements
------------

* MacOS X 10.5 > ??
* Growl Framework - http://growl.info/downloads_developers.php

INSTALL
-------

Download and install Growl.framework into either ~/Library/Frameworks or /Library/Frameworks
gem install real-growl

    $ # Download latest Growl SDK
    $ # Copy Growl.framework under Frameworks
    $ cp -r /Volumes/Growl\ 1.2.2\ SDK/Frameworks/Growl.framework /Library/Frameworks

INSTALLATION HINTS
------------------

Make sure that the Growl.framework is either 32bit or the 64bit depending on the version of MacOS X
installed and the kind of machine it is installed on.

Executable Usage
----------------

Uses slop to easily call a Growl notification with options (http://github.com/injekt/slop).

### Run

    $ realgrowl 
    $ realgrowl -t "New alert"
    $ realgrowl -d "A new notification of something!" -t "New alert"

Contributors
-----------

* basicxman (Growl Executable)
