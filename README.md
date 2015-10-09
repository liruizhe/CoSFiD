# CoSFiD - Compilation-Sensitive Code File Detection Tool

The CoSFiD contains the CoSFiD script and a compiler wrapper script. 

## CoSFiD

CoSFiD will detect compilation-sensitive code file(s) of a program.

Usage:

    CoSFiD <build command> <execution command> <comparison command> <compiler> <options A> <options B> <output>

* <***build command***> is command to build the program.
* <***execution command***> is command to execute the program. CoSFiD will log all the output in STDOUT for comparison.
* <***comparison command***> is command to compare the results. CoSFiD will call the command with two file names as arguments, which are two outputs of the program.
* <***compiler***> is the identity of the compiler to use, which listed in [*compiler.cfg*](#compiler.cfg).
* <***options A***> and <***options B***> are two groups of compiler options in detecting compilation-sensitive code file(s).
* <***output***> is the file name to record the result of detection.

## Compiler wrapper

The compiler wrapper replace the original compiler commands called by the makefile or compiling scripts of models. 
It will change the compiler option by some rules and call the original compiler.

Because it works like a compiler on the command line. The control of compiler wrapper is based on configuration files and environment variables.

### Environment variables for compiler wrapper
* **COSFID_COMPILER**. Specific which compiler (in ID) listed in compiler.cfg will be used.
* **COSFID_COMPILE_RECORD**. The file name to record the source code list. If do not use recording mode, leave it empty.
* **COSFID_REPLACE_OPTION**. Compiler option to replace. If it is not specified, the wrapper will use "*-DCoSFiD*" instead.
* **COSFID_COMPILE_LIST**. A list of configuration which specific the compiler options to replace option ***$COSFID_REPLACE_OPTION*** for each source file or each compiler command.

### Configuration files

#### <a name="compiler.cfg"/>compiler.cfg

This configuration file contains information of compilers in the system. 
This file is located in the same directory of the compiler wrapper script (**compiler.wrapper**).
Each line of the *compiler.cfg* presents the configuration of a compiler in following form:

    <compiler name> : <command to load compiler environment> : <directory contained the compiler command>

* The <***compiler name***> is the identity of the compiler in the use of compiler wrapper.
* The <***command to load compiler environment***> is a script to load some necessary environment variables of the compiler. 
For examples, the *compilervars.sh* script of Intel Compiler. If such script is unnecessary, leave it blank.
* The <***directory contained the compiler command***> specific the path of the compiler command.

####  Configuration of compiler options (file name specified by ***$COSFID_COMPILE_LIST***)

This configuration file contains compiler options which need to change in the compiling progress.
Each line of the configuration presents the compiler options for one source code file or one compiler command, as following form:

    <hash key> : <compiler options>

* The <***hash key***> is a hash key of the source code file or compiler command, which can be generated in recording mode.
if <***hash_key***> is "-", the options will be considered as fallback options when the compiler wrapper cannot find a matched hash key in the file.
* The <***compiler option***> is the compiler options to replace option ***$COSFID_REPLACE_OPTION***.
