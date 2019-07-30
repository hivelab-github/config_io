
## Why do it

## What it does
Config_io is the program used to read the parameters of the configuration file.<br>
　*　The first step is to correctly write the parameters you need in config_ini.<br>
　* Config_io will provide the corresponding parameter value based on the parameter name you entered.<br>
　* When you need to modify the parameters, you only need to modify it in config_ini.<br>
## How does it work？You should really read it，it's important! 
1. The configured files are placed in the Config folder. The contents of the files are mainly the type and number<br>
of lidars and the parameters of different lidars.<br>
2. Usage:<br>
　#include "config_io.h" <br>
　using hivelab_config_io::Config; <br>
//Read the Config_ini file： <br>
　Config::SetConfigPath("mypath/config.ini"); <br>
　//Or : Config::UseDefaultPath("config.ini"); <br>
//Read the parameters you need： <br>
　float var=Config::Get("FieldName","VarName"); <br>
3. Else:<br>
* In SetConfigPath()，the symbol between the default parameter and the parameter value is “=”. When changing<br>
　the symbol in the configuration file, you need to change the second parameter of SetConfig() to the<br>
　corresponding symbol;<br>
* When using the Get() function, incorrect input will cause the compiler to prompt "Field name or variable name<br>
　does not exist!"<br>
* When using the GetVector() and GetVector2() functions，incorrect parameter name input causes the compiler to<br>
　prompt "Invalid data for vector type!"<br>
* When there is the same parameter name under the same segment value node, the compiler will prompt<br>
　"Duplicated names! The last one will be read!"<br>
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
Config Read ERROR: Field name or variable name does not exist!
LIDAR1's port_lidar----0<br>
Config Read ERROR: Invalid data for vector type!
Vetor1 of LIDAR1's factor----0
