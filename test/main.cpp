#include <iostream>
#include "config_io.h"

using std::cout;
using std::endl;
using hivelab_config_io::Config;

int main(int argc, char **argv) {
  Config::SetConfigPath("../config.ini");
//LIDAR1 data output 
  cout << "lidar1 data output:" << endl;
  float var1 = Config::Get<float>("LIDAR1","port_lidar");
  std::string var2 = Config::Get<std::string>("LIDAR1","factor");
  cout << "LIDAR1's port_lidar" <<" ----" << var1 << endl;
  cout << "LIDAR1's factor" << "----" << var2 << endl;
  
  std::vector<float> var3;
  var3 = Config::GetVector<float>("LIDAR1","factor");
  for(float m:var3)
  cout << "Vetor1 of LIDAR1's factor" << "----" << m << endl;
  
  std::vector<std::vector<float>> var4;
  var4 = Config::GetVector2<float>("LIDAR1","factor");
  for(int i=0;i<var4.size();i++)
    for(int j=0;j<4;j++)
  cout << "Vetor2 of LIDAR1's factor" << "----" << var4[i][j] << endl;
  
//wrong output
  cout << "lidar1 data wrong output:" << endl;
  float wro1 = Config::Get<float>("LIDAR1","port_lida");
  cout << "LIDAR1's port_lidar" << "----" << wro1 << endl;
  
  std::vector<float> wro2;
  wro2 = Config::GetVector<float>("LIDAR1","port_lidar");
  for(float m1:wro2)
  cout << "Vetor1 of LIDAR1's factor" << "----" << m1 << endl;
  
  return 0;
}
  
  
  
  
  
         
