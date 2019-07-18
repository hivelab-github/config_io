# lidar_parameters_config
First entered the gate of github, I hope I will be better in the future.
## Why do it
　　* When writing a program, you often encounter a variety of parameters. If the parameters are written directly<br>
in the program, the program needs to be recompiled each time it is modified. When the number is increasing, the<br>
modification becomes difficult. Therefore, it is an excellent way to define a configuration file outside the program,<br>
and the contents of the configuration file are read while the program is running. In this way, each modification only <br>
needs to change the content of the configuration file, and the program itself does not modify it.<br>
　　* Generally, large libraries such as opencv will have their own parameter configuration functions, but they are quite<br> inconvenient to use. On the one hand, the use of parameter commands requires systematic learning, and the operation is<br>
cumbersome. On the other hand, using its parameters' commands simply causes a waste of function and disk capacity. For this<br>
reason, the Config_io.h and Config_io.cpp programs are provided in the include and src folders, which can be used to read<br>
and store related project parameters.<br>
## What it does
　   Config_io provides configuration parameters, and the main program reads the parameter file by calling the Config_io  
built-in function. The parameter file is placed in the Config folder and is the relevant data of the lidar. By specifying  
the parameters of the lidar and inputing the parameters that need to be searched, the corresponding parameter <br>
values can be obtained.<br>
## How does it work？You should really read it，it's important! 
1. The configured files are placed in the Config folder. The contents of the files are mainly the type and number of lidars<br>
and the parameters of different lidars.<br>
<br>
2. Usage:<br>
　   #include "config_io.h" <br>
　   using hivelab_config_io::Config; <br>
//Read the Config_ini file： <br>
　   Config::SetConfigPath("mypath/config.ini"); <br>
　　//Or : Config::UseDefaultPath("config.ini"); <br>
//Read the parameters you need： <br>
　   float var=Config::Get("FieldName","VarName"); <br>
<br>
3. Else:<br>
　　* In SetConfigPath()，the symbol between the default parameter and the parameter value is “=”. When changing the<br>
symbol in the configuration file, you need to change the second parameter of SetConfig() to the corresponding symbol;<br>
　　* When using the Get() function, incorrect input will cause the compiler to prompt "Field name or variable name<br>
does not exist!"<br>
　　* When using the GetVector() and GetVector2() functions，incorrect parameter name input causes the compiler to prompt<br>
"Invalid data for vector type!"<br>
　　* When there is the same parameter name under the same segment value node, the compiler will prompt "Duplicated names!<br>
The last one will be read!"<br>
　　* Allows you to add spaces to the configuration file and use the '#' comment.<br>
 
## Additional information
A small test program was placed under the test folder to  read some of the data, and the error was specifically shown.The 
results of testing in kdevelop are as follows.<br>
<br>
Config Read INFO: Read 6 config fields.<br>
Config Read INFO: Read 34 config contents.<br>
lidar1 data output:<br>
LIDAR1's port_lidar----8320<br>
LIDAR1's factor----{-0.0246748,0.999683,0.00506668,-1.95;-0.804064,-0.0168343,-0.594304,-0.465;-0.59403,-0.0187383,0.804224,1.51}<br>
Vetor1 of LIDAR1's factor-----0.0246748<br>
Vetor1 of LIDAR1's factor----0.999683<br>
Vetor1 of LIDAR1's factor----0.00506668<br>
Vetor1 of LIDAR1's factor-----1.95<br>
Vetor1 of LIDAR1's factor-----0.804064<br>
Vetor1 of LIDAR1's factor-----0.0168343<br>
Vetor1 of LIDAR1's factor-----0.594304<br>
Vetor1 of LIDAR1's factor-----0.465<br>
Vetor1 of LIDAR1's factor-----0.59403<br>
Vetor1 of LIDAR1's factor-----0.0187383<br>
Vetor1 of LIDAR1's factor----0.804224<br>
Vetor1 of LIDAR1's factor----1.51<br>
Vetor2 of LIDAR1's factor-----0.0246748<br>
Vetor2 of LIDAR1's factor----0.999683<br>
Vetor2 of LIDAR1's factor----0.00506668<br>
Vetor2 of LIDAR1's factor-----1.95<br>
Vetor2 of LIDAR1's factor-----0.804064<br>
Vetor2 of LIDAR1's factor-----0.0168343<br>
Vetor2 of LIDAR1's factor-----0.594304<br>
Vetor2 of LIDAR1's factor-----0.465<br>
Vetor2 of LIDAR1's factor-----0.59403<br>
Vetor2 of LIDAR1's factor-----0.0187383<br>
Vetor2 of LIDAR1's factor----0.804224<br>
Vetor2 of LIDAR1's factor----1.51<br>
lidar1 data wrong output:<br>
[31mConfig Read ERROR: Field name or variable name does not exist![0m<br>
LIDAR1's port_lidar----0<br>
[31mConfig Read ERROR: Invalid data for vector type![0m<br>
Vetor1 of LIDAR1's factor----0
