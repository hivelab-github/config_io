/*******************************************************************/
/*                      Author: qxh                                */
/*                     Contact: qxh880507@163.com                  */
/*                 Last update: 2019-07-12                         */
/*******************************************************************/

/*
  Description: The h file for C++ class Config.
  The class reads config files and returns variables in given data types.
  Usage: 
         #include "config_io.h"
         
         using hivelab_config_io::Config;
         
         Config::SetConfigPath("/mypath/config.ini");
         // Or: Config::UseDefaultPath("config.ini");
         
         float my_var = Config::Get<float>("FieldName", "VarName");
*/



/* _<PACKAGE_NAME>_<FILE_NAME>_H_ */
#ifndef _HIVELAB_CONFIG_IO_H_
#define _HIVELAB_CONFIG_IO_H_ 

#include <map>    // To use: map<>.
#include <vector> // To use: vector<>.
#include <memory> // To use: shared_ptr.
#include <string> // To use: string.


namespace hivelab_config_io
{

struct ConfigMetaData
{
public:
  std::string data_;
  
  ConfigMetaData(){}
  ConfigMetaData(std::string _data):data_(_data){}
  
  operator int() const { return atoi(data_.c_str()); }        // Overload of some common operators.
  
  operator long int() const { return atol(data_.c_str()); }
  
  operator long long() const { return atoll(data_.c_str()); }
  
  operator float() const { return atof(data_.c_str()); }
  
  operator double() const { return atof(data_.c_str()); }
  
  operator std::string() const { return data_; }
};

}





namespace hivelab_config_io
{

class Config
{
public:
  
  
public:
  ~Config();
  
  static bool SetConfigPath(const std::string& _file_name, std::string _seperator = "=", int _max_file_len = 1000);  
  
private:
  typedef std::map<std::string, ConfigMetaData> ConfigField;
  
  Config();
  void TrimSpacingComment(std::string& _str);
  void PrintInfo(std::string _str);
  void PrintErrInfo(std::string _str);
  void PrintWarnInfo(std::string _str);
  static bool ReadConfigFile();
  static int ParseTrimLine(std::string& _file_line, std::fstream& _file);
  static void RecordConfigLine(const std::string& _line, ConfigField& _field);
  
private:
  int kMaxFileLen = 1000;
  std::string kSeperator_;
  std::fstream* file_;
  std::map<std::string, ConfigField> config_strs_;
  static std::shared_ptr<Config> ptr_;
  
public:
  template<typename T>
  static T Get(const std::string& _field, const std::string& _var)
  {
    if(ptr_->config_strs_.find(_field) != ptr_->config_strs_.end())                 // Validity check.
      if(ptr_->config_strs_[_field].find(_var) != ptr_->config_strs_[_field].end())
	return T(ptr_->config_strs_[_field][_var]);
      
    ptr_->PrintErrInfo("Field name or variable name does not exist!");
    return 0;
  }
  
  
  template<typename T>
  static std::vector<T> GetVector(const std::string& _field, const std::string& _var)
  {
    std::vector<T> tmp_vector;
    tmp_vector.push_back(T(ConfigMetaData("0")));
    
    if(ptr_->config_strs_.find(_field) != ptr_->config_strs_.end())                 // Validity check.
      if(ptr_->config_strs_[_field].find(_var) != ptr_->config_strs_[_field].end())
      {
	std::string tmp_str = ptr_->config_strs_[_field][_var].data_;
	
	if(tmp_str.find("{") != 0 || tmp_str.find("}") != tmp_str.size() - 1)       // Vector syntax: "{...}".
	{
	  ptr_->PrintErrInfo("Invalid data for vector type!");
	  return tmp_vector;
	}
	
	tmp_str.erase(0, 1);                                                        // Erase "{}" from the string.
	tmp_str.erase(tmp_str.find("}"), 1);
	if(tmp_str.rfind(",") == tmp_str.size() - 1)                                // Comma should not be the last letter.
	{
	  ptr_->PrintErrInfo("Invalid data for vector type!");
	  return tmp_vector;
	}
	
	if(tmp_str.rfind(";") != tmp_str.size() - 1)                                // Add ";" as the last letter.
	  tmp_str += ";";
	
	while(tmp_str.find(";") != std::string::npos)                               // Replace ";" with ",".
	  tmp_str.replace(tmp_str.find(";"), 1, ",");
	
	tmp_vector.clear();
	while(tmp_str.find(",") != std::string::npos)                               // Parse data iteratively.
	{
	  tmp_vector.push_back(T(ConfigMetaData(tmp_str.substr(0, tmp_str.find(",")))));
	  tmp_str.erase(0, tmp_str.find(",") + 1);
	}
	
	return tmp_vector;
      }
    
    ptr_->PrintErrInfo("Field name or variable name does not exist!");
    return tmp_vector;
  }
  
  
  template<typename T>
  static std::vector<std::vector<T>> GetVector2(const std::string& _field, const std::string& _var)
  {
    std::vector<T> tmp_vector;
    std::vector<std::vector<T>> tmp_vector2;
    tmp_vector.push_back(T(ConfigMetaData("0")));
    tmp_vector2.push_back(tmp_vector);
    
    if(ptr_->config_strs_.find(_field) != ptr_->config_strs_.end())
      if(ptr_->config_strs_[_field].find(_var) != ptr_->config_strs_[_field].end())
      {
	std::string tmp_str = ptr_->config_strs_[_field][_var].data_;
	
	if(tmp_str.find("{") != 0 || tmp_str.find("}") != tmp_str.size() - 1)
	{
	  ptr_->PrintErrInfo("Invalid data for vector type!");
	  return tmp_vector2;
	}
	
	tmp_str.erase(0, 1);
	tmp_str.erase(tmp_str.find("}"), 1);
	if(tmp_str.rfind(",") == tmp_str.size() - 1)
	{
	  ptr_->PrintErrInfo("Invalid data for vector type!");
	  return tmp_vector2;
	}
	
	if(tmp_str.rfind(";") != tmp_str.size() - 1)
	  tmp_str += ";";

	tmp_vector2.clear();
	while(tmp_str.find(";") != std::string::npos)
	{
	  tmp_vector.clear();
	  std::string tmp_str_line = tmp_str.substr(0, tmp_str.find(";")) + ",";
	  tmp_str.erase(0, tmp_str.find(";") + 1);

	  while(tmp_str_line.find(",") != std::string::npos)
	  {
	    tmp_vector.push_back(T(ConfigMetaData(tmp_str_line.substr(0, tmp_str_line.find(",")))));
	    tmp_str_line.erase(0, tmp_str_line.find(",") + 1);
	  }
	  tmp_vector2.push_back(tmp_vector);
	}
	return tmp_vector2;
      }
      
    ptr_->PrintErrInfo("Field name or variable name does not exist!");
    return tmp_vector2;
  }
  
public:
  static void UseDefaultPath(std::string _file_name);
};

} // hivelab_config_io





#endif // _HIVELAB_CONFIG_IO_H_
