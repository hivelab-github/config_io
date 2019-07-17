# lidar_parameters_config
First entered the gate of github, I hope I will be better in the future.
## What it does
When writing a program, you often encounter a variety of parameters. If the parameters are written directly in the program, the program needs to be recompiled each time it is modified. When the number is increasing, the modification becomes difficult. Therefore, it is an excellent way to define a configuration file outside the program,and the contents of the configuration file are read while the program is running. In this way, each modification only needs to change the content of the configuration file, and the program itself does not modify it.
Config_io provides configuration parameters, and the main program reads the parameter file by calling the Config_io built-in function. The parameter file is placed in the Config folder and is the relevant data of the lidar. By specifying the parameters of the lidar and inputing the parameters that need to be searched, the corresponding parameter values can be obtained.
## How does it work？You should really read it，it's important! 
Usage:
      #include "config_io.h" 
      using hivelab_config_io::Config; 
//Read the Config_ini file： 
      Config::SetConfigPath("mypath/config.ini"); 
      //Or : Config::UseDefaultPath("config.ini"); 
//Read the parameters you need： 
      float var=Config::Get("FieldName","VarName"); 
## Additional information
A small test program was placed under the test folder to  read some of the data, and the error was specifically shown.The results of testing in kdevelop are as follows.
Result：
Config Read INFO: Read 6 config fields.
Config Read INFO: Read 34 config contents.
lidar1 data output:
LIDAR1's port_lidar----8320
LIDAR1's factor----{-0.0246748,0.999683,0.00506668,-1.95;-0.804064,-0.0168343,-0.594304,-0.465;-0.59403,-0.0187383,0.804224,1.51}
Vetor1 of LIDAR1's factor-----0.0246748
Vetor1 of LIDAR1's factor----0.999683
Vetor1 of LIDAR1's factor----0.00506668
Vetor1 of LIDAR1's factor-----1.95
Vetor1 of LIDAR1's factor-----0.804064
Vetor1 of LIDAR1's factor-----0.0168343
Vetor1 of LIDAR1's factor-----0.594304
Vetor1 of LIDAR1's factor-----0.465
Vetor1 of LIDAR1's factor-----0.59403
Vetor1 of LIDAR1's factor-----0.0187383
Vetor1 of LIDAR1's factor----0.804224
Vetor1 of LIDAR1's factor----1.51
Vetor2 of LIDAR1's factor-----0.0246748
Vetor2 of LIDAR1's factor----0.999683
Vetor2 of LIDAR1's factor----0.00506668
Vetor2 of LIDAR1's factor-----1.95
Vetor2 of LIDAR1's factor-----0.804064
Vetor2 of LIDAR1's factor-----0.0168343
Vetor2 of LIDAR1's factor-----0.594304
Vetor2 of LIDAR1's factor-----0.465
Vetor2 of LIDAR1's factor-----0.59403
Vetor2 of LIDAR1's factor-----0.0187383
Vetor2 of LIDAR1's factor----0.804224
Vetor2 of LIDAR1's factor----1.51
lidar1 data wrong output:
[31mConfig Read ERROR: Field name or variable name does not exist![0m
LIDAR1's port_lidar----0
[31mConfig Read ERROR: Invalid data for vector type![0m
Vetor1 of LIDAR1's factor----0
