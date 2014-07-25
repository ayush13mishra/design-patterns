========================================================================
    CONSOLE APPLICATION : designpatterns Project Overview
========================================================================

Following
	http://en.wikipedia.org/wiki/Abstract_factory_pattern


	The abstract factory pattern provides a way
		to encapsulate a group of individual factories
			that have a common theme without specifying their concrete classes.
	In normal usage,
		the client software 
			creates a concrete implementation of the abstract factory and then 
			uses the generic interface of the factory
				to create the concrete objects that are part of the theme.
		The client doesn't know (or care) which concrete objects it gets from each of these internal factories, 
			since it uses only the generic interfaces of their products.
		This pattern separates the details of implementation of a set of objects from their general usage and 
			relies on object composition, as object creation is implemented in methods exposed in the factory interface.[2]



// -----------------------------------------------------------------------------------------------------------

AppWizard has created this designpatterns application for you.

This file contains a summary of what you will find in each of the files that
make up your designpatterns application.


designpatterns.vcxproj
    This is the main project file for VC++ projects generated using an Application Wizard.
    It contains information about the version of Visual C++ that generated the file, and
    information about the platforms, configurations, and project features selected with the
    Application Wizard.

designpatterns.vcxproj.filters
    This is the filters file for VC++ projects generated using an Application Wizard. 
    It contains information about the association between the files in your project 
    and the filters. This association is used in the IDE to show grouping of files with
    similar extensions under a specific node (for e.g. ".cpp" files are associated with the
    "Source Files" filter).

designpatterns.cpp
    This is the main application source file.

/////////////////////////////////////////////////////////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named designpatterns.pch and a precompiled types file named StdAfx.obj.

/////////////////////////////////////////////////////////////////////////////
Other notes:

AppWizard uses "TODO:" comments to indicate parts of the source code you
should add to or customize.

/////////////////////////////////////////////////////////////////////////////
